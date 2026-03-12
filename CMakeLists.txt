cmake_minimum_required(VERSION 3.14)

project(tiny_imageformat LANGUAGES C CXX)

option(MAKE_GENERATOR "Build the header generator" ON)
option(unittests "Build unit tests" OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(tiny_imageformat STATIC
	src/dummy.c
)

target_include_directories(tiny_imageformat
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MAKE_GENERATOR)
	add_executable(generate_tiny_imageformat
		src/formatgen.cpp
		src/formatgen_base.cpp
		src/formatgen_apis.cpp
		src/formatgen_query.cpp
		src/formatgen_decode.cpp
		src/formatgen_encode.cpp
	)

	target_include_directories(generate_tiny_imageformat
		PRIVATE
			${CMAKE_CURRENT_SOURCE_DIR}/include
			${CMAKE_CURRENT_SOURCE_DIR}/src
	)
endif()

if(unittests)
	include(FetchContent)

	FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG v2.13.10
	)
	FetchContent_MakeAvailable(Catch2)

	enable_testing()

	add_executable(test_tiny_imageformat
		tests/runner.cpp
		tests/test_formatcracker.cpp
	)

	target_include_directories(test_tiny_imageformat
		PRIVATE
			${CMAKE_CURRENT_SOURCE_DIR}/include
	)

	target_link_libraries(test_tiny_imageformat
		PRIVATE
			tiny_imageformat
			Catch2::Catch2
	)

	add_test(NAME test_tiny_imageformat COMMAND test_tiny_imageformat)
endif()
