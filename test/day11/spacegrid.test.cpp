#include <catch2/catch.hpp>
#include "../util/pointUtils.h"
#include "../../src/day11/SpaceGrid.h"

TEST_CASE("Space Grid", "[day11] [grid]") {
    SpaceGrid grid;

    SECTION("It expands empty lines") {
        grid.addLine(".");
        grid.expand();
        REQUIRE(grid.getWidth() == 2);
        REQUIRE(grid.getHeight() == 2);
        REQUIRE(grid.scan('.').size() == 4);
    }

    SECTION("It does not expand galaxy lines") {
        grid.addLine("#..");
        grid.addLine("..#");
        grid.expand();
        const auto galaxies = grid.scan('#');
        REQUIRE(grid.getWidth() == 4);
        REQUIRE(grid.getHeight() == 2);
        REQUIRE(pointIsInVec(galaxies, {0, 0}));
        REQUIRE(pointIsInVec(galaxies, {3, 1}));
    }

    SECTION("Multiple column/row expansions happen properly") {
        grid.addLine("#...#");
        grid.addLine(".....");
        grid.addLine("..#..");
        grid.addLine(".....");
        grid.addLine("#...#");
        grid.expand();
        const auto galaxies = grid.scan('#');
        REQUIRE(grid.getWidth() == 7);
        REQUIRE(grid.getHeight() == 7);
        REQUIRE(pointIsInVec(galaxies, {0,0}));
        REQUIRE(pointIsInVec(galaxies, {6,0}));
        REQUIRE(pointIsInVec(galaxies, {3,3}));
        REQUIRE(pointIsInVec(galaxies, {0,6}));
        REQUIRE(pointIsInVec(galaxies, {6,6}));
    }
}