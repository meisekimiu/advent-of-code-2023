#include <catch2/catch.hpp>
#include "../../src/day11/Day11.h"

TEST_CASE("Day 11", "[day11]") {
    Day11 day;

    SECTION("Advent of Code Example Part 1") {
        day.readInputString("...#......\n"
                            ".......#..\n"
                            "#.........\n"
                            "..........\n"
                            "......#...\n"
                            ".#........\n"
                            ".........#\n"
                            "..........\n"
                            ".......#..\n"
                            "#...#.....");

        REQUIRE(day.sumOfDistancesBetweenGalaxies() == 374);
    }
}
