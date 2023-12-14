#include "Day09.h"
#include <iostream>
#include <numeric>

int Day09::mainPartOne() {
    readInput("data/day09/input.txt");
    std::cout << sumOfExtrapolatedValues() << std::endl;
    return EXIT_SUCCESS;
}

static OasisInt nextInSequence(const std::vector<OasisInt> &sequence) {
    SequencePredictor p(sequence);
    return p.nextNumber();
}

OasisInt Day09::sumOfExtrapolatedValues() const {
    auto &s = parser.sequences;
    return std::transform_reduce(s.begin(), s.end(), 0, std::plus{}, nextInSequence);
}

void Day09::parseLine(const std::string &line) {
    parser.parseLine(line);
}
