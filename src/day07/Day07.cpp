#include "Day07.h"
#include <iostream>

int Day07::mainPartOne() {
    readInput("data/day07/input.txt");
    std::cout << calculateWinnings() << std::endl;
    return EXIT_SUCCESS;
}

void Day07::parseLine(const std::string &line) {
    parser.parseLine(line);
}

int Day07::calculateWinnings() {
    int rank = 1;
    int winnings = 0;
    while (!parser.hands.empty()) {
        winnings += rank * parser.hands.top().bet;
        parser.hands.pop();
        rank++;
    }
    return winnings;
}
