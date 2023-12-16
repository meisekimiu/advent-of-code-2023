#ifndef ADVENT_OF_CODE_DAY11_H
#define ADVENT_OF_CODE_DAY11_H
#include "../include/AdventDay.h"
#include "GalaxyDistances.h"

class Day11 : public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    GalacticDistance sumOfDistancesBetweenGalaxies();
    void setCosmicExpansion(GalacticDistance d);

protected:
    void parseLine(const std::string &line) override;

private:
    GalaxyDistances distances;
};


#endif //ADVENT_OF_CODE_DAY11_H
