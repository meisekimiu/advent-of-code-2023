#ifndef ADVENT_OF_CODE_SEEDMAPLAYER_H
#define ADVENT_OF_CODE_SEEDMAPLAYER_H
#include <vector>

typedef unsigned long Seed;

struct MapRange {
    Seed sourceStart;
    Seed length;
    Seed destinationStart;
};

struct SeedRange {
    Seed start;
    Seed length;
};

class SeedMapLayer {
public:
    [[nodiscard]] Seed process(Seed input) const;
    [[nodiscard]] std::vector<SeedRange> processRanges(const std::vector<SeedRange> &r) const;
    [[nodiscard]] std::vector<SeedRange> processRange(SeedRange r) const;
    void addMapData(Seed destinationStart, Seed sourceStart, Seed length);

private:
    std::vector<MapRange> ranges;
    static std::vector<Seed> seedRangeSplittingPoints(const SeedRange &seed, const MapRange &map);
};


#endif //ADVENT_OF_CODE_SEEDMAPLAYER_H
