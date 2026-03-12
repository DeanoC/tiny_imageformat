#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

int main(int argc, char const* argv[]) {
	return Catch::Session().run(argc, (char**)argv);
}
