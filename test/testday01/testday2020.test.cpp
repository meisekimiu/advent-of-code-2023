#include <catch2/catch.hpp>
#include "../../src/testday01/TestDay2020.h"

TEST_CASE("Test Day: December 1st 2020", "[test]") {
    TestDay2020 day;

    SECTION("It can load in a list of numbers and calculate part one") {
        std::vector<int> list = {1, 2, 3, 4, 5, 2019};
        day.setExpenses(list);
        REQUIRE(day.find2020() == 2019);
    }

    SECTION("Part one example provided by Advent of Code") {
        std::vector<int> list = {1721, 979, 366, 299, 675, 1456};
        day.setExpenses(list);
        REQUIRE(day.find2020() == 514579);
    }

    SECTION("It can calculate part two") {
        std::vector<int> list = {1, 2, 3, 4, 5, 2017};
        day.setExpenses(list);
        REQUIRE(day.find2020PartTwo() == 2017 * 2);
    }

    SECTION("Part two example provided by Advent of Code") {
        std::vector<int> list = {1721, 979, 366, 299, 675, 1456};
        day.setExpenses(list);
        REQUIRE(day.find2020PartTwo() == 241861950);
    }
}
