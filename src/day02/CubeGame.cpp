#include "CubeGame.h"
#include <algorithm>
#include <regex>

void CubeGame::addResults(CubeCount red, CubeCount green, CubeCount blue) {
    results.push_back({red, green, blue});
}

bool CubeGame::isPossible(CubeCount red, CubeCount green, CubeCount blue) const {
    return std::none_of(results.begin(), results.end(), [red, green, blue](CubeResults result) {
        return result.red > red || result.green > green || result.blue > blue;
    });
}

void CubeGame::parseLine(const std::string &line) {
    parseGameId(line);
    const std::regex resultsMatcher("((\\d+) (red|green|blue),?\\s*)+?(;|$)");
    std::string searchLine = line;
    for (std::smatch match; std::regex_search(searchLine, match, resultsMatcher);) {
        auto gameString = match.str();
        CubeCount red = getColorMatch(gameString, "(\\d+) red");
        CubeCount green = getColorMatch(gameString, "(\\d+) green");
        CubeCount blue = getColorMatch(gameString, "(\\d+) blue");
        addResults(red, green, blue);
        searchLine = match.suffix();
    }
}

CubeCount CubeGame::getColorMatch(const std::string &gameString, const std::string& regex) {
    CubeCount count = 0;
    std::regex colorMatcher(regex);
    std::smatch colorMatches;
    bool matched = std::regex_search(gameString, colorMatches, colorMatcher);
    if (matched && colorMatches.size() > 1) {
        count = std::stoi(colorMatches[1]);
    }
    return count;
}

void CubeGame::parseGameId(const std::string &line) {
    const std::regex idMatcher("Game ([0-9]+):");
    std::smatch idMatch;
    bool matched = std::regex_search(line, idMatch, idMatcher);
    if (matched && idMatch.size() > 1) {
        id = std::stoi(idMatch[1]);
    }
}

CubeResults CubeGame::getMinimumValidCubes() const {
    CubeResults min{0,0,0};
    for(const CubeResults &r : results) {
        min.red = std::max(min.red, r.red);
        min.green = std::max(min.green, r.green);
        min.blue = std::max(min.blue, r.blue);
    }
    return min;
}
