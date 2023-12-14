#ifndef ADVENT_OF_CODE_DAYCONFIG_H
#define ADVENT_OF_CODE_DAYCONFIG_H
#include "AdventFactory.h"
#include "testday00/TestDay.h"
#include "testday01/TestDay2020.h"
#include "day01/Day01.h"
#include "day02/Day02.h"
#include "day03/Day03.h"
#include "day04/Day04.h"
#include "day05/Day05.h"
#include "day06/Day06.h"
#include "day07/Day07.h"
#include "day08/Day08.h"

AdventFactory getAdventFactory() {
    AdventFactory f;
    f.registerDay("testday00", []() {return static_cast<AdventDay*>(new TestDay());});
    f.registerDay("testday01", []() {return static_cast<AdventDay*>(new TestDay2020());});
    f.registerDay("day01", []() {return static_cast<AdventDay*>(new Day01());});
    f.registerDay("day02", []() {return static_cast<AdventDay*>(new Day02());});
    f.registerDay("day03", []() {return static_cast<AdventDay*>(new Day03());});
    f.registerDay("day04", []() {return static_cast<AdventDay*>(new Day04());});
    f.registerDay("day05", []() {return static_cast<AdventDay*>(new Day05());});
    f.registerDay("day06", []() {return static_cast<AdventDay*>(new Day06());});
    f.registerDay("day07", []() {return static_cast<AdventDay*>(new Day07());});
    f.registerDay("day08", []() {return static_cast<AdventDay*>(new Day08());});
    return f;
}

#endif //ADVENT_OF_CODE_DAYCONFIG_H
