#include "AdventDay.h"
#include <fstream>
#include <sstream>

void AdventDay::setArgs(const std::vector<std::string>& a) {
    this->args = a;
    if (!args.empty()) {
        if (args[0] == "part2" || args[0] == "parttwo" || args[0] == "--part2" || args[0] == "--parttwo") {
            part = true;
            args.erase(args.begin());
        }
    }
}

int AdventDay::mainPartTwo() {
    return EXIT_SUCCESS;
}

bool AdventDay::isPartOne() const {
    return !part;
}

int AdventDay::run() {
    if (isPartOne()) {
        return mainPartOne();
    }
    return mainPartTwo();
}

void AdventDay::parseLine(const std::string &line) {
    // do nothing
}

void AdventDay::readInput(const char *path) {
    std::ifstream file(path);
    std::string line;
    while(std::getline(file, line)) {
        parseLine(line);
    }
}

void AdventDay::readInputString(const std::string &input) {
    std::istringstream iss(input);
    std::string line;
    while (std::getline(iss, line)) {
        parseLine(line);
    }
}
