#include <catch2/catch.hpp>
#include "../../src/day07/CardsParser.h"

TEST_CASE("Cards Parser", "[day07]") {
    CardsParser parser;

    SECTION("It has an accessible list of hands") {
        REQUIRE(parser.hands.empty());
    }

    SECTION("It can add a card and bet") {
        parser.parseLine("32T3K 765");
        REQUIRE(parser.hands.top().bet == 765);
        REQUIRE(parser.hands.top().getCards()[0] == 3);
        REQUIRE(parser.hands.top().getCards()[1] == 2);
        REQUIRE(parser.hands.top().getCards()[2] == 10);
        REQUIRE(parser.hands.top().getCards()[3] == 3);
        REQUIRE(parser.hands.top().getCards()[4] == 13);
    }

    SECTION("It orders the hands from lowest to highest rank") {
        parser.parseLine("QQQJA 483");
        parser.parseLine("32T3K 765");
        parser.hands.pop();
        REQUIRE(parser.hands.top().bet == 483);
    }
}