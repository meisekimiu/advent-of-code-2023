#ifndef ADVENT_OF_CODE_DAY10_H
#define ADVENT_OF_CODE_DAY10_H
#include "../include/AdventDay.h"
#include "PipeMaze.h"

class Day10 : public AdventDay {
public:
    int mainPartOne() override;
    [[nodiscard]] unsigned int getMaxDistanceOfMaze() const;

protected:
    void parseLine(const std::string &line) override;

private:
    PipeMaze maze;
};


#endif //ADVENT_OF_CODE_DAY10_H
