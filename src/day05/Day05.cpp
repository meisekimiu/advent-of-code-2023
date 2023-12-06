#include "Day05.h"
#include <iostream>
#include <algorithm>

int Day05::mainPartOne() {
    readInput("data/day05/input.txt");
    std::cout << getMinimumSeedLocation() << std::endl;
    return EXIT_SUCCESS;
}

void Day05::parseLine(const std::string &line) {
    parser.parse(line);
}

Seed Day05::getMinimumSeedLocation() {
    auto seeds = parser.startingSeeds;
    auto &map = parser.map;
    std::vector<Seed> locations(seeds.size());
    std::transform(seeds.begin(), seeds.end(), locations.begin(), [&map](int seed) {
        return map.locateSeed(seed);
    });
    Seed minimum = *std::min_element(locations.begin(), locations.end());
    return minimum;
}