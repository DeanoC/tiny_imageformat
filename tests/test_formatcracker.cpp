#include "al2o3_platform/platform.h"
#include "al2o3_catch2/catch2.hpp"

#include "gfx_imageformat/format.h"
#include "gfx_imageformat/formatcracker.h"

TEST_CASE("Format Cracker IsDepth (C)", "[Image]") {

#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "gfx_imageformat/format.h"

  for (int i = 0; i < formatCount; ++i) {
    enum ImageFormat fmt = (ImageFormat) i;
    switch (fmt) {
      case ImageFormat_D16_UNORM:
      case ImageFormat_X8_D24_UNORM_PACK32:
      case ImageFormat_D32_SFLOAT:
      case ImageFormat_D16_UNORM_S8_UINT:
      case ImageFormat_D24_UNORM_S8_UINT:
      case ImageFormat_D32_SFLOAT_S8_UINT: {
        REQUIRE(ImageFormat_IsDepth(fmt));
        break;
      };
      default:REQUIRE(ImageFormat_IsDepth(fmt) == false);
        break;
    }
  }
}

TEST_CASE("Format Cracker IsStencil (C)", "[Image]") {

#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "gfx_imageformat/format.h"

  for (int i = 0; i < formatCount; ++i) {
    enum ImageFormat fmt = (ImageFormat) i;
    switch (fmt) {
      case ImageFormat_S8_UINT:
      case ImageFormat_D16_UNORM_S8_UINT:
      case ImageFormat_D24_UNORM_S8_UINT:
      case ImageFormat_D32_SFLOAT_S8_UINT: {
        REQUIRE(ImageFormat_IsStencil(fmt));
        break;
      };

      default:REQUIRE(ImageFormat_IsStencil(fmt) == false);
        break;
    }
  }
}

TEST_CASE("Format Cracker IsDepthStencil (C)", "[Image]") {

#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "gfx_imageformat/format.h"

  for (int i = 0; i < formatCount; ++i) {
    enum ImageFormat fmt = (ImageFormat) i;
    switch (fmt) {
      case ImageFormat_D16_UNORM_S8_UINT:
      case ImageFormat_D24_UNORM_S8_UINT:
      case ImageFormat_D32_SFLOAT_S8_UINT: {
        REQUIRE(ImageFormat_IsDepthStencil(fmt));
        break;
      };

      default:REQUIRE(ImageFormat_IsDepthStencil(fmt) == false);
        break;
    }
  }
}

TEST_CASE("Format Cracker IsFloat (C)", "[Image]") {

#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "gfx_imageformat/format.h"

  for (int i = 0; i < formatCount; ++i) {
    enum ImageFormat fmt = (ImageFormat) i;
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
      case ImageFormat_BC6H_SFLOAT_BLOCK: {
        REQUIRE(ImageFormat_IsFloat(fmt));
        break;
      };

      default:REQUIRE(ImageFormat_IsFloat(fmt) == false);
        break;
    }
  }
}

TEST_CASE("Format Cracker IsNormalised (C)", "[Image]") {

#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "gfx_imageformat/format.h"

  for (int i = 0; i < formatCount; ++i) {
    enum ImageFormat fmt = (ImageFormat) i;
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
      case ImageFormat_PVR_4BPPA_BLOCK: {
        REQUIRE(ImageFormat_IsNormalised(fmt));
        break;
      };

      default:REQUIRE(ImageFormat_IsNormalised(fmt) == false);
        break;
    }
  }
}

TEST_CASE("Format Cracker IsSigned (C)", "[Image]") {

#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "gfx_imageformat/format.h"

  for (int i = 0; i < formatCount; ++i) {
    enum ImageFormat fmt = (ImageFormat) i;
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
      case ImageFormat_BC6H_SFLOAT_BLOCK: {
        REQUIRE(ImageFormat_IsSigned(fmt));
        break;
      };

      default:REQUIRE(ImageFormat_IsSigned(fmt) == false);
        break;
    }
  }
}

TEST_CASE("Format Cracker IsSRGB (C)", "[Image]") {

#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "gfx_imageformat/format.h"

  for (int i = 0; i < formatCount; ++i) {
    enum ImageFormat fmt = (ImageFormat) i;
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
      case ImageFormat_PVR_4BPPA_SRGB_BLOCK: {
        REQUIRE(ImageFormat_IsSRGB(fmt));
        break;
      };

      default:REQUIRE(ImageFormat_IsSRGB(fmt) == false);
        break;
    }
  }
}

TEST_CASE("Format Cracker IsCompressed (C)", "[Image]") {

#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "gfx_imageformat/format.h"

  for (int i = 0; i < formatCount; ++i) {
    enum ImageFormat fmt = (ImageFormat) i;
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
      case ImageFormat_PVR_4BPPA_SRGB_BLOCK: {
        REQUIRE(ImageFormat_IsCompressed(fmt));
        break;
      };

      default:REQUIRE(ImageFormat_IsCompressed(fmt) == false);
        break;
    }
  }
}

