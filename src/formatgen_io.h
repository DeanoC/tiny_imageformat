#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

using VFile_Handle = std::FILE*;

enum FileMode {
	Os_FM_Write = 0,
};

inline VFile_Handle VFile_FromFile(char const* path, FileMode mode) {
	char const* fopenMode = mode == Os_FM_Write ? "wb" : "rb";
	VFile_Handle file = std::fopen(path, fopenMode);
	if (!file) {
		std::perror(path);
		std::exit(EXIT_FAILURE);
	}
	return file;
}

inline void VFile_Write(VFile_Handle file, void const* data, size_t size) {
	if (size == 0) {
		return;
	}
	if (std::fwrite(data, 1, size, file) != size) {
		std::perror("fwrite");
		std::exit(EXIT_FAILURE);
	}
}

inline void VFile_Close(VFile_Handle file) {
	if (std::fclose(file) != 0) {
		std::perror("fclose");
		std::exit(EXIT_FAILURE);
	}
}

#define LOGERROR(...) do { std::fprintf(stderr, __VA_ARGS__); std::fputc('\n', stderr); } while (0)

#ifndef ASSERT
#define ASSERT(x) assert(x)
#endif
