#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include "vfile.h"
#include "formatgen.h"
/*
 * Implementation Details
 * ----------------------
 * Format Namespaces
 * Internally formats are split into sets called namespace with completely
 * different descriptor encodings. The largest is the PACK namespace which can
 * encode a huge range of packed pixel formats. The enumerations are just
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
 * Future Note: The pack special bit insn't need anymore I think it may be
 *              removed in a future version but its an internal details so won't
 *              affect the API
 *
 */

void GenEnums(VFile_Handle file);
void GenStructs(VFile_Handle file);
void GenCount(VFile_Handle file);
void GenQuerys(VFile_Handle file);
void GenDecode(VFile_Handle file);
void GenEncode(VFile_Handle file);
void GenAPIsEnums(VFile_Handle file);

void IncludeDocs(VFile_Handle file)
{
#define RAW_INCLUDE_START(x) x
	char const *otherEnums =
#include "doc.h"
		"";
#undef RAW_INCLUDE_START

	// skip first ) and last line, artifacts of the include system
	char const *start = otherEnums;
	while (*start != ')')
		start++;

	char const *end = otherEnums + strlen(otherEnums);
	while (*end != 'R')
		end--;

	VFile_Write(file, start + 1, end - start - 1);
}

int main(int argc, char const *argv[])
{

	uint8_t rgbac[4]{0xF0, 0x0F, 0x0, 0xFF};
	uint32_t *rgba32 = (uint32_t *)rgbac;
	uint8_t r = rgbac[0];
	uint8_t r2 = *rgba32 >> 0;
	uint8_t a = rgbac[3];
	uint8_t a2 = *rgba32 >> 24;

	if (r != r2 || a != a2)
	{
		LOGERROR("Non Little Endian machine. This currently only generated a header for LE");
		return 10;
	}

	char const header[] =
		"// Auto generated by formatgen on " __DATE__ "\n"
		"#pragma once\n";

	char const splitguard[] =
		"#if !defined(%s) && !defined(TINYIMAGEFORMAT_IMAGEFORMAT_H)\n"
		"#define %s 1\n";

	char const singleguard[] =
		"#if !defined(TINYIMAGEFORMAT_IMAGEFORMAT_H)\n"
		"#define TINYIMAGEFORMAT_IMAGEFORMAT_H 1\n";

	char const subguard[] =
		"#if !defined(%s)\n"
		"#define %s 1\n";

	char const header2[] =
		"\n"
		"#if __cplusplus > 201402L\n"
		"#define TIF_CONSTEXPR constexpr extern \"C\"\n"
		"#else\n"
		"#define TIF_CONSTEXPR\n"
		"#endif\n"
		"#ifndef  TinyImageFormat_HAVE_UINTXX_T\n"
		"#include <stdint.h> 	// for uint32_t and int64_t\n"
		"#endif\n"
		"#ifndef  TinyImageFormat_HAVE_BOOL\n"
		"#include <stdbool.h>	// for bool\n"
		"#endif\n"
		"#ifndef  TinyImageFormat_HAVE_POWF\n"
		"#include <math.h>	// for powf\n"
		"#endif\n"
		"//TinyImageFormat_ASSERT needs to be constexpr on some platforms\n"
		"#ifndef  TinyImageFormat_ASSERT\n"
		"#define  TinyImageFormat_ASSERT(x)\n"
		"#endif\n"
		"\n";
	char const suffix2[] =
		"#undef TIF_CONSTEXPR\n";

	char const guardclose[] =
		"#endif // %s\n"
		"\n";

	// generate single header
	{

		VFile_Handle file = VFile_FromFile("tinyimageformat.h", Os_FM_Write);
		VFile_Write(file, header, strlen(header));
		VFile_Write(file, singleguard, strlen(singleguard));
		IncludeDocs(file);
		VFile_Write(file, header2, strlen(header2));

		char headerBuffer[2048];
		char guardCloseBuffer[2048];
		sprintf(headerBuffer, subguard, "TINYIMAGEFORMAT_BASE_H_", "TINYIMAGEFORMAT_BASE_H_");
		VFile_Write(file, headerBuffer, strlen(headerBuffer));
		GenEnums(file);
		GenCount(file);
		GenStructs(file);
		sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_BASE_H_");
		VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));

		sprintf(headerBuffer, subguard, "TINYIMAGEFORMAT_QUERY_H_", "TINYIMAGEFORMAT_QUERY_H_");
		VFile_Write(file, headerBuffer, strlen(headerBuffer));
		GenQuerys(file);
		sprintf(guardCloseBuffer, guardclose, "TINYIMAGE_QUERY_H_");
		VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));

		sprintf(headerBuffer, subguard, "TINYIMAGEFORMAT_DECODE_H_", "TINYIMAGEFORMAT_DECODE_H_");
		VFile_Write(file, headerBuffer, strlen(headerBuffer));
		GenDecode(file);
		sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_DECODE_H_");
		VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));

		sprintf(headerBuffer, subguard, "TINYIMAGEFORMAT_ENCODE_H_", "TINYIMAGEFORMAT_ENCODE_H_");
		VFile_Write(file, headerBuffer, strlen(headerBuffer));
		GenEncode(file);
		sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_ENCODE_H_");
		VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));

		sprintf(headerBuffer, subguard, "TINYIMAGEFORMAT_APIS_H_", "TINYIMAGEFORMAT_APIS_H_");
		VFile_Write(file, headerBuffer, strlen(headerBuffer));
		GenAPIsEnums(file);
		sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_APIS_H_");
		VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));

		VFile_Write(file, suffix2, strlen(suffix2));

		sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_H_");
		VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));

		VFile_Close(file);
	}
	// generate multi headers
	{
		{
			VFile_Handle file = VFile_FromFile("tinyimageformat_base.h", Os_FM_Write);
			VFile_Write(file, header, strlen(header));
			char headerBuffer[2048];
			sprintf(headerBuffer, splitguard, "TINYIMAGEFORMAT_BASE_H_", "TINYIMAGEFORMAT_BASE_H_");
			VFile_Write(file, headerBuffer, strlen(headerBuffer));
			IncludeDocs(file);

			GenEnums(file);
			GenCount(file);
			GenStructs(file);

			char guardCloseBuffer[2048];
			sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_BASE_H_");
			VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));

			VFile_Close(file);
		}
		char const multiheader2[] = "\n#include \"tinyimageformat_base.h\"\n";
		{
			VFile_Handle file = VFile_FromFile("tinyimageformat_query.h", Os_FM_Write);
			VFile_Write(file, header, strlen(header));
			char headerBuffer[2048];
			sprintf(headerBuffer, splitguard, "TINYIMAGEFORMAT_QUERY_H_", "TINYIMAGEFORMAT_QUERY_H_");
			VFile_Write(file, headerBuffer, strlen(headerBuffer));
			VFile_Write(file, multiheader2, strlen(multiheader2));
			VFile_Write(file, header2, strlen(header2));

			GenQuerys(file);

			VFile_Write(file, suffix2, strlen(suffix2));
			char guardCloseBuffer[2048];
			sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_QUERY_H_");
			VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));

			VFile_Close(file);
		}
		{
			VFile_Handle file = VFile_FromFile("tinyimageformat_decode.h", Os_FM_Write);
			VFile_Write(file, header, strlen(header));
			char headerBuffer[2048];
			sprintf(headerBuffer, splitguard, "TINYIMAGEFORMAT_DECODE_H_", "TINYIMAGEFORMAT_DECODE_H_");
			VFile_Write(file, headerBuffer, strlen(headerBuffer));
			VFile_Write(file, multiheader2, strlen(multiheader2));
			VFile_Write(file, header2, strlen(header2));

			GenDecode(file);

			VFile_Write(file, suffix2, strlen(suffix2));
			char guardCloseBuffer[2048];
			sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_DECODE_H_");
			VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));
			VFile_Close(file);
		}

		{
			VFile_Handle file = VFile_FromFile("tinyimageformat_encode.h", Os_FM_Write);
			VFile_Write(file, header, strlen(header));
			char headerBuffer[2048];
			sprintf(headerBuffer, splitguard, "TINYIMAGEFORMAT_ENCODE_H_", "TINYIMAGEFORMAT_ENCODE_H_");
			VFile_Write(file, headerBuffer, strlen(headerBuffer));
			VFile_Write(file, multiheader2, strlen(multiheader2));
			VFile_Write(file, header2, strlen(header2));

			GenEncode(file);

			VFile_Write(file, suffix2, strlen(suffix2));
			char guardCloseBuffer[2048];
			sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_ENCODE_H_");
			VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));
			VFile_Close(file);
		}
		{
			VFile_Handle file = VFile_FromFile("tinyimageformat_apis.h", Os_FM_Write);
			VFile_Write(file, header, strlen(header));
			char headerBuffer[2048];
			sprintf(headerBuffer, splitguard, "TINYIMAGEFORMAT_APIS_H_", "TINYIMAGEFORMAT_APIS_H_");
			VFile_Write(file, headerBuffer, strlen(headerBuffer));
			VFile_Write(file, multiheader2, strlen(multiheader2));

			GenAPIsEnums(file);
			VFile_Write(file, suffix2, strlen(suffix2));
			char guardCloseBuffer[2048];
			sprintf(guardCloseBuffer, guardclose, "TINYIMAGEFORMAT_APIS_H_");
			VFile_Write(file, guardCloseBuffer, strlen(guardCloseBuffer));
			VFile_Close(file);
		}
	}
	return 0;
}