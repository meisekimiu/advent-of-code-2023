#include <catch2/catch.hpp>
#include "../../src/util/Grid.h"

TEST_CASE("Grid", "[day10] [grid]") {
    Grid g;

    SECTION("Null grid throws error when accessing coordinates") {
        REQUIRE_THROWS(g.at(0, 0));
    }

    SECTION("Null grid has width and height of 0") {
        REQUIRE(g.getWidth() == 0);
        REQUIRE(g.getHeight() == 0);
    }

    SECTION("Grid can add a line") {
        g.addLine(".");
        REQUIRE(g.at(0, 0) == '.');
        REQUIRE(g.getWidth() == 1);
        REQUIRE(g.getHeight() == 1);
    }

    SECTION("Grid width is maximum line size") {
        g.addLine("$");
        g.addLine("$$$");
        REQUIRE(g.getWidth() == 3);
        REQUIRE(g.getHeight() == 2);

        SECTION("Grid will fill undefined spaces with null character") {
            REQUIRE(g.at(1, 0) == '.');
        }

        SECTION("Grid null character can be customized") {
            g.nullChar = 0;
            REQUIRE(g.at(1, 0) == 0);
        }
    }

    SECTION("Searching") {
        g.addLine("....");
        g.addLine(".$..");
        g.addLine("123$");
        g.addLine("abcd");

        SECTION("Grid returns empty vector when scanning for nonexistent character") {
            auto points = g.scan('!');
            REQUIRE(points.empty());
        }

        SECTION("Grid can scan for character and return positions") {
            auto points = g.scan('$');
            REQUIRE(points.size() == 2);
            REQUIRE(points[0].x == 1);
            REQUIRE(points[0].y == 1);
            REQUIRE(points[1].x == 3);
            REQUIRE(points[1].y == 2);
        }
    }

    SECTION("Border points") {
        g.addLine("....");
        g.addLine(".$..");
        g.addLine("123$");
        g.addLine("abcd");

        SECTION("It cannot get border points of a point that doesn't exist") {
            REQUIRE_THROWS(g.borderPoints(5, 5));
        }

        SECTION("It can get bordering points of an inner point") {
            auto points = g.borderPoints(1, 1);
            REQUIRE(points.points.size() == 4);
            REQUIRE(points.west->x == 0);
            REQUIRE(points.west->y == 1);
            REQUIRE(points.south->x == 1);
            REQUIRE(points.south->y == 2);
            REQUIRE(points.north->x == 1);
            REQUIRE(points.north->y == 0);
            REQUIRE(points.east->x == 2);
            REQUIRE(points.east->y == 1);
        }

        SECTION("A 1x1 size grid doesn't have any border points") {
            Grid grid;
            grid.addLine(".");
            REQUIRE(grid.borderPoints(0, 0).points.empty());
        }
    }
}