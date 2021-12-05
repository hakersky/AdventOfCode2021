#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>

int main() {

	std::ifstream in("input.txt", std::ios::in);
	std::vector<int> data;
	bool binFlag = true;
	int binLen = 0;
	std::string oxygen, co2;

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

	std::vector<int> temp1 = data;
	std::vector<int> temp2 = data;


	for (int i = binLen - 1; i >= 0; i--) {
		int zeros_t = 0;
		int ones_t = 0;
		int mask = pow(2, i);

		for (int j = 0; j < temp1.size(); j++) {
			if (temp1[j] & mask) ones_t++;
			else zeros_t++;
		}

		if (temp1.size() > 1) {
			for (int j = 0; j < temp1.size(); j++) {
				if (ones_t >= zeros_t) {
					if (!(temp1[j] & mask)) {
						temp1.erase(temp1.begin() + j);
						j--;
					}
				}
				else {
					if (temp1[j] & mask) {
						temp1.erase(temp1.begin() + j);
						j--;
					}
				}
				if (temp1.size() == 1) break;
			}
		}

		zeros_t = 0;
		ones_t = 0;

		for (int j = 0; j < temp2.size(); j++) {
			if (temp2[j] & mask) ones_t++;
			else zeros_t++;
		}

		if (temp2.size() > 1) {
			for (int j = 0; j < temp2.size(); j++) {
				if (ones_t >= zeros_t) {
					if (temp2[j] & mask) {
						temp2.erase(temp2.begin() + j);
						j--;
					}
				}
				else {
					if (!(temp2[j] & mask)) {
						temp2.erase(temp2.begin() + j);
						j--;
					}
				}
				if (temp2.size() == 1)break;
			}
		}
	}

	std::cout << "\nResult: " << temp1[0] * temp2[0];

	return 0;
}