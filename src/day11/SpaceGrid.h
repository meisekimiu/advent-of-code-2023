#ifndef ADVENT_OF_CODE_SPACEGRID_H
#define ADVENT_OF_CODE_SPACEGRID_H
#include "../util/Grid.h"

class SpaceGrid : public Grid {
public:
    void expand();

private:
    std::vector<unsigned int> columnsToAdd;
    std::vector<unsigned int> rowsToAdd;

    void addColumn();
    void addRow();

    void getExpansionRowsAndColumns();

    static void adjustValuesForExpansion(unsigned int x, std::vector<unsigned int> &vector) ;
};


#endif //ADVENT_OF_CODE_SPACEGRID_H
