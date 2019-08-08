#include <stdio.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <cmath>
#include "al2o3_vfile/vfile.h"
#include "../include/tiny_imageformat/tinyimageformat_bits.h"
#include "formatgen.h"

int8_t PhysicalChannelToLogical(char const *name, uint64_t const v, uint32_t chan);
void LogicalToPhysicalChannels(const char *name, uint64_t v, int8_t out[4]);
double MaxActual(char const *name, uint64_t v, uint32_t const chan, bool ignoreNormFormats);

uint32_t WidthOfBlock(char const *name, uint64_t v);
uint32_t HeightOfBlock(char const *name, uint64_t v);
uint32_t DepthOfBlock(char const *name, uint64_t v);

void GenMaxPixelCountOfBlock(VFile_Handle file) {
	char buffer[2048];

#define  TinyImageFormat_START_MACRO uint32_t maxPixelCountOfBlock = 0;
#define  TinyImageFormat_MOD_MACRO(x, y) { uint32_t tmp = WidthOfBlock(#x, y) * HeightOfBlock(#x, y) * DepthOfBlock(#x, y); \
                            if(tmp > maxPixelCountOfBlock) maxPixelCountOfBlock = tmp; };
#define  TinyImageFormat_END_MACRO
#include "formatgen.h"
	char const formatCountF[] = "#define TinyImageFormat_MaxPixelCountOfBlock %uU \n\n";

	sprintf(buffer, formatCountF, maxPixelCountOfBlock);
	VFile_Write(file, buffer, strlen(buffer));
}

