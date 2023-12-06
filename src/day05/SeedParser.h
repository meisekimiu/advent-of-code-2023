#ifndef ADVENT_OF_CODE_SEEDPARSER_H
#define ADVENT_OF_CODE_SEEDPARSER_H
#include <string>
#include "SeedMap.h"

class SeedParser {
public:
    std::vector<Seed> startingSeeds;
    SeedMap map;

    void parse(const std::string& in);

private:
    std::string input;
    SeedMapLayer currentLayer;

    void extractSeedsFromMatch(const std::string &matchStr);

    void parseStartingSeeds(const std::string &in);
};


#endif //ADVENT_OF_CODE_SEEDPARSER_H
