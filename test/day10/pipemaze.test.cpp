#include <catch2/catch.hpp>
#include "../../src/day10/PipeMaze.h"
#include "../util/pointUtils.h"

TEST_CASE("Pipe Maze", "[day10]") {
    PipeMaze m;

    SECTION("Null input") {
        REQUIRE_THROWS(m.getStartingPoint());
    }

    SECTION("Basic input") {
        m.addLine("S7");
        m.addLine("LJ");

        SECTION("It can identify the starting point") {
            auto s = m.getStartingPoint();
            REQUIRE(s.x == 0);
            REQUIRE(s.y == 0);
        }

        SECTION("It can scan for the main pipe in the maze") {
            auto points = m.getMazePoints();
            REQUIRE(points.size() == 4);
            REQUIRE(pointIsInVec(points, {0, 0}));
            REQUIRE(pointIsInVec(points, {0, 1}));
            REQUIRE(pointIsInVec(points, {1, 1}));
            REQUIRE(pointIsInVec(points, {1, 0}));
        }
    }

    SECTION("More complex input") {
        m.addLine("-L|F7");
        m.addLine("7S-7|");
        m.addLine("L|7||");
        m.addLine("-L-J|");
        m.addLine("L|-JF");

        auto points = m.getMazePoints();
        REQUIRE(points.size() == 8);
        REQUIRE(pointIsInVec(points, {1,1}));
        REQUIRE(pointIsInVec(points, {1,2}));
        REQUIRE(pointIsInVec(points, {1,3}));
        REQUIRE(pointIsInVec(points, {3,3}));
        REQUIRE(pointIsInVec(points, {3,1}));
    }

    SECTION("Even more complex input") {
        m.addLine("..F7.");
        m.addLine(".FJ|.");
        m.addLine("SJ.L7");
        m.addLine("|F--J");
        m.addLine("LJ...");

        auto points = m.getMazePoints();
        REQUIRE(points.size() == 16);
    }
}