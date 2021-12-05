#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

	std::ifstream in("input.txt", std::ios::in);
	std::vector<int> data;
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
			data.push_back(std::stoi(s));
		}
	}

	last = data[0] + data[1] + data[2];
	for (int i = 0; i < data.size() - 3; i++) {
		int actual = data[i + 1] + data[i + 2] + data[i + 3];
		if (actual > last) larger++;
		last = actual;
	}

	std::cout << "Result: " << larger;

	return 0;
}