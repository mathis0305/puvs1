#include <iostream>

int main() {

	int r = 0;
	int i = 40;
	while (r != 20) {
		
		for (int d = 2; d < 21; d++) {

			if (i % d == 0) {
				r += 1;
			}
			else {
				break;
			}
		}

		if (r == 19) {
			
			std::cout << "This is the number: " << i << "\n";
			break;
		}
		
		i += 20;
		r = 0;


	}

}