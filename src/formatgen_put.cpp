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
uint32_t ChannelCount(char const *name, uint64_t v);
uint32_t ChannelWidth(char const *name, uint64_t const v, uint32_t chan);

bool PutLogicalPixelsPacked(char const *name,
														uint64_t const v,
														uint32_t const inputFloatWidth,
														char *output) {
	sprintf(output, "\n");
	uint32_t maxChanWidth = 0;
	for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
		uint32_t chanWidth = ChannelWidth(name, v, i);
		if (chanWidth > maxChanWidth)
			maxChanWidth = chanWidth;
	}

	if (maxChanWidth > inputFloatWidth) {
		return false;
	}

	// special case
	if (v == TinyImageFormat_E5B9G9R9_UFLOAT) {
		/*		if (outputFloatWidth == 32) {
					char const decoder[] = "\n\t\t\t\tTinyImageFormat_SharedE5B9G9R9UFloatToFloats(*(uint32_t*)in->pixel, out);\n"
																 "\t\t\t\tin->pixel = (void const*)(((uint32_t const*)in->pixel) + 1);\n"
																 "\t\t\t\tout += 4;\n";
					sprintf(output, decoder);
					return true;
				} else*/ {
			return false;
		}
	}

	uint64_t vspec = v >> TinyImageFormat_PACK_SPECIAL_SHIFT;

	auto special = (TinyImageFormat_Pack_Special const) (vspec & Mask(TinyImageFormat_PACK_SPECIAL_REQUIRED_BITS));

	// how wide is the total pixel format we put to
	uint32_t bitWidth = 0;
	for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
		bitWidth += ChannelWidth(name, v, i);
	}
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
	bitWidth *= repeat;

	char const *loadOut;
	char const *nextPixelBuffer;
	char castBuffer[2048];

	uint32_t outTypeSize = 0;
	switch (bitWidth) {
	case 8:
	case 24: loadOut = "\t\t\t\tuint8_t* op%d = (uint8_t*)out->pixel; *op%d = 0;\n";
		nextPixelBuffer = "\t\t\t\tout->pixel = (void*)(((uint8_t*)out->pixel) + 1);\n";
		outTypeSize = 8;
		break;
	case 48:
	case 16: loadOut = "\t\t\t\tuint16_t* op%d = (uint16_t*)out->pixel; *op%d = 0;\n";
		nextPixelBuffer = "\t\t\t\tout->pixel = (void*)(((uint16_t*)out->pixel) + 1);\n";
		outTypeSize = 16;
		break;
	case 96:
	case 32: loadOut = "\t\t\t\tuint32_t* op%d = (uint32_t*)out->pixel; *op%d = 0;\n";
		nextPixelBuffer = "\t\t\t\tout->pixel = (void*)(((uint32_t*)out->pixel) + 1);\n";
		outTypeSize = 32;
		break;
	case 256:
	case 192:
	case 128:
	case 64: loadOut = "\t\t\t\tuint64_t* op%d = (uint64_t*)out->pixel; *op%d = 0;\n";
		nextPixelBuffer = "\t\t\t\tout->pixel = (void*)(((uint64_t*)out->pixel) + 1);\n";
		outTypeSize = 64;
		break;

	default: ASSERT(false);
	}

	ASSERT(outTypeSize != 0);
	sprintf(castBuffer, "(uint%d_t)", outTypeSize);

	uint64_t shifter = 0;
	bool load = true;
	uint32_t loadIndex = 0;
	for (uint32_t j = 0; j < repeat; j++) {
		uint64_t vt = v >> TinyImageFormat_PACK_TYPE_SHIFT;
		uint64_t vs = v >> TinyImageFormat_PACK_SWIZZLE_SHIFT;

		for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint32_t const chanBitWidth = ChannelWidth(name, v, i);
			auto swiz = (TinyImageFormat_Pack_Swizzle const) (vs & Mask(TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS));

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
			case TinyImageFormat_PACK_SWIZZLE_1: swizzle = -2;
				break;
			}

			if (swizzle >= 0 && i < ChannelCount(name, v)) {
				if (shifter >= outTypeSize) {
					sprintf(output, "%s%s", output, nextPixelBuffer);
					shifter -= outTypeSize;
					load = true;
				}
				if (load) {
					char tmp[2048];
					loadIndex = (j * TinyImageFormat_PACK_NUM_CHANNELS) + i;
					sprintf(tmp, loadOut, loadIndex, loadIndex);
					sprintf(output, "%s%s", output, tmp);
					load = false;
				}

				double const maxFactor = MaxActual(name, v, i, true);
				auto type = (TinyImageFormat_Pack_Type) (vt & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));

				switch (type) {
				case TinyImageFormat_PACK_TYPE_UNORM:
					sprintf(output,
									"%s\t\t\t\t*op%d |= (%s(in[%d] * %1.2ff) & 0x%llx) << %lld;\n",
									output,
									loadIndex,
									castBuffer,
									j * 4 + swizzle,
									maxFactor,
									Mask(chanBitWidth),
									shifter);
					break;
				case TinyImageFormat_PACK_TYPE_SNORM:
					sprintf(output,
									"%s\t\t\t\t*op%d |= ((%s(((in[%d] + 1.0f) * 0.5f) * %1.2ff)) & 0x%llx) << %lld;\n",
									output,
									loadIndex,
									castBuffer,
									j * 4 + swizzle,
									(maxFactor * 2) + 1,
									Mask(chanBitWidth),
									shifter);
					break;
				case TinyImageFormat_PACK_TYPE_SINT:
					sprintf(output,
									"%s\t\t\t\t*op%d |= ((%s(in[%d] + %1.2ff)) & 0x%llx) << %lld;\n",
									output,
									loadIndex,
									castBuffer,
									j * 4 + swizzle,
									maxFactor + 1,
									Mask(chanBitWidth),
									shifter);
					break;
				case TinyImageFormat_PACK_TYPE_UINT:
					sprintf(output,
									"%s\t\t\t\t*op%d |= ((%sin[%d]) & 0x%llx) << %lld;\n",
									output,
									loadIndex,
									castBuffer,
									j * 4 + swizzle,
									Mask(chanBitWidth),
									shifter);
					break;
				case TinyImageFormat_PACK_TYPE_SRGB:
					sprintf(output,
									"%s\t\t\t\t*op%d |= (%sTinyImageFormat_Float2SRGB((float)in[%d])) << %lld;\n",
									output,
									loadIndex,
									castBuffer,
									j * 4 + swizzle,
									shifter);
					break;
				case TinyImageFormat_PACK_TYPE_UFLOAT:
					/*					if (chanBitWidth == 10) {
											sprintf(output,
															"%s\t\t\t\tout[%d] = (%s)TinyImageFormat_UFloat10ToFloat((val >> %lld) & 0x%llx);\n",
															output,
															j * 4 + swizzle,
															outputCast,
															shifter,
															Mask(chanBitWidth));
										} else if (chanBitWidth == 11) {
											sprintf(output,
															"%s\t\t\t\tout[%d] = (%s)TinyImageFormat_UFloat11ToFloat((val >> %lld) & 0x%llx);\n",
															output,
															j * 4 + swizzle,
															outputCast,
															shifter,
															Mask(chanBitWidth));
										} else {
											ASSERT(false);
										}*/
					break;
				case TinyImageFormat_PACK_TYPE_SFLOAT:
					if (chanBitWidth == 16) {
						/*						sprintf(output,
																"%s\t\t\t\t*op%d |= TinyImageFormat_FloatToHalfAsUint((float)in[%d]) << %lld;\n",
																output,
																loadIndex,
																j * 4 + swizzle,
																shifter);*/
					} else if (chanBitWidth == 32) {
						sprintf(output,
										"%s\t\t\t\tfloat in%d = (float)in[%d];\n"
										"\t\t\t\t*op%d |= (%s*((uint32_t*)&in%d)) << %lld;\n",
										output,
										j * 4 + swizzle,
										j * 4 + swizzle,
										loadIndex,
										castBuffer,
										j * 4 + swizzle,
										shifter);
					} else if (chanBitWidth == 64) {
						sprintf(output,
										"%s\t\t\t\tdouble in%d = (double)in[%d];\n"
										"\t\t\t\t*op%d |= (%s*((uint64_t*)&in%d)) << %lld;\n",
										output,
										j * 4 + swizzle,
										j * 4 + swizzle,
										loadIndex,
										castBuffer,
										j * 4 + swizzle,
										shifter);
					}
					break;
				case TinyImageFormat_PACK_TYPE_SBFLOAT:
					if (chanBitWidth == 16) {
						sprintf(output,
										"%s\t\t\t\t*op%d |= (%sTinyImageFormat_FloatToBFloatAsUint((float)in[%d])) << %lld;\n",
										output,
										loadIndex,
										castBuffer,
										j * 4 + swizzle,
										shifter);
					} else {
						ASSERT(false);
					}
					break;
				case TinyImageFormat_PACK_TYPE_NONE: ASSERT(false);
				}

			}
			shifter += chanBitWidth;
			vt = vt >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
			vs = vs >> TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS;
		}
	}
	sprintf(output, "%s%s", output, nextPixelBuffer);
	sprintf(output, "%s\t\t\t\tin+=%d;\n", output, 4 * repeat);

	return true;
}

