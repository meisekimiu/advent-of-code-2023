#include <catch2/catch.hpp>
#include "../../src/day04/Day04.h"
#include "../../src/day04/ScratchCard.h"

bool setContains(const std::set<int> &set, int n) {
    return set.find(n) != set.end();
}

TEST_CASE("Day 04", "[day04]") {
    Day04 day;

    SECTION("ScratchCard") {
        ScratchCard card;

        SECTION("It has winning numbers") {
            card.addWinningNumber(1);
            card.addWinningNumber(2);
            auto wins = card.getWinningNumbers();
            REQUIRE(wins.size() == 2);
            REQUIRE(setContains(wins, 1));
            REQUIRE(setContains(wins, 2));
        }

        SECTION("It has game numbers") {
            card.addNumber(1);
            card.addNumber(2);
            auto nums = card.getNumbers();
            REQUIRE(nums.size() == 2);
            REQUIRE(setContains(nums, 1));
            REQUIRE(setContains(nums, 2));
        }

        SECTION("It can parse winning and game numbers from the input") {
            card.parseLine("Game 1: 1 15 100 | 1 2 3 4 5 6");
            auto wins = card.getWinningNumbers();
            auto nums = card.getNumbers();
            REQUIRE(wins.size() == 3);
            REQUIRE(setContains(wins, 1));
            REQUIRE(setContains(wins, 15));
            REQUIRE(setContains(wins, 100));
            REQUIRE(nums.size() == 6);
            REQUIRE(setContains(nums, 1));
            REQUIRE(setContains(nums, 2));
            REQUIRE(setContains(nums, 3));
            REQUIRE(setContains(nums, 4));
            REQUIRE(setContains(nums, 5));
            REQUIRE(setContains(nums, 6));
        }


        SECTION("It can parse game ID") {
            card.parseLine("Game 1337: 1 2 3 | 4 5 6");
            REQUIRE(card.id == 1337);
        }

        SECTION("It can get the number of matches") {
            card.parseLine("Game 1: 1 2 3 | 1 3 5");
            REQUIRE(card.getNumberOfMatches() == 2);
        }

        SECTION("It calculates a 0 score for a losing card") {
            card.parseLine("Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11");
            REQUIRE(card.getScore() == 0);
        }

        SECTION("It calculates a score of 1 for a card with one match") {
            card.parseLine("Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83");
            REQUIRE(card.getScore() == 1);
        }

        SECTION("It doubles the score for each match above 1") {
            ScratchCard card1;
            ScratchCard card2;
            card1.parseLine("Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19");
            card2.parseLine("Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53");
            REQUIRE(card1.getScore() == 2);
            REQUIRE(card2.getScore() == 8);
        }
    }

    SECTION("Day04 example part 1") {
        day.parseLine("Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53\n");
        day.parseLine("Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19\n");
        day.parseLine("Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1\n");
        day.parseLine("Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83\n");
        day.parseLine("Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36\n");
        day.parseLine("Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11\n");
        REQUIRE(day.totalCardWinnings() == 13);
    }

    SECTION("Day04 Part 2") {
        SECTION("Null case") {
            REQUIRE(day.totalCardCopies() == 0);
        }
        SECTION("0 matches on 1 card") {
            day.parseLine("Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11");
            REQUIRE(day.totalCardCopies() == 1);
        }
        SECTION("1 match on 2 cards") {
            day.parseLine("Card 1: 1 2 3 | 3 4 5");
            day.parseLine("Card 2: 1 2 3 | 7 8 9");
            REQUIRE(day.totalCardCopies() == 3);
        }
        SECTION("Basic cascading runs") {
            day.parseLine("Card 1: 1 | 1");
            day.parseLine("Card 2: 1 2 | 1 2");
            day.parseLine("Card 3: 1 | 1");
            day.parseLine("Card 4: 1 | 9");
            REQUIRE(day.totalCardCopies() == 12);
        }
        SECTION("Advent of Code example") {
            day.parseLine("Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53\n");
            day.parseLine("Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19\n");
            day.parseLine("Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1\n");
            day.parseLine("Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83\n");
            day.parseLine("Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36\n");
            day.parseLine("Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11\n");
            REQUIRE(day.totalCardCopies() == 30);
        }
    }
}