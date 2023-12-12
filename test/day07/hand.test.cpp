#include <catch2/catch.hpp>
#include "../../src/day07/Hand.h"

TEST_CASE("Camel Cards Hand", "[day07]") {
    SECTION("Constructor") {
        Hand hand("23456");
        REQUIRE(hand.getCards().size() == 5);
        REQUIRE(hand.getCards()[0] == 2);
        REQUIRE(hand.getCards()[1] == 3);
        REQUIRE(hand.getCards()[2] == 4);
        REQUIRE(hand.getCards()[3] == 5);
        REQUIRE(hand.getCards()[4] == 6);

        SECTION("Hand must be 5 hands long") {
            REQUIRE_THROWS(Hand(""));
            REQUIRE_THROWS(Hand("2345"));
            REQUIRE_THROWS(Hand("23456789"));
        }

        SECTION("Hand must be valid card names") {
            REQUIRE_THROWS(Hand("#$%@#"));
            REQUIRE_THROWS(Hand("12345"));
            REQUIRE_THROWS(Hand("ZYXWV"));
            REQUIRE_NOTHROW(Hand("TJKQA"));
        }

        SECTION("Hand gets card values correct") {
            hand = Hand("TJQKA");
            REQUIRE(hand.getCards()[0] == 10);
            REQUIRE(hand.getCards()[1] == 11);
            REQUIRE(hand.getCards()[2] == 12);
            REQUIRE(hand.getCards()[3] == 13);
            REQUIRE(hand.getCards()[4] == 14);
        }
    }

    SECTION("Bet") {
        Hand hand("23456");
        hand.bet = 1337;
    }

    SECTION("Scoring hands") {
        Hand hand("23456");

        SECTION("High Card") {
            REQUIRE(hand.getHandValue() == CardYaku::HighCard);
        }

        SECTION("One Pair") {
            REQUIRE(Hand("22345").getHandValue() == CardYaku::OnePair);
            REQUIRE(Hand("23245").getHandValue() == CardYaku::OnePair);
            REQUIRE(Hand("23425").getHandValue() == CardYaku::OnePair);
            REQUIRE(Hand("23452").getHandValue() == CardYaku::OnePair);
        }

        SECTION("Two Pairs") {
            REQUIRE(Hand("22344").getHandValue() == CardYaku::TwoPairs);
            REQUIRE(Hand("22434").getHandValue() == CardYaku::TwoPairs);
            REQUIRE(Hand("23424").getHandValue() == CardYaku::TwoPairs);
        }

        SECTION("Three of a Kind") {
            REQUIRE(Hand("22234").getHandValue() == CardYaku::ThreeOfAKind);
            REQUIRE(Hand("23224").getHandValue() == CardYaku::ThreeOfAKind);
            REQUIRE(Hand("23242").getHandValue() == CardYaku::ThreeOfAKind);
        }

        SECTION("Full House") {
            REQUIRE(Hand("22333").getHandValue() == CardYaku::FullHouse);
            REQUIRE(Hand("AJAJA").getHandValue() == CardYaku::FullHouse);
        }

        SECTION("Four of a Kind") {
            REQUIRE(Hand("22223").getHandValue() == CardYaku::FourOfAKind);
            REQUIRE(Hand("22322").getHandValue() == CardYaku::FourOfAKind);
        }

        SECTION("Five of a Kind") {
            REQUIRE(Hand("AAAAA").getHandValue() == CardYaku::FiveOfAKind);
        }
    }

    SECTION("Comparing hands") {
        SECTION("Operator <") {
            SECTION("Bigger Yaku == Bigger Value") {
                REQUIRE(Hand("AKQJT") < Hand("22345"));
                REQUIRE(Hand("22345") < Hand("22234"));
                REQUIRE(Hand("AAAQK") < Hand("22233"));
                REQUIRE(Hand("AAAKK") < Hand("22223"));
                REQUIRE(Hand("AAAAK") < Hand("22222"));
            }
            SECTION("Same Yaku, the hands decide in order") {
                REQUIRE(Hand("22345") < Hand("52234"));
                REQUIRE(Hand("AA234") < Hand("AAJQK"));
                REQUIRE(Hand("AAAAQ") < Hand("AAAAK"));
            }
        }
        SECTION("Operator ==") {
            REQUIRE(Hand("22222") == Hand("22222"));
            REQUIRE_FALSE(Hand("23456") == Hand("23457"));
        }
        SECTION("Operator >") {
            REQUIRE(Hand("AAAAA") > Hand("AAAAK"));
        }
    }
}
