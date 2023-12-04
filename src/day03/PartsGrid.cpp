#include "PartsGrid.h"
#include <regex>
#include <algorithm>

void PartsGrid::addLine(const std::string &line) {
    lines.push_back(line);
}

std::vector<PartNumber> PartsGrid::getValidNumbers() const {
    PartsScanner scanner(lines);
    return scanner.getPartNumbers();
}

std::vector<Gear> PartsGrid::getGears() const {
    PartsScanner scanner(lines);
    return scanner.getGears();
}
