#include "Day05.h"
#include <iostream>
#include <algorithm>
#include <cassert>

int Day05::mainPartOne() {
    readInput("data/day05/input.txt");
    std::cout << getMinimumSeedLocation() << std::endl;
    return EXIT_SUCCESS;
}

int Day05::mainPartTwo() {
    readInput("data/day05/input.txt");
    std::cout << getMinimumSeedLocationUsingRanges() << std::endl;
    return EXIT_SUCCESS;
}

void Day05::parseLine(const std::string &line) {
    parser.parse(line);
}

Seed Day05::getMinimumSeedLocation() {
    auto &seeds = parser.startingSeeds;
    auto &map = parser.map;
    std::vector<Seed> locations(seeds.size());
    std::transform(seeds.begin(), seeds.end(), locations.begin(), [&map](int seed) {
        return map.locateSeed(seed);
    });
    Seed minimum = *std::min_element(locations.begin(), locations.end());
    return minimum;
}

Seed Day05::getMinimumSeedLocationUsingRanges() {
    const auto &seeds = parser.startingSeeds;
    Seed minimum = UINT32_MAX;
    for (int i = 0; i < seeds.size(); i += 2)  {
        std::vector<SeedRange> locatedRanges = parser.map.locateRange({seeds[i], seeds[i+1]});
        for (const SeedRange &sr : locatedRanges) {
            minimum = std::min(minimum, sr.start);
        }
    }
    return minimum;
}

void Day05::configureStartingSeeds(const std::vector<Seed> &seeds) {
    parser.startingSeeds = seeds;
}
