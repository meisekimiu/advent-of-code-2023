#ifndef ADVENT_OF_CODE_DAY04_H
#define ADVENT_OF_CODE_DAY04_H
#include <string>
#include <vector>
#include "../include/AdventDay.h"
#include "ScratchCard.h"

class Day04: public AdventDay {
public:
    int mainPartOne() override;
    void parseLine(const std::string &line);
    [[nodiscard]] int totalCardWinnings() const;

private:
    std::vector<ScratchCard> cards;
    void readFile(const char *path);
};


#endif //ADVENT_OF_CODE_DAY04_H
