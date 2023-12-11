#include "Day06.h"
#include <iostream>
#include <stdexcept>
#include <numeric>

int Day06::mainPartOne() {
    readInput("data/day06/input.txt");
    std::cout << productOfPossibleWinTimes() << std::endl;
    return EXIT_SUCCESS;
}

int Day06::mainPartTwo() {
    parseSingleNumber(true);
    readInput("data/day06/input.txt");
    std::cout << productOfPossibleWinTimes() << std::endl;
    return EXIT_SUCCESS;
}

void Day06::parseLine(const std::string &line) {
    parser.readLine(line);
}

int Day06::productOfPossibleWinTimes() {
    const auto races = parser.generateRaces();
    if (races.empty()) {
        throw std::runtime_error("No input provided");
    }
    return std::transform_reduce(races.begin(), races.end(), 1, std::multiplies<>(), [](const Race &r) {
       return r.numberOfWinningRaces();
    });
}

void Day06::parseSingleNumber(bool n) {
    parser.readSingleNumber = n;
}
