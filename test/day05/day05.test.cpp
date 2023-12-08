#include <catch2/catch.hpp>
#include "../../src/day05/Day05.h"

TEST_CASE("Day 05", "[day05]") {
    Day05 day;

    SECTION("Advent of Code Examples") {
        std::string input("seeds: 79 14 55 13\n"
                          "\n"
                          "seed-to-soil map:\n"
                          "50 98 2\n"
                          "52 50 48\n"
                          "\n"
                          "soil-to-fertilizer map:\n"
                          "0 15 37\n"
                          "37 52 2\n"
                          "39 0 15\n"
                          "\n"
                          "fertilizer-to-water map:\n"
                          "49 53 8\n"
                          "0 11 42\n"
                          "42 0 7\n"
                          "57 7 4\n"
                          "\n"
                          "water-to-light map:\n"
                          "88 18 7\n"
                          "18 25 70\n"
                          "\n"
                          "light-to-temperature map:\n"
                          "45 77 23\n"
                          "81 45 19\n"
                          "68 64 13\n"
                          "\n"
                          "temperature-to-humidity map:\n"
                          "0 69 1\n"
                          "1 0 69\n"
                          "\n"
                          "humidity-to-location map:\n"
                          "60 56 37\n"
                          "56 93 4");
        SECTION("Example part 1") {
            day.readInputString(input);
            REQUIRE(day.getMinimumSeedLocation() == 35);
        }
        SECTION("Example part 2") {
            day.readInputString(input);
            REQUIRE(day.getMinimumSeedLocationUsingRanges() == 46);
        }
    }

    SECTION("SeedParser") {
        SeedParser parser;

        SECTION("Null case") {
            REQUIRE(parser.startingSeeds.empty());
            REQUIRE(parser.map.locateSeed(0) == 0);
        }

        SECTION("It parses the seed list") {
            parser.parse("seeds: 10 20 30 40");
            REQUIRE(parser.startingSeeds.size() == 4);
            REQUIRE(parser.startingSeeds[0] == 10);
            REQUIRE(parser.startingSeeds[1] == 20);
            REQUIRE(parser.startingSeeds[2] == 30);
            REQUIRE(parser.startingSeeds[3] == 40);
        }

        SECTION("It parses LONG ints in the seed list") {
            // This missing test case took HOURS of debugging to find
            parser.parse("seeds: 10 20 30 4000000000");
            REQUIRE(parser.startingSeeds.size() == 4);
            REQUIRE(parser.startingSeeds[0] == 10);
            REQUIRE(parser.startingSeeds[1] == 20);
            REQUIRE(parser.startingSeeds[2] == 30);
            REQUIRE(parser.startingSeeds[3] == 4e9);
        }

        SECTION("It parses one layer") {
            parser.parse("test map:\n"
                         "50 98 2\n"
                         "52 50 48\n");
            REQUIRE(parser.map.locateSeed(0) == 0);
            REQUIRE(parser.map.locateSeed(50) == 52);
            REQUIRE(parser.map.locateSeed(98) == 50);
        }

        SECTION("It parses multiple layers") {
            parser.parse("test map:\n"
                         "50 98 2\n"
                         "52 50 48\n"
                         "\n"
                         "test2 map:\n"
                         "0 15 37\n"
                         "37 52 2\n"
                         "39 0 15\n");
            REQUIRE(parser.map.locateSeed(79) == 81);
            REQUIRE(parser.map.locateSeed(14) == 53);
            REQUIRE(parser.map.locateSeed(1000) == 1000);
        }
    }

    SECTION("SeedMap") {
        SeedMap map;

        SECTION("Null case: if no layers are defined, it outputs the same number back") {
            REQUIRE(map.locateSeed(0) == 0);
            REQUIRE(map.locateSeed(50) == 50);
        }

        SECTION("Can add one layer") {
            SeedMapLayer layer;
            layer.addMapData(50, 98, 2);
            layer.addMapData(52, 50, 48);
            map.addLayer(layer);
            REQUIRE(map.locateSeed(0) == 0);
            REQUIRE(map.locateSeed(49) == 49);
            REQUIRE(map.locateSeed(50) == 52);
            REQUIRE(map.locateSeed(51) == 53);
            REQUIRE(map.locateSeed(97) == 99);
            REQUIRE(map.locateSeed(98) == 50);
            REQUIRE(map.locateSeed(99) == 51);
            REQUIRE(map.locateSeed(100) == 100);
        }

        SECTION("Can add multiple layers") {
            SeedMapLayer seedToSoil;
            SeedMapLayer soilToFertilizer;
            seedToSoil.addMapData(50, 98, 2);
            seedToSoil.addMapData(52, 50, 48);
            soilToFertilizer.addMapData(0, 15, 37);
            soilToFertilizer.addMapData(37, 52, 2);
            soilToFertilizer.addMapData(39, 0, 15);
            map.addLayer(seedToSoil);
            map.addLayer(soilToFertilizer);
            REQUIRE(map.locateSeed(79) == 81);
            REQUIRE(map.locateSeed(14) == 53);
            REQUIRE(map.locateSeed(1000) == 1000);
        }

        SECTION("Can process a range within a map") {
            SeedMapLayer mapA;
            SeedMapLayer mapB;
            mapA.addMapData(50, 98, 2);
            mapA.addMapData(52, 50, 48);
            mapB.addMapData(0, 15, 37);
            mapB.addMapData(37, 52, 2);
            mapB.addMapData(39, 0, 15);
            map.addLayer(mapA);
            map.addLayer(mapB);
            auto ranges = map.locateRange({0, 100});
            REQUIRE(ranges.size() == 5);
        }

        SECTION("SeedMap Layer") {
            SeedMapLayer layer;

            SECTION("Null case: When processing an input with no data it outputs the same number back") {
                REQUIRE(layer.process(0) == 0);
                REQUIRE(layer.process(50) == 50);
            }

            SECTION("Layer can have map data added to it") {
                layer.addMapData(50, 98, 1);
                REQUIRE(layer.process(98) == 50);
                REQUIRE(layer.process(99) == 99);
            }

            SECTION("Map data spans ranges properly") {
                layer.addMapData(50, 98, 3);
                REQUIRE(layer.process(97) == 97);
                REQUIRE(layer.process(98) == 50);
                REQUIRE(layer.process(99) == 51);
                REQUIRE(layer.process(100) == 52);
                REQUIRE(layer.process(101) == 101);
            }

            SECTION("Layer can handle multiple ranges") {
                layer.addMapData(50, 98, 2);
                layer.addMapData(52, 50, 48);
                REQUIRE(layer.process(0) == 0);
                REQUIRE(layer.process(49) == 49);
                REQUIRE(layer.process(50) == 52);
                REQUIRE(layer.process(51) == 53);
                REQUIRE(layer.process(97) == 99);
                REQUIRE(layer.process(98) == 50);
                REQUIRE(layer.process(99) == 51);
                REQUIRE(layer.process(100) == 100);
            }

            SECTION("Layer can handle a range for input as well") {
                auto ranges = layer.processRange({0, 10});
                auto ranges2 = layer.processRange({50, 50000000});
                REQUIRE(ranges.size() == 1);
                REQUIRE(ranges[0].start == 0);
                REQUIRE(ranges[0].length == 10);
                REQUIRE(ranges2.size() == 1);
                REQUIRE(ranges2[0].start == 50);
                REQUIRE(ranges2[0].length == 50000000);
            }

            SECTION("Layer handles range endpoints correctly") {
                layer.addMapData(10, 5, 1);
                layer.addMapData(21, 1, 2);
                auto ranges = layer.processRange({0,10});
                REQUIRE(ranges[0].start == 0);
                REQUIRE(ranges[0].length == 1);
                REQUIRE(ranges[1].start == 21);
                REQUIRE(ranges[1].length == 2);
                REQUIRE(ranges[2].start == 3);
                REQUIRE(ranges[2].length == 2);
                REQUIRE(ranges[3].start == 10);
                REQUIRE(ranges[3].length == 1);
                REQUIRE(ranges[4].start == 6);
                REQUIRE(ranges[4].length == 4);
            }

            SECTION("SeedRange with lower out of bounds map data") {
                layer.addMapData(10, 0, 10);
                auto ranges = layer.processRange({40, 20});
                REQUIRE(ranges.size() == 1);
                REQUIRE(ranges[0].start == 40);
                REQUIRE(ranges[0].length == 20);
            }

            SECTION("SeedRange with higher out of bounds map data") {
                layer.addMapData(10, 100, 10);
                auto ranges = layer.processRange({40, 20});
                REQUIRE(ranges.size() == 1);
                REQUIRE(ranges[0].start == 40);
                REQUIRE(ranges[0].length == 20);
            }

            SECTION("SeedRange dissection by range") {
                layer.addMapData(0, 50, 10);
                auto ranges = layer.processRange({40, 20});
                REQUIRE(ranges.size() == 2);
                REQUIRE(ranges[0].start == 40);
                REQUIRE(ranges[0].length == 10);
                REQUIRE(ranges[1].start == 0);
                REQUIRE(ranges[1].length == 10);
            }

            SECTION("SeedRange dissection by range 2: electric boogaloo") {
                layer.addMapData(0, 30, 20);
                auto ranges = layer.processRange({40, 20});
                REQUIRE(ranges.size() == 2);
                REQUIRE(ranges[0].start == 10);
                REQUIRE(ranges[0].length == 10);
                REQUIRE(ranges[1].start == 50);
                REQUIRE(ranges[1].length == 10);
            }

            SECTION("SeedRange trisection by range") {
                layer.addMapData(0, 50, 5);
                auto ranges = layer.processRange({40, 20});
                REQUIRE(ranges.size() == 3);
                REQUIRE(ranges[0].start == 40);
                REQUIRE(ranges[0].length == 10);
                REQUIRE(ranges[1].start == 0);
                REQUIRE(ranges[1].length == 5);
                REQUIRE(ranges[2].start == 55);
                REQUIRE(ranges[2].length == 5);
            }

            SECTION("SeedRange is surrounded by range") {
                layer.addMapData(0, 50, 40);
                auto ranges = layer.processRange({60, 10});
                REQUIRE(ranges.size() == 1);
                REQUIRE(ranges[0].start == 10);
                REQUIRE(ranges[0].length == 10);
            }

            SECTION("SeedRange is equal to range") {
                layer.addMapData(0, 50, 10);
                auto ranges = layer.processRange({50, 10});
                REQUIRE(ranges.size() == 1);
                REQUIRE(ranges[0].start == 0);
                REQUIRE(ranges[0].length == 10);
            }

            SECTION("SeedRange is equal to two consecutive map ranges") {
                layer.addMapData(0, 50, 10);
                layer.addMapData(20, 60, 10);
                auto ranges = layer.processRange({50, 20});
                REQUIRE(ranges.size() == 2);
                REQUIRE(ranges[0].start == 0);
                REQUIRE(ranges[0].length == 10);
                REQUIRE(ranges[1].start == 20);
                REQUIRE(ranges[1].length == 10);
            }

            SECTION("SeedRange is split by two outside map ranges") {
                layer.addMapData(0, 40, 20);
                layer.addMapData(20, 60, 20);
                auto ranges = layer.processRange({50, 20});
                REQUIRE(ranges.size() == 2);
                REQUIRE(ranges[0].start == 10);
                REQUIRE(ranges[0].length == 10);
                REQUIRE(ranges[1].start == 20);
                REQUIRE(ranges[1].length == 10);
            }

            SECTION("Process with multiple map ranges") {
                layer.addMapData(0, 50, 5);
                layer.addMapData(90, 56, 5);
                auto ranges = layer.processRange({40, 30});
                REQUIRE(ranges.size() == 5);
                REQUIRE(ranges[0].start == 40);
                REQUIRE(ranges[0].length == 10);
                REQUIRE(ranges[1].start == 0);
                REQUIRE(ranges[1].length == 5);
                REQUIRE(ranges[2].start == 55);
                REQUIRE(ranges[2].length == 1);
                REQUIRE(ranges[3].start == 90);
                REQUIRE(ranges[3].length == 5);
                REQUIRE(ranges[4].start == 61);
                REQUIRE(ranges[4].length == 9);
            }

            SECTION("Process multiple seedranges: 1 intersection & 1 with none") {
                layer.addMapData(0, 50, 5);
                auto ranges = layer.processRanges(std::vector<SeedRange>{{40, 12}, {99, 10}});
                REQUIRE(ranges.size() == 3);
                REQUIRE(ranges[0].start == 40);
                REQUIRE(ranges[0].length == 10);
                REQUIRE(ranges[1].start == 0);
                REQUIRE(ranges[1].length == 2);
                REQUIRE(ranges[2].start == 99);
                REQUIRE(ranges[2].length == 10);
            }
        }
    }
}