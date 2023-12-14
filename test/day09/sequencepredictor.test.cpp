#include <catch2/catch.hpp>
#include "../../src/day09/SequencePredictor.h"

TEST_CASE("Sequence Predictor", "[day09]") {
    SECTION("It takes a vector of at least 2 ints") {
        REQUIRE_NOTHROW(SequencePredictor({1, 2}));
        REQUIRE_THROWS(SequencePredictor({0}));
    }

    SECTION("It has a prediction method") {
        SequencePredictor p({0, 0, 0});
        REQUIRE(p.nextNumber() == 0);
    }

    SECTION("It can predict a linear sequence") {
        SequencePredictor p({1, 2, 3, 4});
        REQUIRE(p.nextNumber() == 5);
    }

    SECTION("It can predict a more complicated sequence") {
        SequencePredictor p({10, 13, 16, 21, 30, 45});
        REQUIRE(p.nextNumber() == 68);
    }

    SECTION("Weird edge case") {
        SequencePredictor p({100, 150});
        REQUIRE(p.nextNumber() == 200);
    }

    SECTION("It can predict backwards as well") {
        SequencePredictor p({1, 2, 3, 4});
        REQUIRE(p.prevNumber() == 0);
    }

    SECTION("More complicated backwards prediction") {
        SequencePredictor p({10, 13, 16, 21, 30, 45});
        REQUIRE(p.prevNumber() == 5);
    }

    SECTION("Edge case backwards prediction") {
        SequencePredictor p({100, 150});
        REQUIRE(p.prevNumber() == 50);
    }
}