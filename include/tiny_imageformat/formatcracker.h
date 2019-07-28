#pragma once
#ifndef TINYIMAGEFORMAT_IMAGEFORMAT_H
#define TINYIMAGEFORMAT_IMAGEFORMAT_H

#include "tiny_imageformat/format.h"
#ifndef TINYIMAGEFORMAT_HAVE_UINTXX_T
#include <stdint.h> // for uint32_t etc.
#endif
#ifndef TINYIMAGEFORMAT_HAVE_BOOL
#include <stdbool.h> // for bool
#endif

#ifndef TINYIMAGEFORMAT_HAVE_LIMITS_H
#include <limits.h> // for max/min types
#endif

#ifndef TINYIMAGEFORMAT_HAVE_FLOAT_H
#include <float.h> // for max/min float types
#endif

#ifndef AL2O3_EXTERN_C
#ifdef __cplusplus
#define AL2O3_EXTERN_C extern "C"
#else //!__cplusplus
#define AL2O3_EXTERN_C
#endif // end !_cplusplus
#endif

#ifndef ASSERT
#include <assert.h>
#define ASSERT assert
#endif
#ifndef LOGWARNINGF
#define LOGWARNINGF(message, ...)
#endif
#ifndef LOGERRORF
#define LOGERRORF(message, ...)
#endif

AL2O3_EXTERN_C char const *TinyImageFormat_Name(TinyImageFormat const fmt);
AL2O3_EXTERN_C TinyImageFormat TinyImageFormat_FromName(char const *name);

#ifdef __cplusplus
constexpr uint32_t TinyImageFormat_Count() {
	uint32_t count = 0;
#define IF_START_MACRO
#define IF_MOD_MACRO(x) count++;
#define IF_END_MACRO
#include "tiny_imageformat/format.h"
	return count;
}
#else
AL2O3_EXTERN_C uint32_t TinyImageFormat_Count();
#endif

AL2O3_EXTERN_C inline bool TinyImageFormat_IsDepth(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_D16_UNORM:
	case TinyImageFormat_X8_D24_UNORM_PACK32:
	case TinyImageFormat_D32_SFLOAT:
	case TinyImageFormat_D16_UNORM_S8_UINT:
	case TinyImageFormat_D24_UNORM_S8_UINT:
	case TinyImageFormat_D32_SFLOAT_S8_UINT:return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool TinyImageFormat_IsStencil(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_S8_UINT:
	case TinyImageFormat_D16_UNORM_S8_UINT:
	case TinyImageFormat_D24_UNORM_S8_UINT:
	case TinyImageFormat_D32_SFLOAT_S8_UINT:return true;
	default:return false;
	}
}

//! is this texture format a depth stencil format?
AL2O3_EXTERN_C inline bool TinyImageFormat_IsDepthStencil(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_D16_UNORM_S8_UINT:
	case TinyImageFormat_D24_UNORM_S8_UINT:
	case TinyImageFormat_D32_SFLOAT_S8_UINT:return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool TinyImageFormat_IsFloat(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_R16_SFLOAT:
	case TinyImageFormat_R16G16_SFLOAT:
	case TinyImageFormat_R16G16B16_SFLOAT:
	case TinyImageFormat_R16G16B16A16_SFLOAT:
	case TinyImageFormat_R32_SFLOAT:
	case TinyImageFormat_R32G32_SFLOAT:
	case TinyImageFormat_R32G32B32_SFLOAT:
	case TinyImageFormat_R32G32B32A32_SFLOAT:
	case TinyImageFormat_R64_SFLOAT:
	case TinyImageFormat_R64G64_SFLOAT:
	case TinyImageFormat_R64G64B64_SFLOAT:
	case TinyImageFormat_R64G64B64A64_SFLOAT:
	case TinyImageFormat_D32_SFLOAT:
	case TinyImageFormat_D32_SFLOAT_S8_UINT:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32:
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32: return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool TinyImageFormat_IsNormalised(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_R4G4_UNORM_PACK8:
	case TinyImageFormat_R4G4B4A4_UNORM_PACK16:
	case TinyImageFormat_B4G4R4A4_UNORM_PACK16:
	case TinyImageFormat_R5G6B5_UNORM_PACK16:
	case TinyImageFormat_B5G6R5_UNORM_PACK16:
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16:
	case TinyImageFormat_B5G5R5A1_UNORM_PACK16:
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16:
	case TinyImageFormat_R8_UNORM:
	case TinyImageFormat_R8_SNORM:
	case TinyImageFormat_R8G8_UNORM:
	case TinyImageFormat_R8G8_SNORM:
	case TinyImageFormat_R8G8B8_UNORM:
	case TinyImageFormat_R8G8B8_SNORM:
	case TinyImageFormat_B8G8R8_UNORM:
	case TinyImageFormat_B8G8R8_SNORM:
	case TinyImageFormat_R8G8B8A8_UNORM:
	case TinyImageFormat_R8G8B8A8_SNORM:
	case TinyImageFormat_B8G8R8A8_UNORM:
	case TinyImageFormat_B8G8R8A8_SNORM:
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:
	case TinyImageFormat_A2R10G10B10_UNORM_PACK32:
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32:
	case TinyImageFormat_R16_UNORM:
	case TinyImageFormat_R16_SNORM:
	case TinyImageFormat_R16G16_UNORM:
	case TinyImageFormat_R16G16_SNORM:
	case TinyImageFormat_R16G16B16_UNORM:
	case TinyImageFormat_R16G16B16_SNORM:
	case TinyImageFormat_R16G16B16A16_UNORM:
	case TinyImageFormat_R16G16B16A16_SNORM:
	case TinyImageFormat_X8_D24_UNORM_PACK32:
	case TinyImageFormat_D16_UNORM:
	case TinyImageFormat_D16_UNORM_S8_UINT:
	case TinyImageFormat_D24_UNORM_S8_UINT:
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:

	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:

	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:

	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:

	case TinyImageFormat_A4R4G4B4_UNORM_PACK16:
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32:
	case TinyImageFormat_A8_UNORM:
		return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool TinyImageFormat_IsSigned(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_R8_SNORM:
	case TinyImageFormat_R8_SSCALED:
	case TinyImageFormat_R8_SINT:
	case TinyImageFormat_R8G8_SNORM:
	case TinyImageFormat_R8G8_SSCALED:
	case TinyImageFormat_R8G8_SINT:
	case TinyImageFormat_R8G8B8_SNORM:
	case TinyImageFormat_R8G8B8_SSCALED:
	case TinyImageFormat_R8G8B8_SINT:
	case TinyImageFormat_B8G8R8_SNORM:
	case TinyImageFormat_B8G8R8_SINT:
	case TinyImageFormat_B8G8R8_SSCALED:
	case TinyImageFormat_R8G8B8A8_SNORM:
	case TinyImageFormat_R8G8B8A8_SINT:
	case TinyImageFormat_R8G8B8A8_SSCALED:
	case TinyImageFormat_B8G8R8A8_SNORM:
	case TinyImageFormat_B8G8R8A8_SINT:
	case TinyImageFormat_B8G8R8A8_SSCALED:
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_SINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32:
	case TinyImageFormat_R16_SNORM:
	case TinyImageFormat_R16_SINT:
	case TinyImageFormat_R16_SSCALED:
	case TinyImageFormat_R16_SFLOAT:
	case TinyImageFormat_R16G16_SNORM:
	case TinyImageFormat_R16G16_SINT:
	case TinyImageFormat_R16G16_SSCALED:
	case TinyImageFormat_R16G16_SFLOAT:
	case TinyImageFormat_R16G16B16_SNORM:
	case TinyImageFormat_R16G16B16_SINT:
	case TinyImageFormat_R16G16B16_SSCALED:
	case TinyImageFormat_R16G16B16_SFLOAT:
	case TinyImageFormat_R16G16B16A16_SNORM:
	case TinyImageFormat_R16G16B16A16_SINT:
	case TinyImageFormat_R16G16B16A16_SSCALED:
	case TinyImageFormat_R16G16B16A16_SFLOAT:
	case TinyImageFormat_R32_SINT:
	case TinyImageFormat_R32_SFLOAT:
	case TinyImageFormat_R32G32_SINT:
	case TinyImageFormat_R32G32_SFLOAT:
	case TinyImageFormat_R32G32B32_SINT:
	case TinyImageFormat_R32G32B32_SFLOAT:
	case TinyImageFormat_R32G32B32A32_SINT:
	case TinyImageFormat_R32G32B32A32_SFLOAT:
	case TinyImageFormat_R64_SINT:
	case TinyImageFormat_R64_SFLOAT:
	case TinyImageFormat_R64G64_SINT:
	case TinyImageFormat_R64G64_SFLOAT:
	case TinyImageFormat_R64G64B64_SINT:
	case TinyImageFormat_R64G64B64_SFLOAT:
	case TinyImageFormat_R64G64B64A64_SINT:
	case TinyImageFormat_R64G64B64A64_SFLOAT:
	case TinyImageFormat_D32_SFLOAT:
	case TinyImageFormat_D32_SFLOAT_S8_UINT:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:

		return true;

	default: return false;
	}
}
AL2O3_EXTERN_C inline bool TinyImageFormat_IsSRGB(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_R8_SRGB:
	case TinyImageFormat_R8G8_SRGB:
	case TinyImageFormat_R8G8B8_SRGB:
	case TinyImageFormat_B8G8R8_SRGB:
	case TinyImageFormat_R8G8B8A8_SRGB:
	case TinyImageFormat_B8G8R8A8_SRGB:
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK: return true;

	default: return false;
	}
}

AL2O3_EXTERN_C inline bool TinyImageFormat_IsCompressed(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:

	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:

	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:

	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK: return true;

	default:return false;
	}
}

AL2O3_EXTERN_C inline uint32_t TinyImageFormat_WidthOfBlock(TinyImageFormat const fmt) {
	if(!TinyImageFormat_IsCompressed(fmt)) return 1;

	switch (fmt) {
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK: return 4;
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK: return 4;
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK: return 5;
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK: return 6;
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK: return 8;
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK: return 10;
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK: return 12;

	default: ASSERT(false);
		return 0;
	}
}

AL2O3_EXTERN_C inline uint32_t TinyImageFormat_HeightOfBlock(TinyImageFormat const fmt) {
	if(!TinyImageFormat_IsCompressed(fmt)) return 1;

	switch (fmt) {
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:

	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK: return 4;
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK: return 8;

	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK: return 4;

	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK: return 5;

	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK: return 6;

	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK: return 8;

	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK: return 10;

	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK: return 12;

	default: ASSERT(false);
		return 0;
	}
}

AL2O3_EXTERN_C inline uint32_t TinyImageFormat_DepthOfBlock(TinyImageFormat const fmt) {
	if(!TinyImageFormat_IsCompressed(fmt)) return 1;
	return 1; // no 3d compressed formats yet
}

AL2O3_EXTERN_C inline uint32_t TinyImageFormat_PixelCountOfBlock(TinyImageFormat const fmt) {
	if(!TinyImageFormat_IsCompressed(fmt)) {
		return 1;
	} else {
		return TinyImageFormat_WidthOfBlock(fmt) * TinyImageFormat_HeightOfBlock(fmt) * TinyImageFormat_DepthOfBlock(fmt);
	}
}

AL2O3_EXTERN_C inline uint32_t TinyImageFormat_BitSizeOfBlock(TinyImageFormat const fmt) {
	ASSERT(TinyImageFormat_IsCompressed(fmt));

	switch (fmt) {
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK: return 32;
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK: return 64;
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK: return 128;

	default: ASSERT(false);
		return 0;
	}
}

//! returns the number of channels per gl format
AL2O3_EXTERN_C inline uint32_t TinyImageFormat_ChannelCount(enum TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_R4G4B4A4_UNORM_PACK16:
	case TinyImageFormat_B4G4R4A4_UNORM_PACK16:
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16:
	case TinyImageFormat_B5G5R5A1_UNORM_PACK16:
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16:
	case TinyImageFormat_R8G8B8A8_UNORM:
	case TinyImageFormat_R8G8B8A8_SNORM:
	case TinyImageFormat_R8G8B8A8_USCALED:
	case TinyImageFormat_R8G8B8A8_SSCALED:
	case TinyImageFormat_R8G8B8A8_UINT:
	case TinyImageFormat_R8G8B8A8_SINT:
	case TinyImageFormat_R8G8B8A8_SRGB:
	case TinyImageFormat_B8G8R8A8_UNORM:
	case TinyImageFormat_B8G8R8A8_SNORM:
	case TinyImageFormat_B8G8R8A8_USCALED:
	case TinyImageFormat_B8G8R8A8_SSCALED:
	case TinyImageFormat_B8G8R8A8_UINT:
	case TinyImageFormat_B8G8R8A8_SINT:
	case TinyImageFormat_B8G8R8A8_SRGB:
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_UINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32:
	case TinyImageFormat_A2R10G10B10_UNORM_PACK32:
	case TinyImageFormat_A2R10G10B10_USCALED_PACK32:
	case TinyImageFormat_A2R10G10B10_UINT_PACK32:
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32:
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32:
	case TinyImageFormat_A2B10G10R10_UINT_PACK32:
	case TinyImageFormat_R16G16B16A16_UNORM:
	case TinyImageFormat_R16G16B16A16_SNORM:
	case TinyImageFormat_R16G16B16A16_USCALED:
	case TinyImageFormat_R16G16B16A16_SSCALED:
	case TinyImageFormat_R16G16B16A16_UINT:
	case TinyImageFormat_R16G16B16A16_SINT:
	case TinyImageFormat_R16G16B16A16_SFLOAT:
	case TinyImageFormat_R32G32B32A32_UINT:
	case TinyImageFormat_R32G32B32A32_SINT:
	case TinyImageFormat_R32G32B32A32_SFLOAT:
	case TinyImageFormat_R64G64B64A64_UINT:
	case TinyImageFormat_R64G64B64A64_SINT:
	case TinyImageFormat_R64G64B64A64_SFLOAT:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK:
	case TinyImageFormat_A4R4G4B4_UNORM_PACK16:
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32:
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32:
		return 4;

	case TinyImageFormat_R5G6B5_UNORM_PACK16:
	case TinyImageFormat_B5G6R5_UNORM_PACK16:
	case TinyImageFormat_R8G8B8_UNORM:
	case TinyImageFormat_R8G8B8_SNORM:
	case TinyImageFormat_R8G8B8_USCALED:
	case TinyImageFormat_R8G8B8_SSCALED:
	case TinyImageFormat_R8G8B8_UINT:
	case TinyImageFormat_R8G8B8_SINT:
	case TinyImageFormat_R8G8B8_SRGB:
	case TinyImageFormat_B8G8R8_UNORM:
	case TinyImageFormat_B8G8R8_SNORM:
	case TinyImageFormat_B8G8R8_USCALED:
	case TinyImageFormat_B8G8R8_SSCALED:
	case TinyImageFormat_B8G8R8_UINT:
	case TinyImageFormat_B8G8R8_SINT:
	case TinyImageFormat_B8G8R8_SRGB:
	case TinyImageFormat_R16G16B16_UNORM:
	case TinyImageFormat_R16G16B16_SNORM:
	case TinyImageFormat_R16G16B16_USCALED:
	case TinyImageFormat_R16G16B16_SSCALED:
	case TinyImageFormat_R16G16B16_UINT:
	case TinyImageFormat_R16G16B16_SINT:
	case TinyImageFormat_R16G16B16_SFLOAT:
	case TinyImageFormat_R32G32B32_UINT:
	case TinyImageFormat_R32G32B32_SINT:
	case TinyImageFormat_R32G32B32_SFLOAT:
	case TinyImageFormat_R64G64B64_UINT:
	case TinyImageFormat_R64G64B64_SINT:
	case TinyImageFormat_R64G64B64_SFLOAT:
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32:
		return 3;

	case TinyImageFormat_R4G4_UNORM_PACK8:
	case TinyImageFormat_R8G8_UNORM:
	case TinyImageFormat_R8G8_SNORM:
	case TinyImageFormat_R8G8_USCALED:
	case TinyImageFormat_R8G8_SSCALED:
	case TinyImageFormat_R8G8_UINT:
	case TinyImageFormat_R8G8_SINT:
	case TinyImageFormat_R8G8_SRGB:
	case TinyImageFormat_R16G16_UNORM:
	case TinyImageFormat_R16G16_SNORM:
	case TinyImageFormat_R16G16_USCALED:
	case TinyImageFormat_R16G16_SSCALED:
	case TinyImageFormat_R16G16_UINT:
	case TinyImageFormat_R16G16_SINT:
	case TinyImageFormat_R16G16_SFLOAT:
	case TinyImageFormat_R32G32_UINT:
	case TinyImageFormat_R32G32_SINT:
	case TinyImageFormat_R32G32_SFLOAT:
	case TinyImageFormat_R64G64_UINT:
	case TinyImageFormat_R64G64_SINT:
	case TinyImageFormat_R64G64_SFLOAT:
	case TinyImageFormat_X8_D24_UNORM_PACK32:
	case TinyImageFormat_D16_UNORM_S8_UINT:
	case TinyImageFormat_D24_UNORM_S8_UINT:
	case TinyImageFormat_D32_SFLOAT_S8_UINT:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK: return 2;

	case TinyImageFormat_R8_UNORM:
	case TinyImageFormat_R8_SNORM:
	case TinyImageFormat_R8_USCALED:
	case TinyImageFormat_R8_SSCALED:
	case TinyImageFormat_R8_UINT:
	case TinyImageFormat_R8_SINT:
	case TinyImageFormat_R8_SRGB:
	case TinyImageFormat_R16_UNORM:
	case TinyImageFormat_R16_SNORM:
	case TinyImageFormat_R16_USCALED:
	case TinyImageFormat_R16_SSCALED:
	case TinyImageFormat_R16_UINT:
	case TinyImageFormat_R16_SINT:
	case TinyImageFormat_R16_SFLOAT:
	case TinyImageFormat_R32_UINT:
	case TinyImageFormat_R32_SINT:
	case TinyImageFormat_R32_SFLOAT:
	case TinyImageFormat_R64_UINT:
	case TinyImageFormat_R64_SINT:
	case TinyImageFormat_R64_SFLOAT:
	case TinyImageFormat_D16_UNORM:
	case TinyImageFormat_D32_SFLOAT:
	case TinyImageFormat_S8_UINT:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_A8_UNORM:
		return 1;
	case TinyImageFormat_UNDEFINED:return 0;

	}
	LOGERRORF("channelCount: %s not handled", TinyImageFormat_Name(fmt));
	return 0;
}

//! Returns the number of channel bits for each channel for non compressed formats
AL2O3_EXTERN_C inline uint32_t TinyImageFormat_ChannelBitWidth(enum TinyImageFormat const fmt, int const channel_) {
	ASSERT(!TinyImageFormat_IsCompressed(fmt));
	switch (fmt) {
	case TinyImageFormat_R64_UINT:
	case TinyImageFormat_R64_SINT:
	case TinyImageFormat_R64_SFLOAT:
	case TinyImageFormat_R64G64_UINT:
	case TinyImageFormat_R64G64_SINT:
	case TinyImageFormat_R64G64_SFLOAT:
	case TinyImageFormat_R64G64B64_UINT:
	case TinyImageFormat_R64G64B64_SINT:
	case TinyImageFormat_R64G64B64_SFLOAT:
	case TinyImageFormat_R64G64B64A64_UINT:
	case TinyImageFormat_R64G64B64A64_SINT:
	case TinyImageFormat_R64G64B64A64_SFLOAT:return 64;
	case TinyImageFormat_R32_UINT:
	case TinyImageFormat_R32_SINT:
	case TinyImageFormat_R32_SFLOAT:
	case TinyImageFormat_R32G32_UINT:
	case TinyImageFormat_R32G32_SINT:
	case TinyImageFormat_R32G32_SFLOAT:
	case TinyImageFormat_R32G32B32_UINT:
	case TinyImageFormat_R32G32B32_SINT:
	case TinyImageFormat_R32G32B32_SFLOAT:
	case TinyImageFormat_R32G32B32A32_UINT:
	case TinyImageFormat_R32G32B32A32_SINT:
	case TinyImageFormat_R32G32B32A32_SFLOAT:
	case TinyImageFormat_D32_SFLOAT:return 32;
	case TinyImageFormat_X8_D24_UNORM_PACK32:
		if (channel_ == 1) {
			return 24;
		} else {
			return 8;
		}
	case TinyImageFormat_D16_UNORM_S8_UINT:
		if (channel_ == 0) {
			return 16;
		} else {
			return 8;
		}
	case TinyImageFormat_D24_UNORM_S8_UINT:
		if (channel_ == 0) {
			return 24;
		} else {
			return 8;
		}
	case TinyImageFormat_D32_SFLOAT_S8_UINT:
		if (channel_ == 0) {
			return 32;
		} else {
			return 8;
		}

	case TinyImageFormat_R16_UNORM:
	case TinyImageFormat_R16_SNORM:
	case TinyImageFormat_R16_USCALED:
	case TinyImageFormat_R16_SSCALED:
	case TinyImageFormat_R16_UINT:
	case TinyImageFormat_R16_SINT:
	case TinyImageFormat_R16_SFLOAT:
	case TinyImageFormat_R16G16_UNORM:
	case TinyImageFormat_R16G16_SNORM:
	case TinyImageFormat_R16G16_USCALED:
	case TinyImageFormat_R16G16_SSCALED:
	case TinyImageFormat_R16G16_UINT:
	case TinyImageFormat_R16G16_SINT:
	case TinyImageFormat_R16G16_SFLOAT:
	case TinyImageFormat_R16G16B16_UNORM:
	case TinyImageFormat_R16G16B16_SNORM:
	case TinyImageFormat_R16G16B16_USCALED:
	case TinyImageFormat_R16G16B16_SSCALED:
	case TinyImageFormat_R16G16B16_UINT:
	case TinyImageFormat_R16G16B16_SINT:
	case TinyImageFormat_R16G16B16_SFLOAT:
	case TinyImageFormat_R16G16B16A16_UNORM:
	case TinyImageFormat_R16G16B16A16_SNORM:
	case TinyImageFormat_R16G16B16A16_USCALED:
	case TinyImageFormat_R16G16B16A16_SSCALED:
	case TinyImageFormat_R16G16B16A16_UINT:
	case TinyImageFormat_R16G16B16A16_SINT:
	case TinyImageFormat_R16G16B16A16_SFLOAT:
	case TinyImageFormat_D16_UNORM:return 16;
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32:
		if (channel_ == 0)
			return 10;
		else
			return 11;
	case TinyImageFormat_A2R10G10B10_UNORM_PACK32:
	case TinyImageFormat_A2R10G10B10_USCALED_PACK32:
	case TinyImageFormat_A2R10G10B10_UINT_PACK32:
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32:
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32:
	case TinyImageFormat_A2B10G10R10_UINT_PACK32:
		if (channel_ == 0) {
			return 2;
		} else {
			return 10;
		}
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32:
		if (channel_ == 0)
			return 5;
		else
			return 9;
	case TinyImageFormat_R8_UNORM:
	case TinyImageFormat_R8_SNORM:
	case TinyImageFormat_R8_USCALED:
	case TinyImageFormat_R8_SSCALED:
	case TinyImageFormat_R8_UINT:
	case TinyImageFormat_R8_SINT:
	case TinyImageFormat_R8_SRGB:
	case TinyImageFormat_R8G8_UNORM:
	case TinyImageFormat_R8G8_SNORM:
	case TinyImageFormat_R8G8_USCALED:
	case TinyImageFormat_R8G8_SSCALED:
	case TinyImageFormat_R8G8_UINT:
	case TinyImageFormat_R8G8_SINT:
	case TinyImageFormat_R8G8_SRGB:
	case TinyImageFormat_R8G8B8_UNORM:
	case TinyImageFormat_R8G8B8_SNORM:
	case TinyImageFormat_R8G8B8_USCALED:
	case TinyImageFormat_R8G8B8_SSCALED:
	case TinyImageFormat_R8G8B8_UINT:
	case TinyImageFormat_R8G8B8_SINT:
	case TinyImageFormat_R8G8B8_SRGB:
	case TinyImageFormat_B8G8R8_UNORM:
	case TinyImageFormat_B8G8R8_SNORM:
	case TinyImageFormat_B8G8R8_USCALED:
	case TinyImageFormat_B8G8R8_SSCALED:
	case TinyImageFormat_B8G8R8_UINT:
	case TinyImageFormat_B8G8R8_SINT:
	case TinyImageFormat_B8G8R8_SRGB:
	case TinyImageFormat_R8G8B8A8_UNORM:
	case TinyImageFormat_R8G8B8A8_SNORM:
	case TinyImageFormat_R8G8B8A8_USCALED:
	case TinyImageFormat_R8G8B8A8_SSCALED:
	case TinyImageFormat_R8G8B8A8_UINT:
	case TinyImageFormat_R8G8B8A8_SINT:
	case TinyImageFormat_R8G8B8A8_SRGB:
	case TinyImageFormat_B8G8R8A8_UNORM:
	case TinyImageFormat_B8G8R8A8_SNORM:
	case TinyImageFormat_B8G8R8A8_USCALED:
	case TinyImageFormat_B8G8R8A8_SSCALED:
	case TinyImageFormat_B8G8R8A8_UINT:
	case TinyImageFormat_B8G8R8A8_SINT:
	case TinyImageFormat_B8G8R8A8_SRGB:
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_UINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_S8_UINT:
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32:
	case TinyImageFormat_A8_UNORM:
		return 8;

	case TinyImageFormat_R4G4_UNORM_PACK8:
	case TinyImageFormat_R4G4B4A4_UNORM_PACK16:
	case TinyImageFormat_B4G4R4A4_UNORM_PACK16:
		return 4;
	case TinyImageFormat_R5G6B5_UNORM_PACK16:
	case TinyImageFormat_B5G6R5_UNORM_PACK16:
		if(channel_ == 1) {
			return 6;
		} else
		{
			return 5;
		}
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16:
	case TinyImageFormat_B5G5R5A1_UNORM_PACK16:
		if(channel_ == 3) {
			return 1;
		} else
		{
			return 5;
		}
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16:
		if(channel_ == 0) {
			return 1;
		} else
		{
			return 5;
		}

	case TinyImageFormat_UNDEFINED:return 0;
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:break;
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:break;
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:break;
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:break;
	case TinyImageFormat_BC2_UNORM_BLOCK:break;
	case TinyImageFormat_BC2_SRGB_BLOCK:break;
	case TinyImageFormat_BC3_UNORM_BLOCK:break;
	case TinyImageFormat_BC3_SRGB_BLOCK:break;
	case TinyImageFormat_BC7_UNORM_BLOCK:break;
	case TinyImageFormat_BC7_SRGB_BLOCK:break;
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:break;
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:break;
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:break;
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:break;
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:break;
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:break;
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:break;
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:break;
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:break;
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:break;
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:break;
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:break;
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:break;
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:break;
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:break;
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:break;
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:break;
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:break;
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:break;
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:break;
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK:break;
	case TinyImageFormat_A4R4G4B4_UNORM_PACK16:break;
	}
	LOGERRORF("channelBitWidth: %s not handled", TinyImageFormat_Name(fmt));
	return 0;
}

