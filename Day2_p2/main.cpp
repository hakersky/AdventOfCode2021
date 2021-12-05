#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {

	std::ifstream in("input.txt", std::ios::in);
	std::vector<int> data;
	int horizontal = 0;
	int depth = 0;
	int val = 0;
	int aim = 0;

	while (in) {
		std::string line;
		std::getline(in, line);

		if (!line.find("forward")) {
			val = line.back() - 48;
			horizontal += val;
			depth += aim * val;
		}
		else if (!line.find("down")) {
			val = line.back() - 48;
			aim += val;
		}
		else if (!line.find("up")) {
			val = line.back() - 48;
			aim -= val;
		}
	}

	std::cout << "Result: " << horizontal * depth;

	return 0;
}