bool FetchLogicalPixelsPackedNotSpecial(char const *name,
																				uint64_t const v,
																				char *output) {
	// easy not packed formats
	uint64_t vb = v >> TinyImageFormat_PACK_BITS_SHIFT;
	uint64_t vt = v >> TinyImageFormat_PACK_TYPE_SHIFT;
	uint64_t vs = v >> TinyImageFormat_PACK_SWIZZLE_SHIFT;

	for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
		TinyImageFormat_Pack_Swizzle
				swiz = (TinyImageFormat_Pack_Swizzle) (vs & Mask(TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS));

		int32_t swizzle = PhysicalChannelToLogical(name, v, i);

		TinyImageFormat_Pack_Type
				type = (TinyImageFormat_Pack_Type) (vt & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
		double const maxFactor = MaxActual(name, v, i, true);
		double const normalFactor = 1.0 / maxFactor;

		if (swizzle >= 0) {
			TinyImageFormat_Pack_Bits
					bits = (TinyImageFormat_Pack_Bits) (vb & Mask(TinyImageFormat_PACK_BITS_REQUIRED_BITS));
			uint32_t chanBitWidth = 0;
			switch (bits) {
			case TinyImageFormat_PACK_BITS_0: continue;
			case TinyImageFormat_PACK_BITS_8: chanBitWidth = 8;
				break;
			case TinyImageFormat_PACK_BITS_16: chanBitWidth = 16;
				break;
			case TinyImageFormat_PACK_BITS_32: chanBitWidth = 32;
				break;
			case TinyImageFormat_PACK_BITS_64: chanBitWidth = 64;
				break;
			default: LOGERRORF("unpacked format can only be 8, 16, 32, 64 bits wide per channel: bits encoded as %d",
												 bits);
				continue;
			}

			char const *typeStringFmt;
			switch (type) {
			case TinyImageFormat_PACK_TYPE_UNORM:
			case TinyImageFormat_PACK_TYPE_SRGB:
			case TinyImageFormat_PACK_TYPE_UINT: typeStringFmt = "uint%d_t";
				break;
			case TinyImageFormat_PACK_TYPE_SNORM:
			case TinyImageFormat_PACK_TYPE_SINT: typeStringFmt = "int%d_t";
				break;
			case TinyImageFormat_PACK_TYPE_UFLOAT:
			case TinyImageFormat_PACK_TYPE_SFLOAT:
				if (chanBitWidth == 16) {
					typeStringFmt = "uint16_t"; // special needs decoder
				} else if (chanBitWidth == 32) {
					typeStringFmt = "float";
				} else if (chanBitWidth == 64) {
					typeStringFmt = "double";
				} else {
					ASSERT(false);
				}
				break;
			case TinyImageFormat_PACK_TYPE_SBFLOAT:
				if (chanBitWidth == 16) {
					typeStringFmt = "uint16_t"; // special needs decoder
				} else {
					ASSERT(false);
				}

				break;
			case TinyImageFormat_PACK_TYPE_NONE: continue;
			}

			char typeStringBuf[2048];
			sprintf(typeStringBuf, typeStringFmt, chanBitWidth);
			switch (type) {
			case TinyImageFormat_PACK_TYPE_UNORM:
				sprintf(output,
								"%s\t\t\tout[%d] = ((double)((%s const *)in->pixel)[%d]) * %1.8f;\n",
								output,
								swizzle,
								typeStringBuf,
								i,
								normalFactor);
				break;
			case TinyImageFormat_PACK_TYPE_SNORM:
				sprintf(output,
								"%s\t\t\tout[%d] = (((double)((%s const *)in->pixel)[%d]) * %1.8f) - 1.0;\n",
								output,
								swizzle,
								typeStringBuf,
								i,
								normalFactor);
				break;
			case TinyImageFormat_PACK_TYPE_SFLOAT:
				if (chanBitWidth == 16) {
					sprintf(output,
									"%s\t\t\tout[%d] = TinyImageFormat_HalfAsUintToDouble((((%s const *)in->pixel))[%d]);\n",
									output,
									swizzle,
									typeStringBuf,
									i);

				} else {
					sprintf(output,
									"%s\t\t\tout[%d] = (double)(((%s const *)in->pixel))[%d];\n",
									output,
									swizzle,
									typeStringBuf,
									i);
				}
				break;
			case TinyImageFormat_PACK_TYPE_SBFLOAT:
				sprintf(output,
								"%s\t\t\tout[%d] = TinyImageFormat_BFloatAsUintToDouble((((%s const *)in->pixel))[%d]);\n",
								output,
								swizzle,
								typeStringBuf,
								i);
				break;
			case TinyImageFormat_PACK_TYPE_UINT:
				sprintf(output,
								"%s\t\t\tout[%d] = (double)(((%s const *)in->pixel))[%d];\n",
								output,
								swizzle,
								typeStringBuf,
								i);
				break;
			case TinyImageFormat_PACK_TYPE_SINT:
				sprintf(output,
								"%s\t\t\tout[%d] = ((double)(((%s const *)in->pixel))[%d]) - %1.8f;\n",
								output,
								swizzle,
								typeStringBuf,
								i,
								maxFactor);
				break;
			case TinyImageFormat_PACK_TYPE_SRGB:
				sprintf(output,
								"%s\t\t\tout[%d] = (double)TinyImageFormat_LookupSRGB(((%s const *)in->pixel)[%d]);\n",
								output,
								swizzle,
								typeStringBuf,
								i);
				break;
			case TinyImageFormat_PACK_TYPE_UFLOAT:
			case TinyImageFormat_PACK_TYPE_NONE: ASSERT(false);
			}
		}
		vb = vb >> TinyImageFormat_PACK_BITS_REQUIRED_BITS;
		vt = vt >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
		vs = vs >> TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS;
	}

	int8_t l2p[4];
	LogicalToPhysicalChannels(name, v, l2p);

	for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
		if (l2p[i] < 0) {
			sprintf(output, "%s\t\t\tout[%d] = %.f;\n", output, i, (double) ((-l2p[i]) - 1));
		}
	}
	return true;
}

