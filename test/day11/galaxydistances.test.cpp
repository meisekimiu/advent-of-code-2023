#include <catch2/catch.hpp>
#include "../../src/day11/GalaxyDistances.h"

TEST_CASE("Galaxy Distances", "[day11]") {
    GalaxyDistances g;

    SECTION("Basic example, no expansion") {
        g.addLine("#.");
        g.addLine(".#");
        auto distances = g.getDistances();
        REQUIRE(distances.size() == 1);
        REQUIRE(distances.front() == 2);
    }

    SECTION("With expansion") {
        g.addLine("#...");
        g.addLine(".#..");
        g.addLine("....");
        g.addLine("...#");
        auto distances = g.getDistances();
        REQUIRE(distances.size() == 3);
        REQUIRE(distances[0] == 2);
        REQUIRE(distances[1] == 8);
        REQUIRE(distances[2] == 6);

        SECTION("Repeated calls to getDistances does not change expansion") {
            REQUIRE(g.getDistances().size() == distances.size());
        }
    }

    SECTION("Different cosmic expansion rate") {
        g.addLine("#.....");
        g.addLine(".#....");
        g.addLine("......");
        g.addLine("......");
        g.addLine("....#.");
        g.addLine("......");
        g.cosmicExpansionRate = 2;

        auto distances = g.getDistances();
        REQUIRE(distances[0] == 2);
        REQUIRE(distances[1] == 16);
        REQUIRE(distances[2] == 14);
    }
}