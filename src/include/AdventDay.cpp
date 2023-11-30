#include "AdventDay.h"

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
