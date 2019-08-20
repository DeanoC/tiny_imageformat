#include "al2o3_platform/platform.h"
#include "al2o3_catch2/catch2.hpp"

#include "tiny_imageformat/tinyimageformat_base.h"
#include "tiny_imageformat/tinyimageformat_query.h"
#include <float.h>

TEST_CASE("Format Cracker IsDepthOnly (C)", "[Image]") {

	for (uint32_t i = 0; i < TinyImageFormat_Count; ++i) {
		TinyImageFormat fmt = (TinyImageFormat) i;
		char const *name = TinyImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "D16") != nullptr;
		shouldBe |= strstr(name, "D24") != nullptr;
		shouldBe |= strstr(name, "D32") != nullptr;

		if (TinyImageFormat_IsDepthOnly(fmt) != shouldBe) {
			LOGINFOF("TinyImageFormat_IsDepth failed %s", name);
		}
		CHECK(TinyImageFormat_IsDepthOnly(fmt) == shouldBe);
	}
}

TEST_CASE("Format Cracker IsStencilOnly (C)", "[Image]") {

	for (uint32_t i = 0; i < TinyImageFormat_Count; ++i) {
		TinyImageFormat fmt = (TinyImageFormat) i;
		char const *name = TinyImageFormat_Name(fmt);
		bool shouldBe = (strstr(name, "S8") != nullptr) &&
										(strstr(name, "D") == nullptr);

		if (TinyImageFormat_IsStencilOnly(fmt) != shouldBe) {
			LOGINFOF("TinyImageFormat_IsStencilOnly failed %s", name);
		}
		CHECK(TinyImageFormat_IsStencilOnly(fmt) == shouldBe);
	}
}

TEST_CASE("Format Cracker IsDepthAndStencil (C)", "[Image]") {

  for (uint32_t i = 0; i < TinyImageFormat_Count; ++i) {
		TinyImageFormat fmt = (TinyImageFormat) i;
		char const *name = TinyImageFormat_Name(fmt);
		bool shouldBe = strstr(name, "D16") != nullptr;
		shouldBe |= strstr(name, "D24") != nullptr;
		shouldBe |= strstr(name, "D32") != nullptr;
		shouldBe &= strstr(name, "S8") != nullptr;

		if (TinyImageFormat_IsDepthAndStencil(fmt) != shouldBe) {
			LOGINFOF("TinyImageFormat_IsDepthAndStencil failed %s", name);
		}
		CHECK(TinyImageFormat_IsDepthAndStencil(fmt) == shouldBe);
  }
}

TEST_CASE("Format Cracker IsFloat (C)", "[Image]") {

  for (uint32_t i = 0; i < TinyImageFormat_Count; ++i) {
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

  for (uint32_t i = 0; i < TinyImageFormat_Count; ++i) {
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
  for (uint32_t i = 0; i < TinyImageFormat_Count; ++i) {
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

  for (uint32_t i = 0; i < TinyImageFormat_Count; ++i) {
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

	for (uint32_t i = 0; i < TinyImageFormat_Count; ++i) {
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
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8A8_UINT, TinyImageFormat_LC_Red) == Approx(0));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8A8_UINT, TinyImageFormat_LC_Green) == Approx(0));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8A8_UINT, TinyImageFormat_LC_Blue) == Approx(0));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8A8_UINT, TinyImageFormat_LC_Alpha) == Approx(0));

  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8A8_SINT, TinyImageFormat_LC_Red) == Approx(-128));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8A8_SINT, TinyImageFormat_LC_Green) == Approx(-128));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8A8_SINT, TinyImageFormat_LC_Blue) == Approx(-128));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8A8_SINT, TinyImageFormat_LC_Alpha) == Approx(-128));

  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R32G32B32A32_SFLOAT, TinyImageFormat_LC_Red) == Approx(-FLT_MAX));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R32G32B32A32_SFLOAT, TinyImageFormat_LC_Green) == Approx(-FLT_MAX));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R32G32B32A32_SFLOAT, TinyImageFormat_LC_Blue) == Approx(-FLT_MAX));
  REQUIRE(TinyImageFormat_Min(TinyImageFormat_R32G32B32A32_SFLOAT, TinyImageFormat_LC_Alpha) == Approx(-FLT_MAX));

	REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8X8_UNORM, TinyImageFormat_LC_Red) == Approx(0.0));
	REQUIRE(TinyImageFormat_Min(TinyImageFormat_R8G8B8A8_SNORM, TinyImageFormat_LC_Red) == Approx(-1.0));


}

TEST_CASE("Format Cracker Max (C)", "[Image]") {

  // random sample a few to check
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R8G8B8A8_UINT, TinyImageFormat_LC_Red) == Approx(255));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R8G8B8A8_UINT, TinyImageFormat_LC_Green) == Approx(255));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R8G8B8A8_UINT, TinyImageFormat_LC_Blue) == Approx(255));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R8G8B8A8_UINT, TinyImageFormat_LC_Alpha) == Approx(255));

  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R8G8B8A8_SINT, TinyImageFormat_LC_Red) == Approx(127));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R8G8B8A8_SINT, TinyImageFormat_LC_Green) == Approx(127));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R8G8B8A8_SINT, TinyImageFormat_LC_Blue) == Approx(127));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R8G8B8A8_SINT, TinyImageFormat_LC_Alpha) == Approx(127));

  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R32G32B32A32_SFLOAT, TinyImageFormat_LC_Red) == Approx(FLT_MAX));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R32G32B32A32_SFLOAT, TinyImageFormat_LC_Green) == Approx(FLT_MAX));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R32G32B32A32_SFLOAT, TinyImageFormat_LC_Blue) == Approx(FLT_MAX));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_R32G32B32A32_SFLOAT, TinyImageFormat_LC_Alpha) == Approx(FLT_MAX));

  REQUIRE(TinyImageFormat_Max(TinyImageFormat_D32_SFLOAT_S8_UINT, TinyImageFormat_LC_Depth) == Approx(FLT_MAX));
  REQUIRE(TinyImageFormat_Max(TinyImageFormat_D32_SFLOAT_S8_UINT, TinyImageFormat_LC_Stencil) == Approx(255));

	REQUIRE(TinyImageFormat_Max(TinyImageFormat_D32_SFLOAT, TinyImageFormat_LC_Depth) == Approx(FLT_MAX));
	REQUIRE(TinyImageFormat_Max(TinyImageFormat_S8_UINT, TinyImageFormat_LC_Stencil) == Approx(255));

	REQUIRE(TinyImageFormat_Max(TinyImageFormat_B8G8R8X8_UNORM, TinyImageFormat_LC_Red) == Approx(1.0));
	REQUIRE(TinyImageFormat_Max(TinyImageFormat_B8G8R8A8_SNORM, TinyImageFormat_LC_Red) == Approx(1.0));

}