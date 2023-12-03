#ifndef ADVENT_OF_CODE_PARTSGRID_H
#define ADVENT_OF_CODE_PARTSGRID_H
#include <string>
#include <algorithm>
typedef unsigned short PartNumber;

class PartsGrid {
public:
    void addLine(const std::string &line);
    [[nodiscard]] std::vector<PartNumber> getValidNumbers() const;

private:
    std::vector<std::string> lines;

    [[nodiscard]] static bool scanForSpecialChars(const std::string &line, int startChar, int endChar, int offset);
};


#endif //ADVENT_OF_CODE_PARTSGRID_H