AL2O3_EXTERN_C inline uint32_t TinyImageFormat_BitSize(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_R64G64B64A64_UINT:
	case TinyImageFormat_R64G64B64A64_SINT:
	case TinyImageFormat_R64G64B64A64_SFLOAT:return 256;
	case TinyImageFormat_R64G64B64_UINT:
	case TinyImageFormat_R64G64B64_SINT:
	case TinyImageFormat_R64G64B64_SFLOAT:return 192;

	case TinyImageFormat_R64G64_UINT:
	case TinyImageFormat_R64G64_SINT:
	case TinyImageFormat_R64G64_SFLOAT:
	case TinyImageFormat_R32G32B32A32_UINT:
	case TinyImageFormat_R32G32B32A32_SINT:
	case TinyImageFormat_R32G32B32A32_SFLOAT:return 128;

	case TinyImageFormat_R32G32B32_UINT:
	case TinyImageFormat_R32G32B32_SINT:
	case TinyImageFormat_R32G32B32_SFLOAT:return 96;
	case TinyImageFormat_R64_UINT:
	case TinyImageFormat_R64_SINT:
	case TinyImageFormat_R64_SFLOAT:
	case TinyImageFormat_R32G32_UINT:
	case TinyImageFormat_R32G32_SINT:
	case TinyImageFormat_R32G32_SFLOAT:
	case TinyImageFormat_R16G16B16A16_UNORM:
	case TinyImageFormat_R16G16B16A16_SNORM:
	case TinyImageFormat_R16G16B16A16_USCALED:
	case TinyImageFormat_R16G16B16A16_SSCALED:
	case TinyImageFormat_R16G16B16A16_UINT:
	case TinyImageFormat_R16G16B16A16_SINT:
	case TinyImageFormat_R16G16B16A16_SFLOAT:return 64;

		// best case 40 bits worse case 64, be a pessimist
	case TinyImageFormat_D32_SFLOAT_S8_UINT:return 64;

	case TinyImageFormat_R16G16B16_UNORM:
	case TinyImageFormat_R16G16B16_SNORM:
	case TinyImageFormat_R16G16B16_USCALED:
	case TinyImageFormat_R16G16B16_SSCALED:
	case TinyImageFormat_R16G16B16_UINT:
	case TinyImageFormat_R16G16B16_SINT:
	case TinyImageFormat_R16G16B16_SFLOAT:return 48;
	case TinyImageFormat_R32_SINT:
	case TinyImageFormat_R32_UINT:
	case TinyImageFormat_R32_SFLOAT:
	case TinyImageFormat_R16G16_SINT:
	case TinyImageFormat_R16G16_SFLOAT:
	case TinyImageFormat_R16G16_SNORM:
	case TinyImageFormat_R16G16_UNORM:
	case TinyImageFormat_R16G16_UINT:
	case TinyImageFormat_R16G16_USCALED:
	case TinyImageFormat_R16G16_SSCALED:
	case TinyImageFormat_R8G8B8A8_UNORM:
	case TinyImageFormat_R8G8B8A8_SNORM:
	case TinyImageFormat_R8G8B8A8_USCALED:
	case TinyImageFormat_R8G8B8A8_SSCALED:
	case TinyImageFormat_R8G8B8A8_UINT:
	case TinyImageFormat_R8G8B8A8_SINT:
	case TinyImageFormat_R8G8B8A8_SRGB:
	case TinyImageFormat_B8G8R8A8_UNORM:
	case TinyImageFormat_B8G8R8A8_SNORM:
	case TinyImageFormat_B8G8R8A8_USCALED:
	case TinyImageFormat_B8G8R8A8_SSCALED:
	case TinyImageFormat_B8G8R8A8_UINT:
	case TinyImageFormat_B8G8R8A8_SINT:
	case TinyImageFormat_B8G8R8A8_SRGB:
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_UINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32:
	case TinyImageFormat_A2R10G10B10_UNORM_PACK32:
	case TinyImageFormat_A2R10G10B10_USCALED_PACK32:
	case TinyImageFormat_A2R10G10B10_UINT_PACK32:
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32:
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32:
	case TinyImageFormat_A2B10G10R10_UINT_PACK32:
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32:
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32:
	case TinyImageFormat_X8_D24_UNORM_PACK32:
	case TinyImageFormat_D32_SFLOAT:
	case TinyImageFormat_D24_UNORM_S8_UINT:
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32: return 32;

	case TinyImageFormat_R8G8B8_UNORM:
	case TinyImageFormat_R8G8B8_SNORM:
	case TinyImageFormat_R8G8B8_USCALED:
	case TinyImageFormat_R8G8B8_SSCALED:
	case TinyImageFormat_R8G8B8_UINT:
	case TinyImageFormat_R8G8B8_SINT:
	case TinyImageFormat_R8G8B8_SRGB:
	case TinyImageFormat_B8G8R8_UNORM:
	case TinyImageFormat_B8G8R8_SNORM:
	case TinyImageFormat_B8G8R8_USCALED:
	case TinyImageFormat_B8G8R8_SSCALED:
	case TinyImageFormat_B8G8R8_UINT:
	case TinyImageFormat_B8G8R8_SINT:
	case TinyImageFormat_B8G8R8_SRGB:
	case TinyImageFormat_D16_UNORM_S8_UINT:return 24;

	case TinyImageFormat_R4G4B4A4_UNORM_PACK16:
	case TinyImageFormat_B4G4R4A4_UNORM_PACK16:
	case TinyImageFormat_R5G6B5_UNORM_PACK16:
	case TinyImageFormat_B5G6R5_UNORM_PACK16:
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16:
	case TinyImageFormat_B5G5R5A1_UNORM_PACK16:
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16:
	case TinyImageFormat_R8G8_UNORM:
	case TinyImageFormat_R8G8_SNORM:
	case TinyImageFormat_R8G8_USCALED:
	case TinyImageFormat_R8G8_SSCALED:
	case TinyImageFormat_R8G8_UINT:
	case TinyImageFormat_R8G8_SINT:
	case TinyImageFormat_R8G8_SRGB:
	case TinyImageFormat_R16_UNORM:
	case TinyImageFormat_R16_SNORM:
	case TinyImageFormat_R16_USCALED:
	case TinyImageFormat_R16_SSCALED:
	case TinyImageFormat_R16_UINT:
	case TinyImageFormat_R16_SINT:
	case TinyImageFormat_R16_SFLOAT:
	case TinyImageFormat_D16_UNORM:
	case TinyImageFormat_A4R4G4B4_UNORM_PACK16: return 16;

	case TinyImageFormat_R4G4_UNORM_PACK8:
	case TinyImageFormat_R8_UNORM:
	case TinyImageFormat_R8_SNORM:
	case TinyImageFormat_R8_USCALED:
	case TinyImageFormat_R8_SSCALED:
	case TinyImageFormat_R8_UINT:
	case TinyImageFormat_R8_SINT:
	case TinyImageFormat_R8_SRGB:
	case TinyImageFormat_S8_UINT:
	case TinyImageFormat_A8_UNORM:
		return 8;

	case TinyImageFormat_UNDEFINED: return 0;

	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK:
		return TinyImageFormat_BitSizeOfBlock(fmt);
	}
	LOGERRORF("bitWidth: %s not handled",	TinyImageFormat_Name(fmt));
	return 0;
}

AL2O3_EXTERN_C inline double TinyImageFormat_Max(enum TinyImageFormat const fmt, int channel) {
	switch (fmt) {
	case TinyImageFormat_R16G16B16A16_UNORM:
	case TinyImageFormat_R16G16B16_UNORM:
	case TinyImageFormat_R16G16_UNORM:
	case TinyImageFormat_R16_UNORM:
	case TinyImageFormat_D16_UNORM:
	case TinyImageFormat_R16G16B16A16_SNORM:
	case TinyImageFormat_R16G16B16_SNORM:
	case TinyImageFormat_R16G16_SNORM:
	case TinyImageFormat_R16_SNORM:
	case TinyImageFormat_R8G8B8A8_UNORM:
	case TinyImageFormat_B8G8R8A8_UNORM:
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32:
	case TinyImageFormat_R8G8B8_UNORM:
	case TinyImageFormat_B8G8R8_UNORM:
	case TinyImageFormat_R8G8_UNORM:
	case TinyImageFormat_R8_UNORM:
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32:
	case TinyImageFormat_R8G8B8A8_SRGB:
	case TinyImageFormat_B8G8R8A8_SRGB:
	case TinyImageFormat_B8G8R8_SRGB:
	case TinyImageFormat_R8G8B8_SRGB:
	case TinyImageFormat_R8G8_SRGB:
	case TinyImageFormat_R8_SRGB:
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32:
	case TinyImageFormat_R8G8B8A8_SNORM:
	case TinyImageFormat_B8G8R8A8_SNORM:
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:
	case TinyImageFormat_R8G8B8_SNORM:
	case TinyImageFormat_B8G8R8_SNORM:
	case TinyImageFormat_R8G8_SNORM:
	case TinyImageFormat_R8_SNORM:
	case TinyImageFormat_A2R10G10B10_UNORM_PACK32:
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32:
	case TinyImageFormat_R4G4B4A4_UNORM_PACK16:
	case TinyImageFormat_B4G4R4A4_UNORM_PACK16:
	case TinyImageFormat_R4G4_UNORM_PACK8:
	case TinyImageFormat_A4R4G4B4_UNORM_PACK16:
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_R5G6B5_UNORM_PACK16:
	case TinyImageFormat_B5G6R5_UNORM_PACK16:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16:
	case TinyImageFormat_B5G5R5A1_UNORM_PACK16:
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK:
	case TinyImageFormat_A8_UNORM:
		return 1.0;

	case TinyImageFormat_R64G64B64A64_UINT:
	case TinyImageFormat_R64G64B64_UINT:
	case TinyImageFormat_R64G64_UINT:
	case TinyImageFormat_R64_UINT:return (double) UINT64_MAX;

	case TinyImageFormat_R64G64B64A64_SINT:
	case TinyImageFormat_R64G64B64_SINT:
	case TinyImageFormat_R64G64_SINT:
	case TinyImageFormat_R64_SINT:return (double) INT64_MAX;

	case TinyImageFormat_R64G64B64_SFLOAT:
	case TinyImageFormat_R64G64B64A64_SFLOAT:
	case TinyImageFormat_R64G64_SFLOAT:
	case TinyImageFormat_R64_SFLOAT:return DBL_MAX;

	case TinyImageFormat_R32G32B32A32_UINT:
	case TinyImageFormat_R32G32B32_UINT:
	case TinyImageFormat_R32G32_UINT:
	case TinyImageFormat_R32_UINT:return UINT32_MAX;

	case TinyImageFormat_R32G32B32A32_SINT:
	case TinyImageFormat_R32G32B32_SINT:
	case TinyImageFormat_R32G32_SINT:
	case TinyImageFormat_R32_SINT:return INT32_MAX;

	case TinyImageFormat_R32G32B32A32_SFLOAT:
	case TinyImageFormat_R32G32B32_SFLOAT:
	case TinyImageFormat_R32G32_SFLOAT:
	case TinyImageFormat_R32_SFLOAT:
	case TinyImageFormat_D32_SFLOAT:return FLT_MAX;

	case TinyImageFormat_R16G16B16A16_USCALED:
	case TinyImageFormat_R16G16B16_USCALED:
	case TinyImageFormat_R16G16_USCALED:
	case TinyImageFormat_R16_USCALED:
	case TinyImageFormat_R16G16B16A16_UINT:
	case TinyImageFormat_R16G16B16_UINT:
	case TinyImageFormat_R16G16_UINT:
	case TinyImageFormat_R16_UINT:return UINT16_MAX;

	case TinyImageFormat_R16G16B16A16_SSCALED:
	case TinyImageFormat_R16G16B16_SSCALED:
	case TinyImageFormat_R16G16_SSCALED:
	case TinyImageFormat_R16_SSCALED:
	case TinyImageFormat_R16G16B16A16_SINT:
	case TinyImageFormat_R16G16B16_SINT:
	case TinyImageFormat_R16G16_SINT:
	case TinyImageFormat_R16_SINT:return INT16_MAX;

	case TinyImageFormat_R16G16B16A16_SFLOAT:
	case TinyImageFormat_R16G16B16_SFLOAT:
	case TinyImageFormat_R16G16_SFLOAT:
	case TinyImageFormat_R16_SFLOAT:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:return 0x1.ffcp15;

	case TinyImageFormat_D32_SFLOAT_S8_UINT:
		if (channel == 0) {
			return FLT_MAX;
		} else {
			return UINT8_MAX;
		}

	case TinyImageFormat_R8G8B8A8_USCALED:
	case TinyImageFormat_B8G8R8A8_USCALED:
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32:
	case TinyImageFormat_R8G8B8_USCALED:
	case TinyImageFormat_B8G8R8_USCALED:
	case TinyImageFormat_R8G8_USCALED:
	case TinyImageFormat_R8_USCALED:
	case TinyImageFormat_R8G8B8A8_UINT:
	case TinyImageFormat_B8G8R8A8_UINT:
	case TinyImageFormat_A8B8G8R8_UINT_PACK32:
	case TinyImageFormat_R8G8B8_UINT:
	case TinyImageFormat_B8G8R8_UINT:
	case TinyImageFormat_R8G8_UINT:
	case TinyImageFormat_R8_UINT:
	case TinyImageFormat_S8_UINT:
		 return UINT8_MAX;

	case TinyImageFormat_R8G8B8A8_SSCALED:
	case TinyImageFormat_B8G8R8A8_SSCALED:
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32:
	case TinyImageFormat_R8G8B8_SSCALED:
	case TinyImageFormat_B8G8R8_SSCALED:
	case TinyImageFormat_R8G8_SSCALED:
	case TinyImageFormat_R8_SSCALED:
	case TinyImageFormat_R8G8B8A8_SINT:
	case TinyImageFormat_B8G8R8A8_SINT:
	case TinyImageFormat_A8B8G8R8_SINT_PACK32:
	case TinyImageFormat_R8G8B8_SINT:
	case TinyImageFormat_B8G8R8_SINT:
	case TinyImageFormat_R8G8_SINT:
	case TinyImageFormat_R8_SINT:return INT8_MAX;

	case TinyImageFormat_A2R10G10B10_USCALED_PACK32:
	case TinyImageFormat_A2R10G10B10_UINT_PACK32:
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32:
	case TinyImageFormat_A2B10G10R10_UINT_PACK32:
		if (channel == 0) {
			return 3.0;
		} else {
			return 1023.0;
		}

	case TinyImageFormat_X8_D24_UNORM_PACK32:
		if (channel == 0) {
			return 255.0;
		} else {
			return 1.0;
		};
	case TinyImageFormat_D24_UNORM_S8_UINT:
		if (channel == 0) {
			return 1.0;
		} else {
			return 255.0;
		}
	case TinyImageFormat_D16_UNORM_S8_UINT:
		if (channel == 0) {
			return 1.0;
		} else {
			return 255.0;
		}
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32: return 65000.0;
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32: return 65472.0;

	case TinyImageFormat_UNDEFINED:
		return 0.0;
	}
	LOGWARNINGF("max %s not handled", TinyImageFormat_Name(fmt));
	return 0.0;
}

AL2O3_EXTERN_C inline double TinyImageFormat_Min(enum TinyImageFormat const fmt, int channel) {
	switch (fmt) {
	case TinyImageFormat_R64G64B64A64_UINT:
	case TinyImageFormat_R64G64B64_UINT:
	case TinyImageFormat_R64G64_UINT:
	case TinyImageFormat_R64_UINT:
	case TinyImageFormat_R16G16B16A16_UNORM:
	case TinyImageFormat_R16G16B16_UNORM:
	case TinyImageFormat_R16G16_UNORM:
	case TinyImageFormat_R16_UNORM:
	case TinyImageFormat_D16_UNORM:
	case TinyImageFormat_R16G16B16A16_USCALED:
	case TinyImageFormat_R16G16B16_USCALED:
	case TinyImageFormat_R16G16_USCALED:
	case TinyImageFormat_R16_USCALED:
	case TinyImageFormat_R16G16B16A16_UINT:
	case TinyImageFormat_R16G16B16_UINT:
	case TinyImageFormat_R16G16_UINT:
	case TinyImageFormat_R16_UINT:
	case TinyImageFormat_R8G8B8A8_USCALED:
	case TinyImageFormat_B8G8R8A8_USCALED:
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32:
	case TinyImageFormat_R8G8B8_USCALED:
	case TinyImageFormat_B8G8R8_USCALED:
	case TinyImageFormat_R8G8_USCALED:
	case TinyImageFormat_R8_USCALED:
	case TinyImageFormat_R8G8B8A8_UINT:
	case TinyImageFormat_B8G8R8A8_UINT:
	case TinyImageFormat_A8B8G8R8_UINT_PACK32:
	case TinyImageFormat_R8G8B8_UINT:
	case TinyImageFormat_B8G8R8_UINT:
	case TinyImageFormat_R8G8_UINT:
	case TinyImageFormat_R8_UINT:
	case TinyImageFormat_S8_UINT:
	case TinyImageFormat_R8G8B8A8_UNORM:
	case TinyImageFormat_B8G8R8A8_UNORM:
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32:
	case TinyImageFormat_R8G8B8_UNORM:
	case TinyImageFormat_B8G8R8_UNORM:
	case TinyImageFormat_R8G8_UNORM:
	case TinyImageFormat_R8_UNORM:
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32:
	case TinyImageFormat_R8G8B8A8_SRGB:
	case TinyImageFormat_B8G8R8A8_SRGB:
	case TinyImageFormat_B8G8R8_SRGB:
	case TinyImageFormat_R8G8B8_SRGB:
	case TinyImageFormat_R8G8_SRGB:
	case TinyImageFormat_R8_SRGB:
	case TinyImageFormat_A2R10G10B10_UNORM_PACK32:
	case TinyImageFormat_A2R10G10B10_USCALED_PACK32:
	case TinyImageFormat_A2R10G10B10_UINT_PACK32:
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32:
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32:
	case TinyImageFormat_A2B10G10R10_UINT_PACK32:
	case TinyImageFormat_X8_D24_UNORM_PACK32:
	case TinyImageFormat_D24_UNORM_S8_UINT:
	case TinyImageFormat_D16_UNORM_S8_UINT:
	case TinyImageFormat_R4G4B4A4_UNORM_PACK16:
	case TinyImageFormat_B4G4R4A4_UNORM_PACK16:
	case TinyImageFormat_R4G4_UNORM_PACK8:
	case TinyImageFormat_A4R4G4B4_UNORM_PACK16:
	case TinyImageFormat_R32G32B32A32_UINT:
	case TinyImageFormat_R32G32B32_UINT:
	case TinyImageFormat_R32G32_UINT:
	case TinyImageFormat_R32_UINT:
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_R5G6B5_UNORM_PACK16:
	case TinyImageFormat_B5G6R5_UNORM_PACK16:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16:
	case TinyImageFormat_B5G5R5A1_UNORM_PACK16:
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32:
	case TinyImageFormat_A8_UNORM:
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK:
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32:
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32:
		return 0.0;

	case TinyImageFormat_R64G64B64A64_SINT:
	case TinyImageFormat_R64G64B64_SINT:
	case TinyImageFormat_R64G64_SINT:
	case TinyImageFormat_R64_SINT:return INT64_MIN;

	case TinyImageFormat_R64G64B64_SFLOAT:
	case TinyImageFormat_R64G64B64A64_SFLOAT:
	case TinyImageFormat_R64G64_SFLOAT:
	case TinyImageFormat_R64_SFLOAT:return DBL_MIN;

	case TinyImageFormat_R32G32B32A32_SINT:
	case TinyImageFormat_R32G32B32_SINT:
	case TinyImageFormat_R32G32_SINT:
	case TinyImageFormat_R32_SINT:return INT32_MIN;

	case TinyImageFormat_R32G32B32A32_SFLOAT:
	case TinyImageFormat_R32G32B32_SFLOAT:
	case TinyImageFormat_R32G32_SFLOAT:
	case TinyImageFormat_R32_SFLOAT:
	case TinyImageFormat_D32_SFLOAT:return FLT_MIN;

	case TinyImageFormat_R16G16B16A16_SSCALED:
	case TinyImageFormat_R16G16B16_SSCALED:
	case TinyImageFormat_R16G16_SSCALED:
	case TinyImageFormat_R16_SSCALED:
	case TinyImageFormat_R16G16B16A16_SINT:
	case TinyImageFormat_R16G16B16_SINT:
	case TinyImageFormat_R16G16_SINT:
	case TinyImageFormat_R16_SINT:return INT16_MIN;

	case TinyImageFormat_R16G16B16A16_SFLOAT:
	case TinyImageFormat_R16G16B16_SFLOAT:
	case TinyImageFormat_R16G16_SFLOAT:
	case TinyImageFormat_R16_SFLOAT:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK: return 0x1.0p-14;

	case TinyImageFormat_D32_SFLOAT_S8_UINT:
		if (channel == 0) {
			return FLT_MIN;
		} else {
			return 0;
		}

	case TinyImageFormat_R16G16B16A16_SNORM:
	case TinyImageFormat_R16G16B16_SNORM:
	case TinyImageFormat_R16G16_SNORM:
	case TinyImageFormat_R16_SNORM:
	case TinyImageFormat_R8G8B8A8_SNORM:
	case TinyImageFormat_B8G8R8A8_SNORM:
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:
	case TinyImageFormat_R8G8B8_SNORM:
	case TinyImageFormat_B8G8R8_SNORM:
	case TinyImageFormat_R8G8_SNORM:
	case TinyImageFormat_R8_SNORM:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK: return -1.0;


	case TinyImageFormat_R8G8B8A8_SSCALED:
	case TinyImageFormat_B8G8R8A8_SSCALED:
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32:
	case TinyImageFormat_R8G8B8_SSCALED:
	case TinyImageFormat_B8G8R8_SSCALED:
	case TinyImageFormat_R8G8_SSCALED:
	case TinyImageFormat_R8_SSCALED:
	case TinyImageFormat_R8G8B8A8_SINT:
	case TinyImageFormat_B8G8R8A8_SINT:
	case TinyImageFormat_A8B8G8R8_SINT_PACK32:
	case TinyImageFormat_R8G8B8_SINT:
	case TinyImageFormat_B8G8R8_SINT:
	case TinyImageFormat_R8G8_SINT:
	case TinyImageFormat_R8_SINT:return INT8_MIN;

	case TinyImageFormat_UNDEFINED: return 0.0;

	}
	LOGWARNINGF("min %s not handled", TinyImageFormat_Name(fmt));
	return 0.0;
}
// the channels the same? Compressed are treated as true as
// each block are basically the same (BC6H and BC7 are ignored)
AL2O3_EXTERN_C inline bool TinyImageFormat_IsHomogenous(TinyImageFormat const fmt) {
	switch (fmt) {
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16:
	case TinyImageFormat_B5G5R5A1_UNORM_PACK16:
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16:
	case TinyImageFormat_A2R10G10B10_UNORM_PACK32:
	case TinyImageFormat_A2R10G10B10_USCALED_PACK32:
	case TinyImageFormat_A2R10G10B10_UINT_PACK32:
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32:
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32:
	case TinyImageFormat_A2B10G10R10_UINT_PACK32:
	case TinyImageFormat_X8_D24_UNORM_PACK32:
	case TinyImageFormat_D32_SFLOAT_S8_UINT:
	case TinyImageFormat_R5G6B5_UNORM_PACK16:
	case TinyImageFormat_B5G6R5_UNORM_PACK16:
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32:
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_D16_UNORM_S8_UINT:
	case TinyImageFormat_D24_UNORM_S8_UINT:
		return false;
	case TinyImageFormat_UNDEFINED:
	case TinyImageFormat_R4G4_UNORM_PACK8:
	case TinyImageFormat_R4G4B4A4_UNORM_PACK16:
	case TinyImageFormat_B4G4R4A4_UNORM_PACK16:
	case TinyImageFormat_R8_UNORM:
	case TinyImageFormat_R8_SNORM:
	case TinyImageFormat_R8_USCALED:
	case TinyImageFormat_R8_SSCALED:
	case TinyImageFormat_R8_UINT:
	case TinyImageFormat_R8_SINT:
	case TinyImageFormat_R8_SRGB:
	case TinyImageFormat_R8G8_UNORM:
	case TinyImageFormat_R8G8_SNORM:
	case TinyImageFormat_R8G8_USCALED:
	case TinyImageFormat_R8G8_SSCALED:
	case TinyImageFormat_R8G8_UINT:
	case TinyImageFormat_R8G8_SINT:
	case TinyImageFormat_R8G8_SRGB:
	case TinyImageFormat_R8G8B8_UNORM:
	case TinyImageFormat_R8G8B8_SNORM:
	case TinyImageFormat_R8G8B8_USCALED:
	case TinyImageFormat_R8G8B8_SSCALED:
	case TinyImageFormat_R8G8B8_UINT:
	case TinyImageFormat_R8G8B8_SINT:
	case TinyImageFormat_R8G8B8_SRGB:
	case TinyImageFormat_B8G8R8_UNORM:
	case TinyImageFormat_B8G8R8_SNORM:
	case TinyImageFormat_B8G8R8_USCALED:
	case TinyImageFormat_B8G8R8_SSCALED:
	case TinyImageFormat_B8G8R8_UINT:
	case TinyImageFormat_B8G8R8_SINT:
	case TinyImageFormat_B8G8R8_SRGB:
	case TinyImageFormat_R8G8B8A8_UNORM:
	case TinyImageFormat_R8G8B8A8_SNORM:
	case TinyImageFormat_R8G8B8A8_USCALED:
	case TinyImageFormat_R8G8B8A8_SSCALED:
	case TinyImageFormat_R8G8B8A8_UINT:
	case TinyImageFormat_R8G8B8A8_SINT:
	case TinyImageFormat_R8G8B8A8_SRGB:
	case TinyImageFormat_B8G8R8A8_UNORM:
	case TinyImageFormat_B8G8R8A8_SNORM:
	case TinyImageFormat_B8G8R8A8_USCALED:
	case TinyImageFormat_B8G8R8A8_SSCALED:
	case TinyImageFormat_B8G8R8A8_UINT:
	case TinyImageFormat_B8G8R8A8_SINT:
	case TinyImageFormat_B8G8R8A8_SRGB:
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_UINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32:
	case TinyImageFormat_R16_UNORM:
	case TinyImageFormat_R16_SNORM:
	case TinyImageFormat_R16_USCALED:
	case TinyImageFormat_R16_SSCALED:
	case TinyImageFormat_R16_UINT:
	case TinyImageFormat_R16_SINT:
	case TinyImageFormat_R16_SFLOAT:
	case TinyImageFormat_R16G16_UNORM:
	case TinyImageFormat_R16G16_SNORM:
	case TinyImageFormat_R16G16_USCALED:
	case TinyImageFormat_R16G16_SSCALED:
	case TinyImageFormat_R16G16_UINT:
	case TinyImageFormat_R16G16_SINT:
	case TinyImageFormat_R16G16_SFLOAT:
	case TinyImageFormat_R16G16B16_UNORM:
	case TinyImageFormat_R16G16B16_SNORM:
	case TinyImageFormat_R16G16B16_USCALED:
	case TinyImageFormat_R16G16B16_SSCALED:
	case TinyImageFormat_R16G16B16_UINT:
	case TinyImageFormat_R16G16B16_SINT:
	case TinyImageFormat_R16G16B16_SFLOAT:
	case TinyImageFormat_R16G16B16A16_UNORM:
	case TinyImageFormat_R16G16B16A16_SNORM:
	case TinyImageFormat_R16G16B16A16_USCALED:
	case TinyImageFormat_R16G16B16A16_SSCALED:
	case TinyImageFormat_R16G16B16A16_UINT:
	case TinyImageFormat_R16G16B16A16_SINT:
	case TinyImageFormat_R16G16B16A16_SFLOAT:
	case TinyImageFormat_R32_UINT:
	case TinyImageFormat_R32_SINT:
	case TinyImageFormat_R32_SFLOAT:
	case TinyImageFormat_R32G32_UINT:
	case TinyImageFormat_R32G32_SINT:
	case TinyImageFormat_R32G32_SFLOAT:
	case TinyImageFormat_R32G32B32_UINT:
	case TinyImageFormat_R32G32B32_SINT:
	case TinyImageFormat_R32G32B32_SFLOAT:
	case TinyImageFormat_R32G32B32A32_UINT:
	case TinyImageFormat_R32G32B32A32_SINT:
	case TinyImageFormat_R32G32B32A32_SFLOAT:
	case TinyImageFormat_R64_UINT:
	case TinyImageFormat_R64_SINT:
	case TinyImageFormat_R64_SFLOAT:
	case TinyImageFormat_R64G64_UINT:
	case TinyImageFormat_R64G64_SINT:
	case TinyImageFormat_R64G64_SFLOAT:
	case TinyImageFormat_R64G64B64_UINT:
	case TinyImageFormat_R64G64B64_SINT:
	case TinyImageFormat_R64G64B64_SFLOAT:
	case TinyImageFormat_R64G64B64A64_UINT:
	case TinyImageFormat_R64G64B64A64_SINT:
	case TinyImageFormat_R64G64B64A64_SFLOAT:
	case TinyImageFormat_D16_UNORM:
	case TinyImageFormat_D32_SFLOAT:
	case TinyImageFormat_S8_UINT:
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK:
	case TinyImageFormat_A4R4G4B4_UNORM_PACK16:
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32:
	case TinyImageFormat_A8_UNORM:
		return true;
	}
	LOGWARNINGF("IsHomogenous %s not handled", TinyImageFormat_Name(fmt));

	return true;
}

