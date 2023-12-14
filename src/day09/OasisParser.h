#ifndef ADVENT_OF_CODE_OASISPARSER_H
#define ADVENT_OF_CODE_OASISPARSER_H
#include "SequencePredictor.h"
#include <string>

class OasisParser {
public:
    std::vector<std::vector<OasisInt>> sequences;

    void parseLine(const std::string &line);

    static std::vector<OasisInt> readSequence(const std::string &line) ;
};


#endif //ADVENT_OF_CODE_OASISPARSER_H
