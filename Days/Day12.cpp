#include "Days.h"

namespace Day12 {
	struct Pos {
		Pos(int row = 0, int column = 0) {
			this->row = row;
			this->column = column;
		}

		bool isInBounds(int upBounds[2]) {
			return row < upBounds[0] && row >=0 && column < upBounds[1] && column >= 0;
		}

		friend bool operator == (const Pos& pos1, const Pos& pos2) {
			return pos1.row == pos2.row && pos1.column == pos2.column;
		}

		friend bool operator != (const Pos& pos1, const Pos& pos2) {
			return !(pos1 == pos2);
		}

		friend std::ostream& operator << (std::ostream& os, const Pos & pos) {
			os << "[" << pos.row << "," << pos.column << "]";
			return os;
		}

		Pos north() { return Pos(row + 1, column + 0); }
		Pos east()  { return Pos(row + 0, column + 1); }
		Pos south() { return Pos(row - 1, column + 0); }
		Pos west()  { return Pos(row + 0, column - 1); }

		int row;
		int column;
	};

	typedef std::vector<Pos> Path;
}

int Day12::part1(std::string input) {
	std::ifstream file(input);
	std::string line;

	std::vector<std::string> map;
	while (getline(file, line)) map.push_back(line);
	int bounds[2] = { map.size(),map.front().size() };

	Pos begin;
	Pos endPos;
	for (int row = 0; row < bounds[0]; row++) {
		for (int column = 0; column < bounds[1]; column++) {
			char c = map[row][column];
			if (c == 'S') {
				begin = Pos(row, column);
				map[row][column] = 'a';
			}
			if (c == 'E') {
				endPos = Pos(row, column);
				map[row][column] = 'z';
			}
		}
	}

	std::vector<Path> paths;
	paths.push_back({ begin });
	std::vector<Pos> trail;
	trail.push_back(begin);

	bool endFound = false;
	while (!endFound) {
		std::vector<Path> newPaths;
		for (Path path : paths) {
			Pos north = path.back().north();
			Pos east  = path.back().east();
			Pos south = path.back().south();
			Pos west  = path.back().west();

			//std::cout << (std::find(path.begin(), path.end(), north) == path.end()) << std::endl;

			if (north.isInBounds(bounds) &&
				north != trail.back() &&
				std::find(trail.begin(), trail.end(), north) == trail.end() &&
				map[path.back().row][path.back().column] + 1 >= map[north.row][north.column]) {
				Path newPath = path;
				newPath.push_back(north);
				trail.push_back(north);
				newPaths.push_back(newPath);
				if (north == endPos) endFound = true;
			}
			if (east.isInBounds(bounds) &&
				east != trail.back() &&
				std::find(trail.begin(), trail.end(), east) == trail.end() &&
				map[path.back().row][path.back().column] + 1 >= map[east.row][east.column]) {
				Path newPath = path;
				newPath.push_back(east);
				trail.push_back(east);
				newPaths.push_back(newPath);
				if (east == endPos) endFound = true;
			}
			if (south.isInBounds(bounds) &&
				south != trail.back() &&
				std::find(trail.begin(), trail.end(), south) == trail.end() &&
				map[path.back().row][path.back().column] + 1 >= map[south.row][south.column]) {
				Path newPath = path;
				newPath.push_back(south);
				trail.push_back(south);
				newPaths.push_back(newPath);
				if (south == endPos) endFound = true;
			}
			if (west.isInBounds(bounds) &&
				west != trail.back() &&
				std::find(trail.begin(), trail.end(), west) == trail.end() &&
				map[path.back().row][path.back().column] + 1 >= map[west.row][west.column]) {
				Path newPath = path;
				newPath.push_back(west);
				trail.push_back(west);
				newPaths.push_back(newPath);
				if (west == endPos) endFound = true;
			}

		}

		paths = newPaths;
		//for (Path path : paths) {
		//	std::cout << path.back() << std::endl;
		//	if (path == paths.back()) std::cout << std::endl;
		//}
	}

	Path shortest;
	for (Path path : paths) {
		if (path.back() == endPos) {
			shortest = path;
			//for (Pos pos : path) {
			//	std::cout << pos << std::endl;
			//}
			break;
		}
	}
	/*std::cout << std::endl;*/

	//for (int row = 0; row < bounds[0]; row++) {
	//	for (int column = 0; column < bounds[1]; column++) {
	//		char c = '.';
	//		if (Pos(row, column) == endPos) c = 'E';
	//		else if (std::find(shortest.begin(), shortest.end(), Pos(row, column)) != shortest.end()) {
	//			int vPos = std::find(shortest.begin(), shortest.end(), Pos(row, column)) - shortest.begin();
	//			if (shortest[vPos].north() == shortest[vPos + 1]) c = 'v';
	//			if (shortest[vPos].east()  == shortest[vPos + 1]) c = '>';
	//			if (shortest[vPos].south() == shortest[vPos + 1]) c = '^';
	//			if (shortest[vPos].west()  == shortest[vPos + 1]) c = '<';
	//		}
	//		std::cout << c;
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;

	file.close();
	return shortest.size() -1;
}


