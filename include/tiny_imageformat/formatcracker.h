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


AL2O3_EXTERN_C char const *ImageFormat_Name(ImageFormat const fmt);
AL2O3_EXTERN_C ImageFormat ImageFormat_FromName(char const *name);

#ifdef __cplusplus
constexpr size_t ImageFormat_Count() {
	size_t count = 0;
#define IF_START_MACRO
#define IF_MOD_MACRO(x) count++;
#define IF_END_MACRO
#include "tiny_imageformat/format.h"
	return count;
}
#else
AL2O3_EXTERN_C size_t ImageFormat_Count();
#endif

AL2O3_EXTERN_C inline bool ImageFormat_IsDepth(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_D16_UNORM:
	case ImageFormat_X8_D24_UNORM_PACK32:
	case ImageFormat_D32_SFLOAT:
	case ImageFormat_D16_UNORM_S8_UINT:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_D32_SFLOAT_S8_UINT:return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool ImageFormat_IsStencil(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_S8_UINT:
	case ImageFormat_D16_UNORM_S8_UINT:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_D32_SFLOAT_S8_UINT:return true;
	default:return false;
	}
}

//! is this texture format a depth stencil format?
AL2O3_EXTERN_C inline bool ImageFormat_IsDepthStencil(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_D16_UNORM_S8_UINT:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_D32_SFLOAT_S8_UINT:return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool ImageFormat_IsFloat(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_R16_SFLOAT:
	case ImageFormat_R16G16_SFLOAT:
	case ImageFormat_R16G16B16_SFLOAT:
	case ImageFormat_R16G16B16A16_SFLOAT:
	case ImageFormat_R32_SFLOAT:
	case ImageFormat_R32G32_SFLOAT:
	case ImageFormat_R32G32B32_SFLOAT:
	case ImageFormat_R32G32B32A32_SFLOAT:
	case ImageFormat_R64_SFLOAT:
	case ImageFormat_R64G64_SFLOAT:
	case ImageFormat_R64G64B64_SFLOAT:
	case ImageFormat_R64G64B64A64_SFLOAT:
	case ImageFormat_D32_SFLOAT:
	case ImageFormat_D32_SFLOAT_S8_UINT:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:
	case ImageFormat_E5B9G9R9_UFLOAT_PACK32:
	case ImageFormat_B10G11R11_UFLOAT_PACK32:
		return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool ImageFormat_IsNormalised(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_R4G4_UNORM_PACK8:
	case ImageFormat_R4G4B4A4_UNORM_PACK16:
	case ImageFormat_B4G4R4A4_UNORM_PACK16:
	case ImageFormat_R5G6B5_UNORM_PACK16:
	case ImageFormat_B5G6R5_UNORM_PACK16:
	case ImageFormat_R5G5B5A1_UNORM_PACK16:
	case ImageFormat_B5G5R5A1_UNORM_PACK16:
	case ImageFormat_A1R5G5B5_UNORM_PACK16:
	case ImageFormat_R8_UNORM:
	case ImageFormat_R8_SNORM:
	case ImageFormat_R8G8_UNORM:
	case ImageFormat_R8G8_SNORM:
	case ImageFormat_R8G8B8_UNORM:
	case ImageFormat_R8G8B8_SNORM:
	case ImageFormat_B8G8R8_UNORM:
	case ImageFormat_B8G8R8_SNORM:
	case ImageFormat_R8G8B8A8_UNORM:
	case ImageFormat_R8G8B8A8_SNORM:
	case ImageFormat_B8G8R8A8_UNORM:
	case ImageFormat_B8G8R8A8_SNORM:
	case ImageFormat_A8B8G8R8_UNORM_PACK32:
	case ImageFormat_A8B8G8R8_SNORM_PACK32:
	case ImageFormat_A2R10G10B10_UNORM_PACK32:
	case ImageFormat_A2B10G10R10_UNORM_PACK32:
	case ImageFormat_R16_UNORM:
	case ImageFormat_R16_SNORM:
	case ImageFormat_R16G16_UNORM:
	case ImageFormat_R16G16_SNORM:
	case ImageFormat_R16G16B16_UNORM:
	case ImageFormat_R16G16B16_SNORM:
	case ImageFormat_R16G16B16A16_UNORM:
	case ImageFormat_R16G16B16A16_SNORM:
	case ImageFormat_X8_D24_UNORM_PACK32:
	case ImageFormat_D16_UNORM:
	case ImageFormat_D16_UNORM_S8_UINT:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:

	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:

	case ImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case ImageFormat_EAC_R11_UNORM_BLOCK:
	case ImageFormat_EAC_R11G11_UNORM_BLOCK:
	case ImageFormat_EAC_R11_SNORM_BLOCK:
	case ImageFormat_EAC_R11G11_SNORM_BLOCK:

	case ImageFormat_ASTC_4x4_UNORM_BLOCK:
	case ImageFormat_ASTC_5x4_UNORM_BLOCK:
	case ImageFormat_ASTC_5x5_UNORM_BLOCK:
	case ImageFormat_ASTC_6x5_UNORM_BLOCK:
	case ImageFormat_ASTC_6x6_UNORM_BLOCK:
	case ImageFormat_ASTC_8x5_UNORM_BLOCK:
	case ImageFormat_ASTC_8x6_UNORM_BLOCK:
	case ImageFormat_ASTC_8x8_UNORM_BLOCK:
	case ImageFormat_ASTC_10x5_UNORM_BLOCK:
	case ImageFormat_ASTC_10x6_UNORM_BLOCK:
	case ImageFormat_ASTC_10x8_UNORM_BLOCK:
	case ImageFormat_ASTC_10x10_UNORM_BLOCK:
	case ImageFormat_ASTC_12x10_UNORM_BLOCK:
	case ImageFormat_ASTC_12x12_UNORM_BLOCK:

	case ImageFormat_A4R4G4B4_UNORM_PACK16:
	case ImageFormat_A8R8G8B8_UNORM_PACK32:
		return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool ImageFormat_IsSigned(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_R8_SNORM:
	case ImageFormat_R8_SSCALED:
	case ImageFormat_R8_SINT:
	case ImageFormat_R8G8_SNORM:
	case ImageFormat_R8G8_SSCALED:
	case ImageFormat_R8G8_SINT:
	case ImageFormat_R8G8B8_SNORM:
	case ImageFormat_R8G8B8_SSCALED:
	case ImageFormat_R8G8B8_SINT:
	case ImageFormat_B8G8R8_SNORM:
	case ImageFormat_B8G8R8_SINT:
	case ImageFormat_B8G8R8_SSCALED:
	case ImageFormat_R8G8B8A8_SNORM:
	case ImageFormat_R8G8B8A8_SINT:
	case ImageFormat_R8G8B8A8_SSCALED:
	case ImageFormat_B8G8R8A8_SNORM:
	case ImageFormat_B8G8R8A8_SINT:
	case ImageFormat_B8G8R8A8_SSCALED:
	case ImageFormat_A8B8G8R8_SNORM_PACK32:
	case ImageFormat_A8B8G8R8_SINT_PACK32:
	case ImageFormat_A8B8G8R8_SSCALED_PACK32:
	case ImageFormat_R16_SNORM:
	case ImageFormat_R16_SINT:
	case ImageFormat_R16_SSCALED:
	case ImageFormat_R16_SFLOAT:
	case ImageFormat_R16G16_SNORM:
	case ImageFormat_R16G16_SINT:
	case ImageFormat_R16G16_SSCALED:
	case ImageFormat_R16G16_SFLOAT:
	case ImageFormat_R16G16B16_SNORM:
	case ImageFormat_R16G16B16_SINT:
	case ImageFormat_R16G16B16_SSCALED:
	case ImageFormat_R16G16B16_SFLOAT:
	case ImageFormat_R16G16B16A16_SNORM:
	case ImageFormat_R16G16B16A16_SINT:
	case ImageFormat_R16G16B16A16_SSCALED:
	case ImageFormat_R16G16B16A16_SFLOAT:
	case ImageFormat_R32_SINT:
	case ImageFormat_R32_SFLOAT:
	case ImageFormat_R32G32_SINT:
	case ImageFormat_R32G32_SFLOAT:
	case ImageFormat_R32G32B32_SINT:
	case ImageFormat_R32G32B32_SFLOAT:
	case ImageFormat_R32G32B32A32_SINT:
	case ImageFormat_R32G32B32A32_SFLOAT:
	case ImageFormat_R64_SINT:
	case ImageFormat_R64_SFLOAT:
	case ImageFormat_R64G64_SINT:
	case ImageFormat_R64G64_SFLOAT:
	case ImageFormat_R64G64B64_SINT:
	case ImageFormat_R64G64B64_SFLOAT:
	case ImageFormat_R64G64B64A64_SINT:
	case ImageFormat_R64G64B64A64_SFLOAT:
	case ImageFormat_D32_SFLOAT:
	case ImageFormat_D32_SFLOAT_S8_UINT:
	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:
	case ImageFormat_EAC_R11_SNORM_BLOCK:
	case ImageFormat_EAC_R11G11_SNORM_BLOCK:

		return true;

	default: return false;
	}
}
AL2O3_EXTERN_C inline bool ImageFormat_IsSRGB(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_R8_SRGB:
	case ImageFormat_R8G8_SRGB:
	case ImageFormat_R8G8B8_SRGB:
	case ImageFormat_B8G8R8_SRGB:
	case ImageFormat_R8G8B8A8_SRGB:
	case ImageFormat_B8G8R8A8_SRGB:
	case ImageFormat_A8B8G8R8_SRGB_PACK32:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case ImageFormat_ASTC_4x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x5_SRGB_BLOCK:
	case ImageFormat_ASTC_8x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x5_SRGB_BLOCK:
	case ImageFormat_ASTC_10x6_SRGB_BLOCK:
	case ImageFormat_ASTC_10x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x12_SRGB_BLOCK: return true;

	default: return false;
	}
}

AL2O3_EXTERN_C inline bool ImageFormat_IsCompressed(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:

	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:

	case ImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case ImageFormat_EAC_R11_UNORM_BLOCK:
	case ImageFormat_EAC_R11G11_UNORM_BLOCK:
	case ImageFormat_EAC_R11_SNORM_BLOCK:
	case ImageFormat_EAC_R11G11_SNORM_BLOCK:

	case ImageFormat_ASTC_4x4_UNORM_BLOCK:
	case ImageFormat_ASTC_4x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x4_UNORM_BLOCK:
	case ImageFormat_ASTC_5x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x5_UNORM_BLOCK:
	case ImageFormat_ASTC_5x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x5_UNORM_BLOCK:
	case ImageFormat_ASTC_6x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x6_UNORM_BLOCK:
	case ImageFormat_ASTC_6x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x5_UNORM_BLOCK:
	case ImageFormat_ASTC_8x5_SRGB_BLOCK:
	case ImageFormat_ASTC_8x6_UNORM_BLOCK:
	case ImageFormat_ASTC_8x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x8_UNORM_BLOCK:
	case ImageFormat_ASTC_8x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x5_UNORM_BLOCK:
	case ImageFormat_ASTC_10x5_SRGB_BLOCK:
	case ImageFormat_ASTC_10x6_UNORM_BLOCK:
	case ImageFormat_ASTC_10x6_SRGB_BLOCK:
	case ImageFormat_ASTC_10x8_UNORM_BLOCK:
	case ImageFormat_ASTC_10x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x10_UNORM_BLOCK:
	case ImageFormat_ASTC_10x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x10_UNORM_BLOCK:
	case ImageFormat_ASTC_12x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x12_UNORM_BLOCK:
	case ImageFormat_ASTC_12x12_SRGB_BLOCK:
		return true;

	default:return false;
	}
}

AL2O3_EXTERN_C inline uint32_t ImageFormat_WidthOfBlock(ImageFormat const fmt) {
	ASSERT(ImageFormat_IsCompressed(fmt));

	switch (fmt) {
	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case ImageFormat_EAC_R11_UNORM_BLOCK:
	case ImageFormat_EAC_R11G11_UNORM_BLOCK:
	case ImageFormat_EAC_R11_SNORM_BLOCK:
	case ImageFormat_EAC_R11G11_SNORM_BLOCK: return 4;
	case ImageFormat_ASTC_4x4_UNORM_BLOCK:
	case ImageFormat_ASTC_4x4_SRGB_BLOCK: return 4;
	case ImageFormat_ASTC_5x4_UNORM_BLOCK:
	case ImageFormat_ASTC_5x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x5_UNORM_BLOCK:
	case ImageFormat_ASTC_5x5_SRGB_BLOCK: return 5;
	case ImageFormat_ASTC_6x5_UNORM_BLOCK:
	case ImageFormat_ASTC_6x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x6_UNORM_BLOCK:
	case ImageFormat_ASTC_6x6_SRGB_BLOCK: return 6;
	case ImageFormat_ASTC_8x5_UNORM_BLOCK:
	case ImageFormat_ASTC_8x5_SRGB_BLOCK:
	case ImageFormat_ASTC_8x6_UNORM_BLOCK:
	case ImageFormat_ASTC_8x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x8_UNORM_BLOCK:
	case ImageFormat_ASTC_8x8_SRGB_BLOCK: return 8;
	case ImageFormat_ASTC_10x5_UNORM_BLOCK:
	case ImageFormat_ASTC_10x5_SRGB_BLOCK:
	case ImageFormat_ASTC_10x6_UNORM_BLOCK:
	case ImageFormat_ASTC_10x6_SRGB_BLOCK:
	case ImageFormat_ASTC_10x8_UNORM_BLOCK:
	case ImageFormat_ASTC_10x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x10_UNORM_BLOCK:
	case ImageFormat_ASTC_10x10_SRGB_BLOCK: return 10;
	case ImageFormat_ASTC_12x10_UNORM_BLOCK:
	case ImageFormat_ASTC_12x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x12_UNORM_BLOCK:
	case ImageFormat_ASTC_12x12_SRGB_BLOCK: return 12;

	default: ASSERT(false);
		return 0;
	}
}

