#include <stdio.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <cfloat>
#include <cmath>
#include "al2o3_vfile/vfile.h"
#include "../include/tiny_imageformat/tinyimageformat_bits.h"
#include "formatgen.h"

// get the compiler to check these are legal include fragments (some we can't check)
#define RAW_INCLUDE_START(x)
#define RAW_INCLUDE_END(x)
#define TinyImageFormat_ASSERT ASSERT
#include "otherimageenums.h"

#undef RAW_INCLUDE_START
#undef RAW_INCLUDE_END

void GenEnums(VFile_Handle file) {
	char const ifstartmacro[] = "typedef enum TinyImageFormat {\n";
	char const ifmodmacro[] = "\tTinyImageFormat_%s = %d,\n";
	char const ifendmacro[] = "} TinyImageFormat;\n\n";

	char buffer[2048];
#define  TinyImageFormat_START_MACRO { VFile_Write(file, ifstartmacro, strlen(ifstartmacro)); uint32_t count = 0;
#define  TinyImageFormat_MOD_MACRO(x, y) sprintf(buffer, ifmodmacro, #x, count++); VFile_Write(file, buffer, strlen(buffer));
#define  TinyImageFormat_END_MACRO VFile_Write(file, ifendmacro, strlen(ifendmacro)); }
#include "formatgen.h"

	char const ifstartmacro2[] = "typedef enum TinyImageFormat_Code {\n";
	char const ifmodmacro2[] = "\tTinyImageFormat_Code_%s = 0x%.16" PRIX64 "ULL,\n";
	char const ifendmacro2[] = "} TinyImageFormat_Code;\n\n";

#define  TinyImageFormat_START_MACRO { VFile_Write(file, ifstartmacro2, strlen(ifstartmacro2));
#define  TinyImageFormat_MOD_MACRO(x, y) sprintf(buffer, ifmodmacro2, #x, y); VFile_Write(file, buffer, strlen(buffer));
#define  TinyImageFormat_END_MACRO VFile_Write(file, ifendmacro2, strlen(ifendmacro2)); }
#include "formatgen.h"

	char const logiEnum[] =
			"typedef enum TinyImageFormat_LogicalChannel {\n"
			"\tTinyImageFormat_LC_Red = 0,\n"
			"\tTinyImageFormat_LC_Green = 1,\n"
			"\tTinyImageFormat_LC_Blue = 2,\n"
			"\tTinyImageFormat_LC_Alpha = 3,\n"
			"\tTinyImageFormat_LC_Depth = 0,\n"
			"\tTinyImageFormat_LC_Stencil = 1,\n"
			"\tTinyImageFormat_LC_0 = -1,\n"
			"\tTinyImageFormat_LC_1 = -2,\n"
			"} TinyImageFormat_LogicalChannel;\n\n";

	VFile_Write(file, logiEnum, strlen(logiEnum));

	char const physEnum[] =
			"typedef enum TinyImageFormat_PhysicalChannel {\n"
			"\tTinyImageFormat_PC_0 = 0,\n"
			"\tTinyImageFormat_PC_1 = 1,\n"
			"\tTinyImageFormat_PC_2 = 2,\n"
			"\tTinyImageFormat_PC_3 = 3,\n"
			"\tTinyImageFormat_PC_CONST_0 = -1,\n"
			"\tTinyImageFormat_PC_CONST_1 = -2,\n"
			"} TinyImageFormat_PhysicalChannel;\n\n";
	VFile_Write(file, physEnum, strlen(physEnum));

}

void GenCount(VFile_Handle file) {
	char buffer[2048];
	// format count
#define  TinyImageFormat_START_MACRO uint32_t count = 0;
#define  TinyImageFormat_MOD_MACRO(x, y) count++;
#define  TinyImageFormat_END_MACRO
#include "formatgen.h"
	char const formatCountF[] = "#define TinyImageFormat_Count %uU \n\n";

	sprintf(buffer, formatCountF, count);
	VFile_Write(file, buffer, strlen(buffer));
}

