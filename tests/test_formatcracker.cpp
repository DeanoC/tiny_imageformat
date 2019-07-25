#include "al2o3_platform/platform.h"
#include "al2o3_catch2/catch2.hpp"

#include "tiny_imageformat/format.h"
#include "tiny_imageformat/formatcracker.h"

TEST_CASE("Format Count (C)", "[Image]") {
#define IF_START_MACRO int formatCount = 0;
#define IF_MOD_MACRO(x) formatCount++;
#define IF_END_MACRO
#include "tiny_imageformat/format.h"

	REQUIRE(TinyImageFormat_Count() == formatCount);
}


TEST_CASE("Format Cracker IsDepth (C)", "[Image]") {

  for (int i = 0; i < TinyImageFormat_Count(); ++i) {
    enum TinyImageFormat fmt = (TinyImageFormat) i;
    switch (fmt) {
      case TinyImageFormat_D16_UNORM:
      case TinyImageFormat_X8_D24_UNORM_PACK32:
      case TinyImageFormat_D32_SFLOAT:
      case TinyImageFormat_D16_UNORM_S8_UINT:
      case TinyImageFormat_D24_UNORM_S8_UINT:
      case TinyImageFormat_D32_SFLOAT_S8_UINT: {
        REQUIRE(TinyImageFormat_IsDepth(fmt));
        break;
      };
      default:REQUIRE(TinyImageFormat_IsDepth(fmt) == false);
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
    enum TinyImageFormat fmt = (TinyImageFormat) i;
    switch (fmt) {
      case TinyImageFormat_S8_UINT:
      case TinyImageFormat_D16_UNORM_S8_UINT:
      case TinyImageFormat_D24_UNORM_S8_UINT:
      case TinyImageFormat_D32_SFLOAT_S8_UINT: {
        REQUIRE(TinyImageFormat_IsStencil(fmt));
        break;
      };

      default:REQUIRE(TinyImageFormat_IsStencil(fmt) == false);
        break;
    }
  }
}

TEST_CASE("Format Cracker IsDepthStencil (C)", "[Image]") {

  for (int i = 0; i < TinyImageFormat_Count(); ++i) {
		TinyImageFormat fmt = (TinyImageFormat) i;
		char const *name = TinyImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "D16") != nullptr;
		shouldBe |= strstr(name, "D24") != nullptr;
		shouldBe |= strstr(name, "D32") != nullptr;
		shouldBe &= strstr(name, "S8") != nullptr;

		if (TinyImageFormat_IsDepthStencil(fmt) != shouldBe) {
			LOGINFOF("TinyImageFormat_IsDepthStencil failed %s", name);
		}
		CHECK(TinyImageFormat_IsDepthStencil(fmt) == shouldBe);
  }
}

TEST_CASE("Format Cracker IsFloat (C)", "[Image]") {

  for (int i = 0; i < TinyImageFormat_Count(); ++i) {
		TinyImageFormat fmt = (TinyImageFormat) i;
		char const *name = TinyImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "SFLOAT") != nullptr;
		shouldBe |= strstr(name, "UFLOAT") != nullptr;

		if (TinyImageFormat_IsFloat(fmt) != shouldBe) {
			LOGINFOF("TinyImageFormat_IsFloat failed %s", name);
		}
		CHECK(TinyImageFormat_IsFloat(fmt) == shouldBe);
  }
}

TEST_CASE("Format Cracker IsNormalised (C)", "[Image]") {

  for (int i = 0; i < TinyImageFormat_Count(); ++i) {
		TinyImageFormat fmt = (TinyImageFormat) i;
		char const *name = TinyImageFormat_Name(fmt);
		bool shouldBeNormalised = strstr(name, "UNORM") != nullptr;
		shouldBeNormalised |= strstr(name, "SNORM") != nullptr;
		if (TinyImageFormat_IsNormalised(fmt) != shouldBeNormalised) {
			LOGINFOF("TinyImageFormat_IsNormalised failed %s", name);
		}
		CHECK(TinyImageFormat_IsNormalised(fmt) == shouldBeNormalised);
	}
}

TEST_CASE("Format Cracker IsSigned (C)", "[Image]") {
  for (int i = 0; i < TinyImageFormat_Count(); ++i) {
		TinyImageFormat fmt = (TinyImageFormat) i;
		char const *name = TinyImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "SNORM") != nullptr;
		shouldBe |= strstr(name, "SSCALED") != nullptr;
		shouldBe |= strstr(name, "SINT") != nullptr;
		shouldBe |= strstr(name, "SFLOAT") != nullptr;

		if (TinyImageFormat_IsSigned(fmt) != shouldBe) {
			LOGINFOF("TinyImageFormat_IsSigned failed %s", name);
		}
		CHECK(TinyImageFormat_IsSigned(fmt) == shouldBe);
  }
}

