#include "PipeMaze.h"
#include <stdexcept>

void PipeMaze::addLine(const std::string &line) {
    grid.addLine(line);
}

Point PipeMaze::getStartingPoint() const {
    auto points = grid.scan('S');
    if (points.empty()) {
        throw std::runtime_error("Grid does not contain starting point");
    }
    return points.front();
}

std::vector<Point> PipeMaze::getMazePoints() const {
    std::vector<Point> points;
    const Point &start = getStartingPoint();
    points.push_back(start);
    const BorderingPoints startBorders = grid.borderPoints(start.x, start.y);
    Point cursor = getFirstPipeConnectedToStart(start, startBorders);
    if (cursor == start) {
        throw std::runtime_error("Nothing connects to starting point.");
    }
    Point prevPoint = start;
    while (cursor != start) {
        points.push_back(cursor);
        const BorderingPoints &borders = grid.borderPoints(cursor.x, cursor.y);
        const auto connectingPoints = getPipeConnections(cursor, borders);
        Point nextCursor = connectingPoints.next(prevPoint);
        prevPoint = cursor;
        cursor = nextCursor;
    }
    return points;
}

bool PipeMaze::isPointAPipe(const Point &p) const {
    const std::string validChars = "-|F7LJ";
    const char c = grid.at(p.x, p.y);
    return validChars.find(c) != std::string::npos;
}

Point PipeMaze::getFirstPipeConnectedToStart(const Point &start, const BorderingPoints &startBorders) const {
    Point cursor = start;
    for (const Point &p : startBorders.points) {
        if (isPointAPipe(p)) {
            const BorderingPoints &borders = grid.borderPoints(p.x, p.y);
            auto connections = getPipeConnections(p, borders);
            if (connections.contains(start)) {
                cursor = p;
                break;
            }
        }
    }
    return cursor;
}

ConnectingPoints PipeMaze::getPipeConnections(const Point &p, const BorderingPoints &borders) const {
    ConnectingPoints connections{};
    char c = grid.at(p.x, p.y);
    switch (c) {
        case '-':
            connections.first = borders.west;
            connections.second = borders.east;
            break;
        case '|':
            connections.first = borders.south;
            connections.second = borders.north;
            break;
        case 'F':
            connections.first = borders.south;
            connections.second = borders.east;
            break;
        case '7':
            connections.first = borders.west;
            connections.second = borders.south;
            break;
        case 'J':
            connections.first = borders.west;
            connections.second = borders.north;
            break;
        case 'L':
            connections.first = borders.east;
            connections.second = borders.north;
            break;
        default:
            throw std::runtime_error("Invalid pipe character");
    }
    return connections;
}