AL2O3_EXTERN_C inline uint32_t ImageFormat_HeightOfBlock(ImageFormat const fmt) {
	ASSERT(ImageFormat_IsCompressed(fmt));

	switch (fmt) {
	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:

	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case ImageFormat_EAC_R11_UNORM_BLOCK:
	case ImageFormat_EAC_R11G11_UNORM_BLOCK:
	case ImageFormat_EAC_R11_SNORM_BLOCK:
	case ImageFormat_EAC_R11G11_SNORM_BLOCK: return 4;
	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK: return 8;

	case ImageFormat_ASTC_4x4_UNORM_BLOCK:
	case ImageFormat_ASTC_4x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x4_UNORM_BLOCK:
	case ImageFormat_ASTC_5x4_SRGB_BLOCK: return 4;

	case ImageFormat_ASTC_5x5_UNORM_BLOCK:
	case ImageFormat_ASTC_5x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x5_UNORM_BLOCK:
	case ImageFormat_ASTC_6x5_SRGB_BLOCK:
	case ImageFormat_ASTC_8x5_UNORM_BLOCK:
	case ImageFormat_ASTC_8x5_SRGB_BLOCK:
	case ImageFormat_ASTC_10x5_UNORM_BLOCK:
	case ImageFormat_ASTC_10x5_SRGB_BLOCK: return 5;

	case ImageFormat_ASTC_6x6_UNORM_BLOCK:
	case ImageFormat_ASTC_6x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x6_UNORM_BLOCK:
	case ImageFormat_ASTC_8x6_SRGB_BLOCK:
	case ImageFormat_ASTC_10x6_UNORM_BLOCK:
	case ImageFormat_ASTC_10x6_SRGB_BLOCK: return 6;

	case ImageFormat_ASTC_8x8_UNORM_BLOCK:
	case ImageFormat_ASTC_8x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x8_UNORM_BLOCK:
	case ImageFormat_ASTC_10x8_SRGB_BLOCK: return 8;

	case ImageFormat_ASTC_10x10_UNORM_BLOCK:
	case ImageFormat_ASTC_10x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x10_UNORM_BLOCK:
	case ImageFormat_ASTC_12x10_SRGB_BLOCK: return 10;

	case ImageFormat_ASTC_12x12_UNORM_BLOCK:
	case ImageFormat_ASTC_12x12_SRGB_BLOCK: return 12;

	default: ASSERT(false);
		return 0;
	}
}

AL2O3_EXTERN_C inline uint32_t ImageFormat_PixelCountOfBlock(ImageFormat const fmt) {
	return ImageFormat_WidthOfBlock(fmt) * ImageFormat_HeightOfBlock(fmt);
}

AL2O3_EXTERN_C inline uint32_t ImageFormat_BitSizeOfBlock(ImageFormat const fmt) {
	ASSERT(ImageFormat_IsCompressed(fmt));

	switch (fmt) {
	case ImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case ImageFormat_EAC_R11_UNORM_BLOCK:
	case ImageFormat_EAC_R11G11_UNORM_BLOCK:
	case ImageFormat_EAC_R11_SNORM_BLOCK:
	case ImageFormat_EAC_R11G11_SNORM_BLOCK:
		return 32;
	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:
		return 64;
	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:
	case ImageFormat_ASTC_4x4_UNORM_BLOCK:
	case ImageFormat_ASTC_4x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x4_UNORM_BLOCK:
	case ImageFormat_ASTC_5x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x5_UNORM_BLOCK:
	case ImageFormat_ASTC_5x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x5_UNORM_BLOCK:
	case ImageFormat_ASTC_6x5_SRGB_BLOCK:
	case ImageFormat_ASTC_8x5_UNORM_BLOCK:
	case ImageFormat_ASTC_8x5_SRGB_BLOCK:
	case ImageFormat_ASTC_10x5_UNORM_BLOCK:
	case ImageFormat_ASTC_10x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x6_UNORM_BLOCK:
	case ImageFormat_ASTC_6x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x6_UNORM_BLOCK:
	case ImageFormat_ASTC_8x6_SRGB_BLOCK:
	case ImageFormat_ASTC_10x6_UNORM_BLOCK:
	case ImageFormat_ASTC_10x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x8_UNORM_BLOCK:
	case ImageFormat_ASTC_8x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x8_UNORM_BLOCK:
	case ImageFormat_ASTC_10x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x10_UNORM_BLOCK:
	case ImageFormat_ASTC_10x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x10_UNORM_BLOCK:
	case ImageFormat_ASTC_12x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x12_UNORM_BLOCK:
	case ImageFormat_ASTC_12x12_SRGB_BLOCK:
		return 128;

	default: ASSERT(false);
		return 0;
	}
}

//! returns the number of channels per gl format
AL2O3_EXTERN_C inline uint32_t ImageFormat_ChannelCount(enum ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_R4G4B4A4_UNORM_PACK16:
	case ImageFormat_B4G4R4A4_UNORM_PACK16:
	case ImageFormat_R5G5B5A1_UNORM_PACK16:
	case ImageFormat_B5G5R5A1_UNORM_PACK16:
	case ImageFormat_A1R5G5B5_UNORM_PACK16:
	case ImageFormat_R8G8B8A8_UNORM:
	case ImageFormat_R8G8B8A8_SNORM:
	case ImageFormat_R8G8B8A8_USCALED:
	case ImageFormat_R8G8B8A8_SSCALED:
	case ImageFormat_R8G8B8A8_UINT:
	case ImageFormat_R8G8B8A8_SINT:
	case ImageFormat_R8G8B8A8_SRGB:
	case ImageFormat_B8G8R8A8_UNORM:
	case ImageFormat_B8G8R8A8_SNORM:
	case ImageFormat_B8G8R8A8_USCALED:
	case ImageFormat_B8G8R8A8_SSCALED:
	case ImageFormat_B8G8R8A8_UINT:
	case ImageFormat_B8G8R8A8_SINT:
	case ImageFormat_B8G8R8A8_SRGB:
	case ImageFormat_A8B8G8R8_UNORM_PACK32:
	case ImageFormat_A8B8G8R8_SNORM_PACK32:
	case ImageFormat_A8B8G8R8_USCALED_PACK32:
	case ImageFormat_A8B8G8R8_SSCALED_PACK32:
	case ImageFormat_A8B8G8R8_UINT_PACK32:
	case ImageFormat_A8B8G8R8_SINT_PACK32:
	case ImageFormat_A8B8G8R8_SRGB_PACK32:
	case ImageFormat_A2R10G10B10_UNORM_PACK32:
	case ImageFormat_A2R10G10B10_USCALED_PACK32:
	case ImageFormat_A2R10G10B10_UINT_PACK32:
	case ImageFormat_A2B10G10R10_UNORM_PACK32:
	case ImageFormat_A2B10G10R10_USCALED_PACK32:
	case ImageFormat_A2B10G10R10_UINT_PACK32:
	case ImageFormat_R16G16B16A16_UNORM:
	case ImageFormat_R16G16B16A16_SNORM:
	case ImageFormat_R16G16B16A16_USCALED:
	case ImageFormat_R16G16B16A16_SSCALED:
	case ImageFormat_R16G16B16A16_UINT:
	case ImageFormat_R16G16B16A16_SINT:
	case ImageFormat_R16G16B16A16_SFLOAT:
	case ImageFormat_R32G32B32A32_UINT:
	case ImageFormat_R32G32B32A32_SINT:
	case ImageFormat_R32G32B32A32_SFLOAT:
	case ImageFormat_R64G64B64A64_UINT:
	case ImageFormat_R64G64B64A64_SINT:
	case ImageFormat_R64G64B64A64_SFLOAT:
	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
	case ImageFormat_ASTC_4x4_UNORM_BLOCK:
	case ImageFormat_ASTC_4x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x4_UNORM_BLOCK:
	case ImageFormat_ASTC_5x4_SRGB_BLOCK:
	case ImageFormat_ASTC_5x5_UNORM_BLOCK:
	case ImageFormat_ASTC_5x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x5_UNORM_BLOCK:
	case ImageFormat_ASTC_6x5_SRGB_BLOCK:
	case ImageFormat_ASTC_8x5_UNORM_BLOCK:
	case ImageFormat_ASTC_8x5_SRGB_BLOCK:
	case ImageFormat_ASTC_10x5_UNORM_BLOCK:
	case ImageFormat_ASTC_10x5_SRGB_BLOCK:
	case ImageFormat_ASTC_6x6_UNORM_BLOCK:
	case ImageFormat_ASTC_6x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x6_UNORM_BLOCK:
	case ImageFormat_ASTC_8x6_SRGB_BLOCK:
	case ImageFormat_ASTC_10x6_UNORM_BLOCK:
	case ImageFormat_ASTC_10x6_SRGB_BLOCK:
	case ImageFormat_ASTC_8x8_UNORM_BLOCK:
	case ImageFormat_ASTC_8x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x8_UNORM_BLOCK:
	case ImageFormat_ASTC_10x8_SRGB_BLOCK:
	case ImageFormat_ASTC_10x10_UNORM_BLOCK:
	case ImageFormat_ASTC_10x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x10_UNORM_BLOCK:
	case ImageFormat_ASTC_12x10_SRGB_BLOCK:
	case ImageFormat_ASTC_12x12_UNORM_BLOCK:
	case ImageFormat_ASTC_12x12_SRGB_BLOCK:
	case ImageFormat_A4R4G4B4_UNORM_PACK16:
	case ImageFormat_A8R8G8B8_UNORM_PACK32:
		return 4;

	case ImageFormat_R5G6B5_UNORM_PACK16:
	case ImageFormat_B5G6R5_UNORM_PACK16:
	case ImageFormat_R8G8B8_UNORM:
	case ImageFormat_R8G8B8_SNORM:
	case ImageFormat_R8G8B8_USCALED:
	case ImageFormat_R8G8B8_SSCALED:
	case ImageFormat_R8G8B8_UINT:
	case ImageFormat_R8G8B8_SINT:
	case ImageFormat_R8G8B8_SRGB:
	case ImageFormat_B8G8R8_UNORM:
	case ImageFormat_B8G8R8_SNORM:
	case ImageFormat_B8G8R8_USCALED:
	case ImageFormat_B8G8R8_SSCALED:
	case ImageFormat_B8G8R8_UINT:
	case ImageFormat_B8G8R8_SINT:
	case ImageFormat_B8G8R8_SRGB:
	case ImageFormat_R16G16B16_UNORM:
	case ImageFormat_R16G16B16_SNORM:
	case ImageFormat_R16G16B16_USCALED:
	case ImageFormat_R16G16B16_SSCALED:
	case ImageFormat_R16G16B16_UINT:
	case ImageFormat_R16G16B16_SINT:
	case ImageFormat_R16G16B16_SFLOAT:
	case ImageFormat_R32G32B32_UINT:
	case ImageFormat_R32G32B32_SINT:
	case ImageFormat_R32G32B32_SFLOAT:
	case ImageFormat_R64G64B64_UINT:
	case ImageFormat_R64G64B64_SINT:
	case ImageFormat_R64G64B64_SFLOAT:
	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:
	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
		return 3;

	case ImageFormat_R4G4_UNORM_PACK8:
	case ImageFormat_R8G8_UNORM:
	case ImageFormat_R8G8_SNORM:
	case ImageFormat_R8G8_USCALED:
	case ImageFormat_R8G8_SSCALED:
	case ImageFormat_R8G8_UINT:
	case ImageFormat_R8G8_SINT:
	case ImageFormat_R8G8_SRGB:
	case ImageFormat_R16G16_UNORM:
	case ImageFormat_R16G16_SNORM:
	case ImageFormat_R16G16_USCALED:
	case ImageFormat_R16G16_SSCALED:
	case ImageFormat_R16G16_UINT:
	case ImageFormat_R16G16_SINT:
	case ImageFormat_R16G16_SFLOAT:
	case ImageFormat_R32G32_UINT:
	case ImageFormat_R32G32_SINT:
	case ImageFormat_R32G32_SFLOAT:
	case ImageFormat_R64G64_UINT:
	case ImageFormat_R64G64_SINT:
	case ImageFormat_R64G64_SFLOAT:
	case ImageFormat_X8_D24_UNORM_PACK32:
	case ImageFormat_D16_UNORM_S8_UINT:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_D32_SFLOAT_S8_UINT:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_EAC_R11G11_UNORM_BLOCK:
	case ImageFormat_EAC_R11G11_SNORM_BLOCK:
		return 2;

	case ImageFormat_R8_UNORM:
	case ImageFormat_R8_SNORM:
	case ImageFormat_R8_USCALED:
	case ImageFormat_R8_SSCALED:
	case ImageFormat_R8_UINT:
	case ImageFormat_R8_SINT:
	case ImageFormat_R8_SRGB:
	case ImageFormat_R16_UNORM:
	case ImageFormat_R16_SNORM:
	case ImageFormat_R16_USCALED:
	case ImageFormat_R16_SSCALED:
	case ImageFormat_R16_UINT:
	case ImageFormat_R16_SINT:
	case ImageFormat_R16_SFLOAT:
	case ImageFormat_R32_UINT:
	case ImageFormat_R32_SINT:
	case ImageFormat_R32_SFLOAT:
	case ImageFormat_R64_UINT:
	case ImageFormat_R64_SINT:
	case ImageFormat_R64_SFLOAT:
	case ImageFormat_D16_UNORM:
	case ImageFormat_D32_SFLOAT:
	case ImageFormat_S8_UINT:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_EAC_R11_UNORM_BLOCK:
	case ImageFormat_EAC_R11_SNORM_BLOCK:
		return 1;
	case ImageFormat_UNDEFINED:return 0;

	default:LOGWARNINGF("channelCount: %s not handled", ImageFormat_Name(fmt));
		return 0;
	}
}