bool FetchLogicalPixelsPackedSpecial(char const *name,
																		 uint64_t const v,
																		 char *output,
																		 TinyImageFormat_Pack_Special const special) {
	// tightly packed formats
	uint64_t vb = v >> TinyImageFormat_PACK_BITS_SHIFT;
	uint64_t vt = v >> TinyImageFormat_PACK_TYPE_SHIFT;
	uint64_t vs = v >> TinyImageFormat_PACK_SWIZZLE_SHIFT;

	// how wide is the total pixel format we fetch that and then break out each channel
	uint32_t bitWidth = 0;
	uint64_t vbc = vb;
	for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
		TinyImageFormat_Pack_Bits
				bits = (TinyImageFormat_Pack_Bits) (vbc & Mask(TinyImageFormat_PACK_BITS_REQUIRED_BITS));
		switch (bits) {
		case TinyImageFormat_PACK_BITS_0: break;
		case TinyImageFormat_PACK_BITS_1: bitWidth += 1;
			break;
		case TinyImageFormat_PACK_BITS_2: bitWidth += 2;
			break;
		case TinyImageFormat_PACK_BITS_3: bitWidth += 3;
			break;
		case TinyImageFormat_PACK_BITS_4: bitWidth += 4;
			break;
		case TinyImageFormat_PACK_BITS_5: bitWidth += 5;
			break;
		case TinyImageFormat_PACK_BITS_6: bitWidth += 6;
			break;
		case TinyImageFormat_PACK_BITS_7: bitWidth += 7;
			break;
		case TinyImageFormat_PACK_BITS_8: bitWidth += 8;
			break;
		case TinyImageFormat_PACK_BITS_9: bitWidth += 9;
			break;
		case TinyImageFormat_PACK_BITS_10: bitWidth += 10;
			break;
		case TinyImageFormat_PACK_BITS_11: bitWidth += 11;
			break;
		case TinyImageFormat_PACK_BITS_12: bitWidth += 12;
			break;
		case TinyImageFormat_PACK_BITS_16: bitWidth += 16;
			break;
		case TinyImageFormat_PACK_BITS_24: bitWidth += 24;
			break;
		case TinyImageFormat_PACK_BITS_32: bitWidth += 32;
			break;
		case TinyImageFormat_PACK_BITS_64: bitWidth += 64;
			break;
		}
		vbc = vbc >> TinyImageFormat_PACK_BITS_REQUIRED_BITS;
	}
	switch (special) {
	case TinyImageFormat_PACK_SPECIAL_NONE: ASSERT(special != TinyImageFormat_PACK_SPECIAL_NONE);
	case TinyImageFormat_PACK_SPECIAL_PACK:break;
	case TinyImageFormat_PACK_SPECIAL_MULTI2:bitWidth *= 2;
		break;
	case TinyImageFormat_PACK_SPECIAL_MULTI4:bitWidth *= 4;
		break;
	case TinyImageFormat_PACK_SPECIAL_MULTI8:bitWidth *= 8;
		break;
	}
	// packed formats are currently limited to 32 bits but we allow 64 bit for future possibilities
	switch (bitWidth) {
	case 8: sprintf(output, "%s\t\t\tuint8_t val = ((uint8_t const*)in->pixel)[0];\n", output);
		break;
	case 16: sprintf(output, "%s\t\t\tuint16_t val = ((uint16_t const*)in->pixel)[0];\n", output);
		break;
	case 32: sprintf(output, "%s\t\t\tuint32_t val = ((uint32_t const*)in->pixel)[0];\n", output);
		break;
	case 64: sprintf(output, "%s\t\t\tuint64_t val = ((uint64_t const*)in->pixel)[0];\n", output);
		break;
	default:
		if (bitWidth < 8 || bitWidth > 64) {
			LOGERRORF("The total bitwidth of a pack pixel must be between 8 and 64 bits: %s has %d", name, bitWidth);
			return false;
		}
	}

	uint64_t shifter = 0;
	uint32_t repeat = 1;
	switch (special) {
	case TinyImageFormat_PACK_SPECIAL_NONE:repeat = 1;
		break;
	case TinyImageFormat_PACK_SPECIAL_PACK:repeat = 1;
		break;
	case TinyImageFormat_PACK_SPECIAL_MULTI2:repeat = 2;
		break;
	case TinyImageFormat_PACK_SPECIAL_MULTI4:repeat = 4;
		break;
	case TinyImageFormat_PACK_SPECIAL_MULTI8:repeat = 8;
		break;
	}
	for (uint32_t j = 0; j < repeat; j++) {
		vb = v >> TinyImageFormat_PACK_BITS_SHIFT;
		vt = v >> TinyImageFormat_PACK_TYPE_SHIFT;
		vs = v >> TinyImageFormat_PACK_SWIZZLE_SHIFT;

		for (int i = TinyImageFormat_PACK_NUM_CHANNELS - 1; i >= 0; --i) {
			TinyImageFormat_Pack_Swizzle
					swiz = (TinyImageFormat_Pack_Swizzle) (vs & Mask(TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS));

			int32_t swizzle = -1;
			switch (swiz) {
			case TinyImageFormat_PACK_SWIZZLE_R: swizzle = 0;
				break;
			case TinyImageFormat_PACK_SWIZZLE_G: swizzle = 1;
				break;
			case TinyImageFormat_PACK_SWIZZLE_B: swizzle = 2;
				break;
			case TinyImageFormat_PACK_SWIZZLE_A: swizzle = 3;
				break;
			case TinyImageFormat_PACK_SWIZZLE_0: swizzle = -1;
				break;
			case TinyImageFormat_PACK_SWIZZLE_1: swizzle = -2;
				break;
			}

			TinyImageFormat_Pack_Bits
					bits = (TinyImageFormat_Pack_Bits) (vb & Mask(TinyImageFormat_PACK_BITS_REQUIRED_BITS));
			uint32_t chanBitWidth = 0;
			switch (bits) {
			case TinyImageFormat_PACK_BITS_0: break;
			case TinyImageFormat_PACK_BITS_1: chanBitWidth = 1;
				break;
			case TinyImageFormat_PACK_BITS_2: chanBitWidth = 2;
				break;
			case TinyImageFormat_PACK_BITS_3: chanBitWidth = 3;
				break;
			case TinyImageFormat_PACK_BITS_4: chanBitWidth = 4;
				break;
			case TinyImageFormat_PACK_BITS_5: chanBitWidth = 5;
				break;
			case TinyImageFormat_PACK_BITS_6: chanBitWidth = 6;
				break;
			case TinyImageFormat_PACK_BITS_7: chanBitWidth = 7;
				break;
			case TinyImageFormat_PACK_BITS_8: chanBitWidth = 8;
				break;
			case TinyImageFormat_PACK_BITS_9: chanBitWidth = 9;
				break;
			case TinyImageFormat_PACK_BITS_10: chanBitWidth = 10;
				break;
			case TinyImageFormat_PACK_BITS_11: chanBitWidth = 11;
				break;
			case TinyImageFormat_PACK_BITS_12: chanBitWidth = 12;
				break;
			case TinyImageFormat_PACK_BITS_16: chanBitWidth = 16;
				break;
			case TinyImageFormat_PACK_BITS_24: chanBitWidth = 24;
				break;
			case TinyImageFormat_PACK_BITS_32: chanBitWidth = 32;
				break;
			case TinyImageFormat_PACK_BITS_64: chanBitWidth = 64;
				break;
			}
			double const maxFactor = MaxActual(name, v, TinyImageFormat_PACK_NUM_CHANNELS - i - 1, true);
			TinyImageFormat_Pack_Type
					type = (TinyImageFormat_Pack_Type) (vt & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));

			if (swizzle >= 0) {
				double normalFactor = 1.0 / maxFactor;

				// pretty up 1 bit channels by removed the 1.0 multiplier
				if (type == TinyImageFormat_PACK_TYPE_UNORM && fabs(normalFactor - 1.0) < 1e-10f)
					type = TinyImageFormat_PACK_TYPE_UINT;

				switch (type) {
				case TinyImageFormat_PACK_TYPE_UNORM:
					sprintf(output,
									"%s\t\t\tout[%d] = ((double)((val >> %lld) & 0x%llx)) * %1.8f;\n",
									output,
									j * 4 + swizzle,
									shifter,
									Mask(chanBitWidth),
									normalFactor);
					break;
				case TinyImageFormat_PACK_TYPE_SNORM:
					sprintf(output,
									"%s\t\t\tout[%d] = (((double)((val >> %lld) & 0x%llx)) * %1.8f) - 1.0;\n",
									output,
									j * 4 + swizzle,
									shifter,
									Mask(chanBitWidth),
									normalFactor);
					break;
				case TinyImageFormat_PACK_TYPE_UINT:
					sprintf(output,
									"%s\t\t\tout[%d] = (double)((val >> %lld) & 0x%llx);\n",
									output,
									j * 4 + swizzle,
									shifter,
									Mask(chanBitWidth));
					break;
				case TinyImageFormat_PACK_TYPE_SINT:
					sprintf(output,
									"%s\t\t\tout[%d] = ((double)((val >> %lld) & 0x%llx)) - %1.8f;\n",
									output,
									j * 4 + swizzle,
									shifter,
									Mask(chanBitWidth),
									maxFactor);
					break;
				case TinyImageFormat_PACK_TYPE_SRGB:
					sprintf(output,
									"%s\t\t\tout[%d] = (double)TinyImageFormat_LookupSRGB((val >> %lld) & 0x%llx);\n",
									output,
									j * 4 + swizzle,
									shifter,
									Mask(chanBitWidth));
					break;
				case TinyImageFormat_PACK_TYPE_UFLOAT:
					if (chanBitWidth == 10) {
						sprintf(output,
										"%s\t\t\tout[%d] = TinyImageFormat_UFloat10ToDouble((val >> %lld) & 0x%llx);\n",
										output,
										j * 4 + swizzle,
										shifter,
										Mask(chanBitWidth));
					} else if (chanBitWidth == 11) {
						sprintf(output,
										"%s\t\t\tout[%d] = TinyImageFormat_UFloat11ToDouble((val >> %lld) & 0x%llx);\n",
										output,
										j * 4 + swizzle,
										shifter,
										Mask(chanBitWidth));
					} else {
						ASSERT(false);
					}
					break;
				case TinyImageFormat_PACK_TYPE_SFLOAT:
					if (chanBitWidth == 16) {
						sprintf(output,
										"%s\t\t\tout[%d] = TinyImageFormat_HalfAsUintToDouble((val >> %lld) & 0x%llx);\n",
										output,
										j * 4 + swizzle,
										shifter,
										Mask(chanBitWidth));
					} else {
						ASSERT(false);
					}
					break;
				case TinyImageFormat_PACK_TYPE_SBFLOAT:
					if (chanBitWidth == 16) {
						sprintf(output,
										"%s\t\t\tout[%d] = TinyImageFormat_BFloatAsUintToDouble((val >> %lld) & 0x%llx);\n",
										output,
										j * 4 + swizzle,
										shifter,
										Mask(chanBitWidth));
					} else {
						ASSERT(false);
					}
					break;
				case TinyImageFormat_PACK_TYPE_NONE: ASSERT(false);
				}

			}
			shifter += chanBitWidth;
			vb = vb >> TinyImageFormat_PACK_BITS_REQUIRED_BITS;
			vt = vt >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
			vs = vs >> TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS;
		}

		int8_t l2p[4];
		LogicalToPhysicalChannels(name, v, l2p);

		for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			if (l2p[i] < 0) {
				sprintf(output, "%s\t\t\tout[%d] = %.f;\n", output, j * 4 + i, (double) ((-l2p[i]) - 1));
			}
		}
	}

	return true;
}
bool FetchLogicalPixelsPacked(char const *name, uint64_t const v, char *output) {
	sprintf(output, "\n");

	// special case
	if (v == TinyImageFormat_E5B9G9R9_UFLOAT) {
		char const decoder[] = "\n\t\t\tTinyImageFormat_SharedE5B9G9R9UFloatToDoubles(*(uint32_t*)in, out);\n";
		sprintf(output, decoder);
		return true;
	}

	uint64_t vspec = v >> TinyImageFormat_PACK_SPECIAL_SHIFT;

	auto special = (TinyImageFormat_Pack_Special const) (vspec & Mask(TinyImageFormat_PACK_SPECIAL_REQUIRED_BITS));
	if (special == TinyImageFormat_PACK_SPECIAL_NONE) {
		return FetchLogicalPixelsPackedNotSpecial(name, v, output);
	} else {
		return FetchLogicalPixelsPackedSpecial(name, v, output, special);
	}
}
bool FetchLogicalPixelsCLUT(char const *name, uint64_t const v, char *output) {
	return false;
}

