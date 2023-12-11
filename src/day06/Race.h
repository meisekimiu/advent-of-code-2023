#ifndef ADVENT_OF_CODE_RACE_H
#define ADVENT_OF_CODE_RACE_H

typedef unsigned long long int RaceLength;

struct Race {
    RaceLength time;
    RaceLength distance;

    [[nodiscard]] RaceLength charge(RaceLength ms) const;
    [[nodiscard]] bool chargeBeatsRecord(RaceLength ms) const;
    [[nodiscard]] RaceLength numberOfWinningRaces() const;
};

#endif //ADVENT_OF_CODE_RACE_H
