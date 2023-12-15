#ifndef ADVENT_OF_CODE_CONNECTINGPOINTS_H
#define ADVENT_OF_CODE_CONNECTINGPOINTS_H

#include "Grid.h"
#include <stdexcept>

struct ConnectingPoints {
    Point* first;
    Point* second;

    [[nodiscard]] Point next(Point previous) const;
    [[nodiscard]] bool contains(const Point& point) const;
};

#endif //ADVENT_OF_CODE_CONNECTINGPOINTS_H
