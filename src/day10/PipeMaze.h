#ifndef ADVENT_OF_CODE_PIPEMAZE_H
#define ADVENT_OF_CODE_PIPEMAZE_H
#include "Grid.h"
#include "ConnectingPoints.h"

class PipeMaze {
public:
    void addLine(const std::string &line);
    [[nodiscard]] Point getStartingPoint() const;
    [[nodiscard]] std::vector<Point> getMazePoints() const;
    Grid getGrid() const;

private:
    Grid grid;

    [[nodiscard]] ConnectingPoints getPipeConnections(const Point &p, const BorderingPoints &borders) const;

    [[nodiscard]] Point getFirstPipeConnectedToStart(const Point &start, const BorderingPoints &startBorders) const;

    [[nodiscard]] bool isPointAPipe(const Point &p) const;
};


#endif //ADVENT_OF_CODE_PIPEMAZE_H
