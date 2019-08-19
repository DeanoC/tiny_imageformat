#if !defined( GFX_IMAGEFORMAT_FORMAT_H_ ) || defined(  TinyImageFormat_START_MACRO )

#if !defined  TinyImageFormat_START_MACRO

#define GFX_IMAGEFORMAT_FORMAT_H_ 1
#define  TinyImageFormat_START_MACRO typedef enum TinyImageFormat {
#define  TinyImageFormat_ADD_FUNC

#else

#if !defined(  TinyImageFormat_MOD_MACRO )
#error  TinyImageFormat_START_MACRO set but not  TinyImageFormat_MOD_MACRO
#elif !defined(  TinyImageFormat_END_MACRO )
#error  TinyImageFormat_START_MACRO set but not  TinyImageFormat_END_MACRO
#endif

#endif

#if !defined  TinyImageFormat_MOD_MACRO
#define  TinyImageFormat_MOD_MACRO(x, y) TinyImageFormat_##x = (y),
#endif

#if !defined  TinyImageFormat_END_MACRO
#define  TinyImageFormat_END_MACRO } TinyImageFormat;
#endif


//---------
#include "formatgen_func.h"
#include "formatgen_macros.h"

 TinyImageFormat_START_MACRO
   TinyImageFormat_MOD_MACRO(UNDEFINED,0ULL)

	 TinyImageFormat_MOD_MACRO(R1_UNORM,   TinyImageFormat_PACK_1(R, 1, UNORM, MULTI8))
	 TinyImageFormat_MOD_MACRO(R2_UNORM,   TinyImageFormat_PACK_1(R, 2, UNORM, MULTI4))
	 TinyImageFormat_MOD_MACRO(R4_UNORM,   TinyImageFormat_PACK_1(R, 4, UNORM, MULTI2))

	 TinyImageFormat_MOD_MACRO(R4G4_UNORM,   TinyImageFormat_PACK_2_UNORM(R, 4, G, 4, PACK))
   TinyImageFormat_MOD_MACRO(G4R4_UNORM,   TinyImageFormat_PACK_2_UNORM(G, 4, R, 4, PACK))
	 TinyImageFormat_MOD_MACRO(A8_UNORM,  TinyImageFormat_PACK(A, 8, UNORM, _,_, _, _,_,_, _,_,_, NONE))
	 TinyImageFormat_MOD_MACRO(R8_UNORM,  TinyImageFormat_PACK_1(R, 8, UNORM, NONE))
	 TinyImageFormat_MOD_MACRO(R8_SNORM,  TinyImageFormat_PACK_1(R, 8, SNORM, NONE))
	 TinyImageFormat_MOD_MACRO(R8_UINT,  TinyImageFormat_PACK_1(R, 8, UINT, NONE))
	 TinyImageFormat_MOD_MACRO(R8_SINT,  TinyImageFormat_PACK_1(R, 8, SINT, NONE))
	 TinyImageFormat_MOD_MACRO(R8_SRGB,  TinyImageFormat_PACK_1(R, 8, SRGB, NONE))
	 TinyImageFormat_MOD_MACRO(B2G3R3_UNORM,   TinyImageFormat_PACK_3_UNORM(B, 2, G, 3, R, 3, PACK))

	 TinyImageFormat_MOD_MACRO(R4G4B4A4_UNORM,  TinyImageFormat_PACK_4_UNORM(R, 4, G, 4, B, 4, A, 4, PACK))
	 TinyImageFormat_MOD_MACRO(R4G4B4X4_UNORM,  TinyImageFormat_PACK_4_UNORM(R, 4, G, 4, B, 4, 1, 4, PACK))
	 TinyImageFormat_MOD_MACRO(B4G4R4A4_UNORM,  TinyImageFormat_PACK_4_UNORM(B, 4, G, 4, R, 4, A, 4, PACK))
	 TinyImageFormat_MOD_MACRO(B4G4R4X4_UNORM,  TinyImageFormat_PACK_4_UNORM(B, 4, G, 4, R, 4, 1, 4, PACK))
	 TinyImageFormat_MOD_MACRO(A4R4G4B4_UNORM,  TinyImageFormat_PACK_4_UNORM(A, 4, R, 4, G, 4, B, 4, PACK))
	 TinyImageFormat_MOD_MACRO(X4R4G4B4_UNORM,  TinyImageFormat_PACK(1,4, UINT, R, 4, UNORM, G, 4, UNORM, B, 4, UNORM, PACK))
	 TinyImageFormat_MOD_MACRO(A4B4G4R4_UNORM,  TinyImageFormat_PACK_4_UNORM(A, 4, B, 4, G, 4, R, 4, PACK))
	 TinyImageFormat_MOD_MACRO(X4B4G4R4_UNORM,  TinyImageFormat_PACK(1,4, UINT, B, 4, UNORM, G, 4, UNORM, R, 4, UNORM, PACK))

	 TinyImageFormat_MOD_MACRO(R5G6B5_UNORM,  TinyImageFormat_PACK_3(R,5, UNORM, G, 6, UNORM, B, 5, UNORM, PACK))
	 TinyImageFormat_MOD_MACRO(B5G6R5_UNORM,  TinyImageFormat_PACK_3(B,5, UNORM, G, 6, UNORM, R, 5, UNORM, PACK))
	 TinyImageFormat_MOD_MACRO(R5G5B5A1_UNORM,  TinyImageFormat_PACK_4_UNORM(R,5, G, 5, B, 5, A, 1, PACK))
	 TinyImageFormat_MOD_MACRO(B5G5R5A1_UNORM,  TinyImageFormat_PACK_4_UNORM(B,5, G, 5, R, 5, A, 1, PACK))
	 TinyImageFormat_MOD_MACRO(A1B5G5R5_UNORM,  TinyImageFormat_PACK_4_UNORM(A, 1, B, 5, G, 5, R, 5, PACK))
	 TinyImageFormat_MOD_MACRO(A1R5G5B5_UNORM,  TinyImageFormat_PACK_4_UNORM(A, 1, R, 5, G, 5, B, 5, PACK))
	 TinyImageFormat_MOD_MACRO(R5G5B5X1_UNORM,  TinyImageFormat_PACK(R,5, UNORM, G, 5, UNORM, B, 5, UNORM, 1, 1, UINT, PACK))
	 TinyImageFormat_MOD_MACRO(B5G5R5X1_UNORM,  TinyImageFormat_PACK(B,5, UNORM, G, 5, UNORM, R, 5, UNORM, 1, 1, UINT, PACK))
	 TinyImageFormat_MOD_MACRO(X1R5G5B5_UNORM,  TinyImageFormat_PACK(1, 1, UINT, R, 5, UNORM, G, 5, UNORM, B, 5, UNORM, PACK))
	 TinyImageFormat_MOD_MACRO(X1B5G5R5_UNORM,  TinyImageFormat_PACK(1, 1, UINT, B, 5, UNORM, G, 5, UNORM, R, 5, UNORM, PACK))

	 TinyImageFormat_MOD_MACRO(B2G3R3A8_UNORM,   TinyImageFormat_PACK_4_UNORM(B, 2, G, 3, R, 3, A, 8, PACK))

	 TinyImageFormat_MOD_MACRO(R8G8_UNORM,  TinyImageFormat_PACK_2_UNORM(R, 8, G, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8_SNORM,  TinyImageFormat_PACK_2_SNORM(R, 8, G, 8, NONE))
	 TinyImageFormat_MOD_MACRO(G8R8_UNORM,  TinyImageFormat_PACK_2_UNORM(G, 8, R, 8, NONE))
	 TinyImageFormat_MOD_MACRO(G8R8_SNORM,  TinyImageFormat_PACK_2_SNORM(G, 8, R, 8, NONE))

   TinyImageFormat_MOD_MACRO(R8G8_UINT,  TinyImageFormat_PACK_2_UINT(R, 8, G, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8_SINT,  TinyImageFormat_PACK_2_SINT(R, 8, G, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8_SRGB,  TinyImageFormat_PACK_2_SRGB(R, 8, G, 8, NONE))
	 TinyImageFormat_MOD_MACRO(R16_UNORM,  TinyImageFormat_PACK_1(R, 16, UNORM, NONE))
	 TinyImageFormat_MOD_MACRO(R16_SNORM,  TinyImageFormat_PACK_1(R, 16, SNORM, NONE))
	 TinyImageFormat_MOD_MACRO(R16_UINT,  TinyImageFormat_PACK_1(R, 16, UINT, NONE))
	 TinyImageFormat_MOD_MACRO(R16_SINT,  TinyImageFormat_PACK_1(R, 16, SINT, NONE))
	 TinyImageFormat_MOD_MACRO(R16_SFLOAT,  TinyImageFormat_PACK_1(R, 16, SFLOAT, NONE))
	 TinyImageFormat_MOD_MACRO(R16_SBFLOAT,  TinyImageFormat_PACK_1(R, 16, SBFLOAT, NONE))

	 TinyImageFormat_MOD_MACRO(R8G8B8_UNORM,  TinyImageFormat_PACK_3_UNORM(R, 8, G, 8, B, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8B8_SNORM,  TinyImageFormat_PACK_3_SNORM(R, 8, G, 8, B, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8B8_UINT,   TinyImageFormat_PACK_3_UINT(R, 8, G, 8, B, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8B8_SINT,   TinyImageFormat_PACK_3_SINT(R, 8, G, 8, B, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8B8_SRGB,   TinyImageFormat_PACK_3_SRGB(R, 8, G, 8, B, 8, NONE))
  
   TinyImageFormat_MOD_MACRO(B8G8R8_UNORM,  TinyImageFormat_PACK_3_UNORM(B, 8, G, 8, R, 8, NONE))
   TinyImageFormat_MOD_MACRO(B8G8R8_SNORM,  TinyImageFormat_PACK_3_SNORM(B, 8, G, 8, R, 8, NONE))
   TinyImageFormat_MOD_MACRO(B8G8R8_UINT,   TinyImageFormat_PACK_3_UINT(B, 8, G, 8, R, 8, NONE))
   TinyImageFormat_MOD_MACRO(B8G8R8_SINT,   TinyImageFormat_PACK_3_SINT(B, 8, G, 8, R, 8, NONE))
   TinyImageFormat_MOD_MACRO(B8G8R8_SRGB,   TinyImageFormat_PACK_3_SRGB(B, 8, G, 8, R, 8, NONE))

   TinyImageFormat_MOD_MACRO(R8G8B8A8_UNORM,  TinyImageFormat_PACK_4_UNORM(R, 8, G, 8, B, 8, A, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8B8A8_SNORM,  TinyImageFormat_PACK_4_SNORM(R, 8, G, 8, B, 8, A, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8B8A8_UINT,   TinyImageFormat_PACK_4_UINT(R, 8, G, 8, B, 8, A, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8B8A8_SINT,   TinyImageFormat_PACK_4_SINT(R, 8, G, 8, B, 8, A, 8, NONE))
   TinyImageFormat_MOD_MACRO(R8G8B8A8_SRGB,   TinyImageFormat_PACK_4_SRGB(R, 8, G, 8, B, 8, A, 8, NONE))

   TinyImageFormat_MOD_MACRO(B8G8R8A8_UNORM,  TinyImageFormat_PACK_4_UNORM(B, 8, G, 8, R, 8, A, 8, NONE))
   TinyImageFormat_MOD_MACRO(B8G8R8A8_SNORM,  TinyImageFormat_PACK_4_SNORM(B, 8, G, 8, R, 8, A, 8, NONE))
   TinyImageFormat_MOD_MACRO(B8G8R8A8_UINT,   TinyImageFormat_PACK_4_UINT(B, 8, G, 8, R, 8, A, 8, NONE))
   TinyImageFormat_MOD_MACRO(B8G8R8A8_SINT,   TinyImageFormat_PACK_4_SINT(B, 8, G, 8, R, 8, A, 8, NONE))
   TinyImageFormat_MOD_MACRO(B8G8R8A8_SRGB,   TinyImageFormat_PACK_4_SRGB(B, 8, G, 8, R, 8, A, 8, NONE))

	 TinyImageFormat_MOD_MACRO(R8G8B8X8_UNORM,  TinyImageFormat_PACK(R, 8, UNORM, G, 8, UNORM, B, 8, UNORM, 1, 8, UNORM, NONE))
	 TinyImageFormat_MOD_MACRO(B8G8R8X8_UNORM,  TinyImageFormat_PACK(B, 8, UNORM, G, 8, UNORM, R, 8, UNORM, 1, 8, UNORM, NONE))

	 TinyImageFormat_MOD_MACRO(R16G16_UNORM,  TinyImageFormat_PACK_2_UNORM(R, 16, G, 16, NONE))
	 TinyImageFormat_MOD_MACRO(G16R16_UNORM,  TinyImageFormat_PACK_2_UNORM(G, 16, R, 16, NONE))
	
	 TinyImageFormat_MOD_MACRO(R16G16_SNORM,  TinyImageFormat_PACK_2_SNORM(R, 16, G, 16, NONE))
	 TinyImageFormat_MOD_MACRO(G16R16_SNORM,  TinyImageFormat_PACK_2_SNORM(G, 16, R, 16, NONE))
	
	 TinyImageFormat_MOD_MACRO(R16G16_UINT,  TinyImageFormat_PACK_2_UINT(R, 16, G, 16, NONE))
	 TinyImageFormat_MOD_MACRO(R16G16_SINT,  TinyImageFormat_PACK_2_SINT(R, 16, G, 16, NONE))
	 TinyImageFormat_MOD_MACRO(R16G16_SFLOAT,  TinyImageFormat_PACK_2_SFLOAT(R, 16, G, 16, NONE))
	 TinyImageFormat_MOD_MACRO(R16G16_SBFLOAT,  TinyImageFormat_PACK_2(R, 16, SBFLOAT, G, 16, SBFLOAT, NONE))

	 TinyImageFormat_MOD_MACRO(R32_UINT,  TinyImageFormat_PACK_1(R, 32, UINT, NONE))
	 TinyImageFormat_MOD_MACRO(R32_SINT,  TinyImageFormat_PACK_1(R, 32, SINT, NONE))
	 TinyImageFormat_MOD_MACRO(R32_SFLOAT,  TinyImageFormat_PACK_1(R, 32, SFLOAT, NONE))

	 TinyImageFormat_MOD_MACRO(A2R10G10B10_UNORM,  TinyImageFormat_PACK_4_UNORM(A, 2, R, 10, G, 10, B, 10, PACK))
   TinyImageFormat_MOD_MACRO(A2R10G10B10_UINT,  TinyImageFormat_PACK_4_UINT(A, 2, R, 10, G, 10, B, 10, PACK))
   TinyImageFormat_MOD_MACRO(A2B10G10R10_UNORM,  TinyImageFormat_PACK_4_UNORM(A, 2, B, 10, G, 10, R, 10, PACK))
   TinyImageFormat_MOD_MACRO(A2B10G10R10_UINT,  TinyImageFormat_PACK_4_UINT(A, 2, B, 10, G, 10, R, 10, PACK))

	 TinyImageFormat_MOD_MACRO(R10G10B10A2_UNORM,  TinyImageFormat_PACK_4_UNORM(R, 10, G, 10, B, 10, A, 2, PACK))
	 TinyImageFormat_MOD_MACRO(B10G10R10A2_UNORM,  TinyImageFormat_PACK_4_UNORM(B, 10, G, 10, R, 10, A, 2, PACK))
	 TinyImageFormat_MOD_MACRO(B10G10R10A2_UINT,  TinyImageFormat_PACK_4_UINT(B, 10, G, 10, R, 10, A, 2, PACK))

	 TinyImageFormat_MOD_MACRO(B10G11R11_UFLOAT,  TinyImageFormat_PACK_3(B, 10, UFLOAT, G, 11, UFLOAT, R, 11, UFLOAT, PACK))
	 TinyImageFormat_MOD_MACRO(E5B9G9R9_UFLOAT,  TinyImageFormat_PACK(A, 5, UINT, B, 9, UFLOAT, G, 9, UFLOAT, R, 9, UFLOAT, PACK))

   TinyImageFormat_MOD_MACRO(R16G16B16_UNORM,  TinyImageFormat_PACK_3_UNORM(R, 16, G, 16, B, 16, NONE))
   TinyImageFormat_MOD_MACRO(R16G16B16_SNORM,  TinyImageFormat_PACK_3_SNORM(R, 16, G, 16, B, 16, NONE))
   TinyImageFormat_MOD_MACRO(R16G16B16_UINT,  TinyImageFormat_PACK_3_UINT(R, 16, G, 16, B, 16, NONE))
   TinyImageFormat_MOD_MACRO(R16G16B16_SINT,  TinyImageFormat_PACK_3_SINT(R, 16, G, 16, B, 16, NONE))
   TinyImageFormat_MOD_MACRO(R16G16B16_SFLOAT,  TinyImageFormat_PACK_3_SFLOAT(R, 16, G, 16, B, 16, NONE))
	 TinyImageFormat_MOD_MACRO(R16G16B16_SBFLOAT,  TinyImageFormat_PACK_3(R, 16, SBFLOAT, G, 16, SBFLOAT, B, 16, SBFLOAT, NONE))

   TinyImageFormat_MOD_MACRO(R16G16B16A16_UNORM,  TinyImageFormat_PACK_4_UNORM(R, 16, G, 16, B, 16, A, 16, NONE))
   TinyImageFormat_MOD_MACRO(R16G16B16A16_SNORM,  TinyImageFormat_PACK_4_SNORM(R, 16, G, 16, B, 16, A, 16, NONE))
   TinyImageFormat_MOD_MACRO(R16G16B16A16_UINT,  TinyImageFormat_PACK_4_UINT(R, 16, G, 16, B, 16, A, 16, NONE))
   TinyImageFormat_MOD_MACRO(R16G16B16A16_SINT,  TinyImageFormat_PACK_4_SINT(R, 16, G, 16, B, 16, A, 16, NONE))
   TinyImageFormat_MOD_MACRO(R16G16B16A16_SFLOAT,  TinyImageFormat_PACK_4_SFLOAT(R, 16, G, 16, B, 16, A, 16, NONE))
	 TinyImageFormat_MOD_MACRO(R16G16B16A16_SBFLOAT,  TinyImageFormat_PACK(R, 16, SBFLOAT, G, 16, SBFLOAT, B, 16, SBFLOAT, A, 16, SBFLOAT, NONE))

	 TinyImageFormat_MOD_MACRO(R32G32_UINT,    TinyImageFormat_PACK_2_UINT(R, 32, G, 32, NONE))
   TinyImageFormat_MOD_MACRO(R32G32_SINT,    TinyImageFormat_PACK_2_SINT(R, 32, G, 32, NONE))
   TinyImageFormat_MOD_MACRO(R32G32_SFLOAT,  TinyImageFormat_PACK_2_SFLOAT(R, 32, G, 32, NONE))


	 TinyImageFormat_MOD_MACRO(R32G32B32_UINT,    TinyImageFormat_PACK_3_UINT(R, 32, G, 32, B, 32, NONE))
   TinyImageFormat_MOD_MACRO(R32G32B32_SINT,    TinyImageFormat_PACK_3_SINT(R, 32, G, 32, B, 32, NONE))
   TinyImageFormat_MOD_MACRO(R32G32B32_SFLOAT,  TinyImageFormat_PACK_3_SFLOAT(R, 32, G, 32, B, 32, NONE))

   TinyImageFormat_MOD_MACRO(R32G32B32A32_UINT,    TinyImageFormat_PACK_4_UINT(R, 32, G, 32, B, 32, A, 32, NONE))
   TinyImageFormat_MOD_MACRO(R32G32B32A32_SINT,    TinyImageFormat_PACK_4_SINT(R, 32, G, 32, B, 32, A, 32, NONE))
   TinyImageFormat_MOD_MACRO(R32G32B32A32_SFLOAT,  TinyImageFormat_PACK_4_SFLOAT(R, 32, G, 32, B, 32, A, 32, NONE))

   TinyImageFormat_MOD_MACRO(R64_UINT,  TinyImageFormat_PACK_1(R, 64, UINT, NONE))
   TinyImageFormat_MOD_MACRO(R64_SINT,  TinyImageFormat_PACK_1(R, 64, SINT, NONE))
   TinyImageFormat_MOD_MACRO(R64_SFLOAT,  TinyImageFormat_PACK_1(R, 64, SFLOAT, NONE))

   TinyImageFormat_MOD_MACRO(R64G64_UINT,  TinyImageFormat_PACK_2_UINT(R, 64, G, 64, NONE))
   TinyImageFormat_MOD_MACRO(R64G64_SINT,  TinyImageFormat_PACK_2_SINT(R, 64, G, 64, NONE))
   TinyImageFormat_MOD_MACRO(R64G64_SFLOAT,  TinyImageFormat_PACK_2_SFLOAT(R, 64, G, 64, NONE))

   TinyImageFormat_MOD_MACRO(R64G64B64_UINT,  TinyImageFormat_PACK_3_UINT(R, 64, G, 64, B, 64, NONE))
   TinyImageFormat_MOD_MACRO(R64G64B64_SINT,  TinyImageFormat_PACK_3_SINT(R, 64, G, 64, B, 64, NONE))
   TinyImageFormat_MOD_MACRO(R64G64B64_SFLOAT,  TinyImageFormat_PACK_3_SFLOAT(R, 64, G, 64, B, 64, NONE))

   TinyImageFormat_MOD_MACRO(R64G64B64A64_UINT,  TinyImageFormat_PACK_4_UINT(R, 64, G, 64, B, 64, A, 64, NONE))
   TinyImageFormat_MOD_MACRO(R64G64B64A64_SINT,  TinyImageFormat_PACK_4_SINT(R, 64, G, 64, B, 64, A, 64, NONE))
   TinyImageFormat_MOD_MACRO(R64G64B64A64_SFLOAT,  TinyImageFormat_PACK_4_SFLOAT(R, 64, G, 64, B, 64, A, 64, NONE))

   TinyImageFormat_MOD_MACRO(D16_UNORM,  TinyImageFormat_DEPTH_STENCIL(D, 16, UNORM, _, _, _, 16))
   TinyImageFormat_MOD_MACRO(X8_D24_UNORM,  TinyImageFormat_DEPTH_STENCIL(0, 8, UINT, D, 24, UNORM, 32))
   TinyImageFormat_MOD_MACRO(D32_SFLOAT,  TinyImageFormat_DEPTH_STENCIL(D, 32, SFLOAT, _, _, _, 32))
   TinyImageFormat_MOD_MACRO(S8_UINT,  TinyImageFormat_DEPTH_STENCIL(S, 8, UINT,  _, _, _, 8))
   TinyImageFormat_MOD_MACRO(D16_UNORM_S8_UINT,  TinyImageFormat_DEPTH_STENCIL(D, 16, UNORM, S, 8, UINT, 32))
   TinyImageFormat_MOD_MACRO(D24_UNORM_S8_UINT,  TinyImageFormat_DEPTH_STENCIL(D, 24, UNORM, S, 8, UINT, 32))
   TinyImageFormat_MOD_MACRO(D32_SFLOAT_S8_UINT,  TinyImageFormat_DEPTH_STENCIL(D, 32, SFLOAT, S, 8, UINT, 64))

   TinyImageFormat_MOD_MACRO(DXBC1_RGB_UNORM,  TinyImageFormat_DXTC( NONE, UNORM, 8, 3, 1))
   TinyImageFormat_MOD_MACRO(DXBC1_RGB_SRGB,  TinyImageFormat_DXTC(NONE, SRGB, 8, 3, 1))
   TinyImageFormat_MOD_MACRO(DXBC1_RGBA_UNORM,  TinyImageFormat_DXTC(PUNCHTHROUGH, UNORM, 8, 4, 1))
   TinyImageFormat_MOD_MACRO(DXBC1_RGBA_SRGB,  TinyImageFormat_DXTC(PUNCHTHROUGH, SRGB, 8, 4, 1))
   TinyImageFormat_MOD_MACRO(DXBC2_UNORM,  TinyImageFormat_DXTC(FULL, UNORM, 16, 4, 1))
   TinyImageFormat_MOD_MACRO(DXBC2_SRGB,  TinyImageFormat_DXTC(FULL, SRGB, 16, 4, 1))
   TinyImageFormat_MOD_MACRO(DXBC3_UNORM,  TinyImageFormat_DXTC(BLOCK, UNORM, 16, 4, 1))
   TinyImageFormat_MOD_MACRO(DXBC3_SRGB,  TinyImageFormat_DXTC(BLOCK, SRGB, 16, 4, 1))
   TinyImageFormat_MOD_MACRO(DXBC4_UNORM,  TinyImageFormat_DXTC(NONE, UNORM, 8, 1, 1))
   TinyImageFormat_MOD_MACRO(DXBC4_SNORM,  TinyImageFormat_DXTC(NONE, SNORM, 8, 1, 1))
   TinyImageFormat_MOD_MACRO(DXBC5_UNORM,  TinyImageFormat_DXTC(NONE, UNORM, 16, 2, 1))
   TinyImageFormat_MOD_MACRO(DXBC5_SNORM,  TinyImageFormat_DXTC(NONE, SNORM, 16, 2, 1))
   TinyImageFormat_MOD_MACRO(DXBC6H_UFLOAT,  TinyImageFormat_DXTC(NONE, UFLOAT, 16, 3, 14))
   TinyImageFormat_MOD_MACRO(DXBC6H_SFLOAT,  TinyImageFormat_DXTC(NONE, SFLOAT, 16, 3, 14))
   TinyImageFormat_MOD_MACRO(DXBC7_UNORM,  TinyImageFormat_DXTC(FULL, UNORM, 16, 4, 8))
   TinyImageFormat_MOD_MACRO(DXBC7_SRGB,  TinyImageFormat_DXTC(FULL, SRGB, 16, 4, 8))

	 TinyImageFormat_MOD_MACRO(PVRTC1_2BPP_UNORM,  TinyImageFormat_PVRTC(V1, 2, UNORM))
	 TinyImageFormat_MOD_MACRO(PVRTC1_4BPP_UNORM,  TinyImageFormat_PVRTC(V1, 4, UNORM))
	 TinyImageFormat_MOD_MACRO(PVRTC2_2BPP_UNORM,  TinyImageFormat_PVRTC(V2, 2, UNORM))
	 TinyImageFormat_MOD_MACRO(PVRTC2_4BPP_UNORM,  TinyImageFormat_PVRTC(V2, 4, UNORM))
	 TinyImageFormat_MOD_MACRO(PVRTC1_2BPP_SRGB,  TinyImageFormat_PVRTC(V1, 2, SRGB))
	 TinyImageFormat_MOD_MACRO(PVRTC1_4BPP_SRGB,  TinyImageFormat_PVRTC(V1, 4, SRGB))
	 TinyImageFormat_MOD_MACRO(PVRTC2_2BPP_SRGB,  TinyImageFormat_PVRTC(V2, 2, SRGB))
	 TinyImageFormat_MOD_MACRO(PVRTC2_4BPP_SRGB,  TinyImageFormat_PVRTC(V2, 4, SRGB))

	 TinyImageFormat_MOD_MACRO(ETC2_R8G8B8_UNORM,  TinyImageFormat_ETC(8, NONE, UNORM, 3))
	 TinyImageFormat_MOD_MACRO(ETC2_R8G8B8_SRGB,  TinyImageFormat_ETC(8, NONE, SRGB, 3))
	 TinyImageFormat_MOD_MACRO(ETC2_R8G8B8A1_UNORM,  TinyImageFormat_ETC(8, PUNCHTHROUGH, UNORM, 4))
	 TinyImageFormat_MOD_MACRO(ETC2_R8G8B8A1_SRGB,  TinyImageFormat_ETC(8, PUNCHTHROUGH, SRGB, 4))
	 TinyImageFormat_MOD_MACRO(ETC2_R8G8B8A8_UNORM,  TinyImageFormat_ETC(8, BLOCK, UNORM, 4))
	 TinyImageFormat_MOD_MACRO(ETC2_R8G8B8A8_SRGB,  TinyImageFormat_ETC(8, BLOCK, SRGB, 4))
	 TinyImageFormat_MOD_MACRO(ETC2_EAC_R11_UNORM,  TinyImageFormat_ETC(11, NONE, UNORM, 1))
	 TinyImageFormat_MOD_MACRO(ETC2_EAC_R11_SNORM,  TinyImageFormat_ETC(11, NONE, SNORM, 1))
	 TinyImageFormat_MOD_MACRO(ETC2_EAC_R11G11_UNORM,  TinyImageFormat_ETC(11, NONE, UNORM, 2))
	 TinyImageFormat_MOD_MACRO(ETC2_EAC_R11G11_SNORM,  TinyImageFormat_ETC(11, NONE, SNORM, 2))

	 TinyImageFormat_MOD_MACRO(ASTC_4x4_UNORM,  TinyImageFormat_ASTC(4, 4, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_4x4_SRGB,   TinyImageFormat_ASTC(4, 4, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_5x4_UNORM,  TinyImageFormat_ASTC(5, 4, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_5x4_SRGB,   TinyImageFormat_ASTC(5, 4, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_5x5_UNORM,  TinyImageFormat_ASTC(5, 5, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_5x5_SRGB,   TinyImageFormat_ASTC(5, 5, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_6x5_UNORM,  TinyImageFormat_ASTC(6, 5, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_6x5_SRGB,   TinyImageFormat_ASTC(6, 5, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_6x6_UNORM,  TinyImageFormat_ASTC(6, 6, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_6x6_SRGB,   TinyImageFormat_ASTC(6, 6, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_8x5_UNORM,  TinyImageFormat_ASTC(8, 5, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_8x5_SRGB,   TinyImageFormat_ASTC(8, 5, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_8x6_UNORM,  TinyImageFormat_ASTC(8, 6, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_8x6_SRGB,   TinyImageFormat_ASTC(8, 6, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_8x8_UNORM,  TinyImageFormat_ASTC(8, 8, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_8x8_SRGB,   TinyImageFormat_ASTC(8, 8, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_10x5_UNORM,  TinyImageFormat_ASTC(10, 5, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_10x5_SRGB,   TinyImageFormat_ASTC(10, 5, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_10x6_UNORM,  TinyImageFormat_ASTC(10, 6, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_10x6_SRGB,   TinyImageFormat_ASTC(10, 6, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_10x8_UNORM,  TinyImageFormat_ASTC(10, 8, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_10x8_SRGB,   TinyImageFormat_ASTC(10, 8, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_10x10_UNORM,  TinyImageFormat_ASTC(10, 10, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_10x10_SRGB,   TinyImageFormat_ASTC(10, 10, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_12x10_UNORM,  TinyImageFormat_ASTC(12, 10, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_12x10_SRGB,   TinyImageFormat_ASTC(12, 10, 1, SRGB))
	 TinyImageFormat_MOD_MACRO(ASTC_12x12_UNORM,  TinyImageFormat_ASTC(12, 12, 1, UNORM))
	 TinyImageFormat_MOD_MACRO(ASTC_12x12_SRGB,   TinyImageFormat_ASTC(12, 12, 1, SRGB))

	 TinyImageFormat_MOD_MACRO(CLUT_P4, TinyImageFormat_CLUT(2, 4, RGB, _, _))
	 TinyImageFormat_MOD_MACRO(CLUT_P4A4, TinyImageFormat_CLUT(1, 4, RGB, 4, EXPLICIT_ALPHA))
	 TinyImageFormat_MOD_MACRO(CLUT_P8, TinyImageFormat_CLUT(1, 8, RGB, _, _))
	 TinyImageFormat_MOD_MACRO(CLUT_P8A8, TinyImageFormat_CLUT(1, 8, RGB, 8, EXPLICIT_ALPHA))

 TinyImageFormat_END_MACRO
#undef  TinyImageFormat_START_MACRO
#undef  TinyImageFormat_MOD_MACRO
#undef  TinyImageFormat_END_MACRO

#endif //GFX_IMAGEFORMAT_FORMAT_H_
