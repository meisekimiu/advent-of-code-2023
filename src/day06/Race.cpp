#include "Race.h"

RaceLength Race::charge(RaceLength ms) const {
    return (time - ms) * ms;
}

bool Race::chargeBeatsRecord(RaceLength ms) const {
    return charge(ms) > distance;
}

RaceLength Race::numberOfWinningRaces() const {
    int losingRaces = 0;
    for (RaceLength i = 0; i < time / 2; i++) {
        if (chargeBeatsRecord(i)) {
            break;
        } else {
            losingRaces++;
        }
    }
    return (time + 1) - (losingRaces * 2);
}
