#include <catch2/catch.hpp>
#include "../../src/day09/Day09.h"

TEST_CASE("Day 09", "[day09]") {
    Day09 day;

    SECTION("Advent of Code Example: Part 1") {
        day.readInputString("0 3 6 9 12 15\n"
                            "1 3 6 10 15 21\n"
                            "10 13 16 21 30 45");
        REQUIRE(day.sumOfExtrapolatedValues() == 114);
    }
}