#define CATCH_CONFIG_RUNNER
#include "al2o3_catch2/catch2.hpp"

int main(int argc, char const *argv[]) {
	return Catch::Session().run(argc, (char**)argv);
}
