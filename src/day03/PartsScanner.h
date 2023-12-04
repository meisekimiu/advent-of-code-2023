#ifndef ADVENT_OF_CODE_PARTSSCANNER_H
#define ADVENT_OF_CODE_PARTSSCANNER_H
#include <set>
#include <string>
#include <vector>
#include <regex>

typedef unsigned short PartNumber;

struct Gear {
    int position;
    std::set<PartNumber> adjacentNumbers;

    int getRatio() const;
};

class PartsScanner {
public:
    explicit PartsScanner(const std::vector<std::string> &lines);
    std::vector<PartNumber> getPartNumbers();
    std::vector<Gear> getGears();

private:
    std::vector<std::string> lines;
    std::vector<PartNumber> numbers;
    std::vector<Gear> gears;

    int position{0};
    std::string workingLine;
    int currentNumber{0};
    int startingChar{0};
    int endingChar{0};
    int lineOffset{0};

    void scan();
    bool scanForSpecialChars(int line);

    std::vector<int> getBorderingLines(int i);

    void getStartingEndingChars(std::string &line, const std::smatch &matches);
};


#endif //ADVENT_OF_CODE_PARTSSCANNER_H
