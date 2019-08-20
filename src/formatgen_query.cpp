#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <cfloat>
#include <cmath>
#include "al2o3_vfile/vfile.h"
#include "../include/tiny_imageformat/tinyimageformat_bits.h"
#include "formatgen.h"

void GenCode(VFile_Handle file) {
	char const isPrefixF[] =
		"TIF_CONSTEXPR inline uint64_t TinyImageFormat_Code(TinyImageFormat const fmt) {\n"
		"\tswitch(fmt) {\n";
	char const switchPostfixF[] = "\t\tdefault: return 0ULL;\n\t}\n}\n\n";

	char buffer[2048];

#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) sprintf(buffer, "\t\tcase %s: return 0x%.16" PRIX64 ";\n", "TinyImageFormat_"#x, y); \
                                                               VFile_Write(file, buffer, strlen(buffer));
#define  TinyImageFormat_END_MACRO VFile_Write(file, switchPostfixF, strlen(switchPostfixF));
#include "formatgen.h"

}

bool IsDepthOnly(char const *name, uint64_t v) {
	if (!IsInDepthStencil(name, v))
		return false;

	bool hasDepth = false;
	bool hasStencil = false;
	v = v >> TinyImageFormat_DEPTH_STENCIL_SWIZZLE_SHIFT;
	for (uint32_t i = 0; i < TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS; ++i) {
		uint64_t const swiz = (v & Mask(TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS));
		if (swiz == TinyImageFormat_DEPTH_STENCIL_SWIZZLE_D)
			hasDepth = true;
		if (swiz == TinyImageFormat_DEPTH_STENCIL_SWIZZLE_S)
			hasStencil = true;

		v = v >> TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS;
	}

	return hasDepth && !hasStencil;
}

bool IsStencilOnly(char const *name, uint64_t v) {
	if (!IsInDepthStencil(name, v))
		return false;

	bool hasDepth = false;
	bool hasStencil = false;
	v = v >> TinyImageFormat_DEPTH_STENCIL_SWIZZLE_SHIFT;
	for (uint32_t i = 0; i < TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS; ++i) {
		uint64_t const swiz = (v & Mask(TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS));
		if (swiz == TinyImageFormat_DEPTH_STENCIL_SWIZZLE_D)
			hasDepth = true;
		if (swiz == TinyImageFormat_DEPTH_STENCIL_SWIZZLE_S)
			hasStencil = true;

		v = v >> TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS;
	}

	return !hasDepth && hasStencil;
}

bool IsDepthAndStencil(char const *name, uint64_t v) {
	if (!IsInDepthStencil(name, v))
		return false;

	bool hasDepth = false;
	bool hasStencil = false;
	v = v >> TinyImageFormat_DEPTH_STENCIL_SWIZZLE_SHIFT;
	for (uint32_t i = 0; i < TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS; ++i) {
		uint64_t const swiz = (v & Mask(TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS));
		if (swiz == TinyImageFormat_DEPTH_STENCIL_SWIZZLE_D)
			hasDepth = true;
		if (swiz == TinyImageFormat_DEPTH_STENCIL_SWIZZLE_S)
			hasStencil = true;

		v = v >> TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS;
	}

	return hasDepth && hasStencil;
}

bool IsCLUT(char const *name, uint64_t v) {
	if (IsInCLUT(name, v)) {
		return true;
	} else {
		return false;
	}
}

bool IsFloat(char const *name, uint64_t v) {

	if (IsInPacked(name, v)) {
		v = v >> TinyImageFormat_PACK_TYPE_SHIFT;
		for (uint32_t i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint64_t const chanType = (v & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
			if ((chanType == TinyImageFormat_PACK_TYPE_SFLOAT) ||
					(chanType == TinyImageFormat_PACK_TYPE_UFLOAT) ||
					(chanType == TinyImageFormat_PACK_TYPE_SBFLOAT))
				return true;

			v = v >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
		}
	}

	if (IsInDepthStencil(name, v)) {
		v = v >> TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS;
		for (uint32_t i = 0; i < TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS));
			if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_SFLOAT)
				return true;

			v = v >> TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS;
		}
	}

	if (IsInDXTC(name, v)) {
		v = v >> TinyImageFormat_DXTC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_DXTC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_DXTC_TYPE_SFLOAT || type == TinyImageFormat_DXTC_TYPE_UFLOAT)
			return true;
	}

	return false;
}

bool IsNormalised(char const *name, uint64_t v) {

	if (IsInPacked(name, v)) {
		v = v >> TinyImageFormat_PACK_TYPE_SHIFT;
		for (uint32_t i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
			if (type == TinyImageFormat_PACK_TYPE_SNORM ||
					type == TinyImageFormat_PACK_TYPE_UNORM ||
					type == TinyImageFormat_PACK_TYPE_SRGB
					)
				return true;

			v = v >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
		}
	}

	if (IsInDepthStencil(name, v)) {
		v = v >> TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS;
		for (uint32_t i = 0; i < TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS));
			if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_UNORM)
				return true;

			v = v >> TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS;
		}
	}
	if (IsInDXTC(name, v)) {
		v = v >> TinyImageFormat_DXTC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_DXTC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_DXTC_TYPE_SNORM ||
				type == TinyImageFormat_DXTC_TYPE_UNORM ||
				type == TinyImageFormat_DXTC_TYPE_SRGB
				)
			return true;
	}

	if (IsInPVRTC(name, v)) {
		v = v >> TinyImageFormat_PVRTC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_PVRTC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_PVRTC_TYPE_UNORM ||
				type == TinyImageFormat_PVRTC_TYPE_SRGB
				)
			return true;
	}

	if (IsInETC(name, v)) {
		v = v >> TinyImageFormat_ETC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_ETC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_ETC_TYPE_SNORM ||
				type == TinyImageFormat_ETC_TYPE_UNORM ||
				type == TinyImageFormat_ETC_TYPE_SRGB
				)
			return true;

	}

	if (IsInASTC(name, v)) {
		v = v >> TinyImageFormat_ASTC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_ASTC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_ASTC_TYPE_UNORM ||
				type == TinyImageFormat_ASTC_TYPE_SRGB
				)
			return true;
	}

	return false;
}

bool IsSigned(char const *name, uint64_t v) {

	if (IsInPacked(name, v)) {
		v = v >> TinyImageFormat_PACK_TYPE_SHIFT;
		for (uint32_t i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
			if (type == TinyImageFormat_PACK_TYPE_SNORM ||
					type == TinyImageFormat_PACK_TYPE_SFLOAT ||
					type == TinyImageFormat_PACK_TYPE_SINT ||
					type == TinyImageFormat_PACK_TYPE_SBFLOAT
					)
				return true;

			v = v >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
		}
	}

	if (IsInDepthStencil(name, v)) {
		v = v >> TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS;
		for (uint32_t i = 0; i < TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS));
			if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_SFLOAT)
				return true;

			v = v >> TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS;
		}
	}

	if (IsInDXTC(name, v)) {
		v = v >> TinyImageFormat_DXTC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_DXTC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_DXTC_TYPE_SNORM ||
				type == TinyImageFormat_DXTC_TYPE_SFLOAT
				)
			return true;
	}

	if (IsInETC(name, v)) {
		v = v >> TinyImageFormat_ETC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_ETC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_ETC_TYPE_SNORM)
			return true;

	}

	return false;
}

