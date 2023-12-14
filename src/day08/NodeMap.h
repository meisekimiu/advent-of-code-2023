#ifndef ADVENT_OF_CODE_NODEMAP_H
#define ADVENT_OF_CODE_NODEMAP_H
#include <string>
#include <unordered_map>
#include <vector>

typedef std::string NodeName;

struct Node {
    NodeName left;
    NodeName right;
};

class NodeMap {
public:
    void addNode(const NodeName& name, const Node& node);
    unsigned int stepsToZzz(const std::string& directions);
    unsigned long long int ghostStepsFromAToZ(const std::string& directions);
    std::unordered_map<NodeName, Node> getMap() const;

private:
    std::unordered_map<NodeName, Node> nodeMap;

    static NodeName &getDestinationNode(NodeName &currentNode, char direction, const Node &node) ;

    static void checkForInfiniteLoops(const NodeName &currentNode) ;

    std::vector<NodeName> getNodesEndingWithA();

    static bool allNodesEndWithZ(std::vector<NodeName> &traversalPoints) ;

    static void checkForMultipleInfiniteLoops(const std::vector<NodeName> &traversalPoints,
                                       const std::vector<NodeName> &startingPoints) ;

    static void removeFinishedNodes(std::vector<NodeName> &traversalPoints, std::vector<NodeName> &finishedNodes) ;

    static unsigned long long int lcmOfRepeatTimes(std::vector<unsigned int> &repeatTimes, unsigned long long int steps) ;
};


#endif //ADVENT_OF_CODE_NODEMAP_H
