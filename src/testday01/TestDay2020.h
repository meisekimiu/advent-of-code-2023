#ifndef ADVENT_OF_CODE_TESTDAY2020_H
#define ADVENT_OF_CODE_TESTDAY2020_H
#include "../include/AdventDay.h"

// This is a test problem done on November 30th to ensure everything works well.
// The problem itself is the first problem from Advent of Code 2020.

class TestDay2020 : public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    void setExpenses(const std::vector<int>& list);
    int find2020();
    int find2020PartTwo();
    void loadExpenses(const char* filepath);

private:
    std::vector<int> expenses;
};


#endif //ADVENT_OF_CODE_TESTDAY2020_H
