#include "Days.h"

int Day7::part1(std::string input) {
	std::string line;
	std::ifstream commandPrompt(input);

	const int maxSize = 1e5;
	std::vector<int> dirSizes;

	getline(commandPrompt, line); //skip $ cd /
	dirSizes.push_back(scanDir(commandPrompt, dirSizes));

	int sum = 0;
	for (int size : dirSizes) {
		if (size <= maxSize) sum += size;
	}

	commandPrompt.close();
	return sum;
}

int Day7::part2(std::string input) {
	std::string line;
	std::ifstream commandPrompt(input);

	const int driveSize = 7e7;
	const int programSize = 3e7;
	std::vector<int> dirSizes;

	getline(commandPrompt, line); //skip $ cd /
	int rootSize = scanDir(commandPrompt, dirSizes);
	dirSizes.push_back(rootSize);
	int freeSpace = programSize - (driveSize - rootSize);

	commandPrompt.close();

	std::sort(dirSizes.begin(), dirSizes.end());
	for (int size : dirSizes) {
		if (size > freeSpace) return size;
	}
}

int Day7::scanDir(std::ifstream& commandPrompt, std::vector<int>& dirSizes) {
	std::string line;
	getline(commandPrompt, line); //skip ls

	int dirSize = 0;

	while (getline(commandPrompt, line)) {
		if (line.back() == '.') break;
		else if (std::isdigit(line.front())) {
			int delimPos = line.find(' ');
			dirSize += std::stoi(line.substr(0, delimPos));
		}
		else if (line[2] == 'c') dirSize += scanDir(commandPrompt, dirSizes);
	}

	dirSizes.push_back(dirSize);
	return dirSize;
}