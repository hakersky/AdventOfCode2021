#include <iostream>
#include <fstream>
#include <vector>
#include <string>

	struct board {
		int b[5][5] = {};
	};

bool isWinner(board);
void checkNum(board &, int);
int winnerScore(board);

int main() {

	std::ifstream in("input.txt", std::ios::in);
	std::vector<int> data;
	std::vector<board> boards;
	int j = 0, k = 0, winnerBoard, winnerNum;
	board board_t;

	while (in) {
		char c;
		std::string s, line;

		std::getline(in, line);

		if (line.find(",") != std::string::npos) {
			s.clear();
			for (int i = 0; i <= line.size(); i++) {

				if (line[i] >= '0' && line[i] <= '9') {
					s.push_back(line[i]);
				}
				else {
					data.push_back(std::stoi(s));
					s.clear();
				}

				if (line[i] == '\n') {
					break;
				}
			}
		}
		else if (line.find(" ") != std::string::npos) {
			s.clear();
			for (int i = 0; i <= line.size(); i++) {

				if (line[i] >= '0' && line[i] <= '9') {
					s.push_back(line[i]);
				}
				else if ((line[i] == ' ' || i == line.size()) && !s.empty()) {
					board_t.b[j][k] = std::stoi(s);
					k++;
					if (j == 4 && k == 5) {
						boards.push_back(board_t);
						j = 0;
						k = 0;
					} 
					else if (k == 5) {
						j++;
						k = 0;
					}
					s.clear();
				}

				if (line[i] == '\n') {
					break;
				}
			}
		}
		else {

			continue;
		}
	}

	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < boards.size(); j++) {
			checkNum(boards[j], data[i]);
			if (isWinner(boards[j])) {
				
				std::cout << "Result: " << data[i] * winnerScore(boards[j]);
				
				return 0;;
			}
		}
	}

	return 0;
}

bool isWinner(board b) {
	bool result = false;
	
	for (int i = 0; i < 5; i++) {
		if (b.b[i][0] == -1 && b.b[i][1] == -1 && b.b[i][2] == -1 && b.b[i][3] == -1 && b.b[i][4] == -1) {
			result = true;
			return result;
		}
		if (b.b[0][i] == -1 && b.b[1][i] == -1 && b.b[2][i] == -1 && b.b[3][i] == -1 && b.b[4][i] == -1) {
			result = true;
			return result;
		}
	}
	
	return result;
}

void checkNum(board &b, int val) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (b.b[i][j] == val) {
				b.b[i][j] = -1;
			}
		}
	}
}

int winnerScore(board b) {
	int score = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (b.b[i][j] >= 0) {
				score += b.b[i][j];
			}
		}
	}
	return score;
}