#include <catch2/catch.hpp>
#include "../../src/day07/Day07.h"

TEST_CASE("Day 07", "[day07]") {
    Day07 day;

    SECTION("Advent of Code Examples") {
        std::string input("32T3K 765\n"
                          "T55J5 684\n"
                          "KK677 28\n"
                          "KTJJT 220\n"
                          "QQQJA 483");
        SECTION("Part 1") {
            day.readInputString(input);
            REQUIRE(day.calculateWinnings() == 6440);
        }
        SECTION("Part 2") {
            day.useJokers(true);
            day.readInputString(input);
            REQUIRE(day.calculateWinnings() == 5905);
        }
    }
}