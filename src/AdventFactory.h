#ifndef ADVENT_OF_CODE_ADVENTFACTORY_H
#define ADVENT_OF_CODE_ADVENTFACTORY_H
#include "include/AdventDay.h"
#include <unordered_map>

typedef AdventDay* (*AdventConstructor)();

class AdventFactory {
public:
    static std::vector<std::string> getArgumentVector(int argc, const char** argv);

    AdventDay* createDay(int argc, const char** argv) const;
    void registerDay(const std::string& key, AdventConstructor constructor);
    std::vector<std::string> getAvailableDays() const;

private:
    std::unordered_map<std::string, AdventConstructor> registry;
};


#endif //ADVENT_OF_CODE_ADVENTFACTORY_H
