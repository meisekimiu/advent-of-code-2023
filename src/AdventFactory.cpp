#include "AdventFactory.h"
#include <stdexcept>

void AdventFactory::registerDay(const std::string& key, AdventConstructor constructor) {
    registry[key] = constructor;
}

AdventDay* AdventFactory::createDay(int argc, const char **argv) const {
    std::vector<std::string> args = getArgumentVector(argc, argv);
    if (args.size() < 2) {
        throw std::out_of_range("No arguments passed to adventFactory");
    }
    auto it = registry.find(args[1]);
    if (it == registry.end()) {
        return nullptr;
    }
    auto day = it->second();
    args.erase(args.begin());
    args.erase(args.begin());
    day->setArgs(args);
    return day;
}

std::vector<std::string> AdventFactory::getArgumentVector(int argc, const char **argv) {
    std::vector<std::string> vArgs;
    for (int i = 0; i < argc; i++) {
        vArgs.emplace_back(argv[i]);
    }
    return vArgs;
}

std::vector<std::string> AdventFactory::getAvailableDays() const {
    std::vector<std::string> days;
    for (const auto & it : registry) {
        days.push_back(it.first);
    }
    return days;
}
