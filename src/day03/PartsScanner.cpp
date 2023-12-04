#include "PartsScanner.h"
#include <regex>
#include <numeric>

PartsScanner::PartsScanner(const std::vector<std::string> &lines) {
    this->lines = lines;
    scan();
}

std::vector<PartNumber> PartsScanner::getPartNumbers() {
    return numbers;
}

std::vector<Gear> PartsScanner::getGears() {
    std::vector<Gear> g;
    std::copy_if(gears.begin(), gears.end(), std::back_inserter(g), [](const Gear &g) {
       return g.adjacentNumbers.size() == 2;
    });
    return g;
}

void PartsScanner::scan() {
    for (int i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
        const std::regex numMatcher = std::regex("(\\d+)");
        lineOffset = 0;
        for (std::smatch matches; std::regex_search(line, matches, numMatcher);) {
            currentNumber = std::stoi(matches[1].str());
            getStartingEndingChars(line, matches);
            auto borderingLines = getBorderingLines(i);
            bool valid = std::any_of(borderingLines.begin(), borderingLines.end(), [&](int l) {
               return scanForSpecialChars(l);
            });
            if (valid) {
                numbers.push_back(currentNumber);
            }
            lineOffset += static_cast<int>(line.size() - matches.suffix().length());
            position += lineOffset;
            line = matches.suffix();
        }
    }
}

void PartsScanner::getStartingEndingChars(std::string &line, const std::smatch &matches) {
    unsigned long start = matches[1].first - 1 - line.begin();
    unsigned long ending = matches[1].second + 1 - line.begin();
    startingChar = std::max(0, static_cast<int>(start));
    endingChar = std::min(static_cast<int>(line.length()), static_cast<int>(ending));
}

std::vector<int> PartsScanner::getBorderingLines(int i) {
    std::vector<int> checkedLines;
    checkedLines.push_back(i);
    if (i > 0) {
        checkedLines.push_back(i - 1);
    }
    if (i < lines.size() - 1) {
        checkedLines.push_back(i + 1);
    }
    return checkedLines;
}

bool PartsScanner::scanForSpecialChars(int lineNum) {
    const std::string line = lines[lineNum];
    int pos = lineNum * static_cast<int>(lines[lineNum].length());
    for (int i = startingChar; i < endingChar; i++) {
        const char c = line[i + lineOffset];
        if (c == '*') {
            auto gearIt = std::find_if(gears.begin(), gears.end(), [&](const Gear& g) {
                return g.position == pos + i + lineOffset;
            });
            if (gearIt == gears.end()) {
                Gear g{pos + i + lineOffset, {static_cast<PartNumber>(currentNumber)}};
                gears.push_back(g);
            } else {
                gearIt->adjacentNumbers.insert(currentNumber);
            }
        }
        if (c != '.' && !(c >= '0' && c <= '9')) {
            return true;
        }
    }
    return false;
}

int Gear::getRatio() const {
    return std::accumulate(adjacentNumbers.begin(), adjacentNumbers.end(), 1, std::multiplies<>());
}
