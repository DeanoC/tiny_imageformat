#pragma once

#define  TinyImageFormat_PACK( rs, rb, rt, gs, gb, gt, bs, bb, bt, as, ab, at, special)   TinyImageFormat_CONSTEXPR_Pack( \
				 TinyImageFormat_PACK_SWIZZLE_##rs,  TinyImageFormat_PACK_BITS_##rb,  TinyImageFormat_PACK_TYPE_##rt, \
				 TinyImageFormat_PACK_SWIZZLE_##gs,  TinyImageFormat_PACK_BITS_##gb,  TinyImageFormat_PACK_TYPE_##gt, \
				 TinyImageFormat_PACK_SWIZZLE_##bs,  TinyImageFormat_PACK_BITS_##bb,  TinyImageFormat_PACK_TYPE_##bt, \
				 TinyImageFormat_PACK_SWIZZLE_##as,  TinyImageFormat_PACK_BITS_##ab,  TinyImageFormat_PACK_TYPE_##at, \
				 TinyImageFormat_PACK_SPECIAL_##special)

#define  TinyImageFormat_PACK_3(rs, rb, rt, gs, gb, gt, bs, bb, bt, special)\
			 TinyImageFormat_PACK(rs, rb, rt, gs, gb, gt, bs, bb, bt, 1, _, _, special)
#define  TinyImageFormat_PACK_2(rs, rb, rt, gs, gb, gt, special)  TinyImageFormat_PACK(rs, rb, rt, gs, gb, gt, 0, _, _, 1, _, _, special)
#define  TinyImageFormat_PACK_1(rs, rb, rt, special)    TinyImageFormat_PACK(rs, rb, rt, 0, _, _, 0, _, _, 1, _, _, special)

#define  TinyImageFormat_PACK_2_UNORM(rs, rb, gs, gb, special)    TinyImageFormat_PACK_2(rs, rb, UNORM, gs, gb, UNORM, special)
#define  TinyImageFormat_PACK_3_UNORM(rs, rb, gs, gb, bs, bb, special)   TinyImageFormat_PACK_3(rs, rb, UNORM, gs, gb, UNORM, bs, bb, UNORM, special)
#define  TinyImageFormat_PACK_4_UNORM(rs, rb, gs, gb, bs, bb, as, ab, special)   TinyImageFormat_PACK(rs, rb, UNORM, gs, gb, UNORM, bs, bb, UNORM, as, ab, UNORM, special)
#define  TinyImageFormat_PACK_2_SNORM(rs, rb, gs, gb, special)    TinyImageFormat_PACK_2(rs, rb, SNORM, gs, gb, SNORM, special)
#define  TinyImageFormat_PACK_3_SNORM(rs, rb, gs, gb, bs, bb, special)   TinyImageFormat_PACK_3(rs, rb, SNORM, gs, gb, SNORM, bs, bb, SNORM, special)
#define  TinyImageFormat_PACK_4_SNORM(rs, rb, gs, gb, bs, bb, as, ab, special)   TinyImageFormat_PACK(rs, rb, SNORM, gs, gb, SNORM, bs, bb, SNORM, as, ab, SNORM, special)
#define  TinyImageFormat_PACK_2_UINT(rs, rb, gs, gb, special)    TinyImageFormat_PACK_2(rs, rb, UINT, gs, gb, UINT, special)
#define  TinyImageFormat_PACK_3_UINT(rs, rb, gs, gb, bs, bb, special)   TinyImageFormat_PACK_3(rs, rb, UINT, gs, gb, UINT, bs, bb, UINT, special)
#define  TinyImageFormat_PACK_4_UINT(rs, rb, gs, gb, bs, bb, as, ab, special)   TinyImageFormat_PACK(rs, rb, UINT, gs, gb, UINT, bs, bb, UINT, as, ab, UINT, special)
#define  TinyImageFormat_PACK_2_SINT(rs, rb, gs, gb, special)    TinyImageFormat_PACK_2(rs, rb, SINT, gs, gb, SINT, special)
#define  TinyImageFormat_PACK_3_SINT(rs, rb, gs, gb, bs, bb, special)   TinyImageFormat_PACK_3(rs, rb, SINT, gs, gb, SINT, bs, bb, SINT, special)
#define  TinyImageFormat_PACK_4_SINT(rs, rb, gs, gb, bs, bb, as, ab, special)   TinyImageFormat_PACK(rs, rb, SINT, gs, gb, SINT, bs, bb, SINT, as, ab, SINT, special)
#define  TinyImageFormat_PACK_2_SFLOAT(rs, rb, gs, gb, special)   TinyImageFormat_PACK_2(rs, rb, SFLOAT, gs, gb, SFLOAT, special)
#define  TinyImageFormat_PACK_3_SFLOAT(rs, rb, gs, gb, bs, bb, special)   TinyImageFormat_PACK_3(rs, rb, SFLOAT, gs, gb, SFLOAT, bs, bb, SFLOAT, special)
#define  TinyImageFormat_PACK_4_SFLOAT(rs, rb, gs, gb, bs, bb, as, ab, special)   TinyImageFormat_PACK(rs, rb, SFLOAT, gs, gb, SFLOAT, bs, bb, SFLOAT, as, ab, SFLOAT, special)

