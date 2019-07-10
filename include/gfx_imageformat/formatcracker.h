#pragma once
#ifndef AL2O3_IMAGEFORMAT_FORMATCRACKER_H
#define AL2O3_IMAGEFORMAT_FORMATCRACKER_H

#include "al2o3_platform/platform.h"
#include "gfx_imageformat/format.h"
#include <limits.h> // for max/min types
#include <float.h> // for max/min float types

AL2O3_EXTERN_C char const *ImageFormat_Name(ImageFormat const fmt);
AL2O3_EXTERN_C ImageFormat ImageFormat_FromName(char const *name);

AL2O3_EXTERN_C size_t ImageFormat_Count();

AL2O3_EXTERN_C inline bool ImageFormat_IsDepth(enum ImageFormat const fmt) {
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

AL2O3_EXTERN_C inline bool ImageFormat_IsStencil(enum ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_S8_UINT:
	case ImageFormat_D16_UNORM_S8_UINT:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_D32_SFLOAT_S8_UINT:return true;
	default:return false;
	}
}

//! is this texture format a depth stencil format?
AL2O3_EXTERN_C inline bool ImageFormat_IsDepthStencil(enum ImageFormat const fmt) {
	switch (fmt) {
	case ImageFormat_D16_UNORM_S8_UINT:
	case ImageFormat_D24_UNORM_S8_UINT:
	case ImageFormat_D32_SFLOAT_S8_UINT:return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool ImageFormat_IsFloat(enum ImageFormat const fmt) {
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
	case ImageFormat_BC6H_SFLOAT_BLOCK:return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool ImageFormat_IsNormalised(enum ImageFormat const fmt) {
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

	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:

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

		return true;
	default:return false;
	}
}

AL2O3_EXTERN_C inline bool ImageFormat_IsSigned(enum ImageFormat const fmt) {
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
AL2O3_EXTERN_C inline bool ImageFormat_IsSRGB(enum ImageFormat const fmt) {
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

AL2O3_EXTERN_C inline bool ImageFormat_IsCompressed(enum ImageFormat const fmt) {
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

	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
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
	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
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

	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
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
	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
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
	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
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
	case ImageFormat_PVR_2BPPA_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
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
	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_4BPP_BLOCK:
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

//! Returns the number of channel bits for compression it gives 'apparent' which is pretty whooly..
AL2O3_EXTERN_C inline uint32_t ImageFormat_ChannelBitWidth(enum ImageFormat const fmt, int const channel_) {
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
		//			case GenericTextureFormat::B10G11R11_UFLOAT_PACK32:
		//				if(channel_ == 0) return 10;
		//				else return 11;
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
		//			case GenericTextureFormat::E5B9G9R9_UFLOAT_PACK32:
		//				if(channel_ == 0) return 5;
		//				else return 9;
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
	case ImageFormat_S8_UINT:return 8;
		// BC7 is variable between 4-7 bits for colour and 0-8 bits alpha
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:return 6;
	case ImageFormat_R5G5B5A1_UNORM_PACK16:
	case ImageFormat_B5G5R5A1_UNORM_PACK16:
		if (channel_ == 4) {
			return 1;
		} else {
			return 5;
		}
	case ImageFormat_A1R5G5B5_UNORM_PACK16:
		if (channel_ == 0) {
			return 1;
		} else {
			return 5;
		}
	case ImageFormat_B5G6R5_UNORM_PACK16:
	case ImageFormat_R5G6B5_UNORM_PACK16:
	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:return 5;
	case ImageFormat_R4G4_UNORM_PACK8:
	case ImageFormat_R4G4B4A4_UNORM_PACK16:
	case ImageFormat_B4G4R4A4_UNORM_PACK16:return 4;

	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:return 4;

	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:return 2;

	case ImageFormat_ETC2_R8G8B8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8_SRGB_BLOCK:
		return 5;
	case ImageFormat_ETC2_R8G8B8A1_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A1_SRGB_BLOCK:
		if (channel_ == 0) {
			return 1;
		} else {
			return 5;
		}
	case ImageFormat_ETC2_R8G8B8A8_UNORM_BLOCK:
	case ImageFormat_ETC2_R8G8B8A8_SRGB_BLOCK:
		return 4;

	case ImageFormat_EAC_R11_UNORM_BLOCK:
	case ImageFormat_EAC_R11G11_UNORM_BLOCK:
	case ImageFormat_EAC_R11_SNORM_BLOCK:
	case ImageFormat_EAC_R11G11_SNORM_BLOCK:
		return 8;
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
		return 8; // completely wrong

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
		//			case GenericTextureFormat::B10G11R11_UFLOAT_PACK32:
		//			case GenericTextureFormat::E5B9G9R9_UFLOAT_PACK32:
	case ImageFormat_X8_D24_UNORM_PACK32:
	case ImageFormat_D32_SFLOAT:
	case ImageFormat_D24_UNORM_S8_UINT:return 32;
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
	case ImageFormat_R8_SRGB:return UINT8_MAX;

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
	case ImageFormat_R4G4_UNORM_PACK8:return 15.0;
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
		//			case GenericTextureFormat::B10G11R11_UFLOAT_PACK32:
		//				return 65000.0;
		//			case GenericTextureFormat::E5B9G9R9_UFLOAT_PACK32:
		//				return 65472.0;

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
	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
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
	case ImageFormat_R64_UINT:return 0.0;

	case ImageFormat_R64G64B64A64_SINT:
	case ImageFormat_R64G64B64_SINT:
	case ImageFormat_R64G64_SINT:
	case ImageFormat_R64_SINT:return INT64_MIN;

	case ImageFormat_R64G64B64_SFLOAT:
	case ImageFormat_R64G64B64A64_SFLOAT:
	case ImageFormat_R64G64_SFLOAT:
	case ImageFormat_R64_SFLOAT:return FLT_MIN;

	case ImageFormat_R32G32B32A32_UINT:
	case ImageFormat_R32G32B32_UINT:
	case ImageFormat_R32G32_UINT:
	case ImageFormat_R32_UINT:return 0.0;

	case ImageFormat_R32G32B32A32_SINT:
	case ImageFormat_R32G32B32_SINT:
	case ImageFormat_R32G32_SINT:
	case ImageFormat_R32_SINT:return INT32_MIN;

	case ImageFormat_R32G32B32A32_SFLOAT:
	case ImageFormat_R32G32B32_SFLOAT:
	case ImageFormat_R32G32_SFLOAT:
	case ImageFormat_R32_SFLOAT:
	case ImageFormat_D32_SFLOAT:return FLT_MIN;

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
	case ImageFormat_R16_UINT:return 0.0;

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
	case ImageFormat_R8_SRGB:return 0;

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

	case ImageFormat_A2R10G10B10_UNORM_PACK32:
	case ImageFormat_A2R10G10B10_USCALED_PACK32:
	case ImageFormat_A2R10G10B10_UINT_PACK32:
	case ImageFormat_A2B10G10R10_UNORM_PACK32:
	case ImageFormat_A2B10G10R10_USCALED_PACK32:
	case ImageFormat_A2B10G10R10_UINT_PACK32:
		if (channel == 0) {
			return 0.0;
		} else {
			return 0.0;
		}

	case ImageFormat_X8_D24_UNORM_PACK32:
		if (channel == 0) {
			return 0.0;
		} else {
			return 0.0;
		};
	case ImageFormat_D24_UNORM_S8_UINT:
		if (channel == 1) {
			return 0.0;
		} else {
			return 0.0;
		}
	case ImageFormat_D16_UNORM_S8_UINT:
		if (channel == 1) {
			return 0.0;
		} else {
			return 0.0;
		}
	case ImageFormat_R4G4B4A4_UNORM_PACK16:
	case ImageFormat_B4G4R4A4_UNORM_PACK16:
	case ImageFormat_R4G4_UNORM_PACK8:return 0.0;

	case ImageFormat_BC1_RGB_UNORM_BLOCK:
	case ImageFormat_BC1_RGB_SRGB_BLOCK:
	case ImageFormat_R5G6B5_UNORM_PACK16:
	case ImageFormat_B5G6R5_UNORM_PACK16:
		if (channel == 1) {
			return 0.0;
		} else {
			return 0.0;
		}

	case ImageFormat_BC1_RGBA_UNORM_BLOCK:
	case ImageFormat_BC1_RGBA_SRGB_BLOCK:
	case ImageFormat_R5G5B5A1_UNORM_PACK16:
	case ImageFormat_B5G5R5A1_UNORM_PACK16:
		if (channel == 3) {
			return 0.0;
		} else {
			return 0.0;
		}
	case ImageFormat_A1R5G5B5_UNORM_PACK16:
		if (channel == 0) {
			return 0.0;
		} else {
			return 0.0;
		}

	case ImageFormat_BC2_UNORM_BLOCK:
	case ImageFormat_BC2_SRGB_BLOCK:
	case ImageFormat_BC3_UNORM_BLOCK:
	case ImageFormat_BC3_SRGB_BLOCK:
	case ImageFormat_BC4_UNORM_BLOCK:
	case ImageFormat_BC5_UNORM_BLOCK:
	case ImageFormat_BC7_UNORM_BLOCK:
	case ImageFormat_BC7_SRGB_BLOCK:
	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:return 0.0;

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
	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
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
	case ImageFormat_A1R5G5B5_UNORM_PACK16:return ImageFormat_Swizzle_ARGB;

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
	case ImageFormat_PVR_2BPP_BLOCK:
	case ImageFormat_PVR_2BPPA_BLOCK:
	case ImageFormat_PVR_4BPP_BLOCK:
	case ImageFormat_PVR_4BPPA_BLOCK:
	case ImageFormat_PVR_2BPP_SRGB_BLOCK:
	case ImageFormat_PVR_2BPPA_SRGB_BLOCK:
	case ImageFormat_PVR_4BPP_SRGB_BLOCK:
	case ImageFormat_PVR_4BPPA_SRGB_BLOCK:return ImageFormat_Swizzle_RGBA;

	default:LOGERRORF("swizzleFormat %s not handled", ImageFormat_Name(fmt_));
		return ImageFormat_Swizzle_RGBA;
	}
}

#endif //WYRD_ImageFormat_CRACKER_H
