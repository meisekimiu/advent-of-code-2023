#include <catch2/catch.hpp>
#include "../../src/day05/Day05.h"
#include "sanity.test.h"
#include <iostream>

TEST_CASE("Day 05 Sanity Checks", "[day05]") {
    Day05 rangeDay;
    Day05 singleDay;

    SECTION("Thing I worked out on paper") {
        rangeDay.readInputString(simpleTestInput);
        const Seed min = rangeDay.getMinimumSeedLocationUsingRanges();
        REQUIRE(min == 10);
    }

    std::vector<Seed> seedz = {1347397244, 12212989, 2916488878, 1034516675, 2821376423, 8776260, 2240804122, 368941186, 824872000, 124877531, 1597965637, 36057332, 4091290431, 159289722, 1875817275, 106230212, 998513229, 159131132, 2671581775, 4213184};

    rangeDay.readInputString(testInput);
    rangeDay.configureStartingSeeds({seedz[0], seedz[1]});
    const Seed resultForRangeOne = rangeDay.getMinimumSeedLocationUsingRanges();
    for (int i = 0; i < 10; i++) {
        const Seed start = seedz[0];
        const Seed length = seedz[1];
        rangeDay.configureStartingSeeds({start, length});
        REQUIRE(resultForRangeOne == rangeDay.getMinimumSeedLocationUsingRanges());
    }
    for (int i = 0; i < seedz.size() * 2; i+=2) {
        const Seed start = seedz[i % seedz.size()];
        const Seed length = seedz[(i+1) % seedz.size()];
        rangeDay.configureStartingSeeds({start, length});
        const Seed minWithRanges = rangeDay.getMinimumSeedLocationUsingRanges();
        REQUIRE(minWithRanges != 0);
    }
}