#define  TinyImageFormat_PACK_2_SRGB(rs, rb, gs, gb, special)    TinyImageFormat_PACK_2(rs, rb, SRGB, gs, gb, SRGB, special)
#define  TinyImageFormat_PACK_3_SRGB(rs, rb, gs, gb, bs, bb, special)   TinyImageFormat_PACK_3(rs, rb, SRGB, gs, gb, SRGB, bs, bb, SRGB, special)
// SRGB never goes in alpha
#define  TinyImageFormat_PACK_4_SRGB(rs, rb, gs, gb, bs, bb, as, ab, special)   TinyImageFormat_PACK(rs, rb, SRGB, gs, gb, SRGB, bs, bb, SRGB, as, ab, UNORM, special)


#define  TinyImageFormat_DEPTH_STENCIL( rs, rb, rt, gs, gb, gt, size)   TinyImageFormat_CONSTEXPR_DepthStencil( \
				 TinyImageFormat_DEPTH_STENCIL_SWIZZLE_##rs,  TinyImageFormat_DEPTH_STENCIL_BITS_##rb,  TinyImageFormat_DEPTH_STENCIL_TYPE_##rt, \
				 TinyImageFormat_DEPTH_STENCIL_SWIZZLE_##gs,  TinyImageFormat_DEPTH_STENCIL_BITS_##gb,  TinyImageFormat_DEPTH_STENCIL_TYPE_##gt, \
				 TinyImageFormat_DEPTH_STENCIL_TOTAL_SIZE_##size)

#define  TinyImageFormat_DXTC(a, t, b, cc, mc)  TinyImageFormat_CONSTEXPR_DXTC( TinyImageFormat_DXTC_ALPHA_##a,  TinyImageFormat_DXTC_TYPE_##t,  TinyImageFormat_DXTC_BLOCKBYTES_##b,  TinyImageFormat_DXTC_CHANNELCOUNT_##cc,  TinyImageFormat_DXTC_MODECOUNT_##mc)
#define  TinyImageFormat_PVRTC(v, b, t)  TinyImageFormat_CONSTEXPR_PVRTC( TinyImageFormat_PVRTC_VERSION_##v,  TinyImageFormat_PVRTC_BITS_##b,  TinyImageFormat_PVRTC_TYPE_##t)
#define  TinyImageFormat_ETC(b, a, t, cc)  TinyImageFormat_CONSTEXPR_ETC( TinyImageFormat_ETC_BITS_##b,  TinyImageFormat_ETC_ALPHA_##a,  TinyImageFormat_ETC_TYPE_##t,  TinyImageFormat_ETC_CHANNELCOUNT_##cc)
#define  TinyImageFormat_ASTC(w, h, d, t)  TinyImageFormat_CONSTEXPR_ASTC( TinyImageFormat_ASTC_SIZE_##w,  TinyImageFormat_ASTC_SIZE_##h,  TinyImageFormat_ASTC_SIZE_##d,  TinyImageFormat_ASTC_TYPE_##t)
#define  TinyImageFormat_CLUT(bs, c0s, c0t, c1s, c1t)  TinyImageFormat_CONSTEXPR_CLUT( TinyImageFormat_CLUT_BLOCKSIZE_##bs, TinyImageFormat_CLUT_BITS_##c0s,  TinyImageFormat_CLUT_TYPE_##c0t,   TinyImageFormat_CLUT_BITS_##c1s,  TinyImageFormat_CLUT_TYPE_##c1t)


#define TinyImageFormat_PACK_BITS__  TinyImageFormat_PACK_BITS_0
#define TinyImageFormat_PACK_SWIZZLE__  TinyImageFormat_PACK_SWIZZLE_0
#define TinyImageFormat_PACK_TYPE__  TinyImageFormat_PACK_TYPE_NONE
#define TinyImageFormat_DEPTH_STENCIL_BITS__  TinyImageFormat_DEPTH_STENCIL_BITS_0
#define TinyImageFormat_DEPTH_STENCIL_SWIZZLE__  TinyImageFormat_DEPTH_STENCIL_SWIZZLE_0
#define TinyImageFormat_DEPTH_STENCIL_TYPE__  TinyImageFormat_DEPTH_STENCIL_TYPE_NONE

#define TinyImageFormat_CLUT_BLOCKSIZE__  TinyImageFormat_CLUT_BLOCKSIZE_1
#define TinyImageFormat_CLUT_BITS__  TinyImageFormat_CLUT_BITS_0
#define TinyImageFormat_CLUT_TYPE__  TinyImageFormat_CLUT_TYPE_NONE
