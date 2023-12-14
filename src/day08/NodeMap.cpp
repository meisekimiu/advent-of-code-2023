#include "NodeMap.h"
#include <stdexcept>

void NodeMap::addNode(const NodeName &name, const Node &node) {
    nodeMap[name] = node;
}

unsigned int NodeMap::stepsToZzz(const std::string &directions) {
    NodeName currentNode = "AAA";
    unsigned int steps = 0;
    bool found = false;
    while (!found) {
        for (char direction: directions) {
            steps++;
            currentNode = getDestinationNode(currentNode, direction, nodeMap[currentNode]);
            if (currentNode == "ZZZ") {
                found = true;
                break;
            }
        }
        checkForInfiniteLoops(currentNode);
    }
    return steps;
}

void NodeMap::checkForInfiniteLoops(const NodeName &currentNode) {
    if (currentNode == "AAA") {
        throw std::runtime_error("Infinite loop detected when traversing nodemap.");
    }
}

NodeName &NodeMap::getDestinationNode(NodeName &currentNode, char direction, const Node &node) {
    switch (direction) {
        case 'L':
            currentNode = node.left;
            break;
        case 'R':
            currentNode = node.right;
            break;
        default:
            throw std::runtime_error("Invalid direction");
    }
    return currentNode;
}

std::unordered_map<NodeName, Node> NodeMap::getMap() const {
    return nodeMap;
}
