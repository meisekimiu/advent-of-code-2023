#include <catch2/catch.hpp>
#include "../../src/day10/Day10.h"

TEST_CASE("Day 10", "[day10]") {
    Day10 day;

    SECTION("Advent of Code Example Part 1") {
        day.readInputString("7-F7-\n"
                            ".FJ|7\n"
                            "SJLL7\n"
                            "|F--J\n"
                            "LJ.LJ\n");
        REQUIRE(day.getMaxDistanceOfMaze() == 8);
    }
}
