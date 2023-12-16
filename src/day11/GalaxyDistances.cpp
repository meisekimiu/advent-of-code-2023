#include "GalaxyDistances.h"

void GalaxyDistances::addLine(const std::string &line) {
    grid.addLine(line);
}

static unsigned int numberOfPairs(unsigned int size) {
    return size * (size-1) /2;
}

std::vector<GalacticDistance> GalaxyDistances::getDistances() {
    if (!expanded) {
        grid.expand();
        expanded = true;
    }
    std::vector<Point> galaxies = grid.scan('#');
    std::vector<GalacticDistance> distances;
    distances.reserve(numberOfPairs(galaxies.size()));
    for (int i = 0; i < galaxies.size(); i++) {
        for (int j = i + 1; j < galaxies.size(); j++) {
            GalacticDistance dist = pointDistance(galaxies[i], galaxies[j]);
            distances.push_back(dist);
        }
    }
    return distances;
}

GalacticDistance GalaxyDistances::pointDistance(const Point &p1, const Point &p2) {
    unsigned int xDist = std::abs(static_cast<int>(p1.x) - static_cast<int>(p2.x));
    unsigned int yDist = std::abs(static_cast<int>(p1.y) - static_cast<int>(p2.y));
    return xDist + yDist;
}
