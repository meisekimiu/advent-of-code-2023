#include "Hand.h"
#include "HandTypes.h"
#include <stdexcept>

Hand::Hand(const std::string &contents) {
    if (contents.length() != 5) {
        throw std::invalid_argument("Hand must be exactly 5 hands");
    }
    for (const char c : contents) {
        addCardToHand(c);
    }
}

void Hand::addCardToHand(char c) {
    cards.push_back(getCardValue(c));
    cardMap[c]++;
}

Card Hand::getCardValue(char c) {
    switch (c) {
        case 'A':
            return 14;
        case 'K':
            return 13;
        case 'Q':
            return 12;
        case 'J':
            return 11;
        case 'T':
            return 10;
        default:
            if (!isdigit(c) || c == '1' || c == '0') {
                throw std::invalid_argument("Invalid card char");
            }
            return c - '0';
    }
}

std::vector<Card> Hand::getCards() const {
    return cards;
}

CardYaku Hand::getHandValue() const {
    unsigned long mapSize = cardMap.size();
    if (mapSize == 1) {
        return CardYaku::FiveOfAKind;
    }
    if (mapSize == 2) {
        if (getMaxCardQuantity() == 4) {
            return CardYaku::FourOfAKind;
        }
        return CardYaku::FullHouse;
    }
    if (mapSize == 3) {
        if (getMaxCardQuantity() == 3) {
            return CardYaku::ThreeOfAKind;
        }
        return CardYaku::TwoPairs;
    }
    if (mapSize == 4) {
        return CardYaku::OnePair;
    }
    return CardYaku::HighCard;
}

unsigned char Hand::getMaxCardQuantity() const {
    unsigned char maxQuantity = 0;
    for (const auto &val : cardMap) {
        maxQuantity = std::max(maxQuantity, val.second);
    }
    return maxQuantity;
}

bool operator<(const Hand &h1, const Hand &h2) {
    CardYaku yaku1 = h1.getHandValue();
    CardYaku yaku2 = h2.getHandValue();
    if (yaku1 == yaku2) {
        const auto cards1 = h1.getCards();
        const auto cards2 = h2.getCards();
        for (int i = 0; i < cards1.size(); i++) {
            if (cards1[i] != cards2[i]) {
                return cards1[i] < cards2[i];
            }
        }
    }
    return yaku1 < yaku2;
}

bool operator==(const Hand &h1, const Hand &h2) {
    const auto cards1 = h1.getCards();
    const auto cards2 = h2.getCards();
    for (int i = 0; i < cards1.size(); i++) {
        if (cards1[i] != cards2[i]) {
            return false;
        }
    }
    return true;
}

bool operator>(const Hand &h1, const Hand &h2) {
    return !(h1 == h2) && !(h1 < h2);
}

