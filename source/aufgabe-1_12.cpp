#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include <cmath>
#include <tuple>

double volume(double radius, double height) {
	double vol = (atan(1) * 4) * (radius * radius) * height;
	return vol;
}

double surface(double radius, double height) {
	double sur = (2 * (atan(1) * 4) * (radius * radius)) + (2 * (atan(1) * 4) * radius * height);
	return sur;
}

TEST_CASE("describe_cylinder", "[cylinder]") {
	REQUIRE(volume(4, 8) == Approx(402.12386));
	REQUIRE(surface(4, 8) == Approx(301.59289));

	REQUIRE(volume(1, 1) == Approx(3.14159));
	REQUIRE(surface(1, 1) == Approx(12.56637));

	REQUIRE(volume(100, 500) == Approx(15707963.27));
	REQUIRE(surface(100, 500) == Approx(376991.1184));

	REQUIRE(volume(0, 0) == Approx(0));
	REQUIRE(surface(0, 0) == Approx(0));
}

int main(int argc, char* argv[]) {
	return Catch::Session().run(argc, argv);
}