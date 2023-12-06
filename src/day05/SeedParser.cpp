#include "SeedParser.h"
#include <regex>
#include <sstream>

void SeedParser::parse(const std::string& in) {
    parseStartingSeeds(in);
    std::istringstream iss(in);
    while (std::getline(iss, input))
    {
        const std::regex newMapMatcher = std::regex("(.+?) map:");
        if (std::regex_search(input, newMapMatcher)) {
            map.addLayer(SeedMapLayer());
        }
        const std::regex mapNumbersMatcher = std::regex("^(\\d+)\\s*(\\d+)\\s*(\\d+)");
        std::smatch matches;
        if (std::regex_search(input, matches, mapNumbersMatcher)) {
            Seed destinationStart = std::stol(matches[1].str());
            Seed sourceStart = std::stol(matches[2].str());
            Seed length = std::stol(matches[3].str());
            map.latestLayer().addMapData(
                    destinationStart,
                    sourceStart,
                    length);
        }
    }
}

void SeedParser::parseStartingSeeds(const std::string &in) {
    const std::regex seedMatcher = std::regex(R"(seeds:\s*((?:\d+\s*)+))");
    std::smatch matches;
    if (std::regex_search(in, matches, seedMatcher)) {
        extractSeedsFromMatch(matches[1].str());
    }
}

void SeedParser::extractSeedsFromMatch(const std::string &matchStr) {
    std::stringstream ss;
    int seedNum;
    std::string workingString;
    ss << matchStr;
    while (!ss.eof()) {
        ss >> workingString;
        if (std::stringstream(workingString) >> seedNum) {
            startingSeeds.push_back(seedNum);
        }
    }
}
