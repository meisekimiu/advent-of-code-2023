//
// Created by natalie on 12/11/23.
//

#ifndef ADVENT_OF_CODE_CARDSPARSER_H
#define ADVENT_OF_CODE_CARDSPARSER_H
#include <queue>
#include "Hand.h"

class CardsParser {
public:
    bool useJokers{false};
    void parseLine(const std::string &line);
    std::priority_queue<Hand, std::vector<Hand>, std::greater<>> hands;
};


#endif //ADVENT_OF_CODE_CARDSPARSER_H
