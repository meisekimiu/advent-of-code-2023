#include "Day04.h"
#include <numeric>
#include <fstream>
#include <iostream>
#include <unordered_map>

int Day04::mainPartOne() {
    readInput("data/day04/input.txt");
    std::cout << totalCardWinnings() << std::endl;
    return EXIT_SUCCESS;
}

int Day04::mainPartTwo() {
    readInput("data/day04/input.txt");
    std::cout << totalCardCopies() << std::endl;
    return EXIT_SUCCESS;
}

void Day04::parseLine(const std::string &line) {
    ScratchCard c;
    c.parseLine(line);
    cards.push_back(c);
}

int Day04::totalCardWinnings() const {
    return std::transform_reduce(cards.begin(), cards.end(), 0, std::plus{}, [](const ScratchCard& c) {
       return c.getScore();
    });
}

int Day04::totalCardCopies() const {
    std::unordered_map<int, int> cardCopies;
    for (const auto &card : cards) {
        cardCopies[card.id] += 1;
        int winnings = card.getNumberOfMatches();
        for (int i = 0; i < winnings; i++) {
            int nextId = card.id + i + 1;
            cardCopies[nextId] += cardCopies[card.id];
        }
    }
    return std::transform_reduce(cardCopies.begin(), cardCopies.end(), 0, std::plus{}, [](std::pair<const int, int> x) {
        return x.second;
    });
}

