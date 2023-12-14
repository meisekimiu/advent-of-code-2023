#include "OasisParser.h"
#include <sstream>

void OasisParser::parseLine(const std::string &line) {
    std::vector<OasisInt> sequence = readSequence(line);
    if (!sequence.empty()) {
        sequences.push_back(sequence);
    }
}

std::vector<OasisInt> OasisParser::readSequence(const std::string &line) {
    std::vector<OasisInt> sequence;
    std::stringstream ss;
    OasisInt seedNum;
    std::string workingString;
    ss << line;
    while (!ss.eof()) {
        ss >> workingString;
        if (std::stringstream(workingString) >> seedNum) {
            sequence.push_back(seedNum);
        }
    }
    return sequence;
}