TEST_CASE("Format Cracker IsSRGB (C)", "[Image]") {

  for (int i = 0; i < TinyImageFormat_Count(); ++i) {
		TinyImageFormat fmt = (TinyImageFormat) i;
		char const *name = TinyImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "SRGB") != nullptr;

		if (TinyImageFormat_IsSRGB(fmt) != shouldBe) {
			LOGINFOF("TinyImageFormat_IsSRGB failed %s", name);
		}
		CHECK(TinyImageFormat_IsSRGB(fmt) == shouldBe);
  }
}

TEST_CASE("Format Cracker IsCompressed (C)", "[Image]") {

	for (int i = 0; i < TinyImageFormat_Count(); ++i) {
		TinyImageFormat fmt = (TinyImageFormat) i;
		char const *name = TinyImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "BLOCK") != nullptr;

		if (TinyImageFormat_IsCompressed(fmt) != shouldBe) {
			LOGINFOF("TinyImageFormat_IsCompressed failed %s", name);
		}
		CHECK(TinyImageFormat_IsCompressed(fmt) == shouldBe);
	}
}

TEST_CASE("Format Cracker Min (C)", "[Image]") {

  // random sample a few to check
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_A8B8G8R8_UINT_PACK32, 0) == 0);
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_A8B8G8R8_UINT_PACK32, 1) == 0);
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_A8B8G8R8_UINT_PACK32, 2) == 0);
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_A8B8G8R8_UINT_PACK32, 3) == 0);

  REQUIRE(TinyImageFormat_Min(TinyImageFormat_A8B8G8R8_SINT_PACK32, 0) == -128);
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_A8B8G8R8_SINT_PACK32, 1) == -128);
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_A8B8G8R8_SINT_PACK32, 2) == -128);
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_A8B8G8R8_SINT_PACK32, 3) == -128);

  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R32G32B32A32_SFLOAT, 0) == Approx(FLT_MIN));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R32G32B32A32_SFLOAT, 1) == Approx(FLT_MIN));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R32G32B32A32_SFLOAT, 2) == Approx(FLT_MIN));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R32G32B32A32_SFLOAT, 3) == Approx(FLT_MIN));

}

TEST_CASE("Format Cracker Max (C)", "[Image]") {

  // random sample a few to check
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_A8B8G8R8_UINT_PACK32, 0) == 255);
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_A8B8G8R8_UINT_PACK32, 1) == 255);
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_A8B8G8R8_UINT_PACK32, 2) == 255);
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_A8B8G8R8_UINT_PACK32, 3) == 255);

  REQUIRE(TinyImageFormat_Max(TinyImageFormat_A8B8G8R8_SINT_PACK32, 0) == 127);
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_A8B8G8R8_SINT_PACK32, 1) == 127);
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_A8B8G8R8_SINT_PACK32, 2) == 127);
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_A8B8G8R8_SINT_PACK32, 3) == 127);

  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R32G32B32A32_SFLOAT, 0) == Approx(FLT_MAX));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R32G32B32A32_SFLOAT, 1) == Approx(FLT_MAX));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R32G32B32A32_SFLOAT, 2) == Approx(FLT_MAX));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R32G32B32A32_SFLOAT, 3) == Approx(FLT_MAX));

  REQUIRE(TinyImageFormat_Max(TinyImageFormat_D32_SFLOAT_S8_UINT, 0) == Approx(FLT_MAX));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_D32_SFLOAT_S8_UINT, 1) == 255);

}

TEST_CASE("Format Cracker Swizzle (C)", "[Image]") {

  // random sample a few to check
  REQUIRE(TinyImageFormat_Swizzle(TinyImageFormat_R32G32B32A32_SFLOAT) == TinyImageFormat_Swizzle_RGBA);
  REQUIRE(TinyImageFormat_Swizzle(TinyImageFormat_R4G4_UNORM_PACK8) == TinyImageFormat_Swizzle_RGBA);
  REQUIRE(TinyImageFormat_Swizzle(TinyImageFormat_R5G5B5A1_UNORM_PACK16) == TinyImageFormat_Swizzle_RGBA);
  REQUIRE(TinyImageFormat_Swizzle(TinyImageFormat_A1R5G5B5_UNORM_PACK16) == TinyImageFormat_Swizzle_ARGB);
  REQUIRE(TinyImageFormat_Swizzle(TinyImageFormat_A2R10G10B10_USCALED_PACK32) == TinyImageFormat_Swizzle_ARGB);
  REQUIRE(TinyImageFormat_Swizzle(TinyImageFormat_B4G4R4A4_UNORM_PACK16) == TinyImageFormat_Swizzle_BGRA);
  REQUIRE(TinyImageFormat_Swizzle(TinyImageFormat_B8G8R8_SRGB) == TinyImageFormat_Swizzle_BGRA);
  REQUIRE(TinyImageFormat_Swizzle(TinyImageFormat_B8G8R8A8_USCALED) == TinyImageFormat_Swizzle_BGRA);
  REQUIRE(TinyImageFormat_Swizzle(TinyImageFormat_A8B8G8R8_SINT_PACK32) == TinyImageFormat_Swizzle_ABGR);
}