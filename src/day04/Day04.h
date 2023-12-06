#ifndef ADVENT_OF_CODE_DAY04_H
#define ADVENT_OF_CODE_DAY04_H
#include <string>
#include <vector>
#include <unordered_map>
#include "../include/AdventDay.h"
#include "ScratchCard.h"

class Day04: public AdventDay {
public:
    int mainPartOne() override;
    int mainPartTwo() override;
    [[nodiscard]] int totalCardWinnings() const;
    [[nodiscard]] int totalCardCopies() const;
    void parseLine(const std::string &line) override;

private:
    std::vector<ScratchCard> cards;

};


#endif //ADVENT_OF_CODE_DAY04_H