bool PutLogicalPixelsF(char const *name, uint64_t const v, char *output) {
	if (v == 0)
		return false;

	if (IsInPacked(name, v)) {
		return PutLogicalPixelsPacked(name, v, 32, output);
	}/* else if (IsInCLUT(name, v)) {
		return PutLogicalPixelsCLUT(name, v, 32, output);
	}*/

	return false;
}

bool PutLogicalPixelsD(char const *name, uint64_t const v, char *output) {
	if (v == 0)
		return false;

	uint32_t maxChanWidth = 0;
	for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
		uint32_t chanWidth = ChannelWidth(name, v, i);
		if (chanWidth > maxChanWidth)
			maxChanWidth = chanWidth;
	}

	if (maxChanWidth < 64) {
		return false;
	}

	if (IsInPacked(name, v)) {
		return PutLogicalPixelsPacked(name, v, 64, output);

	} else if (IsInCLUT(name, v)) {
		//		return PutLogicalPixelsCLUT(name, v, 64, output);
	}
	return false;
}

static void GenCanPutLogicalPixelsF(VFile_Handle file) {
	char buffer[2048];

	char const *const isPrefixF =
			"TIF_CONSTEXPR inline bool TinyImageFormat_CanPutLogicalPixelsF(TinyImageFormat const fmt) {\n"
			"\tswitch(fmt) {\n";

	char const *const body = "\t\tcase %s: return true;\n";
	char const switchPostfixF[] = "\t\tdefault: return false;\n\t\t}\n\t}\n\n";

	char output[2048];
#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) { bool okay = PutLogicalPixelsF(#x, y, output); if(okay) { sprintf(buffer, body, "TinyImageFormat_"#x); VFile_Write(file, buffer, strlen(buffer)); } }
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF); VFile_Write(file, buffer, strlen(buffer));
#include "formatgen.h"

}

