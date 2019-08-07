RAW_INCLUDE_START( R"=====( )
/* TinyImageFormat is a library about the encodings of pixel typically
 * encountered in real time graphics.
 *
 * Like modern graphics API it is enumeration based but it also provides an API
 * for reasoning about that enumeration programmatically.
 *
 * Whilst not optimal due to number of formats it supports , it intends to
 * provide fast enough for support for its function, that in most cases it will
 * be fine.
 *
 * This is because internally every format has a descriptor packed into a 64 bit
 * code word.
 * This code word is used to generate the header and it isn't used by the API
 * itself having been burnt out by the code generator but it can be used at
 * runtime if desired and likely will to provide exotic packed formats that
 * don't get there own enumeration value but can be expressed via a descriptor.
 *
 * Additionally it provide ways of accessing pixels encoded in the specified
 * format for most pixel formats. The hope is eventually to get 100% but not
 * there yet. This allows you to effectively read almost any pixel formated data
 * with this library into a form you can manipulate and use easily.
 *
 * To assist with working with graphics API converters to and from the 3 main
 * APIs are provided, Vulkan, D3D12 and Metal. These are self contained and do
 * not require the APIs themselves.
 *
 * This file is large due to unrolling most decoding etc. Function are inline
 * and switch based, allowing the compiler to eliminate and collapse when
 * possible, however particularly the Fetch functions aren't anywhere near as
 * fast as the could be if heavily optimised for specific formats/layouts.
 *
 * However this should compile to be fast enough for many use cases.
 *
 * Where possible for C++ users functions are constexpr.
 *
 * It is MIT licensed and borrows/builds on code/specs including but not
 * limited to
 * Microsoft's Chris Walbourn DXTextureTool
 * Rygerous public domain Half to float code
 * Khronos DFD specifications
 * Khronos Vulkan Specification
 * Microsoft D3D11/D3D12 Specifications
 * Apple Metal documentation
 * DDS Loaders from various sources (Humus, Confetti FX, DXTextureTool)
 *
 * Definitions
 * -----------
 *
 * Pixel
 * We define a pixel as upto 4 channels representing a single 'colour'
 * Depending on context its may not be addressable directly
 * When fetching, pixels are returned as 4 fully decoded doubles
 *
 * Logical Channels (TinyImageFormat_LogicalChannel)
 * Logical channel are the usual way you would ask for a particular channel,
 * so asking about LC_Red while get you data on the red channel however its
 * physically encoded in the data.
 *
 * Physical Channels (TinyImageFormat_PhysicalChannel)
 * Physical channels are the inverse of logical channels, that have no meaning
 * beyond the position in the data itself.
 *
 * Channel Constants
 * Both Logical and Physical channels support return constant 0 or 1 if asked
 * for data outside what encoded.
 *
 * Blocks
 * A block is the smallest addressable element this format refers to. Blocks
 * have up to 3 dimensions (though no format currently uses the 3rd).
 * For single pixel formats this will be 1x1x1.
 * For block compressed format a common value is 4x4x1.
 * Shared channels or very tightly packed this is how many pixels are combined
 * into one addressable unit.
 *
 * API
 * ---
 * The primary enumeration is simply TinyImageFormat, everything else supports
 * this enum.
 * All functions, enums etc. are prefixed with TinyImageFormat_ this is often
 * removed in the api docs to save space.
 *
 * Defines
 * TinyImageFormat_Count - how many formats in total
 *
 * Enums
 * TinyImageFormat - Count entries, one for each format supported
 * TinyImageFormat_Code - one per format, these are the 64 bit descriptors
 * LogicalChannel - values for logical channel or constants
 * 						- LC_Red - Red channel is specified
 * 						- LC_Green - Green channel is specified
 * 						- LC_Blue - Blue channel is specified
 * 						- LC_Alpha - Alpha channel is specified
 * 						- LC_Depth - Depth channel is specified
 * 						- LC_Stencil - Stencil channel is specified
 * 						- LC_1 - constant 1 will be returned
 * 						- LC_0 - constant 0 will be return
 * PhysicalChannel - values for physical channel or constants
 * 						- PC_0 - Leftmost channel
 * 						- PC_1 - 2nd channel
 * 						- PC_2 - 3rd channel
 * 						- PC_3 - 4th channel
 * 						- PC_CONST_1 - constant 1 will be returned
 * 						- PC_CONST_0 - constant 0 will be return
 *
 * Information Functions
 * -----------
 * Name( fmt ) - Human C string with the name of this fmt
 * FromName( name ) - lookup the format given the name as a C String (fast)
 * IsDepthOnly( fmt ) - true if just a depth channel
 * IsStencilOnly( fmt ) - true if just a stencil channel
 * IsDepthAndStencil( fmt ) - if has both depth and stencil channel
 * IsCompressed( fmt ) - true if its a compressed format (aka block)
 * IsCLUT( fmt ) - true if data is index into a CLUT (Colour Look Up Table)
 * IsFloat( fmt ) - is the data in floating point
 * IsNormalised( fmt ) - return true if data will be within 0 to 1 or -1 to 1
 * IsSigned( fmt ) - does the data include negatives
 * IsSRGB( fmt ) - is the data encoded using sRGB non linear encoding
 * IsHomogenous( fmt ) - is the encoding the same for every channel
 * WidthOfBlock( fmt ) - How many pixels in the x dimension for a block
 * HeightOfBlock( fmt ) - How many pixels in the y dimension for a block
 * DepthOfBlock( fmt ) 	- How many pixels in the z dimension for a block
 * PixelCountOfBlock( fmt ) - How many pixels in total for a block
 * BitSizeOfBlock( fmt ) - How big in bits is a single block.
 * ChannelCount( fmt ) - How many channels are actually encoded
 *
 * Logical Channel Functions
 * -------------------------
 * ChannelBitWidth( fmt, logical channel ) - how wide in bits is the channel
 * Min( fmt, logical channel ) - minimum possible value for the channel
 * Max( fmt, logical channel ) - maximum possible value for the channel
 * LogicalChannelToPhysical( fmt, logical channel )
 * 											- what physical channel is the logical channel stored in
 * 											- or constant 0 or 1 if its not physically stored
 *
 * Pixel Decoder Functions
 * -----------------------
 * CanFetchLogicalPixel( fmt ) - Can FetchLogicalPixel work with this format?
 * FetchLogicalPixel(fmt, in pointer out pixel) -
 * 							- returns 4 double values encoded at the in pointer
 * 							- does full decode and remapping into logical channels
 * 							- include constants etc. so returned result can be used directly
 *
 * Pixel Decoder Helper Functions
 * -----------------------
 * UFloat10ToDouble( uint16_t ) - returns the value stored as a 10 bit UFloat
 * UFloat11ToDouble( uint16_t ) - returns the value stored as a 11 bit UFloat
 * SharedE5B9G9R9UFloatToDoubles( uint32 ) - return the pixel stored in shared
 * 															- shared 5 bit exponent,  9 bit mantissa for RGB
 * HalfAsUintToDouble( uint16_t ) returns the value stored as a 16 bit SFloat
 * LookupSRGB( uint8_t) returns the value for an 8 bit sRGB encoded value
 *
 * Physical Channel Functions (in general use the Logical Channels)
 * ------------------
 * ChannelBitWidthAtPhysical( fmt, physical channel )
 * 											- how wide in bits is the channel
 * MinAtPhysical( fmt, physical channel ) - min possible value for the channel
 * MaxAtPhysical( fmt, physical channel ) - max possible value for the channel
 * PhysicalChannelToLogical( fmt, physical channel)
 * 											- what logical channel does a physical channel map to.
 * 											- Or a constant 0 or 1
 *
 * Graphics API Functions
 * ------------------
 * FromVkFormat( VkFormat ) converts from or UNDEFINED if not possible
 * ToVkFormat( fmt ) converts to or VK_FORMAT_UNDEFINED if not possible
 * FromDXGI_FORMAT( DXGI_FORMAT) converts from or UNDEFINED if not possible
 * ToDXGI_FORMAT( fmt ) converts to or DXGI_FORMAT_UNKNOWN if not possible
 * DXGI_FORMATToTypeless( fmt ) returns the DXGI typeless format if possible
 * FromMetal( MTLPixelFormat) converts from or UNDEFINED if not possible
 * ToMetal( fmt) converts to or MTLPixelFormatInvalid if not possible
 *
 *
 * Implementation Details
 * ----------------------
 * Format Namespaces
 * Internally formats are split into sets called namespace with completely
 * different descriptor encodings. The largest is the PACK namespace which can
 * encode a huge range of packed single pixel formats. The enumerations are just
 * the common cases.
 * Each compression family has its own namespace and also colour look up tables.
 * Shared component and various video formats are on the list of things TODO.
 *
 * The namespace size is huge, allowing for many different future formats.
 *
 * PACK namespace
 * The name of the format specifies exactly the channel order with only one
 * factor the PACK special bit.
 * If a format can be encoded word aligned (8, 16, 32, 64 bit alignment) then
 * PACK isn't set and the physical channel is read left to right
 * so R8G8B8A8 is R = PC_0, G = PC_1, B = PC_2, A = PC_3 and can would be read
 * uint8_t* data = ...;
 * R = data[0];
 * G = data[1];
 * B = data[2];
 * A = data[3];
 * If a format can't be simply decoded via word aligned reads then the PACK bit
 * is set and then the names leftsmost element is the lowest bit position going
 * up as you read across the format name to the right.
 * The actual bit size of each channel is read from the descriptor code.
 * so R5G5B5A1 is the first lowest 5 bits being R, next 5 is G then B and the last
 * bit being A.
 * uint16_t data;
 * R = (data >> 0) & 0x1f;
 * G = (data >> 5) & 0x1f;
 * B = (data >> 10) & 0x1f;
 * A = (data >> 15) & 0x1;
 *
 */
RAW_INCLUDE_END( )=====" )