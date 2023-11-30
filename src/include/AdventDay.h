#ifndef ADVENT_OF_CODE_ADVENTDAY_H
#define ADVENT_OF_CODE_ADVENTDAY_H
#include <vector>
#include <string>

class AdventDay {
public:
    [[nodiscard]] virtual int mainPartOne() = 0;
    [[nodiscard]] virtual int mainPartTwo();
    void setArgs(const std::vector<std::string>& args);
    int run();

protected:
    std::vector<std::string> args;
    [[nodiscard]] bool isPartOne() const;

private:
    bool part{false};
};


#endif //ADVENT_OF_CODE_ADVENTDAY_H
