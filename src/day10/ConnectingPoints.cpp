#include "ConnectingPoints.h"

Point ConnectingPoints::next(Point previous) const {
    if (first != nullptr && second != nullptr) {
        if (previous == *first) {
            return *second;
        }
        return *first;
    }
    if (first) {
        return *first;
    }
    if (second) {
        return *second;
    }
    throw std::runtime_error("No valid next point");
}

bool ConnectingPoints::contains(const Point &point) const {
    return (first && *first == point) || (second && *second == point);
}