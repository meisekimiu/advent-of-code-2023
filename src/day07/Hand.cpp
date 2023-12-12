#include "Hand.h"
#include "HandTypes.h"
#include <stdexcept>
#include <algorithm>

Hand::Hand(const std::string &contents, bool useJokers) {
    usingJokers = useJokers;
    if (contents.length() != 5) {
        throw std::invalid_argument("Hand must be exactly 5 hands");
    }
    for (const char c : contents) {
        addCardToHand(c);
    }
    if (useJokers) {
        adjustJokersInCardMap();
    }
}

void Hand::addCardToHand(char c) {
    unsigned char cardValue = getCardValue(c);
    cards.push_back(cardValue);
    cardMap[cardValue]++;
}

Card Hand::getCardValue(char c) const {
    switch (c) {
        case 'A':
            return 14;
        case 'K':
            return 13;
        case 'Q':
            return 12;
        case 'J':
            return usingJokers ? 1 : 11;
        case 'T':
            return 10;
        default:
            if (!isdigit(c) || c == '1' || c == '0') {
                throw std::invalid_argument("Invalid card char");
            }
            return c - '0';
    }
}

void Hand::adjustJokersInCardMap() {
    if (cardMap[1] > 0) {
        if (cardMap[1] == 5) {
            cardMap[14] = 5;
        }
        unsigned char maxQuantity = getMaxCardQuantity();
        unsigned char maxCardType = 1;
        const auto &iterator = cardMap.begin();
        auto it = std::find_if(iterator, cardMap.end(), [maxQuantity](const auto pair) {
            return pair.second == maxQuantity;
        });
        while (it != cardMap.end()) {
            maxCardType = std::max(it->first, maxCardType);
            it = std::find_if(++it, cardMap.end(), [maxQuantity](const auto pair) {
                return pair.second == maxQuantity;
            });
        }
        cardMap[maxCardType] += cardMap[1];
    }
    cardMap.erase(1);
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
        if (val.first != 1) {
            maxQuantity = std::max(maxQuantity, val.second);
        }
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

