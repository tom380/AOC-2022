#include "Days.h"

int Day1::part1(std::string input)
{
    std::string line;
    std::ifstream file(input);

    int maxCal = 0;
    int curCal = 0;
    
    while (getline (file, line)) {
        if (line != "") {
            curCal += std::stoi(line);
        }
        else {
            if (curCal > maxCal) maxCal = curCal;
            curCal = 0;
        }
    }

    file.close();
    return maxCal;
}