//! Returns the number of channel bits for each channel for non compressed formats
AL2O3_EXTERN_C inline uint32_t ImageFormat_ChannelBitWidth(enum ImageFormat const fmt, int const channel_) {
	ASSERT(!ImageFormat_IsCompressed(fmt));
	switch (fmt) {
	case ImageFormat_R64_UINT:
	case ImageFormat_R64_SINT:
	case ImageFormat_R64_SFLOAT:
	case ImageFormat_R64G64_UINT:
	case ImageFormat_R64G64_SINT:
	case ImageFormat_R64G64_SFLOAT:
	case ImageFormat_R64G64B64_UINT:
	case ImageFormat_R64G64B64_SINT:
	case ImageFormat_R64G64B64_SFLOAT:
	case ImageFormat_R64G64B64A64_UINT:
	case ImageFormat_R64G64B64A64_SINT:
	case ImageFormat_R64G64B64A64_SFLOAT:return 64;
	case ImageFormat_R32_UINT:
	case ImageFormat_R32_SINT:
	case ImageFormat_R32_SFLOAT:
	case ImageFormat_R32G32_UINT:
	case ImageFormat_R32G32_SINT:
	case ImageFormat_R32G32_SFLOAT:
	case ImageFormat_R32G32B32_UINT:
	case ImageFormat_R32G32B32_SINT:
	case ImageFormat_R32G32B32_SFLOAT:
	case ImageFormat_R32G32B32A32_UINT:
	case ImageFormat_R32G32B32A32_SINT:
	case ImageFormat_R32G32B32A32_SFLOAT:
	case ImageFormat_D32_SFLOAT:return 32;
	case ImageFormat_X8_D24_UNORM_PACK32:
		if (channel_ == 1) {
			return 24;
		} else {
			return 8;
		}
	case ImageFormat_D16_UNORM_S8_UINT:
		if (channel_ == 0) {
			return 16;
		} else {
			return 8;
		}
	case ImageFormat_D24_UNORM_S8_UINT:
		if (channel_ == 0) {
			return 24;
		} else {
			return 8;
		}
	case ImageFormat_D32_SFLOAT_S8_UINT:
		if (channel_ == 0) {
			return 32;
		} else {
			return 8;
		}

	case ImageFormat_R16_UNORM:
	case ImageFormat_R16_SNORM:
	case ImageFormat_R16_USCALED:
	case ImageFormat_R16_SSCALED:
	case ImageFormat_R16_UINT:
	case ImageFormat_R16_SINT:
	case ImageFormat_R16_SFLOAT:
	case ImageFormat_R16G16_UNORM:
	case ImageFormat_R16G16_SNORM:
	case ImageFormat_R16G16_USCALED:
	case ImageFormat_R16G16_SSCALED:
	case ImageFormat_R16G16_UINT:
	case ImageFormat_R16G16_SINT:
	case ImageFormat_R16G16_SFLOAT:
	case ImageFormat_R16G16B16_UNORM:
	case ImageFormat_R16G16B16_SNORM:
	case ImageFormat_R16G16B16_USCALED:
	case ImageFormat_R16G16B16_SSCALED:
	case ImageFormat_R16G16B16_UINT:
	case ImageFormat_R16G16B16_SINT:
	case ImageFormat_R16G16B16_SFLOAT:
	case ImageFormat_R16G16B16A16_UNORM:
	case ImageFormat_R16G16B16A16_SNORM:
	case ImageFormat_R16G16B16A16_USCALED:
	case ImageFormat_R16G16B16A16_SSCALED:
	case ImageFormat_R16G16B16A16_UINT:
	case ImageFormat_R16G16B16A16_SINT:
	case ImageFormat_R16G16B16A16_SFLOAT:
	case ImageFormat_D16_UNORM:return 16;
	case ImageFormat_B10G11R11_UFLOAT_PACK32:
		if(channel_ == 0) return 10;
		else return 11;
	case ImageFormat_A2R10G10B10_UNORM_PACK32:
	case ImageFormat_A2R10G10B10_USCALED_PACK32:
	case ImageFormat_A2R10G10B10_UINT_PACK32:
	case ImageFormat_A2B10G10R10_UNORM_PACK32:
	case ImageFormat_A2B10G10R10_USCALED_PACK32:
	case ImageFormat_A2B10G10R10_UINT_PACK32:
		if (channel_ == 0) {
			return 2;
		} else {
			return 10;
		}
	case ImageFormat_E5B9G9R9_UFLOAT_PACK32:
		if(channel_ == 0) return 5;
		else return 9;
	case ImageFormat_R8_UNORM:
	case ImageFormat_R8_SNORM:
	case ImageFormat_R8_USCALED:
	case ImageFormat_R8_SSCALED:
	case ImageFormat_R8_UINT:
	case ImageFormat_R8_SINT:
	case ImageFormat_R8_SRGB:
	case ImageFormat_R8G8_UNORM:
	case ImageFormat_R8G8_SNORM:
	case ImageFormat_R8G8_USCALED:
	case ImageFormat_R8G8_SSCALED:
	case ImageFormat_R8G8_UINT:
	case ImageFormat_R8G8_SINT:
	case ImageFormat_R8G8_SRGB:
	case ImageFormat_R8G8B8_UNORM:
	case ImageFormat_R8G8B8_SNORM:
	case ImageFormat_R8G8B8_USCALED:
	case ImageFormat_R8G8B8_SSCALED:
	case ImageFormat_R8G8B8_UINT:
	case ImageFormat_R8G8B8_SINT:
	case ImageFormat_R8G8B8_SRGB:
	case ImageFormat_B8G8R8_UNORM:
	case ImageFormat_B8G8R8_SNORM:
	case ImageFormat_B8G8R8_USCALED:
	case ImageFormat_B8G8R8_SSCALED:
	case ImageFormat_B8G8R8_UINT:
	case ImageFormat_B8G8R8_SINT:
	case ImageFormat_B8G8R8_SRGB:
	case ImageFormat_R8G8B8A8_UNORM:
	case ImageFormat_R8G8B8A8_SNORM:
	case ImageFormat_R8G8B8A8_USCALED:
	case ImageFormat_R8G8B8A8_SSCALED:
	case ImageFormat_R8G8B8A8_UINT:
	case ImageFormat_R8G8B8A8_SINT:
	case ImageFormat_R8G8B8A8_SRGB:
	case ImageFormat_B8G8R8A8_UNORM:
	case ImageFormat_B8G8R8A8_SNORM:
	case ImageFormat_B8G8R8A8_USCALED:
	case ImageFormat_B8G8R8A8_SSCALED:
	case ImageFormat_B8G8R8A8_UINT:
	case ImageFormat_B8G8R8A8_SINT:
	case ImageFormat_B8G8R8A8_SRGB:
	case ImageFormat_A8B8G8R8_UNORM_PACK32:
	case ImageFormat_A8B8G8R8_SNORM_PACK32:
	case ImageFormat_A8B8G8R8_USCALED_PACK32:
	case ImageFormat_A8B8G8R8_SSCALED_PACK32:
	case ImageFormat_A8B8G8R8_UINT_PACK32:
	case ImageFormat_A8B8G8R8_SINT_PACK32:
	case ImageFormat_A8B8G8R8_SRGB_PACK32:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_S8_UINT:
	case ImageFormat_A8R8G8B8_UNORM_PACK32:
		return 8;
	case ImageFormat_UNDEFINED:return 0;

	// unknown
	default: LOGWARNINGF("channelBitWidth: %s not handled", ImageFormat_Name(fmt));
		return 0;
	}
}

AL2O3_EXTERN_C inline uint32_t ImageFormat_BitWidth(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_R64G64B64A64_UINT:
	case ImageFormat_R64G64B64A64_SINT:
	case ImageFormat_R64G64B64A64_SFLOAT:return 256;
	case ImageFormat_R64G64B64_UINT:
	case ImageFormat_R64G64B64_SINT:
	case ImageFormat_R64G64B64_SFLOAT:return 192;

	case ImageFormat_R64G64_UINT:
	case ImageFormat_R64G64_SINT:
	case ImageFormat_R64G64_SFLOAT:
	case ImageFormat_R32G32B32A32_UINT:
	case ImageFormat_R32G32B32A32_SINT:
	case ImageFormat_R32G32B32A32_SFLOAT:return 128;

	case ImageFormat_R32G32B32_UINT:
	case ImageFormat_R32G32B32_SINT:
	case ImageFormat_R32G32B32_SFLOAT:return 96;
	case ImageFormat_R64_UINT:
	case ImageFormat_R64_SINT:
	case ImageFormat_R64_SFLOAT:
	case ImageFormat_R32G32_UINT:
	case ImageFormat_R32G32_SINT:
	case ImageFormat_R32G32_SFLOAT:
	case ImageFormat_R16G16B16A16_UNORM:
	case ImageFormat_R16G16B16A16_SNORM:
	case ImageFormat_R16G16B16A16_USCALED:
	case ImageFormat_R16G16B16A16_SSCALED:
	case ImageFormat_R16G16B16A16_UINT:
	case ImageFormat_R16G16B16A16_SINT:
	case ImageFormat_R16G16B16A16_SFLOAT:return 64;

		// best case 40 bits worse case 64, be a pessimist
	case ImageFormat_D32_SFLOAT_S8_UINT:return 64;

	case ImageFormat_R16G16B16_UNORM:
	case ImageFormat_R16G16B16_SNORM:
	case ImageFormat_R16G16B16_USCALED:
	case ImageFormat_R16G16B16_SSCALED:
	case ImageFormat_R16G16B16_UINT:
	case ImageFormat_R16G16B16_SINT:
	case ImageFormat_R16G16B16_SFLOAT:return 48;
	case ImageFormat_R32_SINT:
	case ImageFormat_R32_UINT:
	case ImageFormat_R32_SFLOAT:
	case ImageFormat_R16G16_SINT:
	case ImageFormat_R16G16_SFLOAT:
	case ImageFormat_R16G16_SNORM:
	case ImageFormat_R16G16_UNORM:
	case ImageFormat_R16G16_UINT:
	case ImageFormat_R16G16_USCALED:
	case ImageFormat_R16G16_SSCALED:
	case ImageFormat_R8G8B8A8_UNORM:
	case ImageFormat_R8G8B8A8_SNORM:
	case ImageFormat_R8G8B8A8_USCALED:
	case ImageFormat_R8G8B8A8_SSCALED:
	case ImageFormat_R8G8B8A8_UINT:
	case ImageFormat_R8G8B8A8_SINT:
	case ImageFormat_R8G8B8A8_SRGB:
	case ImageFormat_B8G8R8A8_UNORM:
	case ImageFormat_B8G8R8A8_SNORM:
	case ImageFormat_B8G8R8A8_USCALED:
	case ImageFormat_B8G8R8A8_SSCALED:
	case ImageFormat_B8G8R8A8_UINT:
	case ImageFormat_B8G8R8A8_SINT:
	case ImageFormat_B8G8R8A8_SRGB:
	case ImageFormat_A8B8G8R8_UNORM_PACK32:
	case ImageFormat_A8B8G8R8_SNORM_PACK32:
	case ImageFormat_A8B8G8R8_USCALED_PACK32:
	case ImageFormat_A8B8G8R8_SSCALED_PACK32:
	case ImageFormat_A8B8G8R8_UINT_PACK32:
	case ImageFormat_A8B8G8R8_SINT_PACK32:
	case ImageFormat_A8B8G8R8_SRGB_PACK32:
	case ImageFormat_A2R10G10B10_UNORM_PACK32:
	case ImageFormat_A2R10G10B10_USCALED_PACK32:
	case ImageFormat_A2R10G10B10_UINT_PACK32:
	case ImageFormat_A2B10G10R10_UNORM_PACK32:
	case ImageFormat_A2B10G10R10_USCALED_PACK32:
	case ImageFormat_A2B10G10R10_UINT_PACK32:
	case ImageFormat_B10G11R11_UFLOAT_PACK32:
	case ImageFormat_E5B9G9R9_UFLOAT_PACK32:
	case ImageFormat_X8_D24_UNORM_PACK32:
	case ImageFormat_D32_SFLOAT:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_A8R8G8B8_UNORM_PACK32:
		return 32;

	case ImageFormat_R8G8B8_UNORM:
	case ImageFormat_R8G8B8_SNORM:
	case ImageFormat_R8G8B8_USCALED:
	case ImageFormat_R8G8B8_SSCALED:
	case ImageFormat_R8G8B8_UINT:
	case ImageFormat_R8G8B8_SINT:
	case ImageFormat_R8G8B8_SRGB:
	case ImageFormat_B8G8R8_UNORM:
	case ImageFormat_B8G8R8_SNORM:
	case ImageFormat_B8G8R8_USCALED:
	case ImageFormat_B8G8R8_SSCALED:
	case ImageFormat_B8G8R8_UINT:
	case ImageFormat_B8G8R8_SINT:
	case ImageFormat_B8G8R8_SRGB:
	case ImageFormat_D16_UNORM_S8_UINT:return 24;

	case ImageFormat_R4G4B4A4_UNORM_PACK16:
	case ImageFormat_B4G4R4A4_UNORM_PACK16:
	case ImageFormat_R5G6B5_UNORM_PACK16:
	case ImageFormat_B5G6R5_UNORM_PACK16:
	case ImageFormat_R5G5B5A1_UNORM_PACK16:
	case ImageFormat_B5G5R5A1_UNORM_PACK16:
	case ImageFormat_A1R5G5B5_UNORM_PACK16:
	case ImageFormat_R8G8_UNORM:
	case ImageFormat_R8G8_SNORM:
	case ImageFormat_R8G8_USCALED:
	case ImageFormat_R8G8_SSCALED:
	case ImageFormat_R8G8_UINT:
	case ImageFormat_R8G8_SINT:
	case ImageFormat_R8G8_SRGB:
	case ImageFormat_R16_UNORM:
	case ImageFormat_R16_SNORM:
	case ImageFormat_R16_USCALED:
	case ImageFormat_R16_SSCALED:
	case ImageFormat_R16_UINT:
	case ImageFormat_R16_SINT:
	case ImageFormat_R16_SFLOAT:
	case ImageFormat_D16_UNORM:
	case ImageFormat_A4R4G4B4_UNORM_PACK16:
		return 16;

	case ImageFormat_R4G4_UNORM_PACK8:
	case ImageFormat_R8_UNORM:
	case ImageFormat_R8_SNORM:
	case ImageFormat_R8_USCALED:
	case ImageFormat_R8_SSCALED:
	case ImageFormat_R8_UINT:
	case ImageFormat_R8_SINT:
	case ImageFormat_R8_SRGB:
	case ImageFormat_S8_UINT:
		return 8;


	default: LOGWARNINGF("bitWidth: %s not handled if compressed use ImageFormat_BitSizeOfBlock", ImageFormat_Name(fmt));
		return 0;
	}
}

