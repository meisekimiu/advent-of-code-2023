#include <catch2/catch.hpp>
#include "../../src/day08/NodeParser.h"

TEST_CASE("NodeParser", "[day08]") {
    NodeParser parser;

    SECTION("Parser can read the input directions") {
        parser.parseLine("RLRLLLRLRLRRRRLR");
        REQUIRE(parser.directions == "RLRLLLRLRLRRRRLR");
    }

    SECTION("Parser can read the nodes") {
        parser.parseLine("AAA = (BBB, CCC)");
        auto map = parser.map.getMap();
        REQUIRE(map["AAA"].left == "BBB");
        REQUIRE(map["AAA"].right == "CCC");
    }

    SECTION("Parser can parse both directions and nodes") {
        parser.parseLine("LR\n");
        parser.parseLine("\n");
        parser.parseLine("AAA = (BBB, CCC)\n");
        REQUIRE(parser.map.getMap()["AAA"].left == "BBB");
        REQUIRE(parser.directions == "LR");
    }
}