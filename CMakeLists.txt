#if building standalone and not specified build tests
option(BUILD_TESTS "Whether to build tests" ON)
include(FetchContent)
FetchContent_Declare( al2o3 GIT_REPOSITORY https://github.com/DeanoC/al2o3 GIT_TAG master )
FetchContent_GetProperties(al2o3)
if(NOT al2o3_POPULATED)
	FetchContent_Populate(al2o3)
	add_subdirectory(${al2o3_SOURCE_DIR} ${al2o3_BINARY_DIR})
endif()

SET_MIN_VERSIONS()
set(LibName tiny_imageformat)
project(${LibName})

set(MAKE_GENERATOR TRUE)
if(MAKE_GENERATOR)
	set(GeneratorSrc
			src/formatgen.cpp
			src/formatgen.h
			src/formatbits.h
			src/otherimageenums.h
			)

	set(GeneratorDeps
			al2o3_platform
			al2o3_cmath
			al2o3_os
			al2o3_vfile
			)
	ADD_CONSOLE_APP(generate_${LibName} "${GeneratorSrc}" "${GeneratorDeps}")
endif()

set(Interface
		tinyimageformat.h )
set(Src
		dummy.c)

set(Deps
		)
ADD_LIB(${LibName} "${Interface}" "${Src}" "${Deps}")

set( Tests
		runner.cpp
		test_formatcracker.cpp
		)
set( TestDeps
		al2o3_catch2
		utils_simple_logmanager
		)
ADD_LIB_TESTS(${LibName} "${Interface}" "${Tests}" "${TestDeps}")

