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
}