void GenPutLogicalPixelsF(VFile_Handle file) {
	char buffer[2048];

	char const *const isPrefixF =
			"TIF_CONSTEXPR inline bool TinyImageFormat_PutLogicalPixelsF(TinyImageFormat const fmt, float const *in, uint32_t const width, TinyImageFormat_PutOutput * out) {\n"
			"\tswitch(fmt) {\n";
	char const *const body = "\t\tcase %s:\n\t\t\tfor(uint32_t w = 0; w < width; ++w) {"
													 "%s"
													 "\t\t\t}\n\t\t\treturn true;\n";

	char const switchPostfixF[] = "\t\tdefault: return false;\n\t}\n}\n\n";

	char output[2048];
#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) { bool okay = PutLogicalPixelsF(#x, y, output); if(okay) { sprintf(buffer, body, "TinyImageFormat_"#x, output); VFile_Write(file, buffer, strlen(buffer)); } }
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF); VFile_Write(file, buffer, strlen(buffer));
#include "formatgen.h"
}

static void GenCanPutLogicalPixelsD(VFile_Handle file) {
	char buffer[2048];

	char const *const isPrefixF =
			"TIF_CONSTEXPR inline bool TinyImageFormat_CanPutLogicalPixelsD(TinyImageFormat const fmt) {\n"
			"\tswitch(fmt) {\n";

	char const *const body = "\t\tcase %s: return true;\n";
	char const switchPostfixF[] = "\t\tdefault: return TinyImageFormat_CanPutLogicalPixelsF(fmt);\n"
																"\t}\n}\n\n";

	char output[2048];
#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) { bool okay = PutLogicalPixelsD(#x, y, output); if(okay) { sprintf(buffer, body, "TinyImageFormat_"#x); VFile_Write(file, buffer, strlen(buffer)); } }
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF); VFile_Write(file, buffer, strlen(buffer));
#include "formatgen.h"

}

void GenPutLogicalPixelsD(VFile_Handle file) {
	char buffer[2048];

	char const *const isPrefixF =
			"TIF_CONSTEXPR inline bool TinyImageFormat_PutLogicalPixelsD(TinyImageFormat const fmt, double const *in, uint32_t const width, TinyImageFormat_PutOutput * out) {\n"
			"\tswitch(fmt) {\n";
	char const *const body = "\t\tcase %s:\n\t\t\tfor(uint32_t w = 0; w < width; ++w) {"
													 "%s"
													 "\t\t\t}\n\t\t\treturn true;\n";

	char const switchPostfixF[] = "\t\tdefault:\n"
																"\t\t{\n"
																"\t\t\tbool ret = true;\n"
																"\t\t\tfor(uint32_t w = 0; w < width && ret; ++w) {\n"
																"\t\t\t\tfloat inF[4] = {(float)in[0], (float)in[1], (float)in[2], (float)in[3]};\n"
																"\t\t\t\tret = TinyImageFormat_PutLogicalPixelsF(fmt, inF, 1, out);\n"
																"\t\t\t\tin += 4;\n"
																"\t\t\t}\n"
																"\t\t\treturn ret;\n"
																"\t\t}\n"
																"\t}\n"
																"}\n\n";

	char output[2048];
#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) { bool okay = PutLogicalPixelsD(#x, y, output); if(okay) { sprintf(buffer, body, "TinyImageFormat_"#x, output); VFile_Write(file, buffer, strlen(buffer)); } }
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF); VFile_Write(file, buffer, strlen(buffer));
#include "formatgen.h"
}

void IncludePutHelpers(VFile_Handle file) {
#define RAW_INCLUDE_START(x) x
	char const *otherEnums =
#include "puthelpers.h"
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

void GenPut(VFile_Handle file) {
	IncludePutHelpers(file);

	//	GetSRGBTableFuncton(file);

	GenCanPutLogicalPixelsF(file);
	GenPutLogicalPixelsF(file);
	GenCanPutLogicalPixelsD(file);
	GenPutLogicalPixelsD(file);

}

