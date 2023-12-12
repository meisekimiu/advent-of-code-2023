#ifndef ADVENT_OF_CODE_DAY07_H
#define ADVENT_OF_CODE_DAY07_H
#include "../include/AdventDay.h"
#include "CardsParser.h"

class Day07 : public AdventDay {
public:
    int mainPartOne() override;
    int calculateWinnings();

protected:
    void parseLine(const std::string &line) override;

private:
    CardsParser parser;
};


#endif //ADVENT_OF_CODE_DAY07_H
