#include "al2o3_platform/platform.h"
#include "al2o3_catch2/catch2.hpp"

#include "tiny_imageformat/format.h"
#include "tiny_imageformat/formatcracker.h"

TEST_CASE("Format Count (C)", "[Image]") {
#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "tiny_imageformat/format.h"

	REQUIRE(ImageFormat_Count() == formatCount);
}


TEST_CASE("Format Cracker IsDepth (C)", "[Image]") {

  for (int i = 0; i < ImageFormat_Count(); ++i) {
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
#include "tiny_imageformat/format.h"

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

  for (int i = 0; i < ImageFormat_Count(); ++i) {
		ImageFormat fmt = (ImageFormat) i;
		char const *name = ImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "D16") != nullptr;
		shouldBe |= strstr(name, "D24") != nullptr;
		shouldBe |= strstr(name, "D32") != nullptr;
		shouldBe &= strstr(name, "S8") != nullptr;

		if (ImageFormat_IsDepthStencil(fmt) != shouldBe) {
			LOGINFOF("ImageFormat_IsDepthStencil failed %s", name);
		}
		CHECK(ImageFormat_IsDepthStencil(fmt) == shouldBe);
  }
}

TEST_CASE("Format Cracker IsFloat (C)", "[Image]") {

  for (int i = 0; i < ImageFormat_Count(); ++i) {
		ImageFormat fmt = (ImageFormat) i;
		char const *name = ImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "SFLOAT") != nullptr;
		shouldBe |= strstr(name, "UFLOAT") != nullptr;

		if (ImageFormat_IsFloat(fmt) != shouldBe) {
			LOGINFOF("ImageFormat_IsFloat failed %s", name);
		}
		CHECK(ImageFormat_IsFloat(fmt) == shouldBe);
  }
}

TEST_CASE("Format Cracker IsNormalised (C)", "[Image]") {

  for (int i = 0; i < ImageFormat_Count(); ++i) {
		ImageFormat fmt = (ImageFormat) i;
		char const *name = ImageFormat_Name(fmt);
		bool shouldBeNormalised = strstr(name, "UNORM") != nullptr;
		shouldBeNormalised |= strstr(name, "SNORM") != nullptr;
		if (ImageFormat_IsNormalised(fmt) != shouldBeNormalised) {
			LOGINFOF("ImageFormat_IsNormalised failed %s", name);
		}
		CHECK(ImageFormat_IsNormalised(fmt) == shouldBeNormalised);
	}
}

TEST_CASE("Format Cracker IsSigned (C)", "[Image]") {
  for (int i = 0; i < ImageFormat_Count(); ++i) {
		ImageFormat fmt = (ImageFormat) i;
		char const *name = ImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "SNORM") != nullptr;
		shouldBe |= strstr(name, "SSCALED") != nullptr;
		shouldBe |= strstr(name, "SINT") != nullptr;
		shouldBe |= strstr(name, "SFLOAT") != nullptr;

		if (ImageFormat_IsSigned(fmt) != shouldBe) {
			LOGINFOF("ImageFormat_IsSigned failed %s", name);
		}
		CHECK(ImageFormat_IsSigned(fmt) == shouldBe);
  }
}

TEST_CASE("Format Cracker IsSRGB (C)", "[Image]") {

  for (int i = 0; i < ImageFormat_Count(); ++i) {
		ImageFormat fmt = (ImageFormat) i;
		char const *name = ImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "SRGB") != nullptr;

		if (ImageFormat_IsSRGB(fmt) != shouldBe) {
			LOGINFOF("ImageFormat_IsSRGB failed %s", name);
		}
		CHECK(ImageFormat_IsSRGB(fmt) == shouldBe);
  }
}

TEST_CASE("Format Cracker IsCompressed (C)", "[Image]") {

	for (int i = 0; i < ImageFormat_Count(); ++i) {
		ImageFormat fmt = (ImageFormat) i;
		char const *name = ImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "BLOCK") != nullptr;

		if (ImageFormat_IsCompressed(fmt) != shouldBe) {
			LOGINFOF("ImageFormat_IsCompressed failed %s", name);
		}
		CHECK(ImageFormat_IsCompressed(fmt) == shouldBe);
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