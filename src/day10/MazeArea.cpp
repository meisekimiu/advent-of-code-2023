#include "MazeArea.h"
#include <algorithm>

MazeArea::MazeArea(PipeMaze &m) : maze(m){
    loop = maze.getMazePoints();
    grid = maze.getGrid();
    minCoord = {grid.getWidth() - 1, grid.getHeight() - 1};
    maxCoord = {0, 0};
    initializeBoundingBox();
}

void MazeArea::initializeBoundingBox() {
    for (const Point& point : loop) {
        minCoord.x = std::min(point.x, minCoord.x);
        minCoord.y = std::min(point.y, minCoord.y);
        maxCoord.x = std::max(point.x, maxCoord.x);
        maxCoord.y = std::max(point.y, maxCoord.y);
    }
}

std::pair<Point, Point> MazeArea::getBoundingBox() const {
    return {minCoord, maxCoord};
}

Area MazeArea::getArea() {
    Area area = 0;
    for (unsigned int y = minCoord.y; y <= maxCoord.y; y++) {
        unsigned int crossedWalls = 0;
        BoundaryProperties boundsCrossed{false, false};
        for (unsigned int x = minCoord.x; x <= maxCoord.x; x++) {
            if (isPointInLoop(x, y)) {
                boundsCrossed.flipProps(propertiesOfGridChar(grid.at(x, y), false));
                if (boundsCrossed.isPerpendicular()) {
                    crossedWalls++;
                    boundsCrossed = {false, false};
                }
            } else {
                if (crossedWalls % 2 == 1) {
                    area++;
                }
            }
        }
    }
    return area;
}

bool MazeArea::isPointInLoop(unsigned int x, unsigned int y) {
    const auto it = std::find(loop.begin(), loop.end(), Point{x, y});
    bool isInLoop = it != loop.end();
    return isInLoop;
}

BoundaryProperties MazeArea::propertiesOfGridChar(char c, bool recursive) {
    BoundaryProperties p;
    switch (c) {
        case '|':
            p = {true, true};
            break;
        case 'F':
        case '7':
            p = {false, true};
            break;
        case 'L':
        case 'J':
            p = {true, false};
            break;
        case 'S':
            p = recursive ? BoundaryProperties{false, false} : propertiesOfStart();
            break;
        default:
            p = {false, false};
            break;
    }
    return p;
}

BoundaryProperties MazeArea::propertiesOfStart() {
    BoundaryProperties p{false, false};
    Point start = maze.getStartingPoint();
    BorderingPoints connections = grid.borderPoints(start.x, start.y);
    setPropertyIfStartConnects(p.up, connections.north, true);
    setPropertyIfStartConnects(p.down, connections.south, false);
    return p;
}

void MazeArea::setPropertyIfStartConnects(bool &destProp, Point *connection, bool north) {
    if (connection && isPointInLoop(connection->x, connection->y)) {
        char c = grid.at(connection->x, connection->y);
        BoundaryProperties props = propertiesOfGridChar(c, true);
        destProp = north ? props.down : props.up;
    }
}

void BoundaryProperties::flipProps(const BoundaryProperties &bounds) {
    if (bounds.up) {
        up = !up;
    }
    if (bounds.down) {
        down = !down;
    }
}

bool BoundaryProperties::isPerpendicular() const {
    return up && down;
}