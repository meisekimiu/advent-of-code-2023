#include <catch2/catch.hpp>
#include "../../src/day06/RaceParser.h"

class TestRaceParser : public RaceParser {
public:
    [[nodiscard]] std::vector<int> getTimes() const {
        return raceTimes;
    }

    [[nodiscard]] std::vector<int> getDistances() const {
        return raceDistances;
    }
};

TEST_CASE("Race Parser", "[day06]") {
    TestRaceParser parser;

    SECTION("Parser is empty by default") {
        REQUIRE(parser.getTimes().empty());
        REQUIRE(parser.getDistances().empty());
    }

    SECTION("Parser ignores lines that don't match format") {
        parser.readLine("Potato: 1 2 3 4");
        REQUIRE(parser.getTimes().empty());
        REQUIRE(parser.getDistances().empty());
    }

    SECTION("Parser can parse times") {
        parser.readLine("Time:      7  15   30");
        REQUIRE(parser.getDistances().empty());
        REQUIRE(parser.getTimes().size() == 3);
        REQUIRE(parser.getTimes()[0] == 7);
        REQUIRE(parser.getTimes()[1] == 15);
        REQUIRE(parser.getTimes()[2] == 30);
    }

    SECTION("Parser can parse distances") {
        parser.readLine("Distance:  9  40  200");
        REQUIRE(parser.getTimes().empty());
        REQUIRE(parser.getDistances().size() == 3);
        REQUIRE(parser.getDistances()[0] == 9);
        REQUIRE(parser.getDistances()[1] == 40);
        REQUIRE(parser.getDistances()[2] == 200);
    }

    SECTION("Assembling numbers into Race objects") {
        SECTION("Empty vector for empty parser object") {
            REQUIRE(parser.generateRaces().empty());
        }

        SECTION("Throws error when time and distance are not equal sizes") {
            parser.readLine("Distance:  9  40  200");
            parser.readLine("Time:  9  40");
            REQUIRE_THROWS(parser.generateRaces());
        }

        SECTION("Generates list of races") {
            parser.readLine("Time:      7  15   30");
            parser.readLine("Distance:  9  40  200");
            const auto races = parser.generateRaces();
            REQUIRE(races.size() == 3);
            REQUIRE(races[0].time == 7);
            REQUIRE(races[0].distance == 9);
            REQUIRE(races[1].time == 15);
            REQUIRE(races[1].distance == 40);
            REQUIRE(races[2].time == 30);
            REQUIRE(races[2].distance == 200);
        }
    }
}
