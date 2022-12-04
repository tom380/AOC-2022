#include "Days.h"

int Day2::part1(std::string input) {
	std::string line;
	std::fstream file(input);

	int totalScore = 0;

	while (getline(file, line)) {
		int roundScore = line.back() - 'C' + 1;

	}

	return 0;
}