AL2O3_EXTERN_C inline bool TinyImageFormat_IsPVR(TinyImageFormat fmt) {
	switch (fmt) {
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:return true;
	default: return false;
	}
}
// swizzle map non RGBA formats to RGBA, positive (and zero) values are the channel
// negative values are constant for that channel,
// the constant value to use is defined as -1 -> 0, -2 -> 1
// Image_Swizzle is simple an 4 tuple with one of
// R=0, G=1, B=2, A=3, constant 0=-1, constant 1=-2
// common swizzles are predefined
typedef int8_t *Image_Swizzle;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_RGBA;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_ARGB;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_BGRA;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_ABGR;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_000A;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_R001;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_RG01;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_RGB1;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_BGR1;

AL2O3_EXTERN_C inline Image_Swizzle TinyImageFormat_Swizzle(TinyImageFormat fmt_) {
	switch (fmt_) {
	case TinyImageFormat_UNDEFINED:

	case TinyImageFormat_R64G64B64A64_UINT:
	case TinyImageFormat_R64G64B64A64_SINT:
	case TinyImageFormat_R64G64B64A64_SFLOAT:
	case TinyImageFormat_R32G32B32A32_UINT:
	case TinyImageFormat_R32G32B32A32_SINT:
	case TinyImageFormat_R32G32B32A32_SFLOAT:
	case TinyImageFormat_R16G16B16A16_USCALED:
	case TinyImageFormat_R16G16B16A16_UINT:
	case TinyImageFormat_R4G4B4A4_UNORM_PACK16:
	case TinyImageFormat_R16G16B16A16_UNORM:
	case TinyImageFormat_R16G16B16A16_SNORM:
	case TinyImageFormat_R16G16B16A16_SSCALED:
	case TinyImageFormat_R16G16B16A16_SINT:
	case TinyImageFormat_R16G16B16A16_SFLOAT:
	case TinyImageFormat_R8G8B8A8_UNORM:
	case TinyImageFormat_R8G8B8A8_USCALED:
	case TinyImageFormat_R8G8B8A8_UINT:
	case TinyImageFormat_R8G8B8A8_SRGB:
	case TinyImageFormat_R8G8B8A8_SNORM:
	case TinyImageFormat_R8G8B8A8_SSCALED:
	case TinyImageFormat_R8G8B8A8_SINT:
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16:
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:
	case TinyImageFormat_BC2_UNORM_BLOCK:
	case TinyImageFormat_BC2_SRGB_BLOCK:
	case TinyImageFormat_BC3_UNORM_BLOCK:
	case TinyImageFormat_BC3_SRGB_BLOCK:
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:
	case TinyImageFormat_BC7_UNORM_BLOCK:
	case TinyImageFormat_BC7_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK:
		return TinyImageFormat_Swizzle_RGBA;

	case TinyImageFormat_A2R10G10B10_UNORM_PACK32:
	case TinyImageFormat_A2R10G10B10_USCALED_PACK32:
	case TinyImageFormat_A2R10G10B10_UINT_PACK32:
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16:
	case TinyImageFormat_A4R4G4B4_UNORM_PACK16:
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32:
		return TinyImageFormat_Swizzle_ARGB;

	case TinyImageFormat_A2B10G10R10_UNORM_PACK32:
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32:
	case TinyImageFormat_A2B10G10R10_UINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32:
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_UINT_PACK32:
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32:
	case TinyImageFormat_A8B8G8R8_SINT_PACK32:
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32:
		return TinyImageFormat_Swizzle_ABGR;

	case TinyImageFormat_B8G8R8A8_UNORM:
	case TinyImageFormat_B8G8R8A8_USCALED:
	case TinyImageFormat_B8G8R8A8_UINT:
	case TinyImageFormat_B8G8R8A8_SRGB:
	case TinyImageFormat_B8G8R8A8_SNORM:
	case TinyImageFormat_B8G8R8A8_SSCALED:
	case TinyImageFormat_B8G8R8A8_SINT:
	case TinyImageFormat_B4G4R4A4_UNORM_PACK16:
	case TinyImageFormat_B5G5R5A1_UNORM_PACK16:
		return TinyImageFormat_Swizzle_BGRA;

		// TODO check PVR swizzle order!
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:
		return TinyImageFormat_Swizzle_RGB1;
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:
		return TinyImageFormat_Swizzle_RGBA;

	case TinyImageFormat_R64G64B64_UINT:
	case TinyImageFormat_R64G64B64_SINT:
	case TinyImageFormat_R64G64B64_SFLOAT:
	case TinyImageFormat_R32G32B32_UINT:
	case TinyImageFormat_R32G32B32_SINT:
	case TinyImageFormat_R32G32B32_SFLOAT:
	case TinyImageFormat_R16G16B16_UNORM:
	case TinyImageFormat_R16G16B16_USCALED:
	case TinyImageFormat_R16G16B16_UINT:
	case TinyImageFormat_R16G16B16_SNORM:
	case TinyImageFormat_R16G16B16_SSCALED:
	case TinyImageFormat_R16G16B16_SINT:
	case TinyImageFormat_R16G16B16_SFLOAT:
	case TinyImageFormat_R8G8B8_USCALED:
	case TinyImageFormat_R8G8B8_UNORM:
	case TinyImageFormat_R8G8B8_UINT:
	case TinyImageFormat_R8G8B8_SRGB:
	case TinyImageFormat_R8G8B8_SNORM:
	case TinyImageFormat_R8G8B8_SINT:
	case TinyImageFormat_R8G8B8_SSCALED:
	case TinyImageFormat_R5G6B5_UNORM_PACK16:
	case TinyImageFormat_B5G6R5_UNORM_PACK16:
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
		return TinyImageFormat_Swizzle_RGB1;

	case TinyImageFormat_B8G8R8_SNORM:
	case TinyImageFormat_B8G8R8_UNORM:
	case TinyImageFormat_B8G8R8_USCALED:
	case TinyImageFormat_B8G8R8_UINT:
	case TinyImageFormat_B8G8R8_SSCALED:
	case TinyImageFormat_B8G8R8_SINT:
	case TinyImageFormat_B8G8R8_SRGB:
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32:
		return TinyImageFormat_Swizzle_BGR1;


	case TinyImageFormat_R64G64_UINT:
	case TinyImageFormat_R64G64_SINT:
	case TinyImageFormat_R64G64_SFLOAT:
	case TinyImageFormat_R32G32_UINT:
	case TinyImageFormat_R32G32_SINT:
	case TinyImageFormat_R32G32_SFLOAT:
	case TinyImageFormat_R16G16_UNORM:
	case TinyImageFormat_R16G16_USCALED:
	case TinyImageFormat_R16G16_UINT:
	case TinyImageFormat_R16G16_SSCALED:
	case TinyImageFormat_R16G16_SNORM:
	case TinyImageFormat_R16G16_SINT:
	case TinyImageFormat_R16G16_SFLOAT:
	case TinyImageFormat_D32_SFLOAT_S8_UINT:
	case TinyImageFormat_R8G8_UNORM:
	case TinyImageFormat_R8G8_USCALED:
	case TinyImageFormat_R8G8_UINT:
	case TinyImageFormat_R8G8_SRGB:
	case TinyImageFormat_R8G8_SNORM:
	case TinyImageFormat_R8G8_SINT:
	case TinyImageFormat_R8G8_SSCALED:
	case TinyImageFormat_X8_D24_UNORM_PACK32:
	case TinyImageFormat_D24_UNORM_S8_UINT:
	case TinyImageFormat_D16_UNORM_S8_UINT:
	case TinyImageFormat_R4G4_UNORM_PACK8:
	case TinyImageFormat_BC5_UNORM_BLOCK:
	case TinyImageFormat_BC5_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:
		return TinyImageFormat_Swizzle_RG01;

	case TinyImageFormat_R64_UINT:
	case TinyImageFormat_R64_SINT:
	case TinyImageFormat_R64_SFLOAT:
	case TinyImageFormat_R32_UINT:
	case TinyImageFormat_R32_SINT:
	case TinyImageFormat_R32_SFLOAT:
	case TinyImageFormat_D32_SFLOAT:
	case TinyImageFormat_R16_UNORM:
	case TinyImageFormat_D16_UNORM:
	case TinyImageFormat_R16_USCALED:
	case TinyImageFormat_R16_UINT:
	case TinyImageFormat_R16_SNORM:
	case TinyImageFormat_R16_SSCALED:
	case TinyImageFormat_R16_SINT:
	case TinyImageFormat_R16_SFLOAT:
	case TinyImageFormat_R8_USCALED:
	case TinyImageFormat_R8_UNORM:
	case TinyImageFormat_R8_UINT:
	case TinyImageFormat_S8_UINT:
	case TinyImageFormat_R8_SRGB:
	case TinyImageFormat_R8_SNORM:
	case TinyImageFormat_R8_SSCALED:
	case TinyImageFormat_R8_SINT:
	case TinyImageFormat_BC4_UNORM_BLOCK:
	case TinyImageFormat_BC4_SNORM_BLOCK:
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:
		return TinyImageFormat_Swizzle_R001;
	case TinyImageFormat_A8_UNORM:
		return TinyImageFormat_Swizzle_000A;
	}

	LOGERRORF("swizzleFormat %s not handled", TinyImageFormat_Name(fmt_));
	return TinyImageFormat_Swizzle_RGBA;
}

#ifndef TINYIMAGEFORMAT_DXGIFORMAT
#define TINYIMAGEFORMAT_DXGIFORMAT

typedef enum x {
	TIF_DXGI_FORMAT_UNKNOWN = 0,
	TIF_DXGI_FORMAT_R32G32B32A32_TYPELESS,
	TIF_DXGI_FORMAT_R32G32B32A32_FLOAT,
	TIF_DXGI_FORMAT_R32G32B32A32_UINT,
	TIF_DXGI_FORMAT_R32G32B32A32_SINT,
	TIF_DXGI_FORMAT_R32G32B32_TYPELESS,
	TIF_DXGI_FORMAT_R32G32B32_FLOAT,
	TIF_DXGI_FORMAT_R32G32B32_UINT,
	TIF_DXGI_FORMAT_R32G32B32_SINT,
	TIF_DXGI_FORMAT_R16G16B16A16_TYPELESS,
	TIF_DXGI_FORMAT_R16G16B16A16_FLOAT,
	TIF_DXGI_FORMAT_R16G16B16A16_UNORM,
	TIF_DXGI_FORMAT_R16G16B16A16_UINT,
	TIF_DXGI_FORMAT_R16G16B16A16_SNORM,
	TIF_DXGI_FORMAT_R16G16B16A16_SINT,
	TIF_DXGI_FORMAT_R32G32_TYPELESS,
	TIF_DXGI_FORMAT_R32G32_FLOAT,
	TIF_DXGI_FORMAT_R32G32_UINT,
	TIF_DXGI_FORMAT_R32G32_SINT,
	TIF_DXGI_FORMAT_R32G8X24_TYPELESS,
	TIF_DXGI_FORMAT_D32_FLOAT_S8X24_UINT,
	TIF_DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS,
	TIF_DXGI_FORMAT_X32_TYPELESS_G8X24_UINT,
	TIF_DXGI_FORMAT_R10G10B10A2_TYPELESS,
	TIF_DXGI_FORMAT_R10G10B10A2_UNORM,
	TIF_DXGI_FORMAT_R10G10B10A2_UINT,
	TIF_DXGI_FORMAT_R11G11B10_FLOAT,
	TIF_DXGI_FORMAT_R8G8B8A8_TYPELESS,
	TIF_DXGI_FORMAT_R8G8B8A8_UNORM,
	TIF_DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
	TIF_DXGI_FORMAT_R8G8B8A8_UINT,
	TIF_DXGI_FORMAT_R8G8B8A8_SNORM,
	TIF_DXGI_FORMAT_R8G8B8A8_SINT,
	TIF_DXGI_FORMAT_R16G16_TYPELESS,
	TIF_DXGI_FORMAT_R16G16_FLOAT,
	TIF_DXGI_FORMAT_R16G16_UNORM,
	TIF_DXGI_FORMAT_R16G16_UINT,
	TIF_DXGI_FORMAT_R16G16_SNORM,
	TIF_DXGI_FORMAT_R16G16_SINT,
	TIF_DXGI_FORMAT_R32_TYPELESS,
	TIF_DXGI_FORMAT_D32_FLOAT,
	TIF_DXGI_FORMAT_R32_FLOAT,
	TIF_DXGI_FORMAT_R32_UINT,
	TIF_DXGI_FORMAT_R32_SINT,
	TIF_DXGI_FORMAT_R24G8_TYPELESS,
	TIF_DXGI_FORMAT_D24_UNORM_S8_UINT,
	TIF_DXGI_FORMAT_R24_UNORM_X8_TYPELESS,
	TIF_DXGI_FORMAT_X24_TYPELESS_G8_UINT,
	TIF_DXGI_FORMAT_R8G8_TYPELESS,
	TIF_DXGI_FORMAT_R8G8_UNORM,
	TIF_DXGI_FORMAT_R8G8_UINT,
	TIF_DXGI_FORMAT_R8G8_SNORM,
	TIF_DXGI_FORMAT_R8G8_SINT,
	TIF_DXGI_FORMAT_R16_TYPELESS,
	TIF_DXGI_FORMAT_R16_FLOAT,
	TIF_DXGI_FORMAT_D16_UNORM,
	TIF_DXGI_FORMAT_R16_UNORM,
	TIF_DXGI_FORMAT_R16_UINT,
	TIF_DXGI_FORMAT_R16_SNORM,
	TIF_DXGI_FORMAT_R16_SINT,
	TIF_DXGI_FORMAT_R8_TYPELESS,
	TIF_DXGI_FORMAT_R8_UNORM,
	TIF_DXGI_FORMAT_R8_UINT,
	TIF_DXGI_FORMAT_R8_SNORM,
	TIF_DXGI_FORMAT_R8_SINT,
	TIF_DXGI_FORMAT_A8_UNORM,
	TIF_DXGI_FORMAT_R1_UNORM,
	TIF_DXGI_FORMAT_R9G9B9E5_SHAREDEXP,
	TIF_DXGI_FORMAT_R8G8_B8G8_UNORM,
	TIF_DXGI_FORMAT_G8R8_G8B8_UNORM,
	TIF_DXGI_FORMAT_BC1_TYPELESS,
	TIF_DXGI_FORMAT_BC1_UNORM,
	TIF_DXGI_FORMAT_BC1_UNORM_SRGB,
	TIF_DXGI_FORMAT_BC2_TYPELESS,
	TIF_DXGI_FORMAT_BC2_UNORM,
	TIF_DXGI_FORMAT_BC2_UNORM_SRGB,
	TIF_DXGI_FORMAT_BC3_TYPELESS,
	TIF_DXGI_FORMAT_BC3_UNORM,
	TIF_DXGI_FORMAT_BC3_UNORM_SRGB,
	TIF_DXGI_FORMAT_BC4_TYPELESS,
	TIF_DXGI_FORMAT_BC4_UNORM,
	TIF_DXGI_FORMAT_BC4_SNORM,
	TIF_DXGI_FORMAT_BC5_TYPELESS,
	TIF_DXGI_FORMAT_BC5_UNORM,
	TIF_DXGI_FORMAT_BC5_SNORM,
	TIF_DXGI_FORMAT_B5G6R5_UNORM,
	TIF_DXGI_FORMAT_B5G5R5A1_UNORM,
	TIF_DXGI_FORMAT_B8G8R8A8_UNORM,
	TIF_DXGI_FORMAT_B8G8R8X8_UNORM,
	TIF_DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM,
	TIF_DXGI_FORMAT_B8G8R8A8_TYPELESS,
	TIF_DXGI_FORMAT_B8G8R8A8_UNORM_SRGB,
	TIF_DXGI_FORMAT_B8G8R8X8_TYPELESS,
	TIF_DXGI_FORMAT_B8G8R8X8_UNORM_SRGB,
	TIF_DXGI_FORMAT_BC6H_TYPELESS,
	TIF_DXGI_FORMAT_BC6H_UF16,
	TIF_DXGI_FORMAT_BC6H_SF16,
	TIF_DXGI_FORMAT_BC7_TYPELESS,
	TIF_DXGI_FORMAT_BC7_UNORM,
	TIF_DXGI_FORMAT_BC7_UNORM_SRGB,
	TIF_DXGI_FORMAT_AYUV,
	TIF_DXGI_FORMAT_Y410,
	TIF_DXGI_FORMAT_Y416,
	TIF_DXGI_FORMAT_NV12,
	TIF_DXGI_FORMAT_P010,
	TIF_DXGI_FORMAT_P016,
	TIF_DXGI_FORMAT_420_OPAQUE,
	TIF_DXGI_FORMAT_YUY2,
	TIF_DXGI_FORMAT_Y210,
	TIF_DXGI_FORMAT_Y216,
	TIF_DXGI_FORMAT_NV11,
	TIF_DXGI_FORMAT_AI44,
	TIF_DXGI_FORMAT_IA44,
	TIF_DXGI_FORMAT_P8,
	TIF_DXGI_FORMAT_A8P8,
	TIF_DXGI_FORMAT_B4G4R4A4_UNORM,
	TIF_DXGI_FORMAT_P208,
	TIF_DXGI_FORMAT_V208,
	TIF_DXGI_FORMAT_V408,
	TIF_DXGI_FORMAT_FORCE_UINT
} TinyImageFormat_DXGI_FORMAT;
#endif

