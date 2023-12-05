#include "Day04.h"
#include <numeric>
#include <fstream>
#include <iostream>

void Day04::parseLine(const std::string &line) {
    ScratchCard c;
    c.parseLine(line);
    cards.push_back(c);
}

int Day04::totalCardWinnings() const {
    return std::transform_reduce(cards.begin(), cards.end(), 0, std::plus{}, [](const ScratchCard& c) {
       return c.getScore();
    });
}

int Day04::mainPartOne() {
    readFile("data/day04/input.txt");
    std::cout << totalCardWinnings() << std::endl;
    return EXIT_SUCCESS;
}

void Day04::readFile(const char *path) {
    std::ifstream file(path);
    std::string line;
    while(std::getline(file, line)) {
        parseLine(line);
    }
}