bool IsSRGB(char const *name, uint64_t v) {

	if (IsInPacked(name, v)) {
		v = v >> TinyImageFormat_PACK_TYPE_SHIFT;
		for (uint32_t i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
			if (type == TinyImageFormat_PACK_TYPE_SRGB)
				return true;

			v = v >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
		}
	}

	if (IsInDXTC(name, v)) {
		v = v >> TinyImageFormat_DXTC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_DXTC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_DXTC_TYPE_SRGB)
			return true;
	}

	if (IsInPVRTC(name, v)) {
		v = v >> TinyImageFormat_PVRTC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_PVRTC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_PVRTC_TYPE_SRGB)
			return true;
	}

	if (IsInETC(name, v)) {
		v = v >> TinyImageFormat_ETC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_ETC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_ETC_TYPE_SRGB)
			return true;

	}

	if (IsInASTC(name, v)) {
		v = v >> TinyImageFormat_ASTC_TYPE_SHIFT;
		uint64_t const type = (v & Mask(TinyImageFormat_ASTC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_ASTC_TYPE_SRGB)
			return true;
	}

	return false;
}

bool IsCompressed(char const *name, uint64_t v) {

	if (IsInDXTC(name, v)) {
		return true;
	}

	if (IsInPVRTC(name, v)) {
		return true;
	}

	if (IsInETC(name, v)) {
		return true;
	}

	if (IsInASTC(name, v)) {
		return true;
	}

	return false;
}

uint32_t SizeOfBlock(char const *name, uint64_t v, uint64_t dim) {
	if (v == 0)
		return 0;

	if (IsInPacked(name, v)) {
		if (dim == 0) {
			uint64_t vspec = v >> TinyImageFormat_PACK_SPECIAL_SHIFT;
			auto special = (TinyImageFormat_Pack_Special const) (vspec & Mask(TinyImageFormat_PACK_SPECIAL_REQUIRED_BITS));
			switch (special) {
			case TinyImageFormat_PACK_SPECIAL_NONE:return 1;
			case TinyImageFormat_PACK_SPECIAL_PACK:return 1;
			case TinyImageFormat_PACK_SPECIAL_MULTI2:return 2;
			case TinyImageFormat_PACK_SPECIAL_MULTI4:return 4;
			case TinyImageFormat_PACK_SPECIAL_MULTI8:return 8;
			}
		} else {
			return 1;
		}
	}

	if (IsInDXTC(name, v)) {
		if (dim < 2)
			return 4;
	}

	if (IsInPVRTC(name, v)) {
		v = v >> TinyImageFormat_PVRTC_BITS_SHIFT;
		if (dim == 0) {
			auto bits = (TinyImageFormat_PVRTC_Bits const) (v & Mask(TinyImageFormat_PVRTC_BITS_REQUIRED_BITS));
			switch (bits) {
			case TinyImageFormat_PVRTC_BITS_2: return 8;
			case TinyImageFormat_PVRTC_BITS_4: return 4;
			}
		} else if (dim == 1) {
			return 4;
		}
	}

	if (IsInETC(name, v)) {
		if (dim < 2)
			return 4;
	}

	if (IsInASTC(name, v)) {
		v = v >> TinyImageFormat_ASTC_SIZE_SHIFT;
		v = v >> dim * TinyImageFormat_ASTC_SIZE_REQUIRED_BITS;

		auto size = (TinyImageFormat_ASTC_Size const) (v & Mask(TinyImageFormat_ASTC_SIZE_REQUIRED_BITS));
		switch (size) {
		case TinyImageFormat_ASTC_SIZE_1: return 1;
		case TinyImageFormat_ASTC_SIZE_4: return 4;
		case TinyImageFormat_ASTC_SIZE_5: return 5;
		case TinyImageFormat_ASTC_SIZE_6: return 6;
		case TinyImageFormat_ASTC_SIZE_8: return 8;
		case TinyImageFormat_ASTC_SIZE_10: return 10;
		case TinyImageFormat_ASTC_SIZE_12: return 12;
		}
	}
	if (IsInCLUT(name, v) && dim == 0) {
		v = v >> TinyImageFormat_CLUT_BLOCKSIZE_SHIFT;
		auto bs = (TinyImageFormat_CLUT_BlockSize const) (v & Mask(TinyImageFormat_CLUT_BLOCKSIZE_REQUIRED_BITS));
		switch (bs) {
		case TinyImageFormat_CLUT_BLOCKSIZE_1: return 1;
		case TinyImageFormat_CLUT_BLOCKSIZE_2: return 2;
		case TinyImageFormat_CLUT_BLOCKSIZE_4: return 4;
		case TinyImageFormat_CLUT_BLOCKSIZE_8: return 8;
		}
	}

	return 1;
}

uint32_t WidthOfBlock(char const *name, uint64_t v) {
	return SizeOfBlock(name, v, 0);
}
uint32_t HeightOfBlock(char const *name, uint64_t v) {
	return SizeOfBlock(name, v, 1);
}
uint32_t DepthOfBlock(char const *name, uint64_t v) {
	return SizeOfBlock(name, v, 2);
}

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

uint32_t ChannelCount(char const *name, uint64_t v) {
	if (v == 0)
		return 0;

	if (IsInPacked(name, v)) {
		v = v >> TinyImageFormat_PACK_TYPE_SHIFT;

		uint32_t count = 0;
		for (uint32_t i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
			if (type != TinyImageFormat_PACK_TYPE_NONE)
				count++;
			v = v >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
		}

		ASSERT(count > 0);
		return count;
	}

	if (IsInDepthStencil(name, v)) {
		v = v >> TinyImageFormat_DEPTH_STENCIL_TYPE_SHIFT;

		uint32_t count = 0;
		for (uint32_t i = 0; i < TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS));
			if (type != TinyImageFormat_DEPTH_STENCIL_TYPE_NONE)
				count++;
			v = v >> TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS;
		}

		ASSERT(count > 0);
		return count;
	}

	if (IsInDXTC(name, v)) {
		v = v >> TinyImageFormat_DXTC_CHANNELCOUNT_SHIFT;
		uint64_t const chans = (v & Mask(TinyImageFormat_DXTC_CHANNELCOUNT_REQUIRED_BITS));
		return (uint32_t) (chans + 1);
	}

	if (IsInPVRTC(name, v)) {
		return 4;
	}

	if (IsInETC(name, v)) {
		v = v >> TinyImageFormat_ETC_CHANNELCOUNT_SHIFT;
		uint64_t const chans = (v & Mask(TinyImageFormat_ETC_CHANNELCOUNT_REQUIRED_BITS));
		return (uint32_t) (chans + 1);
	}

	if (IsInASTC(name, v)) {
		return 4;
	}
	if (IsInCLUT(name, v)) {
		v = v >> TinyImageFormat_CLUT_TYPE_SHIFT;

		uint32_t count = 0;
		for (uint32_t i = 0; i < TinyImageFormat_CLUT_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_CLUT_TYPE_REQUIRED_BITS));
			if (type != TinyImageFormat_CLUT_TYPE_NONE)
				count++;
			v = v >> TinyImageFormat_CLUT_TYPE_REQUIRED_BITS;
		}

		ASSERT(count > 0);
		return count;
	}

	ASSERT(false);
	return 0;
}

