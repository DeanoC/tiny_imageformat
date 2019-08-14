#include <stdio.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <cfloat>
#include <cmath>
#include "al2o3_vfile/vfile.h"
#include "../include/tiny_imageformat/tinyimageformat_bits.h"
#include "formatgen.h"

// get the compiler to check these are legal include fragments (some we can't check)
#define RAW_INCLUDE_START(x)
#define RAW_INCLUDE_END(x)
#define TinyImageFormat_ASSERT ASSERT
#include "otherimageenums.h"

#undef RAW_INCLUDE_START
#undef RAW_INCLUDE_END

void GenEnums(VFile_Handle file);
void GenStructs(VFile_Handle file);
void GenCount(VFile_Handle file);
void GenQuerys(VFile_Handle file);
void GenFetch(VFile_Handle file);

void IncludeDocs(VFile_Handle file) {
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

static void IncludeOtherImageEnums(VFile_Handle file) {
#define RAW_INCLUDE_START(x) x
	char const *otherEnums =
#include "otherimageenums.h"
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


int main(int argc, char const *argv[]) {

	uint8_t rgbac[4] { 0xF0, 0x0F, 0x0, 0xFF };
	uint32_t* rgba32 = (uint32_t*) rgbac;
	uint8_t r = rgbac[0];
	uint8_t r2 = *rgba32 >> 0;
	uint8_t a = rgbac[3];
	uint8_t a2 = *rgba32 >> 24;

	if(r != r2 || a != a2) {
		LOGERROR("Non Little Endian machine. This currently only generated a header for LE");
		return 10;
	}

	char const header[] =
			"//Auto generated by formatgen on " __DATE__ "\n"
			"#pragma once\n";
	char const header2[] =
			"\n"
	 		"#if __cplusplus\n"
			"#define TIF_CONSTEXPR constexpr\n"
			"#else\n"
			"#define TIF_CONSTEXPR\n"
			"#endif\n"
			"#ifndef  TinyImageFormat_HAVE_UINTXX_T\n"
			"#include <stdint.h> 	// for uint32_t and int64_t\n"
			"#endif\n"
			"#ifndef  TinyImageFormat_HAVE_BOOL\n"
			"#include <stdbool.h>	// for bool\n"
			"#endif\n"
			"#ifndef  TinyImageFormat_ASSERT\n"
			"#include <assert.h>\n"
			"#define  TinyImageFormat_ASSERT assert\n"
			"#endif\n"
			"\n";
	char const suffix[] =
			"#undef TIF_CONSTEXPR\n"
			"\n";
	char const definetxt[] = "#define  TINYIMAGEFORMAT_IMAGEFORMAT_H\n";
	// generate single header
	{

		VFile_Handle file = VFile_FromFile("tinyimageformat.h", Os_FM_Write);
		VFile_Write(file, header, strlen(header));
		IncludeDocs(file);
		VFile_Write(file, definetxt, strlen(definetxt));
		VFile_Write(file, header2, strlen(header2));

		GenEnums(file);
		GenCount(file);

		GenStructs(file);

		GenQuerys(file);

		IncludeOtherImageEnums(file);
		GenFetch(file);
		VFile_Write(file, suffix, strlen(suffix));

		VFile_Close(file);
	}
	// generate multi headers
	{
		{
			VFile_Handle basefile = VFile_FromFile("tinyimageformat_base.h", Os_FM_Write);
			VFile_Write(basefile, header, strlen(header));
			IncludeDocs(basefile);
			VFile_Write(basefile, definetxt, strlen(definetxt));

			GenEnums(basefile);
			GenCount(basefile);
			GenStructs(basefile);

			VFile_Close(basefile);
		}
		char const multiheader2[] = "\n#include \"tinyimageformat_base.h\"\n";
		{
			VFile_Handle queryfile = VFile_FromFile("tinyimageformat_query.h", Os_FM_Write);
			VFile_Write(queryfile, header, strlen(header));
			VFile_Write(queryfile, multiheader2, strlen(multiheader2));
			VFile_Write(queryfile, header2, strlen(header2));

			GenQuerys(queryfile);

			VFile_Write(queryfile, suffix, strlen(suffix));
			VFile_Close(queryfile);
		}
		{
			VFile_Handle fetchfile = VFile_FromFile("tinyimageformat_fetch.h", Os_FM_Write);
			VFile_Write(fetchfile, header, strlen(header));
			VFile_Write(fetchfile, multiheader2, strlen(multiheader2));
			VFile_Write(fetchfile, header2, strlen(header2));

			GenFetch(fetchfile);

			VFile_Write(fetchfile, suffix, strlen(suffix));
			VFile_Close(fetchfile);
		}

		{
			VFile_Handle otherfile = VFile_FromFile("tinyimageformat_apis.h", Os_FM_Write);
			VFile_Write(otherfile, header, strlen(header));
			VFile_Write(otherfile, multiheader2, strlen(multiheader2));

			IncludeOtherImageEnums(otherfile);
			VFile_Close(otherfile);
		}


	}
	return 0;
}