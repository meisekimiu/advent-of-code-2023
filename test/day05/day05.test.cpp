#include <catch2/catch.hpp>
#include "../../src/day05/Day05.h"

TEST_CASE("Day 05", "[day05]") {
    Day05 day;

    SECTION("Advent of Code Examples") {
        SECTION("Example part 1") {
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
            day.readInputString(input);
            REQUIRE(day.getMinimumSeedLocation() == 35);
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
        }
    }
}