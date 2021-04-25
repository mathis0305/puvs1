#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include <cmath>

int gcd(int a, int b) {
	int r = 1;
	while (r != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

bool is_prime(long long p) {
	if (p < 2) {
		return false;
	}

	if (p == 2) {
		return true;
	}

	for (int i = 2; i < p; i++) {
		if (p % i == 0) {
			return false;
		}
	}
	return true;
}

TEST_CASE("describe_is_prime", "[is_prime]") {
	REQUIRE(is_prime(1) == false);
	REQUIRE(is_prime(3) == true);
	REQUIRE(is_prime(0) == false);
	REQUIRE(is_prime(100000000000) == false);
	REQUIRE(is_prime(19986419) == true);
	REQUIRE(is_prime(561) == false);
	REQUIRE(is_prime(7) == true);
}

int main(int argc, char* argv[]) {
	return Catch::Session().run(argc, argv);
}