uint32_t ChannelBitWidth(char const *name, uint64_t v, uint32_t chan) {
	if (v == 0)
		return 0;

	if (IsInPacked(name, v)) {
		v = v >> TinyImageFormat_PACK_BITS_SHIFT;

		v = v >> (chan * TinyImageFormat_PACK_BITS_REQUIRED_BITS);
		uint64_t bits = (v & Mask(TinyImageFormat_PACK_BITS_REQUIRED_BITS));

		switch (bits) {
		case TinyImageFormat_PACK_BITS_0: return 0;
		case TinyImageFormat_PACK_BITS_1: return 1;
		case TinyImageFormat_PACK_BITS_2: return 2;
		case TinyImageFormat_PACK_BITS_3: return 3;
		case TinyImageFormat_PACK_BITS_4: return 4;
		case TinyImageFormat_PACK_BITS_5: return 5;
		case TinyImageFormat_PACK_BITS_6: return 6;
		case TinyImageFormat_PACK_BITS_7: return 7;
		case TinyImageFormat_PACK_BITS_8: return 8;
		case TinyImageFormat_PACK_BITS_9: return 9;
		case TinyImageFormat_PACK_BITS_10: return 10;
		case TinyImageFormat_PACK_BITS_11: return 11;
		case TinyImageFormat_PACK_BITS_12: return 12;
		case TinyImageFormat_PACK_BITS_16: return 16;
		case TinyImageFormat_PACK_BITS_24: return 24;
		case TinyImageFormat_PACK_BITS_32: return 32;
		case TinyImageFormat_PACK_BITS_64: return 64;
		default: ASSERT(false);
		}
	}

	if (IsInDepthStencil(name, v)) {
		if (chan >= TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS)
			return 0;

		v = v >> TinyImageFormat_DEPTH_STENCIL_BITS_SHIFT;

		v = v >> (chan * TinyImageFormat_DEPTH_STENCIL_BITS_REQUIRED_BITS);
		uint64_t bits = (v & Mask(TinyImageFormat_DEPTH_STENCIL_BITS_REQUIRED_BITS));

		switch (bits) {
		case TinyImageFormat_DEPTH_STENCIL_BITS_0: return 0;
		case TinyImageFormat_DEPTH_STENCIL_BITS_8: return 8;
		case TinyImageFormat_DEPTH_STENCIL_BITS_16: return 16;
		case TinyImageFormat_DEPTH_STENCIL_BITS_24: return 24;
		case TinyImageFormat_DEPTH_STENCIL_BITS_32: return 32;
		default: ASSERT(false);
		}
	}

	// compressed formats bit width per channel can be hard
	// so these values are crude and possible wrong!
	if (IsInDXTC(name, v)) {
		uint64_t backupV = v;
		v = v >> TinyImageFormat_DXTC_TYPE_SHIFT;
		uint64_t type = (v & Mask(TinyImageFormat_DXTC_TYPE_REQUIRED_BITS));
		if (type == TinyImageFormat_DXTC_TYPE_SFLOAT ||
				type == TinyImageFormat_DXTC_TYPE_UFLOAT)
			return 16;

		// BC 4 and 5 are 8 bit precision per channel
		if (ChannelCount(name, backupV) < 3) {
			return 8;
		}

		// otherwise 565 except BC7 (which is variable so we give it an 8)
		if (chan != 3) {
			v = backupV;
			v = v >> TinyImageFormat_DXTC_MODECOUNT_SHIFT;
			uint64_t modecount = (v & Mask(TinyImageFormat_DXTC_MODECOUNT_REQUIRED_BITS));
			if (modecount != TinyImageFormat_DXTC_MODECOUNT_1)
				return 8;
		}

		if (chan == 0)
			return 5;
		else if (chan == 1)
			return 6;
		else if (chan == 2)
			return 5;
		else {
			// alpha
			v = backupV;
			v = v >> TinyImageFormat_DXTC_ALPHA_SHIFT;
			uint64_t alpha = (v & TinyImageFormat_DXTC_ALPHA_REQUIRED_BITS);
			if (alpha == TinyImageFormat_DXTC_ALPHA_NONE)
				return 0;
			else if (alpha == TinyImageFormat_DXTC_ALPHA_PUNCHTHROUGH)
				return 1;
			else if (alpha == TinyImageFormat_DXTC_ALPHA_BLOCK)
				return 4;
		}
	}

	if (IsInETC(name, v)) {
		uint64_t backupV = v;
		v = v >> TinyImageFormat_ETC_BITS_SHIFT;
		uint64_t bits = (v & Mask(TinyImageFormat_ETC_BITS_REQUIRED_BITS));
		if (bits == TinyImageFormat_ETC_BITS_11)
			return 11;
		else if (chan == 4) {
			// alpha
			v = backupV;
			v = v >> TinyImageFormat_ETC_ALPHA_SHIFT;
			uint64_t alpha = (v & TinyImageFormat_ETC_ALPHA_REQUIRED_BITS);
			if (alpha == TinyImageFormat_ETC_ALPHA_NONE)
				return 0;
			else if (alpha == TinyImageFormat_ETC_ALPHA_PUNCHTHROUGH)
				return 1;
			else if (alpha == TinyImageFormat_ETC_ALPHA_BLOCK)
				return 4;
		}
	}
	if (IsInCLUT(name, v)) {
		v = v >> TinyImageFormat_CLUT_BITS_SHIFT;
		if (chan >= TinyImageFormat_CLUT_NUM_CHANNELS)
			return 0;

		v = v >> (chan * TinyImageFormat_CLUT_BITS_REQUIRED_BITS);
		TinyImageFormat_CLUT_Bits const
				bits = (TinyImageFormat_CLUT_Bits) (v & Mask(TinyImageFormat_CLUT_BITS_REQUIRED_BITS));
		switch (bits) {
		case TinyImageFormat_CLUT_BITS_0:return 0;
		case TinyImageFormat_CLUT_BITS_1:return 1;
		case TinyImageFormat_CLUT_BITS_2:return 2;
		case TinyImageFormat_CLUT_BITS_4:return 4;
		case TinyImageFormat_CLUT_BITS_8:return 8;
		}
		ASSERT(false);
	}

	return 8;
}

