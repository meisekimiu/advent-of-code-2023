#ifndef ADVENT_OF_CODE_GALAXYDISTANCES_H
#define ADVENT_OF_CODE_GALAXYDISTANCES_H
#include "SpaceGrid.h"

typedef unsigned int GalacticDistance;

class GalaxyDistances {
public:
    void addLine(const std::string &line);
    std::vector<GalacticDistance> getDistances();

private:
    SpaceGrid grid;
    bool expanded{false};

    static GalacticDistance pointDistance(const Point &p1, const Point &p2);
};


#endif //ADVENT_OF_CODE_GALAXYDISTANCES_H
