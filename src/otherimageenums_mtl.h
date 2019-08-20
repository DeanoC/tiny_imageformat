#ifndef TINYIMAGEFORMAT_MTLPIXEL_FORMAT
#define TINYIMAGEFORMAT_MTLPIXEL_FORMAT

typedef enum TinyImageFormat_MTLPixelFormat {
	TIF_MTLPixelFormatInvalid = 0,
	TIF_MTLPixelFormatA8Unorm = 1,
	TIF_MTLPixelFormatR8Unorm = 10,
	TIF_MTLPixelFormatR8Unorm_sRGB = 11,
	TIF_MTLPixelFormatR8Snorm = 12,
	TIF_MTLPixelFormatR8Uint = 13,
	TIF_MTLPixelFormatR8Sint = 14,
	TIF_MTLPixelFormatR16Unorm = 20,
	TIF_MTLPixelFormatR16Snorm = 22,
	TIF_MTLPixelFormatR16Uint = 23,
	TIF_MTLPixelFormatR16Sint = 24,
	TIF_MTLPixelFormatR16Float = 25,
	TIF_MTLPixelFormatRG8Unorm = 30,
	TIF_MTLPixelFormatRG8Unorm_sRGB = 31,
	TIF_MTLPixelFormatRG8Snorm = 32,
	TIF_MTLPixelFormatRG8Uint = 33,
	TIF_MTLPixelFormatRG8Sint = 34,
	TIF_MTLPixelFormatB5G6R5Unorm = 40,
	TIF_MTLPixelFormatA1BGR5Unorm = 41,
	TIF_MTLPixelFormatABGR4Unorm = 42,
	TIF_MTLPixelFormatBGR5A1Unorm = 43,
	TIF_MTLPixelFormatR32Uint = 53,
	TIF_MTLPixelFormatR32Sint = 54,
	TIF_MTLPixelFormatR32Float = 55,
	TIF_MTLPixelFormatRG16Unorm = 60,
	TIF_MTLPixelFormatRG16Snorm = 62,
	TIF_MTLPixelFormatRG16Uint = 63,
	TIF_MTLPixelFormatRG16Sint = 64,
	TIF_MTLPixelFormatRG16Float = 65,
	TIF_MTLPixelFormatRGBA8Unorm = 70,
	TIF_MTLPixelFormatRGBA8Unorm_sRGB = 71,
	TIF_MTLPixelFormatRGBA8Snorm = 72,
	TIF_MTLPixelFormatRGBA8Uint = 73,
	TIF_MTLPixelFormatRGBA8Sint = 74,
	TIF_MTLPixelFormatBGRA8Unorm = 80,
	TIF_MTLPixelFormatBGRA8Unorm_sRGB = 81,
	TIF_MTLPixelFormatRGB10A2Unorm = 90,
	TIF_MTLPixelFormatRGB10A2Uint = 91,
	TIF_MTLPixelFormatRG11B10Float = 92,
	TIF_MTLPixelFormatRGB9E5Float = 93,
	TIF_MTLPixelFormatBGR10A2Unorm = 94,
	TIF_MTLPixelFormatBGR10_XR = 554,
	TIF_MTLPixelFormatBGR10_XR_sRGB = 555,
	TIF_MTLPixelFormatRG32Uint = 103,
	TIF_MTLPixelFormatRG32Sint = 104,
	TIF_MTLPixelFormatRG32Float = 105,
	TIF_MTLPixelFormatRGBA16Unorm = 110,
	TIF_MTLPixelFormatRGBA16Snorm = 112,
	TIF_MTLPixelFormatRGBA16Uint = 113,
	TIF_MTLPixelFormatRGBA16Sint = 114,
	TIF_MTLPixelFormatRGBA16Float = 115,
	TIF_MTLPixelFormatBGRA10_XR = 552,
	TIF_MTLPixelFormatBGRA10_XR_sRGB = 553,
	TIF_MTLPixelFormatRGBA32Uint = 123,
	TIF_MTLPixelFormatRGBA32Sint = 124,
	TIF_MTLPixelFormatRGBA32Float = 125,
	TIF_MTLPixelFormatBC1_RGBA = 130,
	TIF_MTLPixelFormatBC1_RGBA_sRGB = 131,
	TIF_MTLPixelFormatBC2_RGBA = 132,
	TIF_MTLPixelFormatBC2_RGBA_sRGB = 133,
	TIF_MTLPixelFormatBC3_RGBA = 134,
	TIF_MTLPixelFormatBC3_RGBA_sRGB = 135,
	TIF_MTLPixelFormatBC4_RUnorm = 140,
	TIF_MTLPixelFormatBC4_RSnorm = 141,
	TIF_MTLPixelFormatBC5_RGUnorm = 142,
	TIF_MTLPixelFormatBC5_RGSnorm = 143,
	TIF_MTLPixelFormatBC6H_RGBFloat = 150,
	TIF_MTLPixelFormatBC6H_RGBUfloat = 151,
	TIF_MTLPixelFormatBC7_RGBAUnorm = 152,
	TIF_MTLPixelFormatBC7_RGBAUnorm_sRGB = 153,
	TIF_MTLPixelFormatPVRTC_RGB_2BPP = 160,
	TIF_MTLPixelFormatPVRTC_RGB_2BPP_sRGB = 161,
	TIF_MTLPixelFormatPVRTC_RGB_4BPP = 162,
	TIF_MTLPixelFormatPVRTC_RGB_4BPP_sRGB = 163,
	TIF_MTLPixelFormatPVRTC_RGBA_2BPP = 164,
	TIF_MTLPixelFormatPVRTC_RGBA_2BPP_sRGB = 165,
	TIF_MTLPixelFormatPVRTC_RGBA_4BPP = 166,
	TIF_MTLPixelFormatPVRTC_RGBA_4BPP_sRGB = 167,
	TIF_MTLPixelFormatEAC_R11Unorm = 170,
	TIF_MTLPixelFormatEAC_R11Snorm = 172,
	TIF_MTLPixelFormatEAC_RG11Unorm = 174,
	TIF_MTLPixelFormatEAC_RG11Snorm = 176,
	TIF_MTLPixelFormatEAC_RGBA8 = 178,
	TIF_MTLPixelFormatEAC_RGBA8_sRGB = 179,
	TIF_MTLPixelFormatETC2_RGB8 = 180,
	TIF_MTLPixelFormatETC2_RGB8_sRGB = 181,
	TIF_MTLPixelFormatETC2_RGB8A1 = 182,
	TIF_MTLPixelFormatETC2_RGB8A1_sRGB = 183,
	TIF_MTLPixelFormatASTC_4x4_sRGB = 186,
	TIF_MTLPixelFormatASTC_5x4_sRGB = 187,
	TIF_MTLPixelFormatASTC_5x5_sRGB = 188,
	TIF_MTLPixelFormatASTC_6x5_sRGB = 189,
	TIF_MTLPixelFormatASTC_6x6_sRGB = 190,
	TIF_MTLPixelFormatASTC_8x5_sRGB = 192,
	TIF_MTLPixelFormatASTC_8x6_sRGB = 193,
	TIF_MTLPixelFormatASTC_8x8_sRGB = 194,
	TIF_MTLPixelFormatASTC_10x5_sRGB = 195,
	TIF_MTLPixelFormatASTC_10x6_sRGB = 196,
	TIF_MTLPixelFormatASTC_10x8_sRGB = 197,
	TIF_MTLPixelFormatASTC_10x10_sRGB = 198,
	TIF_MTLPixelFormatASTC_12x10_sRGB = 199,
	TIF_MTLPixelFormatASTC_12x12_sRGB = 200,
	TIF_MTLPixelFormatASTC_4x4_LDR = 204,
	TIF_MTLPixelFormatASTC_5x4_LDR = 205,
	TIF_MTLPixelFormatASTC_5x5_LDR = 206,
	TIF_MTLPixelFormatASTC_6x5_LDR = 207,
	TIF_MTLPixelFormatASTC_6x6_LDR = 208,
	TIF_MTLPixelFormatASTC_8x5_LDR = 210,
	TIF_MTLPixelFormatASTC_8x6_LDR = 211,
	TIF_MTLPixelFormatASTC_8x8_LDR = 212,
	TIF_MTLPixelFormatASTC_10x5_LDR = 213,
	TIF_MTLPixelFormatASTC_10x6_LDR = 214,
	TIF_MTLPixelFormatASTC_10x8_LDR = 215,
	TIF_MTLPixelFormatASTC_10x10_LDR = 216,
	TIF_MTLPixelFormatASTC_12x10_LDR = 217,
	TIF_MTLPixelFormatASTC_12x12_LDR = 218,
	TIF_MTLPixelFormatGBGR422 = 240,
	TIF_MTLPixelFormatBGRG422 = 241,
	TIF_MTLPixelFormatDepth16Unorm = 250,
	TIF_MTLPixelFormatDepth32Float = 252,
	TIF_MTLPixelFormatStencil8 = 253,
	TIF_MTLPixelFormatDepth24Unorm_Stencil8 = 255,
	TIF_MTLPixelFormatDepth32Float_Stencil8 = 260,
	TIF_MTLPixelFormatX32_Stencil8 = 261,
	TIF_MTLPixelFormatX24_Stencil8 = 262,
} TinyImageFormat_MTLPixelFormat;
#endif

