#include "Day09.h"
#include <iostream>
#include <numeric>

int Day09::mainPartOne() {
    readInput("data/day09/input.txt");
    std::cout << sumOfForwardExtrapolatedValues() << std::endl;
    return EXIT_SUCCESS;
}

int Day09::mainPartTwo() {
    readInput("data/day09/input.txt");
    std::cout << sumOfBackwardExtrapolatedValues() << std::endl;
    return EXIT_SUCCESS;
}

static OasisInt nextInSequence(const std::vector<OasisInt> &sequence) {
    SequencePredictor p(sequence);
    return p.nextNumber();
}

static OasisInt prevInSequence(const std::vector<OasisInt> &sequence) {
    SequencePredictor p(sequence);
    return p.prevNumber();
}

OasisInt Day09::sumOfForwardExtrapolatedValues() const {
    return sumOfSequences(nextInSequence);
}

OasisInt Day09::sumOfBackwardExtrapolatedValues() const {
    return sumOfSequences(prevInSequence);
}

OasisInt Day09::sumOfSequences(OasisInt (*unaryOp)(const std::vector<OasisInt> &)) const {
    auto &s = parser.sequences;
    return std::transform_reduce(s.begin(), s.end(), 0, std::plus{}, unaryOp);
}

void Day09::parseLine(const std::string &line) {
    parser.parseLine(line);
}
