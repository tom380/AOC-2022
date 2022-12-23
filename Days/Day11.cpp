#include "Days.h"

namespace Day11 {
	class Monkey {
		std::vector<int> items;
		std::function<void(uint64_t&)> inspect;
		int testNumber;
		int throwTrue;
		int throwFalse;
		int worryManager;

		uint64_t inspectCount = 0;

	public:
		Monkey(std::vector<int> items, std::function<void(uint64_t&)> operation, int testNumber, int throwTrue, int throwFalse, int worryManager = 3) {
			this->items = items;
			this->inspect = operation;
			this->testNumber = testNumber;
			this->throwTrue = throwTrue;
			this->throwFalse = throwFalse;
			this->worryManager = worryManager;
		}

		void catchItem(int item) {
			items.push_back(item);
		}

		void throwItems(std::vector<Monkey>& monkeys) {
			for (uint64_t item : items) {
				inspect(item);
				inspectCount++;
				item /= worryManager;
				item %= (5 * 2 * 19 * 7 * 17 * 13 * 3 * 11);
				if (item % testNumber == 0) monkeys[throwTrue].catchItem(item);
				else monkeys[throwFalse].catchItem(item);
			}
			items.clear();
		}

		int getInspectCount() {
			return inspectCount;
		}
	};
}

uint64_t Day11::part1(std::string input) {
	std::vector<Monkey> monkeys;
	monkeys.push_back(Monkey({ 98, 89, 52 }, [](uint64_t& x) -> void { x *= 2; }, 5, 6, 1));
	monkeys.push_back(Monkey({ 57, 95, 80, 92, 57, 78 }, [](uint64_t& x) -> void { x *= 13; }, 2, 2, 6));
	monkeys.push_back(Monkey({ 82, 74, 97, 75, 51, 92, 83 }, [](uint64_t& x) -> void { x += 5; }, 19, 7, 5));
	monkeys.push_back(Monkey({ 97, 88, 51, 68, 76 }, [](uint64_t& x) -> void { x += 6; }, 7, 0, 4));
	monkeys.push_back(Monkey({ 63 }, [](uint64_t& x) -> void { x += 1; }, 17, 0, 1));
	monkeys.push_back(Monkey({ 94, 91, 51, 63 }, [](uint64_t& x) -> void { x += 4; }, 13, 4, 3));
	monkeys.push_back(Monkey({ 61, 54, 94, 71, 74, 68, 98, 83 }, [](uint64_t& x) -> void { x += 2; }, 3, 2, 7));
	monkeys.push_back(Monkey({ 90, 56 }, [](uint64_t& x) -> void { x *= x; }, 11, 3, 5));

	for (int i = 0; i < 20; i++) {
		for (Monkey& monkey : monkeys) {
			monkey.throwItems(monkeys);
		}
	}

	std::vector<uint64_t> inspectCounts;
	for (Monkey& monkey : monkeys) {
		inspectCounts.push_back(monkey.getInspectCount());
	}

	std::sort(inspectCounts.begin(), inspectCounts.end(), std::greater<uint64_t>());

	uint64_t monkeyBuisness = inspectCounts[0] * inspectCounts[1];

	return monkeyBuisness;
}

uint64_t Day11::part2(std::string input) {
	std::vector<Monkey> monkeys;
	monkeys.push_back(Monkey({ 98, 89, 52 }, [](uint64_t& x) -> void { x *= 2; }, 5, 6, 1, 1));
	monkeys.push_back(Monkey({ 57, 95, 80, 92, 57, 78 }, [](uint64_t& x) -> void { x *= 13; }, 2, 2, 6, 1));
	monkeys.push_back(Monkey({ 82, 74, 97, 75, 51, 92, 83 }, [](uint64_t& x) -> void { x += 5; }, 19, 7, 5, 1));
	monkeys.push_back(Monkey({ 97, 88, 51, 68, 76 }, [](uint64_t& x) -> void { x += 6; }, 7, 0, 4, 1));
	monkeys.push_back(Monkey({ 63 }, [](uint64_t& x) -> void { x += 1; }, 17, 0, 1, 1));
	monkeys.push_back(Monkey({ 94, 91, 51, 63 }, [](uint64_t& x) -> void { x += 4; }, 13, 4, 3, 1));
	monkeys.push_back(Monkey({ 61, 54, 94, 71, 74, 68, 98, 83 }, [](uint64_t& x) -> void { x += 2; }, 3, 2, 7, 1));
	monkeys.push_back(Monkey({ 90, 56 }, [](uint64_t& x) -> void { x *= x; }, 11, 3, 5, 1));

	for (int i = 0; i < 10000; i++) {
		for (Monkey& monkey : monkeys) {
			monkey.throwItems(monkeys);
		}
	}

	std::vector<uint64_t> inspectCounts;
	for (Monkey& monkey : monkeys) {
		inspectCounts.push_back(monkey.getInspectCount());
	}

	std::sort(inspectCounts.begin(), inspectCounts.end(), std::greater<uint64_t>());

	uint64_t monkeyBuisness = inspectCounts[0] * inspectCounts[1];

	return monkeyBuisness;
}