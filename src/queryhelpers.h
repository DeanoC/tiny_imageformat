RAW_INCLUDE_START( R"=====( )

// Helpers
TIF_CONSTEXPR inline uint32_t TinyImageFormat_PixelCountOfBlock(TinyImageFormat const fmt) {
	return TinyImageFormat_WidthOfBlock(fmt) * TinyImageFormat_HeightOfBlock(fmt) * TinyImageFormat_DepthOfBlock(fmt);
}

TIF_CONSTEXPR inline double TinyImageFormat_Min(TinyImageFormat const fmt, TinyImageFormat_LogicalChannel const channel) {
	return TinyImageFormat_MinAtPhysical(fmt, TinyImageFormat_LogicalChannelToPhysical(fmt, channel));
}

TIF_CONSTEXPR inline double TinyImageFormat_Max(TinyImageFormat const fmt, TinyImageFormat_LogicalChannel const channel) {
	return TinyImageFormat_MaxAtPhysical(fmt, TinyImageFormat_LogicalChannelToPhysical(fmt, channel));
}

TIF_CONSTEXPR inline uint32_t TinyImageFormat_ChannelBitWidth(TinyImageFormat const fmt, TinyImageFormat_LogicalChannel const channel) {
	return TinyImageFormat_ChannelBitWidthAtPhysical(fmt, TinyImageFormat_LogicalChannelToPhysical(fmt, channel));
}

RAW_INCLUDE_END( )=====" )