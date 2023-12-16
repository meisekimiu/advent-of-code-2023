#include "GalaxyDistances.h"
#include <stdexcept>

void GalaxyDistances::addLine(const std::string &line) {
    grid.addLine(line);
}

static unsigned int numberOfPairs(unsigned int size) {
    return size * (size-1) /2;
}

std::vector<GalacticDistance> GalaxyDistances::getDistances() {
    if (!expanded) {
        grid.expand();
        expansionRows = grid.getExpansionRows();
        expansionColumns = grid.getExpansionColumns();
        expanded = true;
    }
    const std::vector<Point> galaxies = grid.scan('#');
    std::vector<GalacticDistance> distances;
    distances.reserve(numberOfPairs(galaxies.size()));
    for (int i = 0; i < galaxies.size(); i++) {
        for (int j = i + 1; j < galaxies.size(); j++) {
            GalacticPoint galaxyI = getPositionWithExpansion(galaxies[i]);
            GalacticPoint galaxyJ = getPositionWithExpansion(galaxies[j]);
            GalacticDistance dist = pointDistance(galaxyI, galaxyJ);
            distances.push_back(dist);
        }
    }
    return distances;
}

GalacticDistance GalaxyDistances::pointDistance(const GalacticPoint &p1, const GalacticPoint &p2) {
    GalacticDistance xDist = std::max(p1.x, p2.x) - std::min(p1.x, p2.x);
    GalacticDistance yDist = std::max(p1.y, p2.y) - std::min(p1.y, p2.y);
    return xDist + yDist;
}

GalacticPoint GalaxyDistances::getPositionWithExpansion(const Point &gridPoint) {
    GalacticPoint p = gridPoint;
    for (const auto row : expansionRows) {
        if (row < gridPoint.y) {
            p.y += cosmicExpansionRate;
        }
    }
    for (const auto column : expansionColumns) {
        if (column < gridPoint.x) {
            p.x += cosmicExpansionRate;
        }
    }
    return p;
}

GalacticPoint::GalacticPoint(const Point &p) {
    x = p.x;
    y = p.y;
}
