#ifndef ADVENT_OF_CODE_DAYCONFIG_H
#define ADVENT_OF_CODE_DAYCONFIG_H
#include "AdventFactory.h"
#include "testday00/TestDay.h"

const AdventFactory getAdventFactory() {
    AdventFactory f;
    f.registerDay("testday00", []() {return static_cast<AdventDay*>(new TestDay());});
    return f;
}

#endif //ADVENT_OF_CODE_DAYCONFIG_H
