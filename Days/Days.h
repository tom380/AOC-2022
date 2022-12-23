#ifndef DAYS_H
#define DAYS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <sstream>

namespace Day1 {
	int part1(std::string input);
	int part2(std::string input);
}

namespace Day2 {
	int part1(std::string input);
	int part2(std::string input);
}

namespace Day3 {
	int part1(std::string input);
	int part2(std::string input);
	char findCommonChar(std::vector<std::string> strings);
}

namespace Day4 {
	int part1(std::string input);
	int part2(std::string input);
}

namespace Day5 {
	std::string part1(std::string input);
	std::string part2(std::string input);
}

namespace Day6 {
	int part1(std::string input);
	int part2(std::string input);
	bool hasDuplicate(std::vector<char> v);
}

namespace Day7 {
	int part1(std::string input);
	int part2(std::string input);
	int scanDir(std::ifstream& commandPrompt, std::vector<int>& dirSizes);
}

namespace Day8 {
	int part1(std::string input);
	int part2(std::string input);
}

namespace Day9 {
	int part1(std::string input);
	int part2(std::string input);
}

namespace Day10 {
	int part1(std::string input);
	std::string part2(std::string input);
}

namespace Day11 {
	uint64_t part1(std::string input);
	uint64_t part2(std::string input);
}

namespace Day12 {
	int part1(std::string input);
	int part2(std::string input);
}

#endif