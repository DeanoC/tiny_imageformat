RAW_INCLUDE_START( R"=====( )

// from D3DX_DXGIFormatConvert.inl
inline uint8_t TinyImageFormat_Float2SRGB(float v) {
	if (v < 0.0031308f) {
		v *= 12.92f;
	} else {
		v = 1.055f * powf(v, 1.0f / 2.4f) - 0.055f;
	}
	return (uint8_t)v;
}

inline uint16_t TinyImageFormat_FloatToBFloatAsUint(float v) {
	union {
		struct {
			uint16_t u;
			uint16_t x;
		};
		float f;
	} o;

	o.f = v;
	o.x = 0;

	return o.u;
}

RAW_INCLUDE_END( )=====" )