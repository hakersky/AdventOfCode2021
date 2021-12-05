#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

int main() {

	std::ifstream in("input_T.txt", std::ios::in);
	std::vector<int> data;
	bool binFlag = true;
	int binLen = 0;
	std::string gamma, epsilon;

	while (in) {
		char c;
		std::string s;
		do {
			in.get(c);
			if (c != '\n') {
				s.push_back(c);
				if(binFlag)binLen++;
			}
		} while (c != '\n');
		
		if (binFlag)binFlag = false;
		
		if (s.length() > 1) {
			data.push_back(std::stoi(s, 0, 2));
		}
	}

	for (int i = binLen - 1; i >= 0; i--) {
		int zeros_t = 0;
		int ones_t = 0;
		int mask = pow(2, i);
		for (int j = 0; j < data.size(); j++) {
			if (data[j] & mask) ones_t++;
			else zeros_t++;
		}
		std::cout << "0: " << zeros_t << " 1: " << ones_t << "\n";
		if (ones_t > zeros_t) {
			gamma.push_back('1');
			epsilon.push_back('0');
		}
		else {
			gamma.push_back('0');
			epsilon.push_back('1');
		}
	}

	std::cout << "\ngamma: " << gamma << " epsilon: " << epsilon << "\n";

	std::cout << "\nResult: " << std::stoi(gamma, 0, 2) * std::stoi(epsilon, 0 ,2);

	return 0;
}