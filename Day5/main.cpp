#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int board[1000][1000] = {};

void drawLine(int [], int []);
int countOverlaps();

int main() {

	std::ifstream in("input.txt", std::ios::in);
	
	while (in) {
		std::string s, line;

		std::getline(in, line);

		int x[2] = {};
		int y[2] = {};
		int m = 0, n = 0;

		s.clear();
		for (int i = 0; i <= line.size(); i++) {

			if (line[i] >= '0' && line[i] <= '9') {
				s.push_back(line[i]);
			}
			else if (line[i] == ',') {
				x[m] = std::stoi(s);
				s.clear();
			}
			else if (line[i] == ' ' && !s.empty()) {
				y[m] = std::stoi(s);
				m++;
				s.clear();
			} else if (i == line.size() && !s.empty()) {
				y[m] = std::stoi(s);
				m = 0;
				s.clear();
				drawLine(x, y);
			}
		}
	}

	std::cout << "\nResult: " << countOverlaps();

	return 0;
}

void drawLine(int x[], int y[]) {
	if (x[0] == x[1]) {
		for (int i = std::min(y[0], y[1]); i <= std::max(y[0], y[1]); i++) {
			board[x[0]][i]++;
		}
	}
	else if (y[0] == y[1]) {
		for (int i = std::min(x[0], x[1]); i <= std::max(x[0], x[1]); i++) {
			board[i][y[0]]++;
		}
	}
}
int countOverlaps() {
	int lines = 0;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (board[i][j] > 1) lines++;
		}
	}

	return lines;
}