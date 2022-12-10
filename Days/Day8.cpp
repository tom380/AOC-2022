#include "Days.h"

#define VIS true
#define NVIS false

int Day8::part1(std::string input) {
	std::ifstream file(input);
	std::vector<std::vector<int>> treeHeights;

	std::string line;
	while (getline(file, line)) {
		std::vector<int> row;
		for (char treeHeight : line) {
			row.push_back(treeHeight - '0');
		}
		treeHeights.push_back(row);
	}

	std::vector<std::vector<bool>> visTrees;

	for (int row = 0; row < treeHeights.size(); row++) {
		std::vector<bool> visTreesRow;
		for (int column = 0; column < treeHeights[row].size(); column++) {
			int thisHeight = treeHeights[row][column];

			bool north, east, south, west;
			north = east = south = west = VIS;

			for (int i = 1; i < treeHeights.size(); i++) {
				if (row - i >= 0 && treeHeights[row - i][column] >= thisHeight) north = NVIS;
				if (column + i < treeHeights[row].size() && treeHeights[row][column + i] >= thisHeight) east = NVIS;
				if (row + i < treeHeights.size() && treeHeights[row + i][column] >= thisHeight) south = NVIS;
				if (column - i >= 0 && treeHeights[row][column - i] >= thisHeight) west = NVIS;
			}

			visTreesRow.push_back(north || east || south || west);
		}
		visTrees.push_back(visTreesRow);
	}

	int sum = 0;

	for (std::vector<bool> v : visTrees) {
		for (bool b : v) {
			if (b) sum++;
		}
	}

	file.close();
	return sum;
}