#include <catch2/catch.hpp>
#include "../../src/day02/CubeGame.h"
#include "../../src/day02/Day02.h"

struct TestingCubeGame : public CubeGame {
    std::vector<CubeResults> getResults() {
        return results;
    }
};

TEST_CASE("Day 02", "[day2]") {
    Day02 day;

    SECTION("CubeGame can validate games") {
        CubeGame game;
        game.id = 1;
        game.addResults(1, 1, 1);
        REQUIRE(game.isPossible(10, 10, 10));
        game.addResults(20, 20, 20);
        REQUIRE_FALSE(game.isPossible(10, 10, 10));
    }

    SECTION("CubeGame can parse a line") {
        TestingCubeGame game;
        game.parseLine("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green");
        REQUIRE(game.id == 1);
        auto results = game.getResults();
        REQUIRE(results.size() == 3);
        REQUIRE(results[0].green == 0);
        REQUIRE(results[0].blue == 3);
        REQUIRE(results[0].red == 4);
        REQUIRE(results[1].red == 1);
        REQUIRE(results[1].green == 2);
        REQUIRE(results[1].blue == 6);
        REQUIRE(results[2].green == 2);
        REQUIRE(results[2].red == 0);
        REQUIRE(results[2].blue == 0);
    }

    SECTION("CubeGame can get the minimum number of cubes needed for a valid game") {
        CubeGame game;
        game.parseLine("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green");
        auto result = game.getMinimumValidCubes();
        REQUIRE(result.red == 4);
        REQUIRE(result.blue == 6);
        REQUIRE(result.green == 2);
    }

    SECTION("Day02 has a collection of CubeGames") {
        day.addGame("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green");
        day.addGame("Game 2: 100 blue, 100 green, 100 red");
        REQUIRE(day.sumOfValidGameIds(10, 10, 10) == 1);
    }

    SECTION("Day02 example test case") {
        day.addGame("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\n");
        day.addGame("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\n");
        day.addGame("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\n");
        day.addGame("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\n");
        day.addGame("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green");
        REQUIRE(day.sumOfValidGameIds(12, 13, 14) == 8);
    }

    SECTION("Day02 part 2 example test case") {
        day.addGame("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\n");
        day.addGame("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\n");
        day.addGame("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\n");
        day.addGame("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\n");
        day.addGame("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green");
        REQUIRE(day.sumOfCubePower() == 2286);
    }
}