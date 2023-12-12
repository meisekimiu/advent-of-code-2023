#include "CardsParser.h"
#include <regex>

void CardsParser::parseLine(const std::string &line) {
    const std::regex cardAndBet(R"((\w{5})\s+(\d+))");
    std::smatch matches;
    if (std::regex_search(line, matches, cardAndBet)) {
        Hand h(matches[1]);
        h.bet = std::stoi(matches[2]);
        hands.push(h);
    }
}
