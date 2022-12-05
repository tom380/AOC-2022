#include "Days.h"

int Day2::part1(std::string input) {
	std::string line;
	std::fstream file(input);

	int totalScore = 0;

	while (getline(file, line)) {
		totalScore += line.back() - 'X' + 1;

		if (line == "A Y" || line == "B Z" || line == "C X") totalScore += 6;
		else if (line.front() - 'A' == line.back() - 'X') totalScore += 3;
	}

	return totalScore;
}