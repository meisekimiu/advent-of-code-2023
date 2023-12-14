#ifndef ADVENT_OF_CODE_SEQUENCEPREDICTOR_H
#define ADVENT_OF_CODE_SEQUENCEPREDICTOR_H
#include <vector>

typedef int OasisInt;

class SequencePredictor {
public:
    explicit SequencePredictor(const std::vector<OasisInt>& input);
    OasisInt nextNumber();

private:
    std::vector<std::vector<OasisInt>> dx;

    void calculateSequenceDifferences();

    void extendSequences();

    static bool sequenceIsAllZero(std::vector<OasisInt> &differences) ;
};


#endif //ADVENT_OF_CODE_SEQUENCEPREDICTOR_H
