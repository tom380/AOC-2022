#include <string>
#include <iostream>
#include "Days/Days.h"

int main() {
	std::cout << std::ifstream("title.txt").rdbuf() << std::endl << std::endl;

	std::cout <<
		"--- Day 1: Calorie Counting ---" << std::endl <<
		"\tPart 1: " << Day1::part1("Inputs/day1.txt") << std::endl <<
		"\tPart 2: " << Day1::part2("Inputs/day1.txt") << std::endl << std::endl <<

		"--- Day 2: Rock Paper Scissors ---" << std::endl <<
		"\tPart 1: " << Day2::part1("Inputs/day2.txt") << std::endl <<
		"\tPart 2: " << Day2::part2("Inputs/day2.txt") << std::endl << std::endl <<

		"--- Day 3: Rucksack Reorganization ---" << std::endl <<
		"\tPart 1: " << Day3::part1("Inputs/day3.txt") << std::endl <<
		"\tPart 2: " << Day3::part2("Inputs/day3.txt") << std::endl << std::endl <<

		"--- Day 4: Camp Cleanup ---" << std::endl <<
		"\tPart 1: " << Day4::part1("Inputs/day4.txt") << std::endl <<
		"\tPart 2: " << Day4::part2("Inputs/day4.txt") << std::endl << std::endl <<

		"--- Day 5: Supply Stacks ---" << std::endl <<
		"\tPart 1: " << Day5::part1("Inputs/day5.txt") << std::endl <<
		"\tPart 2: " << Day5::part2("Inputs/day5.txt") << std::endl << std::endl <<

		"--- Day 6: Tuning Trouble ---" << std::endl <<
		"\tPart 1: " << Day6::part1("Inputs/day6.txt") << std::endl <<
		"\tPart 2: " << Day6::part2("Inputs/day6.txt") << std::endl << std::endl <<

		"--- Day 7: No Space Left On Device ---" << std::endl <<
		"\tPart 1: " << Day7::part1("Inputs/day7.txt") << std::endl <<
		"\tPart 2: " << Day7::part2("Inputs/day7.txt") << std::endl << std::endl;

	return 0;
}