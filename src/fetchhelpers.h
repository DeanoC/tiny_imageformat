RAW_INCLUDE_START( R"=====( )


inline void TinyImageFormat_SharedE5B9G9R9UFloatToFloats(uint32_t v, float out[4]) {
	// https://github.com/microsoft/DirectXMath/blob/ecfb4754400dac581c2eeb6e849617cf5d210426/Inc/DirectXPackedVector.h
	union
	{
		struct
		{
			uint32_t rm : 9;
			uint32_t gm : 9;
			uint32_t bm : 9;
			uint32_t e  : 5;
		};
		uint32_t v;
	} ei;

	union {
		uint32_t u;
		float f;
	} t;

	ei.v = v;
	t.u = 0x33800000 + (ei.e << 23);

	out[0] = t.f * (float)(ei.rm);
	out[1] = t.f * (float)(ei.gm);
	out[2] = t.f * (float)(ei.bm);
	out[3] = 1.0f;
}

//HalfToFloat from Rygorous public domain code
inline float TinyImageFormat_HalfAsUintToFloat(uint16_t h_) {

	const uint32_t shifted_exp = 0x7c00 << 13; // exponent mask after shift
	union {
		uint16_t u;
		struct {
			uint32_t Mantissa : 10;
			uint32_t Exponent : 5;
			uint32_t Sign : 1;
		};
	} h;

	union {
		uint32_t u;
		float f;
		struct {
			uint32_t Mantissa : 23;
			uint32_t Exponent : 8;
			uint32_t Sign : 1;
		};
	} o;

	h.u = h_;

	o.u = (h.u & 0x7fff) << 13;     // exponent/mantissa bits
	uint32_t exp = shifted_exp & o.u;   // just the exponent
	o.u += (127 - 15) << 23;        // exponent adjust

	// handle exponent special cases
	if (exp == shifted_exp) { // Inf/NaN?
		o.u += (128 - 16) << 23;    // extra exp adjust
	} else if (exp == 0) // Zero/Denormal?
	{
		union {
			uint32_t u;
			float f;
		} magic;
		magic.u = 113 << 23;

		o.u += 1 << 23;             // extra exp adjust
		o.f -= magic.f;      // renormalize
	}

	o.u |= (h.u & 0x8000) << 16;    // sign bit
	return o.f;
}

inline float TinyImageFormat_BFloatAsUintToFloat(uint16_t h_) {
	union {
		struct {
			uint16_t x;
			uint16_t u;
		};
		float f;
	} o;

	o.u = h_;
	o.x = 0;

	return o.f;
}

inline float TinyImageFormat_UFloat6AsUintToFloat(uint16_t Value)
{
	// https://github.com/microsoft/DirectXMath/blob/ecfb4754400dac581c2eeb6e849617cf5d210426/Inc/DirectXPackedVector.h

	union {
		uint32_t u;
		float f;
		struct {
			uint32_t Mantissa : 23;
			uint32_t Exponent : 8;
			uint32_t Sign : 1;
		};
	} o;

	o.Mantissa = Value & 0x3F;
	o.Exponent = Value & 0x3C0;
	o.Sign = 0;

	if (o.Exponent != 0)  // The value is normalized
	{
		o.Exponent = (uint32_t)((Value >> 6) & 0xF);
	}
	else if (o.Mantissa != 0)     // The value is denormalized
	{
		// Normalize the value in the resulting float
		o.Exponent = 1;
		do
		{
				o.Exponent--;
				o.Mantissa <<= 1;
		} while ((o.Mantissa & 0x40) == 0);
		o.Mantissa &= 0x3F;
	}
	else
	{
		// The value is zero
		o.u = 0;
	}

	return o.f;
}

inline float TinyImageFormat_UFloat7AsUintToFloat(uint16_t Value)
{
	// https://github.com/microsoft/DirectXMath/blob/ecfb4754400dac581c2eeb6e849617cf5d210426/Inc/DirectXPackedVector.h

	union {
		uint32_t u;
		float f;
		struct {
			uint32_t Mantissa : 23;
			uint32_t Exponent : 8;
			uint32_t Sign : 1;
		};
	} o;

	o.Mantissa = Value & 0x7F;
	o.Exponent = Value & 0x380;
	o.Sign = 0;

	if (o.Exponent != 0)  // The value is normalized
	{
		o.Exponent = (uint32_t)((Value >> 7) & 0x7);
	}
	else if (o.Mantissa != 0)     // The value is denormalized
	{
		// Normalize the value in the resulting float
		o.Exponent = 1;
		do
		{
				o.Exponent--;
				o.Mantissa <<= 1;
		} while ((o.Mantissa & 0x80) == 0);
		o.Mantissa &= 0x7F;
	}
	else
	{
		// The value is zero
		o.u = 0;
	}

	return o.f;
}

inline float TinyImageFormat_UFloat10AsUintToFloat(uint16_t v) {
	// https://github.com/microsoft/DirectXMath/blob/ecfb4754400dac581c2eeb6e849617cf5d210426/Inc/DirectXPackedVector.h
	union {
		struct {
			uint16_t e : 5;
			uint16_t m : 5;
			uint16_t x : 6; // not used
		};
		uint16_t v;
	} ei;

	union {
			uint32_t u;
			float f;
	} t;

	ei.v = v;

	double out = 0.0;
	if (ei.e == 31) {
		if (ei.m == 0) {
			t.u = 0xFF100000; // + infinity
		} else {
			t.u = 0xFF100002; // float qNAN with payload = 1
		}
	} else if (ei.e == 0) {
		if(ei.m == 0) {
			t.f = 0.0f;
		} else {
			// Normalized float
			uint32_t exp = 1;
			uint32_t man = ei.m;
			do
			{
				exp--;
				man <<= 1;
			} while ((man & 0x20) == 0);
			man &= 0x1F;
			t.u = ((exp + 112) << 23) | (man << 18);
		}
	} else {
		t.u = ((ei.e + 112) << 23) | (ei.m << 18);
	}
	return t.f;
}

inline float TinyImageFormat_UFloat11AsUintToFloat(uint16_t v) {
	// https://github.com/microsoft/DirectXMath/blob/ecfb4754400dac581c2eeb6e849617cf5d210426/Inc/DirectXPackedVector.h
	union {
		struct {
			uint16_t e : 5;
			uint16_t m : 6;
			uint16_t x : 5; // not used
		};
		uint16_t v;
	} ei;

	union {
			uint32_t u;
			float f;
	} t;

	ei.v = v;

	if (ei.e == 31) {
		if (ei.m == 0) {
			t.u = 0xFF100000; // + infinity
		} else {
			t.u = 0xFF100002; // float qNAN with payload = 1
		}
	} else if (ei.e == 0) {
		if(ei.m == 0) {
			t.f = 0.0f;
		} else {
			// Normalized float
			uint32_t exp = 1;
			uint32_t man = ei.m;
			do
			{
				exp--;
				man <<= 1;
			} while ((man & 0x40) == 0);
			man &= 0x3F;
			t.u = ((exp + 112) << 23) | (man << 17);
		}
	} else {
		t.u = ((ei.e + 112) << 23) | (ei.m << 17);
	}
	return t.f;
}

RAW_INCLUDE_END( )=====" )