inline TinyImageFormat_MTLPixelFormat TinyImageFormat_ToMTLPixelFormat(TinyImageFormat fmt) {
	switch (fmt) {
	case TinyImageFormat_A8_UNORM: 									return TIF_MTLPixelFormatA8Unorm;
	case TinyImageFormat_R8_UNORM: 		return TIF_MTLPixelFormatR8Unorm;
	case TinyImageFormat_R8_SNORM: 		return TIF_MTLPixelFormatR8Snorm;
	case TinyImageFormat_R8_UINT: 		return TIF_MTLPixelFormatR8Uint;
	case TinyImageFormat_R8_SINT: 		return TIF_MTLPixelFormatR8Sint;
	case TinyImageFormat_R8_SRGB: 		return TIF_MTLPixelFormatR8Unorm_sRGB;
	case TinyImageFormat_UNDEFINED: return TIF_MTLPixelFormatInvalid;
	case TinyImageFormat_R4G4B4A4_UNORM: return TIF_MTLPixelFormatABGR4Unorm;
	case TinyImageFormat_R5G6B5_UNORM: return TIF_MTLPixelFormatB5G6R5Unorm;;
	case TinyImageFormat_R5G5B5A1_UNORM: return TIF_MTLPixelFormatA1BGR5Unorm;
	case TinyImageFormat_R8G8_UNORM:		return TIF_MTLPixelFormatRG8Unorm;
	case TinyImageFormat_R8G8_SNORM:		return TIF_MTLPixelFormatRG8Snorm;
	case TinyImageFormat_R8G8_UINT:			return TIF_MTLPixelFormatRG8Uint;
	case TinyImageFormat_R8G8_SINT:			return TIF_MTLPixelFormatRG8Sint;
	case TinyImageFormat_R8G8_SRGB:			return TIF_MTLPixelFormatRG8Unorm_sRGB;
	case TinyImageFormat_R8G8B8A8_UNORM:		return TIF_MTLPixelFormatRGBA8Unorm;
	case TinyImageFormat_R8G8B8A8_SNORM:		return TIF_MTLPixelFormatRGBA8Snorm;
	case TinyImageFormat_R8G8B8A8_UINT:			return TIF_MTLPixelFormatRGBA8Uint;
	case TinyImageFormat_R8G8B8A8_SINT:			return TIF_MTLPixelFormatRGBA8Sint;
	case TinyImageFormat_R8G8B8A8_SRGB:			return TIF_MTLPixelFormatRGBA8Unorm_sRGB;
	case TinyImageFormat_B8G8R8A8_UNORM: 							return TIF_MTLPixelFormatBGRA8Unorm;
	case TinyImageFormat_B8G8R8A8_SRGB:								return TIF_MTLPixelFormatBGRA8Unorm_sRGB;
	case TinyImageFormat_A2R10G10B10_UNORM:		return TIF_MTLPixelFormatBGR10A2Unorm;
	case TinyImageFormat_A2B10G10R10_UNORM:		return TIF_MTLPixelFormatRGB10A2Unorm;
	case TinyImageFormat_A2B10G10R10_UINT:			return TIF_MTLPixelFormatRGB10A2Uint;
	case TinyImageFormat_R16_UNORM:			return TIF_MTLPixelFormatR16Unorm;
	case TinyImageFormat_R16_SNORM:			return TIF_MTLPixelFormatR16Snorm;
	case TinyImageFormat_R16_UINT:			return TIF_MTLPixelFormatR16Uint;
	case TinyImageFormat_R16_SINT:			return TIF_MTLPixelFormatR16Sint;
	case TinyImageFormat_R16_SFLOAT:		return TIF_MTLPixelFormatR16Float;
	case TinyImageFormat_R16G16_UNORM:	return TIF_MTLPixelFormatRG16Unorm;
	case TinyImageFormat_R16G16_SNORM:	return TIF_MTLPixelFormatRG16Snorm;
	case TinyImageFormat_R16G16_UINT:		return TIF_MTLPixelFormatRG16Uint;
	case TinyImageFormat_R16G16_SINT:		return TIF_MTLPixelFormatRG16Sint;
	case TinyImageFormat_R16G16_SFLOAT:	return TIF_MTLPixelFormatRG16Float;
	case TinyImageFormat_R16G16B16A16_UNORM:	return TIF_MTLPixelFormatRGBA16Unorm;
	case TinyImageFormat_R16G16B16A16_SNORM:	return TIF_MTLPixelFormatRGBA16Snorm;
	case TinyImageFormat_R16G16B16A16_UINT:		return TIF_MTLPixelFormatRGBA16Uint;
	case TinyImageFormat_R16G16B16A16_SINT:		return TIF_MTLPixelFormatRGBA16Sint;
	case TinyImageFormat_R16G16B16A16_SFLOAT:	return TIF_MTLPixelFormatRGBA16Float;
	case TinyImageFormat_R32_UINT:						return TIF_MTLPixelFormatR32Uint;
	case TinyImageFormat_R32_SINT:						return TIF_MTLPixelFormatR32Sint;
	case TinyImageFormat_R32_SFLOAT:					return TIF_MTLPixelFormatR32Float;
	case TinyImageFormat_R32G32_UINT:					return TIF_MTLPixelFormatRG32Uint;
	case TinyImageFormat_R32G32_SINT:					return TIF_MTLPixelFormatRG32Sint;
	case TinyImageFormat_R32G32_SFLOAT:				return TIF_MTLPixelFormatRG32Float;
	case TinyImageFormat_R32G32B32A32_UINT:		return TIF_MTLPixelFormatRGBA32Uint;
	case TinyImageFormat_R32G32B32A32_SINT:		return TIF_MTLPixelFormatRGBA32Sint;
	case TinyImageFormat_R32G32B32A32_SFLOAT:	return TIF_MTLPixelFormatRGBA32Float;
	case TinyImageFormat_B10G11R11_UFLOAT: return TIF_MTLPixelFormatRG11B10Float;
	case TinyImageFormat_E5B9G9R9_UFLOAT:	return TIF_MTLPixelFormatRGB9E5Float;
	case TinyImageFormat_D16_UNORM:								return TIF_MTLPixelFormatDepth16Unorm;
	case TinyImageFormat_X8_D24_UNORM:			return TIF_MTLPixelFormatDepth24Unorm_Stencil8;
	case TinyImageFormat_D32_SFLOAT:							return TIF_MTLPixelFormatDepth32Float;
	case TinyImageFormat_S8_UINT:									return TIF_MTLPixelFormatStencil8;
	case TinyImageFormat_D24_UNORM_S8_UINT:				return TIF_MTLPixelFormatDepth24Unorm_Stencil8;
	case TinyImageFormat_D32_SFLOAT_S8_UINT:			return TIF_MTLPixelFormatDepth32Float_Stencil8;
	case TinyImageFormat_DXBC1_RGB_UNORM:			return TIF_MTLPixelFormatBC1_RGBA;
	case TinyImageFormat_DXBC1_RGB_SRGB:			return TIF_MTLPixelFormatBC1_RGBA_sRGB;
	case TinyImageFormat_DXBC1_RGBA_UNORM:		return TIF_MTLPixelFormatBC1_RGBA;
	case TinyImageFormat_DXBC1_RGBA_SRGB:			return TIF_MTLPixelFormatBC1_RGBA_sRGB;
	case TinyImageFormat_DXBC2_UNORM:					return TIF_MTLPixelFormatBC2_RGBA;
	case TinyImageFormat_DXBC2_SRGB:					return TIF_MTLPixelFormatBC2_RGBA_sRGB;
	case TinyImageFormat_DXBC3_UNORM:					return TIF_MTLPixelFormatBC3_RGBA;
	case TinyImageFormat_DXBC3_SRGB:					return TIF_MTLPixelFormatBC3_RGBA_sRGB;
	case TinyImageFormat_DXBC4_UNORM:					return TIF_MTLPixelFormatBC4_RUnorm;
	case TinyImageFormat_DXBC4_SNORM:					return TIF_MTLPixelFormatBC4_RSnorm;
	case TinyImageFormat_DXBC5_UNORM:					return TIF_MTLPixelFormatBC5_RGUnorm;
	case TinyImageFormat_DXBC5_SNORM:					return TIF_MTLPixelFormatBC5_RGSnorm;
	case TinyImageFormat_DXBC6H_UFLOAT:				return TIF_MTLPixelFormatBC6H_RGBUfloat;
	case TinyImageFormat_DXBC6H_SFLOAT:				return TIF_MTLPixelFormatBC6H_RGBFloat;
	case TinyImageFormat_DXBC7_UNORM:					return TIF_MTLPixelFormatBC7_RGBAUnorm;
	case TinyImageFormat_DXBC7_SRGB:					return TIF_MTLPixelFormatBC7_RGBAUnorm_sRGB;
	case TinyImageFormat_PVRTC1_2BPP_UNORM:		return TIF_MTLPixelFormatPVRTC_RGBA_2BPP;
	case TinyImageFormat_PVRTC1_4BPP_UNORM:		return TIF_MTLPixelFormatPVRTC_RGBA_4BPP;
	case TinyImageFormat_PVRTC1_2BPP_SRGB:		return TIF_MTLPixelFormatPVRTC_RGBA_2BPP_sRGB;
	case TinyImageFormat_PVRTC1_4BPP_SRGB:		return TIF_MTLPixelFormatPVRTC_RGBA_4BPP_sRGB;
	case TinyImageFormat_ETC2_R8G8B8_UNORM:	return TIF_MTLPixelFormatETC2_RGB8;
	case TinyImageFormat_ETC2_R8G8B8A1_UNORM:return TIF_MTLPixelFormatETC2_RGB8A1;
	case TinyImageFormat_ETC2_R8G8B8A8_UNORM: return TIF_MTLPixelFormatEAC_RGBA8;
	case TinyImageFormat_ETC2_R8G8B8_SRGB:		return TIF_MTLPixelFormatETC2_RGB8_sRGB;
	case TinyImageFormat_ETC2_R8G8B8A1_SRGB:	return TIF_MTLPixelFormatETC2_RGB8A1_sRGB;
	case TinyImageFormat_ETC2_R8G8B8A8_SRGB:	return TIF_MTLPixelFormatEAC_RGBA8_sRGB;
	case TinyImageFormat_ETC2_EAC_R11_UNORM:				return TIF_MTLPixelFormatEAC_R11Unorm;
	case TinyImageFormat_ETC2_EAC_R11G11_UNORM:		return TIF_MTLPixelFormatEAC_RG11Unorm;
	case TinyImageFormat_ETC2_EAC_R11_SNORM:				return TIF_MTLPixelFormatEAC_R11Snorm;
	case TinyImageFormat_ETC2_EAC_R11G11_SNORM:		return TIF_MTLPixelFormatEAC_RG11Snorm;
	case TinyImageFormat_ASTC_4x4_UNORM:			return TIF_MTLPixelFormatASTC_4x4_LDR;
	case TinyImageFormat_ASTC_4x4_SRGB:				return TIF_MTLPixelFormatASTC_4x4_sRGB;
	case TinyImageFormat_ASTC_5x4_UNORM:			return TIF_MTLPixelFormatASTC_5x4_LDR;
	case TinyImageFormat_ASTC_5x4_SRGB:				return TIF_MTLPixelFormatASTC_5x4_sRGB;
	case TinyImageFormat_ASTC_5x5_UNORM:			return TIF_MTLPixelFormatASTC_5x5_LDR;
	case TinyImageFormat_ASTC_5x5_SRGB:				return TIF_MTLPixelFormatASTC_5x5_sRGB;
	case TinyImageFormat_ASTC_6x5_UNORM:			return TIF_MTLPixelFormatASTC_6x5_LDR;
	case TinyImageFormat_ASTC_6x5_SRGB:				return TIF_MTLPixelFormatASTC_6x5_sRGB;
	case TinyImageFormat_ASTC_6x6_UNORM:			return TIF_MTLPixelFormatASTC_6x6_LDR;
	case TinyImageFormat_ASTC_6x6_SRGB:				return TIF_MTLPixelFormatASTC_6x6_sRGB;
	case TinyImageFormat_ASTC_8x5_UNORM:			return TIF_MTLPixelFormatASTC_8x5_LDR;
	case TinyImageFormat_ASTC_8x5_SRGB:				return TIF_MTLPixelFormatASTC_8x5_sRGB;
	case TinyImageFormat_ASTC_8x6_UNORM:			return TIF_MTLPixelFormatASTC_8x6_LDR;
	case TinyImageFormat_ASTC_8x6_SRGB:				return TIF_MTLPixelFormatASTC_8x6_sRGB;
	case TinyImageFormat_ASTC_8x8_UNORM:			return TIF_MTLPixelFormatASTC_8x8_LDR;
	case TinyImageFormat_ASTC_8x8_SRGB:				return TIF_MTLPixelFormatASTC_8x8_sRGB;
	case TinyImageFormat_ASTC_10x5_UNORM:			return TIF_MTLPixelFormatASTC_10x5_LDR;
	case TinyImageFormat_ASTC_10x5_SRGB:			return TIF_MTLPixelFormatASTC_10x5_sRGB;
	case TinyImageFormat_ASTC_10x6_UNORM:			return TIF_MTLPixelFormatASTC_10x6_LDR;
	case TinyImageFormat_ASTC_10x6_SRGB:			return TIF_MTLPixelFormatASTC_10x6_sRGB;
	case TinyImageFormat_ASTC_10x8_UNORM:			return TIF_MTLPixelFormatASTC_10x8_LDR;
	case TinyImageFormat_ASTC_10x8_SRGB:			return TIF_MTLPixelFormatASTC_10x8_sRGB;
	case TinyImageFormat_ASTC_10x10_UNORM:		return TIF_MTLPixelFormatASTC_10x10_LDR;
	case TinyImageFormat_ASTC_10x10_SRGB:			return TIF_MTLPixelFormatASTC_10x10_sRGB;
	case TinyImageFormat_ASTC_12x10_UNORM:		return TIF_MTLPixelFormatASTC_12x10_LDR;
	case TinyImageFormat_ASTC_12x10_SRGB:			return TIF_MTLPixelFormatASTC_12x10_sRGB;
	case TinyImageFormat_ASTC_12x12_UNORM:		return TIF_MTLPixelFormatASTC_12x12_LDR;
	case TinyImageFormat_ASTC_12x12_SRGB:			return TIF_MTLPixelFormatASTC_12x12_sRGB;

	default: return TIF_MTLPixelFormatInvalid;
	}

	return TIF_MTLPixelFormatInvalid;
}
inline TinyImageFormat TinyImageFormat_FromMTLPixelFormat(TinyImageFormat_MTLPixelFormat fmt) {
	switch (fmt) {
	case TIF_MTLPixelFormatInvalid: return TinyImageFormat_UNDEFINED;
	case TIF_MTLPixelFormatA8Unorm: return TinyImageFormat_A8_UNORM;
	case TIF_MTLPixelFormatR8Unorm: return TinyImageFormat_R8_UNORM;
	case TIF_MTLPixelFormatR8Unorm_sRGB: return TinyImageFormat_R8_SRGB;
	case TIF_MTLPixelFormatR8Snorm: return TinyImageFormat_R8_SNORM;
	case TIF_MTLPixelFormatR8Uint: return TinyImageFormat_R8_UINT;
	case TIF_MTLPixelFormatR8Sint: return TinyImageFormat_R8_SINT;
	case TIF_MTLPixelFormatR16Unorm: return TinyImageFormat_R16_UNORM;
	case TIF_MTLPixelFormatR16Snorm: return TinyImageFormat_R16_SNORM;
	case TIF_MTLPixelFormatR16Uint: return TinyImageFormat_R16_UINT;
	case TIF_MTLPixelFormatR16Sint: return TinyImageFormat_R16_SINT;
	case TIF_MTLPixelFormatR16Float: return TinyImageFormat_R16_SFLOAT;
	case TIF_MTLPixelFormatRG8Unorm: return TinyImageFormat_R8G8B8_UNORM;
	case TIF_MTLPixelFormatRG8Unorm_sRGB: return TinyImageFormat_R8G8_SRGB;
	case TIF_MTLPixelFormatRG8Snorm: return TinyImageFormat_R8G8_SNORM;
	case TIF_MTLPixelFormatRG8Uint: return TinyImageFormat_R8G8_UINT;
	case TIF_MTLPixelFormatRG8Sint: return TinyImageFormat_R8G8_SINT;
	case TIF_MTLPixelFormatB5G6R5Unorm: return TinyImageFormat_R5G6B5_UNORM;
	case TIF_MTLPixelFormatA1BGR5Unorm: return TinyImageFormat_R5G5B5A1_UNORM;
	case TIF_MTLPixelFormatABGR4Unorm: return TinyImageFormat_R4G4B4A4_UNORM;
	case TIF_MTLPixelFormatBGR5A1Unorm: return TinyImageFormat_A1R5G5B5_UNORM;
	case TIF_MTLPixelFormatR32Uint: return TinyImageFormat_R32_UINT;
	case TIF_MTLPixelFormatR32Sint: return TinyImageFormat_R32_SINT;
	case TIF_MTLPixelFormatR32Float: return TinyImageFormat_R32_SFLOAT;
	case TIF_MTLPixelFormatRG16Unorm: return TinyImageFormat_R16G16_UNORM;
	case TIF_MTLPixelFormatRG16Snorm: return TinyImageFormat_R16G16_SNORM;
	case TIF_MTLPixelFormatRG16Uint: return TinyImageFormat_R16G16B16_UINT;
	case TIF_MTLPixelFormatRG16Sint: return TinyImageFormat_R16G16_SINT;
	case TIF_MTLPixelFormatRG16Float: return TinyImageFormat_R16G16_SFLOAT;
	case TIF_MTLPixelFormatRGBA8Unorm: return TinyImageFormat_R8G8B8A8_UNORM;
	case TIF_MTLPixelFormatRGBA8Unorm_sRGB: return TinyImageFormat_R8G8B8A8_SRGB;
	case TIF_MTLPixelFormatRGBA8Snorm: return TinyImageFormat_R8G8B8A8_SNORM;
	case TIF_MTLPixelFormatRGBA8Uint: return TinyImageFormat_R8G8B8A8_UINT;
	case TIF_MTLPixelFormatRGBA8Sint: return TinyImageFormat_R8G8B8A8_SINT;
	case TIF_MTLPixelFormatBGRA8Unorm: return TinyImageFormat_B8G8R8A8_UNORM;
	case TIF_MTLPixelFormatRGB10A2Unorm: return TinyImageFormat_A2B10G10R10_UNORM;
	case TIF_MTLPixelFormatRGB10A2Uint: return TinyImageFormat_A2B10G10R10_UINT;
	case TIF_MTLPixelFormatRG11B10Float: return TinyImageFormat_B10G11R11_UFLOAT;
	case TIF_MTLPixelFormatRGB9E5Float: return TinyImageFormat_E5B9G9R9_UFLOAT;
	case TIF_MTLPixelFormatBGR10A2Unorm: return TinyImageFormat_A2R10G10B10_UNORM;
	case TIF_MTLPixelFormatRG32Uint: return TinyImageFormat_R32G32_UINT;
	case TIF_MTLPixelFormatRG32Sint: return TinyImageFormat_R32G32_SINT;
	case TIF_MTLPixelFormatRG32Float: return TinyImageFormat_R32G32_SFLOAT;
	case TIF_MTLPixelFormatRGBA16Unorm: return TinyImageFormat_R16G16B16A16_UNORM;
	case TIF_MTLPixelFormatRGBA16Snorm: return TinyImageFormat_R16G16B16A16_SNORM;
	case TIF_MTLPixelFormatRGBA16Uint: return TinyImageFormat_R16G16B16A16_UINT;
	case TIF_MTLPixelFormatRGBA16Sint: return TinyImageFormat_R16G16B16A16_SINT;
	case TIF_MTLPixelFormatRGBA16Float: return TinyImageFormat_R16G16B16A16_SFLOAT;
	case TIF_MTLPixelFormatRGBA32Uint: return TinyImageFormat_R32G32B32A32_UINT;
	case TIF_MTLPixelFormatRGBA32Sint: return TinyImageFormat_R32G32B32A32_SINT;
	case TIF_MTLPixelFormatRGBA32Float: return TinyImageFormat_R32G32B32A32_SFLOAT;
	case TIF_MTLPixelFormatBC1_RGBA: return TinyImageFormat_DXBC1_RGBA_SRGB;
	case TIF_MTLPixelFormatBC1_RGBA_sRGB: return TinyImageFormat_DXBC1_RGBA_SRGB;
	case TIF_MTLPixelFormatBC2_RGBA: return TinyImageFormat_DXBC2_UNORM;
	case TIF_MTLPixelFormatBC2_RGBA_sRGB: return TinyImageFormat_DXBC2_SRGB;
	case TIF_MTLPixelFormatBC3_RGBA: return TinyImageFormat_DXBC3_UNORM;
	case TIF_MTLPixelFormatBC3_RGBA_sRGB: return TinyImageFormat_DXBC2_SRGB;
	case TIF_MTLPixelFormatBC4_RUnorm: return TinyImageFormat_DXBC4_UNORM;
	case TIF_MTLPixelFormatBC4_RSnorm: return TinyImageFormat_DXBC4_SNORM;
	case TIF_MTLPixelFormatBC5_RGUnorm: return TinyImageFormat_DXBC5_UNORM;
	case TIF_MTLPixelFormatBC5_RGSnorm: return TinyImageFormat_DXBC5_SNORM;
	case TIF_MTLPixelFormatBC6H_RGBFloat: return TinyImageFormat_DXBC6H_SFLOAT;
	case TIF_MTLPixelFormatBC6H_RGBUfloat: return TinyImageFormat_DXBC6H_UFLOAT;
	case TIF_MTLPixelFormatBC7_RGBAUnorm: return TinyImageFormat_DXBC7_UNORM;
	case TIF_MTLPixelFormatBC7_RGBAUnorm_sRGB: return TinyImageFormat_DXBC7_SRGB;
	case TIF_MTLPixelFormatPVRTC_RGB_2BPP: return TinyImageFormat_PVRTC1_2BPP_UNORM;
	case TIF_MTLPixelFormatPVRTC_RGB_2BPP_sRGB: return TinyImageFormat_PVRTC1_2BPP_SRGB;
	case TIF_MTLPixelFormatPVRTC_RGB_4BPP: return TinyImageFormat_PVRTC1_4BPP_UNORM;
	case TIF_MTLPixelFormatPVRTC_RGB_4BPP_sRGB: return TinyImageFormat_PVRTC1_4BPP_SRGB;
	case TIF_MTLPixelFormatPVRTC_RGBA_2BPP: return TinyImageFormat_PVRTC1_2BPP_UNORM;
	case TIF_MTLPixelFormatPVRTC_RGBA_2BPP_sRGB: return TinyImageFormat_PVRTC1_2BPP_SRGB;
	case TIF_MTLPixelFormatPVRTC_RGBA_4BPP: return TinyImageFormat_PVRTC1_4BPP_UNORM;
	case TIF_MTLPixelFormatPVRTC_RGBA_4BPP_sRGB: return TinyImageFormat_PVRTC1_4BPP_SRGB;
	case TIF_MTLPixelFormatEAC_R11Unorm: return TinyImageFormat_ETC2_EAC_R11_UNORM;
	case TIF_MTLPixelFormatEAC_R11Snorm: return TinyImageFormat_ETC2_EAC_R11_SNORM;
	case TIF_MTLPixelFormatEAC_RG11Unorm: return TinyImageFormat_ETC2_EAC_R11G11_UNORM;
	case TIF_MTLPixelFormatEAC_RG11Snorm: return TinyImageFormat_ETC2_EAC_R11G11_SNORM;
	case TIF_MTLPixelFormatEAC_RGBA8: return TinyImageFormat_ETC2_R8G8B8A8_UNORM;
	case TIF_MTLPixelFormatEAC_RGBA8_sRGB: return TinyImageFormat_ETC2_R8G8B8A8_SRGB;
	case TIF_MTLPixelFormatETC2_RGB8: return TinyImageFormat_ETC2_R8G8B8_UNORM;
	case TIF_MTLPixelFormatETC2_RGB8_sRGB: return TinyImageFormat_ETC2_R8G8B8_SRGB;
	case TIF_MTLPixelFormatETC2_RGB8A1: return TinyImageFormat_ETC2_R8G8B8A1_UNORM;
	case TIF_MTLPixelFormatETC2_RGB8A1_sRGB: return TinyImageFormat_ETC2_R8G8B8A1_SRGB;
	case TIF_MTLPixelFormatASTC_4x4_sRGB:			return TinyImageFormat_ASTC_4x4_SRGB;
	case TIF_MTLPixelFormatASTC_5x4_sRGB:			return TinyImageFormat_ASTC_5x4_SRGB;
	case TIF_MTLPixelFormatASTC_5x5_sRGB:			return TinyImageFormat_ASTC_5x4_SRGB;
	case TIF_MTLPixelFormatASTC_6x5_sRGB:			return TinyImageFormat_ASTC_6x5_SRGB;
	case TIF_MTLPixelFormatASTC_6x6_sRGB:			return TinyImageFormat_ASTC_6x6_SRGB;
	case TIF_MTLPixelFormatASTC_8x5_sRGB:			return TinyImageFormat_ASTC_8x5_SRGB;
	case TIF_MTLPixelFormatASTC_8x6_sRGB:			return TinyImageFormat_ASTC_8x6_SRGB;
	case TIF_MTLPixelFormatASTC_8x8_sRGB:			return TinyImageFormat_ASTC_8x8_SRGB;
	case TIF_MTLPixelFormatASTC_10x5_sRGB:		return TinyImageFormat_ASTC_10x5_SRGB;
	case TIF_MTLPixelFormatASTC_10x6_sRGB:		return TinyImageFormat_ASTC_10x6_SRGB;
	case TIF_MTLPixelFormatASTC_10x8_sRGB:		return TinyImageFormat_ASTC_10x8_SRGB;
	case TIF_MTLPixelFormatASTC_10x10_sRGB: 	return TinyImageFormat_ASTC_10x10_SRGB;
	case TIF_MTLPixelFormatASTC_12x10_sRGB: 	return TinyImageFormat_ASTC_12x10_SRGB;
	case TIF_MTLPixelFormatASTC_12x12_sRGB: 	return TinyImageFormat_ASTC_12x12_SRGB;
	case TIF_MTLPixelFormatASTC_4x4_LDR: 		return TinyImageFormat_ASTC_4x4_UNORM;
	case TIF_MTLPixelFormatASTC_5x4_LDR: 		return TinyImageFormat_ASTC_5x4_UNORM;
	case TIF_MTLPixelFormatASTC_5x5_LDR: 		return TinyImageFormat_ASTC_5x4_UNORM;
	case TIF_MTLPixelFormatASTC_6x5_LDR: 		return TinyImageFormat_ASTC_6x5_UNORM;
	case TIF_MTLPixelFormatASTC_6x6_LDR: 		return TinyImageFormat_ASTC_6x6_UNORM;
	case TIF_MTLPixelFormatASTC_8x5_LDR: 		return TinyImageFormat_ASTC_8x5_UNORM;
	case TIF_MTLPixelFormatASTC_8x6_LDR: 		return TinyImageFormat_ASTC_8x6_UNORM;
	case TIF_MTLPixelFormatASTC_8x8_LDR: 		return TinyImageFormat_ASTC_8x8_UNORM;
	case TIF_MTLPixelFormatASTC_10x5_LDR:		return TinyImageFormat_ASTC_10x5_UNORM;
	case TIF_MTLPixelFormatASTC_10x6_LDR:		return TinyImageFormat_ASTC_10x6_UNORM;
	case TIF_MTLPixelFormatASTC_10x8_LDR:		return TinyImageFormat_ASTC_10x8_UNORM;
	case TIF_MTLPixelFormatASTC_10x10_LDR: 	return TinyImageFormat_ASTC_10x10_UNORM;
	case TIF_MTLPixelFormatASTC_12x10_LDR: 	return TinyImageFormat_ASTC_12x10_UNORM;
	case TIF_MTLPixelFormatASTC_12x12_LDR: 	return TinyImageFormat_ASTC_12x12_UNORM;
	case TIF_MTLPixelFormatDepth16Unorm: return TinyImageFormat_D16_UNORM;
	case TIF_MTLPixelFormatDepth32Float: return TinyImageFormat_D32_SFLOAT;
	case TIF_MTLPixelFormatStencil8: return TinyImageFormat_S8_UINT;
	case TIF_MTLPixelFormatDepth24Unorm_Stencil8: return TinyImageFormat_D24_UNORM_S8_UINT;
	case TIF_MTLPixelFormatDepth32Float_Stencil8: return TinyImageFormat_D32_SFLOAT_S8_UINT;
	case TIF_MTLPixelFormatX32_Stencil8: return TinyImageFormat_D32_SFLOAT_S8_UINT;
	case TIF_MTLPixelFormatX24_Stencil8: return TinyImageFormat_D24_UNORM_S8_UINT;

	case TIF_MTLPixelFormatBGRA8Unorm_sRGB: return TinyImageFormat_UNDEFINED;
	case TIF_MTLPixelFormatBGR10_XR: return TinyImageFormat_UNDEFINED;
	case TIF_MTLPixelFormatBGR10_XR_sRGB: return TinyImageFormat_UNDEFINED;
	case TIF_MTLPixelFormatBGRA10_XR: return TinyImageFormat_UNDEFINED;
	case TIF_MTLPixelFormatBGRA10_XR_sRGB: return TinyImageFormat_UNDEFINED;
	case TIF_MTLPixelFormatGBGR422: return TinyImageFormat_UNDEFINED;
	case TIF_MTLPixelFormatBGRG422: return TinyImageFormat_UNDEFINED;
	}
	return TinyImageFormat_UNDEFINED;
}
