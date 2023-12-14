#include "NodeParser.h"
#include <regex>

void NodeParser::parseLine(const std::string &line) {
    parseNode(line);
    parseDirections(line);
}

void NodeParser::parseDirections(const std::string &line) {
    const std::regex directionsMatcher = std::regex("^\\s*([RL]+)\\s*$");
    std::smatch matches;
    if (std::regex_match(line, matches, directionsMatcher)) {
        directions = matches[1];
    }
}

void NodeParser::parseNode(const std::string &line) {
    const std::regex nodeMatcher = std::regex(R"((\w{3})\s+=\s+\((\w{3}),\s+(\w{3})\))");
    std::smatch matches;
    if (std::regex_search(line, matches, nodeMatcher)) {
        map.addNode(matches[1], {matches[2], matches[3]});
    }
}