AL2O3_EXTERN_C inline double ImageFormat_Max(enum ImageFormat const fmt, int channel) {
	switch (fmt) {
	case ImageFormat_R64G64B64A64_UINT:
	case ImageFormat_R64G64B64_UINT:
	case ImageFormat_R64G64_UINT:
	case ImageFormat_R64_UINT:return (double) UINT64_MAX;

	case ImageFormat_R64G64B64A64_SINT:
	case ImageFormat_R64G64B64_SINT:
	case ImageFormat_R64G64_SINT:
	case ImageFormat_R64_SINT:return (double) INT64_MAX;

	case ImageFormat_R64G64B64_SFLOAT:
	case ImageFormat_R64G64B64A64_SFLOAT:
	case ImageFormat_R64G64_SFLOAT:
	case ImageFormat_R64_SFLOAT:return DBL_MAX;

	case ImageFormat_R32G32B32A32_UINT:
	case ImageFormat_R32G32B32_UINT:
	case ImageFormat_R32G32_UINT:
	case ImageFormat_R32_UINT:return UINT32_MAX;

	case ImageFormat_R32G32B32A32_SINT:
	case ImageFormat_R32G32B32_SINT:
	case ImageFormat_R32G32_SINT:
	case ImageFormat_R32_SINT:return INT32_MAX;

	case ImageFormat_R32G32B32A32_SFLOAT:
	case ImageFormat_R32G32B32_SFLOAT:
	case ImageFormat_R32G32_SFLOAT:
	case ImageFormat_R32_SFLOAT:
	case ImageFormat_D32_SFLOAT:return FLT_MAX;

	case ImageFormat_R16G16B16A16_UNORM:
	case ImageFormat_R16G16B16_UNORM:
	case ImageFormat_R16G16_UNORM:
	case ImageFormat_R16_UNORM:
	case ImageFormat_D16_UNORM:
	case ImageFormat_R16G16B16A16_USCALED:
	case ImageFormat_R16G16B16_USCALED:
	case ImageFormat_R16G16_USCALED:
	case ImageFormat_R16_USCALED:
	case ImageFormat_R16G16B16A16_UINT:
	case ImageFormat_R16G16B16_UINT:
	case ImageFormat_R16G16_UINT:
	case ImageFormat_R16_UINT:return UINT16_MAX;

	case ImageFormat_R16G16B16A16_SNORM:
	case ImageFormat_R16G16B16_SNORM:
	case ImageFormat_R16G16_SNORM:
	case ImageFormat_R16_SNORM:
	case ImageFormat_R16G16B16A16_SSCALED:
	case ImageFormat_R16G16B16_SSCALED:
	case ImageFormat_R16G16_SSCALED:
	case ImageFormat_R16_SSCALED:
	case ImageFormat_R16G16B16A16_SINT:
	case ImageFormat_R16G16B16_SINT:
	case ImageFormat_R16G16_SINT:
	case ImageFormat_R16_SINT:return INT16_MAX;

	case ImageFormat_R16G16B16A16_SFLOAT:
	case ImageFormat_R16G16B16_SFLOAT:
	case ImageFormat_R16G16_SFLOAT:
	case ImageFormat_R16_SFLOAT:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:return 0x1.ffcp15;

	case ImageFormat_D32_SFLOAT_S8_UINT:
		if (channel == 0) {
			return FLT_MAX;
		} else {
			return UINT8_MAX;
		}

	case ImageFormat_R8G8B8A8_UNORM:
	case ImageFormat_B8G8R8A8_UNORM:
	case ImageFormat_A8B8G8R8_UNORM_PACK32:
	case ImageFormat_R8G8B8_UNORM:
	case ImageFormat_B8G8R8_UNORM:
	case ImageFormat_R8G8_UNORM:
	case ImageFormat_R8_UNORM:
	case ImageFormat_R8G8B8A8_USCALED:
	case ImageFormat_B8G8R8A8_USCALED:
	case ImageFormat_A8B8G8R8_USCALED_PACK32:
	case ImageFormat_R8G8B8_USCALED:
	case ImageFormat_B8G8R8_USCALED:
	case ImageFormat_R8G8_USCALED:
	case ImageFormat_R8_USCALED:
	case ImageFormat_R8G8B8A8_UINT:
	case ImageFormat_B8G8R8A8_UINT:
	case ImageFormat_A8B8G8R8_UINT_PACK32:
	case ImageFormat_R8G8B8_UINT:
	case ImageFormat_B8G8R8_UINT:
	case ImageFormat_R8G8_UINT:
	case ImageFormat_R8_UINT:
	case ImageFormat_S8_UINT:
	case ImageFormat_A8B8G8R8_SRGB_PACK32:
	case ImageFormat_R8G8B8A8_SRGB:
	case ImageFormat_B8G8R8A8_SRGB:
	case ImageFormat_B8G8R8_SRGB:
	case ImageFormat_R8G8B8_SRGB:
	case ImageFormat_R8G8_SRGB:
	case ImageFormat_R8_SRGB:
	case ImageFormat_A8R8G8B8_UNORM_PACK32:
		return UINT8_MAX;

	case ImageFormat_R8G8B8A8_SNORM:
	case ImageFormat_B8G8R8A8_SNORM:
	case ImageFormat_A8B8G8R8_SNORM_PACK32:
	case ImageFormat_R8G8B8_SNORM:
	case ImageFormat_B8G8R8_SNORM:
	case ImageFormat_R8G8_SNORM:
	case ImageFormat_R8_SNORM:
	case ImageFormat_R8G8B8A8_SSCALED:
	case ImageFormat_B8G8R8A8_SSCALED:
	case ImageFormat_A8B8G8R8_SSCALED_PACK32:
	case ImageFormat_R8G8B8_SSCALED:
	case ImageFormat_B8G8R8_SSCALED:
	case ImageFormat_R8G8_SSCALED:
	case ImageFormat_R8_SSCALED:
	case ImageFormat_R8G8B8A8_SINT:
	case ImageFormat_B8G8R8A8_SINT:
	case ImageFormat_A8B8G8R8_SINT_PACK32:
	case ImageFormat_R8G8B8_SINT:
	case ImageFormat_B8G8R8_SINT:
	case ImageFormat_R8G8_SINT:
	case ImageFormat_R8_SINT:return INT8_MAX;

	case ImageFormat_A2R10G10B10_UNORM_PACK32:
	case ImageFormat_A2R10G10B10_USCALED_PACK32:
	case ImageFormat_A2R10G10B10_UINT_PACK32:
	case ImageFormat_A2B10G10R10_UNORM_PACK32:
	case ImageFormat_A2B10G10R10_USCALED_PACK32:
	case ImageFormat_A2B10G10R10_UINT_PACK32:
		if (channel == 0) {
			return 3.0;
		} else {
			return 1023.0;
		}

	case ImageFormat_X8_D24_UNORM_PACK32:
		if (channel == 0) {
			return 255.0;
		} else {
			return (double) (1 << 24) - 1.0;
		};
	case ImageFormat_D24_UNORM_S8_UINT:
		if (channel == 1) {
			return 255.0;
		} else {
			return (double) (1 << 24) - 1.0;
		}
	case ImageFormat_D16_UNORM_S8_UINT:
		if (channel == 1) {
			return 255.0;
		} else {
			return 65535.0;
		}
	case ImageFormat_R4G4B4A4_UNORM_PACK16:
	case ImageFormat_B4G4R4A4_UNORM_PACK16:
	case ImageFormat_R4G4_UNORM_PACK8:
	case ImageFormat_A4R4G4B4_UNORM_PACK16:
		return 15.0;

	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_R5G6B5_UNORM_PACK16:
	case ImageFormat_B5G6R5_UNORM_PACK16:
		if (channel == 1) {
			return 63.0;
		} else {
			return 31.0;
		}

	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_R5G5B5A1_UNORM_PACK16:
	case ImageFormat_B5G5R5A1_UNORM_PACK16:
		if (channel == 3) {
			return 1.0;
		} else {
			return 31.0;
		}
	case ImageFormat_A1R5G5B5_UNORM_PACK16:
		if (channel == 0) {
			return 1.0;
		} else {
			return 31.0;
		}
	case ImageFormat_B10G11R11_UFLOAT_PACK32:
		return 65000.0;
	case ImageFormat_E5B9G9R9_UFLOAT_PACK32:
		return 65472.0;

	case ImageFormat_UNDEFINED:
	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:
	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:

		return 255.0; // TODO
	default:LOGWARNINGF("max %s not handled", ImageFormat_Name(fmt));
		return 0;
	}
}

AL2O3_EXTERN_C inline double ImageFormat_Min(enum ImageFormat const fmt, int channel) {
	switch (fmt) {
	case ImageFormat_R64G64B64A64_UINT:
	case ImageFormat_R64G64B64_UINT:
	case ImageFormat_R64G64_UINT:
	case ImageFormat_R64_UINT:
	case ImageFormat_R16G16B16A16_UNORM:
	case ImageFormat_R16G16B16_UNORM:
	case ImageFormat_R16G16_UNORM:
	case ImageFormat_R16_UNORM:
	case ImageFormat_D16_UNORM:
	case ImageFormat_R16G16B16A16_USCALED:
	case ImageFormat_R16G16B16_USCALED:
	case ImageFormat_R16G16_USCALED:
	case ImageFormat_R16_USCALED:
	case ImageFormat_R16G16B16A16_UINT:
	case ImageFormat_R16G16B16_UINT:
	case ImageFormat_R16G16_UINT:
	case ImageFormat_R16_UINT:
	case ImageFormat_R8G8B8A8_UNORM:
	case ImageFormat_B8G8R8A8_UNORM:
	case ImageFormat_A8B8G8R8_UNORM_PACK32:
	case ImageFormat_R8G8B8_UNORM:
	case ImageFormat_B8G8R8_UNORM:
	case ImageFormat_R8G8_UNORM:
	case ImageFormat_R8_UNORM:
	case ImageFormat_R8G8B8A8_USCALED:
	case ImageFormat_B8G8R8A8_USCALED:
	case ImageFormat_A8B8G8R8_USCALED_PACK32:
	case ImageFormat_R8G8B8_USCALED:
	case ImageFormat_B8G8R8_USCALED:
	case ImageFormat_R8G8_USCALED:
	case ImageFormat_R8_USCALED:
	case ImageFormat_R8G8B8A8_UINT:
	case ImageFormat_B8G8R8A8_UINT:
	case ImageFormat_A8B8G8R8_UINT_PACK32:
	case ImageFormat_R8G8B8_UINT:
	case ImageFormat_B8G8R8_UINT:
	case ImageFormat_R8G8_UINT:
	case ImageFormat_R8_UINT:
	case ImageFormat_S8_UINT:
	case ImageFormat_A8B8G8R8_SRGB_PACK32:
	case ImageFormat_R8G8B8A8_SRGB:
	case ImageFormat_B8G8R8A8_SRGB:
	case ImageFormat_B8G8R8_SRGB:
	case ImageFormat_R8G8B8_SRGB:
	case ImageFormat_R8G8_SRGB:
	case ImageFormat_R8_SRGB:
	case ImageFormat_A2R10G10B10_UNORM_PACK32:
	case ImageFormat_A2R10G10B10_USCALED_PACK32:
	case ImageFormat_A2R10G10B10_UINT_PACK32:
	case ImageFormat_A2B10G10R10_UNORM_PACK32:
	case ImageFormat_A2B10G10R10_USCALED_PACK32:
	case ImageFormat_A2B10G10R10_UINT_PACK32:
	case ImageFormat_X8_D24_UNORM_PACK32:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_D16_UNORM_S8_UINT:
	case ImageFormat_R4G4B4A4_UNORM_PACK16:
	case ImageFormat_B4G4R4A4_UNORM_PACK16:
	case ImageFormat_R4G4_UNORM_PACK8:
	case ImageFormat_A4R4G4B4_UNORM_PACK16:
	case ImageFormat_R32G32B32A32_UINT:
	case ImageFormat_R32G32B32_UINT:
	case ImageFormat_R32G32_UINT:
	case ImageFormat_R32_UINT:
	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_R5G6B5_UNORM_PACK16:
	case ImageFormat_B5G6R5_UNORM_PACK16:
	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_R5G5B5A1_UNORM_PACK16:
	case ImageFormat_B5G5R5A1_UNORM_PACK16:
	case ImageFormat_A1R5G5B5_UNORM_PACK16:
	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:
	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case ImageFormat_A8R8G8B8_UNORM_PACK32:
		return 0.0;
	case ImageFormat_R64G64B64A64_SINT:
	case ImageFormat_R64G64B64_SINT:
	case ImageFormat_R64G64_SINT:
	case ImageFormat_R64_SINT:return INT64_MIN;

	case ImageFormat_R64G64B64_SFLOAT:
	case ImageFormat_R64G64B64A64_SFLOAT:
	case ImageFormat_R64G64_SFLOAT:
	case ImageFormat_R64_SFLOAT:return FLT_MIN;



	case ImageFormat_R32G32B32A32_SINT:
	case ImageFormat_R32G32B32_SINT:
	case ImageFormat_R32G32_SINT:
	case ImageFormat_R32_SINT:return INT32_MIN;

	case ImageFormat_R32G32B32A32_SFLOAT:
	case ImageFormat_R32G32B32_SFLOAT:
	case ImageFormat_R32G32_SFLOAT:
	case ImageFormat_R32_SFLOAT:
	case ImageFormat_D32_SFLOAT:return FLT_MIN;

	case ImageFormat_R16G16B16A16_SNORM:
	case ImageFormat_R16G16B16_SNORM:
	case ImageFormat_R16G16_SNORM:
	case ImageFormat_R16_SNORM:
	case ImageFormat_R16G16B16A16_SSCALED:
	case ImageFormat_R16G16B16_SSCALED:
	case ImageFormat_R16G16_SSCALED:
	case ImageFormat_R16_SSCALED:
	case ImageFormat_R16G16B16A16_SINT:
	case ImageFormat_R16G16B16_SINT:
	case ImageFormat_R16G16_SINT:
	case ImageFormat_R16_SINT:return INT16_MIN;

	case ImageFormat_R16G16B16A16_SFLOAT:
	case ImageFormat_R16G16B16_SFLOAT:
	case ImageFormat_R16G16_SFLOAT:
	case ImageFormat_R16_SFLOAT:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK: return 0x1.0p-14;

	case ImageFormat_D32_SFLOAT_S8_UINT:
		if (channel == 0) {
			return FLT_MIN;
		} else {
			return 0;
		}

	case ImageFormat_R8G8B8A8_SNORM:
	case ImageFormat_B8G8R8A8_SNORM:
	case ImageFormat_A8B8G8R8_SNORM_PACK32:
	case ImageFormat_R8G8B8_SNORM:
	case ImageFormat_B8G8R8_SNORM:
	case ImageFormat_R8G8_SNORM:
	case ImageFormat_R8_SNORM:
	case ImageFormat_R8G8B8A8_SSCALED:
	case ImageFormat_B8G8R8A8_SSCALED:
	case ImageFormat_A8B8G8R8_SSCALED_PACK32:
	case ImageFormat_R8G8B8_SSCALED:
	case ImageFormat_B8G8R8_SSCALED:
	case ImageFormat_R8G8_SSCALED:
	case ImageFormat_R8_SSCALED:
	case ImageFormat_R8G8B8A8_SINT:
	case ImageFormat_B8G8R8A8_SINT:
	case ImageFormat_A8B8G8R8_SINT_PACK32:
	case ImageFormat_R8G8B8_SINT:
	case ImageFormat_B8G8R8_SINT:
	case ImageFormat_R8G8_SINT:
	case ImageFormat_R8_SINT:return INT8_MIN;

	case ImageFormat_BC4_SNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK: return INT8_MIN;

	case ImageFormat_UNDEFINED: return 0.0;

	default:LOGWARNINGF("min %s not handled", ImageFormat_Name(fmt));
		return 0.0;
	}
}
// the channels the same? Compressed are treated as true as
// each block are basically the same (BC6H and BC7 are ignored)
AL2O3_EXTERN_C inline bool ImageFormat_IsHomogenous(ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_R5G5B5A1_UNORM_PACK16:
	case ImageFormat_B5G5R5A1_UNORM_PACK16:
	case ImageFormat_A1R5G5B5_UNORM_PACK16:
	case ImageFormat_A2R10G10B10_UNORM_PACK32:
	case ImageFormat_A2R10G10B10_USCALED_PACK32:
	case ImageFormat_A2R10G10B10_UINT_PACK32:
	case ImageFormat_A2B10G10R10_UNORM_PACK32:
	case ImageFormat_A2B10G10R10_USCALED_PACK32:
	case ImageFormat_A2B10G10R10_UINT_PACK32:
	case ImageFormat_X8_D24_UNORM_PACK32:
	case ImageFormat_D32_SFLOAT_S8_UINT:return false;
	default: return true;
	}
}

