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

    winningNumbers = extractNumbersFromSubstring(line, numbersStart, numbersDivider - numbersStart);
    numbers = extractNumbersFromSubstring(line, numbersDivider, std::string::npos);
}

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
    std::vector<int> intersection(winningNumbers.size());
    auto it = std::set_intersection(winningNumbers.begin(), winningNumbers.end(), numbers.begin(), numbers.end(), intersection.begin());
    intersection.resize(it - intersection.begin());
    if (intersection.empty()) {
        return 0;
    }
    return 1 << (intersection.size() - 1);
}