static uint32_t BitSizeOfBlock(char const *name, uint64_t v) {
	if (v == 0)
		return 0;

	if (IsInPacked(name, v)) {
		uint64_t vspec = v >> TinyImageFormat_PACK_SPECIAL_SHIFT;

		auto special = (TinyImageFormat_Pack_Special const) (vspec & Mask(TinyImageFormat_PACK_SPECIAL_REQUIRED_BITS));
		v = v >> TinyImageFormat_PACK_BITS_SHIFT;
		uint32_t count = 0;
		for (uint32_t chan = 0; chan < TinyImageFormat_PACK_NUM_CHANNELS; ++chan) {
			uint64_t const bits = (v & Mask(TinyImageFormat_PACK_BITS_REQUIRED_BITS));
			if (bits <= TinyImageFormat_PACK_BITS_12)
				count += (uint32_t) bits;
			else {
				switch (bits) {
				case TinyImageFormat_PACK_BITS_16: count += 16;
					break;
				case TinyImageFormat_PACK_BITS_24: count += 24;
					break;
				case TinyImageFormat_PACK_BITS_32: count += 32;
					break;
				case TinyImageFormat_PACK_BITS_64: count += 64;
					break;
				default: ASSERT(false);
				}
			}
			v = v >> TinyImageFormat_PACK_BITS_REQUIRED_BITS;
		}

		switch (special) {
		case TinyImageFormat_PACK_SPECIAL_NONE:break;
		case TinyImageFormat_PACK_SPECIAL_PACK:break;
		case TinyImageFormat_PACK_SPECIAL_MULTI2:count *= 2;
			break;
		case TinyImageFormat_PACK_SPECIAL_MULTI4:count *= 4;
			break;
		case TinyImageFormat_PACK_SPECIAL_MULTI8:count *= 8;
			break;
		}

		return count;
	}

	if (IsInDepthStencil(name, v)) {
		v = v >> TinyImageFormat_DEPTH_STENCIL_TOTAL_SIZE_SHIFT;
		uint64_t const bits = (v & Mask(TinyImageFormat_DEPTH_STENCIL_TOTAL_SIZE_REQUIRED_BITS));
		switch (bits) {
		case TinyImageFormat_DEPTH_STENCIL_TOTAL_SIZE_8: return 8;
		case TinyImageFormat_DEPTH_STENCIL_TOTAL_SIZE_16: return 16;
		case TinyImageFormat_DEPTH_STENCIL_TOTAL_SIZE_32: return 32;
		case TinyImageFormat_DEPTH_STENCIL_TOTAL_SIZE_64: return 64;
		default: ASSERT(false);
		}
	}

	if (IsInDXTC(name, v)) {
		v = v >> TinyImageFormat_DXTC_BLOCKBYTES_SHIFT;
		uint64_t const bytes = (v & Mask(TinyImageFormat_DXTC_BLOCKBYTES_REQUIRED_BITS));
		switch (bytes) {
		case TinyImageFormat_DXTC_BLOCKBYTES_8: return 8 * 8;
		case TinyImageFormat_DXTC_BLOCKBYTES_16: return 16 * 8;
		default: ASSERT(false);
		}
	}

	if (IsInPVRTC(name, v)) {
		return 64;
	}

	if (IsInETC(name, v)) {
		return 32;
	}

	if (IsInASTC(name, v)) {
		return 128;
	}

	if(IsInCLUT(name, v)) {
		uint32_t bitsize = 0;
		for(uint32_t i=0;i < ChannelCount(name, v);++i) {
			bitsize += ChannelBitWidth(name, v, i);
		}

		uint64_t vbs = v >> TinyImageFormat_CLUT_BLOCKSIZE_SHIFT;
		auto blockSize = (TinyImageFormat_CLUT_BlockSize const )(vbs & Mask( TinyImageFormat_CLUT_BLOCKSIZE_REQUIRED_BITS));
		uint32_t repeat = 1;
		switch(blockSize) {
		case TinyImageFormat_CLUT_BLOCKSIZE_1: repeat = 1; break;
		case TinyImageFormat_CLUT_BLOCKSIZE_2: repeat = 2; break;
		case TinyImageFormat_CLUT_BLOCKSIZE_4: repeat = 4; break;
		case TinyImageFormat_CLUT_BLOCKSIZE_8: repeat = 8; break;
		}

		return bitsize * repeat;
	}

	return 8;
}

static bool IsHomogenous(char const *name, uint64_t v) {
	if (v == 0)
		return false;

	if (IsInPacked(name, v)) {

		uint64_t const backupV = v;
		int64_t rtype = -1;
		v = v >> TinyImageFormat_PACK_TYPE_SHIFT;

		// homogenous packed format has the same type for each channel
		for (uint32_t i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
			if (type == TinyImageFormat_PACK_TYPE_NONE) {
				v = v >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
				continue;
			}
			if (rtype == -1) {
				rtype = (int64_t) type;
			}
			if (rtype != (int64_t) type)
				return false;
			v = v >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
		}
		// and bit width
		v = backupV;
		v = v >> TinyImageFormat_PACK_BITS_SHIFT;
		rtype = -1;
		for (uint32_t i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint64_t const bits = (v & Mask(TinyImageFormat_PACK_BITS_REQUIRED_BITS));
			if (bits == TinyImageFormat_PACK_BITS_0) {
				v = v >> TinyImageFormat_PACK_BITS_REQUIRED_BITS;
				continue;
			}

			if (rtype == -1) {
				rtype = (int64_t) bits;
			}
			if (rtype != (int64_t) bits)
				return false;
			v = v >> TinyImageFormat_PACK_BITS_REQUIRED_BITS;
		}
		return true;
	}

	if (IsInDepthStencil(name, v)) {
		if (ChannelCount(name, v) > 1) {
			return false;
		} else {
			return true;
		}
	}

	// rather than work out which submits of compressed blocks are
	// homogenous or not we say false
	return false;
}


int8_t PhysicalChannelToLogical(char const *name, uint64_t const v, uint32_t chan) {
	if (v == 0)
		return TinyImageFormat_LC_0;

	if (IsInPacked(name, v)) {
		uint64_t v2 = v >> TinyImageFormat_PACK_SWIZZLE_SHIFT;
		v2 = v2 >> (chan * TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS);
		uint64_t swiz = (v2 & Mask(TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS));

		switch (swiz) {
		case TinyImageFormat_PACK_SWIZZLE_R: return TinyImageFormat_LC_Red;
		case TinyImageFormat_PACK_SWIZZLE_G: return TinyImageFormat_LC_Green;
		case TinyImageFormat_PACK_SWIZZLE_B: return TinyImageFormat_LC_Blue;
		case TinyImageFormat_PACK_SWIZZLE_A: return TinyImageFormat_LC_Alpha;
		case TinyImageFormat_PACK_SWIZZLE_0: return TinyImageFormat_LC_0;
		case TinyImageFormat_PACK_SWIZZLE_1: return TinyImageFormat_LC_1;
		default: ASSERT(false);
		}
	}

	if (IsInDepthStencil(name, v)) {
		if (chan >= ChannelCount(name, v)) {
			return TinyImageFormat_LC_0;
		}
		uint64_t vs = v >> TinyImageFormat_DEPTH_STENCIL_SWIZZLE_SHIFT;
		vs = vs >> (chan * TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS);
		auto swiz = (TinyImageFormat_DepthStencil_Swizzle const) (vs & Mask(TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS));

		switch (swiz) {
		case TinyImageFormat_DEPTH_STENCIL_SWIZZLE_D: return TinyImageFormat_LC_Depth;
		case TinyImageFormat_DEPTH_STENCIL_SWIZZLE_S: return TinyImageFormat_LC_Stencil;
		case TinyImageFormat_DEPTH_STENCIL_SWIZZLE_0: return TinyImageFormat_LC_0;
		default: ASSERT(false);
		}
	}
	if (IsInCLUT(name, v)) {
		if (chan >= ChannelCount(name, v)) {
			return TinyImageFormat_LC_0;
		}
		uint64_t vt = v >> TinyImageFormat_CLUT_TYPE_SHIFT;
		vt = vt >> (chan * TinyImageFormat_CLUT_TYPE_REQUIRED_BITS);
		auto type = (TinyImageFormat_CLUT_Type const)(vt & Mask(TinyImageFormat_CLUT_TYPE_REQUIRED_BITS));
		switch(type) {
		case TinyImageFormat_CLUT_TYPE_NONE: 		return TinyImageFormat_LC_0;
		case TinyImageFormat_CLUT_TYPE_RGB: 		return TinyImageFormat_LC_Red;
		case TinyImageFormat_CLUT_TYPE_SINGLE: 	return TinyImageFormat_LC_Red;
		case TinyImageFormat_CLUT_TYPE_EXPLICIT_ALPHA:	return TinyImageFormat_LC_Alpha;
		}
	}

	if(IsInETC(name, v) || IsInPVRTC(name,v) || IsInDXTC(name,v) || IsInASTC(name,v)) {
		// all compressed formats are in RGBA
		if (chan >= ChannelCount(name, v)) {
			if (chan == 3)
				return TinyImageFormat_LC_1;
			else
				return TinyImageFormat_LC_0;
		} else {
			return chan;
		}
	}

	ASSERT(false);
	return chan;
}

