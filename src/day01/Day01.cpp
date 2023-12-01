#include "Day01.h"
#include <algorithm>
#include <fstream>
#include <iostream>

int Day01::mainPartOne() {
    readInput("data/day01/input.txt");
    std::cout << getCalibrationSum(false) << std::endl;
    return EXIT_SUCCESS;
}

int Day01::mainPartTwo() {
    readInput("data/day01/input.txt");
    std::cout << getCalibrationSum(true) << std::endl;
    return EXIT_SUCCESS;
}


int Day01::findCalibration(std::string line, bool spelledDigits) {
    if (spelledDigits) {
        line = replaceSpelledDigits(line);
    }
    int tens = getFirstDigitInString(line);
    std::reverse(line.begin(), line.end());
    int ones = getFirstDigitInString(line);
    return tens * 10 + ones;
}

int Day01::getFirstDigitInString(const std::string &line) {
    for (const char c : line) {
        int numValue = digitToValue(c);
        if (numValue > 0 && numValue < 10) {
            return numValue;
        }
    }
    return 0;
}

int Day01::digitToValue(char c) { return c - '0'; }

void Day01::setLines(const std::vector<std::string>& l) {
    lines = l;
}

int Day01::getCalibrationSum(bool spelledDigits) {
    int sum = 0;
    std::for_each(lines.begin(), lines.end(), [&sum, spelledDigits](std::string& line) {
        int calibration = findCalibration(line, spelledDigits);
        sum += calibration;
    });
    return sum;
}

void Day01::readInput(const char *path) {
    lines.clear();
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
}

std::string Day01::replaceSpelledDigits(std::string str) {
    std::vector<std::string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < str.length(); i++) {
        for (int d = 0; d < digits.size(); d++) {
            auto digit = digits[d];
            if (str.find(digit, i) == i) {
                str.replace(i, 1, {static_cast<char>(d + '0')});
            }
        }
    }
    return str;
}
