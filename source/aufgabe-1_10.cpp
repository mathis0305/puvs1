#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include <cmath>

int sum_multiples(int a) {
	int sum = 0;
	for (int i = 1; i < (a+1); i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum = sum + i;
		}
	}
	return sum;
}

TEST_CASE("describe_sum_multiples", "[sum_multiples]") {
	REQUIRE(sum_multiples(1000) == 234168);
	REQUIRE(sum_multiples(15) == 60);
	REQUIRE(sum_multiples(3) == 3);
	REQUIRE(sum_multiples(1) == 0);
}

int main(int argc, char* argv[]) {
	return Catch::Session().run(argc, argv);
}