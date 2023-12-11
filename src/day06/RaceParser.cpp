#include "RaceParser.h"
#include <regex>
#include <stdexcept>

void RaceParser::readLine(const std::string &line) {
    parseParameter(line, "Time", raceTimes);
    parseParameter(line, "Distance", raceDistances);
}

void RaceParser::parseParameter(const std::string &line, const std::string &token, std::vector<int> &destination) {
    const std::regex paramMatcher = std::regex("^" + token + ":\\s+(\\d+)");
    if (std::regex_search(line, paramMatcher)) {
        destination = extractIntsFromLine(line);
    }
}

std::vector<int> RaceParser::extractIntsFromLine(std::string line) {
    std::vector<int> ints;
    const std::regex intMatcher = std::regex("(\\d+)");
    for (std::smatch matches; std::regex_search(line, matches, intMatcher);) {
        ints.push_back(std::stoi(matches[1]));
        line = matches.suffix();
    }
    return ints;
}

std::vector<Race> RaceParser::generateRaces() {
    if (raceTimes.size() != raceDistances.size()) {
        throw std::runtime_error("Quantity of Race Times and Distances are not equal");
    }
    std::vector<Race> races;
    for (int i = 0; i < raceTimes.size(); i++) {
        Race r{};
        r.time = raceTimes[i];
        r.distance = raceDistances[i];
        races.push_back(r);
    }
    return races;
}
