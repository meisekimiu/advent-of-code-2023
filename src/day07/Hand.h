#ifndef ADVENT_OF_CODE_HAND_H
#define ADVENT_OF_CODE_HAND_H
#include <string>
#include <vector>
#include <unordered_map>
#include "HandTypes.h"

class Hand {
public:
    unsigned int bet;

    explicit Hand(const std::string& contents);
    [[nodiscard]] std::vector<unsigned char> getCards() const;
    CardYaku getHandValue() const;
    friend bool operator<(const Hand &h1, const Hand &h2);
    friend bool operator==(const Hand &h1, const Hand &h2);
    friend bool operator>(const Hand &h1, const Hand &h2);

private:
    std::vector<unsigned char> cards;
    std::unordered_map<unsigned char, unsigned char> cardMap;

    static unsigned char getCardValue(char c) ;
    unsigned char getMaxCardQuantity() const;
    void addCardToHand(char c);
};



#endif //ADVENT_OF_CODE_HAND_H
