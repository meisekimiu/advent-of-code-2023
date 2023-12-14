#ifndef ADVENT_OF_CODE_DAY09_H
#define ADVENT_OF_CODE_DAY09_H
#include "../include/AdventDay.h"
#include "OasisParser.h"

class Day09 : public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    [[nodiscard]] OasisInt sumOfForwardExtrapolatedValues() const;
    [[nodiscard]] OasisInt sumOfBackwardExtrapolatedValues() const;

protected:
    void parseLine(const std::string &line) override;

private:
    OasisParser parser;

    OasisInt sumOfSequences(OasisInt (*unaryOp)(const std::vector<OasisInt> &)) const;
};


#endif //ADVENT_OF_CODE_DAY09_H