int Day12::part2(std::string input) {
	std::ifstream file(input);
	std::string line;

	std::vector<std::string> map;
	while (getline(file, line)) map.push_back(line);
	int bounds[2] = { map.size(),map.front().size() };

	Pos begin;
	Pos endPos;
	for (int row = 0; row < bounds[0]; row++) {
		for (int column = 0; column < bounds[1]; column++) {
			char c = map[row][column];
			if (c == 'E') {
				begin = Pos(row, column);
				map[row][column] = 'z';
			}
		}
	}

	std::vector<Path> paths;
	paths.push_back({ begin });
	std::vector<Pos> trail;
	trail.push_back(begin);

	bool endFound = false;
	while (!endFound) {
		std::vector<Path> newPaths;
		for (Path path : paths) {
			Pos north = path.back().north();
			Pos east = path.back().east();
			Pos south = path.back().south();
			Pos west = path.back().west();

			//std::cout << (std::find(path.begin(), path.end(), north) == path.end()) << std::endl;

			if (north.isInBounds(bounds) &&
				north != trail.back() &&
				std::find(trail.begin(), trail.end(), north) == trail.end() &&
				map[path.back().row][path.back().column] - 1 <= map[north.row][north.column]) {
				Path newPath = path;
				newPath.push_back(north);
				trail.push_back(north);
				newPaths.push_back(newPath);
				if (map[north.row][north.column] == 'a') { endFound = true; endPos = north; }
			}
			if (east.isInBounds(bounds) &&
				east != trail.back() &&
				std::find(trail.begin(), trail.end(), east) == trail.end() &&
				map[path.back().row][path.back().column] - 1 <= map[east.row][east.column]) {
				Path newPath = path;
				newPath.push_back(east);
				trail.push_back(east);
				newPaths.push_back(newPath);
				if (map[east.row][east.column] == 'a') { endFound = true; endPos = north; }
			}
			if (south.isInBounds(bounds) &&
				south != trail.back() &&
				std::find(trail.begin(), trail.end(), south) == trail.end() &&
				map[path.back().row][path.back().column] - 1 <= map[south.row][south.column]) {
				Path newPath = path;
				newPath.push_back(south);
				trail.push_back(south);
				newPaths.push_back(newPath);
				if (map[south.row][south.column] == 'a') { endFound = true; endPos = north; }
			}
			if (west.isInBounds(bounds) &&
				west != trail.back() &&
				std::find(trail.begin(), trail.end(), west) == trail.end() &&
				map[path.back().row][path.back().column] - 1 <= map[west.row][west.column]) {
				Path newPath = path;
				newPath.push_back(west);
				trail.push_back(west);
				newPaths.push_back(newPath);
				if (map[west.row][west.column] == 'a') { endFound = true; endPos = north; }
			}

		}

		paths = newPaths;
		//for (Path path : paths) {
		//	std::cout << path.back() << std::endl;
		//	if (path == paths.back()) std::cout << std::endl;
		//}
	}

	Path shortest;
	for (Path path : paths) {
		if (path.back() == endPos) {
			shortest = path;
			//for (Pos pos : path) {
			//	std::cout << pos << std::endl;
			//}
			break;
		}
	}
	//std::cout << std::endl;

	//for (int row = 0; row < bounds[0]; row++) {
	//	for (int column = 0; column < bounds[1]; column++) {
	//		char c = '.';
	//		if (Pos(row, column) == endPos) c = 'S';
	//		else if (std::find(shortest.begin(), shortest.end(), Pos(row, column)) != shortest.end()) {
	//			int vPos = std::find(shortest.begin(), shortest.end(), Pos(row, column)) - shortest.begin();
	//			if (shortest[vPos].north() == shortest[vPos + 1]) c = 'v';
	//			if (shortest[vPos].east() == shortest[vPos + 1]) c = '>';
	//			if (shortest[vPos].south() == shortest[vPos + 1]) c = '^';
	//			if (shortest[vPos].west() == shortest[vPos + 1]) c = '<';
	//		}
	//		std::cout << c;
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;

	file.close();
	return shortest.size() - 1;
}