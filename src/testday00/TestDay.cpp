#include "TestDay.h"
#include <iostream>

int TestDay::mainPartOne() {
    std::cout << "Hello World!" << std::endl;
    std::cout << "Args:" << std::endl;
    for (const auto &arg : args) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
