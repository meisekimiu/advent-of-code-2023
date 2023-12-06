#ifndef ADVENT_OF_CODE_DAY01_H
#define ADVENT_OF_CODE_DAY01_H
#include "../include/AdventDay.h"

class Day01 : public AdventDay {
public:
    static int findCalibration(std::string line, bool spelledDigits);
    int mainPartOne() override;
    int mainPartTwo() override;
    void setLines(const std::vector<std::string>& l);
    int getCalibrationSum(bool spelledDigits);


protected:
    void parseLine(const std::string &line) override;

private:
    static int getFirstDigitInString(const std::string &line);
    static int digitToValue(char c);
    static std::string replaceSpelledDigits(std::string str);
    std::vector<std::string> lines;
};


#endif //ADVENT_OF_CODE_DAY01_H
