#ifndef ADVENT_OF_CODE_HANDTYPES_H
#define ADVENT_OF_CODE_HANDTYPES_H

typedef unsigned char Card;
typedef unsigned char YakuValue;
typedef unsigned int Bet;
enum class CardYaku : YakuValue {
    HighCard = 0,
    OnePair = 1,
    TwoPairs = 2,
    ThreeOfAKind = 3,
    FullHouse = 4,
    FourOfAKind = 5,
    FiveOfAKind = 6,
    /* ThirteenOrphans = 13 ... whoops, wrong game */
};
#endif //ADVENT_OF_CODE_HANDTYPES_H
