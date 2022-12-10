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

	for (std::vector<bool> visTreesRow : visTrees) {
		for (bool visTree : visTreesRow) {
			if (visTree) sum++;
		}
	}

	file.close();
	return sum;
}

int Day8::part2(std::string input) {
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

	std::vector<std::vector<int>> treeScores;

	for (int row = 0; row < treeHeights.size(); row++) {
		std::vector<int> treeScoresRow;
		for (int column = 0; column < treeHeights[row].size(); column++) {
			int thisHeight = treeHeights[row][column];

			bool northBlocked, eastBlocked, southBlocked, westBlocked;
			northBlocked = eastBlocked = southBlocked = westBlocked = false;
			int northScore, eastScore, southScore, westScore;
			northScore = eastScore = southScore = westScore = 0;

			for (int i = 1; i < treeHeights.size(); i++) {
				if (!northBlocked && row - i >= 0) {
					northScore++;
					if (treeHeights[row - i][column] >= thisHeight) northBlocked = true;
				}
				if (!eastBlocked && column + i < treeHeights[row].size()) {
					eastScore++;
					if (treeHeights[row][column + i] >= thisHeight) eastBlocked = true;
				}
				if (!southBlocked && row + i < treeHeights.size()) {
					southScore++;
					if(treeHeights[row + i][column] >= thisHeight) southBlocked = true;
				}
				if (!westBlocked && column - i >= 0) {
					westScore++;
					if (treeHeights[row][column - i] >= thisHeight) westBlocked = true;
				}
			}

			treeScoresRow.push_back(northScore * eastScore * southScore * westScore);
		}
		treeScores.push_back(treeScoresRow);
	}

	int highestScore = 0;

	for (std::vector<int> treeScoresRow : treeScores) {
		for (int currentScore : treeScoresRow) {
			if (currentScore > highestScore) highestScore = currentScore;
		}
	}

	file.close();
	return highestScore;
}