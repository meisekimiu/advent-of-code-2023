#include <catch2/catch.hpp>
#include "../../src/day08/NodeMap.h"

TEST_CASE("Node Map", "[day08]") {
    NodeMap map;

    SECTION("Map can add a node") {
        map.addNode("AAA", {"BBB", "CCC"});
    }

    SECTION("Map can traverse nodes for part 1") {
        map.addNode("AAA", {"BBB", "CCC"});
        map.addNode("BBB", {"AAA", "AAA"});
        map.addNode("CCC", {"ZZZ", "BBB"});
        map.addNode("ZZZ", {"ZZZ", "ZZZ"});
        REQUIRE(map.stepsToZzz("RL") == 2);
    }

    SECTION("Map will retry until it hits ZZZ") {
        map.addNode("AAA", {"BBB", "BBB"});
        map.addNode("BBB", {"AAA", "ZZZ"});
        map.addNode("ZZZ", {"ZZZ", "ZZZ"});
        REQUIRE(map.stepsToZzz("LLR") == 6);
    }

    SECTION("Map will detect infinite loops") {
        map.addNode("AAA", {"AAA", "AAA"});
        map.addNode("ZZZ", {"ZZZ", "ZZZ"});
        REQUIRE_THROWS(map.stepsToZzz("LLRLRLRL"));
    }

    SECTION("Map can return the map contents") {
        map.addNode("AAA", {"BBB", "CCC"});
        auto nodeMap = map.getMap();
        REQUIRE(nodeMap["AAA"].left == "BBB");
        REQUIRE(nodeMap["AAA"].right == "CCC");
    }

    SECTION("It can traverse from all **A nodes to **Z nodes") {
        map.addNode("11A", {"11B", "XXX"});
        map.addNode("11B", {"XXX", "11Z"});
        map.addNode("11Z", {"11B", "XXX"});
        map.addNode("22A", {"22B", "XXX"});
        map.addNode("22B", {"22C", "22C"});
        map.addNode("22C", {"22Z", "22Z"});
        map.addNode("22Z", {"22B", "22B"});
        map.addNode("XXX", {"XXX", "XXX"});
        REQUIRE(map.ghostStepsFromAToZ("LR") == 6);
    }

    SECTION("It can detect infinite loops in 'ghost mode'") {
        map.addNode("11A", {"11A", "11A"});
        map.addNode("22A", {"22A", "22A"});
        REQUIRE_THROWS(map.ghostStepsFromAToZ("LRLLRLRLRLR"));
    }
}