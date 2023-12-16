#include "SpaceGrid.h"
#include <set>

void SpaceGrid::expand() {
    getExpansionRowsAndColumns();
}

void SpaceGrid::getExpansionRowsAndColumns() {
    const std::vector<Point> galaxyLocations = scan('#');
    std::set<unsigned int> galaxyRows, galaxyColumns;
    for (const Point& p : galaxyLocations) {
        galaxyRows.insert(p.y);
        galaxyColumns.insert(p.x);
    }
    const unsigned int originalWidth = width;
    for (unsigned int x = 0; x < originalWidth; x++) {
        if (galaxyColumns.find(x) == galaxyColumns.end()) {
            columnsToAdd.push_back(x);
        }
    }
    const unsigned int originalHeight = height;
    for (unsigned int y = 0; y < originalHeight; y++) {
        if (galaxyRows.find(y) == galaxyRows.end()) {
            rowsToAdd.push_back(y);
        }
    }
}

std::vector<unsigned int> SpaceGrid::getExpansionColumns() {
    return columnsToAdd;
}

std::vector<unsigned int> SpaceGrid::getExpansionRows() {
    return rowsToAdd;
}
