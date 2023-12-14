#include "SequencePredictor.h"
#include <stdexcept>
#include <algorithm>

SequencePredictor::SequencePredictor(const std::vector<OasisInt>& input) {
    if (input.size() < 2) {
        throw std::invalid_argument("SequencePredictor needs at least 2 numbers in sequence.");
    }
    dx.push_back(input);
}

OasisInt SequencePredictor::nextNumber() {
    calculateSequenceDifferences();
    extendSequences();
    return dx[0].back();
}

void SequencePredictor::extendSequences() {
    dx.back().push_back(dx.back().back());
    for (int i = static_cast<int>(dx.size()) - 2; i >= 0; i--) {
        dx[i].push_back(dx[i].back() + dx[i + 1].back());
    }
}

void SequencePredictor::calculateSequenceDifferences() {
    unsigned int level = 0;
    while (true) {
        std::vector<OasisInt> &sequence = dx[level];
        if (sequence.size() < 2) {
            break;
        }
        std::vector<OasisInt> differences;
        differences.reserve(sequence.size() - 1);
        for (int i = 0; i < sequence.size() - 1; i++) {
            differences.push_back(sequence[i + 1] - sequence[i]);
        }
        dx.push_back(differences);
        if (sequenceIsAllZero(differences)) {
            break;
        }
        level++;
    }
}

bool SequencePredictor::sequenceIsAllZero(std::vector<OasisInt> &differences) {
    return std::all_of(differences.begin(), differences.end(), [](OasisInt i) {
                return i == 0;
            });
}