#ifndef TINYIMAGEFORMAT_VKFORMAT
#define TINYIMAGEFORMAT_VKFORMAT
typedef enum TinyImageFormat_VkFormat {
	TIF_VK_FORMAT_UNDEFINED = 0,
	TIF_VK_FORMAT_R4G4_UNORM_PACK8 = 1,
	TIF_VK_FORMAT_R4G4B4A4_UNORM_PACK16 = 2,
	TIF_VK_FORMAT_B4G4R4A4_UNORM_PACK16 = 3,
	TIF_VK_FORMAT_R5G6B5_UNORM_PACK16 = 4,
	TIF_VK_FORMAT_B5G6R5_UNORM_PACK16 = 5,
	TIF_VK_FORMAT_R5G5B5A1_UNORM_PACK16 = 6,
	TIF_VK_FORMAT_B5G5R5A1_UNORM_PACK16 = 7,
	TIF_VK_FORMAT_A1R5G5B5_UNORM_PACK16 = 8,
	TIF_VK_FORMAT_R8_UNORM = 9,
	TIF_VK_FORMAT_R8_SNORM = 10,
	TIF_VK_FORMAT_R8_USCALED = 11,
	TIF_VK_FORMAT_R8_SSCALED = 12,
	TIF_VK_FORMAT_R8_UINT = 13,
	TIF_VK_FORMAT_R8_SINT = 14,
	TIF_VK_FORMAT_R8_SRGB = 15,
	TIF_VK_FORMAT_R8G8_UNORM = 16,
	TIF_VK_FORMAT_R8G8_SNORM = 17,
	TIF_VK_FORMAT_R8G8_USCALED = 18,
	TIF_VK_FORMAT_R8G8_SSCALED = 19,
	TIF_VK_FORMAT_R8G8_UINT = 20,
	TIF_VK_FORMAT_R8G8_SINT = 21,
	TIF_VK_FORMAT_R8G8_SRGB = 22,
	TIF_VK_FORMAT_R8G8B8_UNORM = 23,
	TIF_VK_FORMAT_R8G8B8_SNORM = 24,
	TIF_VK_FORMAT_R8G8B8_USCALED = 25,
	TIF_VK_FORMAT_R8G8B8_SSCALED = 26,
	TIF_VK_FORMAT_R8G8B8_UINT = 27,
	TIF_VK_FORMAT_R8G8B8_SINT = 28,
	TIF_VK_FORMAT_R8G8B8_SRGB = 29,
	TIF_VK_FORMAT_B8G8R8_UNORM = 30,
	TIF_VK_FORMAT_B8G8R8_SNORM = 31,
	TIF_VK_FORMAT_B8G8R8_USCALED = 32,
	TIF_VK_FORMAT_B8G8R8_SSCALED = 33,
	TIF_VK_FORMAT_B8G8R8_UINT = 34,
	TIF_VK_FORMAT_B8G8R8_SINT = 35,
	TIF_VK_FORMAT_B8G8R8_SRGB = 36,
	TIF_VK_FORMAT_R8G8B8A8_UNORM = 37,
	TIF_VK_FORMAT_R8G8B8A8_SNORM = 38,
	TIF_VK_FORMAT_R8G8B8A8_USCALED = 39,
	TIF_VK_FORMAT_R8G8B8A8_SSCALED = 40,
	TIF_VK_FORMAT_R8G8B8A8_UINT = 41,
	TIF_VK_FORMAT_R8G8B8A8_SINT = 42,
	TIF_VK_FORMAT_R8G8B8A8_SRGB = 43,
	TIF_VK_FORMAT_B8G8R8A8_UNORM = 44,
	TIF_VK_FORMAT_B8G8R8A8_SNORM = 45,
	TIF_VK_FORMAT_B8G8R8A8_USCALED = 46,
	TIF_VK_FORMAT_B8G8R8A8_SSCALED = 47,
	TIF_VK_FORMAT_B8G8R8A8_UINT = 48,
	TIF_VK_FORMAT_B8G8R8A8_SINT = 49,
	TIF_VK_FORMAT_B8G8R8A8_SRGB = 50,
	TIF_VK_FORMAT_A8B8G8R8_UNORM_PACK32 = 51,
	TIF_VK_FORMAT_A8B8G8R8_SNORM_PACK32 = 52,
	TIF_VK_FORMAT_A8B8G8R8_USCALED_PACK32 = 53,
	TIF_VK_FORMAT_A8B8G8R8_SSCALED_PACK32 = 54,
	TIF_VK_FORMAT_A8B8G8R8_UINT_PACK32 = 55,
	TIF_VK_FORMAT_A8B8G8R8_SINT_PACK32 = 56,
	TIF_VK_FORMAT_A8B8G8R8_SRGB_PACK32 = 57,
	TIF_VK_FORMAT_A2R10G10B10_UNORM_PACK32 = 58,
	TIF_VK_FORMAT_A2R10G10B10_SNORM_PACK32 = 59,
	TIF_VK_FORMAT_A2R10G10B10_USCALED_PACK32 = 60,
	TIF_VK_FORMAT_A2R10G10B10_SSCALED_PACK32 = 61,
	TIF_VK_FORMAT_A2R10G10B10_UINT_PACK32 = 62,
	TIF_VK_FORMAT_A2R10G10B10_SINT_PACK32 = 63,
	TIF_VK_FORMAT_A2B10G10R10_UNORM_PACK32 = 64,
	TIF_VK_FORMAT_A2B10G10R10_SNORM_PACK32 = 65,
	TIF_VK_FORMAT_A2B10G10R10_USCALED_PACK32 = 66,
	TIF_VK_FORMAT_A2B10G10R10_SSCALED_PACK32 = 67,
	TIF_VK_FORMAT_A2B10G10R10_UINT_PACK32 = 68,
	TIF_VK_FORMAT_A2B10G10R10_SINT_PACK32 = 69,
	TIF_VK_FORMAT_R16_UNORM = 70,
	TIF_VK_FORMAT_R16_SNORM = 71,
	TIF_VK_FORMAT_R16_USCALED = 72,
	TIF_VK_FORMAT_R16_SSCALED = 73,
	TIF_VK_FORMAT_R16_UINT = 74,
	TIF_VK_FORMAT_R16_SINT = 75,
	TIF_VK_FORMAT_R16_SFLOAT = 76,
	TIF_VK_FORMAT_R16G16_UNORM = 77,
	TIF_VK_FORMAT_R16G16_SNORM = 78,
	TIF_VK_FORMAT_R16G16_USCALED = 79,
	TIF_VK_FORMAT_R16G16_SSCALED = 80,
	TIF_VK_FORMAT_R16G16_UINT = 81,
	TIF_VK_FORMAT_R16G16_SINT = 82,
	TIF_VK_FORMAT_R16G16_SFLOAT = 83,
	TIF_VK_FORMAT_R16G16B16_UNORM = 84,
	TIF_VK_FORMAT_R16G16B16_SNORM = 85,
	TIF_VK_FORMAT_R16G16B16_USCALED = 86,
	TIF_VK_FORMAT_R16G16B16_SSCALED = 87,
	TIF_VK_FORMAT_R16G16B16_UINT = 88,
	TIF_VK_FORMAT_R16G16B16_SINT = 89,
	TIF_VK_FORMAT_R16G16B16_SFLOAT = 90,
	TIF_VK_FORMAT_R16G16B16A16_UNORM = 91,
	TIF_VK_FORMAT_R16G16B16A16_SNORM = 92,
	TIF_VK_FORMAT_R16G16B16A16_USCALED = 93,
	TIF_VK_FORMAT_R16G16B16A16_SSCALED = 94,
	TIF_VK_FORMAT_R16G16B16A16_UINT = 95,
	TIF_VK_FORMAT_R16G16B16A16_SINT = 96,
	TIF_VK_FORMAT_R16G16B16A16_SFLOAT = 97,
	TIF_VK_FORMAT_R32_UINT = 98,
	TIF_VK_FORMAT_R32_SINT = 99,
	TIF_VK_FORMAT_R32_SFLOAT = 100,
	TIF_VK_FORMAT_R32G32_UINT = 101,
	TIF_VK_FORMAT_R32G32_SINT = 102,
	TIF_VK_FORMAT_R32G32_SFLOAT = 103,
	TIF_VK_FORMAT_R32G32B32_UINT = 104,
	TIF_VK_FORMAT_R32G32B32_SINT = 105,
	TIF_VK_FORMAT_R32G32B32_SFLOAT = 106,
	TIF_VK_FORMAT_R32G32B32A32_UINT = 107,
	TIF_VK_FORMAT_R32G32B32A32_SINT = 108,
	TIF_VK_FORMAT_R32G32B32A32_SFLOAT = 109,
	TIF_VK_FORMAT_R64_UINT = 110,
	TIF_VK_FORMAT_R64_SINT = 111,
	TIF_VK_FORMAT_R64_SFLOAT = 112,
	TIF_VK_FORMAT_R64G64_UINT = 113,
	TIF_VK_FORMAT_R64G64_SINT = 114,
	TIF_VK_FORMAT_R64G64_SFLOAT = 115,
	TIF_VK_FORMAT_R64G64B64_UINT = 116,
	TIF_VK_FORMAT_R64G64B64_SINT = 117,
	TIF_VK_FORMAT_R64G64B64_SFLOAT = 118,
	TIF_VK_FORMAT_R64G64B64A64_UINT = 119,
	TIF_VK_FORMAT_R64G64B64A64_SINT = 120,
	TIF_VK_FORMAT_R64G64B64A64_SFLOAT = 121,
	TIF_VK_FORMAT_B10G11R11_UFLOAT_PACK32 = 122,
	TIF_VK_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123,
	TIF_VK_FORMAT_D16_UNORM = 124,
	TIF_VK_FORMAT_X8_D24_UNORM_PACK32 = 125,
	TIF_VK_FORMAT_D32_SFLOAT = 126,
	TIF_VK_FORMAT_S8_UINT = 127,
	TIF_VK_FORMAT_D16_UNORM_S8_UINT = 128,
	TIF_VK_FORMAT_D24_UNORM_S8_UINT = 129,
	TIF_VK_FORMAT_D32_SFLOAT_S8_UINT = 130,
	TIF_VK_FORMAT_BC1_RGB_UNORM_BLOCK = 131,
	TIF_VK_FORMAT_BC1_RGB_SRGB_BLOCK = 132,
	TIF_VK_FORMAT_BC1_RGBA_UNORM_BLOCK = 133,
	TIF_VK_FORMAT_BC1_RGBA_SRGB_BLOCK = 134,
	TIF_VK_FORMAT_BC2_UNORM_BLOCK = 135,
	TIF_VK_FORMAT_BC2_SRGB_BLOCK = 136,
	TIF_VK_FORMAT_BC3_UNORM_BLOCK = 137,
	TIF_VK_FORMAT_BC3_SRGB_BLOCK = 138,
	TIF_VK_FORMAT_BC4_UNORM_BLOCK = 139,
	TIF_VK_FORMAT_BC4_SNORM_BLOCK = 140,
	TIF_VK_FORMAT_BC5_UNORM_BLOCK = 141,
	TIF_VK_FORMAT_BC5_SNORM_BLOCK = 142,
	TIF_VK_FORMAT_BC6H_UFLOAT_BLOCK = 143,
	TIF_VK_FORMAT_BC6H_SFLOAT_BLOCK = 144,
	TIF_VK_FORMAT_BC7_UNORM_BLOCK = 145,
	TIF_VK_FORMAT_BC7_SRGB_BLOCK = 146,
	TIF_VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147,
	TIF_VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148,
	TIF_VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149,
	TIF_VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150,
	TIF_VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151,
	TIF_VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152,
	TIF_VK_FORMAT_EAC_R11_UNORM_BLOCK = 153,
	TIF_VK_FORMAT_EAC_R11_SNORM_BLOCK = 154,
	TIF_VK_FORMAT_EAC_R11G11_UNORM_BLOCK = 155,
	TIF_VK_FORMAT_EAC_R11G11_SNORM_BLOCK = 156,
	TIF_VK_FORMAT_ASTC_4x4_UNORM_BLOCK = 157,
	TIF_VK_FORMAT_ASTC_4x4_SRGB_BLOCK = 158,
	TIF_VK_FORMAT_ASTC_5x4_UNORM_BLOCK = 159,
	TIF_VK_FORMAT_ASTC_5x4_SRGB_BLOCK = 160,
	TIF_VK_FORMAT_ASTC_5x5_UNORM_BLOCK = 161,
	TIF_VK_FORMAT_ASTC_5x5_SRGB_BLOCK = 162,
	TIF_VK_FORMAT_ASTC_6x5_UNORM_BLOCK = 163,
	TIF_VK_FORMAT_ASTC_6x5_SRGB_BLOCK = 164,
	TIF_VK_FORMAT_ASTC_6x6_UNORM_BLOCK = 165,
	TIF_VK_FORMAT_ASTC_6x6_SRGB_BLOCK = 166,
	TIF_VK_FORMAT_ASTC_8x5_UNORM_BLOCK = 167,
	TIF_VK_FORMAT_ASTC_8x5_SRGB_BLOCK = 168,
	TIF_VK_FORMAT_ASTC_8x6_UNORM_BLOCK = 169,
	TIF_VK_FORMAT_ASTC_8x6_SRGB_BLOCK = 170,
	TIF_VK_FORMAT_ASTC_8x8_UNORM_BLOCK = 171,
	TIF_VK_FORMAT_ASTC_8x8_SRGB_BLOCK = 172,
	TIF_VK_FORMAT_ASTC_10x5_UNORM_BLOCK = 173,
	TIF_VK_FORMAT_ASTC_10x5_SRGB_BLOCK = 174,
	TIF_VK_FORMAT_ASTC_10x6_UNORM_BLOCK = 175,
	TIF_VK_FORMAT_ASTC_10x6_SRGB_BLOCK = 176,
	TIF_VK_FORMAT_ASTC_10x8_UNORM_BLOCK = 177,
	TIF_VK_FORMAT_ASTC_10x8_SRGB_BLOCK = 178,
	TIF_VK_FORMAT_ASTC_10x10_UNORM_BLOCK = 179,
	TIF_VK_FORMAT_ASTC_10x10_SRGB_BLOCK = 180,
	TIF_VK_FORMAT_ASTC_12x10_UNORM_BLOCK = 181,
	TIF_VK_FORMAT_ASTC_12x10_SRGB_BLOCK = 182,
	TIF_VK_FORMAT_ASTC_12x12_UNORM_BLOCK = 183,
	TIF_VK_FORMAT_ASTC_12x12_SRGB_BLOCK = 184,

	TIF_VK_FORMAT_G8B8G8R8_422_UNORM = 1000156000,
	TIF_VK_FORMAT_B8G8R8G8_422_UNORM = 1000156001,
	TIF_VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM = 1000156002,
	TIF_VK_FORMAT_G8_B8R8_2PLANE_420_UNORM = 1000156003,
	TIF_VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM = 1000156004,
	TIF_VK_FORMAT_G8_B8R8_2PLANE_422_UNORM = 1000156005,
	TIF_VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM = 1000156006,
	TIF_VK_FORMAT_R10X6_UNORM_PACK16 = 1000156007,
	TIF_VK_FORMAT_R10X6G10X6_UNORM_2PACK16 = 1000156008,
	TIF_VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16 = 1000156009,
	TIF_VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 = 1000156010,
	TIF_VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 = 1000156011,
	TIF_VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 = 1000156012,
	TIF_VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 = 1000156013,
	TIF_VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 = 1000156014,
	TIF_VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 = 1000156015,
	TIF_VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 = 1000156016,
	TIF_VK_FORMAT_R12X4_UNORM_PACK16 = 1000156017,
	TIF_VK_FORMAT_R12X4G12X4_UNORM_2PACK16 = 1000156018,
	TIF_VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16 = 1000156019,
	TIF_VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 = 1000156020,
	TIF_VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 = 1000156021,
	TIF_VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 = 1000156022,
	TIF_VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 = 1000156023,
	TIF_VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 = 1000156024,
	TIF_VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 = 1000156025,
	TIF_VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 = 1000156026,
	TIF_VK_FORMAT_G16B16G16R16_422_UNORM = 1000156027,
	TIF_VK_FORMAT_B16G16R16G16_422_UNORM = 1000156028,
	TIF_VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM = 1000156029,
	TIF_VK_FORMAT_G16_B16R16_2PLANE_420_UNORM = 1000156030,
	TIF_VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM = 1000156031,
	TIF_VK_FORMAT_G16_B16R16_2PLANE_422_UNORM = 1000156032,
	TIF_VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM = 1000156033,
	TIF_VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG = 1000054000,
	TIF_VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG = 1000054001,
	TIF_VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG = 1000054002,
	TIF_VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG = 1000054003,
	TIF_VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG = 1000054004,
	TIF_VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG = 1000054005,
	TIF_VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG = 1000054006,
	TIF_VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG = 1000054007,
} TinyImageFormat_VkFormat;
#endif

#ifndef TINYIMAGEFORMAT_MTLPIXEL_FORMAT
#define TINYIMAGEFORMAT_MTLPIXEL_FORMAT

typedef enum TinyImageFormat_MTLPixelFormat {
	TIF_MTLPixelFormatInvalid = 0,
	TIF_MTLPixelFormatA8Unorm = 1,
	TIF_MTLPixelFormatR8Unorm = 10,
	TIF_MTLPixelFormatR8Unorm_sRGB = 11,
	TIF_MTLPixelFormatR8Snorm = 12,
	TIF_MTLPixelFormatR8Uint = 13,
	TIF_MTLPixelFormatR8Sint = 14,
	TIF_MTLPixelFormatR16Unorm = 20,
	TIF_MTLPixelFormatR16Snorm = 22,
	TIF_MTLPixelFormatR16Uint = 23,
	TIF_MTLPixelFormatR16Sint = 24,
	TIF_MTLPixelFormatR16Float = 25,
	TIF_MTLPixelFormatRG8Unorm = 30,
	TIF_MTLPixelFormatRG8Unorm_sRGB = 31,
	TIF_MTLPixelFormatRG8Snorm = 32,
	TIF_MTLPixelFormatRG8Uint = 33,
	TIF_MTLPixelFormatRG8Sint = 34,
	TIF_MTLPixelFormatB5G6R5Unorm = 40,
	TIF_MTLPixelFormatA1BGR5Unorm = 41,
	TIF_MTLPixelFormatABGR4Unorm = 42,
	TIF_MTLPixelFormatBGR5A1Unorm = 43,
	TIF_MTLPixelFormatR32Uint = 53,
	TIF_MTLPixelFormatR32Sint = 54,
	TIF_MTLPixelFormatR32Float = 55,
	TIF_MTLPixelFormatRG16Unorm = 60,
	TIF_MTLPixelFormatRG16Snorm = 62,
	TIF_MTLPixelFormatRG16Uint = 63,
	TIF_MTLPixelFormatRG16Sint = 64,
	TIF_MTLPixelFormatRG16Float = 65,
	TIF_MTLPixelFormatRGBA8Unorm = 70,
	TIF_MTLPixelFormatRGBA8Unorm_sRGB = 71,
	TIF_MTLPixelFormatRGBA8Snorm = 72,
	TIF_MTLPixelFormatRGBA8Uint = 73,
	TIF_MTLPixelFormatRGBA8Sint = 74,
	TIF_MTLPixelFormatBGRA8Unorm = 80,
	TIF_MTLPixelFormatBGRA8Unorm_sRGB = 81,
	TIF_MTLPixelFormatRGB10A2Unorm = 90,
	TIF_MTLPixelFormatRGB10A2Uint = 91,
	TIF_MTLPixelFormatRG11B10Float = 92,
	TIF_MTLPixelFormatRGB9E5Float = 93,
	TIF_MTLPixelFormatBGR10A2Unorm = 94,
	TIF_MTLPixelFormatBGR10_XR = 554,
	TIF_MTLPixelFormatBGR10_XR_sRGB = 555,
	TIF_MTLPixelFormatRG32Uint = 103,
	TIF_MTLPixelFormatRG32Sint = 104,
	TIF_MTLPixelFormatRG32Float = 105,
	TIF_MTLPixelFormatRGBA16Unorm = 110,
	TIF_MTLPixelFormatRGBA16Snorm = 112,
	TIF_MTLPixelFormatRGBA16Uint = 113,
	TIF_MTLPixelFormatRGBA16Sint = 114,
	TIF_MTLPixelFormatRGBA16Float = 115,
	TIF_MTLPixelFormatBGRA10_XR = 552,
	TIF_MTLPixelFormatBGRA10_XR_sRGB = 553,
	TIF_MTLPixelFormatRGBA32Uint = 123,
	TIF_MTLPixelFormatRGBA32Sint = 124,
	TIF_MTLPixelFormatRGBA32Float = 125,
	TIF_MTLPixelFormatBC1_RGBA = 130,
	TIF_MTLPixelFormatBC1_RGBA_sRGB = 131,
	TIF_MTLPixelFormatBC2_RGBA = 132,
	TIF_MTLPixelFormatBC2_RGBA_sRGB = 133,
	TIF_MTLPixelFormatBC3_RGBA = 134,
	TIF_MTLPixelFormatBC3_RGBA_sRGB = 135,
	TIF_MTLPixelFormatBC4_RUnorm = 140,
	TIF_MTLPixelFormatBC4_RSnorm = 141,
	TIF_MTLPixelFormatBC5_RGUnorm = 142,
	TIF_MTLPixelFormatBC5_RGSnorm = 143,
	TIF_MTLPixelFormatBC6H_RGBFloat = 150,
	TIF_MTLPixelFormatBC6H_RGBUfloat = 151,
	TIF_MTLPixelFormatBC7_RGBAUnorm = 152,
	TIF_MTLPixelFormatBC7_RGBAUnorm_sRGB = 153,
	TIF_MTLPixelFormatPVRTC_RGB_2BPP = 160,
	TIF_MTLPixelFormatPVRTC_RGB_2BPP_sRGB = 161,
	TIF_MTLPixelFormatPVRTC_RGB_4BPP = 162,
	TIF_MTLPixelFormatPVRTC_RGB_4BPP_sRGB = 163,
	TIF_MTLPixelFormatPVRTC_RGBA_2BPP = 164,
	TIF_MTLPixelFormatPVRTC_RGBA_2BPP_sRGB = 165,
	TIF_MTLPixelFormatPVRTC_RGBA_4BPP = 166,
	TIF_MTLPixelFormatPVRTC_RGBA_4BPP_sRGB = 167,
	TIF_MTLPixelFormatEAC_R11Unorm = 170,
	TIF_MTLPixelFormatEAC_R11Snorm = 172,
	TIF_MTLPixelFormatEAC_RG11Unorm = 174,
	TIF_MTLPixelFormatEAC_RG11Snorm = 176,
	TIF_MTLPixelFormatEAC_RGBA8 = 178,
	TIF_MTLPixelFormatEAC_RGBA8_sRGB = 179,
	TIF_MTLPixelFormatETC2_RGB8 = 180,
	TIF_MTLPixelFormatETC2_RGB8_sRGB = 181,
	TIF_MTLPixelFormatETC2_RGB8A1 = 182,
	TIF_MTLPixelFormatETC2_RGB8A1_sRGB = 183,
	TIF_MTLPixelFormatASTC_4x4_sRGB = 186,
	TIF_MTLPixelFormatASTC_5x4_sRGB = 187,
	TIF_MTLPixelFormatASTC_5x5_sRGB = 188,
	TIF_MTLPixelFormatASTC_6x5_sRGB = 189,
	TIF_MTLPixelFormatASTC_6x6_sRGB = 190,
	TIF_MTLPixelFormatASTC_8x5_sRGB = 192,
	TIF_MTLPixelFormatASTC_8x6_sRGB = 193,
	TIF_MTLPixelFormatASTC_8x8_sRGB = 194,
	TIF_MTLPixelFormatASTC_10x5_sRGB = 195,
	TIF_MTLPixelFormatASTC_10x6_sRGB = 196,
	TIF_MTLPixelFormatASTC_10x8_sRGB = 197,
	TIF_MTLPixelFormatASTC_10x10_sRGB = 198,
	TIF_MTLPixelFormatASTC_12x10_sRGB = 199,
	TIF_MTLPixelFormatASTC_12x12_sRGB = 200,
	TIF_MTLPixelFormatASTC_4x4_LDR = 204,
	TIF_MTLPixelFormatASTC_5x4_LDR = 205,
	TIF_MTLPixelFormatASTC_5x5_LDR = 206,
	TIF_MTLPixelFormatASTC_6x5_LDR = 207,
	TIF_MTLPixelFormatASTC_6x6_LDR = 208,
	TIF_MTLPixelFormatASTC_8x5_LDR = 210,
	TIF_MTLPixelFormatASTC_8x6_LDR = 211,
	TIF_MTLPixelFormatASTC_8x8_LDR = 212,
	TIF_MTLPixelFormatASTC_10x5_LDR = 213,
	TIF_MTLPixelFormatASTC_10x6_LDR = 214,
	TIF_MTLPixelFormatASTC_10x8_LDR = 215,
	TIF_MTLPixelFormatASTC_10x10_LDR = 216,
	TIF_MTLPixelFormatASTC_12x10_LDR = 217,
	TIF_MTLPixelFormatASTC_12x12_LDR = 218,
	TIF_MTLPixelFormatGBGR422 = 240,
	TIF_MTLPixelFormatBGRG422 = 241,
	TIF_MTLPixelFormatDepth16Unorm = 250,
	TIF_MTLPixelFormatDepth32Float = 252,
	TIF_MTLPixelFormatStencil8 = 253,
	TIF_MTLPixelFormatDepth24Unorm_Stencil8 = 255,
	TIF_MTLPixelFormatDepth32Float_Stencil8 = 260,
	TIF_MTLPixelFormatX32_Stencil8 = 261,
	TIF_MTLPixelFormatX24_Stencil8 = 262,
} TinyImageFormat_MTLPixelFormat;
#endif

AL2O3_EXTERN_C TinyImageFormat TinyImageFormat_FromVkFormat(TinyImageFormat_VkFormat fmt);
AL2O3_EXTERN_C TinyImageFormat_VkFormat TinyImageFormat_ToVkFormat(TinyImageFormat fmt);
AL2O3_EXTERN_C TinyImageFormat_DXGI_FORMAT TinyImageFormat_ToDXGI_FORMAT(TinyImageFormat fmt);
AL2O3_EXTERN_C TinyImageFormat TinyImageFormat_FromDXGI_FORMAT(TinyImageFormat_DXGI_FORMAT fmt);
AL2O3_EXTERN_C TinyImageFormat_MTLPixelFormat TinyImageFormat_ToMTLPixelFormat(TinyImageFormat fmt);
AL2O3_EXTERN_C TinyImageFormat TinyImageFormat_FromMTLPixelFormat(TinyImageFormat_MTLPixelFormat fmt);

AL2O3_EXTERN_C TinyImageFormat_DXGI_FORMAT TinyImageFormat_DXGI_FORMATToTypeless(TinyImageFormat_DXGI_FORMAT fmt);

#ifdef IMAGE_IMAGEFORMAT_IMPLEMENTATION

#ifndef TINYKTX_HAVE_STRICMP
#include "string.h" // for stricmp
#endif

static int8_t s_TinyImageFormat_Swizzle_RGBA[4] = { 0, 1, 2, 3};
static int8_t s_TinyImageFormat_Swizzle_ARGB[4] = { 3, 0, 1, 2};
static int8_t s_TinyImageFormat_Swizzle_BGRA[4] = { 2, 1, 0, 3};
static int8_t s_TinyImageFormat_Swizzle_ABGR[4] = { 3, 2, 1, 0};

static int8_t s_TinyImageFormat_Swizzle_000A[4] = {-1,-1,-1, 0};
static int8_t s_TinyImageFormat_Swizzle_R001[4] = { 0,-1,-1,-2};
static int8_t s_TinyImageFormat_Swizzle_RG01[4] = { 0, 1,-1,-2};
static int8_t s_TinyImageFormat_Swizzle_RGB1[4] = { 0, 1, 2,-2};
static int8_t s_TinyImageFormat_Swizzle_BGR1[4] = { 2, 1, 0,-2};

AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_RGBA = s_TinyImageFormat_Swizzle_RGBA;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_ARGB = s_TinyImageFormat_Swizzle_ARGB;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_BGRA = s_TinyImageFormat_Swizzle_BGRA;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_ABGR = s_TinyImageFormat_Swizzle_ABGR;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_000A = s_TinyImageFormat_Swizzle_000A;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_R001 = s_TinyImageFormat_Swizzle_R001;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_RG01 = s_TinyImageFormat_Swizzle_RG01;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_RGB1 = s_TinyImageFormat_Swizzle_RGB1;
AL2O3_EXTERN_C Image_Swizzle TinyImageFormat_Swizzle_BGR1 = s_TinyImageFormat_Swizzle_BGR1;

AL2O3_EXTERN_C char const *TinyImageFormat_Name(enum TinyImageFormat const fmt) {
#define IF_START_MACRO switch(fmt) {
#define IF_MOD_MACRO(x) case TinyImageFormat_##x: return #x;
#define IF_END_MACRO };

#include "tiny_imageformat/format.h"

	return "Unknown Format";
}

AL2O3_EXTERN_C TinyImageFormat TinyImageFormat_FromName(char const *name) {
	for (size_t i = 0u; i < TinyImageFormat_Count(); ++i) {
		if (stricmp(name, TinyImageFormat_Name(i)) == 0) {
			return (TinyImageFormat) i;
		}
	}
	return TinyImageFormat_UNDEFINED;
}

#ifndef __cplusplus
AL2O3_EXTERN_C uint32_t TinyImageFormat_Count() {
	static uint32_t s_count = 0;
	if (s_count == 0) {
#define IF_START_MACRO
#define IF_MOD_MACRO(x) s_count++;
#define IF_END_MACRO
#include "tiny_imageformat/format.h"
	}
	return s_count;
}
#endif

