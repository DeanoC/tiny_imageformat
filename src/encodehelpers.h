RAW_INCLUDE_START( R"=====( )

// from D3DX_DXGIFormatConvert.inl
inline uint8_t TinyImageFormat_FloatToSRGB(float v) {
	if (v < 0.0031308f) {
		v *= 12.92f;
	} else {
		v = 1.055f * powf(v, 1.0f / 2.4f) - 0.055f;
	}
	return (uint8_t)v;
}

//Float2Half from Rygorous public domain code
inline uint16_t TinyImageFormat_FloatToHalfAsUint(float f_) {
	union {
		uint16_t u;
		struct {
			uint16_t Mantissa : 10;
			uint16_t Exponent : 5;
			uint16_t Sign : 1;
		};
	} o;

	union {
		uint32_t u;
		float f;
		struct {
			uint32_t Mantissa : 23;
			uint32_t Exponent : 8;
			uint32_t Sign : 1;
		};
	} f;

	static uint32_t const f32infty = {255 << 23};
	static uint32_t const f16max = {(127 + 16) << 23};
	static uint32_t const denorm_magicU = {((127 - 15) + (23 - 10) + 1) << 23};
	static uint32_t const sign_mask = 0x80000000u;

	float const denorm_magic = *(float const*)(&denorm_magicU);

	o.u = 0;
	f.f = f_;

	uint32_t const sign = f.u & sign_mask;
	f.u ^= sign;

	// NOTE all the integer compares in this function can be safely
	// compiled into signed compares since all operands are below
	// 0x80000000. Important if you want fast straight SSE2 code
	// (since there's no unsigned PCMPGTD).

	if (f.u >= f16max) { // result is Inf or NaN (all exponent bits set)
		o.u = (f.u > f32infty) ? 0x7e00 : 0x7c00; // NaN->qNaN and Inf->Inf
	} else // (De)normalized number or zero
	{
		if (f.u < (113 << 23)) // resulting FP16 is subnormal or zero
		{
			// use a magic value to align our 10 mantissa bits at the bottom of
			// the float. as long as FP addition is round-to-nearest-even this
			// just works.
			f.f += denorm_magic;

			// and one integer subtract of the bias later, we have our final float!
			o.u = f.u - denorm_magicU;
		} else {
			uint32_t mant_odd = (f.u >> 13) & 1; // resulting mantissa is odd

			// update exponent, rounding bias part 1
			f.u += 0xc8000fff;
			// rounding bias part 2
			f.u += mant_odd;
			// take the bits!
			o.u = f.u >> 13;
		}
	}

	o.u |= sign >> 16;
	return o.u;
}

inline uint16_t TinyImageFormat_FloatToBFloatAsUint(float v) {
	union {
		struct {
			uint16_t x;
			uint16_t u;
		};
		float f;
	} o;

	o.f = v;
	o.x = 0;

	return o.u;
}

inline void TinyImageFormat_FloatRGBToRGB9E5AsUint32(float const* in, uint32_t* out) {
	float const r = in[0];
	float const g = in[1];
	float const b = in[2];
	float const v = r > g ? r > b ? r : b : g > b ? g : b;


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

	if (v < 1.52587890625e-5f) {
		*out = 0;
	} else if (v < 65536) {
		int ex;
		float m = frexpf(v, &ex) * 512.0f / v;

		ei.rm = (uint32_t)(m * r);
		ei.gm = (uint32_t)(m * g);
		ei.bm = (uint32_t)(m * b);
		ei.e = (unsigned int) (ex + 15);
		*out = ei.v;
	} else {
		ei.rm = (r < 65536) ? (uint32_t)(r * (1.0f / 128.0f)) : 0x1FF;
		ei.gm = (g < 65536) ? (uint32_t)(g * (1.0f / 128.0f)) : 0x1FF;
		ei.bm = (b < 65536) ? (uint32_t)(b * (1.0f / 128.0f)) : 0x1FF;
		ei.e = 31;
		*out = ei.v;
	}
}

inline uint16_t TinyImageFormat_FloatToUFloat6AsUint(float Value)
{
		uint32_t IValue = *((uint32_t *)&Value);

		if (IValue & 0x80000000U)
		{
				// Positive only
				return 0;
		}
		else if (IValue > 0x43FEFFFFU)
		{
				// The number is too large to be represented as a 6e4. Saturate.
				return 0x3FFU;
		}
		else
		{
				if (IValue < 0x3C800000U)
				{
						// The number is too small to be represented as a normalized 6e4.
						// Convert it to a denormalized value.
						uint32_t Shift = 121U - (IValue >> 23U);
						if(Shift < 24U) Shift = 24U;

						IValue = (0x800000U | (IValue & 0x7FFFFFU)) >> Shift;
				}
				else
				{
						// Rebias the exponent to represent the value as a normalized 6e4.
						IValue += 0xC4000000U;
				}

				return (uint16_t)(((IValue + 0xFFFFU + ((IValue >> 17U) & 1U)) >> 17U) & 0x3FFU);
		}
}

inline uint16_t TinyImageFormat_FloatToUFloat7AsUint(float Value)
{
		uint32_t IValue = *((uint32_t *)&Value);

		if (IValue & 0x80000000U)
		{
				// Positive only
				return 0;
		}
		else if (IValue > 0x41FF73FFU)
		{
				// The number is too large to be represented as a 7e3. Saturate.
				return 0x3FFU;
		}
		else
		{
				if (IValue < 0x3E800000U)
				{
						// The number is too small to be represented as a normalized 7e3.
						// Convert it to a denormalized value.
						uint32_t Shift = 125U - (IValue >> 23U);
						if(Shift < 24U) Shift = 24U;

						IValue = (0x800000U | (IValue & 0x7FFFFFU)) >> Shift;
				}
				else
				{
						// Rebias the exponent to represent the value as a normalized 7e3.
						IValue += 0xC2000000U;
				}

				return (uint16_t)(((IValue + 0x7FFFU + ((IValue >> 16U) & 1U)) >> 16U) & 0x3FFU);
		}
}

inline uint16_t TinyImageFormat_FloatToUFloat10AsUint(float v) {
	union {
		uint32_t u;
		float f;
		struct {
			uint32_t Mantissa : 23;
			uint32_t Exponent : 8;
			uint32_t Sign : 1;
		};
	} o;
	union {
		struct {
			uint16_t e : 5;
			uint16_t m : 5;
			uint16_t x : 6; // not used
		};
		uint16_t v;
	} ei;

	o.f = v;
	ei.v = 0;

	//  positive only, so clamp to zero
	if(o.Sign) return 0;

	// 5-bit exponent, 5-bit mantissa

	// INF or NAN
	if (o.Exponent == 0xFF) {
		if ( o.Mantissa != 0) {
			return  0x3e0 | (((o.u>>18)|(o.u>>11)|(o.u>>6)|(o.u))&0x3f);
		} else {
			return 0x3e0;
		}
	} else if (o.u > 0x477C0000U) {
		// The number is too large to be represented as a float10, set to max
		return 0x3df;
	}
	else if (o.u < 0x38800000U) {
		// The number is too small to be represented as a normalized float11
		// Convert it to a denormalized value.
		ei.e = 0;
		ei.m = o.Mantissa >> (113U - o.Exponent);
	} else {
		// Rebias the exponent to represent the value as a normalized float11
		ei.e = o.Exponent + 16;
		ei.m = o.Mantissa >> 18;
	}

	return ei.v;
}

inline uint16_t TinyImageFormat_FloatToUFloat11AsUint(float v) {
    union {
        uint32_t u;
        float f;
        struct {
            uint32_t Mantissa : 23;
            uint32_t Exponent : 8;
            uint32_t Sign : 1;
        };
    } o;
	union {
		struct {
			uint16_t e : 5;
			uint16_t m : 6;
			uint16_t x : 5; // not used
		};
		uint16_t v;
	} ei;

	o.f = v;
	ei.v = 0;

	//  positive only, so clamp to zero
	if(o.Sign) return 0;

	// 5-bit exponent, 6-bit mantissa)

	// INF or NAN
	if (o.Exponent == 0xFF) {
		if ( o.Mantissa != 0) {
				return  0x7c0 | (((o.u>>17)|(o.u>>11)|(o.u>>6)|(o.u))&0x3f);
		} else {
				return 0x7c0;
		}
	} else if (o.u > 0x477C0000U) {
		// The number is too large to be represented as a float11, set to max
		return 0x7BF;
	}
	else if (o.u < 0x38800000U) {
		// The number is too small to be represented as a normalized float11
		// Convert it to a denormalized value.
		ei.e = 0;
		ei.m = o.Mantissa >> (113U - o.Exponent);
	} else {
		// Rebias the exponent to represent the value as a normalized float11
		ei.e = o.Exponent + 16;
		ei.m = o.Mantissa >> 17;
	}

	return ei.v;
}

RAW_INCLUDE_END( )=====" )