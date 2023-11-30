#ifndef ADVENT_OF_CODE_DAYCONFIG_H
#define ADVENT_OF_CODE_DAYCONFIG_H
#include "AdventFactory.h"
#include "testday00/TestDay.h"
#include "testday01/TestDay2020.h"

AdventFactory getAdventFactory() {
    AdventFactory f;
    f.registerDay("testday00", []() {return static_cast<AdventDay*>(new TestDay());});
    f.registerDay("testday01", []() {return static_cast<AdventDay*>(new TestDay2020());});
    return f;
}

#endif //ADVENT_OF_CODE_DAYCONFIG_H
