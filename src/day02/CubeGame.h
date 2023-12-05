#ifndef ADVENT_OF_CODE_CUBEGAME_H
#define ADVENT_OF_CODE_CUBEGAME_H
#include <vector>
#include <string>
typedef unsigned short CubeCount;

struct CubeResults {
    CubeCount red;
    CubeCount green;
    CubeCount blue;
};

class CubeGame {
public:
    int id;
    void addResults(CubeCount red, CubeCount green, CubeCount blue);
    [[nodiscard]] bool isPossible(CubeCount red, CubeCount green, CubeCount blue) const;
    void parseLine(const std::string &line);
    [[nodiscard]] CubeResults getMinimumValidCubes() const;

protected:
    std::vector<CubeResults> results;

    void parseGameId(const std::string &line);

    [[nodiscard]] static CubeCount getColorMatch(const std::string &gameString, const std::string &regex) ;
};


#endif //ADVENT_OF_CODE_CUBEGAME_H