AL2O3_EXTERN_C TinyImageFormat TinyImageFormat_FromVkFormat(TinyImageFormat_VkFormat fmt) {
	switch (fmt) {

	case TIF_VK_FORMAT_UNDEFINED: return TinyImageFormat_UNDEFINED;
	case TIF_VK_FORMAT_R4G4_UNORM_PACK8: return TinyImageFormat_R4G4_UNORM_PACK8;
	case TIF_VK_FORMAT_R4G4B4A4_UNORM_PACK16: return TinyImageFormat_R4G4B4A4_UNORM_PACK16;
	case TIF_VK_FORMAT_B4G4R4A4_UNORM_PACK16: return TinyImageFormat_B4G4R4A4_UNORM_PACK16;
	case TIF_VK_FORMAT_R5G6B5_UNORM_PACK16: return TinyImageFormat_R5G6B5_UNORM_PACK16;
	case TIF_VK_FORMAT_B5G6R5_UNORM_PACK16: return TinyImageFormat_B5G6R5_UNORM_PACK16;
	case TIF_VK_FORMAT_R5G5B5A1_UNORM_PACK16: return TinyImageFormat_R5G5B5A1_UNORM_PACK16;
	case TIF_VK_FORMAT_B5G5R5A1_UNORM_PACK16: return TinyImageFormat_B5G5R5A1_UNORM_PACK16;
	case TIF_VK_FORMAT_A1R5G5B5_UNORM_PACK16: return TinyImageFormat_A1R5G5B5_UNORM_PACK16;
	case TIF_VK_FORMAT_R8_UNORM: return TinyImageFormat_R8_UNORM;
	case TIF_VK_FORMAT_R8_SNORM: return TinyImageFormat_R8_SNORM;
	case TIF_VK_FORMAT_R8_USCALED: return TinyImageFormat_R8_USCALED;
	case TIF_VK_FORMAT_R8_SSCALED: return TinyImageFormat_R8_SSCALED;
	case TIF_VK_FORMAT_R8_UINT: return TinyImageFormat_R8_UINT;
	case TIF_VK_FORMAT_R8_SINT: return TinyImageFormat_R8_SINT;
	case TIF_VK_FORMAT_R8_SRGB: return TinyImageFormat_R8_SRGB;
	case TIF_VK_FORMAT_R8G8_UNORM: return TinyImageFormat_R8G8_UNORM;
	case TIF_VK_FORMAT_R8G8_SNORM: return TinyImageFormat_R8G8_SNORM;
	case TIF_VK_FORMAT_R8G8_USCALED: return TinyImageFormat_R8G8_USCALED;
	case TIF_VK_FORMAT_R8G8_SSCALED: return TinyImageFormat_R8G8_SSCALED;
	case TIF_VK_FORMAT_R8G8_UINT: return TinyImageFormat_R8G8_UINT;
	case TIF_VK_FORMAT_R8G8_SINT: return TinyImageFormat_R8G8_SINT;
	case TIF_VK_FORMAT_R8G8_SRGB: return TinyImageFormat_R8G8_SRGB;
	case TIF_VK_FORMAT_R8G8B8_UNORM: return TinyImageFormat_R8G8B8_UNORM;
	case TIF_VK_FORMAT_R8G8B8_SNORM: return TinyImageFormat_R8G8B8_SNORM;
	case TIF_VK_FORMAT_R8G8B8_USCALED: return TinyImageFormat_R8G8B8_USCALED;
	case TIF_VK_FORMAT_R8G8B8_SSCALED: return TinyImageFormat_R8G8B8_SSCALED;
	case TIF_VK_FORMAT_R8G8B8_UINT: return TinyImageFormat_R8G8B8_UINT;
	case TIF_VK_FORMAT_R8G8B8_SINT: return TinyImageFormat_R8G8B8_SINT;
	case TIF_VK_FORMAT_R8G8B8_SRGB: return TinyImageFormat_R8G8B8_SRGB;
	case TIF_VK_FORMAT_B8G8R8_UNORM: return TinyImageFormat_B8G8R8_UNORM;
	case TIF_VK_FORMAT_B8G8R8_SNORM: return TinyImageFormat_B8G8R8_SNORM;
	case TIF_VK_FORMAT_B8G8R8_USCALED: return TinyImageFormat_B8G8R8_USCALED;
	case TIF_VK_FORMAT_B8G8R8_SSCALED: return TinyImageFormat_B8G8R8_SSCALED;
	case TIF_VK_FORMAT_B8G8R8_UINT: return TinyImageFormat_B8G8R8_UINT;
	case TIF_VK_FORMAT_B8G8R8_SINT: return TinyImageFormat_B8G8R8_SINT;
	case TIF_VK_FORMAT_B8G8R8_SRGB: return TinyImageFormat_B8G8R8_SRGB;
	case TIF_VK_FORMAT_R8G8B8A8_UNORM: return TinyImageFormat_R8G8B8A8_UNORM;
	case TIF_VK_FORMAT_R8G8B8A8_SNORM: return TinyImageFormat_R8G8B8A8_SNORM;
	case TIF_VK_FORMAT_R8G8B8A8_USCALED: return TinyImageFormat_R8G8B8A8_USCALED;
	case TIF_VK_FORMAT_R8G8B8A8_SSCALED: return TinyImageFormat_R8G8B8A8_SSCALED;
	case TIF_VK_FORMAT_R8G8B8A8_UINT: return TinyImageFormat_R8G8B8A8_UINT;
	case TIF_VK_FORMAT_R8G8B8A8_SINT: return TinyImageFormat_R8G8B8A8_SINT;
	case TIF_VK_FORMAT_R8G8B8A8_SRGB: return TinyImageFormat_R8G8B8A8_SRGB;
	case TIF_VK_FORMAT_B8G8R8A8_UNORM: return TinyImageFormat_B8G8R8A8_UNORM;
	case TIF_VK_FORMAT_B8G8R8A8_SNORM: return TinyImageFormat_B8G8R8A8_SNORM;
	case TIF_VK_FORMAT_B8G8R8A8_USCALED: return TinyImageFormat_B8G8R8A8_USCALED;
	case TIF_VK_FORMAT_B8G8R8A8_SSCALED: return TinyImageFormat_B8G8R8A8_SSCALED;
	case TIF_VK_FORMAT_B8G8R8A8_UINT: return TinyImageFormat_B8G8R8A8_UINT;
	case TIF_VK_FORMAT_B8G8R8A8_SINT: return TinyImageFormat_B8G8R8A8_SINT;
	case TIF_VK_FORMAT_B8G8R8A8_SRGB: return TinyImageFormat_B8G8R8A8_SRGB;
	case TIF_VK_FORMAT_A8B8G8R8_UNORM_PACK32: return TinyImageFormat_A8B8G8R8_UNORM_PACK32;
	case TIF_VK_FORMAT_A8B8G8R8_SNORM_PACK32: return TinyImageFormat_A8B8G8R8_SNORM_PACK32;
	case TIF_VK_FORMAT_A8B8G8R8_USCALED_PACK32: return TinyImageFormat_A8B8G8R8_USCALED_PACK32;
	case TIF_VK_FORMAT_A8B8G8R8_SSCALED_PACK32: return TinyImageFormat_A8B8G8R8_SSCALED_PACK32;
	case TIF_VK_FORMAT_A8B8G8R8_UINT_PACK32: return TinyImageFormat_A8B8G8R8_UINT_PACK32;
	case TIF_VK_FORMAT_A8B8G8R8_SINT_PACK32: return TinyImageFormat_A8B8G8R8_SINT_PACK32;
	case TIF_VK_FORMAT_A8B8G8R8_SRGB_PACK32: return TinyImageFormat_A8B8G8R8_SRGB_PACK32;
	case TIF_VK_FORMAT_A2R10G10B10_UNORM_PACK32: return TinyImageFormat_A2R10G10B10_UNORM_PACK32;
	case TIF_VK_FORMAT_A2R10G10B10_USCALED_PACK32: return TinyImageFormat_A2R10G10B10_USCALED_PACK32;
	case TIF_VK_FORMAT_A2R10G10B10_UINT_PACK32: return TinyImageFormat_A2R10G10B10_UINT_PACK32;
	case TIF_VK_FORMAT_A2B10G10R10_UNORM_PACK32: return TinyImageFormat_A2B10G10R10_UNORM_PACK32;
	case TIF_VK_FORMAT_A2B10G10R10_USCALED_PACK32: return TinyImageFormat_A2B10G10R10_USCALED_PACK32;
	case TIF_VK_FORMAT_A2B10G10R10_UINT_PACK32: return TinyImageFormat_A2B10G10R10_UINT_PACK32;
	case TIF_VK_FORMAT_R16_UNORM: return TinyImageFormat_R16_UNORM;
	case TIF_VK_FORMAT_R16_SNORM: return TinyImageFormat_R16_SNORM;
	case TIF_VK_FORMAT_R16_USCALED: return TinyImageFormat_R16_USCALED;
	case TIF_VK_FORMAT_R16_SSCALED: return TinyImageFormat_R16_SSCALED;
	case TIF_VK_FORMAT_R16_UINT: return TinyImageFormat_R16_UINT;
	case TIF_VK_FORMAT_R16_SINT: return TinyImageFormat_R16_SINT;
	case TIF_VK_FORMAT_R16_SFLOAT: return TinyImageFormat_R16_SFLOAT;
	case TIF_VK_FORMAT_R16G16_UNORM: return TinyImageFormat_R16G16_UNORM;
	case TIF_VK_FORMAT_R16G16_SNORM: return TinyImageFormat_R16G16_SNORM;
	case TIF_VK_FORMAT_R16G16_USCALED: return TinyImageFormat_R16G16_USCALED;
	case TIF_VK_FORMAT_R16G16_SSCALED: return TinyImageFormat_R16G16_SSCALED;
	case TIF_VK_FORMAT_R16G16_UINT: return TinyImageFormat_R16G16_UINT;
	case TIF_VK_FORMAT_R16G16_SINT: return TinyImageFormat_R16G16_SINT;
	case TIF_VK_FORMAT_R16G16_SFLOAT: return TinyImageFormat_R16G16_SFLOAT;
	case TIF_VK_FORMAT_R16G16B16_UNORM: return TinyImageFormat_R16G16B16_UNORM;
	case TIF_VK_FORMAT_R16G16B16_SNORM: return TinyImageFormat_R16G16B16_SNORM;
	case TIF_VK_FORMAT_R16G16B16_USCALED: return TinyImageFormat_R16G16B16_USCALED;
	case TIF_VK_FORMAT_R16G16B16_SSCALED: return TinyImageFormat_R16G16B16_SSCALED;
	case TIF_VK_FORMAT_R16G16B16_UINT: return TinyImageFormat_R16G16B16_UINT;
	case TIF_VK_FORMAT_R16G16B16_SINT: return TinyImageFormat_R16G16B16_SINT;
	case TIF_VK_FORMAT_R16G16B16_SFLOAT: return TinyImageFormat_R16G16B16_SFLOAT;
	case TIF_VK_FORMAT_R16G16B16A16_UNORM: return TinyImageFormat_R16G16B16A16_UNORM;
	case TIF_VK_FORMAT_R16G16B16A16_SNORM: return TinyImageFormat_R16G16B16A16_SNORM;
	case TIF_VK_FORMAT_R16G16B16A16_USCALED: return TinyImageFormat_R16G16B16A16_USCALED;
	case TIF_VK_FORMAT_R16G16B16A16_SSCALED: return TinyImageFormat_R16G16B16A16_SSCALED;
	case TIF_VK_FORMAT_R16G16B16A16_UINT: return TinyImageFormat_R16G16B16A16_UINT;
	case TIF_VK_FORMAT_R16G16B16A16_SINT: return TinyImageFormat_R16G16B16A16_SINT;
	case TIF_VK_FORMAT_R16G16B16A16_SFLOAT: return TinyImageFormat_R16G16B16A16_SFLOAT;
	case TIF_VK_FORMAT_R32_UINT: return TinyImageFormat_R32_UINT;
	case TIF_VK_FORMAT_R32_SINT: return TinyImageFormat_R32_SINT;
	case TIF_VK_FORMAT_R32_SFLOAT: return TinyImageFormat_R32_SFLOAT;
	case TIF_VK_FORMAT_R32G32_UINT: return TinyImageFormat_R32G32_UINT;
	case TIF_VK_FORMAT_R32G32_SINT: return TinyImageFormat_R32G32_SINT;
	case TIF_VK_FORMAT_R32G32_SFLOAT: return TinyImageFormat_R32G32_SFLOAT;
	case TIF_VK_FORMAT_R32G32B32_UINT: return TinyImageFormat_R32G32B32_UINT;
	case TIF_VK_FORMAT_R32G32B32_SINT: return TinyImageFormat_R32G32B32_SINT;
	case TIF_VK_FORMAT_R32G32B32_SFLOAT: return TinyImageFormat_R32G32B32_SFLOAT;
	case TIF_VK_FORMAT_R32G32B32A32_UINT: return TinyImageFormat_R32G32B32A32_UINT;
	case TIF_VK_FORMAT_R32G32B32A32_SINT: return TinyImageFormat_R32G32B32A32_SINT;
	case TIF_VK_FORMAT_R32G32B32A32_SFLOAT: return TinyImageFormat_R32G32B32A32_SFLOAT;
	case TIF_VK_FORMAT_R64_UINT: return TinyImageFormat_R64_UINT;
	case TIF_VK_FORMAT_R64_SINT: return TinyImageFormat_R64_SINT;
	case TIF_VK_FORMAT_R64_SFLOAT: return TinyImageFormat_R64_SFLOAT;
	case TIF_VK_FORMAT_R64G64_UINT: return TinyImageFormat_R64G64_UINT;
	case TIF_VK_FORMAT_R64G64_SINT: return TinyImageFormat_R64G64_SINT;
	case TIF_VK_FORMAT_R64G64_SFLOAT: return TinyImageFormat_R64G64_SFLOAT;
	case TIF_VK_FORMAT_R64G64B64_UINT: return TinyImageFormat_R64G64B64_UINT;
	case TIF_VK_FORMAT_R64G64B64_SINT: return TinyImageFormat_R64G64B64_SINT;
	case TIF_VK_FORMAT_R64G64B64_SFLOAT: return TinyImageFormat_R64G64B64_SFLOAT;
	case TIF_VK_FORMAT_R64G64B64A64_UINT: return TinyImageFormat_R64G64B64A64_UINT;
	case TIF_VK_FORMAT_R64G64B64A64_SINT: return TinyImageFormat_R64G64B64A64_SINT;
	case TIF_VK_FORMAT_R64G64B64A64_SFLOAT: return TinyImageFormat_R64G64B64A64_SFLOAT;
	case TIF_VK_FORMAT_B10G11R11_UFLOAT_PACK32: return TinyImageFormat_B10G11R11_UFLOAT_PACK32;
	case TIF_VK_FORMAT_E5B9G9R9_UFLOAT_PACK32: return TinyImageFormat_E5B9G9R9_UFLOAT_PACK32;
	case TIF_VK_FORMAT_D16_UNORM: return TinyImageFormat_D16_UNORM;
	case TIF_VK_FORMAT_X8_D24_UNORM_PACK32: return TinyImageFormat_X8_D24_UNORM_PACK32;
	case TIF_VK_FORMAT_D32_SFLOAT: return TinyImageFormat_D32_SFLOAT;
	case TIF_VK_FORMAT_S8_UINT: return TinyImageFormat_S8_UINT;
	case TIF_VK_FORMAT_D16_UNORM_S8_UINT: return TinyImageFormat_D16_UNORM_S8_UINT;
	case TIF_VK_FORMAT_D24_UNORM_S8_UINT: return TinyImageFormat_D24_UNORM_S8_UINT;
	case TIF_VK_FORMAT_D32_SFLOAT_S8_UINT: return TinyImageFormat_D32_SFLOAT_S8_UINT;
	case TIF_VK_FORMAT_BC1_RGB_UNORM_BLOCK: return TinyImageFormat_BC1_RGB_UNORM_BLOCK;
	case TIF_VK_FORMAT_BC1_RGB_SRGB_BLOCK: return TinyImageFormat_BC1_RGB_SRGB_BLOCK;
	case TIF_VK_FORMAT_BC1_RGBA_UNORM_BLOCK: return TinyImageFormat_BC1_RGBA_UNORM_BLOCK;
	case TIF_VK_FORMAT_BC1_RGBA_SRGB_BLOCK: return TinyImageFormat_BC1_RGBA_SRGB_BLOCK;
	case TIF_VK_FORMAT_BC2_UNORM_BLOCK: return TinyImageFormat_BC2_UNORM_BLOCK;
	case TIF_VK_FORMAT_BC2_SRGB_BLOCK: return TinyImageFormat_BC2_SRGB_BLOCK;
	case TIF_VK_FORMAT_BC3_UNORM_BLOCK: return TinyImageFormat_BC3_UNORM_BLOCK;
	case TIF_VK_FORMAT_BC3_SRGB_BLOCK: return TinyImageFormat_BC3_SRGB_BLOCK;
	case TIF_VK_FORMAT_BC4_UNORM_BLOCK: return TinyImageFormat_BC4_UNORM_BLOCK;
	case TIF_VK_FORMAT_BC4_SNORM_BLOCK: return TinyImageFormat_BC4_SNORM_BLOCK;
	case TIF_VK_FORMAT_BC5_UNORM_BLOCK: return TinyImageFormat_BC5_UNORM_BLOCK;
	case TIF_VK_FORMAT_BC5_SNORM_BLOCK: return TinyImageFormat_BC5_SNORM_BLOCK;
	case TIF_VK_FORMAT_BC6H_UFLOAT_BLOCK: return TinyImageFormat_BC6H_UFLOAT_BLOCK;
	case TIF_VK_FORMAT_BC6H_SFLOAT_BLOCK: return TinyImageFormat_BC6H_SFLOAT_BLOCK;
	case TIF_VK_FORMAT_BC7_UNORM_BLOCK: return TinyImageFormat_BC7_UNORM_BLOCK;
	case TIF_VK_FORMAT_BC7_SRGB_BLOCK: return TinyImageFormat_BC7_SRGB_BLOCK;
	case TIF_VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK: return TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK;
	case TIF_VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK: return TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK;
	case TIF_VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK: return TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK;
	case TIF_VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK: return TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK;
	case TIF_VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK: return TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK;
	case TIF_VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK: return TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK;
	case TIF_VK_FORMAT_EAC_R11_UNORM_BLOCK: return TinyImageFormat_EAC_R11_UNORM_BLOCK;
	case TIF_VK_FORMAT_EAC_R11_SNORM_BLOCK: return TinyImageFormat_EAC_R11_SNORM_BLOCK;
	case TIF_VK_FORMAT_EAC_R11G11_UNORM_BLOCK: return TinyImageFormat_EAC_R11G11_UNORM_BLOCK;
	case TIF_VK_FORMAT_EAC_R11G11_SNORM_BLOCK: return TinyImageFormat_EAC_R11G11_SNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_4x4_UNORM_BLOCK: return TinyImageFormat_ASTC_4x4_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_4x4_SRGB_BLOCK: return TinyImageFormat_ASTC_4x4_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_5x4_UNORM_BLOCK: return TinyImageFormat_ASTC_5x4_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_5x4_SRGB_BLOCK: return TinyImageFormat_ASTC_5x4_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_5x5_UNORM_BLOCK: return TinyImageFormat_ASTC_5x5_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_5x5_SRGB_BLOCK: return TinyImageFormat_ASTC_5x5_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_6x5_UNORM_BLOCK: return TinyImageFormat_ASTC_6x5_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_6x5_SRGB_BLOCK: return TinyImageFormat_ASTC_6x5_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_6x6_UNORM_BLOCK: return TinyImageFormat_ASTC_6x6_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_6x6_SRGB_BLOCK: return TinyImageFormat_ASTC_6x6_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_8x5_UNORM_BLOCK: return TinyImageFormat_ASTC_8x5_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_8x5_SRGB_BLOCK: return TinyImageFormat_ASTC_8x5_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_8x6_UNORM_BLOCK: return TinyImageFormat_ASTC_8x6_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_8x6_SRGB_BLOCK: return TinyImageFormat_ASTC_8x6_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_8x8_UNORM_BLOCK: return TinyImageFormat_ASTC_8x8_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_8x8_SRGB_BLOCK: return TinyImageFormat_ASTC_8x8_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_10x5_UNORM_BLOCK: return TinyImageFormat_ASTC_10x5_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_10x5_SRGB_BLOCK: return TinyImageFormat_ASTC_10x5_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_10x6_UNORM_BLOCK: return TinyImageFormat_ASTC_10x6_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_10x6_SRGB_BLOCK: return TinyImageFormat_ASTC_10x6_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_10x8_UNORM_BLOCK: return TinyImageFormat_ASTC_10x8_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_10x8_SRGB_BLOCK: return TinyImageFormat_ASTC_10x8_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_10x10_UNORM_BLOCK: return TinyImageFormat_ASTC_10x10_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_10x10_SRGB_BLOCK: return TinyImageFormat_ASTC_10x10_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_12x10_UNORM_BLOCK: return TinyImageFormat_ASTC_12x10_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_12x10_SRGB_BLOCK: return TinyImageFormat_ASTC_12x10_SRGB_BLOCK;
	case TIF_VK_FORMAT_ASTC_12x12_UNORM_BLOCK: return TinyImageFormat_ASTC_12x12_UNORM_BLOCK;
	case TIF_VK_FORMAT_ASTC_12x12_SRGB_BLOCK: return TinyImageFormat_ASTC_12x12_SRGB_BLOCK;

	case TIF_VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG: return TinyImageFormat_PVR_2BPP_UNORM_BLOCK;
	case TIF_VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG: return TinyImageFormat_PVR_4BPP_UNORM_BLOCK;
	case TIF_VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG: return TinyImageFormat_PVR_2BPP_SRGB_BLOCK;
	case TIF_VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG: return TinyImageFormat_PVR_4BPP_SRGB_BLOCK;

		/* PVR v2 not supported
		case TIF_VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG: return TinyImageFormat_PVR_2BPP_UNORM_BLOCK;
		case TIF_VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG: return TinyImageFormat_PVR_2BPP_UNORM_BLOCK;
		case TIF_VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG: return TinyImageFormat_PVRTC2_2BPP_SRGB_BLOCK_IMG;
		case TIF_VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG: return TinyImageFormat_PVRTC2_4BPP_SRGB_BLOCK_IMG;
		*/
	default: return TinyImageFormat_UNDEFINED;
	}
}

