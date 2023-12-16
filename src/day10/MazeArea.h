#ifndef ADVENT_OF_CODE_MAZEAREA_H
#define ADVENT_OF_CODE_MAZEAREA_H
#include "PipeMaze.h"

typedef unsigned int Area;

struct BoundaryProperties {
    bool up{false};
    bool down{false};

    void flipProps(const BoundaryProperties &bounds);
    [[nodiscard]] bool isPerpendicular() const;
};

class MazeArea {
public:
    explicit MazeArea(PipeMaze &m);
    [[nodiscard]] std::pair<Point, Point> getBoundingBox() const;
    Area getArea();

private:
    PipeMaze &maze;
    Grid grid;
    std::vector<Point> loop;
    Point minCoord;
    Point maxCoord;

    void initializeBoundingBox();

    bool isPointInLoop(unsigned int x, unsigned int y);

    BoundaryProperties propertiesOfGridChar(char c, bool recursive);

    BoundaryProperties propertiesOfStart();

    void setPropertyIfStartConnects(bool &destProp, Point *connection, bool north);
};


#endif //ADVENT_OF_CODE_MAZEAREA_H
