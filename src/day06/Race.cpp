#include "Race.h"

int Race::charge(int ms) const {
    return (time - ms) * ms;
}

bool Race::chargeBeatsRecord(int ms) const {
    return charge(ms) > distance;
}

int Race::numberOfWinningRaces() const {
    int winningRaces = 0;
    for (int i = 0; i < time; i++) {
        if (chargeBeatsRecord(i)) {
            winningRaces++;
        }
    }
    return winningRaces;
}
