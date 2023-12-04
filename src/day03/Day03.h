#ifndef ADVENT_OF_CODE_DAY03_H
#define ADVENT_OF_CODE_DAY03_H
#include "../include/AdventDay.h"
#include "PartsGrid.h"

class Day03 : public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    void addLine(const std::string& line);
    int partNumberSum();
    int gearRatioSum();

private:
    PartsGrid grid;
    void readFile(const char *path);
};


#endif //ADVENT_OF_CODE_DAY03_H
