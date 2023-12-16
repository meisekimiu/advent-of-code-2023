#ifndef ADVENT_OF_CODE_GRID_H
#define ADVENT_OF_CODE_GRID_H
#include <string>
#include <vector>

struct Point {
    unsigned int x;
    unsigned int y;

    friend bool operator==(const Point &p1, const Point &p2);
    friend bool operator!=(const Point &p1, const Point &p2);
};

struct BorderingPoints {
    Point *north{nullptr};
    Point *south{nullptr};
    Point *east{nullptr};
    Point *west{nullptr};
    std::vector<Point> points;
};

class Grid {
public:
    char nullChar{'.'};
    void addLine(const std::string &line);
    [[nodiscard]] char at(unsigned int x, unsigned int y) const;
    [[nodiscard]] std::vector<Point> scan(char c) const;
    [[nodiscard]] BorderingPoints borderPoints(unsigned int x, unsigned int y) const;
    [[nodiscard]] unsigned int getWidth() const;
    [[nodiscard]] unsigned int getHeight() const;

protected:
    std::vector<std::vector<char>> grid;
    unsigned int width{0};
    unsigned int height{0};

private:
    void checkInBounds(unsigned int x, unsigned int y) const;

    void setBorderPoint(BorderingPoints &points, unsigned int destX, unsigned int destY, Point *& destDir) const;
};


#endif //ADVENT_OF_CODE_GRID_H
