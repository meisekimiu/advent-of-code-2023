#ifndef ADVENT_OF_CODE_GALAXYDISTANCES_H
#define ADVENT_OF_CODE_GALAXYDISTANCES_H
#include "SpaceGrid.h"

typedef unsigned long long GalacticDistance;

struct GalacticPoint {
    GalacticDistance x;
    GalacticDistance y;

    GalacticPoint(const Point& p);
};

class GalaxyDistances {
public:
    GalacticDistance cosmicExpansionRate{1};
    void addLine(const std::string &line);
    std::vector<GalacticDistance> getDistances();

private:
    SpaceGrid grid;
    bool expanded{false};
    std::vector<unsigned int> expansionRows;
    std::vector<unsigned int> expansionColumns;

    GalacticPoint getPositionWithExpansion(const Point &gridPoint);
    static GalacticDistance pointDistance(const GalacticPoint &p1, const GalacticPoint &p2);
};


#endif //ADVENT_OF_CODE_GALAXYDISTANCES_H
