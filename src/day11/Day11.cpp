#include "Day11.h"
#include <numeric>
#include <iostream>

int Day11::mainPartOne() {
    readInput("data/day11/input.txt");
    std::cout << sumOfDistancesBetweenGalaxies() << std::endl;
    return EXIT_SUCCESS;
}


int Day11::mainPartTwo() {
    setCosmicExpansion(999999);
    return mainPartOne();
}

void Day11::parseLine(const std::string &line) {
    distances.addLine(line);
}

GalacticDistance Day11::sumOfDistancesBetweenGalaxies() {
    auto d = distances.getDistances();
    return std::accumulate(d.begin(), d.end(), 0lu, std::plus{});
}

void Day11::setCosmicExpansion(GalacticDistance d) {
    distances.cosmicExpansionRate = d;
}

