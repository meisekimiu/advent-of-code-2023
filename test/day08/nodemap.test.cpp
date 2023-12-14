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
}