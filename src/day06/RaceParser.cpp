#include "RaceParser.h"
#include <regex>
#include <stdexcept>

void RaceParser::readLine(const std::string &line) {
    parseParameter(line, "Time", raceTimes);
    parseParameter(line, "Distance", raceDistances);
}

void RaceParser::parseParameter(const std::string &line, const std::string &token, std::vector<RaceLength> &destination) {
    const std::regex paramMatcher = std::regex("^" + token + ":\\s+(\\d+)");
    if (std::regex_search(line, paramMatcher)) {
        destination = extractNumbersFromLine(line);
    }
}

std::vector<RaceLength> RaceParser::extractNumbersFromLine(const std::string &line) const {
    if (readSingleNumber) {
        return std::vector<RaceLength>{extractSingleNumberFromLine(line)};
    }
    return extractMultipleNumbersFromLine(line);
}

std::vector<RaceLength> RaceParser::extractMultipleNumbersFromLine(std::string line) {
    std::vector<RaceLength> ints;
    const std::regex intMatcher = std::regex("(\\d+)");
    for (std::smatch matches; std::regex_search(line, matches, intMatcher);) {
        ints.push_back(std::stoi(matches[1]));
        line = matches.suffix();
    }
    return ints;
}

RaceLength RaceParser::extractSingleNumberFromLine(std::string line) {
    std::string singleNumber;
    const std::regex intMatcher = std::regex("(\\d+)");
    for (std::smatch matches; std::regex_search(line, matches, intMatcher);) {
        singleNumber += matches[1];
        line = matches.suffix();
    }
    return std::stoll(singleNumber);
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
