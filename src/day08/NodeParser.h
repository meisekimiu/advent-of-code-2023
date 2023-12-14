#ifndef ADVENT_OF_CODE_NODEPARSER_H
#define ADVENT_OF_CODE_NODEPARSER_H
#include <string>
#include "NodeMap.h"

class NodeParser {
public:
    std::string directions;
    NodeMap map;
    void parseLine(const std::string& line);

    void parseNode(const std::string &line);

    void parseDirections(const std::string &line);
};


#endif //ADVENT_OF_CODE_NODEPARSER_H
