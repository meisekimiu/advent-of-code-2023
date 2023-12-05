#ifndef ADVENT_OF_CODE_SCRATCHCARD_H
#define ADVENT_OF_CODE_SCRATCHCARD_H
#include <string>
#include <vector>
#include <set>

class ScratchCard {
public:
    void addWinningNumber(int number);
    void addNumber(int number);
    void parseLine(const std::string& line);
    [[nodiscard]] std::set<int> getWinningNumbers() const;
    [[nodiscard]] std::set<int> getNumbers() const;
    [[nodiscard]] int getScore() const;

private:
    std::set<int> winningNumbers;
    std::set<int> numbers;

    static std::set<int> extractNumbersFromSubstring(const std::string &line, unsigned long pos, unsigned long length);
};


#endif //ADVENT_OF_CODE_SCRATCHCARD_H
