#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include "float.h"
#include "math.h"
#include "vfile.h"
#include "../include/tiny_imageformat/tinyimageformat_bits.h"
#include "formatgen.h"

void GenEnums(VFile_Handle file)
{
	char const ifstartmacro[] = "typedef enum TinyImageFormat {\n";
	char const ifmodmacro[] = "\tTinyImageFormat_%s = %d,\n";
	char const ifendmacro[] = "} TinyImageFormat;\n\n";

	char buffer[2048];
#define TinyImageFormat_START_MACRO                            \
	{                                                          \
		VFile_Write(file, ifstartmacro, strlen(ifstartmacro)); \
		uint32_t count = 0;
#define TinyImageFormat_MOD_MACRO(x, y)       \
	sprintf(buffer, ifmodmacro, #x, count++); \
	VFile_Write(file, buffer, strlen(buffer));
#define TinyImageFormat_END_MACRO                      \
	VFile_Write(file, ifendmacro, strlen(ifendmacro)); \
	}
#include "formatgen.h"

	char const logiEnum[] =
		"typedef enum TinyImageFormat_LogicalChannel {\n"
		"\tTinyImageFormat_LC_Red = 0,\n"
		"\tTinyImageFormat_LC_Green = 1,\n"
		"\tTinyImageFormat_LC_Blue = 2,\n"
		"\tTinyImageFormat_LC_Alpha = 3,\n"
		"\tTinyImageFormat_LC_Depth = 0,\n"
		"\tTinyImageFormat_LC_Stencil = 1,\n"
		"\tTinyImageFormat_LC_0 = -1,\n"
		"\tTinyImageFormat_LC_1 = -2,\n"
		"} TinyImageFormat_LogicalChannel;\n\n";

	VFile_Write(file, logiEnum, strlen(logiEnum));

	char const physEnum[] =
		"typedef enum TinyImageFormat_PhysicalChannel {\n"
		"\tTinyImageFormat_PC_0 = 0,\n"
		"\tTinyImageFormat_PC_1 = 1,\n"
		"\tTinyImageFormat_PC_2 = 2,\n"
		"\tTinyImageFormat_PC_3 = 3,\n"
		"\tTinyImageFormat_PC_CONST_0 = -1,\n"
		"\tTinyImageFormat_PC_CONST_1 = -2,\n"
		"} TinyImageFormat_PhysicalChannel;\n\n";
	VFile_Write(file, physEnum, strlen(physEnum));
}

void GenStructs(VFile_Handle file)
{
	char const fetchInput[] =
		"typedef struct TinyImageFormat_DecodeInput {\n"
		"\tunion { void const* pixel; void const* pixelPlane0; };\n"
		"\tunion { void const* lut; void const* pixelPlane1; };\n"
		"\tvoid const* pixelPlane2;\n"
		"\tvoid const* pixelPlane3;\n"
		"\tvoid const* pixelPlane4;\n"
		"\tvoid const* pixelPlane5;\n"
		"\tvoid const* pixelPlane6;\n"
		"\tvoid const* pixelPlane7;\n"
		"\tvoid const* pixelPlane8;\n"
		"\tvoid const* pixelPlane9;\n"
		"} TinyImageFormat_FetchInput;\n\n";
	VFile_Write(file, fetchInput, strlen(fetchInput));

	char const putOutput[] =
		"typedef struct TinyImageFormat_EncodeOutput {\n"
		"\tunion { void * pixel; void * pixelPlane0; };\n"
		"\tvoid * pixelPlane1;\n"
		"\tvoid * pixelPlane2;\n"
		"\tvoid * pixelPlane3;\n"
		"\tvoid * pixelPlane4;\n"
		"\tvoid * pixelPlane5;\n"
		"\tvoid * pixelPlane6;\n"
		"\tvoid * pixelPlane7;\n"
		"\tvoid * pixelPlane8;\n"
		"\tvoid * pixelPlane9;\n"
		"} TinyImageFormat_EncodeOutput;\n\n";
	VFile_Write(file, putOutput, strlen(putOutput));
}

void GenCount(VFile_Handle file)
{
	char buffer[2048];
	// format count
#define TinyImageFormat_START_MACRO uint32_t count = 0;
#define TinyImageFormat_MOD_MACRO(x, y) count++;
#define TinyImageFormat_END_MACRO
#include "formatgen.h"
	char const formatCountF[] = "#define TinyImageFormat_Count %uU \n\n";

	sprintf(buffer, formatCountF, count);
	VFile_Write(file, buffer, strlen(buffer));
}
