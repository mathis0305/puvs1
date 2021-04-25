#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include <cmath>

long long factorial(long long a) {
	if (a > 0) {
		return a * factorial(a - 1);
	}
	if (a == 0) {
		return 1;
	}
}



TEST_CASE("describe_factorial", "[factorial]") {
	REQUIRE(factorial(3) == 6);
	REQUIRE(factorial(1) == 1);
	REQUIRE(factorial(11) == 39916800);
	REQUIRE(factorial(14) == 87178291200);
	REQUIRE(factorial(20) == 2432902008176640000);
	REQUIRE(factorial(0) == 1);
}

int main(int argc, char* argv[]) {
	return Catch::Session().run(argc, argv);
}