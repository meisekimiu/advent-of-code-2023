#ifndef ADVENT_OF_CODE_DAY06_H
#define ADVENT_OF_CODE_DAY06_H
#include "../include/AdventDay.h"
#include "RaceParser.h"

class Day06 : public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    int productOfPossibleWinTimes();
    void parseSingleNumber(bool n);

protected:
    void parseLine(const std::string &line) override;

private:
    RaceParser parser;
};


#endif //ADVENT_OF_CODE_DAY06_H
