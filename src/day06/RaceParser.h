#ifndef ADVENT_OF_CODE_RACEPARSER_H
#define ADVENT_OF_CODE_RACEPARSER_H
#include <string>
#include <vector>
#include "Race.h"

class RaceParser {
public:
    void readLine(const std::string &line);
    std::vector<Race> generateRaces();

protected:
    std::vector<int> raceTimes;
    std::vector<int> raceDistances;

private:
    static std::vector<int> extractIntsFromLine(std::string line);
    static void parseParameter(const std::string &line, const std::string &token, std::vector<int> &destination) ;
};


#endif //ADVENT_OF_CODE_RACEPARSER_H