static double Min(char const *name, uint64_t v, uint32_t const chan) {
	if (v == 0)
		return 0.0;

	if (IsInPacked(name, v)) {
		uint64_t v2 = v;
		v = v >> TinyImageFormat_PACK_BITS_SHIFT;
		v2 = v2 >> TinyImageFormat_PACK_TYPE_SHIFT;

		v = v >> (chan * TinyImageFormat_PACK_BITS_REQUIRED_BITS);
		v2 = v2 >> (chan * TinyImageFormat_PACK_TYPE_REQUIRED_BITS);

		uint64_t bits = (v & Mask(TinyImageFormat_PACK_BITS_REQUIRED_BITS));
		uint64_t type = (v2 & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));

		if (type == TinyImageFormat_PACK_TYPE_NONE)
			return 0.0;

		// unsigned min is always 0
		if (type == TinyImageFormat_PACK_TYPE_UNORM ||
				type == TinyImageFormat_PACK_TYPE_UFLOAT ||
				type == TinyImageFormat_PACK_TYPE_UINT ||
				type == TinyImageFormat_PACK_TYPE_SRGB
				)
			return 0.0;
		// signed normalised -1
		if (type == TinyImageFormat_PACK_TYPE_SNORM)
			return -1.0;

		// signed float
		if (type == TinyImageFormat_PACK_TYPE_SFLOAT) {
			switch (bits) {
			case TinyImageFormat_PACK_BITS_16: return -65504;
			case TinyImageFormat_PACK_BITS_32: return -FLT_MAX;
			case TinyImageFormat_PACK_BITS_64: return -DBL_MAX;
			default: ASSERT(false);
			}
		}
		// signed bfloat
		if (type == TinyImageFormat_PACK_TYPE_SBFLOAT) {
			if(bits !=TinyImageFormat_PACK_BITS_16) ASSERT(false);
			union {
				struct {
					uint16_t u;
					uint16_t x;
				};
				float f;
			} o;

			o.f = -FLT_MAX;
			o.x = 0;
			return o.f;
		}

		// signed int
		if (type == TinyImageFormat_PACK_TYPE_SINT) {
			switch (bits) {
			case TinyImageFormat_PACK_BITS_0: return 0.0;
			case TinyImageFormat_PACK_BITS_1: return (double) -1;
			case TinyImageFormat_PACK_BITS_2: return (double) -2;
			case TinyImageFormat_PACK_BITS_3: return (double) -4;
			case TinyImageFormat_PACK_BITS_4: return (double) -8;
			case TinyImageFormat_PACK_BITS_5: return (double) -16;
			case TinyImageFormat_PACK_BITS_6: return (double) -32;
			case TinyImageFormat_PACK_BITS_7: return (double) -64;
			case TinyImageFormat_PACK_BITS_8: return (double) INT8_MIN;
			case TinyImageFormat_PACK_BITS_9: return (double) -256;
			case TinyImageFormat_PACK_BITS_10: return (double) -512;
			case TinyImageFormat_PACK_BITS_11: return (double) -1024;
			case TinyImageFormat_PACK_BITS_12: return (double) -2048;
			case TinyImageFormat_PACK_BITS_16: return (double) INT16_MIN;
			case TinyImageFormat_PACK_BITS_32: return (double) INT32_MIN;
			case TinyImageFormat_PACK_BITS_64: return (double) INT64_MIN; // lossy
			default: ASSERT(false);
			}
		}
		ASSERT(false);

	}

	if (IsInDepthStencil(name, v)) {
		uint64_t v2 = v;
		v = v >> TinyImageFormat_DEPTH_STENCIL_BITS_SHIFT;
		v2 = v2 >> TinyImageFormat_DEPTH_STENCIL_TYPE_SHIFT;

		v = v >> (chan * TinyImageFormat_DEPTH_STENCIL_BITS_REQUIRED_BITS);
		v2 = v2 >> (chan * TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS);

		uint64_t bits = (v & Mask(TinyImageFormat_DEPTH_STENCIL_BITS_REQUIRED_BITS));
		uint64_t type = (v2 & Mask(TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS));

		if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_NONE)
			return 0.0;
		// unsigned min is always 0
		if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_UNORM ||
				type == TinyImageFormat_DEPTH_STENCIL_TYPE_UINT)
			return 0.0;

		if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_SFLOAT) {
			switch (bits) {
			case TinyImageFormat_DEPTH_STENCIL_BITS_32: return (double) -FLT_MAX;
			default: ASSERT(false);
			}
		}
		ASSERT(false);
	}

	if (IsInDXTC(name, v)) {
		uint64_t v2 = v;
		v2 = v2 >> TinyImageFormat_DXTC_TYPE_SHIFT;

		uint64_t type = (v2 & Mask(TinyImageFormat_DXTC_TYPE_REQUIRED_BITS));
		// unsigned min is always 0
		if (type == TinyImageFormat_DXTC_TYPE_UNORM ||
				type == TinyImageFormat_DXTC_TYPE_SRGB ||
				type == TinyImageFormat_DXTC_TYPE_UFLOAT)
			return 0.0;

		if (type == TinyImageFormat_DXTC_TYPE_SNORM) {
			return -1.0;
		}

		if (type == TinyImageFormat_DXTC_TYPE_SFLOAT) {
			return -FLT_MAX;
		}

		ASSERT(false);
	}

	if (IsInPVRTC(name, v))
		return 0.0;

	if (IsInETC(name, v)) {
		uint64_t v2 = v;
		v2 = v2 >> TinyImageFormat_ETC_TYPE_SHIFT;
		uint64_t type = (v2 & Mask(TinyImageFormat_ETC_TYPE_REQUIRED_BITS));
		// unsigned min is always 0
		if (type == TinyImageFormat_ETC_TYPE_UNORM ||
				type == TinyImageFormat_ETC_TYPE_SRGB
				)
			return 0.0;
		if (type == TinyImageFormat_ETC_TYPE_SNORM) {
			return -1.0;
		}
		ASSERT(false);

	}

	if(IsInASTC(name, v))
		return 0.0;

	if(IsInCLUT(name, v)) {
		return 0.0;
	}

	return 0.0;
}

