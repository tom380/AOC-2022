#include "Days.h"

int Day6::part1(std::string input) {
	std::string line;
	std::ifstream file(input);

	const int windowSize = 4;
	std::vector<char> window(windowSize);
	for (int i = 0; i < windowSize - 1; i++) {
		file >> window[i];
	}

	for (int i = windowSize - 1; file >> window[i % windowSize]; i++) {
		if (!hasDuplicate(window)) return i + 1;
	}

	file.close();
	return 0;
}

int Day6::part2(std::string input) {
	std::string line;
	std::ifstream file(input);

	const int windowSize = 14;
	std::vector<char> window(windowSize);
	for (int i = 0; i < windowSize - 1; i++) {
		file >> window[i];
	}

	for (int i = windowSize - 1; file >> window[i % windowSize]; i++) {
		if (!hasDuplicate(window)) return i + 1;
	}

	file.close();
	return 0;
}

bool Day6::hasDuplicate(std::vector<char> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i != j && v[i] == v[j]) return true;
		}
	}

	return false;
}