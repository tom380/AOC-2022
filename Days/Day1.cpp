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

int Day1::part2(std::string input)
{
    std::string line;
    std::ifstream file(input);

    std::vector<int> calories = { 0 };

    while (getline(file, line)) {
        if (line != "") calories.back() += std::stoi(line);
        else calories.push_back(0);
    }
    file.close();

    std::sort(calories.begin(), calories.end(), std::greater<int>());
    return std::accumulate(calories.begin(),calories.begin()+3,0);
}