double MaxActual(char const *name, uint64_t v, uint32_t const chan, bool ignoreNormFormats) {
	if (v == 0)
		return 0.0;

	if (IsInPacked(name, v)) {
		uint64_t v2 = v;
		v = v >> TinyImageFormat_PACK_BITS_SHIFT;
		v2 = v2 >> TinyImageFormat_PACK_TYPE_SHIFT;

		v = v >> (chan * TinyImageFormat_PACK_BITS_REQUIRED_BITS);
		v2 = v2 >> (chan * TinyImageFormat_PACK_TYPE_REQUIRED_BITS);

		uint64_t bits = (v & Mask(TinyImageFormat_PACK_BITS_REQUIRED_BITS));
		uint64_t type = (v2 & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));

		if (type == TinyImageFormat_PACK_TYPE_NONE)
			return 0.0;

		if (ignoreNormFormats == false) {
			if (type == TinyImageFormat_PACK_TYPE_UNORM ||
					type == TinyImageFormat_PACK_TYPE_SNORM ||
					type == TinyImageFormat_PACK_TYPE_SRGB)
				return 1.0;
		} else {
			if (type == TinyImageFormat_PACK_TYPE_UNORM ||
					type == TinyImageFormat_PACK_TYPE_SRGB)
				type = TinyImageFormat_PACK_TYPE_UINT;
			else if (type == TinyImageFormat_PACK_TYPE_SNORM)
				type = TinyImageFormat_PACK_TYPE_SINT;
		}

		if (type == TinyImageFormat_PACK_TYPE_UINT) {
			switch (bits) {
			case TinyImageFormat_PACK_BITS_0: return 0.0;
			case TinyImageFormat_PACK_BITS_1: return (double) 1;
			case TinyImageFormat_PACK_BITS_2: return (double) 3;
			case TinyImageFormat_PACK_BITS_3: return (double) 7;
			case TinyImageFormat_PACK_BITS_4: return (double) 15;
			case TinyImageFormat_PACK_BITS_5: return (double) 31;
			case TinyImageFormat_PACK_BITS_6: return (double) 63;
			case TinyImageFormat_PACK_BITS_7: return (double) 127;
			case TinyImageFormat_PACK_BITS_8: return (double) UINT8_MAX;
			case TinyImageFormat_PACK_BITS_9: return (double) 511;
			case TinyImageFormat_PACK_BITS_10: return (double) 1023;
			case TinyImageFormat_PACK_BITS_11: return (double) 2047;
			case TinyImageFormat_PACK_BITS_12: return (double) 4095;
			case TinyImageFormat_PACK_BITS_16: return (double) UINT16_MAX;
			case TinyImageFormat_PACK_BITS_32: return (double) UINT32_MAX;
			case TinyImageFormat_PACK_BITS_64: return (double) UINT64_MAX; // lossy
			default: ASSERT(false);
			}
		}
		if (type == TinyImageFormat_PACK_TYPE_SINT) {
			switch (bits) {
			case TinyImageFormat_PACK_BITS_0: return 0.0;
			case TinyImageFormat_PACK_BITS_1: return 0.0;
			case TinyImageFormat_PACK_BITS_2: return (double) 1;
			case TinyImageFormat_PACK_BITS_3: return (double) 3;
			case TinyImageFormat_PACK_BITS_4: return (double) 7;
			case TinyImageFormat_PACK_BITS_5: return (double) 15;
			case TinyImageFormat_PACK_BITS_6: return (double) 31;
			case TinyImageFormat_PACK_BITS_7: return (double) 63;
			case TinyImageFormat_PACK_BITS_8: return (double) INT8_MAX;
			case TinyImageFormat_PACK_BITS_9: return (double) 255;
			case TinyImageFormat_PACK_BITS_10: return (double) 511;
			case TinyImageFormat_PACK_BITS_11: return (double) 1023;
			case TinyImageFormat_PACK_BITS_12: return (double) 2043;
			case TinyImageFormat_PACK_BITS_16: return (double) INT16_MAX;
			case TinyImageFormat_PACK_BITS_32: return (double) INT32_MAX;
			case TinyImageFormat_PACK_BITS_64: return (double) INT64_MAX; // lossy
			default: ASSERT(false);
			}
		}

		// signed float
		if (type == TinyImageFormat_PACK_TYPE_SFLOAT) {
			switch (bits) {
			case TinyImageFormat_PACK_BITS_16: return 65504.0;
			case TinyImageFormat_PACK_BITS_32: return FLT_MAX;
			case TinyImageFormat_PACK_BITS_64: return DBL_MAX;
			default: ASSERT(false);
			}
		}

		// signed bfloat
		if (type == TinyImageFormat_PACK_TYPE_SBFLOAT) {
			if(bits !=TinyImageFormat_PACK_BITS_16) ASSERT(false);
			union {
				struct {
					uint16_t u;
					uint16_t x;
				};
				float f;
			} o;

			o.f = FLT_MAX;
			o.x = 0;
			return o.f;
		}

		if (type == TinyImageFormat_PACK_TYPE_UFLOAT) {
			switch (bits) {
			case TinyImageFormat_PACK_BITS_9: return float(0x1FF << 7); // this is with the shared exponent
			case TinyImageFormat_PACK_BITS_10: return 65000.0;
			case TinyImageFormat_PACK_BITS_11: return 65500.0;
			default: ASSERT(false);
			}
		}

		ASSERT(false);

	}

	if (IsInDepthStencil(name, v)) {
		uint64_t v2 = v;
		v = v >> TinyImageFormat_DEPTH_STENCIL_BITS_SHIFT;
		v2 = v2 >> TinyImageFormat_DEPTH_STENCIL_TYPE_SHIFT;
		v = v >> (chan * TinyImageFormat_DEPTH_STENCIL_BITS_REQUIRED_BITS);
		v2 = v2 >> (chan * TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS);

		uint64_t bits = (v2 & Mask(TinyImageFormat_DEPTH_STENCIL_BITS_REQUIRED_BITS));
		uint64_t type = (v2 & Mask(TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS));

		if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_NONE)
			return 0.0;
		if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_UNORM)
			return 1.0;
		if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_UINT)
			return 255.0;
		if (type == TinyImageFormat_DEPTH_STENCIL_TYPE_SFLOAT) {
			return FLT_MAX;
		}
		ASSERT(false);
	}

	if (IsInDXTC(name, v)) {
		uint64_t v2 = v;
		v2 = v2 >> TinyImageFormat_DXTC_TYPE_SHIFT;
		uint64_t type = (v2 & Mask(TinyImageFormat_DXTC_TYPE_REQUIRED_BITS));
		// unsigned min is always 0
		if (type == TinyImageFormat_DXTC_TYPE_UNORM ||
				type == TinyImageFormat_DXTC_TYPE_SRGB ||
				type == TinyImageFormat_DXTC_TYPE_SNORM)
			return 1.0;

		if (type == TinyImageFormat_DXTC_TYPE_SFLOAT) {
			return 65504;
		}
		if (type == TinyImageFormat_DXTC_TYPE_UFLOAT) {
			return 131008;
		}

		ASSERT(false);
	}

	if (IsInPVRTC(name, v))
		return 1.0;

	if (IsInETC(name, v))
		return 1.0;

	if (IsInASTC(name, v))
		return 1.0;

	if (IsInCLUT(name, v))
		return 1.0;

	ASSERT(false);
	return 8;
}
double Max(char const *name, uint64_t v, uint32_t const chan) {
	return MaxActual(name, v, chan, false);
}

void GenBoolFunc(VFile_Handle file,
												const char *testname,
												bool defaultval,
												bool (*func)(char const *, uint64_t)) {
	char buffer[2048];
	char const isPrefixF[] =
			"TIF_CONSTEXPR inline bool TinyImageFormat_%s(TinyImageFormat const fmt) {\n\tswitch(fmt) {\n";
	char const switchPostfixF[] = "\t\tdefault: return %s;\n\t}\n}\n\n";

	char prefix[2048];
	sprintf(prefix, isPrefixF, testname);

#define  TinyImageFormat_START_MACRO { VFile_Write(file, prefix, strlen(prefix));
#define  TinyImageFormat_MOD_MACRO(x, y) if(func(#x, y) != defaultval) { sprintf(buffer, "\t\tcase %s: return %s;\n", "TinyImageFormat_"#x, defaultval?"false":"true"); \
                                                               VFile_Write(file, buffer, strlen(buffer)); };
#define  TinyImageFormat_END_MACRO  sprintf(buffer, switchPostfixF, defaultval?"true":"false"); VFile_Write(file, buffer, strlen(buffer)); }
#include "formatgen.h"
}

void GenU32Func(VFile_Handle file,
											 const char *testname,
											 uint32_t defaultval,
											 uint32_t (*func)(char const *, uint64_t)) {
	char buffer[2048];
	char const isPrefixF[] =
			"TIF_CONSTEXPR inline uint32_t TinyImageFormat_%s(TinyImageFormat const fmt) {\n\tswitch(fmt) {\n";
	char const switchPostfixF[] = "\t\tdefault: return %d;\n\t}\n}\n\n";

	char prefix[2048];
	sprintf(prefix, isPrefixF, testname);

#define  TinyImageFormat_START_MACRO { VFile_Write(file, prefix, strlen(prefix));
#define  TinyImageFormat_MOD_MACRO(x, y) { auto f = func(#x, y); if(f != defaultval) { sprintf(buffer, "\t\tcase %s: return %d;\n", "TinyImageFormat_"#x, f); \
                                                               VFile_Write(file, buffer, strlen(buffer)); } };
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF, defaultval); VFile_Write(file, buffer, strlen(buffer)); }
#include "formatgen.h"
}

