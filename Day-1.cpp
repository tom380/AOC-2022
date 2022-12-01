#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string line;
    std::ifstream MyReadFile("input.txt");
    
    int maxCal = 0;
    int curCal = 0;
    
    while (getline (MyReadFile, line)) {
        if (std::atoi(line.c_str()) != 0) {
            curCal += std::atoi(line.c_str());
            //std::cout << std::atoi(line.c_str()) << std::endl;
        }
        else {
            if (curCal > maxCal) maxCal = curCal;
            curCal = 0;
            //std::cout << "newline" << std::endl;
        }
    }
    
    std::cout << maxCal << std::endl;
    
    // Close the file
    MyReadFile.close();
    return 0;
}