AL2O3_EXTERN_C TinyImageFormat_VkFormat TinyImageFormat_ToVkFormat(TinyImageFormat fmt) {
	switch (fmt) {

	case TinyImageFormat_UNDEFINED: return TIF_VK_FORMAT_UNDEFINED;
	case TinyImageFormat_R4G4_UNORM_PACK8: return TIF_VK_FORMAT_R4G4_UNORM_PACK8;
	case TinyImageFormat_R4G4B4A4_UNORM_PACK16: return TIF_VK_FORMAT_R4G4B4A4_UNORM_PACK16;
	case TinyImageFormat_B4G4R4A4_UNORM_PACK16: return TIF_VK_FORMAT_B4G4R4A4_UNORM_PACK16;
	case TinyImageFormat_R5G6B5_UNORM_PACK16: return TIF_VK_FORMAT_R5G6B5_UNORM_PACK16;
	case TinyImageFormat_B5G6R5_UNORM_PACK16: return TIF_VK_FORMAT_B5G6R5_UNORM_PACK16;
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16: return TIF_VK_FORMAT_R5G5B5A1_UNORM_PACK16;
	case TinyImageFormat_B5G5R5A1_UNORM_PACK16: return TIF_VK_FORMAT_B5G5R5A1_UNORM_PACK16;
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16: return TIF_VK_FORMAT_A1R5G5B5_UNORM_PACK16;
	case TinyImageFormat_R8_UNORM: return TIF_VK_FORMAT_R8_UNORM;
	case TinyImageFormat_R8_SNORM: return TIF_VK_FORMAT_R8_SNORM;
	case TinyImageFormat_R8_USCALED: return TIF_VK_FORMAT_R8_USCALED;
	case TinyImageFormat_R8_SSCALED: return TIF_VK_FORMAT_R8_SSCALED;
	case TinyImageFormat_R8_UINT: return TIF_VK_FORMAT_R8_UINT;
	case TinyImageFormat_R8_SINT: return TIF_VK_FORMAT_R8_SINT;
	case TinyImageFormat_R8_SRGB: return TIF_VK_FORMAT_R8_SRGB;
	case TinyImageFormat_R8G8_UNORM: return TIF_VK_FORMAT_R8G8_UNORM;
	case TinyImageFormat_R8G8_SNORM: return TIF_VK_FORMAT_R8G8_SNORM;
	case TinyImageFormat_R8G8_USCALED: return TIF_VK_FORMAT_R8G8_USCALED;
	case TinyImageFormat_R8G8_SSCALED: return TIF_VK_FORMAT_R8G8_SSCALED;
	case TinyImageFormat_R8G8_UINT: return TIF_VK_FORMAT_R8G8_UINT;
	case TinyImageFormat_R8G8_SINT: return TIF_VK_FORMAT_R8G8_SINT;
	case TinyImageFormat_R8G8_SRGB: return TIF_VK_FORMAT_R8G8_SRGB;
	case TinyImageFormat_R8G8B8_UNORM: return TIF_VK_FORMAT_R8G8B8_UNORM;
	case TinyImageFormat_R8G8B8_SNORM: return TIF_VK_FORMAT_R8G8B8_SNORM;
	case TinyImageFormat_R8G8B8_USCALED: return TIF_VK_FORMAT_R8G8B8_USCALED;
	case TinyImageFormat_R8G8B8_SSCALED: return TIF_VK_FORMAT_R8G8B8_SSCALED;
	case TinyImageFormat_R8G8B8_UINT: return TIF_VK_FORMAT_R8G8B8_UINT;
	case TinyImageFormat_R8G8B8_SINT: return TIF_VK_FORMAT_R8G8B8_SINT;
	case TinyImageFormat_R8G8B8_SRGB: return TIF_VK_FORMAT_R8G8B8_SRGB;
	case TinyImageFormat_B8G8R8_UNORM: return TIF_VK_FORMAT_B8G8R8_UNORM;
	case TinyImageFormat_B8G8R8_SNORM: return TIF_VK_FORMAT_B8G8R8_SNORM;
	case TinyImageFormat_B8G8R8_USCALED: return TIF_VK_FORMAT_B8G8R8_USCALED;
	case TinyImageFormat_B8G8R8_SSCALED: return TIF_VK_FORMAT_B8G8R8_SSCALED;
	case TinyImageFormat_B8G8R8_UINT: return TIF_VK_FORMAT_B8G8R8_UINT;
	case TinyImageFormat_B8G8R8_SINT: return TIF_VK_FORMAT_B8G8R8_SINT;
	case TinyImageFormat_B8G8R8_SRGB: return TIF_VK_FORMAT_B8G8R8_SRGB;
	case TinyImageFormat_R8G8B8A8_UNORM: return TIF_VK_FORMAT_R8G8B8A8_UNORM;
	case TinyImageFormat_R8G8B8A8_SNORM: return TIF_VK_FORMAT_R8G8B8A8_SNORM;
	case TinyImageFormat_R8G8B8A8_USCALED: return TIF_VK_FORMAT_R8G8B8A8_USCALED;
	case TinyImageFormat_R8G8B8A8_SSCALED: return TIF_VK_FORMAT_R8G8B8A8_SSCALED;
	case TinyImageFormat_R8G8B8A8_UINT: return TIF_VK_FORMAT_R8G8B8A8_UINT;
	case TinyImageFormat_R8G8B8A8_SINT: return TIF_VK_FORMAT_R8G8B8A8_SINT;
	case TinyImageFormat_R8G8B8A8_SRGB: return TIF_VK_FORMAT_R8G8B8A8_SRGB;
	case TinyImageFormat_B8G8R8A8_UNORM: return TIF_VK_FORMAT_B8G8R8A8_UNORM;
	case TinyImageFormat_B8G8R8A8_SNORM: return TIF_VK_FORMAT_B8G8R8A8_SNORM;
	case TinyImageFormat_B8G8R8A8_USCALED: return TIF_VK_FORMAT_B8G8R8A8_USCALED;
	case TinyImageFormat_B8G8R8A8_SSCALED: return TIF_VK_FORMAT_B8G8R8A8_SSCALED;
	case TinyImageFormat_B8G8R8A8_UINT: return TIF_VK_FORMAT_B8G8R8A8_UINT;
	case TinyImageFormat_B8G8R8A8_SINT: return TIF_VK_FORMAT_B8G8R8A8_SINT;
	case TinyImageFormat_B8G8R8A8_SRGB: return TIF_VK_FORMAT_B8G8R8A8_SRGB;
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32: return TIF_VK_FORMAT_A8B8G8R8_UNORM_PACK32;
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32: return TIF_VK_FORMAT_A8B8G8R8_SNORM_PACK32;
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32: return TIF_VK_FORMAT_A8B8G8R8_USCALED_PACK32;
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32: return TIF_VK_FORMAT_A8B8G8R8_SSCALED_PACK32;
	case TinyImageFormat_A8B8G8R8_UINT_PACK32: return TIF_VK_FORMAT_A8B8G8R8_UINT_PACK32;
	case TinyImageFormat_A8B8G8R8_SINT_PACK32: return TIF_VK_FORMAT_A8B8G8R8_SINT_PACK32;
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32: return TIF_VK_FORMAT_A8B8G8R8_SRGB_PACK32;
	case TinyImageFormat_A2R10G10B10_UNORM_PACK32: return TIF_VK_FORMAT_A2R10G10B10_UNORM_PACK32;
	case TinyImageFormat_A2R10G10B10_USCALED_PACK32: return TIF_VK_FORMAT_A2R10G10B10_USCALED_PACK32;
	case TinyImageFormat_A2R10G10B10_UINT_PACK32: return TIF_VK_FORMAT_A2R10G10B10_UINT_PACK32;
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32: return TIF_VK_FORMAT_A2B10G10R10_UNORM_PACK32;
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32: return TIF_VK_FORMAT_A2B10G10R10_USCALED_PACK32;
	case TinyImageFormat_A2B10G10R10_UINT_PACK32: return TIF_VK_FORMAT_A2B10G10R10_UINT_PACK32;
	case TinyImageFormat_R16_UNORM: return TIF_VK_FORMAT_R16_UNORM;
	case TinyImageFormat_R16_SNORM: return TIF_VK_FORMAT_R16_SNORM;
	case TinyImageFormat_R16_USCALED: return TIF_VK_FORMAT_R16_USCALED;
	case TinyImageFormat_R16_SSCALED: return TIF_VK_FORMAT_R16_SSCALED;
	case TinyImageFormat_R16_UINT: return TIF_VK_FORMAT_R16_UINT;
	case TinyImageFormat_R16_SINT: return TIF_VK_FORMAT_R16_SINT;
	case TinyImageFormat_R16_SFLOAT: return TIF_VK_FORMAT_R16_SFLOAT;
	case TinyImageFormat_R16G16_UNORM: return TIF_VK_FORMAT_R16G16_UNORM;
	case TinyImageFormat_R16G16_SNORM: return TIF_VK_FORMAT_R16G16_SNORM;
	case TinyImageFormat_R16G16_USCALED: return TIF_VK_FORMAT_R16G16_USCALED;
	case TinyImageFormat_R16G16_SSCALED: return TIF_VK_FORMAT_R16G16_SSCALED;
	case TinyImageFormat_R16G16_UINT: return TIF_VK_FORMAT_R16G16_UINT;
	case TinyImageFormat_R16G16_SINT: return TIF_VK_FORMAT_R16G16_SINT;
	case TinyImageFormat_R16G16_SFLOAT: return TIF_VK_FORMAT_R16G16_SFLOAT;
	case TinyImageFormat_R16G16B16_UNORM: return TIF_VK_FORMAT_R16G16B16_UNORM;
	case TinyImageFormat_R16G16B16_SNORM: return TIF_VK_FORMAT_R16G16B16_SNORM;
	case TinyImageFormat_R16G16B16_USCALED: return TIF_VK_FORMAT_R16G16B16_USCALED;
	case TinyImageFormat_R16G16B16_SSCALED: return TIF_VK_FORMAT_R16G16B16_SSCALED;
	case TinyImageFormat_R16G16B16_UINT: return TIF_VK_FORMAT_R16G16B16_UINT;
	case TinyImageFormat_R16G16B16_SINT: return TIF_VK_FORMAT_R16G16B16_SINT;
	case TinyImageFormat_R16G16B16_SFLOAT: return TIF_VK_FORMAT_R16G16B16_SFLOAT;
	case TinyImageFormat_R16G16B16A16_UNORM: return TIF_VK_FORMAT_R16G16B16A16_UNORM;
	case TinyImageFormat_R16G16B16A16_SNORM: return TIF_VK_FORMAT_R16G16B16A16_SNORM;
	case TinyImageFormat_R16G16B16A16_USCALED: return TIF_VK_FORMAT_R16G16B16A16_USCALED;
	case TinyImageFormat_R16G16B16A16_SSCALED: return TIF_VK_FORMAT_R16G16B16A16_SSCALED;
	case TinyImageFormat_R16G16B16A16_UINT: return TIF_VK_FORMAT_R16G16B16A16_UINT;
	case TinyImageFormat_R16G16B16A16_SINT: return TIF_VK_FORMAT_R16G16B16A16_SINT;
	case TinyImageFormat_R16G16B16A16_SFLOAT: return TIF_VK_FORMAT_R16G16B16A16_SFLOAT;
	case TinyImageFormat_R32_UINT: return TIF_VK_FORMAT_R32_UINT;
	case TinyImageFormat_R32_SINT: return TIF_VK_FORMAT_R32_SINT;
	case TinyImageFormat_R32_SFLOAT: return TIF_VK_FORMAT_R32_SFLOAT;
	case TinyImageFormat_R32G32_UINT: return TIF_VK_FORMAT_R32G32_UINT;
	case TinyImageFormat_R32G32_SINT: return TIF_VK_FORMAT_R32G32_SINT;
	case TinyImageFormat_R32G32_SFLOAT: return TIF_VK_FORMAT_R32G32_SFLOAT;
	case TinyImageFormat_R32G32B32_UINT: return TIF_VK_FORMAT_R32G32B32_UINT;
	case TinyImageFormat_R32G32B32_SINT: return TIF_VK_FORMAT_R32G32B32_SINT;
	case TinyImageFormat_R32G32B32_SFLOAT: return TIF_VK_FORMAT_R32G32B32_SFLOAT;
	case TinyImageFormat_R32G32B32A32_UINT: return TIF_VK_FORMAT_R32G32B32A32_UINT;
	case TinyImageFormat_R32G32B32A32_SINT: return TIF_VK_FORMAT_R32G32B32A32_SINT;
	case TinyImageFormat_R32G32B32A32_SFLOAT: return TIF_VK_FORMAT_R32G32B32A32_SFLOAT;
	case TinyImageFormat_R64_UINT: return TIF_VK_FORMAT_R64_UINT;
	case TinyImageFormat_R64_SINT: return TIF_VK_FORMAT_R64_SINT;
	case TinyImageFormat_R64_SFLOAT: return TIF_VK_FORMAT_R64_SFLOAT;
	case TinyImageFormat_R64G64_UINT: return TIF_VK_FORMAT_R64G64_UINT;
	case TinyImageFormat_R64G64_SINT: return TIF_VK_FORMAT_R64G64_SINT;
	case TinyImageFormat_R64G64_SFLOAT: return TIF_VK_FORMAT_R64G64_SFLOAT;
	case TinyImageFormat_R64G64B64_UINT: return TIF_VK_FORMAT_R64G64B64_UINT;
	case TinyImageFormat_R64G64B64_SINT: return TIF_VK_FORMAT_R64G64B64_SINT;
	case TinyImageFormat_R64G64B64_SFLOAT: return TIF_VK_FORMAT_R64G64B64_SFLOAT;
	case TinyImageFormat_R64G64B64A64_UINT: return TIF_VK_FORMAT_R64G64B64A64_UINT;
	case TinyImageFormat_R64G64B64A64_SINT: return TIF_VK_FORMAT_R64G64B64A64_SINT;
	case TinyImageFormat_R64G64B64A64_SFLOAT: return TIF_VK_FORMAT_R64G64B64A64_SFLOAT;
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32: return TIF_VK_FORMAT_B10G11R11_UFLOAT_PACK32;
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32: return TIF_VK_FORMAT_E5B9G9R9_UFLOAT_PACK32;
	case TinyImageFormat_D16_UNORM: return TIF_VK_FORMAT_D16_UNORM;
	case TinyImageFormat_X8_D24_UNORM_PACK32: return TIF_VK_FORMAT_X8_D24_UNORM_PACK32;
	case TinyImageFormat_D32_SFLOAT: return TIF_VK_FORMAT_D32_SFLOAT;
	case TinyImageFormat_S8_UINT: return TIF_VK_FORMAT_S8_UINT;
	case TinyImageFormat_D16_UNORM_S8_UINT: return TIF_VK_FORMAT_D16_UNORM_S8_UINT;
	case TinyImageFormat_D24_UNORM_S8_UINT: return TIF_VK_FORMAT_D24_UNORM_S8_UINT;
	case TinyImageFormat_D32_SFLOAT_S8_UINT: return TIF_VK_FORMAT_D32_SFLOAT_S8_UINT;
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK: return TIF_VK_FORMAT_BC1_RGB_UNORM_BLOCK;
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK: return TIF_VK_FORMAT_BC1_RGB_SRGB_BLOCK;
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK: return TIF_VK_FORMAT_BC1_RGBA_UNORM_BLOCK;
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK: return TIF_VK_FORMAT_BC1_RGBA_SRGB_BLOCK;
	case TinyImageFormat_BC2_UNORM_BLOCK: return TIF_VK_FORMAT_BC2_UNORM_BLOCK;
	case TinyImageFormat_BC2_SRGB_BLOCK: return TIF_VK_FORMAT_BC2_SRGB_BLOCK;
	case TinyImageFormat_BC3_UNORM_BLOCK: return TIF_VK_FORMAT_BC3_UNORM_BLOCK;
	case TinyImageFormat_BC3_SRGB_BLOCK: return TIF_VK_FORMAT_BC3_SRGB_BLOCK;
	case TinyImageFormat_BC4_UNORM_BLOCK: return TIF_VK_FORMAT_BC4_UNORM_BLOCK;
	case TinyImageFormat_BC4_SNORM_BLOCK: return TIF_VK_FORMAT_BC4_SNORM_BLOCK;
	case TinyImageFormat_BC5_UNORM_BLOCK: return TIF_VK_FORMAT_BC5_UNORM_BLOCK;
	case TinyImageFormat_BC5_SNORM_BLOCK: return TIF_VK_FORMAT_BC5_SNORM_BLOCK;
	case TinyImageFormat_BC6H_UFLOAT_BLOCK: return TIF_VK_FORMAT_BC6H_UFLOAT_BLOCK;
	case TinyImageFormat_BC6H_SFLOAT_BLOCK: return TIF_VK_FORMAT_BC6H_SFLOAT_BLOCK;
	case TinyImageFormat_BC7_UNORM_BLOCK: return TIF_VK_FORMAT_BC7_UNORM_BLOCK;
	case TinyImageFormat_BC7_SRGB_BLOCK: return TIF_VK_FORMAT_BC7_SRGB_BLOCK;
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK: return TIF_VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG;
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK: return TIF_VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG;
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK: return TIF_VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG;
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK: return TIF_VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG;
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK: return TIF_VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG;
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK: return TIF_VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG;
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK: return TIF_VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG;
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK: return TIF_VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG;
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK: return TIF_VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK: return TIF_VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK: return TIF_VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK: return TIF_VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK: return TIF_VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK: return TIF_VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK;
	case TinyImageFormat_EAC_R11_UNORM_BLOCK: return TIF_VK_FORMAT_EAC_R11_UNORM_BLOCK;
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK: return TIF_VK_FORMAT_EAC_R11G11_UNORM_BLOCK;
	case TinyImageFormat_EAC_R11_SNORM_BLOCK: return TIF_VK_FORMAT_EAC_R11_SNORM_BLOCK;
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK: return TIF_VK_FORMAT_EAC_R11G11_SNORM_BLOCK;
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_4x4_UNORM_BLOCK;
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_4x4_SRGB_BLOCK;
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_5x4_UNORM_BLOCK;
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_5x4_SRGB_BLOCK;
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_5x5_UNORM_BLOCK;
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_5x5_SRGB_BLOCK;
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_6x5_UNORM_BLOCK;
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_6x5_SRGB_BLOCK;
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_6x6_UNORM_BLOCK;
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_6x6_SRGB_BLOCK;
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_8x5_UNORM_BLOCK;
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_8x5_SRGB_BLOCK;
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_8x6_UNORM_BLOCK;
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_8x6_SRGB_BLOCK;
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_8x8_UNORM_BLOCK;
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_8x8_SRGB_BLOCK;
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_10x5_UNORM_BLOCK;
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_10x5_SRGB_BLOCK;
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_10x6_UNORM_BLOCK;
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_10x6_SRGB_BLOCK;
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_10x8_UNORM_BLOCK;
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_10x8_SRGB_BLOCK;
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_10x10_UNORM_BLOCK;
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_10x10_SRGB_BLOCK;
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_12x10_UNORM_BLOCK;
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_12x10_SRGB_BLOCK;
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK: return TIF_VK_FORMAT_ASTC_12x12_UNORM_BLOCK;
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK: return TIF_VK_FORMAT_ASTC_12x12_SRGB_BLOCK;

	case TinyImageFormat_A4R4G4B4_UNORM_PACK16:
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32:
	default: return TIF_VK_FORMAT_UNDEFINED;
	}
}

AL2O3_EXTERN_C TinyImageFormat TinyImageFormat_FromDXGI_FORMAT(TinyImageFormat_DXGI_FORMAT fmt) {
	switch (fmt) {
	case TIF_DXGI_FORMAT_UNKNOWN: return TinyImageFormat_UNDEFINED;
	case TIF_DXGI_FORMAT_R32G32B32A32_FLOAT: return TinyImageFormat_R32G32B32A32_SFLOAT;
	case TIF_DXGI_FORMAT_R32G32B32A32_UINT: return TinyImageFormat_R32G32B32A32_UINT;
	case TIF_DXGI_FORMAT_R32G32B32A32_SINT: return TinyImageFormat_R32G32B32A32_SINT;
	case TIF_DXGI_FORMAT_R32G32B32_FLOAT: return TinyImageFormat_R32G32B32_SFLOAT;
	case TIF_DXGI_FORMAT_R32G32B32_UINT: return TinyImageFormat_R32G32B32_UINT;
	case TIF_DXGI_FORMAT_R32G32B32_SINT: return TinyImageFormat_R32G32B32_SINT;
	case TIF_DXGI_FORMAT_R16G16B16A16_FLOAT: return TinyImageFormat_R16G16B16A16_SFLOAT;
	case TIF_DXGI_FORMAT_R16G16B16A16_UNORM: return TinyImageFormat_R16G16B16A16_UNORM;
	case TIF_DXGI_FORMAT_R16G16B16A16_UINT: return TinyImageFormat_R16G16B16A16_UINT;
	case TIF_DXGI_FORMAT_R16G16B16A16_SNORM: return TinyImageFormat_R16G16B16A16_SNORM;
	case TIF_DXGI_FORMAT_R16G16B16A16_SINT: return TinyImageFormat_R16G16B16A16_SINT;
	case TIF_DXGI_FORMAT_R32G32_FLOAT: return TinyImageFormat_R32G32_SFLOAT;
	case TIF_DXGI_FORMAT_R32G32_UINT: return TinyImageFormat_R32G32_UINT;
	case TIF_DXGI_FORMAT_R32G32_SINT: return TinyImageFormat_R32G32_SINT;
	case TIF_DXGI_FORMAT_D32_FLOAT_S8X24_UINT: return TinyImageFormat_D32_SFLOAT_S8_UINT;
	case TIF_DXGI_FORMAT_R10G10B10A2_UNORM: return TinyImageFormat_A2B10G10R10_UNORM_PACK32;
	case TIF_DXGI_FORMAT_R10G10B10A2_UINT: return TinyImageFormat_A2B10G10R10_UINT_PACK32;
	case TIF_DXGI_FORMAT_R11G11B10_FLOAT: return TinyImageFormat_B10G11R11_UFLOAT_PACK32;
	case TIF_DXGI_FORMAT_R8G8B8A8_UNORM: return TinyImageFormat_R8G8B8A8_UNORM;
	case TIF_DXGI_FORMAT_R8G8B8A8_UNORM_SRGB: return TinyImageFormat_A8B8G8R8_UNORM_PACK32;
	case TIF_DXGI_FORMAT_R8G8B8A8_UINT: return TinyImageFormat_A8B8G8R8_UINT_PACK32;
	case TIF_DXGI_FORMAT_R8G8B8A8_SNORM: return TinyImageFormat_A8B8G8R8_SNORM_PACK32;
	case TIF_DXGI_FORMAT_R8G8B8A8_SINT: return TinyImageFormat_A8B8G8R8_SINT_PACK32;
	case TIF_DXGI_FORMAT_R16G16_FLOAT: return TinyImageFormat_R16G16_SFLOAT;
	case TIF_DXGI_FORMAT_R16G16_UNORM: return TinyImageFormat_R16G16_UNORM;
	case TIF_DXGI_FORMAT_R16G16_UINT: return TinyImageFormat_R16G16_UINT;
	case TIF_DXGI_FORMAT_R16G16_SNORM: return TinyImageFormat_R16G16_SNORM;
	case TIF_DXGI_FORMAT_R16G16_SINT: return TinyImageFormat_R16G16_SINT;
	case TIF_DXGI_FORMAT_D32_FLOAT: return TinyImageFormat_D32_SFLOAT;
	case TIF_DXGI_FORMAT_R32_FLOAT: return TinyImageFormat_R32_SFLOAT;
	case TIF_DXGI_FORMAT_R32_UINT: return TinyImageFormat_R32_UINT;
	case TIF_DXGI_FORMAT_R32_SINT: return TinyImageFormat_R32_SINT;
	case TIF_DXGI_FORMAT_D24_UNORM_S8_UINT: return TinyImageFormat_D24_UNORM_S8_UINT;
	case TIF_DXGI_FORMAT_X24_TYPELESS_G8_UINT: return TinyImageFormat_D24_UNORM_S8_UINT;
	case TIF_DXGI_FORMAT_R8G8_UNORM: return TinyImageFormat_R8G8_UNORM;
	case TIF_DXGI_FORMAT_R8G8_UINT: return TinyImageFormat_R8G8_UINT;
	case TIF_DXGI_FORMAT_R8G8_SNORM: return TinyImageFormat_R8G8_SNORM;
	case TIF_DXGI_FORMAT_R8G8_SINT: return TinyImageFormat_R8G8_SINT;
	case TIF_DXGI_FORMAT_R16_FLOAT: return TinyImageFormat_R16_SFLOAT;
	case TIF_DXGI_FORMAT_D16_UNORM: return TinyImageFormat_D16_UNORM;
	case TIF_DXGI_FORMAT_R16_UNORM: return TinyImageFormat_R16_UNORM;
	case TIF_DXGI_FORMAT_R16_UINT: return TinyImageFormat_R16_UINT;
	case TIF_DXGI_FORMAT_R16_SNORM: return TinyImageFormat_R16_SNORM;
	case TIF_DXGI_FORMAT_R16_SINT: return TinyImageFormat_R16_SINT;
	case TIF_DXGI_FORMAT_R8_UNORM: return TinyImageFormat_R8_UNORM;
	case TIF_DXGI_FORMAT_R8_UINT: return TinyImageFormat_R8_UINT;
	case TIF_DXGI_FORMAT_R8_SNORM: return TinyImageFormat_R8_SNORM;
	case TIF_DXGI_FORMAT_R8_SINT: return TinyImageFormat_R8_SINT;
	case TIF_DXGI_FORMAT_A8_UNORM: return TinyImageFormat_R8_UNORM;
	case TIF_DXGI_FORMAT_R9G9B9E5_SHAREDEXP: return TinyImageFormat_E5B9G9R9_UFLOAT_PACK32;
	case TIF_DXGI_FORMAT_BC1_UNORM: return TinyImageFormat_BC1_RGBA_UNORM_BLOCK;
	case TIF_DXGI_FORMAT_BC1_UNORM_SRGB: return TinyImageFormat_BC1_RGBA_SRGB_BLOCK;
	case TIF_DXGI_FORMAT_BC2_UNORM: return TinyImageFormat_BC2_UNORM_BLOCK;
	case TIF_DXGI_FORMAT_BC2_UNORM_SRGB: return TinyImageFormat_BC2_SRGB_BLOCK;
	case TIF_DXGI_FORMAT_BC3_UNORM: return TinyImageFormat_BC3_UNORM_BLOCK;
	case TIF_DXGI_FORMAT_BC3_UNORM_SRGB: return TinyImageFormat_BC3_SRGB_BLOCK;
	case TIF_DXGI_FORMAT_BC4_UNORM: return TinyImageFormat_BC4_UNORM_BLOCK;
	case TIF_DXGI_FORMAT_BC4_SNORM: return TinyImageFormat_BC4_SNORM_BLOCK;
	case TIF_DXGI_FORMAT_BC5_UNORM: return TinyImageFormat_BC5_UNORM_BLOCK;
	case TIF_DXGI_FORMAT_BC5_SNORM: return TinyImageFormat_BC5_SNORM_BLOCK;
	case TIF_DXGI_FORMAT_B5G6R5_UNORM: return TinyImageFormat_R5G6B5_UNORM_PACK16;
	case TIF_DXGI_FORMAT_B5G5R5A1_UNORM: return TinyImageFormat_R5G5B5A1_UNORM_PACK16;
	case TIF_DXGI_FORMAT_B8G8R8A8_UNORM: return TinyImageFormat_B8G8R8A8_UNORM;
	case TIF_DXGI_FORMAT_B8G8R8X8_UNORM: return TinyImageFormat_B8G8R8A8_UNORM;
	case TIF_DXGI_FORMAT_B8G8R8A8_UNORM_SRGB: return TinyImageFormat_B8G8R8A8_SRGB;
	case TIF_DXGI_FORMAT_B8G8R8X8_UNORM_SRGB: return TinyImageFormat_B8G8R8A8_SRGB;
	case TIF_DXGI_FORMAT_BC6H_UF16: return TinyImageFormat_BC6H_UFLOAT_BLOCK;
	case TIF_DXGI_FORMAT_BC6H_SF16: return TinyImageFormat_BC6H_SFLOAT_BLOCK;
	case TIF_DXGI_FORMAT_BC7_UNORM: return TinyImageFormat_BC7_UNORM_BLOCK;
	case TIF_DXGI_FORMAT_BC7_UNORM_SRGB: return TinyImageFormat_BC7_SRGB_BLOCK;
	case TIF_DXGI_FORMAT_B4G4R4A4_UNORM: return TinyImageFormat_B4G4R4A4_UNORM_PACK16;

	default: return TinyImageFormat_UNDEFINED;
	}
}

