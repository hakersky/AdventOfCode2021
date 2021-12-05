#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

	std::ifstream in("input.txt", std::ios::in);
	int last = 0;
	int larger = 0;

	while (in) {
		char c;
		std::string s;
		int actual = 0;
		do {
			in.get(c);
			if (c != '\n') {
				s.push_back(c);
			}
		} while (c != '\n');

		if (s.length() > 1) {
			actual = std::stoi(s);
			if (actual > last)larger++;
			last = actual;
		}
	}

	std::cout << "Result: " << larger - 1;

	return 0;
}