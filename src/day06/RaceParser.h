#ifndef ADVENT_OF_CODE_RACEPARSER_H
#define ADVENT_OF_CODE_RACEPARSER_H
#include <string>
#include <vector>
#include "Race.h"

class RaceParser {
public:
    bool readSingleNumber{false};
    void readLine(const std::string &line);
    std::vector<Race> generateRaces();

protected:
    std::vector<RaceLength> raceTimes;
    std::vector<RaceLength> raceDistances;

private:
    static std::vector<RaceLength> extractMultipleNumbersFromLine(std::string line);
    static RaceLength extractSingleNumberFromLine(std::string line);
    void parseParameter(const std::string &line, const std::string &token, std::vector<RaceLength> &destination) ;
    [[nodiscard]] std::vector<RaceLength> extractNumbersFromLine(const std::string &line) const;
};


#endif //ADVENT_OF_CODE_RACEPARSER_H