AL2O3_EXTERN_C TinyImageFormat_DXGI_FORMAT TinyImageFormat_ToDXGI_FORMAT(TinyImageFormat fmt) {
	switch (fmt) {
	case TinyImageFormat_UNDEFINED: return TIF_DXGI_FORMAT_UNKNOWN;
	case TinyImageFormat_R5G6B5_UNORM_PACK16: return TIF_DXGI_FORMAT_B5G6R5_UNORM;
	case TinyImageFormat_B5G6R5_UNORM_PACK16: return TIF_DXGI_FORMAT_B5G6R5_UNORM;
	case TinyImageFormat_A1R5G5B5_UNORM_PACK16: return TIF_DXGI_FORMAT_B5G5R5A1_UNORM;
	case TinyImageFormat_R8_UNORM: return TIF_DXGI_FORMAT_R8_UNORM;
	case TinyImageFormat_R8_SNORM: return TIF_DXGI_FORMAT_R8_SNORM;
	case TinyImageFormat_R8_USCALED: return TIF_DXGI_FORMAT_R8_UINT;
	case TinyImageFormat_R8_SSCALED: return TIF_DXGI_FORMAT_R8_SINT;
	case TinyImageFormat_R8_UINT: return TIF_DXGI_FORMAT_R8_UINT;
	case TinyImageFormat_R8_SINT: return TIF_DXGI_FORMAT_R8_SINT;
	case TinyImageFormat_R8G8_UNORM: return TIF_DXGI_FORMAT_R8G8_UNORM;
	case TinyImageFormat_R8G8_SNORM: return TIF_DXGI_FORMAT_R8G8_SNORM;
	case TinyImageFormat_R8G8_USCALED: return TIF_DXGI_FORMAT_R8G8_UINT;
	case TinyImageFormat_R8G8_SSCALED: return TIF_DXGI_FORMAT_R8G8_SINT;
	case TinyImageFormat_R8G8_UINT: return TIF_DXGI_FORMAT_R8G8_UINT;
	case TinyImageFormat_R8G8_SINT: return TIF_DXGI_FORMAT_R8G8_SINT;
	case TinyImageFormat_R8G8B8A8_UNORM: return TIF_DXGI_FORMAT_R8G8B8A8_UNORM;
	case TinyImageFormat_R8G8B8A8_SNORM: return TIF_DXGI_FORMAT_R8G8B8A8_SNORM;
	case TinyImageFormat_R8G8B8A8_USCALED: return TIF_DXGI_FORMAT_R8G8B8A8_UINT;
	case TinyImageFormat_R8G8B8A8_SSCALED: return TIF_DXGI_FORMAT_R8G8B8A8_SINT;
	case TinyImageFormat_R8G8B8A8_UINT: return TIF_DXGI_FORMAT_R8G8B8A8_UINT;
	case TinyImageFormat_R8G8B8A8_SINT: return TIF_DXGI_FORMAT_R8G8B8A8_SINT;
	case TinyImageFormat_R8G8B8A8_SRGB: return TIF_DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
	case TinyImageFormat_B8G8R8A8_UNORM: return TIF_DXGI_FORMAT_B8G8R8A8_UNORM;
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32: return TIF_DXGI_FORMAT_R8G8B8A8_UNORM;
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32: return TIF_DXGI_FORMAT_R8G8B8A8_SNORM;
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32: return TIF_DXGI_FORMAT_R8G8B8A8_UINT;
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32: return TIF_DXGI_FORMAT_R8G8B8A8_SINT;
	case TinyImageFormat_A8B8G8R8_UINT_PACK32: return TIF_DXGI_FORMAT_R8G8B8A8_UINT;
	case TinyImageFormat_A8B8G8R8_SINT_PACK32: return TIF_DXGI_FORMAT_R8G8B8A8_SINT;
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32: return TIF_DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32: return TIF_DXGI_FORMAT_R10G10B10A2_UNORM;
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32: return TIF_DXGI_FORMAT_R10G10B10A2_UINT;
	case TinyImageFormat_A2B10G10R10_UINT_PACK32: return TIF_DXGI_FORMAT_R10G10B10A2_UINT;
	case TinyImageFormat_R16_UNORM: return TIF_DXGI_FORMAT_R16_UNORM;
	case TinyImageFormat_R16_SNORM: return TIF_DXGI_FORMAT_R16_SNORM;
	case TinyImageFormat_R16_USCALED: return TIF_DXGI_FORMAT_R16_UINT;
	case TinyImageFormat_R16_SSCALED: return TIF_DXGI_FORMAT_R16_SINT;
	case TinyImageFormat_R16_UINT: return TIF_DXGI_FORMAT_R16_UINT;
	case TinyImageFormat_R16_SINT: return TIF_DXGI_FORMAT_R16_SINT;
	case TinyImageFormat_R16_SFLOAT: return TIF_DXGI_FORMAT_R16_FLOAT;
	case TinyImageFormat_R16G16_UNORM: return TIF_DXGI_FORMAT_R16G16_UNORM;
	case TinyImageFormat_R16G16_SNORM: return TIF_DXGI_FORMAT_R16G16_SNORM;
	case TinyImageFormat_R16G16_USCALED: return TIF_DXGI_FORMAT_R16G16_UINT;
	case TinyImageFormat_R16G16_SSCALED: return TIF_DXGI_FORMAT_R16G16_SINT;
	case TinyImageFormat_R16G16_UINT: return TIF_DXGI_FORMAT_R16G16_UINT;
	case TinyImageFormat_R16G16_SINT: return TIF_DXGI_FORMAT_R16G16_SINT;
	case TinyImageFormat_R16G16_SFLOAT: return TIF_DXGI_FORMAT_R16G16_FLOAT;
	case TinyImageFormat_R16G16B16A16_UNORM: return TIF_DXGI_FORMAT_R16G16B16A16_UNORM;
	case TinyImageFormat_R16G16B16A16_SNORM: return TIF_DXGI_FORMAT_R16G16B16A16_SNORM;
	case TinyImageFormat_R16G16B16A16_USCALED: return TIF_DXGI_FORMAT_R16G16B16A16_UINT;
	case TinyImageFormat_R16G16B16A16_SSCALED: return TIF_DXGI_FORMAT_R16G16B16A16_SINT;
	case TinyImageFormat_R16G16B16A16_UINT: return TIF_DXGI_FORMAT_R16G16B16A16_UINT;
	case TinyImageFormat_R16G16B16A16_SINT: return TIF_DXGI_FORMAT_R16G16B16A16_SINT;
	case TinyImageFormat_R16G16B16A16_SFLOAT: return TIF_DXGI_FORMAT_R16G16B16A16_FLOAT;
	case TinyImageFormat_R32_UINT: return TIF_DXGI_FORMAT_R32_UINT;
	case TinyImageFormat_R32_SINT: return TIF_DXGI_FORMAT_R32_SINT;
	case TinyImageFormat_R32_SFLOAT: return TIF_DXGI_FORMAT_R32_FLOAT;
	case TinyImageFormat_R32G32_UINT: return TIF_DXGI_FORMAT_R32G32_UINT;
	case TinyImageFormat_R32G32_SINT: return TIF_DXGI_FORMAT_R32G32_SINT;
	case TinyImageFormat_R32G32_SFLOAT: return TIF_DXGI_FORMAT_R32G32_FLOAT;
	case TinyImageFormat_R32G32B32_UINT: return TIF_DXGI_FORMAT_R32G32B32_UINT;
	case TinyImageFormat_R32G32B32_SINT: return TIF_DXGI_FORMAT_R32G32B32_SINT;
	case TinyImageFormat_R32G32B32_SFLOAT: return TIF_DXGI_FORMAT_R32G32B32_FLOAT;
	case TinyImageFormat_R32G32B32A32_UINT: return TIF_DXGI_FORMAT_R32G32B32A32_UINT;
	case TinyImageFormat_R32G32B32A32_SINT: return TIF_DXGI_FORMAT_R32G32B32A32_SINT;
	case TinyImageFormat_R32G32B32A32_SFLOAT: return TIF_DXGI_FORMAT_R32G32B32A32_FLOAT;
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32: return TIF_DXGI_FORMAT_R11G11B10_FLOAT;
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32: return TIF_DXGI_FORMAT_R9G9B9E5_SHAREDEXP;
	case TinyImageFormat_D16_UNORM: return TIF_DXGI_FORMAT_D16_UNORM;
	case TinyImageFormat_X8_D24_UNORM_PACK32: return TIF_DXGI_FORMAT_D24_UNORM_S8_UINT;
	case TinyImageFormat_D32_SFLOAT: return TIF_DXGI_FORMAT_D32_FLOAT;
	case TinyImageFormat_D24_UNORM_S8_UINT: return TIF_DXGI_FORMAT_D24_UNORM_S8_UINT;
	case TinyImageFormat_D32_SFLOAT_S8_UINT: return TIF_DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
	case TinyImageFormat_BC1_RGB_UNORM_BLOCK: return TIF_DXGI_FORMAT_BC1_UNORM;
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK: return TIF_DXGI_FORMAT_BC1_UNORM_SRGB;
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK: return TIF_DXGI_FORMAT_BC1_UNORM;
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK: return TIF_DXGI_FORMAT_BC1_UNORM_SRGB;
	case TinyImageFormat_BC2_UNORM_BLOCK: return TIF_DXGI_FORMAT_BC2_UNORM;
	case TinyImageFormat_BC2_SRGB_BLOCK: return TIF_DXGI_FORMAT_BC2_UNORM_SRGB;
	case TinyImageFormat_BC3_UNORM_BLOCK: return TIF_DXGI_FORMAT_BC3_UNORM;
	case TinyImageFormat_BC3_SRGB_BLOCK: return TIF_DXGI_FORMAT_BC3_UNORM_SRGB;
	case TinyImageFormat_BC4_UNORM_BLOCK: return TIF_DXGI_FORMAT_BC4_UNORM;
	case TinyImageFormat_BC4_SNORM_BLOCK: return TIF_DXGI_FORMAT_BC4_SNORM;
	case TinyImageFormat_BC5_UNORM_BLOCK: return TIF_DXGI_FORMAT_BC5_UNORM;
	case TinyImageFormat_BC5_SNORM_BLOCK: return TIF_DXGI_FORMAT_BC5_SNORM;
	case TinyImageFormat_BC6H_UFLOAT_BLOCK: return TIF_DXGI_FORMAT_BC6H_UF16;
	case TinyImageFormat_BC6H_SFLOAT_BLOCK: return TIF_DXGI_FORMAT_BC6H_SF16;
	case TinyImageFormat_BC7_UNORM_BLOCK: return TIF_DXGI_FORMAT_BC7_UNORM;
	case TinyImageFormat_BC7_SRGB_BLOCK: return TIF_DXGI_FORMAT_BC7_UNORM_SRGB;
	case TinyImageFormat_A4R4G4B4_UNORM_PACK16: return TIF_DXGI_FORMAT_B4G4R4A4_UNORM;
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32: return TIF_DXGI_FORMAT_B8G8R8A8_UNORM;
	default: return TIF_DXGI_FORMAT_UNKNOWN;
	}
}

AL2O3_EXTERN_C TinyImageFormat_DXGI_FORMAT TinyImageFormat_DXGI_FORMATToTypeless(TinyImageFormat_DXGI_FORMAT fmt) {
	switch (fmt) {
	case TIF_DXGI_FORMAT_R32G32B32A32_FLOAT:
	case TIF_DXGI_FORMAT_R32G32B32A32_UINT:
	case TIF_DXGI_FORMAT_R32G32B32A32_SINT: return TIF_DXGI_FORMAT_R32G32B32A32_TYPELESS;
	case TIF_DXGI_FORMAT_R32G32B32_FLOAT:
	case TIF_DXGI_FORMAT_R32G32B32_UINT:
	case TIF_DXGI_FORMAT_R32G32B32_SINT: return TIF_DXGI_FORMAT_R32G32B32_TYPELESS;
	case TIF_DXGI_FORMAT_R16G16B16A16_FLOAT:
	case TIF_DXGI_FORMAT_R16G16B16A16_UNORM:
	case TIF_DXGI_FORMAT_R16G16B16A16_UINT:
	case TIF_DXGI_FORMAT_R16G16B16A16_SNORM:
	case TIF_DXGI_FORMAT_R16G16B16A16_SINT: return TIF_DXGI_FORMAT_R16G16B16A16_TYPELESS;
	case TIF_DXGI_FORMAT_R32G32_FLOAT:
	case TIF_DXGI_FORMAT_R32G32_UINT:
	case TIF_DXGI_FORMAT_R32G32_SINT: return TIF_DXGI_FORMAT_R32G32_TYPELESS;
	case TIF_DXGI_FORMAT_R10G10B10A2_UNORM:
	case TIF_DXGI_FORMAT_R10G10B10A2_UINT: return TIF_DXGI_FORMAT_R10G10B10A2_TYPELESS;
	case TIF_DXGI_FORMAT_R8G8B8A8_UNORM:
	case TIF_DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
	case TIF_DXGI_FORMAT_R8G8B8A8_UINT:
	case TIF_DXGI_FORMAT_R8G8B8A8_SNORM:
	case TIF_DXGI_FORMAT_R8G8B8A8_SINT: return TIF_DXGI_FORMAT_R8G8B8A8_TYPELESS;
	case TIF_DXGI_FORMAT_R16G16_FLOAT:
	case TIF_DXGI_FORMAT_R16G16_UNORM:
	case TIF_DXGI_FORMAT_R16G16_UINT:
	case TIF_DXGI_FORMAT_R16G16_SNORM:
	case TIF_DXGI_FORMAT_R16G16_SINT: return TIF_DXGI_FORMAT_R16G16_TYPELESS;

	case TIF_DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
	case TIF_DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
	case TIF_DXGI_FORMAT_R11G11B10_FLOAT: // closest typeless is raw 32 bits
	case TIF_DXGI_FORMAT_D32_FLOAT:
	case TIF_DXGI_FORMAT_R32_FLOAT:
	case TIF_DXGI_FORMAT_R32_UINT:
	case TIF_DXGI_FORMAT_R32_SINT: return TIF_DXGI_FORMAT_R32_TYPELESS;
	case TIF_DXGI_FORMAT_R8G8_UNORM:
	case TIF_DXGI_FORMAT_R8G8_UINT:
	case TIF_DXGI_FORMAT_R8G8_SNORM:
	case TIF_DXGI_FORMAT_R8G8_SINT: return TIF_DXGI_FORMAT_R8G8_TYPELESS;
	case TIF_DXGI_FORMAT_B4G4R4A4_UNORM: // just treats a 16 raw bits
	case TIF_DXGI_FORMAT_D16_UNORM:
	case TIF_DXGI_FORMAT_R16_FLOAT:
	case TIF_DXGI_FORMAT_R16_UNORM:
	case TIF_DXGI_FORMAT_R16_UINT:
	case TIF_DXGI_FORMAT_R16_SNORM:
	case TIF_DXGI_FORMAT_R16_SINT: return TIF_DXGI_FORMAT_R16_TYPELESS;
	case TIF_DXGI_FORMAT_A8_UNORM:
	case TIF_DXGI_FORMAT_R8_UNORM:
	case TIF_DXGI_FORMAT_R8_UINT:
	case TIF_DXGI_FORMAT_R8_SNORM:
	case TIF_DXGI_FORMAT_R8_SINT: return TIF_DXGI_FORMAT_R8_TYPELESS;
	case TIF_DXGI_FORMAT_BC1_UNORM:
	case TIF_DXGI_FORMAT_BC1_UNORM_SRGB: return TIF_DXGI_FORMAT_BC1_TYPELESS;
	case TIF_DXGI_FORMAT_BC2_UNORM:
	case TIF_DXGI_FORMAT_BC2_UNORM_SRGB: return TIF_DXGI_FORMAT_BC2_TYPELESS;
	case TIF_DXGI_FORMAT_BC3_UNORM:
	case TIF_DXGI_FORMAT_BC3_UNORM_SRGB: return TIF_DXGI_FORMAT_BC3_TYPELESS;
	case TIF_DXGI_FORMAT_BC4_UNORM:
	case TIF_DXGI_FORMAT_BC4_SNORM: return TIF_DXGI_FORMAT_BC4_TYPELESS;
	case TIF_DXGI_FORMAT_BC5_UNORM:
	case TIF_DXGI_FORMAT_BC5_SNORM: return TIF_DXGI_FORMAT_BC5_TYPELESS;
	case TIF_DXGI_FORMAT_B5G6R5_UNORM:
	case TIF_DXGI_FORMAT_B5G5R5A1_UNORM: return TIF_DXGI_FORMAT_R16_TYPELESS;
	case TIF_DXGI_FORMAT_B8G8R8A8_UNORM:
	case TIF_DXGI_FORMAT_B8G8R8X8_UNORM:
	case TIF_DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
	case TIF_DXGI_FORMAT_B8G8R8X8_UNORM_SRGB: return TIF_DXGI_FORMAT_B8G8R8A8_UNORM;
	case TIF_DXGI_FORMAT_BC6H_UF16:
	case TIF_DXGI_FORMAT_BC6H_SF16: return TIF_DXGI_FORMAT_BC6H_TYPELESS;
	case TIF_DXGI_FORMAT_BC7_UNORM:
	case TIF_DXGI_FORMAT_BC7_UNORM_SRGB: return TIF_DXGI_FORMAT_BC7_TYPELESS;

	case TIF_DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
	case TIF_DXGI_FORMAT_D32_FLOAT_S8X24_UINT: return TIF_DXGI_FORMAT_R32G32_TYPELESS;
	case TIF_DXGI_FORMAT_X24_TYPELESS_G8_UINT: return TIF_DXGI_FORMAT_R24G8_TYPELESS;
	case TIF_DXGI_FORMAT_D24_UNORM_S8_UINT: return TIF_DXGI_FORMAT_R24G8_TYPELESS;

		// typeless just return the input format
	case TIF_DXGI_FORMAT_R32G32B32A32_TYPELESS:
	case TIF_DXGI_FORMAT_R32G32B32_TYPELESS:
	case TIF_DXGI_FORMAT_R16G16B16A16_TYPELESS:
	case TIF_DXGI_FORMAT_R32G32_TYPELESS:
	case TIF_DXGI_FORMAT_R32G8X24_TYPELESS:
	case TIF_DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
	case TIF_DXGI_FORMAT_R10G10B10A2_TYPELESS:
	case TIF_DXGI_FORMAT_R8G8B8A8_TYPELESS:
	case TIF_DXGI_FORMAT_R16G16_TYPELESS:
	case TIF_DXGI_FORMAT_R32_TYPELESS:
	case TIF_DXGI_FORMAT_R24G8_TYPELESS:
	case TIF_DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
	case TIF_DXGI_FORMAT_R8G8_TYPELESS:
	case TIF_DXGI_FORMAT_R16_TYPELESS:
	case TIF_DXGI_FORMAT_R8_TYPELESS:
	case TIF_DXGI_FORMAT_BC1_TYPELESS:
	case TIF_DXGI_FORMAT_BC2_TYPELESS:
	case TIF_DXGI_FORMAT_BC3_TYPELESS:
	case TIF_DXGI_FORMAT_BC4_TYPELESS:
	case TIF_DXGI_FORMAT_BC5_TYPELESS:
	case TIF_DXGI_FORMAT_B8G8R8A8_TYPELESS:
	case TIF_DXGI_FORMAT_B8G8R8X8_TYPELESS:
	case TIF_DXGI_FORMAT_BC6H_TYPELESS:
	case TIF_DXGI_FORMAT_BC7_TYPELESS: return fmt;

	case TIF_DXGI_FORMAT_R1_UNORM:
	case TIF_DXGI_FORMAT_R8G8_B8G8_UNORM:
	case TIF_DXGI_FORMAT_G8R8_G8B8_UNORM:
	case TIF_DXGI_FORMAT_AYUV:
	case TIF_DXGI_FORMAT_Y410:
	case TIF_DXGI_FORMAT_Y416:
	case TIF_DXGI_FORMAT_NV12:
	case TIF_DXGI_FORMAT_P010:
	case TIF_DXGI_FORMAT_P016:
	case TIF_DXGI_FORMAT_420_OPAQUE:
	case TIF_DXGI_FORMAT_YUY2:
	case TIF_DXGI_FORMAT_Y210:
	case TIF_DXGI_FORMAT_Y216:
	case TIF_DXGI_FORMAT_NV11:
	case TIF_DXGI_FORMAT_AI44:
	case TIF_DXGI_FORMAT_IA44:
	case TIF_DXGI_FORMAT_P8:
	case TIF_DXGI_FORMAT_A8P8:
	case TIF_DXGI_FORMAT_P208:
	case TIF_DXGI_FORMAT_V208:
	case TIF_DXGI_FORMAT_V408:
	case TIF_DXGI_FORMAT_UNKNOWN: return TIF_DXGI_FORMAT_UNKNOWN;
	case TIF_DXGI_FORMAT_FORCE_UINT:break;
	}
	ASSERT(false);
	return TIF_DXGI_FORMAT_UNKNOWN;
}

