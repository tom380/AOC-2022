#include <string>
#include <iostream>
#include "Days/Days.h"

int main() {
	std::cout << std::ifstream("title.txt").rdbuf() << std::endl << std::endl;

	std::cout <<
		"Day 1: Calorie Counting" << std::endl <<
		"\tPart 1: " << Day1::part1("Inputs/day1.txt") << std::endl <<
		"\tPart 2: " << Day1::part2("Inputs/day1.txt") << std::endl;

	return 0;
}