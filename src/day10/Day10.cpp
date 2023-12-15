#include "Day10.h"
#include <iostream>

int Day10::mainPartOne() {
    readInput("data/day10/input.txt");
    std::cout << getMaxDistanceOfMaze() << std::endl;
    return EXIT_SUCCESS;
}

void Day10::parseLine(const std::string &line) {
    maze.addLine(line);
}

unsigned int Day10::getMaxDistanceOfMaze() const {
    return maze.getMazePoints().size() / 2;
}
