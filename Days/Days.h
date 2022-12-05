#ifndef DAYS_H
#define DAYS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Day1 {
public:
	static int part1(std::string input);
	static int part2(std::string input);
};

class Day2 {
public:
	static int part1(std::string input);
	static int part2(std::string input);
};

class Day3 {
public:
	static int part1(std::string input);
	static int part2(std::string input);
private:
	static char findCommonChar(std::vector<std::string> strings);
};

#endif