#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include <cmath>
using namespace std;

double mile_to_kilometer(double m) {
	double km = m * 1.609344;
	return km;
}

int main(int argc, char* argv[]) {
	cout << "Please enter a value in miles:\n";
	double miles;
	cin >> miles;
	cout << miles << " mi are " << mile_to_kilometer(miles) << " km!\n";
	return 0;
}