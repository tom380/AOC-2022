#include "Days.h"

static struct Pos {
	int x;
	int y;
	Pos(int x = 0, int y = 0) : x(x), y(y) {};
	Pos(std::string s) {
		std::stringstream ss(s);
		int x, y;
		char comma;
		ss >> x >> comma >> y;
		this->x = x;
		this->y = y;
	}

	Pos operator - (Pos pos) {
		return Pos(x - pos.x, y - pos.y);
	}

	Pos operator + (Pos pos) {
		return Pos(x + pos.x, y + pos.y);
	}

	bool operator == (Pos pos) {
		return x == pos.x && y == pos.y;
	}

	void operator += (Pos pos) {
		x += pos.x;
		y += pos.y;
	}

	Pos operator * (int& i) {
		return Pos(x * i, y * i);
	}

	Pos normalized() {
		int x = (this->x < 0) ? -1 : ((this->x > 0) ? 1 : 0);
		int y = (this->y < 0) ? -1 : ((this->y > 0) ? 1 : 0);
		return Pos(x, y);
	}

	template <typename T> T& on(std::vector<std::vector<T>>& map) {
		return map[x][y];
	}
	template <typename T> bool isInBounds(std::vector<std::vector<T>>& map) {
		return x < map.size() && y < map[0].size() && x >= 0 && y >= 0;
	}
};

static std::vector<std::vector<Pos>> readPaths(std::ifstream& file) {
	std::string string;
	std::vector<Pos> path;
	std::vector<std::vector<Pos>> paths;
	bool end = false;
	while (file >> string) {
		if (string == "->") end = false;
		else {
			if (end) {
				paths.push_back(path);
				path.clear();
			}
			path.push_back(Pos(string));
			end = true;
		}
	}
	paths.push_back(path);

	return paths;
}

static void drawPaths(std::vector<std::vector<Pos>>& paths, std::vector<std::vector<char>>& map) {
	for (std::vector<Pos> path : paths) {
		for (int i = 1; i < path.size(); i++) {
			Pos direction = path[i - 1] - path[i];
			int distance = direction.x + direction.y;
			Pos step = direction.normalized();

			for (int j = 0; j <= abs(distance); j++) {
				int x = path[i].x + step.x * j;
				int y = path[i].y + step.y * j;
				map[x][y] = '#';
			}
		}
	}
}

int Day14::part1(std::string input) {
	std::ifstream file(input);

	std::vector<std::vector<Pos>> paths = readPaths(file);

	Pos max;
	for (std::vector<Pos> path : paths) {
		for (Pos pos : path) {
			if (pos.x > max.x) max.x = pos.x;
			if (pos.y > max.y) max.y = pos.y;
		}
	}

	std::vector<char> row(max.y + 2, '.');
	std::vector<std::vector<char>> map(max.x + 2, row);
	map[500][0] = '+';

	drawPaths(paths, map);

	int sandCount = 0;

	while (true) {
		Pos sand(500, 0);
		while (true) {
			if (!(sand + Pos(0, 1)).isInBounds(map)) goto exitloop;
			if ((sand + Pos(0, 1)).on(map) == '.') sand += Pos(0, 1);
			else if ((sand + Pos(-1, 1)).on(map) == '.') sand += Pos(-1, 1);
			else if ((sand + Pos(1, 1)).on(map) == '.') sand += Pos(1, 1);
			else break;
		}
		sand.on(map) = 'o';
		sandCount++;
	}
	exitloop:

	return sandCount;
}

int Day14::part2(std::string input) {
	std::ifstream file(input);

	std::vector<std::vector<Pos>> paths = readPaths(file);

	Pos max;
	for (std::vector<Pos> path : paths) {
		for (Pos pos : path) {
			if (pos.x > max.x) max.x = pos.x;
			if (pos.y > max.y) max.y = pos.y;
		}
	}

	std::vector<char> row(max.y + 2, '.');
	row.push_back('#');
	std::vector<std::vector<char>> map(max.x + max.y, row);
	map[500][0] = '+';

	drawPaths(paths, map);

	int sandCount = 0;

	while (true) {
		Pos sand(500, 0);
		while (true) {
			if (!(sand + Pos(0, 1)).isInBounds(map)) goto exitloop;
			if ((sand + Pos(0, 1)).on(map) == '.') sand += Pos(0, 1);
			else if ((sand + Pos(-1, 1)).on(map) == '.') sand += Pos(-1, 1);
			else if ((sand + Pos(1, 1)).on(map) == '.') sand += Pos(1, 1);
			else break;
		}
		sand.on(map) = 'o';
		sandCount++;
		if (sand == Pos(500, 0)) goto exitloop;
	}
	exitloop:

	return sandCount;
}