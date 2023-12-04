#include <catch2/catch.hpp>
#include "../../src/day03/Day03.h"
#include "../../src/day03/PartsGrid.h"

TEST_CASE("Day 03", "[day03]") {
    Day03 day;

    SECTION("PartsGrid") {
        PartsGrid grid;

        SECTION("Null case") {
            auto validNumbers = grid.getValidNumbers();
            REQUIRE(validNumbers.empty());
        }

        SECTION("Can scan part numbers in one line") {
            grid.addLine("*123...456...789$");
            auto validNumbers = grid.getValidNumbers();
            REQUIRE(validNumbers.size() == 2);
            REQUIRE(validNumbers[0] == 123);
            REQUIRE(validNumbers[1] == 789);
        }

        SECTION("Can scan part numbers in multiple lines") {
            grid.addLine("*123...456...789$");
            grid.addLine("*......$.........");
            grid.addLine("151...........970");
            auto validNumbers = grid.getValidNumbers();
            REQUIRE(validNumbers.size() == 4);
            REQUIRE(validNumbers[0] == 123);
            REQUIRE(validNumbers[1] == 456);
            REQUIRE(validNumbers[2] == 789);
            REQUIRE(validNumbers[3] == 151);
        }

        SECTION("Can get a list of gears") {
            grid.addLine("*123...456");
            grid.addLine("151...*987");
            grid.addLine("151....123");
            auto gears = grid.getGears();
            REQUIRE(gears.size() == 1);
            REQUIRE(gears[0].adjacentNumbers.size() == 2);
            REQUIRE(gears[0].getRatio() == 123 * 151);
        }
    }

    SECTION("Day03 example part 1") {
        day.addLine("467..114..");
        day.addLine("...*......");
        day.addLine("..35..633.");
        day.addLine("......#...");
        day.addLine("617*......");
        day.addLine(".....+.58.");
        day.addLine("..592.....");
        day.addLine("......755.");
        day.addLine("...$.*....");
        day.addLine(".664.598..");
        REQUIRE(day.partNumberSum() == 4361);
    }

    SECTION("Day03 example part 2") {
        day.addLine("467..114..");
        day.addLine("...*......");
        day.addLine("..35..633.");
        day.addLine("......#...");
        day.addLine("617*......");
        day.addLine(".....+.58.");
        day.addLine("..592.....");
        day.addLine("......755.");
        day.addLine("...$.*....");
        day.addLine(".664.598..");
        REQUIRE(day.gearRatioSum() == 467835);
    }
}