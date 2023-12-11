#include <catch2/catch.hpp>
#include "../../src/day06/Race.h"
#include "../../src/day06/Day06.h"

TEST_CASE("Day 06", "[day06]") {
    Day06 day;

    SECTION("Advent of Code Examples") {
        SECTION("Part 1") {
            day.readInputString("Time:      7  15   30\n"
                                "Distance:  9  40  200");
            REQUIRE(day.productOfPossibleWinTimes() == 288);
        }
        SECTION("Part 2") {
            day.parseSingleNumber(true);
            day.readInputString("Time:      7  15   30\n"
                                "Distance:  9  40  200");
            REQUIRE(day.productOfPossibleWinTimes() == 71503);
        }
    }

    SECTION("Part 1: Product of Possible Win Times") {
        SECTION("Null case") {
            REQUIRE_THROWS(day.productOfPossibleWinTimes());
        }

        SECTION("One race") {
            day.readInputString("Time: 7\n"
                                "Distance: 9\n");
            REQUIRE(day.productOfPossibleWinTimes() == 4);
        }

        SECTION("Two races") {
            day.readInputString("Time: 7 15\n"
                                "Distance: 9 40\n");
            REQUIRE(day.productOfPossibleWinTimes() == 32);
        }
    }

    SECTION("Race can calculate distance gone for charge up time") {
        Race r{7, 9};

        SECTION("0ms charge up time") {
            REQUIRE(r.charge(0) == 0);
            REQUIRE_FALSE(r.chargeBeatsRecord(0));
        }

        SECTION("1ms charge up time") {
            REQUIRE(r.charge(1) == 6);
            REQUIRE_FALSE(r.chargeBeatsRecord(1));
        }

        SECTION("2ms charge up time") {
            REQUIRE(r.charge(2) == 10);
            REQUIRE(r.chargeBeatsRecord(2));

        }

        SECTION("7ms charge up time") {
            REQUIRE(r.charge(7) == 0);
            REQUIRE_FALSE(r.chargeBeatsRecord(7));

        }
    }
}