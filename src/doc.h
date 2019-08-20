RAW_INCLUDE_START( R"=====( )
/* TinyImageFormat is a library about the encodings of pixels typically
 * encountered in real time graphics.
 *
 * Like modern graphics API it is enumeration based but it also provides an API
 * for reasoning about that enumeration programmatically.
 *
 * Additionally it provide ways of accessing pixels encoded in the specified
 * format for most pixel formats. The hope is eventually to get decode to 100%
 * but not there yet (119 out of 193 currently).
 * This allows you to effectively read/write a large amount of image data.
 *
 * To assist with working with graphics APIs converters to and from Vulkan,
 * D3D12 and Metal. These are self contained and do not require the actual APIs.
 *
 * Available as either a single header or a version made of 6 headers split into
 * functional groups. Use one style or the other but they don't mix.
 *
 * These files are large due to unrolling and large switches. Functions are
 * inlined, allowing the compiler to eliminate and collapse when possible,
 * however particularly the Encode/Decode functions aren't near as fast as they
 * could be if heavily optimised for specific formats/layouts.
 *
 * Whilst not optimal due to number of formats it supports, it intends to be
 * fast enough that in many cases it will be fine.
 *
 * Internally every format has a descriptor packed into a 64 bit code word.
 * This code word is used to generate the header and it isn't used by the API
 * itself, as its been 'burnt' out by the code generator but it can be used at
 * runtime if desired and in future its intended to be used for exotic packed
 * formats that don't get there own enumeration value but can be expressed
 * via a descriptor.
 *
 * Where possible for C++ users functions are constexpr.
 *
 * It is MIT licensed and borrows/builds on code/specs including but not
 * limited to
 * Microsoft's Chris Walbourn DXTextureTool
 * Rygerous public domain Half to float (and vice versa) code
 * Khronos DFD specifications
 * Khronos Vulkan Specification
 * Microsoft D3D11/D3D12 Specifications
 * Apple Metal documentation
 * DDS Loaders from various sources (Humus, Confetti FX, DXTextureTool)
 *
 * TODO
 * ----
 * Test CLUT formats and add encode clause
 * Add shared component i.e. G8R8G8B8 4:2:x formats
 * Add Multi plane formats
 * Add compressed format decoders
 * Add Block copy (for updating compressed formats)
 * Add functions that work on descriptor codes directly
 * Add UFLOAT 6 and 7 bit support
 * Optional SIMD decode/encode functions
 * More tests
 *
 * Definitions
 * -----------
 *
 * Pixel
 * We define a pixel as upto 4 channels representing a single 'colour'
 * Its may not be addressable directly but as blocks of related pixels.
 * When decode/encoding pixels are presented to the API as 4 floats or doubles.
 *
 * Logical Channels (TinyImageFormat_LogicalChannel)
 * Logical channel are the usual way you would ask for a particular channel,
 * so asking about LC_Red while get you data for the red channel, however its
 * actually physically encoded in the data.
 *
 * Physical Channels (TinyImageFormat_PhysicalChannel)
 * Physical channels are the inverse of logical channels, that have no meaning
 * beyond the position in the data itself.
 *
 * Both Logical and Physical channels support returning constant 0 or 1
 *
 * Blocks
 * A block is the smallest addressable element this format refers to. Blocks
 * have up to 3 dimensions (though no format currently uses the 3rd).
 * Blocks are always at least byte aligned.
 * For single pixel formats this will be 1x1x1. For something like R1 it would
 * be 8x1x1 (8 single bits for 8 pixels).
 * For block compressed format a common value is 4x4x1.
 * A block for shared channels or very tightly packed this is how many pixels
 * are combined into one addressable unit.
 *
 * API
 * ---
 * The primary enumeration is simply TinyImageFormat, everything else supports
 * this enum.
 * All functions, enums etc. are prefixed with TinyImageFormat_, All functions
 * also take the format as first parameter. These are often removed in the api
 * docs to save space.
 *
 * Defines
 * -------
 * TinyImageFormat_Count - how many formats in total
 * TinyImageFormat_MaxPixelCountOfBlock - maximum number of pixels in a block
 * 									- for any format (for static decode buffer allocation)
 *
 * Enums
 * -----
 * TinyImageFormat - Count entries, one for each format supported
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
 * Structs
 * -------
 * TinyImageFormat_DecodeInput
 *   - pixel or pixelPlane0 - pixel data ptr or pixel data ptr for plane 0
 *   - lut or pixelPlane1 - Look Up Table ptr for CLUT formats or pixel plane 1
 *	 - pixelPlane2 to pixelPlane 9 - 7 more planes ptrs
 * TinyImageFormat_EncodeOutput
 *   - pixel or pixelPlane0 - pixel data ptr or pixel data ptr for plane 0
 *	 - pixelPlane2 to pixelPlane 9 - 8 more planes ptrs

 * Query Functions
 * -----------
 * Code - uint64_t with the internal descriptor code
 * Name  - Human C string with the name of this fmt
 * FromName - lookup the format given the name as a C String (fast)
 * IsDepthOnly - true if just a depth channel
 * IsStencilOnly - true if just a stencil channel
 * IsDepthAndStencil - if has both depth and stencil channel
 * IsCompressed - true if its a compressed format (aka block)
 * IsCLUT - true if data is index into a CLUT (Colour Look Up Table)
 * IsFloat - is the data in floating point
 * IsNormalised - return true if data will be within 0 to 1 or -1 to 1
 * IsSigned - does the data include negatives
 * IsSRGB - is the data encoded using sRGB non linear encoding
 * IsHomogenous - is the encoding the same for every channel
 * WidthOfBlock - How many pixels in the x dimension for a block
 * HeightOfBlock - How many pixels in the y dimension for a block
 * DepthOfBlock 	- How many pixels in the z dimension for a block
 * PixelCountOfBlock - How many pixels in total for a block
 * BitSizeOfBlock - How big in bits is a single block.
 * ChannelCount - How many channels are actually encoded
 *
 * Logical Channel Functions
 * -------------------------
 * ChannelBitWidth( logical channel ) - how wide in bits is the channel
 * Min( logical channel ) - minimum possible value for the channel
 * Max(  logical channel ) - maximum possible value for the channel
 * LogicalChannelToPhysical( logical channel )
 * 											- what physical channel is the logical channel stored in
 * 											- or constant 0 or 1 if its not physically stored
 *
 * Pixel Decoder Functions (X = F or D version, use F if possible as its faster)
 * -----------------------
 * CanDecodeLogicalPixelsX - Can DecodeLogicalPixelsX work with this format?
 * DecodeLogicalPixelsX( width in blocks, FetchInput, out pixels)
 * 		 - pixels should be a pointer to 4 * PixelCounfOfBlack float/doubles
 * 		 - does full decode and remapping into logical channels include constants.
 *     - Returned result can be used directly as RGBA floating point data
 *     - Input pointers are updated are used, so can be passed back in for
 *     - next set of pixel decoding if desired.
 *     - For CLUT formats in.pixel should be the packed pixel data and in.lut is
 *		 - the lookuptable in R8G8B8A8 format of 2^Pbits entries
 *     - For all others in.pixel should be the packed pixel data
 * Pixel Decoder Helper Functions
 * -----------------------
 * UFloat6AsUintToFloat - returns the value stored as a 6 bit UFloat
 * UFloat7AsUintToFloat - returns the value stored as a 7 bit UFloat
 * UFloat10AsUintToFloat - returns the value stored as a 10 bit UFloat
 * UFloat11AsUintToFloat - returns the value stored as a 11 bit UFloat
 * SharedE5B9G9R9UFloatToFloats - return the pixel stored in shared
 * 															- shared 5 bit exponent,  9 bit mantissa for RGB
 * HalfAsUintToFloat - returns the value stored as a 16 bit SFloat
 * BFloatAsUintToFloat - returns the value stored as a 16 bit BFloat
 * LookupSRGB - returns the value for an 8 bit sRGB encoded value
 *
 * Pixel Encoder Functions (X = F or D version, use F if possible as its faster)
 * -----------------------
 * CanEncodeLogicalPixelsX - Can EncodeLogicalPixelsX work with this format?
 * EncodeLogicalPixelsX( width in blocks, in pixels, PutOutput)
 * 		 - pixels should be a pointer to 4 * PixelCounfOfBlack float/doubles
 * 		 - does full encode and remapping into logical channels
 *     - Output pointers are updated are used, so can be passed back in for
 *     - next set of pixel encoding if desired.
 *     - out.pixel is where colour information should be stored
 *
 * Pixel Encoder Helper Functions
 * -----------------------
 * FloatToUFloat6AsUint - Encodes float into  a 6 bit UFloat
 * FloatToUFloat7AsUint - Encodes float into  a 7 bit UFloat
 * FloatToUFloat10AsUint - Encodes float into a 10 bit UFloat
 * FloatToUFloat11AsUint - Encodes float into  11 bit UFloat
 * FloatRGBToRGB9E5AsUint32 - Encodes a float RGB into RGB9E5
 * FloatToHalfAsUint - Encodes a float into a 16 bit SFloat
 * FloatToBFloatAsUint -  Encodes a float into a 16 bit BFloat
 * FloatToSRGB - encodes a float to sRGB assuming input is 0-1
 *
 * Physical Channel Functions (in general use the Logical Channels)
 * ------------------
 * ChannelBitWidthAtPhysical( phys channel ) - how wide in bits for this channel
 * MinAtPhysical( phys channel ) - min possible value for this channel
 * MaxAtPhysical( phys channel ) - max possible value for this channel
 * PhysicalChannelToLogical(phys channel)
 * 											- what logical channel does a physical channel map to.
 * 											- Or a constant 0 or 1
 *
 * Graphics API Functions
 * ------------------
 * FromVkFormat( VkFormat ) - converts from or UNDEFINED if not possible
 * ToVkFormat - converts to or VK_FORMAT_UNDEFINED if not possible
 * FromDXGI_FORMAT( DXGI_FORMAT) converts from or UNDEFINED if not possible
 * ToDXGI_FORMAT - converts to or DXGI_FORMAT_UNKNOWN if not possible
 * DXGI_FORMATToTypeless - returns the DXGI typeless format if possible
 * FromMetal( MTLPixelFormat ) - converts from or UNDEFINED if not possible
 * ToMetal - converts to or MTLPixelFormatInvalid if not possible
 *
 *
 */
RAW_INCLUDE_END( )=====" )