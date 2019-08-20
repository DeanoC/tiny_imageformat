// NOTE this copy is not actually used copy it manually into formatgen.cpp

#ifndef TINYIMAGEFORMAT_VKFORMAT
#define TINYIMAGEFORMAT_VKFORMAT
typedef enum TinyImageFormat_VkFormat {
	TIF_VK_FORMAT_UNDEFINED = 0,
	TIF_VK_FORMAT_R4G4_UNORM_PACK8 = 1,
	TIF_VK_FORMAT_R4G4B4A4_UNORM_PACK16 = 2,
	TIF_VK_FORMAT_B4G4R4A4_UNORM_PACK16 = 3,
	TIF_VK_FORMAT_R5G6B5_UNORM_PACK16 = 4,
	TIF_VK_FORMAT_B5G6R5_UNORM_PACK16 = 5,
	TIF_VK_FORMAT_R5G5B5A1_UNORM_PACK16 = 6,
	TIF_VK_FORMAT_B5G5R5A1_UNORM_PACK16 = 7,
	TIF_VK_FORMAT_A1R5G5B5_UNORM_PACK16 = 8,
	TIF_VK_FORMAT_R8_UNORM = 9,
	TIF_VK_FORMAT_R8_SNORM = 10,
	TIF_VK_FORMAT_R8_USCALED = 11,
	TIF_VK_FORMAT_R8_SSCALED = 12,
	TIF_VK_FORMAT_R8_UINT = 13,
	TIF_VK_FORMAT_R8_SINT = 14,
	TIF_VK_FORMAT_R8_SRGB = 15,
	TIF_VK_FORMAT_R8G8_UNORM = 16,
	TIF_VK_FORMAT_R8G8_SNORM = 17,
	TIF_VK_FORMAT_R8G8_USCALED = 18,
	TIF_VK_FORMAT_R8G8_SSCALED = 19,
	TIF_VK_FORMAT_R8G8_UINT = 20,
	TIF_VK_FORMAT_R8G8_SINT = 21,
	TIF_VK_FORMAT_R8G8_SRGB = 22,
	TIF_VK_FORMAT_R8G8B8_UNORM = 23,
	TIF_VK_FORMAT_R8G8B8_SNORM = 24,
	TIF_VK_FORMAT_R8G8B8_USCALED = 25,
	TIF_VK_FORMAT_R8G8B8_SSCALED = 26,
	TIF_VK_FORMAT_R8G8B8_UINT = 27,
	TIF_VK_FORMAT_R8G8B8_SINT = 28,
	TIF_VK_FORMAT_R8G8B8_SRGB = 29,
	TIF_VK_FORMAT_B8G8R8_UNORM = 30,
	TIF_VK_FORMAT_B8G8R8_SNORM = 31,
	TIF_VK_FORMAT_B8G8R8_USCALED = 32,
	TIF_VK_FORMAT_B8G8R8_SSCALED = 33,
	TIF_VK_FORMAT_B8G8R8_UINT = 34,
	TIF_VK_FORMAT_B8G8R8_SINT = 35,
	TIF_VK_FORMAT_B8G8R8_SRGB = 36,
	TIF_VK_FORMAT_R8G8B8A8_UNORM = 37,
	TIF_VK_FORMAT_R8G8B8A8_SNORM = 38,
	TIF_VK_FORMAT_R8G8B8A8_USCALED = 39,
	TIF_VK_FORMAT_R8G8B8A8_SSCALED = 40,
	TIF_VK_FORMAT_R8G8B8A8_UINT = 41,
	TIF_VK_FORMAT_R8G8B8A8_SINT = 42,
	TIF_VK_FORMAT_R8G8B8A8_SRGB = 43,
	TIF_VK_FORMAT_B8G8R8A8_UNORM = 44,
	TIF_VK_FORMAT_B8G8R8A8_SNORM = 45,
	TIF_VK_FORMAT_B8G8R8A8_USCALED = 46,
	TIF_VK_FORMAT_B8G8R8A8_SSCALED = 47,
	TIF_VK_FORMAT_B8G8R8A8_UINT = 48,
	TIF_VK_FORMAT_B8G8R8A8_SINT = 49,
	TIF_VK_FORMAT_B8G8R8A8_SRGB = 50,
	TIF_VK_FORMAT_A8B8G8R8_UNORM_PACK32 = 51,
	TIF_VK_FORMAT_A8B8G8R8_SNORM_PACK32 = 52,
	TIF_VK_FORMAT_A8B8G8R8_USCALED_PACK32 = 53,
	TIF_VK_FORMAT_A8B8G8R8_SSCALED_PACK32 = 54,
	TIF_VK_FORMAT_A8B8G8R8_UINT_PACK32 = 55,
	TIF_VK_FORMAT_A8B8G8R8_SINT_PACK32 = 56,
	TIF_VK_FORMAT_A8B8G8R8_SRGB_PACK32 = 57,
	TIF_VK_FORMAT_A2R10G10B10_UNORM_PACK32 = 58,
	TIF_VK_FORMAT_A2R10G10B10_SNORM_PACK32 = 59,
	TIF_VK_FORMAT_A2R10G10B10_USCALED_PACK32 = 60,
	TIF_VK_FORMAT_A2R10G10B10_SSCALED_PACK32 = 61,
	TIF_VK_FORMAT_A2R10G10B10_UINT_PACK32 = 62,
	TIF_VK_FORMAT_A2R10G10B10_SINT_PACK32 = 63,
	TIF_VK_FORMAT_A2B10G10R10_UNORM_PACK32 = 64,
	TIF_VK_FORMAT_A2B10G10R10_SNORM_PACK32 = 65,
	TIF_VK_FORMAT_A2B10G10R10_USCALED_PACK32 = 66,
	TIF_VK_FORMAT_A2B10G10R10_SSCALED_PACK32 = 67,
	TIF_VK_FORMAT_A2B10G10R10_UINT_PACK32 = 68,
	TIF_VK_FORMAT_A2B10G10R10_SINT_PACK32 = 69,
	TIF_VK_FORMAT_R16_UNORM = 70,
	TIF_VK_FORMAT_R16_SNORM = 71,
	TIF_VK_FORMAT_R16_USCALED = 72,
	TIF_VK_FORMAT_R16_SSCALED = 73,
	TIF_VK_FORMAT_R16_UINT = 74,
	TIF_VK_FORMAT_R16_SINT = 75,
	TIF_VK_FORMAT_R16_SFLOAT = 76,
	TIF_VK_FORMAT_R16G16_UNORM = 77,
	TIF_VK_FORMAT_R16G16_SNORM = 78,
	TIF_VK_FORMAT_R16G16_USCALED = 79,
	TIF_VK_FORMAT_R16G16_SSCALED = 80,
	TIF_VK_FORMAT_R16G16_UINT = 81,
	TIF_VK_FORMAT_R16G16_SINT = 82,
	TIF_VK_FORMAT_R16G16_SFLOAT = 83,
	TIF_VK_FORMAT_R16G16B16_UNORM = 84,
	TIF_VK_FORMAT_R16G16B16_SNORM = 85,
	TIF_VK_FORMAT_R16G16B16_USCALED = 86,
	TIF_VK_FORMAT_R16G16B16_SSCALED = 87,
	TIF_VK_FORMAT_R16G16B16_UINT = 88,
	TIF_VK_FORMAT_R16G16B16_SINT = 89,
	TIF_VK_FORMAT_R16G16B16_SFLOAT = 90,
	TIF_VK_FORMAT_R16G16B16A16_UNORM = 91,
	TIF_VK_FORMAT_R16G16B16A16_SNORM = 92,
	TIF_VK_FORMAT_R16G16B16A16_USCALED = 93,
	TIF_VK_FORMAT_R16G16B16A16_SSCALED = 94,
	TIF_VK_FORMAT_R16G16B16A16_UINT = 95,
	TIF_VK_FORMAT_R16G16B16A16_SINT = 96,
	TIF_VK_FORMAT_R16G16B16A16_SFLOAT = 97,
	TIF_VK_FORMAT_R32_UINT = 98,
	TIF_VK_FORMAT_R32_SINT = 99,
	TIF_VK_FORMAT_R32_SFLOAT = 100,
	TIF_VK_FORMAT_R32G32_UINT = 101,
	TIF_VK_FORMAT_R32G32_SINT = 102,
	TIF_VK_FORMAT_R32G32_SFLOAT = 103,
	TIF_VK_FORMAT_R32G32B32_UINT = 104,
	TIF_VK_FORMAT_R32G32B32_SINT = 105,
	TIF_VK_FORMAT_R32G32B32_SFLOAT = 106,
	TIF_VK_FORMAT_R32G32B32A32_UINT = 107,
	TIF_VK_FORMAT_R32G32B32A32_SINT = 108,
	TIF_VK_FORMAT_R32G32B32A32_SFLOAT = 109,
	TIF_VK_FORMAT_R64_UINT = 110,
	TIF_VK_FORMAT_R64_SINT = 111,
	TIF_VK_FORMAT_R64_SFLOAT = 112,
	TIF_VK_FORMAT_R64G64_UINT = 113,
	TIF_VK_FORMAT_R64G64_SINT = 114,
	TIF_VK_FORMAT_R64G64_SFLOAT = 115,
	TIF_VK_FORMAT_R64G64B64_UINT = 116,
	TIF_VK_FORMAT_R64G64B64_SINT = 117,
	TIF_VK_FORMAT_R64G64B64_SFLOAT = 118,
	TIF_VK_FORMAT_R64G64B64A64_UINT = 119,
	TIF_VK_FORMAT_R64G64B64A64_SINT = 120,
	TIF_VK_FORMAT_R64G64B64A64_SFLOAT = 121,
	TIF_VK_FORMAT_B10G11R11_UFLOAT_PACK32 = 122,
	TIF_VK_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123,
	TIF_VK_FORMAT_D16_UNORM = 124,
	TIF_VK_FORMAT_X8_D24_UNORM_PACK32 = 125,
	TIF_VK_FORMAT_D32_SFLOAT = 126,
	TIF_VK_FORMAT_S8_UINT = 127,
	TIF_VK_FORMAT_D16_UNORM_S8_UINT = 128,
	TIF_VK_FORMAT_D24_UNORM_S8_UINT = 129,
	TIF_VK_FORMAT_D32_SFLOAT_S8_UINT = 130,
	TIF_VK_FORMAT_BC1_RGB_UNORM_BLOCK = 131,
	TIF_VK_FORMAT_BC1_RGB_SRGB_BLOCK = 132,
	TIF_VK_FORMAT_BC1_RGBA_UNORM_BLOCK = 133,
	TIF_VK_FORMAT_BC1_RGBA_SRGB_BLOCK = 134,
	TIF_VK_FORMAT_BC2_UNORM_BLOCK = 135,
	TIF_VK_FORMAT_BC2_SRGB_BLOCK = 136,
	TIF_VK_FORMAT_BC3_UNORM_BLOCK = 137,
	TIF_VK_FORMAT_BC3_SRGB_BLOCK = 138,
	TIF_VK_FORMAT_BC4_UNORM_BLOCK = 139,
	TIF_VK_FORMAT_BC4_SNORM_BLOCK = 140,
	TIF_VK_FORMAT_BC5_UNORM_BLOCK = 141,
	TIF_VK_FORMAT_BC5_SNORM_BLOCK = 142,
	TIF_VK_FORMAT_BC6H_UFLOAT_BLOCK = 143,
	TIF_VK_FORMAT_BC6H_SFLOAT_BLOCK = 144,
	TIF_VK_FORMAT_BC7_UNORM_BLOCK = 145,
	TIF_VK_FORMAT_BC7_SRGB_BLOCK = 146,
	TIF_VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147,
	TIF_VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148,
	TIF_VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149,
	TIF_VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150,
	TIF_VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151,
	TIF_VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152,
	TIF_VK_FORMAT_EAC_R11_UNORM_BLOCK = 153,
	TIF_VK_FORMAT_EAC_R11_SNORM_BLOCK = 154,
	TIF_VK_FORMAT_EAC_R11G11_UNORM_BLOCK = 155,
	TIF_VK_FORMAT_EAC_R11G11_SNORM_BLOCK = 156,
	TIF_VK_FORMAT_ASTC_4x4_UNORM_BLOCK = 157,
	TIF_VK_FORMAT_ASTC_4x4_SRGB_BLOCK = 158,
	TIF_VK_FORMAT_ASTC_5x4_UNORM_BLOCK = 159,
	TIF_VK_FORMAT_ASTC_5x4_SRGB_BLOCK = 160,
	TIF_VK_FORMAT_ASTC_5x5_UNORM_BLOCK = 161,
	TIF_VK_FORMAT_ASTC_5x5_SRGB_BLOCK = 162,
	TIF_VK_FORMAT_ASTC_6x5_UNORM_BLOCK = 163,
	TIF_VK_FORMAT_ASTC_6x5_SRGB_BLOCK = 164,
	TIF_VK_FORMAT_ASTC_6x6_UNORM_BLOCK = 165,
	TIF_VK_FORMAT_ASTC_6x6_SRGB_BLOCK = 166,
	TIF_VK_FORMAT_ASTC_8x5_UNORM_BLOCK = 167,
	TIF_VK_FORMAT_ASTC_8x5_SRGB_BLOCK = 168,
	TIF_VK_FORMAT_ASTC_8x6_UNORM_BLOCK = 169,
	TIF_VK_FORMAT_ASTC_8x6_SRGB_BLOCK = 170,
	TIF_VK_FORMAT_ASTC_8x8_UNORM_BLOCK = 171,
	TIF_VK_FORMAT_ASTC_8x8_SRGB_BLOCK = 172,
	TIF_VK_FORMAT_ASTC_10x5_UNORM_BLOCK = 173,
	TIF_VK_FORMAT_ASTC_10x5_SRGB_BLOCK = 174,
	TIF_VK_FORMAT_ASTC_10x6_UNORM_BLOCK = 175,
	TIF_VK_FORMAT_ASTC_10x6_SRGB_BLOCK = 176,
	TIF_VK_FORMAT_ASTC_10x8_UNORM_BLOCK = 177,
	TIF_VK_FORMAT_ASTC_10x8_SRGB_BLOCK = 178,
	TIF_VK_FORMAT_ASTC_10x10_UNORM_BLOCK = 179,
	TIF_VK_FORMAT_ASTC_10x10_SRGB_BLOCK = 180,
	TIF_VK_FORMAT_ASTC_12x10_UNORM_BLOCK = 181,
	TIF_VK_FORMAT_ASTC_12x10_SRGB_BLOCK = 182,
	TIF_VK_FORMAT_ASTC_12x12_UNORM_BLOCK = 183,
	TIF_VK_FORMAT_ASTC_12x12_SRGB_BLOCK = 184,

	TIF_VK_FORMAT_G8B8G8R8_422_UNORM = 1000156000,
	TIF_VK_FORMAT_B8G8R8G8_422_UNORM = 1000156001,
	TIF_VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM = 1000156002,
	TIF_VK_FORMAT_G8_B8R8_2PLANE_420_UNORM = 1000156003,
	TIF_VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM = 1000156004,
	TIF_VK_FORMAT_G8_B8R8_2PLANE_422_UNORM = 1000156005,
	TIF_VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM = 1000156006,
	TIF_VK_FORMAT_R10X6_UNORM_PACK16 = 1000156007,
	TIF_VK_FORMAT_R10X6G10X6_UNORM_2PACK16 = 1000156008,
	TIF_VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16 = 1000156009,
	TIF_VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 = 1000156010,
	TIF_VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 = 1000156011,
	TIF_VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 = 1000156012,
	TIF_VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 = 1000156013,
	TIF_VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 = 1000156014,
	TIF_VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 = 1000156015,
	TIF_VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 = 1000156016,
	TIF_VK_FORMAT_R12X4_UNORM_PACK16 = 1000156017,
	TIF_VK_FORMAT_R12X4G12X4_UNORM_2PACK16 = 1000156018,
	TIF_VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16 = 1000156019,
	TIF_VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 = 1000156020,
	TIF_VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 = 1000156021,
	TIF_VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 = 1000156022,
	TIF_VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 = 1000156023,
	TIF_VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 = 1000156024,
	TIF_VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 = 1000156025,
	TIF_VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 = 1000156026,
	TIF_VK_FORMAT_G16B16G16R16_422_UNORM = 1000156027,
	TIF_VK_FORMAT_B16G16R16G16_422_UNORM = 1000156028,
	TIF_VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM = 1000156029,
	TIF_VK_FORMAT_G16_B16R16_2PLANE_420_UNORM = 1000156030,
	TIF_VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM = 1000156031,
	TIF_VK_FORMAT_G16_B16R16_2PLANE_422_UNORM = 1000156032,
	TIF_VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM = 1000156033,
	TIF_VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG = 1000054000,
	TIF_VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG = 1000054001,
	TIF_VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG = 1000054002,
	TIF_VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG = 1000054003,
	TIF_VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG = 1000054004,
	TIF_VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG = 1000054005,
	TIF_VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG = 1000054006,
	TIF_VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG = 1000054007,
} TinyImageFormat_VkFormat;
#endif

