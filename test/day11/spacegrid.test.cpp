#include <catch2/catch.hpp>
#include "../util/pointUtils.h"
#include "../../src/day11/SpaceGrid.h"

TEST_CASE("Space Grid", "[day11] [grid]") {
    SpaceGrid grid;

    SECTION("It expands empty lines") {
        grid.addLine(".");
        grid.expand();
        REQUIRE(grid.getExpansionColumns().size() == 1);
        REQUIRE(grid.getExpansionRows().size() == 1);
        REQUIRE(grid.getExpansionRows().front() == 0);
        REQUIRE(grid.getExpansionColumns().front() == 0);
    }

    SECTION("It does not expand galaxy lines") {
        grid.addLine("#..");
        grid.addLine("..#");
        grid.expand();
        REQUIRE(grid.getExpansionRows().empty());
        REQUIRE(grid.getExpansionColumns().size() == 1);
        REQUIRE(grid.getExpansionColumns().front() == 1);
    }

    SECTION("Multiple column/row expansions happen properly") {
        grid.addLine("#...#");
        grid.addLine(".....");
        grid.addLine("..#..");
        grid.addLine(".....");
        grid.addLine("#...#");
        grid.expand();
        REQUIRE(grid.getExpansionColumns().size() == 2);
        REQUIRE(grid.getExpansionRows().size() == 2);
    }
}