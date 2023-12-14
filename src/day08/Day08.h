#ifndef ADVENT_OF_CODE_DAY08_H
#define ADVENT_OF_CODE_DAY08_H
#include "../include/AdventDay.h"
#include "NodeParser.h"

class Day08 : public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    unsigned int stepsToZzz();
    unsigned long long int ghostStepsFromAToZ();

protected:
    void parseLine(const std::string &line) override;

private:
    NodeParser parser;
};


#endif //ADVENT_OF_CODE_DAY08_H
