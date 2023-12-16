#include <catch2/catch.hpp>
#include "../../src/day10/Day10.h"

TEST_CASE("Day 10", "[day10]") {
    Day10 day;

    SECTION("Advent of Code Example Part 1") {
        day.readInputString("7-F7-\n"
                            ".FJ|7\n"
                            "SJLL7\n"
                            "|F--J\n"
                            "LJ.LJ\n");
        REQUIRE(day.getMaxDistanceOfMaze() == 8);
    }

    SECTION("Advent of Code Example Part 2") {
        day.readInputString("FF7FSF7F7F7F7F7F---7\n"
                            "L|LJ||||||||||||F--J\n"
                            "FL-7LJLJ||||||LJL-77\n"
                            "F--JF--7||LJLJ7F7FJ-\n"
                            "L---JF-JLJ.||-FJLJJ7\n"
                            "|F|F-JF---7F7-L7L|7|\n"
                            "|FFJF7L7F-JF7|JL---7\n"
                            "7-L-JL7||F7|L7F-7F7|\n"
                            "L.L7LFJ|||||FJL7||LJ\n"
                            "L7JLJL-JLJLJL--JLJ.L");
        REQUIRE(day.getAreaOfMaze() == 10);
    }
}
