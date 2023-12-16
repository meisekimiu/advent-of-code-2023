#ifndef ADVENT_OF_CODE_SPACEGRID_H
#define ADVENT_OF_CODE_SPACEGRID_H
#include "../util/Grid.h"

class SpaceGrid : public Grid {
public:
    void expand();
    std::vector<unsigned int> getExpansionColumns();
    std::vector<unsigned int> getExpansionRows();

private:
    std::vector<unsigned int> columnsToAdd;
    std::vector<unsigned int> rowsToAdd;

    void getExpansionRowsAndColumns();
};


#endif //ADVENT_OF_CODE_SPACEGRID_H
