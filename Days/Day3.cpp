#include "Days.h"

int Day3::part1(std::string input) {
	std::string line;
	std::ifstream file(input);

	int prioritySum = 0;

	while (getline(file, line)) {
		std::string firstComp = line.substr(0, line.size() / 2);
		std::string secondComp = line.substr(line.size() / 2, line.size() - 1);

		int itemType = findCommonChar({ firstComp,secondComp });
		prioritySum += itemType < 'a' ? (itemType - 'A' + 27) : (itemType - 'a' + 1);
	}

	file.close();
	return prioritySum;
}

int Day3::part2(std::string input) {
	std::string line;
	std::ifstream file(input);

	int prioritySum = 0;

	std::string firstSack;
	std::string secondSack;
	std::string thirdSack;

	while (!file.eof()) {
		getline(file, firstSack);
		getline(file, secondSack);
		getline(file, thirdSack);
		
		int itemType = findCommonChar({ firstSack,secondSack,thirdSack });
		prioritySum += itemType < 'a' ? (itemType - 'A' + 27) : (itemType - 'a' + 1);
	}

	file.close();
	return prioritySum;
}

char Day3::findCommonChar(std::vector<std::string> strings) {
	std::string commonChars = strings.front();

	for (std::string s : strings) {
		std::string currCommonChars;
		for (char c : s) {
			for (char d : commonChars) {
				if (c == d) currCommonChars.push_back(c);
			}
		}
		commonChars = currCommonChars;
	}

	return commonChars.front();
}