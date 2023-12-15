#include "Grid.h"
#include <stdexcept>

void Grid::addLine(const std::string &line) {
    std::vector<char> vec;
    vec.reserve(line.length());
    for (const char c : line) {
        vec.push_back(c);
    }
    grid.push_back(vec);
    height++;
    width = std::max(width, static_cast<unsigned int>(line.length()));
}

char Grid::at(unsigned int x, unsigned int y) const {
    checkInBounds(x, y);
    if (grid[y].size() <= x) {
        return nullChar;
    }
    return grid[y][x];
}

unsigned int Grid::getWidth() const {
    return width;
}

unsigned int Grid::getHeight() const {
    return height;
}

std::vector<Point> Grid::scan(char c) const {
    std::vector<Point> points;
    unsigned int x = 0, y = 0;
    for (const auto &vec : grid) {
        for (const char p : vec) {
            if (p == c) {
                points.push_back({x, y});
            }
            x++;
        }
        x = 0;
        y++;
    }
    return points;
}

BorderingPoints Grid::borderPoints(unsigned int x, unsigned int y) const {
    checkInBounds(x, y);
    BorderingPoints points;
    points.points.reserve(4);
    setBorderPoint(points, x - 1, y, points.west);
    setBorderPoint(points, x, y + 1, points.south);
    setBorderPoint(points, x, y - 1, points.north);
    setBorderPoint(points, x + 1, y, points.east);
    return points;
}

void Grid::setBorderPoint(BorderingPoints& points, unsigned int destX, unsigned int destY, Point *&destDir) const {
    if (destX < width && destY < height) {
        points.points.push_back({destX, destY});
        destDir = &points.points.back();
    }
}

void Grid::checkInBounds(unsigned int x, unsigned int y) const {
    if (y >= height || x >= width) {
        throw std::runtime_error("Trying to fetch coordinate outside of grid boundaries");
    }
}

bool operator==(const Point &p1, const Point &p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const Point &p1, const Point &p2) {
    return !(p1 == p2);
}