void GenNames(VFile_Handle file) {
	char buffer[2048];
	char const
			isPrefixF[] =
			"TIF_CONSTEXPR inline char const * const TinyImageFormat_Name(TinyImageFormat const fmt) {\n\tswitch(fmt) {\n";
	char const switchPostfixF[] = "\t\tdefault: return \"The_Format_With_No_Name\";\n\t}\n}\n\n";

#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) sprintf(buffer, "\t\tcase %s: return \"%s\";\n", "TinyImageFormat_"#x, #x); \
                                                               VFile_Write(file, buffer, strlen(buffer));
#define  TinyImageFormat_END_MACRO VFile_Write(file, switchPostfixF, strlen(switchPostfixF));
#include "formatgen.h"
}

static uint64_t EmbeddedHash(char const *p) {
	uint64_t hash = 0xcbf29ce484222325ULL;
	while ((*p) != 0) {
		hash = (((uint64_t) *p) ^ hash) * 1099511628211ULL;
		p++;
	}
	return hash;
}

void GenNameLookup(VFile_Handle file) {
	char buffer[2048];
	char const isPrefixF[] = "inline TinyImageFormat TinyImageFormat_FromName(char const* p) {\n"
													 "\t// FNV-1a hashing algorithm.\n"
													 "\tuint64_t hash = 0xcbf29ce484222325ULL;\n"
													 "\twhile ((*p) != 0) { hash = (((uint64_t) *p) ^ hash) * 1099511628211ULL;	p++; }\n"
													 "\tswitch(hash) {\n";
	char const switchPostfixF[] = "\t\tdefault: return TinyImageFormat_UNDEFINED;\n\t}\n}\n\n";

#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) sprintf(buffer, "\t\tcase 0x%" PRIX64 ": return %s;\n", EmbeddedHash(#x), "TinyImageFormat_"#x); \
                                                               VFile_Write(file, buffer, strlen(buffer));
#define  TinyImageFormat_END_MACRO VFile_Write(file, switchPostfixF, strlen(switchPostfixF));
#include "formatgen.h"

}

void GenU32PerChanFunc(VFile_Handle file,
															const char *testname,
															uint32_t defaultval,
															uint32_t (*func)(char const *, uint64_t, uint32_t)) {
	char buffer[2048];
	char const *const isPrefixF[] = {
			"TIF_CONSTEXPR inline uint32_t TinyImageFormat_%sAtPhysical(TinyImageFormat const fmt, uint32_t const channel) {\n"
			"\tif(TinyImageFormat_IsHomogenous(fmt) || channel == 0) {\n\t\tswitch(fmt) {\n",
			"\telse if(channel == %d) {\n\t\tswitch(fmt) { \n"
	};
	char const switchPostfixF[] = "\t\t\tdefault: return %d;\n\t\t}\n\t}";

	for (auto i = 0u; i < 4; ++i) {
		char prefix[2048];

		if (i == 0)
			sprintf(prefix, isPrefixF[0], testname);
		else
			sprintf(prefix, isPrefixF[1], i);

#define  TinyImageFormat_START_MACRO { VFile_Write(file, prefix, strlen(prefix));
#define  TinyImageFormat_MOD_MACRO(x, y) if(func(#x, y, i) != defaultval) { sprintf(buffer, "\t\t\tcase %s: return %d;\n", "TinyImageFormat_"#x, func(#x, y, i)); \
                                                               VFile_Write(file, buffer, strlen(buffer)); };
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF, defaultval); VFile_Write(file, buffer, strlen(buffer)); }
#include "formatgen.h"
	}
	char const closerF[] = "\n\t TinyImageFormat_ASSERT(false);\n\treturn 0;\n}\n\n";
	VFile_Write(file, closerF, strlen(closerF));
}
void GenPhysicalChannelToLogicalPerChanFunc(VFile_Handle file) {
	static char const *const lnames[6] = {
			"TinyImageFormat_LC_1",
			"TinyImageFormat_LC_0",
			"TinyImageFormat_LC_Red",
			"TinyImageFormat_LC_Green",
			"TinyImageFormat_LC_Blue",
			"TinyImageFormat_LC_Alpha",
	};
	static char const *const pnames[4] = {
			"TinyImageFormat_PC_0",
			"TinyImageFormat_PC_1",
			"TinyImageFormat_PC_2",
			"TinyImageFormat_PC_3"
	};
	static char const *const isPrefixF[2] = {
			"TIF_CONSTEXPR inline TinyImageFormat_LogicalChannel TinyImageFormat_PhysicalChannelToLogical(TinyImageFormat const fmt, int8_t const channel) {\n"
			"\t TinyImageFormat_ASSERT(channel != TinyImageFormat_PC_CONST_0);\n\t TinyImageFormat_ASSERT(channel != TinyImageFormat_PC_CONST_1);\n"
			"\tif(channel == %s) {\n\t\tswitch(fmt) {\n",
			"\telse if(channel == %s) {\n\t\tswitch(fmt) {\n"
	};
	static char const *const switchPostfixF = "\t\t\tdefault: return %s;\n\t\t}\n\t}";

	char buffer[2048];
	char prefix[2048];

	for (auto i = 0u; i < 4; ++i) {
		if (i == 0)
			sprintf(prefix, isPrefixF[0], pnames[i]);
		else
			sprintf(prefix, isPrefixF[1], pnames[i]);

#define  TinyImageFormat_START_MACRO { VFile_Write(file, prefix, strlen(prefix));
#define  TinyImageFormat_MOD_MACRO(x, y) if(PhysicalChannelToLogical(#x, y, i) != i) { sprintf(buffer, "\t\t\tcase %s: return %s;\n", "TinyImageFormat_"#x, lnames[PhysicalChannelToLogical(#x, y,i)+2]); \
                                                               VFile_Write(file, buffer, strlen(buffer)); };
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF, lnames[i+2]); VFile_Write(file, buffer, strlen(buffer)); }
#include "formatgen.h"
	}

	char const closerF[] = "\n\t TinyImageFormat_ASSERT(false);\n\treturn TinyImageFormat_LC_0;\n}\n\n";
	VFile_Write(file, closerF, strlen(closerF));
}

static void WriteL2PPack(VFile_Handle file, char const *name, uint32_t physChan, uint64_t v) {

	static char const *const pnames[6] = {
			"TinyImageFormat_PC_CONST_1",
			"TinyImageFormat_PC_CONST_0",
			"TinyImageFormat_PC_0",
			"TinyImageFormat_PC_1",
			"TinyImageFormat_PC_2",
			"TinyImageFormat_PC_3"
	};

	char buffer[2048];
	sprintf(buffer, "\t\t\tcase %s: return %s;\n", name, pnames[physChan + 2]);
	VFile_Write(file, buffer, strlen(buffer));
}

void LogicalToPhysicalChannels(const char *name, uint64_t v, int8_t out[4]) {

	int8_t p2l[4];
	p2l[0] = PhysicalChannelToLogical(name, v, 0);
	p2l[1] = PhysicalChannelToLogical(name, v, 1);
	p2l[2] = PhysicalChannelToLogical(name, v, 2);
	p2l[3] = PhysicalChannelToLogical(name, v, 3);

	bool done[4] = {false, false, false, false};
	int8_t constants[4]{-1, -1, -1, -1};
	uint32_t constCount = 0;

	// two passes
	for (auto c = 0u; c < 4; ++c) {
		int8_t n = p2l[c];
		if (n >= 0) {
			ASSERT(n < 4);
			out[n] = c;
			done[n] = true;
		} else {
			constants[constCount++] = n;
		}
	}
	uint32_t constUsed = 0;
	for (auto c = 0u; c < 4; ++c) {
		if (!done[c]) {
			out[c] = constants[constUsed++];
		}
	}
	ASSERT(constUsed == constCount);

}

