#include <catch2/catch.hpp>
#include "../../src/day01/Day01.h"

TEST_CASE("Day 01", "[day1]") {
    Day01 day;

    SECTION("It can identify the first and last digit of a line") {
        REQUIRE(Day01::findCalibration("1abc2", false) == 12);
        REQUIRE(Day01::findCalibration("1a2b3", false) == 13);
    }

    SECTION("It can multiply lines together for Part 1") {
        std::vector<std::string> lines = {"1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"};
        day.setLines(lines);
        REQUIRE(day.getCalibrationSum(false) == 142);
    }

    SECTION("In part two it can identify spelled out digits as well") {
        REQUIRE(Day01::findCalibration("1abc2", true) == 12);
        REQUIRE(Day01::findCalibration("one2three", true) == 13);
    }

    SECTION("Part two edge case that took me forever to figure out") {
        // I ended up having to search this because I thought the problem was bugged at first!
        // https://www.reddit.com/r/adventofcode/comments/1884fpl/2023_day_1for_those_who_stuck_on_part_2/
        REQUIRE(Day01::findCalibration("eighthree", true) == 83);
    }

    SECTION("It can multiply lines together for Part 2") {
        std::vector<std::string> lines = {"two1nine","eightwothree","abcone2threexyz","xtwone3four","4nineeightseven2","zoneight234", "7pqrstsixteen"};
        day.setLines(lines);
        REQUIRE(day.getCalibrationSum(true) == 281);
    }
}
