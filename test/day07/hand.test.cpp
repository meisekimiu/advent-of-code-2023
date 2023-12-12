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
            REQUIRE_THROWS(Hand("", false));
            REQUIRE_THROWS(Hand("2345", false));
            REQUIRE_THROWS(Hand("23456789", false));
        }

        SECTION("Hand must be valid card names") {
            REQUIRE_THROWS(Hand("#$%@#", false));
            REQUIRE_THROWS(Hand("12345", false));
            REQUIRE_THROWS(Hand("ZYXWV", false));
            REQUIRE_NOTHROW(Hand("TJKQA", false));
        }

        SECTION("Hand gets card values correct") {
            hand = Hand("TJQKA", false);
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

        SECTION("Part two") {
            SECTION("Five jokers") {
                REQUIRE(Hand("JJJJJ", true).getHandValue() == CardYaku::FiveOfAKind);
            }
            SECTION("Joker makes pair") {
                REQUIRE(Hand("J2345", true).getHandValue() == CardYaku::OnePair);
            }
            SECTION("Joker makes four of a kind") {
                REQUIRE(Hand("QJJQ2", true).getHandValue() == CardYaku::FourOfAKind);
            }
        }

        SECTION("High Card") {
            REQUIRE(hand.getHandValue() == CardYaku::HighCard);
        }

        SECTION("One Pair") {
            REQUIRE(Hand("22345", false).getHandValue() == CardYaku::OnePair);
            REQUIRE(Hand("23245", false).getHandValue() == CardYaku::OnePair);
            REQUIRE(Hand("23425", false).getHandValue() == CardYaku::OnePair);
            REQUIRE(Hand("23452", false).getHandValue() == CardYaku::OnePair);
        }

        SECTION("Two Pairs") {
            REQUIRE(Hand("22344", false).getHandValue() == CardYaku::TwoPairs);
            REQUIRE(Hand("22434", false).getHandValue() == CardYaku::TwoPairs);
            REQUIRE(Hand("23424", false).getHandValue() == CardYaku::TwoPairs);
        }

        SECTION("Three of a Kind") {
            REQUIRE(Hand("22234", false).getHandValue() == CardYaku::ThreeOfAKind);
            REQUIRE(Hand("23224", false).getHandValue() == CardYaku::ThreeOfAKind);
            REQUIRE(Hand("23242", false).getHandValue() == CardYaku::ThreeOfAKind);
        }

        SECTION("Full House") {
            REQUIRE(Hand("22333", false).getHandValue() == CardYaku::FullHouse);
            REQUIRE(Hand("AJAJA", false).getHandValue() == CardYaku::FullHouse);
        }

        SECTION("Four of a Kind") {
            REQUIRE(Hand("22223", false).getHandValue() == CardYaku::FourOfAKind);
            REQUIRE(Hand("22322", false).getHandValue() == CardYaku::FourOfAKind);
        }

        SECTION("Five of a Kind") {
            REQUIRE(Hand("AAAAA", false).getHandValue() == CardYaku::FiveOfAKind);
        }
    }

    SECTION("Comparing hands") {
        SECTION("Operator <") {
            SECTION("Bigger Yaku == Bigger Value") {
                REQUIRE(Hand("AKQJT", false) < Hand("22345", false));
                REQUIRE(Hand("22345", false) < Hand("22234", false));
                REQUIRE(Hand("AAAQK", false) < Hand("22233", false));
                REQUIRE(Hand("AAAKK", false) < Hand("22223", false));
                REQUIRE(Hand("AAAAK", false) < Hand("22222", false));
            }
            SECTION("Same Yaku, the hands decide in order") {
                REQUIRE(Hand("22345", false) < Hand("52234", false));
                REQUIRE(Hand("AA234", false) < Hand("AAJQK", false));
                REQUIRE(Hand("AAAAQ", false) < Hand("AAAAK", false));
            }
        }
        SECTION("Operator ==") {
            REQUIRE(Hand("22222", false) == Hand("22222", false));
            REQUIRE_FALSE(Hand("23456", false) == Hand("23457", false));
        }
        SECTION("Operator >") {
            REQUIRE(Hand("AAAAA", false) > Hand("AAAAK", false));
        }
        SECTION("Part 2: Joker is lowest value") {
            REQUIRE(Hand("22222", true) > Hand("JJJJJ", true));
        }
    }
}
