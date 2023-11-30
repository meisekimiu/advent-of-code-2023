#include <iostream>
#include "AdventFactory.h"
#include "dayConfig.h"

void help(const std::string& programName, const AdventFactory& factory) {
    std::cout << "Advent of Code 2023 Collection" << std::endl;
    std::cout << "By Natalie Martin" << std::endl;
    std::cout << std::endl;
    std::cout << "Usage: " << programName << " [DAY] [params]" << std::endl;
    std::cout << std::endl;
    auto days = factory.getAvailableDays();
    if (days.empty()) {
        std::cout << "Unfortunately no days are defined right now." << std::endl;
        return;
    }
    std::cout << "Where [DAY] is one of the following available modules:" << std::endl;
    for (const auto & day : days) {
        std::cout << "\t" << day << std::endl;
    }
}

int main(int argc, const char** argv) {
    const AdventFactory factory = getAdventFactory();
    if (argc < 2) {
        help(argv[0], factory);
        return EXIT_SUCCESS;
    }
    auto day = factory.createDay(argc, argv);
    if (day == nullptr) {
        std::cerr << "No day found with name." << std::endl;
        return EXIT_FAILURE;
    }
    return day->run();
}
