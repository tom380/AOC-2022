#include "Days.h"

namespace Day9 {
	struct Pos {
		Pos(int x = 0, int y = 0) { this->x = x; this->y = y; }
		int x;
		int y;

	};

	bool operator == (const Pos& pos1, const Pos& pos2) {
		return pos1.x == pos2.x && pos1.y == pos2.y;
	}

	Pos operator - (const Pos& pos1, const Pos& pos2) {
		return Pos(pos1.x - pos2.x, pos1.y - pos2.y);
	}

	void operator += (Pos& pos1, const Pos& pos2) {
		pos1.x += pos2.x; pos1.y += pos2.y;
	}

	bool operator > (const Pos& pos, const int& length) {
		return std::abs(pos.x) > length || abs(pos.y) > length;
	}

	bool operator < (const Pos& pos1, const Pos& pos2) {
		if (pos1.x < pos2.x) return true;
		else if (pos1.x > pos2.x) return false;
		else if (pos1.y < pos2.y) return true;
		else return false;
	}

	Pos norm(Pos& pos) {
		return Pos((pos.x < 0) ? -1 : (pos.x > 0), (pos.y < 0) ? -1 : (pos.y > 0));
	}
}

int Day9::part1(std::string input) {
	char direction;
	int steps;
	std::ifstream file(input);

	Pos head;
	Pos tail;

	std::vector<Pos> tracker;
	tracker.push_back(tail);

	while (file >> direction) {
		file >> steps;

		for (int i = 0; i < steps; i++) {
			switch (direction) {
			case 'U':
				head.y++; break;
			case 'D':
				head.y--; break;
			case 'R':
				head.x++; break;
			case 'L':
				head.x--; break;
			}

			Pos diff = head - tail;
			if (diff > 1) tail += norm(diff);

			tracker.push_back(tail);
		}
	}

	//Erase duplicates
	std::sort(tracker.begin(), tracker.end());
	tracker.erase(std::unique(tracker.begin(), tracker.end()), tracker.end());

	file.close();
	return tracker.size();
}

int Day9::part2(std::string input) {
	char direction;
	int steps;
	std::ifstream file(input);

	std::vector<Pos> knots(10);

	std::vector<Pos> tracker;
	tracker.push_back(knots.back());

	while (file >> direction) {
		file >> steps;

		for (int i = 0; i < steps; i++) {
			switch (direction) {
			case 'U':
				knots.front().y++; break;
			case 'D':
				knots.front().y--; break;
			case 'R':
				knots.front().x++; break;
			case 'L':
				knots.front().x--; break;
			}

			for (int j = 1; j < knots.size(); j++) {
				Pos diff = knots[j - 1] - knots[j];
				if (diff > 1) knots[j] += norm(diff);
			}

			tracker.push_back(knots.back());
		}
	}

	//Erase duplicates
	std::sort(tracker.begin(), tracker.end());
	tracker.erase(std::unique(tracker.begin(), tracker.end()), tracker.end());

	file.close();
	return tracker.size();
}