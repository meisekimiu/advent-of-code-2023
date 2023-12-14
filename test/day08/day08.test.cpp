#include <catch2/catch.hpp>
#include "../../src/day08/Day08.h"

TEST_CASE("Day08", "[day08]") {
    Day08 day;

    SECTION("Advent of Code Example Part 1") {
        day.readInputString("LLR\n"
                            "\n"
                            "AAA = (BBB, BBB)\n"
                            "BBB = (AAA, ZZZ)\n"
                            "ZZZ = (ZZZ, ZZZ)");
        REQUIRE(day.stepsToZzz() == 6);
    }

    SECTION("Advent of Code Example Part 2") {
        day.readInputString("LR\n"
                            "\n"
                            "11A = (11B, XXX)\n"
                            "11B = (XXX, 11Z)\n"
                            "11Z = (11B, XXX)\n"
                            "22A = (22B, XXX)\n"
                            "22B = (22C, 22C)\n"
                            "22C = (22Z, 22Z)\n"
                            "22Z = (22B, 22B)\n"
                            "XXX = (XXX, XXX)");
        REQUIRE(day.ghostStepsFromAToZ() == 6);
    }

    SECTION("Custom example for Part 2") {
        day.readInputString("LR\n"
                            "\n"
                            "11A = (11B, XXX)\n"
                            "11B = (XXX, 11Z)\n"
                            "11Z = (11B, XXX)\n"
                            "22A = (22B, XXX)\n"
                            "22B = (22C, 22C)\n"
                            "22C = (22Z, 22Z)\n"
                            "22Z = (22B, 22B)\n"
                            "33A = (33B, XXX)\n"
                            "33B = (XXX, 33C)\n"
                            "33C = (33D, XXX)\n"
                            "33D = (XXX, 33E)\n"
                            "33E = (33Z, XXX)\n"
                            "33Z = (XXX, 33A)\n"
                            "XXX = (XXX, XXX)\n"
                            );
        REQUIRE(day.ghostStepsFromAToZ() == 30);
    }
}
