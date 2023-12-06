#ifndef ADVENT_OF_CODE_SEEDMAPLAYER_H
#define ADVENT_OF_CODE_SEEDMAPLAYER_H
#include <vector>

typedef unsigned long Seed;

struct MapRange {
    Seed sourceStart;
    Seed length;
    Seed destinationStart;
};

class SeedMapLayer {
public:
    [[nodiscard]] Seed process(Seed input) const;
    void addMapData(Seed destinationStart, Seed sourceStart, Seed length);

private:
    std::vector<MapRange> ranges;
};


#endif //ADVENT_OF_CODE_SEEDMAPLAYER_H
