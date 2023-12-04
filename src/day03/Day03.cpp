#include "Day03.h"
#include <fstream>
#include <iostream>
#include <numeric>

int Day03::mainPartOne() {
    readFile("data/day03/input.txt");
    std::cout << partNumberSum() << std::endl;
    return EXIT_SUCCESS;
}

int Day03::mainPartTwo() {
    readFile("data/day03/input.txt");
    std::cout << gearRatioSum()<< std::endl;
    return EXIT_SUCCESS;
}

void Day03::addLine(const std::string &line) {
    grid.addLine(line);
}

int Day03::partNumberSum() {
    auto numbers = grid.getValidNumbers();
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

void Day03::readFile(const char* path) {
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        addLine(line);
    }
}

int Day03::gearRatioSum() {
    auto gears = grid.getGears();
    return std::transform_reduce(gears.begin(), gears.end(), 0, std::plus{}, [](const Gear &g) {
        return g.getRatio();
    });
}
