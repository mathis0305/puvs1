#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include <cmath>

int checksum(int a) {
	if (a < 0) {
		a = a * (-1);
	}
	int len = trunc(log10(a)) + 1;
	int sum = 0;
	while (len > 0) {
		std::cout << a << "\n";
		if (len == 1) {
			sum = sum + a;
			len = len - 1;
		}

		else {
			int i = a / 10;
			int s = i * 10;
			sum = sum + (a - s);
			a = i;
			len = len - 1;
		}
	}
	return sum;
}

TEST_CASE("describe_checksum", "[checksum]") {
	REQUIRE(checksum(12345) == 15);
	REQUIRE(checksum(0) == 0);
	REQUIRE(checksum(10) == 1);
	REQUIRE(checksum(122979) == 30);
	REQUIRE(checksum(-122979) == 30);
}

int main(int argc, char* argv[]) {
	return Catch::Session().run(argc, argv);
}