inline TinyImageFormat TinyImageFormat_FromVkFormat(TinyImageFormat_VkFormat fmt) {
	switch (fmt) {

	case TIF_VK_FORMAT_UNDEFINED: return TinyImageFormat_UNDEFINED;
	case TIF_VK_FORMAT_R4G4_UNORM_PACK8: return TinyImageFormat_R4G4_UNORM;
	case TIF_VK_FORMAT_R4G4B4A4_UNORM_PACK16: return TinyImageFormat_R4G4B4A4_UNORM;
	case TIF_VK_FORMAT_B4G4R4A4_UNORM_PACK16: return TinyImageFormat_B4G4R4A4_UNORM;
	case TIF_VK_FORMAT_R5G6B5_UNORM_PACK16: return TinyImageFormat_R5G6B5_UNORM;
	case TIF_VK_FORMAT_B5G6R5_UNORM_PACK16: return TinyImageFormat_B5G6R5_UNORM;
	case TIF_VK_FORMAT_R5G5B5A1_UNORM_PACK16: return TinyImageFormat_R5G5B5A1_UNORM;
	case TIF_VK_FORMAT_B5G5R5A1_UNORM_PACK16: return TinyImageFormat_B5G5R5A1_UNORM;
	case TIF_VK_FORMAT_A1R5G5B5_UNORM_PACK16: return TinyImageFormat_A1R5G5B5_UNORM;
	case TIF_VK_FORMAT_R8_UNORM: return TinyImageFormat_R8_UNORM;
	case TIF_VK_FORMAT_R8_SNORM: return TinyImageFormat_R8_SNORM;
	case TIF_VK_FORMAT_R8_UINT: return TinyImageFormat_R8_UINT;
	case TIF_VK_FORMAT_R8_SINT: return TinyImageFormat_R8_SINT;
	case TIF_VK_FORMAT_R8_SRGB: return TinyImageFormat_R8_SRGB;
	case TIF_VK_FORMAT_R8G8_UNORM: return TinyImageFormat_R8G8_UNORM;
	case TIF_VK_FORMAT_R8G8_SNORM: return TinyImageFormat_R8G8_SNORM;
	case TIF_VK_FORMAT_R8G8_UINT: return TinyImageFormat_R8G8_UINT;
	case TIF_VK_FORMAT_R8G8_SINT: return TinyImageFormat_R8G8_SINT;
	case TIF_VK_FORMAT_R8G8_SRGB: return TinyImageFormat_R8G8_SRGB;
	case TIF_VK_FORMAT_R8G8B8_UNORM: return TinyImageFormat_R8G8B8_UNORM;
	case TIF_VK_FORMAT_R8G8B8_SNORM: return TinyImageFormat_R8G8B8_SNORM;
	case TIF_VK_FORMAT_R8G8B8_UINT: return TinyImageFormat_R8G8B8_UINT;
	case TIF_VK_FORMAT_R8G8B8_SINT: return TinyImageFormat_R8G8B8_SINT;
	case TIF_VK_FORMAT_R8G8B8_SRGB: return TinyImageFormat_R8G8B8_SRGB;
	case TIF_VK_FORMAT_B8G8R8_UNORM: return TinyImageFormat_B8G8R8_UNORM;
	case TIF_VK_FORMAT_B8G8R8_SNORM: return TinyImageFormat_B8G8R8_SNORM;
	case TIF_VK_FORMAT_B8G8R8_UINT: return TinyImageFormat_B8G8R8_UINT;
	case TIF_VK_FORMAT_B8G8R8_SINT: return TinyImageFormat_B8G8R8_SINT;
	case TIF_VK_FORMAT_B8G8R8_SRGB: return TinyImageFormat_B8G8R8_SRGB;
	case TIF_VK_FORMAT_R8G8B8A8_UNORM: return TinyImageFormat_R8G8B8A8_UNORM;
	case TIF_VK_FORMAT_R8G8B8A8_SNORM: return TinyImageFormat_R8G8B8A8_SNORM;
	case TIF_VK_FORMAT_R8G8B8A8_UINT: return TinyImageFormat_R8G8B8A8_UINT;
	case TIF_VK_FORMAT_R8G8B8A8_SINT: return TinyImageFormat_R8G8B8A8_SINT;
	case TIF_VK_FORMAT_R8G8B8A8_SRGB: return TinyImageFormat_R8G8B8A8_SRGB;
	case TIF_VK_FORMAT_B8G8R8A8_UNORM: return TinyImageFormat_B8G8R8A8_UNORM;
	case TIF_VK_FORMAT_B8G8R8A8_SNORM: return TinyImageFormat_B8G8R8A8_SNORM;
	case TIF_VK_FORMAT_B8G8R8A8_UINT: return TinyImageFormat_B8G8R8A8_UINT;
	case TIF_VK_FORMAT_B8G8R8A8_SINT: return TinyImageFormat_B8G8R8A8_SINT;
	case TIF_VK_FORMAT_B8G8R8A8_SRGB: return TinyImageFormat_B8G8R8A8_SRGB;
	case TIF_VK_FORMAT_A2R10G10B10_UNORM_PACK32: return TinyImageFormat_A2R10G10B10_UNORM;
	case TIF_VK_FORMAT_A2R10G10B10_UINT_PACK32: return TinyImageFormat_A2R10G10B10_UINT;
	case TIF_VK_FORMAT_A2B10G10R10_UNORM_PACK32: return TinyImageFormat_A2B10G10R10_UNORM;
	case TIF_VK_FORMAT_A2B10G10R10_UINT_PACK32: return TinyImageFormat_A2B10G10R10_UINT;
	case TIF_VK_FORMAT_R16_UNORM: return TinyImageFormat_R16_UNORM;
	case TIF_VK_FORMAT_R16_SNORM: return TinyImageFormat_R16_SNORM;
	case TIF_VK_FORMAT_R16_UINT: return TinyImageFormat_R16_UINT;
	case TIF_VK_FORMAT_R16_SINT: return TinyImageFormat_R16_SINT;
	case TIF_VK_FORMAT_R16_SFLOAT: return TinyImageFormat_R16_SFLOAT;
	case TIF_VK_FORMAT_R16G16_UNORM: return TinyImageFormat_R16G16_UNORM;
	case TIF_VK_FORMAT_R16G16_SNORM: return TinyImageFormat_R16G16_SNORM;
	case TIF_VK_FORMAT_R16G16_UINT: return TinyImageFormat_R16G16_UINT;
	case TIF_VK_FORMAT_R16G16_SINT: return TinyImageFormat_R16G16_SINT;
	case TIF_VK_FORMAT_R16G16_SFLOAT: return TinyImageFormat_R16G16_SFLOAT;
	case TIF_VK_FORMAT_R16G16B16_UNORM: return TinyImageFormat_R16G16B16_UNORM;
	case TIF_VK_FORMAT_R16G16B16_SNORM: return TinyImageFormat_R16G16B16_SNORM;
	case TIF_VK_FORMAT_R16G16B16_UINT: return TinyImageFormat_R16G16B16_UINT;
	case TIF_VK_FORMAT_R16G16B16_SINT: return TinyImageFormat_R16G16B16_SINT;
	case TIF_VK_FORMAT_R16G16B16_SFLOAT: return TinyImageFormat_R16G16B16_SFLOAT;
	case TIF_VK_FORMAT_R16G16B16A16_UNORM: return TinyImageFormat_R16G16B16A16_UNORM;
	case TIF_VK_FORMAT_R16G16B16A16_SNORM: return TinyImageFormat_R16G16B16A16_SNORM;
	case TIF_VK_FORMAT_R16G16B16A16_UINT: return TinyImageFormat_R16G16B16A16_UINT;
	case TIF_VK_FORMAT_R16G16B16A16_SINT: return TinyImageFormat_R16G16B16A16_SINT;
	case TIF_VK_FORMAT_R16G16B16A16_SFLOAT: return TinyImageFormat_R16G16B16A16_SFLOAT;
	case TIF_VK_FORMAT_R32_UINT: return TinyImageFormat_R32_UINT;
	case TIF_VK_FORMAT_R32_SINT: return TinyImageFormat_R32_SINT;
	case TIF_VK_FORMAT_R32_SFLOAT: return TinyImageFormat_R32_SFLOAT;
	case TIF_VK_FORMAT_R32G32_UINT: return TinyImageFormat_R32G32_UINT;
	case TIF_VK_FORMAT_R32G32_SINT: return TinyImageFormat_R32G32_SINT;
	case TIF_VK_FORMAT_R32G32_SFLOAT: return TinyImageFormat_R32G32_SFLOAT;
	case TIF_VK_FORMAT_R32G32B32_UINT: return TinyImageFormat_R32G32B32_UINT;
	case TIF_VK_FORMAT_R32G32B32_SINT: return TinyImageFormat_R32G32B32_SINT;
	case TIF_VK_FORMAT_R32G32B32_SFLOAT: return TinyImageFormat_R32G32B32_SFLOAT;
	case TIF_VK_FORMAT_R32G32B32A32_UINT: return TinyImageFormat_R32G32B32A32_UINT;
	case TIF_VK_FORMAT_R32G32B32A32_SINT: return TinyImageFormat_R32G32B32A32_SINT;
	case TIF_VK_FORMAT_R32G32B32A32_SFLOAT: return TinyImageFormat_R32G32B32A32_SFLOAT;
	case TIF_VK_FORMAT_R64_UINT: return TinyImageFormat_R64_UINT;
	case TIF_VK_FORMAT_R64_SINT: return TinyImageFormat_R64_SINT;
	case TIF_VK_FORMAT_R64_SFLOAT: return TinyImageFormat_R64_SFLOAT;
	case TIF_VK_FORMAT_R64G64_UINT: return TinyImageFormat_R64G64_UINT;
	case TIF_VK_FORMAT_R64G64_SINT: return TinyImageFormat_R64G64_SINT;
	case TIF_VK_FORMAT_R64G64_SFLOAT: return TinyImageFormat_R64G64_SFLOAT;
	case TIF_VK_FORMAT_R64G64B64_UINT: return TinyImageFormat_R64G64B64_UINT;
	case TIF_VK_FORMAT_R64G64B64_SINT: return TinyImageFormat_R64G64B64_SINT;
	case TIF_VK_FORMAT_R64G64B64_SFLOAT: return TinyImageFormat_R64G64B64_SFLOAT;
	case TIF_VK_FORMAT_R64G64B64A64_UINT: return TinyImageFormat_R64G64B64A64_UINT;
	case TIF_VK_FORMAT_R64G64B64A64_SINT: return TinyImageFormat_R64G64B64A64_SINT;
	case TIF_VK_FORMAT_R64G64B64A64_SFLOAT: return TinyImageFormat_R64G64B64A64_SFLOAT;
	case TIF_VK_FORMAT_B10G11R11_UFLOAT_PACK32: return TinyImageFormat_B10G11R11_UFLOAT;
	case TIF_VK_FORMAT_E5B9G9R9_UFLOAT_PACK32: return TinyImageFormat_E5B9G9R9_UFLOAT;
	case TIF_VK_FORMAT_D16_UNORM: return TinyImageFormat_D16_UNORM;
	case TIF_VK_FORMAT_X8_D24_UNORM_PACK32: return TinyImageFormat_X8_D24_UNORM;
	case TIF_VK_FORMAT_D32_SFLOAT: return TinyImageFormat_D32_SFLOAT;
	case TIF_VK_FORMAT_S8_UINT: return TinyImageFormat_S8_UINT;
	case TIF_VK_FORMAT_D16_UNORM_S8_UINT: return TinyImageFormat_D16_UNORM_S8_UINT;
	case TIF_VK_FORMAT_D24_UNORM_S8_UINT: return TinyImageFormat_D24_UNORM_S8_UINT;
	case TIF_VK_FORMAT_D32_SFLOAT_S8_UINT: return TinyImageFormat_D32_SFLOAT_S8_UINT;
	case TIF_VK_FORMAT_BC1_RGB_UNORM_BLOCK: return TinyImageFormat_DXBC1_RGB_UNORM;
	case TIF_VK_FORMAT_BC1_RGB_SRGB_BLOCK: return TinyImageFormat_DXBC1_RGB_SRGB;
	case TIF_VK_FORMAT_BC1_RGBA_UNORM_BLOCK: return TinyImageFormat_DXBC1_RGBA_UNORM;
	case TIF_VK_FORMAT_BC1_RGBA_SRGB_BLOCK: return TinyImageFormat_DXBC1_RGBA_SRGB;
	case TIF_VK_FORMAT_BC2_UNORM_BLOCK: return TinyImageFormat_DXBC2_UNORM;
	case TIF_VK_FORMAT_BC2_SRGB_BLOCK: return TinyImageFormat_DXBC2_SRGB;
	case TIF_VK_FORMAT_BC3_UNORM_BLOCK: return TinyImageFormat_DXBC3_UNORM;
	case TIF_VK_FORMAT_BC3_SRGB_BLOCK: return TinyImageFormat_DXBC3_SRGB;
	case TIF_VK_FORMAT_BC4_UNORM_BLOCK: return TinyImageFormat_DXBC4_UNORM;
	case TIF_VK_FORMAT_BC4_SNORM_BLOCK: return TinyImageFormat_DXBC4_SNORM;
	case TIF_VK_FORMAT_BC5_UNORM_BLOCK: return TinyImageFormat_DXBC5_UNORM;
	case TIF_VK_FORMAT_BC5_SNORM_BLOCK: return TinyImageFormat_DXBC5_SNORM;
	case TIF_VK_FORMAT_BC6H_UFLOAT_BLOCK: return TinyImageFormat_DXBC6H_UFLOAT;
	case TIF_VK_FORMAT_BC6H_SFLOAT_BLOCK: return TinyImageFormat_DXBC6H_SFLOAT;
	case TIF_VK_FORMAT_BC7_UNORM_BLOCK: return TinyImageFormat_DXBC7_UNORM;
	case TIF_VK_FORMAT_BC7_SRGB_BLOCK: return TinyImageFormat_DXBC7_SRGB;
	case TIF_VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK: return TinyImageFormat_ETC2_R8G8B8_UNORM;
	case TIF_VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK: return TinyImageFormat_ETC2_R8G8B8_SRGB;
	case TIF_VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK: return TinyImageFormat_ETC2_R8G8B8A1_UNORM;
	case TIF_VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK: return TinyImageFormat_ETC2_R8G8B8A1_SRGB;
	case TIF_VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK: return TinyImageFormat_ETC2_R8G8B8A8_UNORM;
	case TIF_VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK: return TinyImageFormat_ETC2_R8G8B8A8_SRGB;
	case TIF_VK_FORMAT_EAC_R11_UNORM_BLOCK: return TinyImageFormat_ETC2_EAC_R11_UNORM;
	case TIF_VK_FORMAT_EAC_R11_SNORM_BLOCK: return TinyImageFormat_ETC2_EAC_R11_SNORM;
	case TIF_VK_FORMAT_EAC_R11G11_UNORM_BLOCK: return TinyImageFormat_ETC2_EAC_R11G11_UNORM;
	case TIF_VK_FORMAT_EAC_R11G11_SNORM_BLOCK: return TinyImageFormat_ETC2_EAC_R11G11_SNORM;
	case TIF_VK_FORMAT_ASTC_4x4_UNORM_BLOCK: return TinyImageFormat_ASTC_4x4_UNORM;
	case TIF_VK_FORMAT_ASTC_4x4_SRGB_BLOCK: return TinyImageFormat_ASTC_4x4_SRGB;
	case TIF_VK_FORMAT_ASTC_5x4_UNORM_BLOCK: return TinyImageFormat_ASTC_5x4_UNORM;
	case TIF_VK_FORMAT_ASTC_5x4_SRGB_BLOCK: return TinyImageFormat_ASTC_5x4_SRGB;
	case TIF_VK_FORMAT_ASTC_5x5_UNORM_BLOCK: return TinyImageFormat_ASTC_5x5_UNORM;
	case TIF_VK_FORMAT_ASTC_5x5_SRGB_BLOCK: return TinyImageFormat_ASTC_5x5_SRGB;
	case TIF_VK_FORMAT_ASTC_6x5_UNORM_BLOCK: return TinyImageFormat_ASTC_6x5_UNORM;
	case TIF_VK_FORMAT_ASTC_6x5_SRGB_BLOCK: return TinyImageFormat_ASTC_6x5_SRGB;
	case TIF_VK_FORMAT_ASTC_6x6_UNORM_BLOCK: return TinyImageFormat_ASTC_6x6_UNORM;
	case TIF_VK_FORMAT_ASTC_6x6_SRGB_BLOCK: return TinyImageFormat_ASTC_6x6_SRGB;
	case TIF_VK_FORMAT_ASTC_8x5_UNORM_BLOCK: return TinyImageFormat_ASTC_8x5_UNORM;
	case TIF_VK_FORMAT_ASTC_8x5_SRGB_BLOCK: return TinyImageFormat_ASTC_8x5_SRGB;
	case TIF_VK_FORMAT_ASTC_8x6_UNORM_BLOCK: return TinyImageFormat_ASTC_8x6_UNORM;
	case TIF_VK_FORMAT_ASTC_8x6_SRGB_BLOCK: return TinyImageFormat_ASTC_8x6_SRGB;
	case TIF_VK_FORMAT_ASTC_8x8_UNORM_BLOCK: return TinyImageFormat_ASTC_8x8_UNORM;
	case TIF_VK_FORMAT_ASTC_8x8_SRGB_BLOCK: return TinyImageFormat_ASTC_8x8_SRGB;
	case TIF_VK_FORMAT_ASTC_10x5_UNORM_BLOCK: return TinyImageFormat_ASTC_10x5_UNORM;
	case TIF_VK_FORMAT_ASTC_10x5_SRGB_BLOCK: return TinyImageFormat_ASTC_10x5_SRGB;
	case TIF_VK_FORMAT_ASTC_10x6_UNORM_BLOCK: return TinyImageFormat_ASTC_10x6_UNORM;
	case TIF_VK_FORMAT_ASTC_10x6_SRGB_BLOCK: return TinyImageFormat_ASTC_10x6_SRGB;
	case TIF_VK_FORMAT_ASTC_10x8_UNORM_BLOCK: return TinyImageFormat_ASTC_10x8_UNORM;
	case TIF_VK_FORMAT_ASTC_10x8_SRGB_BLOCK: return TinyImageFormat_ASTC_10x8_SRGB;
	case TIF_VK_FORMAT_ASTC_10x10_UNORM_BLOCK: return TinyImageFormat_ASTC_10x10_UNORM;
	case TIF_VK_FORMAT_ASTC_10x10_SRGB_BLOCK: return TinyImageFormat_ASTC_10x10_SRGB;
	case TIF_VK_FORMAT_ASTC_12x10_UNORM_BLOCK: return TinyImageFormat_ASTC_12x10_UNORM;
	case TIF_VK_FORMAT_ASTC_12x10_SRGB_BLOCK: return TinyImageFormat_ASTC_12x10_SRGB;
	case TIF_VK_FORMAT_ASTC_12x12_UNORM_BLOCK: return TinyImageFormat_ASTC_12x12_UNORM;
	case TIF_VK_FORMAT_ASTC_12x12_SRGB_BLOCK: return TinyImageFormat_ASTC_12x12_SRGB;

	case TIF_VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG: return TinyImageFormat_PVRTC1_2BPP_UNORM;
	case TIF_VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG: return TinyImageFormat_PVRTC1_4BPP_UNORM;
	case TIF_VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG: return TinyImageFormat_PVRTC1_2BPP_SRGB;
	case TIF_VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG: return TinyImageFormat_PVRTC1_4BPP_SRGB;

	case TIF_VK_FORMAT_A8B8G8R8_UNORM_PACK32:
	case TIF_VK_FORMAT_R8_USCALED:
	case TIF_VK_FORMAT_R8_SSCALED:
	case TIF_VK_FORMAT_R8G8_USCALED:
	case TIF_VK_FORMAT_R8G8_SSCALED:
	case TIF_VK_FORMAT_R8G8B8_USCALED:
	case TIF_VK_FORMAT_R8G8B8_SSCALED:
	case TIF_VK_FORMAT_B8G8R8_USCALED:
	case TIF_VK_FORMAT_B8G8R8_SSCALED:
	case TIF_VK_FORMAT_R8G8B8A8_USCALED:
	case TIF_VK_FORMAT_R8G8B8A8_SSCALED:
	case TIF_VK_FORMAT_B8G8R8A8_USCALED:
	case TIF_VK_FORMAT_B8G8R8A8_SSCALED:
	case TIF_VK_FORMAT_A8B8G8R8_SNORM_PACK32:
	case TIF_VK_FORMAT_A8B8G8R8_USCALED_PACK32:
	case TIF_VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
	case TIF_VK_FORMAT_A8B8G8R8_UINT_PACK32:
	case TIF_VK_FORMAT_A8B8G8R8_SINT_PACK32:
	case TIF_VK_FORMAT_A8B8G8R8_SRGB_PACK32:
	case TIF_VK_FORMAT_A2R10G10B10_SNORM_PACK32:
	case TIF_VK_FORMAT_A2R10G10B10_USCALED_PACK32:
	case TIF_VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
	case TIF_VK_FORMAT_A2R10G10B10_SINT_PACK32:
	case TIF_VK_FORMAT_A2B10G10R10_SNORM_PACK32:
	case TIF_VK_FORMAT_A2B10G10R10_USCALED_PACK32:
	case TIF_VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
	case TIF_VK_FORMAT_A2B10G10R10_SINT_PACK32:
	case TIF_VK_FORMAT_R16_USCALED:
	case TIF_VK_FORMAT_R16_SSCALED:
	case TIF_VK_FORMAT_R16G16_USCALED:
	case TIF_VK_FORMAT_R16G16_SSCALED:
	case TIF_VK_FORMAT_R16G16B16_USCALED:
	case TIF_VK_FORMAT_R16G16B16_SSCALED:
	case TIF_VK_FORMAT_R16G16B16A16_USCALED:
	case TIF_VK_FORMAT_R16G16B16A16_SSCALED:
	case TIF_VK_FORMAT_G8B8G8R8_422_UNORM:
	case TIF_VK_FORMAT_B8G8R8G8_422_UNORM:
	case TIF_VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
	case TIF_VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
	case TIF_VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
	case TIF_VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
	case TIF_VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
	case TIF_VK_FORMAT_R10X6_UNORM_PACK16:
	case TIF_VK_FORMAT_R10X6G10X6_UNORM_2PACK16:
	case TIF_VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16:
	case TIF_VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16:
	case TIF_VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16:
	case TIF_VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
	case TIF_VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
	case TIF_VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
	case TIF_VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
	case TIF_VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
	case TIF_VK_FORMAT_R12X4_UNORM_PACK16:
	case TIF_VK_FORMAT_R12X4G12X4_UNORM_2PACK16:
	case TIF_VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16:
	case TIF_VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16:
	case TIF_VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16:
	case TIF_VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
	case TIF_VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
	case TIF_VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
	case TIF_VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
	case TIF_VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
	case TIF_VK_FORMAT_G16B16G16R16_422_UNORM:
	case TIF_VK_FORMAT_B16G16R16G16_422_UNORM:
	case TIF_VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
	case TIF_VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
	case TIF_VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
	case TIF_VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
	case TIF_VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
	case TIF_VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
	case TIF_VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
	case TIF_VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
	case TIF_VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
		return TinyImageFormat_UNDEFINED;
	}
	return TinyImageFormat_UNDEFINED;
}

