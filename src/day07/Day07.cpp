#include "Day07.h"
#include <iostream>

int Day07::mainPartOne() {
    readInput("data/day07/input.txt");
    std::cout << calculateWinnings() << std::endl;
    return EXIT_SUCCESS;
}

int Day07::mainPartTwo() {
    useJokers(true);
    return mainPartOne();
}

void Day07::parseLine(const std::string &line) {
    parser.parseLine(line);
}

unsigned int Day07::calculateWinnings() {
    unsigned int rank = 1;
    unsigned int winnings = 0;
    while (!parser.hands.empty()) {
        winnings += rank * parser.hands.top().bet;
        parser.hands.pop();
        rank++;
    }
    return winnings;
}

void Day07::useJokers(bool j) {
    parser.useJokers = j;
}