AL2O3_EXTERN_C inline bool ImageFormat_IsPVR(ImageFormat fmt) {
	switch (fmt) {
	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:return true;
	default: return false;
	}
}
typedef uint8_t *Image_Swizzle;
AL2O3_EXTERN_C Image_Swizzle ImageFormat_Swizzle_RGBA;
AL2O3_EXTERN_C Image_Swizzle ImageFormat_Swizzle_ARGB;
AL2O3_EXTERN_C Image_Swizzle ImageFormat_Swizzle_BGRA;
AL2O3_EXTERN_C Image_Swizzle ImageFormat_Swizzle_ABGR;

AL2O3_EXTERN_C inline Image_Swizzle ImageFormat_Swizzle(enum ImageFormat fmt_) {
	switch (fmt_) {
	case ImageFormat_UNDEFINED:
	case ImageFormat_R64G64B64A64_UINT:
	case ImageFormat_R64G64B64_UINT:
	case ImageFormat_R64G64_UINT:
	case ImageFormat_R64_UINT:
	case ImageFormat_R64G64B64A64_SINT:
	case ImageFormat_R64G64B64_SINT:
	case ImageFormat_R64G64_SINT:
	case ImageFormat_R64_SINT:
	case ImageFormat_R64G64B64_SFLOAT:
	case ImageFormat_R64G64B64A64_SFLOAT:
	case ImageFormat_R64G64_SFLOAT:
	case ImageFormat_R64_SFLOAT:
	case ImageFormat_R32G32B32A32_UINT:
	case ImageFormat_R32G32B32_UINT:
	case ImageFormat_R32G32_UINT:
	case ImageFormat_R32_UINT:
	case ImageFormat_R32G32B32A32_SINT:
	case ImageFormat_R32G32B32_SINT:
	case ImageFormat_R32G32_SINT:
	case ImageFormat_R32_SINT:
	case ImageFormat_R32G32B32A32_SFLOAT:
	case ImageFormat_R32G32B32_SFLOAT:
	case ImageFormat_R32G32_SFLOAT:
	case ImageFormat_R32_SFLOAT:
	case ImageFormat_D32_SFLOAT:
	case ImageFormat_R16G16B16A16_UNORM:
	case ImageFormat_R16G16B16_UNORM:
	case ImageFormat_R16G16_UNORM:
	case ImageFormat_R16_UNORM:
	case ImageFormat_D16_UNORM:
	case ImageFormat_R16G16B16A16_USCALED:
	case ImageFormat_R16G16B16_USCALED:
	case ImageFormat_R16G16_USCALED:
	case ImageFormat_R16_USCALED:
	case ImageFormat_R16G16B16A16_UINT:
	case ImageFormat_R16G16B16_UINT:
	case ImageFormat_R16G16_UINT:
	case ImageFormat_R16_UINT:
	case ImageFormat_R16G16B16A16_SNORM:
	case ImageFormat_R16G16B16_SNORM:
	case ImageFormat_R16G16_SNORM:
	case ImageFormat_R16_SNORM:
	case ImageFormat_R16G16B16A16_SSCALED:
	case ImageFormat_R16G16B16_SSCALED:
	case ImageFormat_R16G16_SSCALED:
	case ImageFormat_R16_SSCALED:
	case ImageFormat_R16G16B16A16_SINT:
	case ImageFormat_R16G16B16_SINT:
	case ImageFormat_R16G16_SINT:
	case ImageFormat_R16_SINT:
	case ImageFormat_R16G16B16A16_SFLOAT:
	case ImageFormat_R16G16B16_SFLOAT:
	case ImageFormat_R16G16_SFLOAT:
	case ImageFormat_R16_SFLOAT:
	case ImageFormat_D32_SFLOAT_S8_UINT:
	case ImageFormat_R8G8B8A8_UNORM:
	case ImageFormat_R8G8B8A8_USCALED:
	case ImageFormat_R8G8B8A8_UINT:
	case ImageFormat_R8G8B8_USCALED:
	case ImageFormat_R8G8B8_UNORM:
	case ImageFormat_R8G8B8_UINT:
	case ImageFormat_R8G8B8A8_SRGB:
	case ImageFormat_R8G8_UNORM:
	case ImageFormat_R8G8_USCALED:
	case ImageFormat_R8_USCALED:
	case ImageFormat_R8_UNORM:
	case ImageFormat_R8G8_UINT:
	case ImageFormat_R8_UINT:
	case ImageFormat_S8_UINT:
	case ImageFormat_R8G8B8_SRGB:
	case ImageFormat_R8G8_SRGB:
	case ImageFormat_R8_SRGB:
	case ImageFormat_R8G8B8A8_SNORM:
	case ImageFormat_R8G8B8_SNORM:
	case ImageFormat_R8G8_SNORM:
	case ImageFormat_R8_SNORM:
	case ImageFormat_R8G8B8A8_SSCALED:
	case ImageFormat_R8G8_SSCALED:
	case ImageFormat_R8_SSCALED:
	case ImageFormat_R8G8B8A8_SINT:
	case ImageFormat_R8G8B8_SINT:
	case ImageFormat_R8G8_SINT:
	case ImageFormat_R8_SINT:
	case ImageFormat_R8G8B8_SSCALED:
	case ImageFormat_R4G4B4A4_UNORM_PACK16:
	case ImageFormat_X8_D24_UNORM_PACK32:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_D16_UNORM_S8_UINT:
	case ImageFormat_R4G4_UNORM_PACK8:
	case ImageFormat_R5G6B5_UNORM_PACK16:
	case ImageFormat_R5G5B5A1_UNORM_PACK16:return ImageFormat_Swizzle_RGBA;

	case ImageFormat_A2R10G10B10_UNORM_PACK32:
	case ImageFormat_A2R10G10B10_USCALED_PACK32:
	case ImageFormat_A2R10G10B10_UINT_PACK32:
	case ImageFormat_A1R5G5B5_UNORM_PACK16:
	case ImageFormat_A4R4G4B4_UNORM_PACK16:
	case ImageFormat_A8R8G8B8_UNORM_PACK32:
		return ImageFormat_Swizzle_ARGB;

	case ImageFormat_A2B10G10R10_UNORM_PACK32:
	case ImageFormat_A2B10G10R10_USCALED_PACK32:
	case ImageFormat_A2B10G10R10_UINT_PACK32:
	case ImageFormat_A8B8G8R8_SRGB_PACK32:
	case ImageFormat_A8B8G8R8_USCALED_PACK32:
	case ImageFormat_A8B8G8R8_UNORM_PACK32:
	case ImageFormat_A8B8G8R8_UINT_PACK32:
	case ImageFormat_A8B8G8R8_SNORM_PACK32:
	case ImageFormat_A8B8G8R8_SSCALED_PACK32:
	case ImageFormat_A8B8G8R8_SINT_PACK32:return ImageFormat_Swizzle_ABGR;

	case ImageFormat_B8G8R8A8_UNORM:
	case ImageFormat_B8G8R8A8_USCALED:
	case ImageFormat_B8G8R8A8_UINT:
	case ImageFormat_B8G8R8A8_SRGB:
	case ImageFormat_B8G8R8A8_SNORM:
	case ImageFormat_B8G8R8A8_SSCALED:
	case ImageFormat_B8G8R8A8_SINT:
	case ImageFormat_B4G4R4A4_UNORM_PACK16:
	case ImageFormat_B5G5R5A1_UNORM_PACK16:return ImageFormat_Swizzle_BGRA;

	case ImageFormat_B8G8R8_SNORM:
	case ImageFormat_B8G8R8_UNORM:
	case ImageFormat_B8G8R8_USCALED:
	case ImageFormat_B8G8R8_UINT:
	case ImageFormat_B8G8R8_SSCALED:
	case ImageFormat_B8G8R8_SINT:
	case ImageFormat_B5G6R5_UNORM_PACK16:
	case ImageFormat_B8G8R8_SRGB:return ImageFormat_Swizzle_BGRA;

	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC5_SNORM_BLOCK:
	case ImageFormat_BC6H_UFLOAT_BLOCK:
	case ImageFormat_BC6H_SFLOAT_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:
	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC4_SNORM_BLOCK:

		// TODO check PVR swizzle order!
	case ImageFormat_PVR_2BPP_UNORM_BLOCK:
	case ImageFormat_PVR_2BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_4BPP_UNORM_BLOCK:
	case ImageFormat_PVR_4BPPA_UNORM_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:return ImageFormat_Swizzle_RGBA;

	default:LOGERRORF("swizzleFormat %s not handled", ImageFormat_Name(fmt_));
		return ImageFormat_Swizzle_RGBA;
	}
}