inline TinyImageFormat_VkFormat TinyImageFormat_ToVkFormat(TinyImageFormat fmt) {
	switch (fmt) {

	case TinyImageFormat_UNDEFINED: return TIF_VK_FORMAT_UNDEFINED;
	case TinyImageFormat_R4G4_UNORM: return TIF_VK_FORMAT_R4G4_UNORM_PACK8;
	case TinyImageFormat_R4G4B4A4_UNORM: return TIF_VK_FORMAT_R4G4B4A4_UNORM_PACK16;
	case TinyImageFormat_B4G4R4A4_UNORM: return TIF_VK_FORMAT_B4G4R4A4_UNORM_PACK16;
	case TinyImageFormat_R5G6B5_UNORM: return TIF_VK_FORMAT_R5G6B5_UNORM_PACK16;
	case TinyImageFormat_B5G6R5_UNORM: return TIF_VK_FORMAT_B5G6R5_UNORM_PACK16;
	case TinyImageFormat_R5G5B5A1_UNORM: return TIF_VK_FORMAT_R5G5B5A1_UNORM_PACK16;
	case TinyImageFormat_B5G5R5A1_UNORM: return TIF_VK_FORMAT_B5G5R5A1_UNORM_PACK16;
	case TinyImageFormat_A1R5G5B5_UNORM: return TIF_VK_FORMAT_A1R5G5B5_UNORM_PACK16;
	case TinyImageFormat_R8_UNORM: return TIF_VK_FORMAT_R8_UNORM;
	case TinyImageFormat_R8_SNORM: return TIF_VK_FORMAT_R8_SNORM;
	case TinyImageFormat_R8_UINT: return TIF_VK_FORMAT_R8_UINT;
	case TinyImageFormat_R8_SINT: return TIF_VK_FORMAT_R8_SINT;
	case TinyImageFormat_R8_SRGB: return TIF_VK_FORMAT_R8_SRGB;
	case TinyImageFormat_R8G8_UNORM: return TIF_VK_FORMAT_R8G8_UNORM;
	case TinyImageFormat_R8G8_SNORM: return TIF_VK_FORMAT_R8G8_SNORM;
	case TinyImageFormat_R8G8_UINT: return TIF_VK_FORMAT_R8G8_UINT;
	case TinyImageFormat_R8G8_SINT: return TIF_VK_FORMAT_R8G8_SINT;
	case TinyImageFormat_R8G8_SRGB: return TIF_VK_FORMAT_R8G8_SRGB;
	case TinyImageFormat_R8G8B8_UNORM: return TIF_VK_FORMAT_R8G8B8_UNORM;
	case TinyImageFormat_R8G8B8_SNORM: return TIF_VK_FORMAT_R8G8B8_SNORM;
	case TinyImageFormat_R8G8B8_UINT: return TIF_VK_FORMAT_R8G8B8_UINT;
	case TinyImageFormat_R8G8B8_SINT: return TIF_VK_FORMAT_R8G8B8_SINT;
	case TinyImageFormat_R8G8B8_SRGB: return TIF_VK_FORMAT_R8G8B8_SRGB;
	case TinyImageFormat_B8G8R8_UNORM: return TIF_VK_FORMAT_B8G8R8_UNORM;
	case TinyImageFormat_B8G8R8_SNORM: return TIF_VK_FORMAT_B8G8R8_SNORM;
	case TinyImageFormat_B8G8R8_UINT: return TIF_VK_FORMAT_B8G8R8_UINT;
	case TinyImageFormat_B8G8R8_SINT: return TIF_VK_FORMAT_B8G8R8_SINT;
	case TinyImageFormat_B8G8R8_SRGB: return TIF_VK_FORMAT_B8G8R8_SRGB;
	case TinyImageFormat_R8G8B8A8_UNORM: return TIF_VK_FORMAT_R8G8B8A8_UNORM;
	case TinyImageFormat_R8G8B8A8_SNORM: return TIF_VK_FORMAT_R8G8B8A8_SNORM;
	case TinyImageFormat_R8G8B8A8_UINT: return TIF_VK_FORMAT_R8G8B8A8_UINT;
	case TinyImageFormat_R8G8B8A8_SINT: return TIF_VK_FORMAT_R8G8B8A8_SINT;
	case TinyImageFormat_R8G8B8A8_SRGB: return TIF_VK_FORMAT_R8G8B8A8_SRGB;
	case TinyImageFormat_B8G8R8A8_UNORM: return TIF_VK_FORMAT_B8G8R8A8_UNORM;
	case TinyImageFormat_B8G8R8A8_SNORM: return TIF_VK_FORMAT_B8G8R8A8_SNORM;
	case TinyImageFormat_B8G8R8A8_UINT: return TIF_VK_FORMAT_B8G8R8A8_UINT;
	case TinyImageFormat_B8G8R8A8_SINT: return TIF_VK_FORMAT_B8G8R8A8_SINT;
	case TinyImageFormat_B8G8R8A8_SRGB: return TIF_VK_FORMAT_B8G8R8A8_SRGB;
	case TinyImageFormat_A2R10G10B10_UNORM: return TIF_VK_FORMAT_A2R10G10B10_UNORM_PACK32;
	case TinyImageFormat_A2R10G10B10_UINT: return TIF_VK_FORMAT_A2R10G10B10_UINT_PACK32;
	case TinyImageFormat_A2B10G10R10_UNORM: return TIF_VK_FORMAT_A2B10G10R10_UNORM_PACK32;
	case TinyImageFormat_A2B10G10R10_UINT: return TIF_VK_FORMAT_A2B10G10R10_UINT_PACK32;
	case TinyImageFormat_R16_UNORM: return TIF_VK_FORMAT_R16_UNORM;
	case TinyImageFormat_R16_SNORM: return TIF_VK_FORMAT_R16_SNORM;
	case TinyImageFormat_R16_UINT: return TIF_VK_FORMAT_R16_UINT;
	case TinyImageFormat_R16_SINT: return TIF_VK_FORMAT_R16_SINT;
	case TinyImageFormat_R16_SFLOAT: return TIF_VK_FORMAT_R16_SFLOAT;
	case TinyImageFormat_R16G16_UNORM: return TIF_VK_FORMAT_R16G16_UNORM;
	case TinyImageFormat_R16G16_SNORM: return TIF_VK_FORMAT_R16G16_SNORM;
	case TinyImageFormat_R16G16_UINT: return TIF_VK_FORMAT_R16G16_UINT;
	case TinyImageFormat_R16G16_SINT: return TIF_VK_FORMAT_R16G16_SINT;
	case TinyImageFormat_R16G16_SFLOAT: return TIF_VK_FORMAT_R16G16_SFLOAT;
	case TinyImageFormat_R16G16B16_UNORM: return TIF_VK_FORMAT_R16G16B16_UNORM;
	case TinyImageFormat_R16G16B16_SNORM: return TIF_VK_FORMAT_R16G16B16_SNORM;
	case TinyImageFormat_R16G16B16_UINT: return TIF_VK_FORMAT_R16G16B16_UINT;
	case TinyImageFormat_R16G16B16_SINT: return TIF_VK_FORMAT_R16G16B16_SINT;
	case TinyImageFormat_R16G16B16_SFLOAT: return TIF_VK_FORMAT_R16G16B16_SFLOAT;
	case TinyImageFormat_R16G16B16A16_UNORM: return TIF_VK_FORMAT_R16G16B16A16_UNORM;
	case TinyImageFormat_R16G16B16A16_SNORM: return TIF_VK_FORMAT_R16G16B16A16_SNORM;
	case TinyImageFormat_R16G16B16A16_UINT: return TIF_VK_FORMAT_R16G16B16A16_UINT;
	case TinyImageFormat_R16G16B16A16_SINT: return TIF_VK_FORMAT_R16G16B16A16_SINT;
	case TinyImageFormat_R16G16B16A16_SFLOAT: return TIF_VK_FORMAT_R16G16B16A16_SFLOAT;
	case TinyImageFormat_R32_UINT: return TIF_VK_FORMAT_R32_UINT;
	case TinyImageFormat_R32_SINT: return TIF_VK_FORMAT_R32_SINT;
	case TinyImageFormat_R32_SFLOAT: return TIF_VK_FORMAT_R32_SFLOAT;
	case TinyImageFormat_R32G32_UINT: return TIF_VK_FORMAT_R32G32_UINT;
	case TinyImageFormat_R32G32_SINT: return TIF_VK_FORMAT_R32G32_SINT;
	case TinyImageFormat_R32G32_SFLOAT: return TIF_VK_FORMAT_R32G32_SFLOAT;
	case TinyImageFormat_R32G32B32_UINT: return TIF_VK_FORMAT_R32G32B32_UINT;
	case TinyImageFormat_R32G32B32_SINT: return TIF_VK_FORMAT_R32G32B32_SINT;
	case TinyImageFormat_R32G32B32_SFLOAT: return TIF_VK_FORMAT_R32G32B32_SFLOAT;
	case TinyImageFormat_R32G32B32A32_UINT: return TIF_VK_FORMAT_R32G32B32A32_UINT;
	case TinyImageFormat_R32G32B32A32_SINT: return TIF_VK_FORMAT_R32G32B32A32_SINT;
	case TinyImageFormat_R32G32B32A32_SFLOAT: return TIF_VK_FORMAT_R32G32B32A32_SFLOAT;
	case TinyImageFormat_R64_UINT: return TIF_VK_FORMAT_R64_UINT;
	case TinyImageFormat_R64_SINT: return TIF_VK_FORMAT_R64_SINT;
	case TinyImageFormat_R64_SFLOAT: return TIF_VK_FORMAT_R64_SFLOAT;
	case TinyImageFormat_R64G64_UINT: return TIF_VK_FORMAT_R64G64_UINT;
	case TinyImageFormat_R64G64_SINT: return TIF_VK_FORMAT_R64G64_SINT;
	case TinyImageFormat_R64G64_SFLOAT: return TIF_VK_FORMAT_R64G64_SFLOAT;
	case TinyImageFormat_R64G64B64_UINT: return TIF_VK_FORMAT_R64G64B64_UINT;
	case TinyImageFormat_R64G64B64_SINT: return TIF_VK_FORMAT_R64G64B64_SINT;
	case TinyImageFormat_R64G64B64_SFLOAT: return TIF_VK_FORMAT_R64G64B64_SFLOAT;
	case TinyImageFormat_R64G64B64A64_UINT: return TIF_VK_FORMAT_R64G64B64A64_UINT;
	case TinyImageFormat_R64G64B64A64_SINT: return TIF_VK_FORMAT_R64G64B64A64_SINT;
	case TinyImageFormat_R64G64B64A64_SFLOAT: return TIF_VK_FORMAT_R64G64B64A64_SFLOAT;
	case TinyImageFormat_B10G11R11_UFLOAT: return TIF_VK_FORMAT_B10G11R11_UFLOAT_PACK32;
	case TinyImageFormat_E5B9G9R9_UFLOAT: return TIF_VK_FORMAT_E5B9G9R9_UFLOAT_PACK32;
	case TinyImageFormat_D16_UNORM: return TIF_VK_FORMAT_D16_UNORM;
	case TinyImageFormat_X8_D24_UNORM: return TIF_VK_FORMAT_X8_D24_UNORM_PACK32;
	case TinyImageFormat_D32_SFLOAT: return TIF_VK_FORMAT_D32_SFLOAT;
	case TinyImageFormat_S8_UINT: return TIF_VK_FORMAT_S8_UINT;
	case TinyImageFormat_D16_UNORM_S8_UINT: return TIF_VK_FORMAT_D16_UNORM_S8_UINT;
	case TinyImageFormat_D24_UNORM_S8_UINT: return TIF_VK_FORMAT_D24_UNORM_S8_UINT;
	case TinyImageFormat_D32_SFLOAT_S8_UINT: return TIF_VK_FORMAT_D32_SFLOAT_S8_UINT;
	case TinyImageFormat_DXBC1_RGB_UNORM: return TIF_VK_FORMAT_BC1_RGB_UNORM_BLOCK;
	case TinyImageFormat_DXBC1_RGB_SRGB: return TIF_VK_FORMAT_BC1_RGB_SRGB_BLOCK;
	case TinyImageFormat_DXBC1_RGBA_UNORM: return TIF_VK_FORMAT_BC1_RGBA_UNORM_BLOCK;
	case TinyImageFormat_DXBC1_RGBA_SRGB: return TIF_VK_FORMAT_BC1_RGBA_SRGB_BLOCK;
	case TinyImageFormat_DXBC2_UNORM: return TIF_VK_FORMAT_BC2_UNORM_BLOCK;
	case TinyImageFormat_DXBC2_SRGB: return TIF_VK_FORMAT_BC2_SRGB_BLOCK;
	case TinyImageFormat_DXBC3_UNORM: return TIF_VK_FORMAT_BC3_UNORM_BLOCK;
	case TinyImageFormat_DXBC3_SRGB: return TIF_VK_FORMAT_BC3_SRGB_BLOCK;
	case TinyImageFormat_DXBC4_UNORM: return TIF_VK_FORMAT_BC4_UNORM_BLOCK;
	case TinyImageFormat_DXBC4_SNORM: return TIF_VK_FORMAT_BC4_SNORM_BLOCK;
	case TinyImageFormat_DXBC5_UNORM: return TIF_VK_FORMAT_BC5_UNORM_BLOCK;
	case TinyImageFormat_DXBC5_SNORM: return TIF_VK_FORMAT_BC5_SNORM_BLOCK;
	case TinyImageFormat_DXBC6H_UFLOAT: return TIF_VK_FORMAT_BC6H_UFLOAT_BLOCK;
	case TinyImageFormat_DXBC6H_SFLOAT: return TIF_VK_FORMAT_BC6H_SFLOAT_BLOCK;
	case TinyImageFormat_DXBC7_UNORM: return TIF_VK_FORMAT_BC7_UNORM_BLOCK;
	case TinyImageFormat_DXBC7_SRGB: return TIF_VK_FORMAT_BC7_SRGB_BLOCK;
	case TinyImageFormat_PVRTC1_2BPP_UNORM: return TIF_VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG;
	case TinyImageFormat_PVRTC1_4BPP_UNORM: return TIF_VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG;
	case TinyImageFormat_PVRTC1_2BPP_SRGB: return TIF_VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG;
	case TinyImageFormat_PVRTC1_4BPP_SRGB: return TIF_VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG;
	case TinyImageFormat_ETC2_R8G8B8_UNORM: return TIF_VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM: return TIF_VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM: return TIF_VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8_SRGB: return TIF_VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB: return TIF_VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK;
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB: return TIF_VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK;
	case TinyImageFormat_ETC2_EAC_R11_UNORM: return TIF_VK_FORMAT_EAC_R11_UNORM_BLOCK;
	case TinyImageFormat_ETC2_EAC_R11G11_UNORM: return TIF_VK_FORMAT_EAC_R11G11_UNORM_BLOCK;
	case TinyImageFormat_ETC2_EAC_R11_SNORM: return TIF_VK_FORMAT_EAC_R11_SNORM_BLOCK;
	case TinyImageFormat_ETC2_EAC_R11G11_SNORM: return TIF_VK_FORMAT_EAC_R11G11_SNORM_BLOCK;
	case TinyImageFormat_ASTC_4x4_UNORM: return TIF_VK_FORMAT_ASTC_4x4_UNORM_BLOCK;
	case TinyImageFormat_ASTC_4x4_SRGB: return TIF_VK_FORMAT_ASTC_4x4_SRGB_BLOCK;
	case TinyImageFormat_ASTC_5x4_UNORM: return TIF_VK_FORMAT_ASTC_5x4_UNORM_BLOCK;
	case TinyImageFormat_ASTC_5x4_SRGB: return TIF_VK_FORMAT_ASTC_5x4_SRGB_BLOCK;
	case TinyImageFormat_ASTC_5x5_UNORM: return TIF_VK_FORMAT_ASTC_5x5_UNORM_BLOCK;
	case TinyImageFormat_ASTC_5x5_SRGB: return TIF_VK_FORMAT_ASTC_5x5_SRGB_BLOCK;
	case TinyImageFormat_ASTC_6x5_UNORM: return TIF_VK_FORMAT_ASTC_6x5_UNORM_BLOCK;
	case TinyImageFormat_ASTC_6x5_SRGB: return TIF_VK_FORMAT_ASTC_6x5_SRGB_BLOCK;
	case TinyImageFormat_ASTC_6x6_UNORM: return TIF_VK_FORMAT_ASTC_6x6_UNORM_BLOCK;
	case TinyImageFormat_ASTC_6x6_SRGB: return TIF_VK_FORMAT_ASTC_6x6_SRGB_BLOCK;
	case TinyImageFormat_ASTC_8x5_UNORM: return TIF_VK_FORMAT_ASTC_8x5_UNORM_BLOCK;
	case TinyImageFormat_ASTC_8x5_SRGB: return TIF_VK_FORMAT_ASTC_8x5_SRGB_BLOCK;
	case TinyImageFormat_ASTC_8x6_UNORM: return TIF_VK_FORMAT_ASTC_8x6_UNORM_BLOCK;
	case TinyImageFormat_ASTC_8x6_SRGB: return TIF_VK_FORMAT_ASTC_8x6_SRGB_BLOCK;
	case TinyImageFormat_ASTC_8x8_UNORM: return TIF_VK_FORMAT_ASTC_8x8_UNORM_BLOCK;
	case TinyImageFormat_ASTC_8x8_SRGB: return TIF_VK_FORMAT_ASTC_8x8_SRGB_BLOCK;
	case TinyImageFormat_ASTC_10x5_UNORM: return TIF_VK_FORMAT_ASTC_10x5_UNORM_BLOCK;
	case TinyImageFormat_ASTC_10x5_SRGB: return TIF_VK_FORMAT_ASTC_10x5_SRGB_BLOCK;
	case TinyImageFormat_ASTC_10x6_UNORM: return TIF_VK_FORMAT_ASTC_10x6_UNORM_BLOCK;
	case TinyImageFormat_ASTC_10x6_SRGB: return TIF_VK_FORMAT_ASTC_10x6_SRGB_BLOCK;
	case TinyImageFormat_ASTC_10x8_UNORM: return TIF_VK_FORMAT_ASTC_10x8_UNORM_BLOCK;
	case TinyImageFormat_ASTC_10x8_SRGB: return TIF_VK_FORMAT_ASTC_10x8_SRGB_BLOCK;
	case TinyImageFormat_ASTC_10x10_UNORM: return TIF_VK_FORMAT_ASTC_10x10_UNORM_BLOCK;
	case TinyImageFormat_ASTC_10x10_SRGB: return TIF_VK_FORMAT_ASTC_10x10_SRGB_BLOCK;
	case TinyImageFormat_ASTC_12x10_UNORM: return TIF_VK_FORMAT_ASTC_12x10_UNORM_BLOCK;
	case TinyImageFormat_ASTC_12x10_SRGB: return TIF_VK_FORMAT_ASTC_12x10_SRGB_BLOCK;
	case TinyImageFormat_ASTC_12x12_UNORM: return TIF_VK_FORMAT_ASTC_12x12_UNORM_BLOCK;
	case TinyImageFormat_ASTC_12x12_SRGB: return TIF_VK_FORMAT_ASTC_12x12_SRGB_BLOCK;
	case TinyImageFormat_PVRTC2_2BPP_UNORM: return TIF_VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG;
	case TinyImageFormat_PVRTC2_4BPP_UNORM: return TIF_VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG;
	case TinyImageFormat_PVRTC2_2BPP_SRGB: return TIF_VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG;
	case TinyImageFormat_PVRTC2_4BPP_SRGB: return TIF_VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG;

	default: return TIF_VK_FORMAT_UNDEFINED;
	}
	return TIF_VK_FORMAT_UNDEFINED;
}