#ifndef ADVENT_OF_CODE_PARTSGRID_H
#define ADVENT_OF_CODE_PARTSGRID_H
#include <string>
#include <algorithm>
#include "PartsScanner.h"

class PartsGrid {
public:
    void addLine(const std::string &line);
    [[nodiscard]] std::vector<PartNumber> getValidNumbers() const;
    [[nodiscard]] std::vector<Gear> getGears() const;

private:
    std::vector<std::string> lines;
};


#endif //ADVENT_OF_CODE_PARTSGRID_H
