#pragma once

constexpr uint64_t  TinyImageFormat_CONSTEXPR_Pack(
		uint64_t rs, uint64_t rb, uint64_t rt,
		uint64_t gs, uint64_t gb, uint64_t gt,
		uint64_t bs, uint64_t bb, uint64_t bt,
		uint64_t as, uint64_t ab, uint64_t at,
		uint64_t special ) {

	static_assert((( TinyImageFormat_PACK_NUM_CHANNELS *  TinyImageFormat_PACK_BITS_REQUIRED_BITS) +  TinyImageFormat_PACK_BITS_SHIFT) == 35);
	static_assert((( TinyImageFormat_PACK_NUM_CHANNELS *  TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS) +  TinyImageFormat_PACK_SWIZZLE_SHIFT) == 47);
	static_assert((( TinyImageFormat_PACK_NUM_CHANNELS *  TinyImageFormat_PACK_TYPE_REQUIRED_BITS) +  TinyImageFormat_PACK_TYPE_SHIFT) == 63);

	static_assert((( TinyImageFormat_PACK_NUM_CHANNELS *  TinyImageFormat_PACK_TYPE_REQUIRED_BITS) +  TinyImageFormat_PACK_TYPE_SHIFT) < 64);

	uint64_t packed = TinyImageFormat_NAMESPACE_PACK |
			(special <<  TinyImageFormat_PACK_SPECIAL_SHIFT) |
			(rb << (( TinyImageFormat_PC_0 *  TinyImageFormat_PACK_BITS_REQUIRED_BITS) +  TinyImageFormat_PACK_BITS_SHIFT)) |
			(rs << (( TinyImageFormat_PC_0 *  TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS) +  TinyImageFormat_PACK_SWIZZLE_SHIFT)) |
			(rt << (( TinyImageFormat_PC_0 *  TinyImageFormat_PACK_TYPE_REQUIRED_BITS) +  TinyImageFormat_PACK_TYPE_SHIFT)) |

			(gb << (( TinyImageFormat_PC_1 *  TinyImageFormat_PACK_BITS_REQUIRED_BITS) +  TinyImageFormat_PACK_BITS_SHIFT)) |
			(gs << (( TinyImageFormat_PC_1 *  TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS) +  TinyImageFormat_PACK_SWIZZLE_SHIFT)) |
			(gt << (( TinyImageFormat_PC_1 *  TinyImageFormat_PACK_TYPE_REQUIRED_BITS) +  TinyImageFormat_PACK_TYPE_SHIFT)) |

			(bb << (( TinyImageFormat_PC_2 *  TinyImageFormat_PACK_BITS_REQUIRED_BITS) +  TinyImageFormat_PACK_BITS_SHIFT)) |
			(bs << (( TinyImageFormat_PC_2 *  TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS) +  TinyImageFormat_PACK_SWIZZLE_SHIFT)) |
			(bt << (( TinyImageFormat_PC_2 *  TinyImageFormat_PACK_TYPE_REQUIRED_BITS) +  TinyImageFormat_PACK_TYPE_SHIFT)) |

			(ab << (( TinyImageFormat_PC_3 *  TinyImageFormat_PACK_BITS_REQUIRED_BITS) +  TinyImageFormat_PACK_BITS_SHIFT)) |
			(as << (( TinyImageFormat_PC_3 *  TinyImageFormat_PACK_SWIZZLE_REQUIRED_BITS) +  TinyImageFormat_PACK_SWIZZLE_SHIFT)) |
			(at << (( TinyImageFormat_PC_3 *  TinyImageFormat_PACK_TYPE_REQUIRED_BITS) +  TinyImageFormat_PACK_TYPE_SHIFT)) |
			0;
	return packed;
}

