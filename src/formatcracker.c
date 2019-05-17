#include "al2o3_platform/platform.h"
#include "gfx_imageformat/format.h"
#include "gfx_imageformat/formatcracker.h"

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

#include "gfx_imageformat/format.h"

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

AL2O3_EXTERN_C size_t ImageFormat_Count() {
  static size_t s_count = 0;
  if (s_count == 0) {
#define IF_START_MACRO
#define IF_MOD_MACRO(x) s_count++;
#define IF_END_MACRO
#include "gfx_imageformat/format.h"
  }
  return s_count;
}