void GenLogicalToPhysicalChannelPerChanFunc(VFile_Handle file) {

#define  TinyImageFormat_START_MACRO uint32_t fmtCount = 0;
#define  TinyImageFormat_MOD_MACRO(x, y) fmtCount++;
#define  TinyImageFormat_END_MACRO
#include "formatgen.h"

	// we need a buffer to store the logical to physical channel map for each channel
	int8_t *l2p = (int8_t *) malloc(sizeof(int8_t) * fmtCount * 4);

#define  TinyImageFormat_START_MACRO { uint32_t count = 0;
#define  TinyImageFormat_MOD_MACRO(x, y)  LogicalToPhysicalChannels(#x, y, &l2p[count]);\
                                          count += 4;
#define  TinyImageFormat_END_MACRO }
#include "formatgen.h"

	static char const *const lnames[6] = {
			"TinyImageFormat_LC_Red",
			"TinyImageFormat_LC_Green",
			"TinyImageFormat_LC_Blue",
			"TinyImageFormat_LC_Alpha",
			"TinyImageFormat_LC_Depth",
			"TinyImageFormat_LC_Stencil",
	};
	static char const *const pnames[6] = {
			"TinyImageFormat_PC_CONST_1",
			"TinyImageFormat_PC_CONST_0",
			"TinyImageFormat_PC_0",
			"TinyImageFormat_PC_1",
			"TinyImageFormat_PC_2",
			"TinyImageFormat_PC_3"
	};
	static char const *const isPrefixF[2] = {
			"TIF_CONSTEXPR inline int8_t TinyImageFormat_LogicalChannelToPhysical(TinyImageFormat const fmt, TinyImageFormat_LogicalChannel const channel) {\n"
			"\t TinyImageFormat_ASSERT(channel != TinyImageFormat_LC_0);\n\t TinyImageFormat_ASSERT(channel != TinyImageFormat_LC_1);\n"
			"\tif(channel == TinyImageFormat_LC_Red) {\n\t\tswitch(fmt) {\n",
			"\telse if(channel == %s) {\n\t\tswitch(fmt) {\n"
	};
	static char const *const switchPostfixF = "\t\t\tdefault: return %s;\n\t\t}\n\t}";

	char buffer[2048];
	char prefix[2048];

	for (auto i = 0u; i < 4; ++i) {
		if (i == 0)
			sprintf(prefix, "%s", isPrefixF[0]);
		else
			sprintf(prefix, isPrefixF[1], lnames[i]);

#define  TinyImageFormat_START_MACRO { VFile_Write(file, prefix, strlen(prefix)); uint32_t count = 0;
#define  TinyImageFormat_MOD_MACRO(x, y) if(l2p[(count*4)+i] != i) { WriteL2PPack(file, "TinyImageFormat_"#x, l2p[(count*4)+i], y); } count++;
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF, pnames[i+2]); VFile_Write(file, buffer, strlen(buffer)); }
#include "formatgen.h"
	}

	char const closerF[] = "\n\t TinyImageFormat_ASSERT(false);\n\treturn TinyImageFormat_PC_CONST_0;\n}\n\n";
	VFile_Write(file, closerF, strlen(closerF));
	free(l2p);
}

void GenDoublePerChanFunc(VFile_Handle file,
																 const char *testname,
																 double defaultval,
																 double (*func)(char const *, uint64_t, uint32_t)) {
	char buffer[2048];
	char const *const isPrefixF[] = {
			"TIF_CONSTEXPR inline double TinyImageFormat_%sAtPhysical(TinyImageFormat const fmt, uint32_t const channel) {\n"
			"\tif(TinyImageFormat_IsHomogenous(fmt) || channel == 0) {\n\t\tswitch(fmt) {\n",
			"\telse if(channel == %d) {\n\t\tswitch(fmt) { \n"
	};
	char const switchPostfixF[] = "\t\t\tdefault: return %f;\n\t\t}\n\t}";

	for (auto i = 0u; i < 4; ++i) {
		char prefix[2048];

		if (i == 0)
			sprintf(prefix, isPrefixF[0], testname);
		else
			sprintf(prefix, isPrefixF[1], i);
#define  TinyImageFormat_START_MACRO { VFile_Write(file, prefix, strlen(prefix));
#define  TinyImageFormat_MOD_MACRO(x, y) if(fabs(func(#x, y, i)-defaultval) > 1e-10) { sprintf(buffer, "\t\t\tcase %s: return %f;\n", "TinyImageFormat_"#x, func(#x, y, i)); \
                                                               VFile_Write(file, buffer, strlen(buffer)); };
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF, defaultval); VFile_Write(file, buffer, strlen(buffer)); }
#include "formatgen.h"
	}

	char const closerF[] = "\n\t TinyImageFormat_ASSERT(false);\n\treturn 0.0;\n}\n\n";
	VFile_Write(file, closerF, strlen(closerF));
}

void IncludeQueryHelpers(VFile_Handle file) {
#define RAW_INCLUDE_START(x) x
	char const *otherEnums =
#include "queryhelpers.h"
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

#define GEN_BOOL_FUNC(f, d, t) GenBoolFunc(f, #t, d, &t)
#define GEN_U32_FUNC(f, d, t) GenU32Func(f, #t, d, &t)
#define GEN_U32PERCHAN_FUNC(f, d, t) GenU32PerChanFunc(f, #t, d, &t)
#define GEN_DBLPERCHAN_FUNC(f, d, t) GenDoublePerChanFunc(f, #t, d, &t)

void GenQuerys(VFile_Handle file) {

	GenCode(file);

	GenMaxPixelCountOfBlock(file);
	GEN_BOOL_FUNC(file, false, IsDepthOnly);
	GEN_BOOL_FUNC(file, false, IsStencilOnly);
	GEN_BOOL_FUNC(file, false, IsDepthAndStencil);
	GEN_BOOL_FUNC(file, false, IsCLUT);
	GEN_BOOL_FUNC(file, false, IsFloat);
	GEN_BOOL_FUNC(file, false, IsNormalised);
	GEN_BOOL_FUNC(file, false, IsSigned);
	GEN_BOOL_FUNC(file, false, IsSRGB);
	GEN_BOOL_FUNC(file, false, IsCompressed);
	GEN_BOOL_FUNC(file, true,  IsHomogenous);

	GEN_U32_FUNC(file, 1, WidthOfBlock);
	GEN_U32_FUNC(file, 1, HeightOfBlock);
	GEN_U32_FUNC(file, 1, DepthOfBlock);
	GEN_U32_FUNC(file, 32, BitSizeOfBlock);
	GEN_U32_FUNC(file, 4, ChannelCount);
	GEN_U32PERCHAN_FUNC(file, 8, ChannelBitWidth);
	GEN_DBLPERCHAN_FUNC(file, 0.0, Min);
	GEN_DBLPERCHAN_FUNC(file, 1.0, Max);


	GenPhysicalChannelToLogicalPerChanFunc(file);
	GenLogicalToPhysicalChannelPerChanFunc(file);
	GenNames(file);
	GenNameLookup(file);

	IncludeQueryHelpers(file);
}