constexpr uint64_t  TinyImageFormat_CONSTEXPR_DepthStencil( uint64_t rs, uint64_t rb, uint64_t rt, uint64_t gs, uint64_t gb, uint64_t gt, uint64_t size) {
	static_assert((( TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS *  TinyImageFormat_DEPTH_STENCIL_BITS_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_BITS_SHIFT) == 20);
	static_assert((( TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS *  TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_SWIZZLE_SHIFT) == 24);
	static_assert((( TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS *  TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_TYPE_SHIFT) == 28);

	static_assert((( TinyImageFormat_DEPTH_STENCIL_NUM_CHANNELS *  TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_TYPE_SHIFT) < 64);

	uint64_t value = TinyImageFormat_NAMESPACE_DEPTH_STENCIL |
			(size <<  TinyImageFormat_DEPTH_STENCIL_TOTAL_SIZE_SHIFT) |
			(rb << (( TinyImageFormat_PC_0 *  TinyImageFormat_DEPTH_STENCIL_BITS_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_BITS_SHIFT)) |
			(rs << (( TinyImageFormat_PC_0 *  TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_SWIZZLE_SHIFT)) |
			(rt << (( TinyImageFormat_PC_0 *  TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_TYPE_SHIFT)) |

			(gb << (( TinyImageFormat_PC_1 *  TinyImageFormat_DEPTH_STENCIL_BITS_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_BITS_SHIFT)) |
			(gs << (( TinyImageFormat_PC_1 *  TinyImageFormat_DEPTH_STENCIL_SWIZZLE_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_SWIZZLE_SHIFT)) |
			(gt << (( TinyImageFormat_PC_1 *  TinyImageFormat_DEPTH_STENCIL_TYPE_REQUIRED_BITS) +  TinyImageFormat_DEPTH_STENCIL_TYPE_SHIFT)) |
			0;
	return value;
}

constexpr uint64_t  TinyImageFormat_CONSTEXPR_DXTC(uint64_t alpha, uint64_t type, uint64_t blockBytes, uint64_t channelCount, uint64_t modeCount) {
	static_assert( TinyImageFormat_DXTC_ALPHA_SHIFT == 12);
	static_assert( TinyImageFormat_DXTC_TYPE_SHIFT == 14);
	static_assert( TinyImageFormat_DXTC_BLOCKBYTES_SHIFT == 17);
	static_assert( TinyImageFormat_DXTC_CHANNELCOUNT_SHIFT == 19);
	static_assert( TinyImageFormat_DXTC_MODECOUNT_SHIFT == 21);

	static_assert( TinyImageFormat_DXTC_MODECOUNT_REQUIRED_BITS +  TinyImageFormat_DXTC_MODECOUNT_SHIFT < 64);

	uint64_t value = TinyImageFormat_NAMESPACE_DXTC |
			(alpha <<  TinyImageFormat_DXTC_ALPHA_SHIFT) |
			(type <<  TinyImageFormat_DXTC_TYPE_SHIFT) |
			(blockBytes <<  TinyImageFormat_DXTC_BLOCKBYTES_SHIFT) |
			(channelCount <<  TinyImageFormat_DXTC_CHANNELCOUNT_SHIFT) |
			(modeCount <<  TinyImageFormat_DXTC_MODECOUNT_SHIFT) |
			0;
	return value;
}

constexpr uint64_t  TinyImageFormat_CONSTEXPR_PVRTC(uint64_t version, uint64_t bits, uint64_t type) {
	static_assert( TinyImageFormat_PVRTC_VERSION_SHIFT == 12);
	static_assert( TinyImageFormat_PVRTC_BITS_SHIFT == 14);
	static_assert( TinyImageFormat_PVRTC_TYPE_SHIFT == 16);

	static_assert( TinyImageFormat_PVRTC_TYPE_REQUIRED_BITS +  TinyImageFormat_PVRTC_TYPE_SHIFT < 64);

	uint64_t value = TinyImageFormat_NAMESPACE_PVRTC |
			(version <<  TinyImageFormat_PVRTC_VERSION_SHIFT) |
			(bits <<  TinyImageFormat_PVRTC_BITS_SHIFT) |
			(type <<  TinyImageFormat_PVRTC_TYPE_SHIFT) |
			0;
	return value;
}

constexpr uint64_t  TinyImageFormat_CONSTEXPR_ETC(uint64_t bits, uint64_t alpha, uint64_t type, uint64_t channelCount) {
	static_assert( TinyImageFormat_ETC_BITS_SHIFT == 12);
	static_assert( TinyImageFormat_ETC_ALPHA_SHIFT == 14);
	static_assert( TinyImageFormat_ETC_TYPE_SHIFT == 16);
	static_assert( TinyImageFormat_ETC_CHANNELCOUNT_SHIFT == 18);

	static_assert( TinyImageFormat_ETC_CHANNELCOUNT_REQUIRED_BITS +  TinyImageFormat_ETC_CHANNELCOUNT_SHIFT < 64);

	uint64_t value = TinyImageFormat_NAMESPACE_ETC |
			(bits <<  TinyImageFormat_ETC_BITS_SHIFT) |
			(alpha <<  TinyImageFormat_ETC_ALPHA_SHIFT) |
			(type <<  TinyImageFormat_ETC_TYPE_SHIFT) |
			(channelCount <<  TinyImageFormat_ETC_CHANNELCOUNT_SHIFT) |
			0;
	return value;
}

constexpr uint64_t  TinyImageFormat_CONSTEXPR_ASTC(uint64_t w, uint64_t h, uint64_t d, uint64_t type) {
	static_assert( TinyImageFormat_ASTC_SIZE_SHIFT == 12);
	static_assert( TinyImageFormat_ASTC_TYPE_SHIFT == 21);

	static_assert( (TinyImageFormat_ASTC_NUM_DIMS * TinyImageFormat_ASTC_TYPE_REQUIRED_BITS) +  TinyImageFormat_ASTC_TYPE_SHIFT < 64);

	uint64_t value = TinyImageFormat_NAMESPACE_ASTC |
			(w << ((0 *  TinyImageFormat_ASTC_SIZE_REQUIRED_BITS) +  TinyImageFormat_ASTC_SIZE_SHIFT)) |
			(h << ((1 *  TinyImageFormat_ASTC_SIZE_REQUIRED_BITS) +  TinyImageFormat_ASTC_SIZE_SHIFT)) |
			(d << ((2 *  TinyImageFormat_ASTC_SIZE_REQUIRED_BITS) +  TinyImageFormat_ASTC_SIZE_SHIFT)) |
			(type <<  TinyImageFormat_ASTC_TYPE_SHIFT) |
			0;
	return value;
}

constexpr uint64_t  TinyImageFormat_CONSTEXPR_CLUT(uint64_t bs, uint64_t c0s, uint64_t c0t, uint64_t c1s, uint64_t c1t) {
	static_assert( TinyImageFormat_CLUT_BLOCKSIZE_SHIFT == 12);
	static_assert( TinyImageFormat_CLUT_BITS_SHIFT == 14);
	static_assert( TinyImageFormat_CLUT_TYPE_SHIFT == 20);

	static_assert( (TinyImageFormat_CLUT_NUM_CHANNELS * TinyImageFormat_CLUT_TYPE_REQUIRED_BITS) +  TinyImageFormat_CLUT_TYPE_SHIFT < 64);

	uint64_t value = 	TinyImageFormat_NAMESPACE_CLUT |
			(bs << TinyImageFormat_CLUT_BLOCKSIZE_SHIFT) |
			(c0s << ((0 *  TinyImageFormat_CLUT_BITS_REQUIRED_BITS) +  TinyImageFormat_CLUT_BITS_SHIFT)) |
			(c1s << ((1 *  TinyImageFormat_CLUT_BITS_REQUIRED_BITS) +  TinyImageFormat_CLUT_BITS_SHIFT)) |
			(c0t << ((0 *  TinyImageFormat_CLUT_TYPE_REQUIRED_BITS) +  TinyImageFormat_CLUT_TYPE_SHIFT)) |
			(c1t << ((1 *  TinyImageFormat_CLUT_TYPE_REQUIRED_BITS) +  TinyImageFormat_CLUT_TYPE_SHIFT)) |
			0;
	return value;
}

constexpr bool IsInPacked(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_PACK;
}

constexpr bool IsInDepthStencil(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_DEPTH_STENCIL;
}

constexpr bool IsInDXTC(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_DXTC;
}

constexpr bool IsInPVRTC(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_PVRTC;
}

constexpr bool IsInETC(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_ETC;
}

constexpr bool IsInASTC(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_ASTC;
}

constexpr bool IsInCLUT(char const *name, uint64_t v) {
	return (v & TinyImageFormat_NAMESPACE_MASK) == TinyImageFormat_NAMESPACE_CLUT;
}

constexpr uint64_t Mask(uint64_t v) {
	return (1ULL << v) - 1ULL;
}
