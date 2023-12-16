#ifndef ADVENT_OF_CODE_DAY10_H
#define ADVENT_OF_CODE_DAY10_H
#include "../include/AdventDay.h"
#include "PipeMaze.h"
#include "MazeArea.h"

class Day10 : public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    [[nodiscard]] unsigned int getMaxDistanceOfMaze() const;
    Area getAreaOfMaze();

protected:
    void parseLine(const std::string &line) override;

private:
    PipeMaze maze;
};


#endif //ADVENT_OF_CODE_DAY10_H
