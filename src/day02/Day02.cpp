#include "Day02.h"
#include <fstream>
#include <iostream>

int Day02::mainPartOne() {
    readInput("data/day02/input.txt");
    std::cout << sumOfValidGameIds(12, 13, 14) << std::endl;
    return EXIT_SUCCESS;
}

int Day02::mainPartTwo() {
    readInput("data/day02/input.txt");
    std::cout << sumOfCubePower() << std::endl;
    return EXIT_SUCCESS;
}

void Day02::addGame(const std::string& line) {
    CubeGame game;
    game.parseLine(line);
    games.push_back(game);
}

int Day02::sumOfValidGameIds(CubeCount red, CubeCount green, CubeCount blue) const {
    int sum = 0;
    for (const auto &game : games) {
        if (game.isPossible(red, green, blue)) {
            sum += game.id;
        }
    }
    return sum;
}

void Day02::readInput(const char *path) {
    lines.clear();
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        addGame(line);
    }
}

int Day02::sumOfCubePower() const {
    int power = 0;
    for (const auto &game : games) {
        const CubeResults results = game.getMinimumValidCubes();
        power += results.red * results.green * results.blue;
    }
    return power;
}
