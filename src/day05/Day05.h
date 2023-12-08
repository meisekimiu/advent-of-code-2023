#ifndef ADVENT_OF_CODE_DAY05_H
#define ADVENT_OF_CODE_DAY05_H
#include "../include/AdventDay.h"
#include "SeedParser.h"

class Day05 : public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    Seed getMinimumSeedLocation();
    Seed getMinimumSeedLocationUsingRanges();
    void configureStartingSeeds(const std::vector<Seed> &seeds);

protected:
    void parseLine(const std::string &line) override;

private:
    SeedParser parser;
};


#endif //ADVENT_OF_CODE_DAY05_H
