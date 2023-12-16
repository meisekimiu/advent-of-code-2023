#include "pointUtils.h"
#include <algorithm>

bool pointIsInVec(const std::vector<Point> &points, const Point &p) {
    return std::any_of(points.begin(), points.end(), [p](const Point &point) {
        return point == p;
    });
}