AL2O3_EXTERN_C TinyImageFormat_MTLPixelFormat TinyImageFormat_ToMTLPixelFormat(TinyImageFormat fmt) {
	switch (fmt) {
	case TinyImageFormat_A8_UNORM: 									return TIF_MTLPixelFormatA8Unorm;
	case TinyImageFormat_R8_UNORM: 		return TIF_MTLPixelFormatR8Unorm;
	case TinyImageFormat_R8_SNORM: 		return TIF_MTLPixelFormatR8Snorm;
	case TinyImageFormat_R8_USCALED: 	return TIF_MTLPixelFormatR8Uint;
	case TinyImageFormat_R8_SSCALED: 	return TIF_MTLPixelFormatR8Sint;
	case TinyImageFormat_R8_UINT: 		return TIF_MTLPixelFormatR8Uint;
	case TinyImageFormat_R8_SINT: 		return TIF_MTLPixelFormatR8Sint;
	case TinyImageFormat_R8_SRGB: 		return TIF_MTLPixelFormatR8Unorm_sRGB;
	case TinyImageFormat_UNDEFINED: return TIF_MTLPixelFormatInvalid;
//	case TinyImageFormat_R4G4_UNORM_PACK8: return TIF_MTLPixelFormatR4G4;
	case TinyImageFormat_R4G4B4A4_UNORM_PACK16: return TIF_MTLPixelFormatABGR4Unorm;
//	case TinyImageFormat_A4R4G4B4_UNORM_PACK16:			return TIF_MTLBRGA4
//	case TinyImageFormat_B4G4R4A4_UNORM_PACK16:
	case TinyImageFormat_R5G6B5_UNORM_PACK16: return TIF_MTLPixelFormatB5G6R5Unorm;;
//	case TinyImageFormat_B5G6R5_UNORM_PACK16: return TIF_MTLPixelFormatB5G6R5Unorm;
	case TinyImageFormat_R5G5B5A1_UNORM_PACK16: return TIF_MTLPixelFormatA1BGR5Unorm;
//	case TinyImageFormat_B5G5R5A1_UNORM_PACK16:
//	case TinyImageFormat_A1R5G5B5_UNORM_PACK16:
	case TinyImageFormat_R8G8_UNORM:		return TIF_MTLPixelFormatRG8Unorm;
	case TinyImageFormat_R8G8_SNORM:		return TIF_MTLPixelFormatRG8Snorm;
	case TinyImageFormat_R8G8_USCALED:	return TIF_MTLPixelFormatRG8Uint;
	case TinyImageFormat_R8G8_SSCALED:	return TIF_MTLPixelFormatRG8Sint;
	case TinyImageFormat_R8G8_UINT:			return TIF_MTLPixelFormatRG8Uint;
	case TinyImageFormat_R8G8_SINT:			return TIF_MTLPixelFormatRG8Sint;
	case TinyImageFormat_R8G8_SRGB:			return TIF_MTLPixelFormatRG8Unorm_sRGB;
//	case TinyImageFormat_R8G8B8_UNORM:	return TIF_MTLPixelFormatBGR88Unorm;
//	case TinyImageFormat_R8G8B8_SNORM:	return TIF_MTLPixelFormatBGR8Snorm;
//	case TinyImageFormat_R8G8B8_USCALED:return TIF_MTLPixelFormatBGR8Uint;
//	case TinyImageFormat_R8G8B8_SSCALED:return TIF_MTLPixelFormatBGR8Sint;
//	case TinyImageFormat_R8G8B8_UINT:		return TIF_MTLPixelFormatBGR8Uint;
//	case TinyImageFormat_R8G8B8_SINT:		return TIF_MTLPixelFormatBGR8Sint;
//	case TinyImageFormat_R8G8B8_SRGB:		return TIF_MTLPixelFormatRGB8Unorm_sRGB;
//	case TinyImageFormat_B8G8R8_UNORM:
//	case TinyImageFormat_B8G8R8_SNORM:
//	case TinyImageFormat_B8G8R8_USCALED:
//	case TinyImageFormat_B8G8R8_SSCALED:
//	case TinyImageFormat_B8G8R8_UINT:
//	case TinyImageFormat_B8G8R8_SINT:
//	case TinyImageFormat_B8G8R8_SRGB:

	case TinyImageFormat_R8G8B8A8_UNORM:		return TIF_MTLPixelFormatRGBA8Unorm;
	case TinyImageFormat_R8G8B8A8_SNORM:		return TIF_MTLPixelFormatRGBA8Snorm;
	case TinyImageFormat_R8G8B8A8_USCALED:	return TIF_MTLPixelFormatRGBA8Uint;
	case TinyImageFormat_R8G8B8A8_SSCALED:	return TIF_MTLPixelFormatRGBA8Sint;
	case TinyImageFormat_R8G8B8A8_UINT:			return TIF_MTLPixelFormatRGBA8Uint;
	case TinyImageFormat_R8G8B8A8_SINT:			return TIF_MTLPixelFormatRGBA8Sint;
	case TinyImageFormat_R8G8B8A8_SRGB:			return TIF_MTLPixelFormatRGBA8Unorm_sRGB;

	case TinyImageFormat_B8G8R8A8_UNORM: 							return TIF_MTLPixelFormatBGRA8Unorm;
//	case TinyImageFormat_B8G8R8A8_SNORM:							return TIF_MTLPixelFormatBGRA8Snorm;
//	case TinyImageFormat_B8G8R8A8_USCALED:						return TIF_MTLPixelFormatBGRA8Uint;
//	case TinyImageFormat_B8G8R8A8_SSCALED:						return TIF_MTLPixelFormatBGRA8Sint;
//	case TinyImageFormat_B8G8R8A8_UINT:								return TIF_MTLPixelFormatBGRA8Uint;
//	case TinyImageFormat_B8G8R8A8_SINT:								return TIF_MTLPixelFormatBGRA8Sint;
	case TinyImageFormat_B8G8R8A8_SRGB:								return TIF_MTLPixelFormatBGRA8Unorm_sRGB;
	case TinyImageFormat_A8B8G8R8_UNORM_PACK32: 			return TIF_MTLPixelFormatRGBA8Unorm;
	case TinyImageFormat_A8B8G8R8_SNORM_PACK32:				return TIF_MTLPixelFormatRGBA8Snorm;
	case TinyImageFormat_A8B8G8R8_USCALED_PACK32:			return TIF_MTLPixelFormatRGBA8Uint;
	case TinyImageFormat_A8B8G8R8_SSCALED_PACK32:			return TIF_MTLPixelFormatRGBA8Sint;
	case TinyImageFormat_A8B8G8R8_UINT_PACK32:				return TIF_MTLPixelFormatRGBA8Uint;
	case TinyImageFormat_A8B8G8R8_SINT_PACK32:				return TIF_MTLPixelFormatRGBA8Sint;
	case TinyImageFormat_A8B8G8R8_SRGB_PACK32:				return TIF_MTLPixelFormatRGBA8Unorm_sRGB;
	case TinyImageFormat_A8R8G8B8_UNORM_PACK32:			return TIF_MTLPixelFormatBGRA8Unorm;

	case TinyImageFormat_A2R10G10B10_UNORM_PACK32:		return TIF_MTLPixelFormatBGR10A2Unorm;
//	case TinyImageFormat_A2R10G10B10_USCALED_PACK32:	return TIF_MTLPixelFormatBGR10A2Uint;
//	case TinyImageFormat_A2R10G10B10_UINT_PACK32:			return TIF_MTLPixelFormatBGR10A2Uint;
	case TinyImageFormat_A2B10G10R10_UNORM_PACK32:		return TIF_MTLPixelFormatRGB10A2Unorm;
	case TinyImageFormat_A2B10G10R10_USCALED_PACK32:	return TIF_MTLPixelFormatRGB10A2Uint;
	case TinyImageFormat_A2B10G10R10_UINT_PACK32:			return TIF_MTLPixelFormatRGB10A2Uint;
	case TinyImageFormat_R16_UNORM:			return TIF_MTLPixelFormatR16Unorm;
	case TinyImageFormat_R16_SNORM:			return TIF_MTLPixelFormatR16Snorm;
	case TinyImageFormat_R16_USCALED:		return TIF_MTLPixelFormatR16Uint;
	case TinyImageFormat_R16_SSCALED:		return TIF_MTLPixelFormatR16Sint;
	case TinyImageFormat_R16_UINT:			return TIF_MTLPixelFormatR16Uint;
	case TinyImageFormat_R16_SINT:			return TIF_MTLPixelFormatR16Sint;
	case TinyImageFormat_R16_SFLOAT:		return TIF_MTLPixelFormatR16Float;
	case TinyImageFormat_R16G16_UNORM:	return TIF_MTLPixelFormatRG16Unorm;
	case TinyImageFormat_R16G16_SNORM:	return TIF_MTLPixelFormatRG16Snorm;
	case TinyImageFormat_R16G16_USCALED:return TIF_MTLPixelFormatRG16Uint;
	case TinyImageFormat_R16G16_SSCALED:return TIF_MTLPixelFormatRG16Sint;
	case TinyImageFormat_R16G16_UINT:		return TIF_MTLPixelFormatRG16Uint;
	case TinyImageFormat_R16G16_SINT:		return TIF_MTLPixelFormatRG16Sint;
	case TinyImageFormat_R16G16_SFLOAT:	return TIF_MTLPixelFormatRG16Float;
//	case TinyImageFormat_R16G16B16_UNORM:		return TIF_MTLPixelFormatRGB16Unorm;
//	case TinyImageFormat_R16G16B16_SNORM:		return TIF_MTLPixelFormatRGB16Snorm;
//	case TinyImageFormat_R16G16B16_USCALED:	return TIF_MTLPixelFormatRGB16Uint;
//	case TinyImageFormat_R16G16B16_SSCALED:	return TIF_MTLPixelFormatRGB16Sint;
//	case TinyImageFormat_R16G16B16_UINT:		return TIF_MTLPixelFormatRGB16Uint;
//	case TinyImageFormat_R16G16B16_SINT:		return TIF_MTLPixelFormatRGB16Sint;
//	case TinyImageFormat_R16G16B16_SFLOAT:	return TIF_MTLPixelFormatRGB16Float;
	case TinyImageFormat_R16G16B16A16_UNORM:	return TIF_MTLPixelFormatRGBA16Unorm;
	case TinyImageFormat_R16G16B16A16_SNORM:	return TIF_MTLPixelFormatRGBA16Snorm;
	case TinyImageFormat_R16G16B16A16_USCALED:return TIF_MTLPixelFormatRGBA16Uint;
	case TinyImageFormat_R16G16B16A16_SSCALED:return TIF_MTLPixelFormatRGBA16Sint;
	case TinyImageFormat_R16G16B16A16_UINT:		return TIF_MTLPixelFormatRGBA16Uint;
	case TinyImageFormat_R16G16B16A16_SINT:		return TIF_MTLPixelFormatRGBA16Sint;
	case TinyImageFormat_R16G16B16A16_SFLOAT:	return TIF_MTLPixelFormatRGBA16Float;
	case TinyImageFormat_R32_UINT:						return TIF_MTLPixelFormatR32Uint;
	case TinyImageFormat_R32_SINT:						return TIF_MTLPixelFormatR32Sint;
	case TinyImageFormat_R32_SFLOAT:					return TIF_MTLPixelFormatR32Float;
	case TinyImageFormat_R32G32_UINT:					return TIF_MTLPixelFormatRG32Uint;
	case TinyImageFormat_R32G32_SINT:					return TIF_MTLPixelFormatRG32Sint;
	case TinyImageFormat_R32G32_SFLOAT:				return TIF_MTLPixelFormatRG32Float;
//	case TinyImageFormat_R32G32B32_UINT:			return TIF_MTLPixelFormatRGB32Uint;
//	case TinyImageFormat_R32G32B32_SINT:			return TIF_MTLPixelFormatRGB32Sint;
//	case TinyImageFormat_R32G32B32_SFLOAT:		return TIF_MTLPixelFormatRGB32Float;
	case TinyImageFormat_R32G32B32A32_UINT:		return TIF_MTLPixelFormatRGBA32Uint;
	case TinyImageFormat_R32G32B32A32_SINT:		return TIF_MTLPixelFormatRGBA32Sint;
	case TinyImageFormat_R32G32B32A32_SFLOAT:	return TIF_MTLPixelFormatRGBA32Float;
//	case TinyImageFormat_R64_UINT:
//	case TinyImageFormat_R64_SINT:
//	case TinyImageFormat_R64_SFLOAT:
//	case TinyImageFormat_R64G64_UINT:
//	case TinyImageFormat_R64G64_SINT:
//	case TinyImageFormat_R64G64_SFLOAT:
//	case TinyImageFormat_R64G64B64_UINT:
//	case TinyImageFormat_R64G64B64_SINT:
//	case TinyImageFormat_R64G64B64_SFLOAT:
//	case TinyImageFormat_R64G64B64A64_UINT:
//	case TinyImageFormat_R64G64B64A64_SINT:
//	case TinyImageFormat_R64G64B64A64_SFLOAT:
	case TinyImageFormat_B10G11R11_UFLOAT_PACK32: return TIF_MTLPixelFormatRG11B10Float;
	case TinyImageFormat_E5B9G9R9_UFLOAT_PACK32:	return TIF_MTLPixelFormatRGB9E5Float;
	case TinyImageFormat_D16_UNORM:								return TIF_MTLPixelFormatDepth16Unorm;
	case TinyImageFormat_X8_D24_UNORM_PACK32:			return TIF_MTLPixelFormatDepth24Unorm_Stencil8;
	case TinyImageFormat_D32_SFLOAT:							return TIF_MTLPixelFormatDepth32Float;
	case TinyImageFormat_S8_UINT:									return TIF_MTLPixelFormatStencil8;
//	case TinyImageFormat_D16_UNORM_S8_UINT:				return TIF_MTLPixelFormatDepth16;
	case TinyImageFormat_D24_UNORM_S8_UINT:				return TIF_MTLPixelFormatDepth24Unorm_Stencil8;
	case TinyImageFormat_D32_SFLOAT_S8_UINT:			return TIF_MTLPixelFormatDepth32Float_Stencil8;

	case TinyImageFormat_BC1_RGB_UNORM_BLOCK:			return TIF_MTLPixelFormatBC1_RGBA;
	case TinyImageFormat_BC1_RGB_SRGB_BLOCK:			return TIF_MTLPixelFormatBC1_RGBA_sRGB;
	case TinyImageFormat_BC1_RGBA_UNORM_BLOCK:		return TIF_MTLPixelFormatBC1_RGBA;
	case TinyImageFormat_BC1_RGBA_SRGB_BLOCK:			return TIF_MTLPixelFormatBC1_RGBA_sRGB;
	case TinyImageFormat_BC2_UNORM_BLOCK:					return TIF_MTLPixelFormatBC2_RGBA;
	case TinyImageFormat_BC2_SRGB_BLOCK:					return TIF_MTLPixelFormatBC2_RGBA_sRGB;
	case TinyImageFormat_BC3_UNORM_BLOCK:					return TIF_MTLPixelFormatBC3_RGBA;
	case TinyImageFormat_BC3_SRGB_BLOCK:					return TIF_MTLPixelFormatBC3_RGBA_sRGB;
	case TinyImageFormat_BC4_UNORM_BLOCK:					return TIF_MTLPixelFormatBC4_RUnorm;
	case TinyImageFormat_BC4_SNORM_BLOCK:					return TIF_MTLPixelFormatBC4_RSnorm;
	case TinyImageFormat_BC5_UNORM_BLOCK:					return TIF_MTLPixelFormatBC5_RGUnorm;
	case TinyImageFormat_BC5_SNORM_BLOCK:					return TIF_MTLPixelFormatBC5_RGSnorm;
	case TinyImageFormat_BC6H_UFLOAT_BLOCK:				return TIF_MTLPixelFormatBC6H_RGBUfloat;
	case TinyImageFormat_BC6H_SFLOAT_BLOCK:				return TIF_MTLPixelFormatBC6H_RGBFloat;
	case TinyImageFormat_BC7_UNORM_BLOCK:					return TIF_MTLPixelFormatBC7_RGBAUnorm;
	case TinyImageFormat_BC7_SRGB_BLOCK:					return TIF_MTLPixelFormatBC7_RGBAUnorm_sRGB;
	case TinyImageFormat_PVR_2BPP_UNORM_BLOCK:		return TIF_MTLPixelFormatPVRTC_RGB_2BPP;
	case TinyImageFormat_PVR_2BPPA_UNORM_BLOCK:		return TIF_MTLPixelFormatPVRTC_RGBA_2BPP;
	case TinyImageFormat_PVR_4BPP_UNORM_BLOCK:		return TIF_MTLPixelFormatPVRTC_RGB_4BPP;
	case TinyImageFormat_PVR_4BPPA_UNORM_BLOCK:		return TIF_MTLPixelFormatPVRTC_RGBA_4BPP;
	case TinyImageFormat_PVR_2BPP_SRGB_BLOCK:			return TIF_MTLPixelFormatPVRTC_RGB_2BPP_sRGB;
	case TinyImageFormat_PVR_2BPPA_SRGB_BLOCK:		return TIF_MTLPixelFormatPVRTC_RGBA_2BPP_sRGB;
	case TinyImageFormat_PVR_4BPP_SRGB_BLOCK:			return TIF_MTLPixelFormatPVRTC_RGB_4BPP_sRGB;
	case TinyImageFormat_PVR_4BPPA_SRGB_BLOCK:		return TIF_MTLPixelFormatPVRTC_RGBA_4BPP_sRGB;
	case TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK:	return TIF_MTLPixelFormatETC2_RGB8;
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:return TIF_MTLPixelFormatETC2_RGB8A1;
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK: return TIF_MTLPixelFormatEAC_RGBA8;
	case TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK:		return TIF_MTLPixelFormatETC2_RGB8_sRGB;
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:	return TIF_MTLPixelFormatETC2_RGB8A1_sRGB;
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:	return TIF_MTLPixelFormatEAC_RGBA8_sRGB;
	case TinyImageFormat_EAC_R11_UNORM_BLOCK:				return TIF_MTLPixelFormatEAC_R11Unorm;
	case TinyImageFormat_EAC_R11G11_UNORM_BLOCK:		return TIF_MTLPixelFormatEAC_RG11Unorm;
	case TinyImageFormat_EAC_R11_SNORM_BLOCK:				return TIF_MTLPixelFormatEAC_R11Snorm;
	case TinyImageFormat_EAC_R11G11_SNORM_BLOCK:		return TIF_MTLPixelFormatEAC_RG11Snorm;
	case TinyImageFormat_ASTC_4x4_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_4x4_LDR;
	case TinyImageFormat_ASTC_4x4_SRGB_BLOCK:				return TIF_MTLPixelFormatASTC_4x4_sRGB;
	case TinyImageFormat_ASTC_5x4_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_5x4_LDR;
	case TinyImageFormat_ASTC_5x4_SRGB_BLOCK:				return TIF_MTLPixelFormatASTC_5x4_sRGB;
	case TinyImageFormat_ASTC_5x5_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_5x5_LDR;
	case TinyImageFormat_ASTC_5x5_SRGB_BLOCK:				return TIF_MTLPixelFormatASTC_5x5_sRGB;
	case TinyImageFormat_ASTC_6x5_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_6x5_LDR;
	case TinyImageFormat_ASTC_6x5_SRGB_BLOCK:				return TIF_MTLPixelFormatASTC_6x5_sRGB;
	case TinyImageFormat_ASTC_6x6_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_6x6_LDR;
	case TinyImageFormat_ASTC_6x6_SRGB_BLOCK:				return TIF_MTLPixelFormatASTC_6x6_sRGB;
	case TinyImageFormat_ASTC_8x5_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_8x5_LDR;
	case TinyImageFormat_ASTC_8x5_SRGB_BLOCK:				return TIF_MTLPixelFormatASTC_8x5_sRGB;
	case TinyImageFormat_ASTC_8x6_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_8x6_LDR;
	case TinyImageFormat_ASTC_8x6_SRGB_BLOCK:				return TIF_MTLPixelFormatASTC_8x6_sRGB;
	case TinyImageFormat_ASTC_8x8_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_8x8_LDR;
	case TinyImageFormat_ASTC_8x8_SRGB_BLOCK:				return TIF_MTLPixelFormatASTC_8x8_sRGB;
	case TinyImageFormat_ASTC_10x5_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_10x5_LDR;
	case TinyImageFormat_ASTC_10x5_SRGB_BLOCK:			return TIF_MTLPixelFormatASTC_10x5_sRGB;
	case TinyImageFormat_ASTC_10x6_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_10x6_LDR;
	case TinyImageFormat_ASTC_10x6_SRGB_BLOCK:			return TIF_MTLPixelFormatASTC_10x6_sRGB;
	case TinyImageFormat_ASTC_10x8_UNORM_BLOCK:			return TIF_MTLPixelFormatASTC_10x8_LDR;
	case TinyImageFormat_ASTC_10x8_SRGB_BLOCK:			return TIF_MTLPixelFormatASTC_10x8_sRGB;
	case TinyImageFormat_ASTC_10x10_UNORM_BLOCK:		return TIF_MTLPixelFormatASTC_10x10_LDR;
	case TinyImageFormat_ASTC_10x10_SRGB_BLOCK:			return TIF_MTLPixelFormatASTC_10x10_sRGB;
	case TinyImageFormat_ASTC_12x10_UNORM_BLOCK:		return TIF_MTLPixelFormatASTC_12x10_LDR;
	case TinyImageFormat_ASTC_12x10_SRGB_BLOCK:			return TIF_MTLPixelFormatASTC_12x10_sRGB;
	case TinyImageFormat_ASTC_12x12_UNORM_BLOCK:		return TIF_MTLPixelFormatASTC_12x12_LDR;
	case TinyImageFormat_ASTC_12x12_SRGB_BLOCK:			return TIF_MTLPixelFormatASTC_12x12_sRGB;
	default:
		return TIF_MTLPixelFormatInvalid;
	}

}
AL2O3_EXTERN_C TinyImageFormat TinyImageFormat_FromMTLPixelFormat(TinyImageFormat_MTLPixelFormat fmt) {
	switch (fmt) {
	case TIF_MTLPixelFormatA8Unorm: return TinyImageFormat_A8_UNORM;
	case TIF_MTLPixelFormatR8Unorm: return TinyImageFormat_R8_UNORM;
	case TIF_MTLPixelFormatR8Unorm_sRGB: return TinyImageFormat_R8_SRGB;
	case TIF_MTLPixelFormatR8Snorm: return TinyImageFormat_R8_SNORM;
	case TIF_MTLPixelFormatR8Uint: return TinyImageFormat_R8_UINT;
	case TIF_MTLPixelFormatR8Sint: return TinyImageFormat_R8_SINT;
	case TIF_MTLPixelFormatR16Unorm: return TinyImageFormat_R16_UNORM;
	case TIF_MTLPixelFormatR16Snorm: return TinyImageFormat_R16_SNORM;
	case TIF_MTLPixelFormatR16Uint: return TinyImageFormat_R16_UINT;
	case TIF_MTLPixelFormatR16Sint: return TinyImageFormat_R16_SINT;
	case TIF_MTLPixelFormatR16Float: return TinyImageFormat_R16_SFLOAT;
	case TIF_MTLPixelFormatRG8Unorm: return TinyImageFormat_R8G8B8_UNORM;
	case TIF_MTLPixelFormatRG8Unorm_sRGB: return TinyImageFormat_R8G8_SRGB;
	case TIF_MTLPixelFormatRG8Snorm: return TinyImageFormat_R8G8_SNORM;
	case TIF_MTLPixelFormatRG8Uint: return TinyImageFormat_R8G8_UINT;
	case TIF_MTLPixelFormatRG8Sint: return TinyImageFormat_R8G8_SINT;
	case TIF_MTLPixelFormatB5G6R5Unorm: return TinyImageFormat_R5G6B5_UNORM_PACK16;
	case TIF_MTLPixelFormatA1BGR5Unorm: return TinyImageFormat_R5G5B5A1_UNORM_PACK16;
	case TIF_MTLPixelFormatABGR4Unorm: return TinyImageFormat_R4G4B4A4_UNORM_PACK16;
	case TIF_MTLPixelFormatBGR5A1Unorm: return TinyImageFormat_A1R5G5B5_UNORM_PACK16;
	case TIF_MTLPixelFormatR32Uint: return TinyImageFormat_R32_UINT;
	case TIF_MTLPixelFormatR32Sint: return TinyImageFormat_R32_SINT;
	case TIF_MTLPixelFormatR32Float: return TinyImageFormat_R32_SFLOAT;
	case TIF_MTLPixelFormatRG16Unorm: return TinyImageFormat_R16G16_UNORM;
	case TIF_MTLPixelFormatRG16Snorm: return TinyImageFormat_R16G16_SNORM;
	case TIF_MTLPixelFormatRG16Uint: return TinyImageFormat_R16G16B16_UINT;
	case TIF_MTLPixelFormatRG16Sint: return TinyImageFormat_R16G16_SINT;
	case TIF_MTLPixelFormatRG16Float: return TinyImageFormat_R16G16_SFLOAT;
	case TIF_MTLPixelFormatRGBA8Unorm: return TinyImageFormat_R8G8B8A8_UNORM;
	case TIF_MTLPixelFormatRGBA8Unorm_sRGB: return TinyImageFormat_R8G8B8A8_SRGB;
	case TIF_MTLPixelFormatRGBA8Snorm: return TinyImageFormat_R8G8B8A8_SNORM;
	case TIF_MTLPixelFormatRGBA8Uint: return TinyImageFormat_R8G8B8A8_UINT;
	case TIF_MTLPixelFormatRGBA8Sint: return TinyImageFormat_R8G8B8A8_SINT;
	case TIF_MTLPixelFormatBGRA8Unorm: return TinyImageFormat_A8R8G8B8_UNORM_PACK32;
//	case TIF_MTLPixelFormatBGRA8Unorm_sRGB: return TinyImageFormat_
	case TIF_MTLPixelFormatRGB10A2Unorm: return TinyImageFormat_A2B10G10R10_UNORM_PACK32;
	case TIF_MTLPixelFormatRGB10A2Uint: return TinyImageFormat_A2B10G10R10_UINT_PACK32;
	case TIF_MTLPixelFormatRG11B10Float: return TinyImageFormat_B10G11R11_UFLOAT_PACK32;
	case TIF_MTLPixelFormatRGB9E5Float: return TinyImageFormat_E5B9G9R9_UFLOAT_PACK32;
	case TIF_MTLPixelFormatBGR10A2Unorm: return TinyImageFormat_A2R10G10B10_UNORM_PACK32;
//	case TIF_MTLPixelFormatBGR10_XR: return TinyImageFormat_
//	case TIF_MTLPixelFormatBGR10_XR_sRGB: return TinyImageFormat_
	case TIF_MTLPixelFormatRG32Uint: return TinyImageFormat_R32G32_UINT;
	case TIF_MTLPixelFormatRG32Sint: return TinyImageFormat_R32G32_SINT;
	case TIF_MTLPixelFormatRG32Float: return TinyImageFormat_R32G32_SFLOAT;
	case TIF_MTLPixelFormatRGBA16Unorm: return TinyImageFormat_R16G16B16A16_UNORM;
	case TIF_MTLPixelFormatRGBA16Snorm: return TinyImageFormat_R16G16B16A16_SNORM;
	case TIF_MTLPixelFormatRGBA16Uint: return TinyImageFormat_R16G16B16A16_UINT;
	case TIF_MTLPixelFormatRGBA16Sint: return TinyImageFormat_R16G16B16A16_SINT;
	case TIF_MTLPixelFormatRGBA16Float: return TinyImageFormat_R16G16B16A16_SFLOAT;
//	case TIF_MTLPixelFormatBGRA10_XR: return TinyImageFormat_
//	case TIF_MTLPixelFormatBGRA10_XR_sRGB: return TinyImageFormat_
	case TIF_MTLPixelFormatRGBA32Uint: return TinyImageFormat_R32G32B32A32_UINT;
	case TIF_MTLPixelFormatRGBA32Sint: return TinyImageFormat_R32G32B32A32_SINT;
	case TIF_MTLPixelFormatRGBA32Float: return TinyImageFormat_R32G32B32A32_SFLOAT;
	case TIF_MTLPixelFormatBC1_RGBA: return TinyImageFormat_BC1_RGBA_SRGB_BLOCK;
	case TIF_MTLPixelFormatBC1_RGBA_sRGB: return TinyImageFormat_BC1_RGBA_SRGB_BLOCK;
	case TIF_MTLPixelFormatBC2_RGBA: return TinyImageFormat_BC2_UNORM_BLOCK;
	case TIF_MTLPixelFormatBC2_RGBA_sRGB: return TinyImageFormat_BC2_SRGB_BLOCK;
	case TIF_MTLPixelFormatBC3_RGBA: return TinyImageFormat_BC3_UNORM_BLOCK;
	case TIF_MTLPixelFormatBC3_RGBA_sRGB: return TinyImageFormat_BC2_SRGB_BLOCK;
	case TIF_MTLPixelFormatBC4_RUnorm: return TinyImageFormat_BC4_UNORM_BLOCK;
	case TIF_MTLPixelFormatBC4_RSnorm: return TinyImageFormat_BC4_SNORM_BLOCK;
	case TIF_MTLPixelFormatBC5_RGUnorm: return TinyImageFormat_BC5_UNORM_BLOCK;
	case TIF_MTLPixelFormatBC5_RGSnorm: return TinyImageFormat_BC5_SNORM_BLOCK;
	case TIF_MTLPixelFormatBC6H_RGBFloat: return TinyImageFormat_BC6H_SFLOAT_BLOCK;
	case TIF_MTLPixelFormatBC6H_RGBUfloat: return TinyImageFormat_BC6H_UFLOAT_BLOCK;
	case TIF_MTLPixelFormatBC7_RGBAUnorm: return TinyImageFormat_BC7_UNORM_BLOCK;
	case TIF_MTLPixelFormatBC7_RGBAUnorm_sRGB: return TinyImageFormat_BC7_SRGB_BLOCK;
	case TIF_MTLPixelFormatPVRTC_RGB_2BPP: return TinyImageFormat_PVR_2BPP_UNORM_BLOCK;
	case TIF_MTLPixelFormatPVRTC_RGB_2BPP_sRGB: return TinyImageFormat_PVR_2BPP_SRGB_BLOCK;
	case TIF_MTLPixelFormatPVRTC_RGB_4BPP: return TinyImageFormat_PVR_4BPP_UNORM_BLOCK;
	case TIF_MTLPixelFormatPVRTC_RGB_4BPP_sRGB: return TinyImageFormat_PVR_4BPP_SRGB_BLOCK;
	case TIF_MTLPixelFormatPVRTC_RGBA_2BPP: return TinyImageFormat_PVR_2BPPA_UNORM_BLOCK;
	case TIF_MTLPixelFormatPVRTC_RGBA_2BPP_sRGB: return TinyImageFormat_PVR_2BPPA_SRGB_BLOCK;
	case TIF_MTLPixelFormatPVRTC_RGBA_4BPP: return TinyImageFormat_PVR_4BPPA_UNORM_BLOCK;
	case TIF_MTLPixelFormatPVRTC_RGBA_4BPP_sRGB: return TinyImageFormat_PVR_4BPPA_SRGB_BLOCK;
	case TIF_MTLPixelFormatEAC_R11Unorm: return TinyImageFormat_EAC_R11_UNORM_BLOCK;
	case TIF_MTLPixelFormatEAC_R11Snorm: return TinyImageFormat_EAC_R11_SNORM_BLOCK;
	case TIF_MTLPixelFormatEAC_RG11Unorm: return TinyImageFormat_EAC_R11G11_UNORM_BLOCK;
	case TIF_MTLPixelFormatEAC_RG11Snorm: return TinyImageFormat_EAC_R11G11_SNORM_BLOCK;
	case TIF_MTLPixelFormatEAC_RGBA8: return TinyImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK;
	case TIF_MTLPixelFormatEAC_RGBA8_sRGB: return TinyImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK;
	case TIF_MTLPixelFormatETC2_RGB8: return TinyImageFormat_ETC2_R8G8B8_UNORM_BLOCK;
	case TIF_MTLPixelFormatETC2_RGB8_sRGB: return TinyImageFormat_ETC2_R8G8B8_SRGB_BLOCK;
	case TIF_MTLPixelFormatETC2_RGB8A1: return TinyImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK;
	case TIF_MTLPixelFormatETC2_RGB8A1_sRGB: return TinyImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_4x4_sRGB:			return TinyImageFormat_ASTC_4x4_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_5x4_sRGB:			return TinyImageFormat_ASTC_5x4_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_5x5_sRGB:			return TinyImageFormat_ASTC_5x4_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_6x5_sRGB:			return TinyImageFormat_ASTC_6x5_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_6x6_sRGB:			return TinyImageFormat_ASTC_6x6_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_8x5_sRGB:			return TinyImageFormat_ASTC_8x5_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_8x6_sRGB:			return TinyImageFormat_ASTC_8x6_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_8x8_sRGB:			return TinyImageFormat_ASTC_8x8_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_10x5_sRGB:		return TinyImageFormat_ASTC_10x5_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_10x6_sRGB:		return TinyImageFormat_ASTC_10x6_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_10x8_sRGB:		return TinyImageFormat_ASTC_10x8_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_10x10_sRGB: 	return TinyImageFormat_ASTC_10x10_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_12x10_sRGB: 	return TinyImageFormat_ASTC_12x10_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_12x12_sRGB: 	return TinyImageFormat_ASTC_12x12_SRGB_BLOCK;
	case TIF_MTLPixelFormatASTC_4x4_LDR: 		return TinyImageFormat_ASTC_4x4_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_5x4_LDR: 		return TinyImageFormat_ASTC_5x4_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_5x5_LDR: 		return TinyImageFormat_ASTC_5x4_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_6x5_LDR: 		return TinyImageFormat_ASTC_6x5_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_6x6_LDR: 		return TinyImageFormat_ASTC_6x6_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_8x5_LDR: 		return TinyImageFormat_ASTC_8x5_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_8x6_LDR: 		return TinyImageFormat_ASTC_8x6_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_8x8_LDR: 		return TinyImageFormat_ASTC_8x8_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_10x5_LDR:		return TinyImageFormat_ASTC_10x5_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_10x6_LDR:		return TinyImageFormat_ASTC_10x6_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_10x8_LDR:		return TinyImageFormat_ASTC_10x8_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_10x10_LDR: 	return TinyImageFormat_ASTC_10x10_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_12x10_LDR: 	return TinyImageFormat_ASTC_12x10_UNORM_BLOCK;
	case TIF_MTLPixelFormatASTC_12x12_LDR: 	return TinyImageFormat_ASTC_12x12_UNORM_BLOCK;
//	case TIF_MTLPixelFormatGBGR422: return TinyImageFormat_
//	case TIF_MTLPixelFormatBGRG422: return TinyImageFormat_
	case TIF_MTLPixelFormatDepth16Unorm: return TinyImageFormat_D16_UNORM;
	case TIF_MTLPixelFormatDepth32Float: return TinyImageFormat_D32_SFLOAT;
	case TIF_MTLPixelFormatStencil8: return TinyImageFormat_S8_UINT;
	case TIF_MTLPixelFormatDepth24Unorm_Stencil8: return TinyImageFormat_D24_UNORM_S8_UINT;
	case TIF_MTLPixelFormatDepth32Float_Stencil8: return TinyImageFormat_D32_SFLOAT_S8_UINT;
	case TIF_MTLPixelFormatX32_Stencil8: return TinyImageFormat_D32_SFLOAT_S8_UINT;
	case TIF_MTLPixelFormatX24_Stencil8: return TinyImageFormat_D24_UNORM_S8_UINT;

	default:
	case TIF_MTLPixelFormatInvalid: return TinyImageFormat_UNDEFINED;
	}
}

#endif

#endif //TINYIMAGEFORMAT_IMAGEFORMAT_H
