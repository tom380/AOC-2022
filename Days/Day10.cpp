#include "Days.h"

int Day10::part1(std::string input) {
	std::ifstream file(input);
	std::string instruction;
	int increase;

	int reg = 1;
	std::vector<int> cycleHist;
	cycleHist.push_back(reg);

	while (file >> instruction) {
		if (instruction == "noop") cycleHist.push_back(reg);
		else if (instruction == "addx") {
			file >> increase;
			cycleHist.push_back(reg);
			reg += increase;
			cycleHist.push_back(reg);
		}
	}

	file.close();
	return 20 * cycleHist[20 - 1] + 60 * cycleHist[60 - 1] + 100 * cycleHist[100 - 1] + 140 * cycleHist[140 - 1] + 180 * cycleHist[180 - 1] + 220 * cycleHist[220 - 1];
}

std::string Day10::part2(std::string input) {
	std::ifstream file(input);
	std::string instruction;
	int increase;

	int reg = 1;
	std::string screen = "\n";

	bool isExecuting = false;

	for (int cycle = 1; cycle <= 240; cycle++) {
		screen.push_back(std::abs((cycle - 1) % 40 - reg) > 1 ? '.' : '#');
		if (cycle % 40 == 0) screen.push_back('\n');

		if (isExecuting) {
			reg += increase;
			isExecuting = false;
		}
		else {
			file >> instruction;
			if (instruction == "addx") {
				file >> increase;
				isExecuting = true;
			}
		}
	}

	file.close();
	return screen;
}