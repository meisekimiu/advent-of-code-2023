#ifndef ADVENT_OF_CODE_SEEDMAP_H
#define ADVENT_OF_CODE_SEEDMAP_H
#include <vector>
#include "SeedMapLayer.h"

class SeedMap {
public:
    [[nodiscard]] Seed locateSeed(Seed seed);
    std::vector<SeedRange> locateRange(const SeedRange &range);
    void addLayer(const SeedMapLayer& layer);
    SeedMapLayer& latestLayer();

private:
    std::vector<SeedMapLayer> layers;
};


#endif //ADVENT_OF_CODE_SEEDMAP_H
