#include "Days.h"

std::string Day5::part1(std::string input) {
	std::string line;
	std::ifstream file(input);

	const int stacksAmount = 9;

	std::vector<std::vector<char>> stacks(stacksAmount);
	while (getline(file,line)) {
		if (line[1] == '1') break;
		for (int i = 0; i < stacksAmount; i++) {
			char crate = line[1 + i * 4];
			if (crate != ' ') stacks[i].insert(stacks[i].begin(), crate);
		}
	}
	
	getline(file, line);

	int amount;		//Amount of crates to move
	int from;		//From where to move
	int to;			//To where to move
	std::string tmp;//Throwaway for inbetween words
	while (file >> tmp >> amount >> tmp >> from >> tmp >> to) {
		stacks[to - 1].insert(stacks[to - 1].end(), stacks[from - 1].rbegin(), stacks[from - 1].rbegin() + amount);
		stacks[from - 1].resize(stacks[from - 1].size() - amount);
	}
	
	std::string topCrates;
	for (std::vector<char> stack : stacks) if (!stack.empty()) topCrates.push_back(stack.back());

	file.close();
	return topCrates;
}

std::string Day5::part2(std::string input) {
	std::string line;
	std::ifstream file(input);

	const int stacksAmount = 9;

	std::vector<std::vector<char>> stacks(stacksAmount);
	while (getline(file, line)) {
		if (line[1] == '1') break;
		for (int i = 0; i < stacksAmount; i++) {
			char crate = line[1 + i * 4];
			if (crate != ' ') stacks[i].insert(stacks[i].begin(), crate);
		}
	}

	getline(file, line);

	int amount;		//Amount of crates to move
	int from;		//From where to move
	int to;			//To where to move
	std::string tmp;//Throwaway for inbetween words
	while (file >> tmp >> amount >> tmp >> from >> tmp >> to) {
		stacks[to - 1].insert(stacks[to - 1].end(), stacks[from - 1].end() - amount, stacks[from - 1].end());
		stacks[from - 1].resize(stacks[from - 1].size() - amount);
	}

	std::string topCrates;
	for (std::vector<char> stack : stacks) if (!stack.empty()) topCrates.push_back(stack.back());

	file.close();
	return topCrates;
}