#include "Day08.h"
#include <iostream>

int Day08::mainPartOne() {
    readInput("data/day08/input.txt");
    std::cout << stepsToZzz() << std::endl;
    return EXIT_SUCCESS;
}

void Day08::parseLine(const std::string &line) {
    parser.parseLine(line);
}

unsigned int Day08::stepsToZzz() {
    return parser.map.stepsToZzz(parser.directions);
}
