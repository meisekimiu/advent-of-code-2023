#include <catch2/catch.hpp>
#include "../../src/day10/MazeArea.h"

TEST_CASE("Maze Area", "[day10]") {
    PipeMaze maze;

    SECTION("Easy example") {
        maze.addLine(".....");
        maze.addLine(".S-7.");
        maze.addLine(".|.|.");
        maze.addLine(".L-J.");
        maze.addLine(".....");

        MazeArea area(maze);

        SECTION("Bounding Box") {
            const auto [min, max] = area.getBoundingBox();
            REQUIRE(min == Point{1, 1});
            REQUIRE(max == Point{3, 3});
        }

        SECTION("Area") {
            REQUIRE(area.getArea() == 1);
        }
    }

    SECTION("0 Area example") {
        maze.addLine("S7");
        maze.addLine("LJ");

        MazeArea area(maze);

        REQUIRE(area.getArea() == 0);
    }

    SECTION("Basic example") {
        maze.addLine("...........");
        maze.addLine(".S-------7.");
        maze.addLine(".|F-----7|.");
        maze.addLine(".||.....||.");
        maze.addLine(".||.....||.");
        maze.addLine(".|L-7.F-J|.");
        maze.addLine(".|..|.|..|.");
        maze.addLine(".L--J.L--J.");
        maze.addLine("...........");

        MazeArea area(maze);

        SECTION("Bounding box") {
            const auto [min, max] = area.getBoundingBox();
            REQUIRE(min == Point{1, 1});
            REQUIRE(max == Point{9, 7});
        }

        SECTION("Area") {
            REQUIRE(area.getArea() == 4);
        }
    }

    SECTION("More complex example") {
        maze.addLine(".F----7F7F7F7F-7....");
        maze.addLine(".|F--7||||||||FJ....");
        maze.addLine(".||.FJ||||||||L7....");
        maze.addLine("FJL7L7LJLJ||LJ.L-7..");
        maze.addLine("L--J.L7...LJS7F-7L7.");
        maze.addLine("....F-J..F7FJ|L7L7L7");
        maze.addLine("....L7.F7||L7|.L7L7|");
        maze.addLine(".....|FJLJ|FJ|F7|.LJ");
        maze.addLine("....FJL-7.||.||||...");
        maze.addLine("....L---J.LJ.LJLJ...");

        MazeArea area(maze);

        REQUIRE(area.getArea() == 8);
    }

    SECTION("Final example") {
        maze.addLine("FF7FSF7F7F7F7F7F---7");
        maze.addLine("L|LJ||||||||||||F--J");
        maze.addLine("FL-7LJLJ||||||LJL-77");
        maze.addLine("F--JF--7||LJLJ7F7FJ-");
        maze.addLine("L---JF-JLJ.||-FJLJJ7");
        maze.addLine("|F|F-JF---7F7-L7L|7|");
        maze.addLine("|FFJF7L7F-JF7|JL---7");
        maze.addLine("7-L-JL7||F7|L7F-7F7|");
        maze.addLine("L.L7LFJ|||||FJL7||LJ");
        maze.addLine("L7JLJL-JLJLJL--JLJ.L");

        MazeArea area(maze);

        REQUIRE(area.getArea() == 10);
    }
}
