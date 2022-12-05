#include "Days.h"

int Day4::part1(std::string input) {
	std::string line;
	std::ifstream file(input);

	int containingPairs = 0;

	int lowA;	//Upper bound elf A
	int upA;	//Lower bound elf A
	int lowB;	//Upper bound elf B
	int upB;	//Lower bound elf B
	char d;		//Throwaway for delimiters

	while (file >> lowA >> d >> upA >> d >> lowB >> d >> upB) {
		if ((lowA >= lowB && upA <= upB) || (lowA <= lowB && upA >= upB)) containingPairs++;
	}

	file.close();
	return containingPairs;
}

int Day4::part2(std::string input) {
	std::string line;
	std::ifstream file(input);

	int overlapPairs = 0;

	int lowA;	//Upper bound elf A
	int upA;	//Lower bound elf A
	int lowB;	//Upper bound elf B
	int upB;	//Lower bound elf B
	char d;		//Throwaway for delimiters

	while (file >> lowA >> d >> upA >> d >> lowB >> d >> upB) {
		if (!(upA < lowB || lowA > upB)) overlapPairs++;
	}

	file.close();
	return overlapPairs;
}