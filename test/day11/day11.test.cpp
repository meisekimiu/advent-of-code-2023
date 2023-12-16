#include <catch2/catch.hpp>
#include "../../src/day11/Day11.h"

TEST_CASE("Day 11", "[day11]") {
    Day11 day;
    const std::string input = "...#......\n"
                              ".......#..\n"
                              "#.........\n"
                              "..........\n"
                              "......#...\n"
                              ".#........\n"
                              ".........#\n"
                              "..........\n"
                              ".......#..\n"
                              "#...#.....";
    day.readInputString(input);

    SECTION("Advent of Code Example Part 1") {
        REQUIRE(day.sumOfDistancesBetweenGalaxies() == 374);
    }
    SECTION("Advent of Code Example Part 2") {
        SECTION("10x expansion factor") {
            day.setCosmicExpansion(9);
            REQUIRE(day.sumOfDistancesBetweenGalaxies() == 1030);
        }
        SECTION("1000x expansion factor") {
            day.setCosmicExpansion(99);
            REQUIRE(day.sumOfDistancesBetweenGalaxies() == 8410);
        }
    }
}
