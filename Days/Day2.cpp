#include "Days.h"

int Day2::part1(std::string input) {
	std::string line;
	std::ifstream file(input);

	int totalScore = 0;

	while (getline(file, line)) {
		totalScore += line.back() - 'X' + 1;

		if (line == "A Y" || line == "B Z" || line == "C X") totalScore += 6;
		else if (line.front() - 'A' == line.back() - 'X') totalScore += 3;
	}

	file.close();
	return totalScore;
}

int Day2::part2(std::string input) {
	std::string line;
	std::ifstream file(input);

	int totalScore = 0;

	while (getline(file, line)) {
		switch (line.back()) {
		case 'X':
			switch (line.front()) {
			case 'A': totalScore += 0 + 3; break;
			case 'B': totalScore += 0 + 1; break;
			case 'C': totalScore += 0 + 2; break;
			} break;
		case 'Y':
			switch (line.front()) {
			case 'A': totalScore += 3 + 1; break;
			case 'B': totalScore += 3 + 2; break;
			case 'C': totalScore += 3 + 3; break;
			} break;
		case 'Z':
			switch (line.front()) {
			case 'A': totalScore += 6 + 2; break;
			case 'B': totalScore += 6 + 3; break;
			case 'C': totalScore += 6 + 1; break;
			} break;
		}
	}

	file.close();
	return totalScore;
}