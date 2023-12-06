#include "SeedMapLayer.h"
#include <algorithm>

Seed SeedMapLayer::process(Seed input) const {
    auto it = std::find_if(ranges.begin(), ranges.end(), [input](const MapRange &range) {
       return range.sourceStart <= input && input - range.sourceStart < range.length;
    });
    if (it != ranges.end()) {
        return it->destinationStart - it->sourceStart + input;
    }
    return input;
}

void SeedMapLayer::addMapData(Seed destinationStart, Seed sourceStart, Seed length) {
    ranges.push_back({sourceStart, length, destinationStart});
}
