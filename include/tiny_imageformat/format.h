#if !defined( GFX_IMAGEFORMAT_FORMAT_H_ ) || defined( IF_START_MACRO )

#if !defined IF_START_MACRO

#define GFX_IMAGEFORMAT_FORMAT_H_ 1
#define IF_START_MACRO typedef enum TinyImageFormat {

#else

#if !defined( IF_MOD_MACRO )
#error IF_START_MACRO set but not IF_MOD_MACRO
#elif !defined( IF_END_MACRO )
#error IF_START_MACRO set but not IF_END_MACRO
#endif

#endif

#if !defined IF_MOD_MACRO
#define IF_MOD_MACRO(x) TinyImageFormat_##x,
#endif

#if !defined IF_END_MACRO
#define IF_END_MACRO } TinyImageFormat;
#endif

IF_START_MACRO
  IF_MOD_MACRO(UNDEFINED)
  IF_MOD_MACRO(R4G4_UNORM_PACK8)
	IF_MOD_MACRO(A8_UNORM)
	IF_MOD_MACRO(R8_UNORM)
  IF_MOD_MACRO(R8_SNORM)
  IF_MOD_MACRO(R8_USCALED)
  IF_MOD_MACRO(R8_SSCALED)
  IF_MOD_MACRO(R8_UINT)
  IF_MOD_MACRO(R8_SINT)
  IF_MOD_MACRO(R8_SRGB)

	IF_MOD_MACRO(R4G4B4A4_UNORM_PACK16)
	IF_MOD_MACRO(B4G4R4A4_UNORM_PACK16)
	IF_MOD_MACRO(A4R4G4B4_UNORM_PACK16)
	IF_MOD_MACRO(R5G6B5_UNORM_PACK16)
	IF_MOD_MACRO(B5G6R5_UNORM_PACK16)
	IF_MOD_MACRO(R5G5B5A1_UNORM_PACK16)
	IF_MOD_MACRO(B5G5R5A1_UNORM_PACK16)
	IF_MOD_MACRO(A1R5G5B5_UNORM_PACK16)
  IF_MOD_MACRO(R8G8_UNORM)
  IF_MOD_MACRO(R8G8_SNORM)
  IF_MOD_MACRO(R8G8_USCALED)
  IF_MOD_MACRO(R8G8_SSCALED)
  IF_MOD_MACRO(R8G8_UINT)
  IF_MOD_MACRO(R8G8_SINT)
  IF_MOD_MACRO(R8G8_SRGB)
	IF_MOD_MACRO(R16_UNORM)
	IF_MOD_MACRO(R16_SNORM)
	IF_MOD_MACRO(R16_USCALED)
	IF_MOD_MACRO(R16_SSCALED)
	IF_MOD_MACRO(R16_UINT)
	IF_MOD_MACRO(R16_SINT)
	IF_MOD_MACRO(R16_SFLOAT)

	IF_MOD_MACRO(R8G8B8_UNORM)
  IF_MOD_MACRO(R8G8B8_SNORM)
  IF_MOD_MACRO(R8G8B8_USCALED)
  IF_MOD_MACRO(R8G8B8_SSCALED)
  IF_MOD_MACRO(R8G8B8_UINT)
  IF_MOD_MACRO(R8G8B8_SINT)
  IF_MOD_MACRO(R8G8B8_SRGB)
  IF_MOD_MACRO(B8G8R8_UNORM)
  IF_MOD_MACRO(B8G8R8_SNORM)
  IF_MOD_MACRO(B8G8R8_USCALED)
  IF_MOD_MACRO(B8G8R8_SSCALED)
  IF_MOD_MACRO(B8G8R8_UINT)
  IF_MOD_MACRO(B8G8R8_SINT)
  IF_MOD_MACRO(B8G8R8_SRGB)

  IF_MOD_MACRO(R8G8B8A8_UNORM)
  IF_MOD_MACRO(R8G8B8A8_SNORM)
  IF_MOD_MACRO(R8G8B8A8_USCALED)
  IF_MOD_MACRO(R8G8B8A8_SSCALED)
  IF_MOD_MACRO(R8G8B8A8_UINT)
  IF_MOD_MACRO(R8G8B8A8_SINT)
  IF_MOD_MACRO(R8G8B8A8_SRGB)
  IF_MOD_MACRO(B8G8R8A8_UNORM)
  IF_MOD_MACRO(B8G8R8A8_SNORM)
  IF_MOD_MACRO(B8G8R8A8_USCALED)
  IF_MOD_MACRO(B8G8R8A8_SSCALED)
  IF_MOD_MACRO(B8G8R8A8_UINT)
  IF_MOD_MACRO(B8G8R8A8_SINT)
  IF_MOD_MACRO(B8G8R8A8_SRGB)
	IF_MOD_MACRO(R16G16_UNORM)
	IF_MOD_MACRO(R16G16_SNORM)
	IF_MOD_MACRO(R16G16_USCALED)
	IF_MOD_MACRO(R16G16_SSCALED)
	IF_MOD_MACRO(R16G16_UINT)
	IF_MOD_MACRO(R16G16_SINT)
	IF_MOD_MACRO(R16G16_SFLOAT)
	IF_MOD_MACRO(R32_UINT)
	IF_MOD_MACRO(R32_SINT)
	IF_MOD_MACRO(R32_SFLOAT)

	IF_MOD_MACRO(A8B8G8R8_UNORM_PACK32)
  IF_MOD_MACRO(A8B8G8R8_SNORM_PACK32)
  IF_MOD_MACRO(A8B8G8R8_USCALED_PACK32)
  IF_MOD_MACRO(A8B8G8R8_SSCALED_PACK32)
  IF_MOD_MACRO(A8B8G8R8_UINT_PACK32)
  IF_MOD_MACRO(A8B8G8R8_SINT_PACK32)
  IF_MOD_MACRO(A8B8G8R8_SRGB_PACK32)
	IF_MOD_MACRO(A8R8G8B8_UNORM_PACK32)
	IF_MOD_MACRO(A2R10G10B10_UNORM_PACK32)
  IF_MOD_MACRO(A2R10G10B10_USCALED_PACK32)
  IF_MOD_MACRO(A2R10G10B10_UINT_PACK32)
  IF_MOD_MACRO(A2B10G10R10_UNORM_PACK32)
  IF_MOD_MACRO(A2B10G10R10_USCALED_PACK32)
  IF_MOD_MACRO(A2B10G10R10_UINT_PACK32)
	IF_MOD_MACRO(B10G11R11_UFLOAT_PACK32)
	IF_MOD_MACRO(E5B9G9R9_UFLOAT_PACK32)


  IF_MOD_MACRO(R16G16B16_UNORM)
  IF_MOD_MACRO(R16G16B16_SNORM)
  IF_MOD_MACRO(R16G16B16_USCALED)
  IF_MOD_MACRO(R16G16B16_SSCALED)
  IF_MOD_MACRO(R16G16B16_UINT)
  IF_MOD_MACRO(R16G16B16_SINT)
  IF_MOD_MACRO(R16G16B16_SFLOAT)

  IF_MOD_MACRO(R16G16B16A16_UNORM)
  IF_MOD_MACRO(R16G16B16A16_SNORM)
  IF_MOD_MACRO(R16G16B16A16_USCALED)
  IF_MOD_MACRO(R16G16B16A16_SSCALED)
  IF_MOD_MACRO(R16G16B16A16_UINT)
  IF_MOD_MACRO(R16G16B16A16_SINT)
  IF_MOD_MACRO(R16G16B16A16_SFLOAT)
  IF_MOD_MACRO(R32G32_UINT)
  IF_MOD_MACRO(R32G32_SINT)
  IF_MOD_MACRO(R32G32_SFLOAT)

  IF_MOD_MACRO(R32G32B32_UINT)
  IF_MOD_MACRO(R32G32B32_SINT)
  IF_MOD_MACRO(R32G32B32_SFLOAT)

  IF_MOD_MACRO(R32G32B32A32_UINT)
  IF_MOD_MACRO(R32G32B32A32_SINT)
  IF_MOD_MACRO(R32G32B32A32_SFLOAT)
  IF_MOD_MACRO(R64_UINT)
  IF_MOD_MACRO(R64_SINT)
  IF_MOD_MACRO(R64_SFLOAT)

  IF_MOD_MACRO(R64G64_UINT)
  IF_MOD_MACRO(R64G64_SINT)
  IF_MOD_MACRO(R64G64_SFLOAT)

  IF_MOD_MACRO(R64G64B64_UINT)
  IF_MOD_MACRO(R64G64B64_SINT)
  IF_MOD_MACRO(R64G64B64_SFLOAT)

  IF_MOD_MACRO(R64G64B64A64_UINT)
  IF_MOD_MACRO(R64G64B64A64_SINT)
  IF_MOD_MACRO(R64G64B64A64_SFLOAT)

  IF_MOD_MACRO(D16_UNORM)
  IF_MOD_MACRO(X8_D24_UNORM_PACK32)
  IF_MOD_MACRO(D32_SFLOAT)
  IF_MOD_MACRO(S8_UINT)
  IF_MOD_MACRO(D16_UNORM_S8_UINT)
  IF_MOD_MACRO(D24_UNORM_S8_UINT)
  IF_MOD_MACRO(D32_SFLOAT_S8_UINT)

  IF_MOD_MACRO(BC1_RGB_UNORM_BLOCK)
  IF_MOD_MACRO(BC1_RGB_SRGB_BLOCK)
  IF_MOD_MACRO(BC1_RGBA_UNORM_BLOCK)
  IF_MOD_MACRO(BC1_RGBA_SRGB_BLOCK)
  IF_MOD_MACRO(BC2_UNORM_BLOCK)
  IF_MOD_MACRO(BC2_SRGB_BLOCK)
  IF_MOD_MACRO(BC3_UNORM_BLOCK)
  IF_MOD_MACRO(BC3_SRGB_BLOCK)
  IF_MOD_MACRO(BC4_UNORM_BLOCK)
  IF_MOD_MACRO(BC4_SNORM_BLOCK)
  IF_MOD_MACRO(BC5_UNORM_BLOCK)
  IF_MOD_MACRO(BC5_SNORM_BLOCK)
  IF_MOD_MACRO(BC6H_UFLOAT_BLOCK)
  IF_MOD_MACRO(BC6H_SFLOAT_BLOCK)
  IF_MOD_MACRO(BC7_UNORM_BLOCK)
  IF_MOD_MACRO(BC7_SRGB_BLOCK)
  IF_MOD_MACRO(PVR_2BPP_UNORM_BLOCK)
  IF_MOD_MACRO(PVR_2BPPA_UNORM_BLOCK)
  IF_MOD_MACRO(PVR_4BPP_UNORM_BLOCK)
  IF_MOD_MACRO(PVR_4BPPA_UNORM_BLOCK)
  IF_MOD_MACRO(PVR_2BPP_SRGB_BLOCK)
  IF_MOD_MACRO(PVR_2BPPA_SRGB_BLOCK)
  IF_MOD_MACRO(PVR_4BPP_SRGB_BLOCK)
  IF_MOD_MACRO(PVR_4BPPA_SRGB_BLOCK)
	IF_MOD_MACRO(ETC2_R8G8B8_UNORM_BLOCK)
	IF_MOD_MACRO(ETC2_R8G8B8A1_UNORM_BLOCK)
	IF_MOD_MACRO(ETC2_R8G8B8A8_UNORM_BLOCK)
	IF_MOD_MACRO(ETC2_R8G8B8_SRGB_BLOCK)
	IF_MOD_MACRO(ETC2_R8G8B8A1_SRGB_BLOCK)
	IF_MOD_MACRO(ETC2_R8G8B8A8_SRGB_BLOCK)
	IF_MOD_MACRO(EAC_R11_UNORM_BLOCK)
	IF_MOD_MACRO(EAC_R11G11_UNORM_BLOCK)
	IF_MOD_MACRO(EAC_R11_SNORM_BLOCK)
	IF_MOD_MACRO(EAC_R11G11_SNORM_BLOCK)
	IF_MOD_MACRO(ASTC_4x4_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_4x4_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_5x4_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_5x4_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_5x5_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_5x5_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_6x5_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_6x5_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_6x6_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_6x6_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_8x5_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_8x5_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_8x6_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_8x6_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_8x8_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_8x8_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_10x5_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_10x5_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_10x6_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_10x6_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_10x8_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_10x8_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_10x10_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_10x10_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_12x10_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_12x10_SRGB_BLOCK)
	IF_MOD_MACRO(ASTC_12x12_UNORM_BLOCK)
	IF_MOD_MACRO(ASTC_12x12_SRGB_BLOCK)


	IF_END_MACRO
#undef IF_START_MACRO
#undef IF_MOD_MACRO
#undef IF_END_MACRO

#endif //GFX_IMAGEFORMAT_FORMAT_H_
