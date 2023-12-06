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

protected:
    void parseLine(const std::string &line) override;

private:
    PartsGrid grid;
};


#endif //ADVENT_OF_CODE_DAY03_H
