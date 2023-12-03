#include "PartsGrid.h"
#include <regex>
#include <algorithm>

void PartsGrid::addLine(const std::string &line) {
    lines.push_back(line);
}

std::vector<PartNumber> PartsGrid::getValidNumbers() const {
    std::vector<PartNumber> numbers;
    int gridPosition = 0;
    for (int i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
        const std::regex numMatcher = std::regex("(\\d+)");
        int lineOffset = 0;
        for (std::smatch matches; std::regex_search(line, matches, numMatcher);) {
            const int number = std::stoi(matches[1].str());
            int startChar = static_cast<int>(matches[1].first - 1 - line.begin());
            int endChar = static_cast<int>(matches[1].second + 1  - line.begin());
            bool valid = scanForSpecialChars(line, startChar, endChar, 0);
            if (!valid) {
                if (i > 0) {
                    valid = scanForSpecialChars(lines[i - 1], startChar, endChar, lineOffset);
                }
                if (i < lines.size() - 1) {
                    valid = valid || scanForSpecialChars(lines[i + 1], startChar, endChar, lineOffset);
                }
            }
            if (valid) {
                numbers.push_back(number);
            }
            lineOffset += static_cast<int>(line.size() - matches.suffix().length());
            gridPosition += lineOffset;
            line = matches.suffix();
        }
    }
    return numbers;
}

bool PartsGrid::scanForSpecialChars(const std::string &line, int startChar, int endChar, int offset) {
    startChar = std::max(startChar, 0);
    endChar = std::min(endChar, static_cast<int>(line.size()) - offset);
    for (unsigned long i = startChar; i < endChar; i++) {
        const char c = line[i + offset];
        if (c != '.' && !(c >= '0' && c <= '9')) {
            return true;
        }
    }
    return false;
}