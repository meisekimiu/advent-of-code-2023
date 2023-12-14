#include <catch2/catch.hpp>
#include "../../src/day09/Day09.h"

TEST_CASE("Day 09", "[day09]") {
    Day09 day;

    SECTION("Advent of Code Examples") {
        std::string input = "0 3 6 9 12 15\n"
                            "1 3 6 10 15 21\n"
                            "10 13 16 21 30 45";
        day.readInputString(input);
        SECTION("Part 1") {
            REQUIRE(day.sumOfForwardExtrapolatedValues() == 114);
        }
        SECTION("Part 2") {
            REQUIRE(day.sumOfBackwardExtrapolatedValues() == 2);
        }
    }
}