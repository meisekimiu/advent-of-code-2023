#include "TestDay2020.h"
#include <fstream>
#include <iostream>

int TestDay2020::mainPartOne() {
    loadExpenses("data/testday01/input.txt");
    std::cout << find2020() << std::endl;
    return EXIT_SUCCESS;
}

int TestDay2020::mainPartTwo() {
    loadExpenses("data/testday01/input.txt");
    std::cout << find2020PartTwo() << std::endl;
    return EXIT_SUCCESS;
}

void TestDay2020::setExpenses(const std::vector<int>& list) {
    expenses = list;
}

int TestDay2020::find2020() {
    for (int i : expenses) {
        for (int j : expenses) {
            if (i + j == 2020) {
                return i * j;
            }
        }
    }
    return 0;
}

void TestDay2020::loadExpenses(const char* filepath) {
    std::ifstream file(filepath);
    int expense;
    while (file >> expense) {
        expenses.push_back(expense);
    }
}

int TestDay2020::find2020PartTwo() {
    for (int i : expenses) {
        for (int j : expenses) {
            if (i + j >= 2020) {
                continue;
            }
            for (int k : expenses) {
                if (i + j + k == 2020) {
                    return i * j * k;
                }
            }
        }
    }
    return 0;
}
