#include "SeedMapLayer.h"
#include <algorithm>
#include <cassert>

Seed SeedMapLayer::process(Seed input) const {
    auto it = std::find_if(ranges.begin(), ranges.end(), [input](const MapRange &range) {
        return range.sourceStart <= input && input - range.sourceStart < range.length;
    });
    if (it != ranges.end()) {
        const MapRange &range = *it;
        Seed processed = range.destinationStart - range.sourceStart + input;
        return processed;
    }
    return input;
}

void SeedMapLayer::addMapData(Seed destinationStart, Seed sourceStart, Seed length) {
    ranges.push_back({sourceStart, length, destinationStart});
}

std::vector<Seed> SeedMapLayer::seedRangeSplittingPoints(const SeedRange &seed, const MapRange &map) {
    const Seed &mapPoint1 = map.sourceStart;
    const Seed mapPoint2 = map.sourceStart + map.length;
    const Seed &seedPoint1 = seed.start;
    const Seed seedPoint2 = seed.start + seed.length;
    std::vector<Seed> keyPoints;
    keyPoints.reserve(4);
    keyPoints.push_back(seedPoint1);
    if (mapPoint1 > seedPoint1 && mapPoint1 < seedPoint2) {
        keyPoints.push_back(mapPoint1);
    }
    if (mapPoint2 > seedPoint1 && mapPoint2 < seedPoint2) {
        keyPoints.push_back(mapPoint2);
    }
    keyPoints.push_back(seedPoint2);
    return keyPoints;
}

std::vector<SeedRange> SeedMapLayer::processRanges(const std::vector<SeedRange> &seedRanges) const {
    std::vector<std::vector<SeedRange>> rangeOutput;
    std::transform(seedRanges.begin(), seedRanges.end(), std::back_inserter(rangeOutput), [&](const SeedRange& range) {
       return processRange(range);
    });

    std::vector<SeedRange> flatOutput;
    for (const auto &vec : rangeOutput) {
        for (const auto &r : vec) {
            flatOutput.push_back(r);
        }
    }
    return flatOutput;
}

std::vector<SeedRange> SeedMapLayer::processRange(SeedRange r) const {
    std::vector<SeedRange> seedRanges;
    seedRanges.push_back(r);
    for (const MapRange &range : ranges) {
        std::vector<SeedRange> newSeedRanges;
        for (const SeedRange &seedRange : seedRanges) {
            auto keyPoints = seedRangeSplittingPoints(seedRange, range);
            for (int i = 0; i < keyPoints.size() - 1; i++) {
                newSeedRanges.push_back({keyPoints[i], keyPoints[i + 1] - keyPoints[i]});
            }
        }
        seedRanges = newSeedRanges;
    }
    for (auto &seedRange : seedRanges) {
        seedRange.start = process(seedRange.start);
    }
    return seedRanges;
}