typedef enum TinyImageFormat_DXGI_FORMAT {
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

#ifdef TINYDDS_DEFINED
#error TinyImageFormat must be included before tinydds.h if both are used
#endif

typedef enum TinyDDS_Format {
	TDDS_UNDEFINED = TIF_DXGI_FORMAT_UNKNOWN,
	TDDS_B4G4R4A4_UNORM = TIF_DXGI_FORMAT_B4G4R4A4_UNORM,
	TDDS_B5G6R5_UNORM = TIF_DXGI_FORMAT_B5G6R5_UNORM,
	TDDS_R5G5B5A1_UNORM = TIF_DXGI_FORMAT_B5G5R5A1_UNORM,
	TDDS_R8_UNORM = TIF_DXGI_FORMAT_R8_UNORM,
	TDDS_R8_SNORM = TIF_DXGI_FORMAT_R8_SNORM,
	TDDS_R8_UINT = TIF_DXGI_FORMAT_R8_UINT,
	TDDS_R8_SINT = TIF_DXGI_FORMAT_R8_SINT,
	TDDS_R8G8_UNORM = TIF_DXGI_FORMAT_R8G8_UNORM,
	TDDS_R8G8_SNORM = TIF_DXGI_FORMAT_R8G8_SNORM,
	TDDS_R8G8_UINT = TIF_DXGI_FORMAT_R8G8_UINT,
	TDDS_R8G8_SINT = TIF_DXGI_FORMAT_R8G8_SINT,
	TDDS_R8G8B8A8_UNORM = TIF_DXGI_FORMAT_R8G8B8A8_UNORM,
	TDDS_R8G8B8A8_SNORM = TIF_DXGI_FORMAT_R8G8B8A8_SNORM,
	TDDS_R8G8B8A8_UINT = TIF_DXGI_FORMAT_R8G8B8A8_UINT,
	TDDS_R8G8B8A8_SINT = TIF_DXGI_FORMAT_R8G8B8A8_SINT,
	TDDS_R8G8B8A8_SRGB = TIF_DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
	TDDS_B8G8R8A8_UNORM = TIF_DXGI_FORMAT_B8G8R8A8_UNORM,
	TDDS_B8G8R8A8_SRGB = TIF_DXGI_FORMAT_B8G8R8A8_UNORM_SRGB,

	TDDS_R9G9B9E5_UFLOAT = TIF_DXGI_FORMAT_R9G9B9E5_SHAREDEXP,
	TDDS_R10G10B10A2_UNORM = TIF_DXGI_FORMAT_R10G10B10A2_UNORM,
	TDDS_R10G10B10A2_UINT = TIF_DXGI_FORMAT_R10G10B10A2_UINT,
	TDDS_R11G11B10_UFLOAT = TIF_DXGI_FORMAT_R11G11B10_FLOAT,

	TDDS_R16_UNORM = TIF_DXGI_FORMAT_R16_UNORM,
	TDDS_R16_SNORM = TIF_DXGI_FORMAT_R16_SNORM,
	TDDS_R16_UINT = TIF_DXGI_FORMAT_R16_UINT,
	TDDS_R16_SINT = TIF_DXGI_FORMAT_R16_SINT,
	TDDS_R16_SFLOAT = TIF_DXGI_FORMAT_R16_FLOAT,

	TDDS_R16G16_UNORM = TIF_DXGI_FORMAT_R16G16_UNORM,
	TDDS_R16G16_SNORM = TIF_DXGI_FORMAT_R16G16_SNORM,
	TDDS_R16G16_UINT = TIF_DXGI_FORMAT_R16G16_UINT,
	TDDS_R16G16_SINT = TIF_DXGI_FORMAT_R16G16_SINT,
	TDDS_R16G16_SFLOAT = TIF_DXGI_FORMAT_R16G16_FLOAT,

	TDDS_R16G16B16A16_UNORM = TIF_DXGI_FORMAT_R16G16B16A16_UNORM,
	TDDS_R16G16B16A16_SNORM = TIF_DXGI_FORMAT_R16G16B16A16_SNORM,
	TDDS_R16G16B16A16_UINT = TIF_DXGI_FORMAT_R16G16B16A16_UINT,
	TDDS_R16G16B16A16_SINT = TIF_DXGI_FORMAT_R16G16B16A16_SINT,
	TDDS_R16G16B16A16_SFLOAT = TIF_DXGI_FORMAT_R16G16B16A16_FLOAT,

	TDDS_R32_UINT = TIF_DXGI_FORMAT_R32_UINT,
	TDDS_R32_SINT = TIF_DXGI_FORMAT_R32_SINT,
	TDDS_R32_SFLOAT = TIF_DXGI_FORMAT_R32_FLOAT,

	TDDS_R32G32_UINT = TIF_DXGI_FORMAT_R32G32_UINT,
	TDDS_R32G32_SINT = TIF_DXGI_FORMAT_R32G32_SINT,
	TDDS_R32G32_SFLOAT = TIF_DXGI_FORMAT_R32G32_FLOAT,

	TDDS_R32G32B32_UINT = TIF_DXGI_FORMAT_R32G32B32_UINT,
	TDDS_R32G32B32_SINT = TIF_DXGI_FORMAT_R32G32B32_SINT,
	TDDS_R32G32B32_SFLOAT = TIF_DXGI_FORMAT_R32G32B32_FLOAT,

	TDDS_R32G32B32A32_UINT = TIF_DXGI_FORMAT_R32G32B32A32_UINT,
	TDDS_R32G32B32A32_SINT = TIF_DXGI_FORMAT_R32G32B32A32_SINT,
	TDDS_R32G32B32A32_SFLOAT = TIF_DXGI_FORMAT_R32G32B32A32_FLOAT,

	TDDS_BC1_RGBA_UNORM_BLOCK = TIF_DXGI_FORMAT_BC1_UNORM,
	TDDS_BC1_RGBA_SRGB_BLOCK = TIF_DXGI_FORMAT_BC1_UNORM_SRGB,
	TDDS_BC2_UNORM_BLOCK = TIF_DXGI_FORMAT_BC2_UNORM,
	TDDS_BC2_SRGB_BLOCK = TIF_DXGI_FORMAT_BC2_UNORM_SRGB,
	TDDS_BC3_UNORM_BLOCK = TIF_DXGI_FORMAT_BC3_UNORM,
	TDDS_BC3_SRGB_BLOCK = TIF_DXGI_FORMAT_BC3_UNORM_SRGB,
	TDDS_BC4_UNORM_BLOCK = TIF_DXGI_FORMAT_BC4_UNORM,
	TDDS_BC4_SNORM_BLOCK = TIF_DXGI_FORMAT_BC4_SNORM,
	TDDS_BC5_UNORM_BLOCK = TIF_DXGI_FORMAT_BC5_UNORM,
	TDDS_BC5_SNORM_BLOCK = TIF_DXGI_FORMAT_BC5_SNORM,

	TDDS_BC6H_UFLOAT_BLOCK = TIF_DXGI_FORMAT_BC6H_UF16,
	TDDS_BC6H_SFLOAT_BLOCK = TIF_DXGI_FORMAT_BC6H_SF16,
	TDDS_BC7_UNORM_BLOCK = TIF_DXGI_FORMAT_BC7_UNORM,
	TDDS_BC7_SRGB_BLOCK = TIF_DXGI_FORMAT_BC7_UNORM_SRGB,

	TDDS_SYNTHESISED_DXGIFORMATS = 0xFFFF,
	TDDS_R4G4_UNORM = TDDS_SYNTHESISED_DXGIFORMATS,
	TDDS_R4G4B4A4_UNORM,
	TDDS_A4R4G4B4_UNORM,
	TDDS_R5G6B5_UNORM,
	TDDS_B5G5R5A1_UNORM,
	TDDS_A1R5G5B5_UNORM,
	TDDS_R8_SRGB,
	TDDS_R8G8_SRGB,
	TDDS_R8G8B8_UNORM,
	TDDS_R8G8B8_SNORM,
	TDDS_R8G8B8_UINT,
	TDDS_R8G8B8_SINT,
	TDDS_R8G8B8_SRGB,
	TDDS_B8G8R8_UNORM,
	TDDS_B8G8R8_SNORM,
	TDDS_B8G8R8_UINT,
	TDDS_B8G8R8_SINT,
	TDDS_B8G8R8_SRGB,

	TDDS_A8B8G8R8_UNORM,
	TDDS_A8B8G8R8_SNORM,
	TDDS_A8B8G8R8_UINT,
	TDDS_A8B8G8R8_SINT,
	TDDS_A8B8G8R8_SRGB,

	TDDS_A8R8G8B8_UNORM,

	TDDS_B8G8R8A8_SNORM,
	TDDS_B8G8R8A8_UINT,
	TDDS_B8G8R8A8_SINT,

	TDDS_R16G16B16_UNORM,
	TDDS_R16G16B16_SNORM,
	TDDS_R16G16B16_UINT,
	TDDS_R16G16B16_SINT,
	TDDS_R16G16B16_SFLOAT,

	TDDS_A2B10G10R10_UNORM,
	TDDS_A2B10G10R10_UINT,
	TDDS_BC1_RGB_UNORM_BLOCK,
	TDDS_BC1_RGB_SRGB_BLOCK,

} TinyDDS_Format;

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

#ifdef TINYKTX_DEFINED
#error TinyImageFormat must be included before tinyktx.h if both are used
#endif

#define TINYKTX_MEV(x) TKTX_##x = TIF_VK_FORMAT_##x
typedef enum TinyKtx_Format {
	TINYKTX_MEV(UNDEFINED),
	TINYKTX_MEV(R4G4_UNORM_PACK8),
	TINYKTX_MEV(R4G4B4A4_UNORM_PACK16),
	TINYKTX_MEV(B4G4R4A4_UNORM_PACK16),
	TINYKTX_MEV(R5G6B5_UNORM_PACK16),
	TINYKTX_MEV(B5G6R5_UNORM_PACK16),
	TINYKTX_MEV(R5G5B5A1_UNORM_PACK16),
	TINYKTX_MEV(B5G5R5A1_UNORM_PACK16),
	TINYKTX_MEV(A1R5G5B5_UNORM_PACK16),

	TINYKTX_MEV(R8_UNORM),
	TINYKTX_MEV(R8_SNORM),
	TINYKTX_MEV(R8_UINT),
	TINYKTX_MEV(R8_SINT),
	TINYKTX_MEV(R8_SRGB),

	TINYKTX_MEV(R8G8_UNORM),
	TINYKTX_MEV(R8G8_SNORM),
	TINYKTX_MEV(R8G8_UINT),
	TINYKTX_MEV(R8G8_SINT),
	TINYKTX_MEV(R8G8_SRGB),

	TINYKTX_MEV(R8G8B8_UNORM),
	TINYKTX_MEV(R8G8B8_SNORM),
	TINYKTX_MEV(R8G8B8_UINT),
	TINYKTX_MEV(R8G8B8_SINT),
	TINYKTX_MEV(R8G8B8_SRGB),
	TINYKTX_MEV(B8G8R8_UNORM),
	TINYKTX_MEV(B8G8R8_SNORM),
	TINYKTX_MEV(B8G8R8_UINT),
	TINYKTX_MEV(B8G8R8_SINT),
	TINYKTX_MEV(B8G8R8_SRGB),

	TINYKTX_MEV(R8G8B8A8_UNORM),
	TINYKTX_MEV(R8G8B8A8_SNORM),
	TINYKTX_MEV(R8G8B8A8_UINT),
	TINYKTX_MEV(R8G8B8A8_SINT),
	TINYKTX_MEV(R8G8B8A8_SRGB),
	TINYKTX_MEV(B8G8R8A8_UNORM),
	TINYKTX_MEV(B8G8R8A8_SNORM),
	TINYKTX_MEV(B8G8R8A8_UINT),
	TINYKTX_MEV(B8G8R8A8_SINT),
	TINYKTX_MEV(B8G8R8A8_SRGB),

	TINYKTX_MEV(A8B8G8R8_UNORM_PACK32),
	TINYKTX_MEV(A8B8G8R8_SNORM_PACK32),
	TINYKTX_MEV(A8B8G8R8_UINT_PACK32),
	TINYKTX_MEV(A8B8G8R8_SINT_PACK32),
	TINYKTX_MEV(A8B8G8R8_SRGB_PACK32),

	TINYKTX_MEV(E5B9G9R9_UFLOAT_PACK32),
	TINYKTX_MEV(A2R10G10B10_UNORM_PACK32),
	TINYKTX_MEV(A2R10G10B10_UINT_PACK32),
	TINYKTX_MEV(A2B10G10R10_UNORM_PACK32),
	TINYKTX_MEV(A2B10G10R10_UINT_PACK32),
	TINYKTX_MEV(B10G11R11_UFLOAT_PACK32),

	TINYKTX_MEV(R16_UNORM),
	TINYKTX_MEV(R16_SNORM),
	TINYKTX_MEV(R16_UINT),
	TINYKTX_MEV(R16_SINT),
	TINYKTX_MEV(R16_SFLOAT),
	TINYKTX_MEV(R16G16_UNORM),
	TINYKTX_MEV(R16G16_SNORM),
	TINYKTX_MEV(R16G16_UINT),
	TINYKTX_MEV(R16G16_SINT),
	TINYKTX_MEV(R16G16_SFLOAT),
	TINYKTX_MEV(R16G16B16_UNORM),
	TINYKTX_MEV(R16G16B16_SNORM),
	TINYKTX_MEV(R16G16B16_UINT),
	TINYKTX_MEV(R16G16B16_SINT),
	TINYKTX_MEV(R16G16B16_SFLOAT),
	TINYKTX_MEV(R16G16B16A16_UNORM),
	TINYKTX_MEV(R16G16B16A16_SNORM),
	TINYKTX_MEV(R16G16B16A16_UINT),
	TINYKTX_MEV(R16G16B16A16_SINT),
	TINYKTX_MEV(R16G16B16A16_SFLOAT),
	TINYKTX_MEV(R32_UINT),
	TINYKTX_MEV(R32_SINT),
	TINYKTX_MEV(R32_SFLOAT),
	TINYKTX_MEV(R32G32_UINT),
	TINYKTX_MEV(R32G32_SINT),
	TINYKTX_MEV(R32G32_SFLOAT),
	TINYKTX_MEV(R32G32B32_UINT),
	TINYKTX_MEV(R32G32B32_SINT),
	TINYKTX_MEV(R32G32B32_SFLOAT),
	TINYKTX_MEV(R32G32B32A32_UINT),
	TINYKTX_MEV(R32G32B32A32_SINT),
	TINYKTX_MEV(R32G32B32A32_SFLOAT),

	TINYKTX_MEV(BC1_RGB_UNORM_BLOCK),
	TINYKTX_MEV(BC1_RGB_SRGB_BLOCK),
	TINYKTX_MEV(BC1_RGBA_UNORM_BLOCK),
	TINYKTX_MEV(BC1_RGBA_SRGB_BLOCK),
	TINYKTX_MEV(BC2_UNORM_BLOCK),
	TINYKTX_MEV(BC2_SRGB_BLOCK),
	TINYKTX_MEV(BC3_UNORM_BLOCK),
	TINYKTX_MEV(BC3_SRGB_BLOCK),
	TINYKTX_MEV(BC4_UNORM_BLOCK),
	TINYKTX_MEV(BC4_SNORM_BLOCK),
	TINYKTX_MEV(BC5_UNORM_BLOCK),
	TINYKTX_MEV(BC5_SNORM_BLOCK),
	TINYKTX_MEV(BC6H_UFLOAT_BLOCK),
	TINYKTX_MEV(BC6H_SFLOAT_BLOCK),
	TINYKTX_MEV(BC7_UNORM_BLOCK),
	TINYKTX_MEV(BC7_SRGB_BLOCK),

	TINYKTX_MEV(ETC2_R8G8B8_UNORM_BLOCK),
	TINYKTX_MEV(ETC2_R8G8B8A1_UNORM_BLOCK),
	TINYKTX_MEV(ETC2_R8G8B8A8_UNORM_BLOCK),
	TINYKTX_MEV(ETC2_R8G8B8_SRGB_BLOCK),
	TINYKTX_MEV(ETC2_R8G8B8A1_SRGB_BLOCK),
	TINYKTX_MEV(ETC2_R8G8B8A8_SRGB_BLOCK),
	TINYKTX_MEV(EAC_R11_UNORM_BLOCK),
	TINYKTX_MEV(EAC_R11G11_UNORM_BLOCK),
	TINYKTX_MEV(EAC_R11_SNORM_BLOCK),
	TINYKTX_MEV(EAC_R11G11_SNORM_BLOCK),

	TKTX_PVR_2BPP_BLOCK = TIF_VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG,
	TKTX_PVR_2BPPA_BLOCK = TIF_VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG,
	TKTX_PVR_4BPP_BLOCK = TIF_VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG,
	TKTX_PVR_4BPPA_BLOCK = TIF_VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG,
	TKTX_PVR_2BPP_SRGB_BLOCK = TIF_VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG,
	TKTX_PVR_2BPPA_SRGB_BLOCK = TIF_VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG,
	TKTX_PVR_4BPP_SRGB_BLOCK = TIF_VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG,
	TKTX_PVR_4BPPA_SRGB_BLOCK = TIF_VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG,

	TINYKTX_MEV(ASTC_4x4_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_4x4_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_5x4_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_5x4_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_5x5_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_5x5_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_6x5_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_6x5_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_6x6_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_6x6_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_8x5_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_8x5_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_8x6_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_8x6_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_8x8_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_8x8_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_10x5_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_10x5_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_10x6_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_10x6_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_10x8_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_10x8_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_10x10_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_10x10_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_12x10_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_12x10_SRGB_BLOCK),
	TINYKTX_MEV(ASTC_12x12_UNORM_BLOCK),
	TINYKTX_MEV(ASTC_12x12_SRGB_BLOCK),

} TinyKtx_Format;
#undef TINYKTX_MEV

#define TINYKTX_DEFINED
#define TINYDDS_DEFINED

static ImageFormat ImageFormat_FromTinyDDSFormat(TinyDDS_Format fmt) {
	switch (fmt) {
	case TDDS_R32G32B32A32_SFLOAT: return ImageFormat_R32G32B32A32_SFLOAT;
	case TDDS_R32G32B32A32_UINT: return ImageFormat_R32G32B32A32_UINT;
	case TDDS_R32G32B32A32_SINT: return ImageFormat_R32G32B32A32_SINT;
	case TDDS_R32G32B32_SFLOAT: return ImageFormat_R32G32B32_SFLOAT;
	case TDDS_R32G32B32_UINT: return ImageFormat_R32G32B32_UINT;
	case TDDS_R32G32B32_SINT: return ImageFormat_R32G32B32_SINT;
	case TDDS_R16G16B16A16_SFLOAT: return ImageFormat_R16G16B16A16_SFLOAT;
	case TDDS_R16G16B16A16_UNORM: return ImageFormat_R16G16B16A16_UNORM;
	case TDDS_R16G16B16A16_UINT: return ImageFormat_R16G16B16A16_UINT;
	case TDDS_R16G16B16A16_SNORM: return ImageFormat_R16G16B16A16_SNORM;
	case TDDS_R16G16B16A16_SINT: return ImageFormat_R16G16B16A16_SINT;
	case TDDS_R32G32_SFLOAT: return ImageFormat_R32G32_SFLOAT;
	case TDDS_R32G32_UINT: return ImageFormat_R32G32_UINT;
	case TDDS_R32G32_SINT: return ImageFormat_R32G32_SINT;
	case TDDS_R10G10B10A2_UNORM: return ImageFormat_A2B10G10R10_UNORM_PACK32;
	case TDDS_R10G10B10A2_UINT: return ImageFormat_A2B10G10R10_UINT_PACK32;
	case TDDS_R8G8B8A8_UNORM: return ImageFormat_R8G8B8A8_UNORM;
	case TDDS_R8G8B8A8_SRGB: return ImageFormat_R8G8B8A8_SRGB;
	case TDDS_R8G8B8A8_UINT: return ImageFormat_R8G8B8A8_UINT;
	case TDDS_R8G8B8A8_SNORM: return ImageFormat_R8G8B8A8_SNORM;
	case TDDS_R8G8B8A8_SINT: return ImageFormat_R8G8B8A8_SINT;
	case TDDS_R16G16_SFLOAT: return ImageFormat_R16G16_SFLOAT;
	case TDDS_R16G16_UNORM: return ImageFormat_R16G16_UNORM;
	case TDDS_R16G16_UINT: return ImageFormat_R16G16_UINT;
	case TDDS_R16G16_SNORM: return ImageFormat_R16G16_SNORM;
	case TDDS_R16G16_SINT: return ImageFormat_R16G16_SINT;
	case TDDS_R32_SFLOAT: return ImageFormat_R32_SFLOAT;
	case TDDS_R32_UINT: return ImageFormat_R32_UINT;
	case TDDS_R32_SINT: return ImageFormat_R32_SINT;
	case TDDS_R8G8_UNORM: return ImageFormat_R8G8_UNORM;
	case TDDS_R8G8_UINT: return ImageFormat_R8G8_UINT;
	case TDDS_R8G8_SNORM: return ImageFormat_R8G8_SNORM;
	case TDDS_R8G8_SINT: return ImageFormat_R8G8_SINT;
	case TDDS_R16_SFLOAT: return ImageFormat_R16_SFLOAT;
	case TDDS_R16_UNORM: return ImageFormat_R16_UNORM;
	case TDDS_R16_UINT: return ImageFormat_R16_UINT;
	case TDDS_R16_SNORM: return ImageFormat_R16_SNORM;
	case TDDS_R16_SINT: return ImageFormat_R16_SINT;
	case TDDS_R8_UNORM: return ImageFormat_R8_UNORM;
	case TDDS_R8_UINT: return ImageFormat_R8_UINT;
	case TDDS_R8_SNORM: return ImageFormat_R8_SNORM;
	case TDDS_R8_SINT: return ImageFormat_R8_SINT;
	case TDDS_BC1_RGB_UNORM_BLOCK: return ImageFormat_BC1_RGB_UNORM_BLOCK;
	case TDDS_BC1_RGBA_UNORM_BLOCK: return ImageFormat_BC1_RGBA_UNORM_BLOCK;
	case TDDS_BC2_UNORM_BLOCK: return ImageFormat_BC2_UNORM_BLOCK;
	case TDDS_BC2_SRGB_BLOCK: return ImageFormat_BC2_SRGB_BLOCK;
	case TDDS_BC3_UNORM_BLOCK: return ImageFormat_BC3_UNORM_BLOCK;
	case TDDS_BC3_SRGB_BLOCK: return ImageFormat_BC3_SRGB_BLOCK;
	case TDDS_BC4_UNORM_BLOCK: return ImageFormat_BC4_UNORM_BLOCK;
	case TDDS_BC4_SNORM_BLOCK: return ImageFormat_BC4_SNORM_BLOCK;
	case TDDS_BC5_UNORM_BLOCK: return ImageFormat_BC5_UNORM_BLOCK;
	case TDDS_BC5_SNORM_BLOCK: return ImageFormat_BC5_SNORM_BLOCK;
	case TDDS_BC6H_UFLOAT_BLOCK: return ImageFormat_BC6H_UFLOAT_BLOCK;
	case TDDS_BC6H_SFLOAT_BLOCK: return ImageFormat_BC6H_SFLOAT_BLOCK;
	case TDDS_BC7_UNORM_BLOCK: return ImageFormat_BC7_UNORM_BLOCK;
	case TDDS_BC7_SRGB_BLOCK: return ImageFormat_BC7_SRGB_BLOCK;
	case TDDS_B5G6R5_UNORM: return ImageFormat_B5G6R5_UNORM_PACK16;
	case TDDS_B5G5R5A1_UNORM: return ImageFormat_B5G5R5A1_UNORM_PACK16;
	case TDDS_B8G8R8A8_UNORM: return ImageFormat_B8G8R8A8_UNORM;
	case TDDS_B8G8R8A8_SRGB: return ImageFormat_B8G8R8A8_SRGB;
	case TDDS_B4G4R4A4_UNORM: return ImageFormat_B4G4R4A4_UNORM_PACK16;

	case TDDS_R4G4_UNORM: return ImageFormat_R4G4_UNORM_PACK8;
	case TDDS_R4G4B4A4_UNORM: return ImageFormat_R4G4B4A4_UNORM_PACK16;
	case TDDS_R5G6B5_UNORM: return ImageFormat_R5G6B5_UNORM_PACK16;
	case TDDS_A1R5G5B5_UNORM: return ImageFormat_A1R5G5B5_UNORM_PACK16;
	case TDDS_R8_SRGB: return ImageFormat_R8_SRGB;
	case TDDS_R8G8_SRGB: return ImageFormat_R8G8_SRGB;
	case TDDS_R8G8B8_UNORM: return ImageFormat_R8G8B8_UNORM;
	case TDDS_R8G8B8_SNORM: return ImageFormat_R8G8B8_SNORM;
	case TDDS_R8G8B8_UINT:  return ImageFormat_R8G8B8_UINT;
	case TDDS_R8G8B8_SINT:  return ImageFormat_R8G8B8_SINT;
	case TDDS_R8G8B8_SRGB:	return ImageFormat_R8G8B8_SRGB;
	case TDDS_B8G8R8_UNORM:	return ImageFormat_B8G8R8_UNORM;
	case TDDS_B8G8R8_SNORM:	return ImageFormat_B8G8R8_SNORM;
	case TDDS_B8G8R8_UINT:	return ImageFormat_B8G8R8_UINT;
	case TDDS_B8G8R8_SINT:	return ImageFormat_B8G8R8_SINT;
	case TDDS_B8G8R8_SRGB:	return ImageFormat_B8G8R8_SRGB;
	case TDDS_A8B8G8R8_UNORM:	return ImageFormat_A8B8G8R8_UNORM_PACK32;
	case TDDS_A8B8G8R8_SNORM:	return ImageFormat_A8B8G8R8_SNORM_PACK32;
	case TDDS_A8B8G8R8_UINT:		return ImageFormat_A8B8G8R8_UINT_PACK32;
	case TDDS_A8B8G8R8_SINT:		return ImageFormat_A8B8G8R8_SINT_PACK32;
	case TDDS_A8B8G8R8_SRGB:		return ImageFormat_A8B8G8R8_SRGB_PACK32;
	case TDDS_B8G8R8A8_SNORM:					return ImageFormat_B8G8R8A8_SNORM;
	case TDDS_B8G8R8A8_UINT:					return ImageFormat_B8G8R8A8_UINT;
	case TDDS_B8G8R8A8_SINT:					return ImageFormat_B8G8R8A8_SINT;
	case TDDS_R16G16B16_UNORM:				return ImageFormat_R16G16B16_UNORM;
	case TDDS_R16G16B16_SNORM:				return ImageFormat_R16G16B16_SNORM;
	case TDDS_R16G16B16_UINT:					return ImageFormat_R16G16B16_UINT;
	case TDDS_R16G16B16_SINT:					return ImageFormat_R16G16B16_SINT;
	case TDDS_R16G16B16_SFLOAT:				return ImageFormat_R16G16B16_SFLOAT;
	case TDDS_A2B10G10R10_UNORM:	return ImageFormat_A2B10G10R10_UNORM_PACK32;
	case TDDS_A2B10G10R10_UINT:	return ImageFormat_A2B10G10R10_UINT_PACK32;
	case TDDS_BC1_RGB_SRGB_BLOCK:			return ImageFormat_BC1_RGB_SRGB_BLOCK;
	case TDDS_A4R4G4B4_UNORM:	return ImageFormat_A4R4G4B4_UNORM_PACK16;
	case TDDS_A8R8G8B8_UNORM:	return ImageFormat_A8R8G8B8_UNORM_PACK32;
	default:
		return ImageFormat_UNDEFINED;
	case TDDS_UNDEFINED:
		return ImageFormat_UNDEFINED;
	}
}

static ImageFormat ImageFormat_FromTinyKtxFormat(TinyKtx_Format format) {
	switch(format) {
	case TKTX_UNDEFINED: return ImageFormat_UNDEFINED;
	case TKTX_R4G4_UNORM_PACK8: return ImageFormat_R4G4_UNORM_PACK8;
	case TKTX_R4G4B4A4_UNORM_PACK16: return ImageFormat_R4G4B4A4_UNORM_PACK16;
	case TKTX_B4G4R4A4_UNORM_PACK16: return ImageFormat_B4G4R4A4_UNORM_PACK16;
	case TKTX_R5G6B5_UNORM_PACK16: return ImageFormat_R5G6B5_UNORM_PACK16;
	case TKTX_B5G6R5_UNORM_PACK16: return ImageFormat_B5G6R5_UNORM_PACK16;
	case TKTX_R5G5B5A1_UNORM_PACK16: return ImageFormat_R5G5B5A1_UNORM_PACK16;
	case TKTX_B5G5R5A1_UNORM_PACK16: return ImageFormat_B5G5R5A1_UNORM_PACK16;
	case TKTX_A1R5G5B5_UNORM_PACK16: return ImageFormat_A1R5G5B5_UNORM_PACK16;
	case TKTX_R8_UNORM: return ImageFormat_R8_UNORM;
	case TKTX_R8_SNORM: return ImageFormat_R8_SNORM;
	case TKTX_R8_UINT: return ImageFormat_R8_UINT;
	case TKTX_R8_SINT: return ImageFormat_R8_SINT;
	case TKTX_R8_SRGB: return ImageFormat_R8_SRGB;
	case TKTX_R8G8_UNORM: return ImageFormat_R8G8_UNORM;
	case TKTX_R8G8_SNORM: return ImageFormat_R8G8_SNORM;
	case TKTX_R8G8_UINT: return ImageFormat_R8G8_UINT;
	case TKTX_R8G8_SINT: return ImageFormat_R8G8_SINT;
	case TKTX_R8G8_SRGB: return ImageFormat_R8G8_SRGB;
	case TKTX_R8G8B8_UNORM: return ImageFormat_R8G8B8_UNORM;
	case TKTX_R8G8B8_SNORM: return ImageFormat_R8G8B8_SNORM;
	case TKTX_R8G8B8_UINT: return ImageFormat_R8G8B8_UINT;
	case TKTX_R8G8B8_SINT: return ImageFormat_R8G8B8_SINT;
	case TKTX_R8G8B8_SRGB: return ImageFormat_R8G8B8_SRGB;
	case TKTX_B8G8R8_UNORM: return ImageFormat_B8G8R8_UNORM;
	case TKTX_B8G8R8_SNORM: return ImageFormat_B8G8R8_SNORM;
	case TKTX_B8G8R8_UINT: return ImageFormat_B8G8R8_UINT;
	case TKTX_B8G8R8_SINT: return ImageFormat_B8G8R8_SINT;
	case TKTX_B8G8R8_SRGB: return ImageFormat_B8G8R8_SRGB;
	case TKTX_R8G8B8A8_UNORM: return ImageFormat_R8G8B8A8_UNORM;
	case TKTX_R8G8B8A8_SNORM: return ImageFormat_R8G8B8A8_SNORM;
	case TKTX_R8G8B8A8_UINT: return ImageFormat_R8G8B8A8_UINT;
	case TKTX_R8G8B8A8_SINT: return ImageFormat_R8G8B8A8_SINT;
	case TKTX_R8G8B8A8_SRGB: return ImageFormat_R8G8B8A8_SRGB;
	case TKTX_B8G8R8A8_UNORM: return ImageFormat_B8G8R8A8_UNORM;
	case TKTX_B8G8R8A8_SNORM: return ImageFormat_B8G8R8A8_SNORM;
	case TKTX_B8G8R8A8_UINT: return ImageFormat_B8G8R8A8_UINT;
	case TKTX_B8G8R8A8_SINT: return ImageFormat_B8G8R8A8_SINT;
	case TKTX_B8G8R8A8_SRGB: return ImageFormat_B8G8R8A8_SRGB;
	case TKTX_A8B8G8R8_UNORM_PACK32: return ImageFormat_A8B8G8R8_UNORM_PACK32;
	case TKTX_A8B8G8R8_SNORM_PACK32: return ImageFormat_A8B8G8R8_SNORM_PACK32;
	case TKTX_A8B8G8R8_UINT_PACK32: return ImageFormat_A8B8G8R8_UINT_PACK32;
	case TKTX_A8B8G8R8_SINT_PACK32: return ImageFormat_A8B8G8R8_SINT_PACK32;
	case TKTX_A8B8G8R8_SRGB_PACK32: return ImageFormat_A8B8G8R8_SRGB_PACK32;
	case TKTX_E5B9G9R9_UFLOAT_PACK32: return ImageFormat_E5B9G9R9_UFLOAT_PACK32;
	case TKTX_A2R10G10B10_UNORM_PACK32: return ImageFormat_A2R10G10B10_UNORM_PACK32;
	case TKTX_A2R10G10B10_UINT_PACK32: return ImageFormat_A2R10G10B10_UINT_PACK32;
	case TKTX_A2B10G10R10_UNORM_PACK32: return ImageFormat_A2B10G10R10_UNORM_PACK32;
	case TKTX_A2B10G10R10_UINT_PACK32: return ImageFormat_A2B10G10R10_UINT_PACK32;
	case TKTX_B10G11R11_UFLOAT_PACK32: return ImageFormat_B10G11R11_UFLOAT_PACK32;
	case TKTX_R16_UNORM: return ImageFormat_R16_UNORM;
	case TKTX_R16_SNORM: return ImageFormat_R16_SNORM;
	case TKTX_R16_UINT: return ImageFormat_R16_UINT;
	case TKTX_R16_SINT: return ImageFormat_R16_SINT;
	case TKTX_R16_SFLOAT: return ImageFormat_R16_SFLOAT;
	case TKTX_R16G16_UNORM: return ImageFormat_R16G16_UNORM;
	case TKTX_R16G16_SNORM: return ImageFormat_R16G16_SNORM;
	case TKTX_R16G16_UINT: return ImageFormat_R16G16_UINT;
	case TKTX_R16G16_SINT: return ImageFormat_R16G16_SINT;
	case TKTX_R16G16_SFLOAT: return ImageFormat_R16G16_SFLOAT;
	case TKTX_R16G16B16_UNORM: return ImageFormat_R16G16B16_UNORM;
	case TKTX_R16G16B16_SNORM: return ImageFormat_R16G16B16_SNORM;
	case TKTX_R16G16B16_UINT: return ImageFormat_R16G16B16_UINT;
	case TKTX_R16G16B16_SINT: return ImageFormat_R16G16B16_SINT;
	case TKTX_R16G16B16_SFLOAT: return ImageFormat_R16G16B16_SFLOAT;
	case TKTX_R16G16B16A16_UNORM: return ImageFormat_R16G16B16A16_UNORM;
	case TKTX_R16G16B16A16_SNORM: return ImageFormat_R16G16B16A16_SNORM;
	case TKTX_R16G16B16A16_UINT: return ImageFormat_R16G16B16A16_UINT;
	case TKTX_R16G16B16A16_SINT: return ImageFormat_R16G16B16A16_SINT;
	case TKTX_R16G16B16A16_SFLOAT: return ImageFormat_R16G16B16A16_SFLOAT;
	case TKTX_R32_UINT: return ImageFormat_R32_UINT;
	case TKTX_R32_SINT: return ImageFormat_R32_SINT;
	case TKTX_R32_SFLOAT: return ImageFormat_R32_SFLOAT;
	case TKTX_R32G32_UINT: return ImageFormat_R32G32_UINT;
	case TKTX_R32G32_SINT: return ImageFormat_R32G32_SINT;
	case TKTX_R32G32_SFLOAT: return ImageFormat_R32G32_SFLOAT;
	case TKTX_R32G32B32_UINT: return ImageFormat_R32G32B32_UINT;
	case TKTX_R32G32B32_SINT: return ImageFormat_R32G32B32_SINT;
	case TKTX_R32G32B32_SFLOAT: return ImageFormat_R32G32B32_SFLOAT;
	case TKTX_R32G32B32A32_UINT: return ImageFormat_R32G32B32A32_UINT;
	case TKTX_R32G32B32A32_SINT: return ImageFormat_R32G32B32A32_SINT;
	case TKTX_R32G32B32A32_SFLOAT: return ImageFormat_R32G32B32A32_SFLOAT;
	case TKTX_BC1_RGB_UNORM_BLOCK: return ImageFormat_BC1_RGB_UNORM_BLOCK;
	case TKTX_BC1_RGB_SRGB_BLOCK: return ImageFormat_BC1_RGB_SRGB_BLOCK;
	case TKTX_BC1_RGBA_UNORM_BLOCK: return ImageFormat_BC1_RGBA_UNORM_BLOCK;
	case TKTX_BC1_RGBA_SRGB_BLOCK: return ImageFormat_BC1_RGBA_SRGB_BLOCK;
	case TKTX_BC2_UNORM_BLOCK: return ImageFormat_BC2_UNORM_BLOCK;
	case TKTX_BC2_SRGB_BLOCK: return ImageFormat_BC2_SRGB_BLOCK;
	case TKTX_BC3_UNORM_BLOCK: return ImageFormat_BC3_UNORM_BLOCK;
	case TKTX_BC3_SRGB_BLOCK: return ImageFormat_BC3_SRGB_BLOCK;
	case TKTX_BC4_UNORM_BLOCK: return ImageFormat_BC4_UNORM_BLOCK;
	case TKTX_BC4_SNORM_BLOCK: return ImageFormat_BC4_SNORM_BLOCK;
	case TKTX_BC5_UNORM_BLOCK: return ImageFormat_BC5_UNORM_BLOCK;
	case TKTX_BC5_SNORM_BLOCK: return ImageFormat_BC5_SNORM_BLOCK;
	case TKTX_BC6H_UFLOAT_BLOCK: return ImageFormat_BC6H_UFLOAT_BLOCK;
	case TKTX_BC6H_SFLOAT_BLOCK: return ImageFormat_BC6H_SFLOAT_BLOCK;
	case TKTX_BC7_UNORM_BLOCK: return ImageFormat_BC7_UNORM_BLOCK;
	case TKTX_BC7_SRGB_BLOCK: return ImageFormat_BC7_SRGB_BLOCK;
	case TKTX_PVR_2BPP_BLOCK: return ImageFormat_PVR_2BPP_UNORM_BLOCK;
	case TKTX_PVR_2BPPA_BLOCK: return ImageFormat_PVR_2BPPA_UNORM_BLOCK;
	case TKTX_PVR_4BPP_BLOCK: return ImageFormat_PVR_4BPP_UNORM_BLOCK;
	case TKTX_PVR_4BPPA_BLOCK: return ImageFormat_PVR_4BPPA_UNORM_BLOCK;
	case TKTX_PVR_2BPP_SRGB_BLOCK: return ImageFormat_PVR_2BPP_SRGB_BLOCK;
	case TKTX_PVR_2BPPA_SRGB_BLOCK: return ImageFormat_PVR_2BPPA_SRGB_BLOCK;
	case TKTX_PVR_4BPP_SRGB_BLOCK: return ImageFormat_PVR_4BPP_SRGB_BLOCK;
	case TKTX_PVR_4BPPA_SRGB_BLOCK: return ImageFormat_PVR_4BPPA_SRGB_BLOCK;

	case TKTX_ETC2_R8G8B8_UNORM_BLOCK: return ImageFormat_ETC2_R8G8B8_UNORM_BLOCK;
	case TKTX_ETC2_R8G8B8A1_UNORM_BLOCK: return ImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK;
	case TKTX_ETC2_R8G8B8A8_UNORM_BLOCK: return ImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK;
	case TKTX_ETC2_R8G8B8_SRGB_BLOCK: return ImageFormat_ETC2_R8G8B8_SRGB_BLOCK;
	case TKTX_ETC2_R8G8B8A1_SRGB_BLOCK: return ImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK;
	case TKTX_ETC2_R8G8B8A8_SRGB_BLOCK: return ImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK;
	case TKTX_EAC_R11_UNORM_BLOCK: return ImageFormat_EAC_R11_UNORM_BLOCK;
	case TKTX_EAC_R11G11_UNORM_BLOCK: return ImageFormat_EAC_R11G11_UNORM_BLOCK;
	case TKTX_EAC_R11_SNORM_BLOCK: return ImageFormat_EAC_R11_SNORM_BLOCK;
	case TKTX_EAC_R11G11_SNORM_BLOCK: return ImageFormat_EAC_R11G11_SNORM_BLOCK;
	case TKTX_ASTC_4x4_UNORM_BLOCK: return ImageFormat_ASTC_4x4_UNORM_BLOCK;
	case TKTX_ASTC_4x4_SRGB_BLOCK: return ImageFormat_ASTC_4x4_SRGB_BLOCK;
	case TKTX_ASTC_5x4_UNORM_BLOCK: return ImageFormat_ASTC_5x4_UNORM_BLOCK;
	case TKTX_ASTC_5x4_SRGB_BLOCK: return ImageFormat_ASTC_5x4_SRGB_BLOCK;
	case TKTX_ASTC_5x5_UNORM_BLOCK: return ImageFormat_ASTC_5x5_UNORM_BLOCK;
	case TKTX_ASTC_5x5_SRGB_BLOCK: return ImageFormat_ASTC_5x5_SRGB_BLOCK;
	case TKTX_ASTC_6x5_UNORM_BLOCK: return ImageFormat_ASTC_6x5_UNORM_BLOCK;
	case TKTX_ASTC_6x5_SRGB_BLOCK: return ImageFormat_ASTC_6x5_SRGB_BLOCK;
	case TKTX_ASTC_6x6_UNORM_BLOCK: return ImageFormat_ASTC_6x6_UNORM_BLOCK;
	case TKTX_ASTC_6x6_SRGB_BLOCK: return ImageFormat_ASTC_6x6_SRGB_BLOCK;
	case TKTX_ASTC_8x5_UNORM_BLOCK: return ImageFormat_ASTC_8x5_UNORM_BLOCK;
	case TKTX_ASTC_8x5_SRGB_BLOCK: return ImageFormat_ASTC_8x5_SRGB_BLOCK;
	case TKTX_ASTC_8x6_UNORM_BLOCK: return ImageFormat_ASTC_8x6_UNORM_BLOCK;
	case TKTX_ASTC_8x6_SRGB_BLOCK: return ImageFormat_ASTC_8x6_SRGB_BLOCK;
	case TKTX_ASTC_8x8_UNORM_BLOCK: return ImageFormat_ASTC_8x8_UNORM_BLOCK;
	case TKTX_ASTC_8x8_SRGB_BLOCK: return ImageFormat_ASTC_8x8_SRGB_BLOCK;
	case TKTX_ASTC_10x5_UNORM_BLOCK: return ImageFormat_ASTC_10x5_UNORM_BLOCK;
	case TKTX_ASTC_10x5_SRGB_BLOCK: return ImageFormat_ASTC_10x5_SRGB_BLOCK;
	case TKTX_ASTC_10x6_UNORM_BLOCK: return ImageFormat_ASTC_10x6_UNORM_BLOCK;
	case TKTX_ASTC_10x6_SRGB_BLOCK: return ImageFormat_ASTC_10x6_SRGB_BLOCK;
	case TKTX_ASTC_10x8_UNORM_BLOCK: return ImageFormat_ASTC_10x8_UNORM_BLOCK;
	case TKTX_ASTC_10x8_SRGB_BLOCK: return ImageFormat_ASTC_10x8_SRGB_BLOCK;
	case TKTX_ASTC_10x10_UNORM_BLOCK: return ImageFormat_ASTC_10x10_UNORM_BLOCK;
	case TKTX_ASTC_10x10_SRGB_BLOCK: return ImageFormat_ASTC_10x10_SRGB_BLOCK;
	case TKTX_ASTC_12x10_UNORM_BLOCK: return ImageFormat_ASTC_12x10_UNORM_BLOCK;
	case TKTX_ASTC_12x10_SRGB_BLOCK: return ImageFormat_ASTC_12x10_SRGB_BLOCK;
	case TKTX_ASTC_12x12_UNORM_BLOCK: return ImageFormat_ASTC_12x12_UNORM_BLOCK;
	case TKTX_ASTC_12x12_SRGB_BLOCK: return ImageFormat_ASTC_12x12_SRGB_BLOCK;

	default: return ImageFormat_UNDEFINED;
	}
}

#ifdef IMAGE_IMAGEFORMAT_IMPLEMENTATION
#ifndef TINYKTX_HAVE_STRICMP
#include "string.h" // for stricmp
#endif

static uint8_t s_ImageFormat_Swizzle_RGBA[4] = {0, 1, 2, 3};
static uint8_t s_ImageFormat_Swizzle_ARGB[4] = {3, 0, 1, 2};
static uint8_t s_ImageFormat_Swizzle_BGRA[4] = {2, 1, 0, 3};
static uint8_t s_ImageFormat_Swizzle_ABGR[4] = {3, 2, 1, 0};
AL2O3_EXTERN_C Image_Swizzle ImageFormat_Swizzle_RGBA = s_ImageFormat_Swizzle_RGBA;
AL2O3_EXTERN_C Image_Swizzle ImageFormat_Swizzle_ARGB = s_ImageFormat_Swizzle_ARGB;
AL2O3_EXTERN_C Image_Swizzle ImageFormat_Swizzle_BGRA = s_ImageFormat_Swizzle_BGRA;
AL2O3_EXTERN_C Image_Swizzle ImageFormat_Swizzle_ABGR = s_ImageFormat_Swizzle_ABGR;

AL2O3_EXTERN_C char const *ImageFormat_Name(enum ImageFormat const fmt) {
#define IF_START_MACRO switch(fmt) {
#define IF_MOD_MACRO(x) case ImageFormat_##x: return #x;
#define IF_END_MACRO };

#include "tiny_imageformat/format.h"

  return "Unknown Format";
}

AL2O3_EXTERN_C ImageFormat ImageFormat_FromName(char const * name) {
  for (size_t i = 0u; i < ImageFormat_Count(); ++i) {
    if (stricmp(name, ImageFormat_Name(i)) == 0) {
      return (ImageFormat)i;
    }
  }
  return ImageFormat_UNDEFINED;
}

#ifndef __cplusplus
AL2O3_EXTERN_C size_t ImageFormat_Count() {
  static size_t s_count = 0;
  if (s_count == 0) {
#define IF_START_MACRO
#define IF_MOD_MACRO(x) s_count++;
#define IF_END_MACRO
#include "tiny_imageformat/format.h"
  }
  return s_count;
}
#endif

#endif

#endif //TINYIMAGEFORMAT_IMAGEFORMAT_H