TEST_CASE("Format Cracker Min (C)", "[Image]") {

  // random sample a few to check
  REQUIRE(ImageFormat_Min(ImageFormat_A8B8G8R8_UINT_PACK32, 0) == 0);
  REQUIRE(ImageFormat_Min(ImageFormat_A8B8G8R8_UINT_PACK32, 1) == 0);
  REQUIRE(ImageFormat_Min(ImageFormat_A8B8G8R8_UINT_PACK32, 2) == 0);
  REQUIRE(ImageFormat_Min(ImageFormat_A8B8G8R8_UINT_PACK32, 3) == 0);

  REQUIRE(ImageFormat_Min(ImageFormat_A8B8G8R8_SINT_PACK32, 0) == -128);
  REQUIRE(ImageFormat_Min(ImageFormat_A8B8G8R8_SINT_PACK32, 1) == -128);
  REQUIRE(ImageFormat_Min(ImageFormat_A8B8G8R8_SINT_PACK32, 2) == -128);
  REQUIRE(ImageFormat_Min(ImageFormat_A8B8G8R8_SINT_PACK32, 3) == -128);

  REQUIRE(ImageFormat_Min(ImageFormat_R32G32B32A32_SFLOAT, 0) == Approx(FLT_MIN));
  REQUIRE(ImageFormat_Min(ImageFormat_R32G32B32A32_SFLOAT, 1) == Approx(FLT_MIN));
  REQUIRE(ImageFormat_Min(ImageFormat_R32G32B32A32_SFLOAT, 2) == Approx(FLT_MIN));
  REQUIRE(ImageFormat_Min(ImageFormat_R32G32B32A32_SFLOAT, 3) == Approx(FLT_MIN));

}

TEST_CASE("Format Cracker Max (C)", "[Image]") {

  // random sample a few to check
  REQUIRE(ImageFormat_Max(ImageFormat_A8B8G8R8_UINT_PACK32, 0) == 255);
  REQUIRE(ImageFormat_Max(ImageFormat_A8B8G8R8_UINT_PACK32, 1) == 255);
  REQUIRE(ImageFormat_Max(ImageFormat_A8B8G8R8_UINT_PACK32, 2) == 255);
  REQUIRE(ImageFormat_Max(ImageFormat_A8B8G8R8_UINT_PACK32, 3) == 255);

  REQUIRE(ImageFormat_Max(ImageFormat_A8B8G8R8_SINT_PACK32, 0) == 127);
  REQUIRE(ImageFormat_Max(ImageFormat_A8B8G8R8_SINT_PACK32, 1) == 127);
  REQUIRE(ImageFormat_Max(ImageFormat_A8B8G8R8_SINT_PACK32, 2) == 127);
  REQUIRE(ImageFormat_Max(ImageFormat_A8B8G8R8_SINT_PACK32, 3) == 127);

  REQUIRE(ImageFormat_Max(ImageFormat_R32G32B32A32_SFLOAT, 0) == Approx(FLT_MAX));
  REQUIRE(ImageFormat_Max(ImageFormat_R32G32B32A32_SFLOAT, 1) == Approx(FLT_MAX));
  REQUIRE(ImageFormat_Max(ImageFormat_R32G32B32A32_SFLOAT, 2) == Approx(FLT_MAX));
  REQUIRE(ImageFormat_Max(ImageFormat_R32G32B32A32_SFLOAT, 3) == Approx(FLT_MAX));

  REQUIRE(ImageFormat_Max(ImageFormat_D32_SFLOAT_S8_UINT, 0) == Approx(FLT_MAX));
  REQUIRE(ImageFormat_Max(ImageFormat_D32_SFLOAT_S8_UINT, 1) == 255);

}

TEST_CASE("Format Cracker Swizzle (C)", "[Image]") {

  // random sample a few to check
  REQUIRE(ImageFormat_Swizzle(ImageFormat_R32G32B32A32_SFLOAT) == ImageFormat_Swizzle_RGBA);
  REQUIRE(ImageFormat_Swizzle(ImageFormat_R4G4_UNORM_PACK8) == ImageFormat_Swizzle_RGBA);
  REQUIRE(ImageFormat_Swizzle(ImageFormat_R5G5B5A1_UNORM_PACK16) == ImageFormat_Swizzle_RGBA);
  REQUIRE(ImageFormat_Swizzle(ImageFormat_A1R5G5B5_UNORM_PACK16) == ImageFormat_Swizzle_ARGB);
  REQUIRE(ImageFormat_Swizzle(ImageFormat_A2R10G10B10_USCALED_PACK32) == ImageFormat_Swizzle_ARGB);
  REQUIRE(ImageFormat_Swizzle(ImageFormat_B4G4R4A4_UNORM_PACK16) == ImageFormat_Swizzle_BGRA);
  REQUIRE(ImageFormat_Swizzle(ImageFormat_B8G8R8_SRGB) == ImageFormat_Swizzle_BGRA);
  REQUIRE(ImageFormat_Swizzle(ImageFormat_B8G8R8A8_USCALED) == ImageFormat_Swizzle_BGRA);
  REQUIRE(ImageFormat_Swizzle(ImageFormat_A8B8G8R8_SINT_PACK32) == ImageFormat_Swizzle_ABGR);
}