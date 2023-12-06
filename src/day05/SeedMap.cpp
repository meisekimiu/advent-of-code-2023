#include "SeedMap.h"

Seed SeedMap::locateSeed(Seed seed) {
    Seed input = seed;
    for (const SeedMapLayer& layer : layers) {
        input = layer.process(input);
    }
    return input;
}

void SeedMap::addLayer(const SeedMapLayer &layer) {
    layers.push_back(layer);
}

SeedMapLayer &SeedMap::latestLayer() {
    return layers.back();
}
