#ifndef ADVENT_OF_CODE_DAY02_H
#define ADVENT_OF_CODE_DAY02_H
#include "../include/AdventDay.h"
#include "CubeGame.h"

class Day02 : public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    void addGame(const std::string& line);
    [[nodiscard]] int sumOfValidGameIds(CubeCount red, CubeCount green, CubeCount blue) const;
    [[nodiscard]] int sumOfCubePower()const ;

protected:
    void parseLine(const std::string &line) override;

private:
    std::vector<CubeGame> games;
    std::vector<std::string> lines;
};


#endif //ADVENT_OF_CODE_DAY02_H
