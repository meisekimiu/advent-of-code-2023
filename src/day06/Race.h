#ifndef ADVENT_OF_CODE_RACE_H
#define ADVENT_OF_CODE_RACE_H

struct Race {
    int time;
    int distance;

    [[nodiscard]] int charge(int ms) const;
    [[nodiscard]] bool chargeBeatsRecord(int ms) const;
    int numberOfWinningRaces() const;
};

#endif //ADVENT_OF_CODE_RACE_H
