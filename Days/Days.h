#ifndef DAYS_H
#define DAYS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

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

#endif