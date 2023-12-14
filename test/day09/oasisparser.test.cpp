#include <catch2/catch.hpp>
#include "../../src/day09/OasisParser.h"

TEST_CASE("Oasis Parser", "[day09]") {
    OasisParser parser;

    SECTION("It can read a line and create a SequencePredictor") {
        parser.parseLine("1 2 3 4");
        REQUIRE(parser.sequences.size() == 1);
        REQUIRE(parser.sequences[0][0] == 1);
        REQUIRE(parser.sequences[0][1] == 2);
        REQUIRE(parser.sequences[0][2] == 3);
        REQUIRE(parser.sequences[0][3] == 4);
    }

    SECTION("It will ignore lines without numbers") {
        parser.parseLine("potatoskjflksajfsjf");
        REQUIRE(parser.sequences.empty());
    }
}