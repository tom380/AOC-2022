#include "Days.h"

namespace Day13 {
	typedef std::vector<std::string> List;

	List listify(std::string list) {
		if (list.front() == '[') list.erase(list.begin());
		if (list.back() == ']') list.erase(list.end());

		int depth = 0;
		std::string subList = "";
		List splitList;

		for (int i = 0; i < list.size(); i++) {
			subList.push_back(list[i]);
			if (list[i] == '[') depth++;
			else if (list[i] == ']') depth--;
			if (!depth) {
				if (list[i] == ',') subList.clear();
				else if (i == list.size() - 1) splitList.push_back(subList);
				else if (!std::isdigit(list[i + 1])) splitList.push_back(subList);
			}
		}

		return splitList;
	}

	bool operator < (const List left, const List right) {
		const int n = std::min(left.size(), right.size());

		for (int i = 0; i < n; i++) {
			if (left[i].front() != '[' && right[i].back() != ']') {
				if (std::stoi(left[i]) != std::stoi(right[i])) return std::stoi(left[i]) < std::stoi(right[i]);
			}
			else if (listify(left[i]) != listify(right[i])) {
				return listify(left[i]) < listify(right[i]);
			}
		}

		return left.size() < right.size();
	}
}

int Day13::part1(std::string input) {
	std::ifstream file(input);
	std::string left, right;

	int sum = 0;
	for (int i = 1; file >> left >> right; i++) if (listify(left) < listify(right)) sum += i;

	return sum;
}

int Day13::part2(std::string input) {
	std::ifstream file(input);
	std::string list;

	std::vector<List> lists = {listify("[[2]]"), listify("[[6]]")};
	while (file >> list) {
		lists.push_back(listify(list));
	}

	std::sort(lists.begin(), lists.end(), [](List left, List right) {return left < right; });

	int decoderKey = 1;
	for (int i = 0; i < lists.size(); i++) {
		if (lists[i] == listify("[[2]]") || lists[i] == listify("[[6]]")) decoderKey *= i + 1;
	}

	return decoderKey;
}