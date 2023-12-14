#include "NodeMap.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <numeric>

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

unsigned long long int NodeMap::ghostStepsFromAToZ(const std::string &directions) {
    std::vector<NodeName> traversalPoints = getNodesEndingWithA();
    std::vector<NodeName> startingPoints = traversalPoints;
    std::vector<unsigned int> repeatTimes;
    std::vector<NodeName> finishedNodes;
    unsigned long long int steps = 0;
    bool found = false;
    while (!found) {
        for (char direction : directions) {
            steps++;
            for (NodeName &node : traversalPoints) {
                node = getDestinationNode(node, direction, nodeMap[node]);
                if (node.back() == 'Z') {
                    finishedNodes.push_back(node);
                    repeatTimes.push_back(steps);
                }
            }
            removeFinishedNodes(traversalPoints, finishedNodes);
            if (allNodesEndWithZ(traversalPoints)) {
                found = true;
                break;
            }
            checkForMultipleInfiniteLoops(traversalPoints, startingPoints);
        }
    }
    steps = lcmOfRepeatTimes(repeatTimes, steps);
    return steps;
}

unsigned long long int NodeMap::lcmOfRepeatTimes(std::vector<unsigned int> &repeatTimes, unsigned long long int steps) {
    if (!repeatTimes.empty()) {
        unsigned long long int lcm = repeatTimes.back();
        repeatTimes.pop_back();
        while(!repeatTimes.empty()) {
            lcm = std::lcm(lcm, repeatTimes.back());
            repeatTimes.pop_back();
        }
        steps = lcm;
    }
    return steps;
}

void NodeMap::removeFinishedNodes(std::vector<NodeName> &traversalPoints, std::vector<NodeName> &finishedNodes) {
    for (NodeName &node : finishedNodes) {
        traversalPoints.erase(std::find(traversalPoints.begin(), traversalPoints.end(), node));
    }
    finishedNodes.clear();
}

void NodeMap::checkForMultipleInfiniteLoops(const std::vector<NodeName> &traversalPoints,
                                            const std::vector<NodeName> &startingPoints) {
    for (int i = 0; i < startingPoints.size(); i++) {
        if (startingPoints[i] != traversalPoints[i]) {
            return;
        }
    }
    throw std::runtime_error("Infinite loop detected when traversing nodemap.");
}

bool NodeMap::allNodesEndWithZ(std::vector<NodeName> &traversalPoints) {
    return traversalPoints.empty() || std::all_of(traversalPoints.begin(), traversalPoints.end(), [](const NodeName &node) {
        return node.back() == 'Z';
    });
}

std::vector<NodeName> NodeMap::getNodesEndingWithA() {
    std::vector<NodeName> startingPoints;
    // get starting points; nodes that end with A
    for (const auto &pair : nodeMap) {
        const NodeName& pairName = pair.first;
        if (pairName.back() == 'A') {
            startingPoints.push_back(pair.first);
        }
    }
    return startingPoints;
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