void IncludeHelpers(VFile_Handle file) {
#define RAW_INCLUDE_START(x) x
	char const *otherEnums =
#include "helpers.h"
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

void IncludeDocs(VFile_Handle file) {
#define RAW_INCLUDE_START(x) x
	char const *otherEnums =
#include "doc.h"
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

static void IncludeOtherImageEnums(VFile_Handle file) {
#define RAW_INCLUDE_START(x) x
	char const *otherEnums =
#include "otherimageenums.h"
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

constexpr uint64_t Mask(uint64_t v) {
	return (1ULL << v) - 1ULL;
}

static bool IsInPacked(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_PACK;
}

static bool IsInDepthStencil(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_DEPTH_STENCIL;
}

static bool IsInDXTC(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_DXTC;
}
static bool IsInPVRTC(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_PVRTC;
}
static bool IsInETC(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_ETC;
}
static bool IsInASTC(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_ASTC;
}

static bool IsInCLUT(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_CLUT;
}

static bool IsDepthOnly(char const *name, uint64_t v) {
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

static bool IsStencilOnly(char const *name, uint64_t v) {
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

static bool IsDepthAndStencil(char const *name, uint64_t v) {
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

static bool IsCLUT(char const *name, uint64_t v) {
	if(IsInCLUT(name, v)) {
		return true;
	} else {
		return false;
	}
}

static bool IsFloat(char const *name, uint64_t v) {

	if (IsInPacked(name, v)) {
		v = v >> TinyImageFormat_PACK_TYPE_SHIFT;
		for (uint32_t i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint64_t const chanType = (v & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
			if ((chanType == TinyImageFormat_PACK_TYPE_SFLOAT) ||
					(chanType == TinyImageFormat_PACK_TYPE_UFLOAT))
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

static bool IsNormalised(char const *name, uint64_t v) {

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

static bool IsSigned(char const *name, uint64_t v) {

	if (IsInPacked(name, v)) {
		v = v >> TinyImageFormat_PACK_TYPE_SHIFT;
		for (uint32_t i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
			uint64_t const type = (v & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
			if (type == TinyImageFormat_PACK_TYPE_SNORM ||
					type == TinyImageFormat_PACK_TYPE_SFLOAT ||
					type == TinyImageFormat_PACK_TYPE_SINT
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

static bool IsSRGB(char const *name, uint64_t v) {

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

static bool IsCompressed(char const *name, uint64_t v) {

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

static uint32_t SizeOfBlock(char const *name, uint64_t v, uint64_t dim) {
	if (v == 0)
		return 0;

	if (IsInDXTC(name, v)) {
		if (dim < 2)
			return 4;
	}

	if (IsInPVRTC(name, v)) {
		v = v >> TinyImageFormat_PVRTC_BITS_SHIFT;
		if (dim == 0) {
			auto bits = (TinyImageFormat_PVRTC_Bits const)(v & Mask(TinyImageFormat_PVRTC_BITS_REQUIRED_BITS));
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

		auto size = (TinyImageFormat_ASTC_Size const)(v & Mask(TinyImageFormat_ASTC_SIZE_REQUIRED_BITS));
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
	if(IsInCLUT(name, v) && dim == 0) {
		v = v >> TinyImageFormat_CLUT_BLOCKSIZE_SHIFT;
		auto bs = (TinyImageFormat_CLUT_BlockSize const) (v & Mask(TinyImageFormat_CLUT_BLOCKSIZE_REQUIRED_BITS));
		switch(bs) {
		case TinyImageFormat_CLUT_BLOCKSIZE_1: return 1;
		case TinyImageFormat_CLUT_BLOCKSIZE_2: return 2;
		case TinyImageFormat_CLUT_BLOCKSIZE_4: return 4;
		case TinyImageFormat_CLUT_BLOCKSIZE_8: return 8;
		}
	}

	return 1;
}

static uint32_t WidthOfBlock(char const *name, uint64_t v) {
	return SizeOfBlock(name, v, 0);
}
static uint32_t HeightOfBlock(char const *name, uint64_t v) {
	return SizeOfBlock(name, v, 1);
}
static uint32_t DepthOfBlock(char const *name, uint64_t v) {
	return SizeOfBlock(name, v, 2);
}

static uint32_t BitSizeBlock(char const *name, uint64_t v) {
	if (v == 0)
		return 0;

	if (IsInPacked(name, v)) {
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

	return 8;
}

static uint32_t ChannelCount(char const *name, uint64_t v) {
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

static uint32_t ChannelBitWidth(char const *name, uint64_t v, uint32_t chan) {
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
		if(chan >= TinyImageFormat_CLUT_NUM_CHANNELS) return 0;

		v = v >> (chan * TinyImageFormat_CLUT_BITS_REQUIRED_BITS);
		TinyImageFormat_CLUT_Bits const bits = (TinyImageFormat_CLUT_Bits) (v & Mask(TinyImageFormat_CLUT_BITS_REQUIRED_BITS));
		switch(bits) {
		case TinyImageFormat_CLUT_BITS_0:return 0;
		case TinyImageFormat_CLUT_BITS_1:return 1;
		case TinyImageFormat_CLUT_BITS_2:return 2;
		case TinyImageFormat_CLUT_BITS_4:return 4;
		case TinyImageFormat_CLUT_BITS_8:return 8;
		case TinyImageFormat_CLUT_BITS_16:return 16;
		case TinyImageFormat_CLUT_BITS_32:return 32;
		}
		ASSERT(false);
	}

	return 8;
}

static int8_t PhysicalChannelToLogical(char const *name, uint64_t v, uint32_t chan) {
	if (v == 0)
		return TinyImageFormat_LC_0;

	if (IsInPacked(name, v)) {
		v = v >> TinyImageFormat_PACK_SWIZZLE_SHIFT;
		v = v >> (chan * TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS);
		uint64_t swiz = (v & Mask(TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS));

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
		v = v >> TinyImageFormat_DEPTH_STENCIL_SWIZZLE_SHIFT;
		v = v >> (chan * TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS);
		uint64_t swiz = (v & Mask(TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS));

		switch (swiz) {
		case TinyImageFormat_DEPTH_STENCIL_SWIZZLE_D: return TinyImageFormat_LC_Depth;
		case TinyImageFormat_DEPTH_STENCIL_SWIZZLE_S: return TinyImageFormat_LC_Stencil;
		case TinyImageFormat_DEPTH_STENCIL_SWIZZLE_0: return TinyImageFormat_LC_0;
		default: ASSERT(false);
		}
	}
	if (IsInCLUT(name, v)) {
		return chan; // no swizzling for palettes
	}

	// all compressed formats are in RGBA
	if (chan >= ChannelCount(name, v)) {
		if (chan == 3)
			return TinyImageFormat_LC_1;
		else
			return TinyImageFormat_LC_0;
	}

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
		// signed init
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

	if (IsInASTC(name, v))
		return 0.0;

	return 0.0;
}

static double MaxActual(char const *name, uint64_t v, uint32_t const chan, bool ignoreNormFormats = false) {
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

	return 8;
}
static double Max(char const *name, uint64_t v, uint32_t const chan) {
	return MaxActual(name, v, chan, false);
}

static void GenBoolFunc(VFile_Handle file,
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

static void GenU32Func(VFile_Handle file,
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

static void GenNames(VFile_Handle file) {
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

static void GenNameLookup(VFile_Handle file) {
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

static void GenU32PerChanFunc(VFile_Handle file,
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

static bool UnpackPacked(char const *name, uint64_t const v, char *output) {
	if (v == 0)
		return false;

	if (IsInPacked(name, v)) {
		sprintf(output, "\n");
		// special case
		if (v == TinyImageFormat_E5B9G9R9_UFLOAT) {
			char const decoder[] = "\n\t\t\tTinyImageFormat_SharedE5B9G9R9UFloatToDoubles(*(uint32_t*)in, out);\n";
			sprintf(output, decoder);
			return true;
		}

		uint64_t vspec = v >> TinyImageFormat_PACK_SPECIAL_SHIFT;
		uint64_t vb = v >> TinyImageFormat_PACK_BITS_SHIFT;
		uint64_t vt = v >> TinyImageFormat_PACK_TYPE_SHIFT;
		uint64_t vs = v >> TinyImageFormat_PACK_SWIZZLE_SHIFT;

		bool freeChan[TinyImageFormat_PACK_NUM_CHANNELS] = {true, true, true, true};
		if (TinyImageFormat_PACK_SPECIAL_PACK != (vspec & Mask(TinyImageFormat_PACK_SPECIAL_REQUIRED_BITS))) {
			// easy not packed formats
			for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
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

				TinyImageFormat_Pack_Type type = (TinyImageFormat_Pack_Type) (vt & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));
				double const maxFactor = MaxActual(name, v,  i, true);
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
						}
						break;
					default:
					case TinyImageFormat_PACK_TYPE_NONE: continue;
					}

					char typeStringBuf[2048];
					sprintf(typeStringBuf, typeStringFmt, chanBitWidth);
					switch (type) {
					case TinyImageFormat_PACK_TYPE_UNORM:
						sprintf(output,
										"%s\t\t\tout[%d] = ((double)((%s const *)in)[%d]) * %1.8f;\n",
										output,
										swizzle,
										typeStringBuf,
										i,
										normalFactor);
						break;
					case TinyImageFormat_PACK_TYPE_SNORM:
						sprintf(output,
										"%s\t\t\tout[%d] = (((double)((%s const *)in)[%d]) * %1.8f) - 1.0;\n",
										output,
										swizzle,
										typeStringBuf,
										i,
										normalFactor);
						break;
					case TinyImageFormat_PACK_TYPE_SFLOAT:
						if(chanBitWidth == 16) {
							sprintf(output,
											"%s\t\t\tout[%d] = TinyImageFormat_HalfAsUintToDouble((((%s const *)in))[%d]);\n",
											output,
											swizzle,
											typeStringBuf,
											i);

						} else {
							sprintf(output,
											"%s\t\t\tout[%d] = (double)(((%s const *)in))[%d];\n",
											output,
											swizzle,
											typeStringBuf,
											i);
						}
						break;
					case TinyImageFormat_PACK_TYPE_UINT:
						sprintf(output,
										"%s\t\t\tout[%d] = (double)(((%s const *)in))[%d];\n",
										output,
										swizzle,
										typeStringBuf,
										i);
						break;
					case TinyImageFormat_PACK_TYPE_SINT:
						sprintf(output,
										"%s\t\t\tout[%d] = ((double)(((%s const *)in))[%d]) - %1.8f;\n",
										output,
										swizzle,
										typeStringBuf,
										i,
										maxFactor);
						break;
					case TinyImageFormat_PACK_TYPE_SRGB:
						sprintf(output,
										"%s\t\t\tout[%d] = (double)TinyImageFormat_LookupSRGB(((%s const *)in)[%d]);\n",
										output,
										swizzle,
										typeStringBuf,
										i);
						break;
					case TinyImageFormat_PACK_TYPE_UFLOAT:
					case TinyImageFormat_PACK_TYPE_NONE: ASSERT(false);
					}
					freeChan[swizzle] = false;
				} else {
					// found first free channel to put this constant in
					uint32_t firstFree = 0;
					for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
						if (freeChan[i] == true) {
							firstFree = i;
							break;
						}
					}
					if (firstFree < TinyImageFormat_PACK_NUM_CHANNELS) {
						double c = (double) ((-swizzle) - 1);
						switch (type) {
						case TinyImageFormat_PACK_TYPE_UINT:
						case TinyImageFormat_PACK_TYPE_SINT:
							sprintf(output, "%s\t\t\tout[%d] = %.f;\n", output, firstFree, c * maxFactor);
							break;
						default:
							sprintf(output, "%s\t\t\tout[%d] = %.f;\n", output, firstFree, c);
							break;
						}
						freeChan[firstFree] = false;
					}
				}

				vb = vb >> TinyImageFormat_PACK_BITS_REQUIRED_BITS;
				vt = vt >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
				vs = vs >> TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS;
			}
			return true;
		} else {
			// tightly packed formats

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
			// packed formats are currently limited to 32 bits but we allow 64 bit for future possibilities
			switch (bitWidth) {
			case 8: sprintf(output, "%s\t\t\tuint8_t val = ((uint8_t const*)in)[0];\n", output);
				break;
			case 16: sprintf(output, "%s\t\t\tuint16_t val = ((uint16_t const*)in)[0];\n", output);
				break;
			case 32: sprintf(output, "%s\t\t\tuint32_t val = ((uint32_t const*)in)[0];\n", output);
				break;
			case 64: sprintf(output, "%s\t\t\tuint64_t val = ((uint64_t const*)in)[0];\n", output);
				break;
			default:
				if (bitWidth < 8 || bitWidth > 64) {
					LOGERRORF("The total bitwidth of a pack pixel must be between 8 and 64 bits: %s has %d", name, bitWidth);
					return false;
				}
			}

			uint64_t shifter = 0;
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
				TinyImageFormat_Pack_Type	type = (TinyImageFormat_Pack_Type) (vt & Mask(TinyImageFormat_PACK_TYPE_REQUIRED_BITS));

				if (swizzle >= 0) {
					double normalFactor = 1.0 / maxFactor;

					switch (type) {
					case TinyImageFormat_PACK_TYPE_UNORM:
						sprintf(output,
										"%s\t\t\tout[%d] = ((double)((val >> %lld) & 0x%llx)) * %1.8f;\n",
										output,
										swizzle,
										shifter,
										Mask(chanBitWidth),
										normalFactor);
						break;
					case TinyImageFormat_PACK_TYPE_SNORM:
						sprintf(output,
										"%s\t\t\tout[%d] = (((double)((val >> %lld) & 0x%llx)) * %1.8f) - 1.0;\n",
										output,
										swizzle,
										shifter,
										Mask(chanBitWidth),
										normalFactor);
						break;
					case TinyImageFormat_PACK_TYPE_UINT:
						sprintf(output,
										"%s\t\t\tout[%d] = (double)((val >> %lld) & 0x%llx);\n",
										output,
										swizzle,
										shifter,
										Mask(chanBitWidth));
						break;
					case TinyImageFormat_PACK_TYPE_SINT:
						sprintf(output,
										"%s\t\t\tout[%d] = ((double)((val >> %lld) & 0x%llx)) - %1.8f;\n",
										output,
										swizzle,
										shifter,
										Mask(chanBitWidth),
										maxFactor);
						break;
					case TinyImageFormat_PACK_TYPE_SRGB:
						sprintf(output,
										"%s\t\t\tout[%d] = (double)TinyImageFormat_LookupSRGB((val >> %lld) & 0x%llx);\n",
										output,
										swizzle,
										shifter,
										Mask(chanBitWidth));
						break;
					case TinyImageFormat_PACK_TYPE_UFLOAT:
						if (chanBitWidth == 10) {
							sprintf(output,
											"%s\t\t\tout[%d] = TinyImageFormat_UFloat10ToDouble((val >> %lld) & 0x%llx);\n",
											output,
											swizzle,
											shifter,
											Mask(chanBitWidth));
						} else if (chanBitWidth == 11) {
							sprintf(output,
											"%s\t\t\tout[%d] = TinyImageFormat_UFloat11ToDouble((val >> %lld) & 0x%llx);\n",
											output,
											swizzle,
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
											swizzle,
											shifter,
											Mask(chanBitWidth));
						} else {
							ASSERT(false);
						}
						break;
					case TinyImageFormat_PACK_TYPE_NONE: ASSERT(false);
					}

					freeChan[TinyImageFormat_PACK_NUM_CHANNELS - i - 1] = false;
				} else {
					// found first free channel to put this constant in
					uint32_t firstFree = 0;
					for (int i = 0; i < TinyImageFormat_PACK_NUM_CHANNELS; ++i) {
						if (freeChan[i] == true) {
							firstFree = i;
							break;
						}
					}
					if (firstFree < TinyImageFormat_PACK_NUM_CHANNELS) {
						double c = (double) ((-swizzle) - 1);
						switch (type) {
						case TinyImageFormat_PACK_TYPE_UINT:
						case TinyImageFormat_PACK_TYPE_SINT:
							sprintf(output, "%s\t\t\tout[%d] = %.f;\n", output, firstFree, c * maxFactor);
							break;
						default:
							sprintf(output, "%s\t\t\tout[%d] = %.f;\n", output, firstFree, c);
							break;
						}
						freeChan[firstFree] = false;
					}
				}
				shifter += chanBitWidth;
				vb = vb >> TinyImageFormat_PACK_BITS_REQUIRED_BITS;
				vt = vt >> TinyImageFormat_PACK_TYPE_REQUIRED_BITS;
				vs = vs >> TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS;
			}
			return true;
		}
	} else {
		return false;
	}
}

static void GetSRGBTableFuncton(VFile_Handle file) {
	char const *const prefix =
			"TIF_CONSTEXPR float TinyImageFormat_LookupSRGB(uint8_t lookup) {\n"
	 		"\tswitch(lookup) {\n";
	char const * const body = "\t\tcase %d: return %1.8f;\n";
	char const *const postfix = "\t\tdefault: return 1.0;\n\t}\n }\n\n";

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
		sprintf(buffer, body, i, ((float const*)sRGBTable)[i]);
		VFile_Write(file, buffer, strlen(buffer));
	}

	VFile_Write(file, postfix, strlen(postfix));
}

static void GenCanFetchLogicalData(VFile_Handle file) {
	char buffer[2048];

	char const *const isPrefixF =
			"TIF_CONSTEXPR inline bool TinyImageFormat_CanFetchLogicalPixel(TinyImageFormat const fmt) {\n"
			"\tswitch(fmt) {\n";

	char const switchPostfixF[] = "\t\tdefault: return false;\n\t\t}\n\t}\n\n";

	char output[2048];
#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) { bool okay = UnpackPacked(#x, y, output); if(okay) { sprintf(buffer, "\t\tcase %s: {\t\t\treturn true;}\n", "TinyImageFormat_"#x); VFile_Write(file, buffer, strlen(buffer)); } }
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF); VFile_Write(file, buffer, strlen(buffer));
#include "formatgen.h"

}

static void GenFetchLogicalData(VFile_Handle file) {
	char buffer[2048];


	char const *const isPrefixF =
			"TIF_CONSTEXPR inline bool TinyImageFormat_FetchLogicalPixel(TinyImageFormat const fmt, void const* in, double* out) {\n"
			"\tswitch(fmt) {\n";

	char const switchPostfixF[] = "\t\tdefault: return false;\n\t\t}\n\t}\n\n";

	char output[2048];
#define  TinyImageFormat_START_MACRO VFile_Write(file, isPrefixF, strlen(isPrefixF));
#define  TinyImageFormat_MOD_MACRO(x, y) { bool okay = UnpackPacked(#x, y, output); if(okay) { sprintf(buffer, "\t\tcase %s: {%s\t\t\treturn true;}\n", "TinyImageFormat_"#x, output); VFile_Write(file, buffer, strlen(buffer)); } }
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF); VFile_Write(file, buffer, strlen(buffer));
#include "formatgen.h"

}

static void GenPhysicalChannelToLogicalPerChanFunc(VFile_Handle file,
																									 const char *testname) {
	int8_t (*func)(char const *, uint64_t, uint32_t) = &PhysicalChannelToLogical;

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
			"TIF_CONSTEXPR inline TinyImageFormat_LogicalChannel TinyImageFormat_%s(TinyImageFormat const fmt, int8_t const channel) {\n"
			"\t TinyImageFormat_ASSERT(channel != TinyImageFormat_PC_CONST_0);\n\t TinyImageFormat_ASSERT(channel != TinyImageFormat_PC_CONST_1);\n"
			"\tif(channel == %s) {\n\t\tswitch(fmt) {\n",
			"\telse if(channel == %s) {\n\t\tswitch(fmt) {\n"
	};
	static char const *const switchPostfixF = "\t\t\tdefault: return %s;\n\t\t}\n\t}";

	char buffer[2048];
	char prefix[2048];

	for (auto i = 0u; i < 4; ++i) {
		if (i == 0)
			sprintf(prefix, isPrefixF[0], testname, pnames[i]);
		else
			sprintf(prefix, isPrefixF[1], pnames[i]);

#define  TinyImageFormat_START_MACRO { VFile_Write(file, prefix, strlen(prefix));
#define  TinyImageFormat_MOD_MACRO(x, y) if(func(#x, y, i) != i) { sprintf(buffer, "\t\t\tcase %s: return %s;\n", "TinyImageFormat_"#x, lnames[func(#x, y,i)+2]); \
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

static void GenLogicalToPhysicalChannelPerChanFunc(VFile_Handle file,
																									 const char *testname) {

#define  TinyImageFormat_START_MACRO uint32_t fmtCount = 0;
#define  TinyImageFormat_MOD_MACRO(x, y) fmtCount++;
#define  TinyImageFormat_END_MACRO
#include "formatgen.h"

	// we need a buffer to store the physical to logical channel map for each channel
	int8_t *p2l = (int8_t *) malloc(sizeof(int8_t) * fmtCount * 4);
	int8_t *l2p = (int8_t *) malloc(sizeof(int8_t) * fmtCount * 4);

#define  TinyImageFormat_START_MACRO { uint32_t count = 0;
#define  TinyImageFormat_MOD_MACRO(x, y)  p2l[count + 0] = PhysicalChannelToLogical(#x, y, 0); \
                                          p2l[count + 1] = PhysicalChannelToLogical(#x, y, 1); \
                                          p2l[count + 2] = PhysicalChannelToLogical(#x, y, 2); \
                                          p2l[count + 3] = PhysicalChannelToLogical(#x, y, 3); \
                                          count += 4;
#define  TinyImageFormat_END_MACRO }
#include "formatgen.h"

	// now invert it except consts.
	for (auto f = 0u; f < fmtCount; ++f) {
		bool done[4] = {false, false, false, false};
		int8_t constants[4]{-1, -1, -1, -1};
		uint32_t constCount = 0;

		// two passes
		for (auto c = 0u; c < 4; ++c) {
			int8_t n = p2l[(f * 4) + c];
			if (n >= 0) {
				ASSERT(n < 4);
				l2p[(f * 4) + n] = c;
				done[n] = true;
			} else {
				constants[constCount++] = n;
			}
		}
		uint32_t constUsed = 0;
		for (auto c = 0u; c < 4; ++c) {
			if (!done[c]) {
				l2p[(f * 4) + c] = constants[constUsed++];
			}
		}
		ASSERT(constUsed == constCount);

	}
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
			"TIF_CONSTEXPR inline int8_t TinyImageFormat_%s(TinyImageFormat const fmt, TinyImageFormat_LogicalChannel const channel) {\n"
			"\t TinyImageFormat_ASSERT(channel != TinyImageFormat_LC_0);\n\t TinyImageFormat_ASSERT(channel != TinyImageFormat_LC_1);\n"
			"\tif(channel == TinyImageFormat_LC_Red) {\n\t\tswitch(fmt) {\n",
			"\telse if(channel == %s) {\n\t\tswitch(fmt) {\n"
	};
	static char const *const switchPostfixF = "\t\t\tdefault: return %s;\n\t\t}\n\t}";

	char buffer[2048];
	char prefix[2048];

	for (auto i = 0u; i < 4; ++i) {
		if (i == 0)
			sprintf(prefix, isPrefixF[0], testname);
		else
			sprintf(prefix, isPrefixF[1], lnames[i]);

#define  TinyImageFormat_START_MACRO { VFile_Write(file, prefix, strlen(prefix)); uint32_t count = 0;
#define  TinyImageFormat_MOD_MACRO(x, y) if(l2p[(count*4)+i] != i) { WriteL2PPack(file, "TinyImageFormat_"#x, l2p[(count*4)+i], y); } count++;
#define  TinyImageFormat_END_MACRO sprintf(buffer, switchPostfixF, pnames[i+2]); VFile_Write(file, buffer, strlen(buffer)); }
#include "formatgen.h"
	}

	char const closerF[] = "\n\t TinyImageFormat_ASSERT(false);\n\treturn TinyImageFormat_PC_CONST_0;\n}\n\n";
	VFile_Write(file, closerF, strlen(closerF));
	free(p2l);
	free(l2p);
}

static void GenDoublePerChanFunc(VFile_Handle file,
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

#define GEN_BOOL_FUNC(f, d, t) GenBoolFunc(f, #t, d, &t)
#define GEN_U32_FUNC(f, d, t) GenU32Func(f, #t, d, &t)
#define GEN_U32PERCHAN_FUNC(f, d, t) GenU32PerChanFunc(f, #t, d, &t)
#define GEN_DBLPERCHAN_FUNC(f, d, t) GenDoublePerChanFunc(f, #t, d, &t)

int main(int argc, char const *argv[]) {
	char const header[] =
			"//Auto generated by formatgen on " __DATE__ "\n"
			"#pragma once\n";
	char const header2[] =
			"#define  TINYIMAGEFORMAT_IMAGEFORMAT_H\n"
			"#if __cplusplus\n"
			"#define TIF_CONSTEXPR constexpr\n"
			"#else\n"
			"#define TIF_CONSTEXPR\n"
			"#endif\n"
			"#ifndef  TinyImageFormat_HAVE_UINTXX_T\n"
			"#include <stdint.h> 	// for uint32_t and int64_t\n"
			"#endif\n"
			"#ifndef  TinyImageFormat_HAVE_BOOL\n"
			"#include <stdbool.h>	// for bool\n"
			"#endif\n"
			"#ifndef  TinyImageFormat_ASSERT\n"
			"#include <assert.h>\n"
			"#define  TinyImageFormat_ASSERT assert\n"
			"#endif\n"
			"\n";
	char const suffix[] =
			"#undef TIF_CONSTEXPR\n"
			"\n";
	// generate format
	VFile_Handle file = VFile_FromFile("tinyimageformat.h", Os_FM_Write);
	VFile_Write(file, header, strlen(header));
	IncludeDocs(file);
	VFile_Write(file, header2, strlen(header2));

	GenEnums(file);
	GenCount(file);

	GEN_BOOL_FUNC(file, false, IsDepthOnly);
	GEN_BOOL_FUNC(file, false, IsStencilOnly);
	GEN_BOOL_FUNC(file, false, IsDepthAndStencil);
	GEN_BOOL_FUNC(file, false, IsCLUT);
	GEN_BOOL_FUNC(file, false, IsFloat);
	GEN_BOOL_FUNC(file, false, IsNormalised);
	GEN_BOOL_FUNC(file, false, IsSigned);
	GEN_BOOL_FUNC(file, false, IsSRGB);
	GEN_BOOL_FUNC(file, false, IsCompressed);
	GEN_BOOL_FUNC(file, true, IsHomogenous);

	GEN_U32_FUNC(file, 1, WidthOfBlock);
	GEN_U32_FUNC(file, 1, HeightOfBlock);
	GEN_U32_FUNC(file, 1, DepthOfBlock);
	GEN_U32_FUNC(file, 32, BitSizeBlock);
	GEN_U32_FUNC(file, 4, ChannelCount);
	GEN_U32PERCHAN_FUNC(file, 8, ChannelBitWidth);
	GEN_DBLPERCHAN_FUNC(file, 0.0, Min);
	GEN_DBLPERCHAN_FUNC(file, 1.0, Max);
	GenPhysicalChannelToLogicalPerChanFunc(file, "PhysicalChannelToLogical");
	GenLogicalToPhysicalChannelPerChanFunc(file, "LogicalChannelToPhysical");
	GenNames(file);
	GenNameLookup(file);
	IncludeOtherImageEnums(file);

	IncludeHelpers(file);

	GetSRGBTableFuncton(file);
	GenCanFetchLogicalData(file);
	GenFetchLogicalData(file);
	VFile_Write(file, suffix, strlen(suffix));

	VFile_Close(file);
	return 0;
}