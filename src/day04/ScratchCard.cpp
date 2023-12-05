#include "ScratchCard.h"
#include <regex>
#include <algorithm>

void ScratchCard::addWinningNumber(int number) {
    winningNumbers.insert(number);
}

void ScratchCard::addNumber(int number) {
    numbers.insert(number);
}

void ScratchCard::parseLine(const std::string &line) {
    int numbersStart = static_cast<int>(line.find(':'));
    int numbersDivider = static_cast<int>(line.find('|'));

    extractGameId(line, numbersStart);
    winningNumbers = extractNumbersFromSubstring(line, numbersStart, numbersDivider - numbersStart);
    numbers = extractNumbersFromSubstring(line, numbersDivider, std::string::npos);
}

void ScratchCard::extractGameId(const std::string &line, int numbersStart) { id = *extractNumbersFromSubstring(line, 0, numbersStart).begin(); }

std::set<int> ScratchCard::extractNumbersFromSubstring(const std::string &line, unsigned long pos, unsigned long length) {
    std::set<int> nums;
    std::string numString = line.substr(pos, length);
    for (std::smatch matches; std::regex_search(numString, matches, std::regex("(\\d+)"));) {
        nums.insert(std::stoi(matches[1].str()));
        numString = matches.suffix();
    }
    return nums;
}

std::set<int> ScratchCard::getWinningNumbers() const {
    return winningNumbers;
}

std::set<int> ScratchCard::getNumbers() const {
    return numbers;
}

int ScratchCard::getScore() const {
    int matches = getNumberOfMatches();
    return matches == 0 ? 0 : 1 << (matches - 1);
}

int ScratchCard::getNumberOfMatches() const {
    std::vector<int> intersection(winningNumbers.size());
    auto it = std::set_intersection(winningNumbers.begin(), winningNumbers.end(), numbers.begin(), numbers.end(), intersection.begin());
    return static_cast<int>(it - intersection.begin());
}
