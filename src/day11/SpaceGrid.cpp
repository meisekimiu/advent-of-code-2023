#include "SpaceGrid.h"
#include <set>

void SpaceGrid::expand() {
    getExpansionRowsAndColumns();
    while (!columnsToAdd.empty()) {
        addColumn();
    }
    while (!rowsToAdd.empty()) {
        addRow();
    }
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

void SpaceGrid::addColumn() {
    unsigned int x = columnsToAdd.back();
    columnsToAdd.pop_back();
    for (auto &vec : grid) {
        vec.insert(vec.begin() + x, '.');
    }
    adjustValuesForExpansion(x, columnsToAdd);
    width++;
}

void SpaceGrid::adjustValuesForExpansion(unsigned int x, std::vector<unsigned int> &vector) {
    for (auto &val : vector) {
        if (val > x) {
            val++;
        }
    }
}

void SpaceGrid::addRow() {
    unsigned int y = rowsToAdd.back();
    rowsToAdd.pop_back();
    std::vector<char> row(width);
    std::fill(row.begin(), row.end(), '.');
    grid.insert(grid.begin() + y, row);
    adjustValuesForExpansion(y, rowsToAdd);
    height++;
}
