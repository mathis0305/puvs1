#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include <cmath>

double fract(double a) {
	while (a >= 1.0) {
		a = a - 1.0;
	}
	return a;
}

TEST_CASE("describe_fract", "[fract]") {
	//REQUIRE(fract(1.2345) == Approx(0.2345));
	REQUIRE(fract(3.14159) == Approx(0.14159));
	REQUIRE(fract(123456789.123456789) == Approx(0.123456789));
	REQUIRE(fract(0.8765) == Approx(0.8765));
	REQUIRE(fract(1) == Approx(0.0));
}

int main(int argc, char* argv[]) {
	return Catch::Session().run(argc, argv);
}