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

class Day4 {
public:
	static int part1(std::string input);
	static int part2(std::string input);
};

class Day5 {
public:
	static std::string part1(std::string input);
	static std::string part2(std::string input);
};

class Day6 {
public:
	static int part1(std::string input);
	static int part2(std::string input);
private:
	static bool hasDuplicate(std::vector<char> v);
};

class Day7 {
public:
	static int part1(std::string input);
	static int part2(std::string input);
private:
	static int scanDir(std::ifstream& commandPrompt, std::vector<int>& dirSizes);
};

#endif