bool FetchLogicalPixels(char const *name, uint64_t const v, char *output) {
	if (v == 0)
		return false;

	if (IsInPacked(name, v)) {
		return FetchLogicalPixelsPacked(name, v, output);

	} else if(IsInCLUT(name,v)) {
		return FetchLogicalPixelsCLUT(name, v, output);
	}
	{
		return false;
	}
}
static void GenCanFetchLogicalPixels(VFile_Handle file) {
	char buffer[2048];

	char const *const isPrefixF =
			"TIF_CONSTEXPR inline bool TinyImageFormat_CanFetchLogicalPixels(TinyImageFormat const fmt) {\n"
			"\tswitch(fmt) {\n";

	char const switchPostfixF[] = "\t\tdefault: return false;\n\t\t}\n\t}\n\n";

	char output[2048];
#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) { bool okay = FetchLogicalPixels(#x, y, output); if(okay) { sprintf(buffer, "\t\tcase %s: return true;\n", "TinyImageFormat_"#x); VFile_Write(file, buffer, strlen(buffer)); } }
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF); VFile_Write(file, buffer, strlen(buffer));
#include "formatgen.h"

}

void GenFetchLogicalPixels(VFile_Handle file) {
	char buffer[2048];

	char const *const isPrefixF =
			"TIF_CONSTEXPR inline bool TinyImageFormat_FetchLogicalPixels(TinyImageFormat const fmt, TinyImageFormat_FetchInput const* in, double* out) {\n"
			"\tswitch(fmt) {\n";

	char const switchPostfixF[] = "\t\tdefault: return false;\n\t}\n}\n\n";

	char output[2048];
#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) { bool okay = FetchLogicalPixels(#x, y, output); if(okay) { sprintf(buffer, "\t\tcase %s: {%s\t\t\treturn true;}\n", "TinyImageFormat_"#x, output); VFile_Write(file, buffer, strlen(buffer)); } }
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF); VFile_Write(file, buffer, strlen(buffer));
#include "formatgen.h"

}
static void GetSRGBTableFuncton(VFile_Handle file) {
	char const *const prefix =
			"TIF_CONSTEXPR float TinyImageFormat_LookupSRGB(uint8_t lookup) {\n"
			"\tswitch(lookup) {\n";
	char const *const body = "\t\tcase %d: return %1.8f;\n";
	char const *const postfix = "\t\tdefault: return 1.0;\n\t}\n}\n\n";

	static uint32_t const sRGBTable[256] = {
			0x00000000, 0x399f22b4, 0x3a1f22b4, 0x3a6eb40e, 0x3a9f22b4, 0x3ac6eb61, 0x3aeeb40e, 0x3b0b3e5d,
			0x3b1f22b4, 0x3b33070b, 0x3b46eb61, 0x3b5b518d, 0x3b70f18d, 0x3b83e1c6, 0x3b8fe616, 0x3b9c87fd,
			0x3ba9c9b7, 0x3bb7ad6f, 0x3bc63549, 0x3bd56361, 0x3be539c1, 0x3bf5ba70, 0x3c0373b5, 0x3c0c6152,
			0x3c15a703, 0x3c1f45be, 0x3c293e6b, 0x3c3391f7, 0x3c3e4149, 0x3c494d43, 0x3c54b6c7, 0x3c607eb1,
			0x3c6ca5df, 0x3c792d22, 0x3c830aa8, 0x3c89af9f, 0x3c9085db, 0x3c978dc5, 0x3c9ec7c2, 0x3ca63433,
			0x3cadd37d, 0x3cb5a601, 0x3cbdac20, 0x3cc5e639, 0x3cce54ab, 0x3cd6f7d5, 0x3cdfd010, 0x3ce8ddb9,
			0x3cf2212c, 0x3cfb9ac1, 0x3d02a569, 0x3d0798dc, 0x3d0ca7e6, 0x3d11d2af, 0x3d171963, 0x3d1c7c2e,
			0x3d21fb3c, 0x3d2796b2, 0x3d2d4ebb, 0x3d332380, 0x3d39152b, 0x3d3f23e3, 0x3d454fd1, 0x3d4b991c,
			0x3d51ffef, 0x3d58846a, 0x3d5f26b7, 0x3d65e6fe, 0x3d6cc564, 0x3d73c20f, 0x3d7add29, 0x3d810b67,
			0x3d84b795, 0x3d887330, 0x3d8c3e4a, 0x3d9018f6, 0x3d940345, 0x3d97fd4a, 0x3d9c0716, 0x3da020bb,
			0x3da44a4b, 0x3da883d7, 0x3daccd70, 0x3db12728, 0x3db59112, 0x3dba0b3b, 0x3dbe95b5, 0x3dc33092,
			0x3dc7dbe2, 0x3dcc97b6, 0x3dd1641f, 0x3dd6412c, 0x3ddb2eef, 0x3de02d77, 0x3de53cd5, 0x3dea5d19,
			0x3def8e52, 0x3df4d091, 0x3dfa23e8, 0x3dff8861, 0x3e027f07, 0x3e054280, 0x3e080ea3, 0x3e0ae378,
			0x3e0dc105, 0x3e10a754, 0x3e13966b, 0x3e168e52, 0x3e198f10, 0x3e1c98ad, 0x3e1fab30, 0x3e22c6a3,
			0x3e25eb09, 0x3e29186c, 0x3e2c4ed0, 0x3e2f8e41, 0x3e32d6c4, 0x3e362861, 0x3e39831e, 0x3e3ce703,
			0x3e405416, 0x3e43ca5f, 0x3e4749e4, 0x3e4ad2ae, 0x3e4e64c2, 0x3e520027, 0x3e55a4e6, 0x3e595303,
			0x3e5d0a8b, 0x3e60cb7c, 0x3e6495e0, 0x3e6869bf, 0x3e6c4720, 0x3e702e0c, 0x3e741e84, 0x3e781890,
			0x3e7c1c38, 0x3e8014c2, 0x3e82203c, 0x3e84308d, 0x3e8645ba, 0x3e885fc5, 0x3e8a7eb2, 0x3e8ca283,
			0x3e8ecb3d, 0x3e90f8e1, 0x3e932b74, 0x3e9562f8, 0x3e979f71, 0x3e99e0e2, 0x3e9c274e, 0x3e9e72b7,
			0x3ea0c322, 0x3ea31892, 0x3ea57308, 0x3ea7d289, 0x3eaa3718, 0x3eaca0b7, 0x3eaf0f69, 0x3eb18333,
			0x3eb3fc18, 0x3eb67a18, 0x3eb8fd37, 0x3ebb8579, 0x3ebe12e1, 0x3ec0a571, 0x3ec33d2d, 0x3ec5da17,
			0x3ec87c33, 0x3ecb2383, 0x3ecdd00b, 0x3ed081cd, 0x3ed338cc, 0x3ed5f50b, 0x3ed8b68d, 0x3edb7d54,
			0x3ede4965, 0x3ee11ac1, 0x3ee3f16b, 0x3ee6cd67, 0x3ee9aeb6, 0x3eec955d, 0x3eef815d, 0x3ef272ba,
			0x3ef56976, 0x3ef86594, 0x3efb6717, 0x3efe6e02, 0x3f00bd2d, 0x3f02460e, 0x3f03d1a7, 0x3f055ff9,
			0x3f06f106, 0x3f0884cf, 0x3f0a1b56, 0x3f0bb49b, 0x3f0d50a0, 0x3f0eef67, 0x3f1090f1, 0x3f12353e,
			0x3f13dc51, 0x3f15862b, 0x3f1732cd, 0x3f18e239, 0x3f1a946f, 0x3f1c4971, 0x3f1e0141, 0x3f1fbbdf,
			0x3f21794e, 0x3f23398e, 0x3f24fca0, 0x3f26c286, 0x3f288b41, 0x3f2a56d3, 0x3f2c253d, 0x3f2df680,
			0x3f2fca9e, 0x3f31a197, 0x3f337b6c, 0x3f355820, 0x3f3737b3, 0x3f391a26, 0x3f3aff7c, 0x3f3ce7b5,
			0x3f3ed2d2, 0x3f40c0d4, 0x3f42b1be, 0x3f44a590, 0x3f469c4b, 0x3f4895f1, 0x3f4a9282, 0x3f4c9201,
			0x3f4e946e, 0x3f5099cb, 0x3f52a218, 0x3f54ad57, 0x3f56bb8a, 0x3f58ccb0, 0x3f5ae0cd, 0x3f5cf7e0,
			0x3f5f11ec, 0x3f612eee, 0x3f634eef, 0x3f6571e9, 0x3f6797e3, 0x3f69c0d6, 0x3f6beccd, 0x3f6e1bbf,
			0x3f704db8, 0x3f7282af, 0x3f74baae, 0x3f76f5ae, 0x3f7933b9, 0x3f7b74c6, 0x3f7db8e0, 0x3f800000
	};

	VFile_Write(file, prefix, strlen(prefix));

	char buffer[2048];

	for (int i = 0; i < 256; ++i) {
		sprintf(buffer, body, i, ((float const *) sRGBTable)[i]);
		VFile_Write(file, buffer, strlen(buffer));
	}

	VFile_Write(file, postfix, strlen(postfix));
}

void IncludeFetchHelpers(VFile_Handle file) {
#define RAW_INCLUDE_START(x) x
	char const *otherEnums =
#include "fetchhelpers.h"
			"";
#undef RAW_INCLUDE_START

	// skip first ) and last line, artifacts of the include system
	char const *start = otherEnums;
	while (*start != ')')
		start++;

	char const *end = otherEnums + strlen(otherEnums);
	while (*end != 'R')
		end--;

	VFile_Write(file, start + 1, end - start - 1);
}

void GenFetch(VFile_Handle file) {
	GenMaxPixelCountOfBlock(file);

	IncludeFetchHelpers(file);
	GetSRGBTableFuncton(file);
	GenCanFetchLogicalPixels(file);
	GenFetchLogicalPixels(file);

}