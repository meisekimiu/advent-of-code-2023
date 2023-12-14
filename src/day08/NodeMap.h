#ifndef ADVENT_OF_CODE_NODEMAP_H
#define ADVENT_OF_CODE_NODEMAP_H
#include <string>
#include <unordered_map>

typedef std::string NodeName;

struct Node {
    NodeName left;
    NodeName right;
};

class NodeMap {
public:
    void addNode(const NodeName& name, const Node& node);
    unsigned int stepsToZzz(const std::string& directions);
    std::unordered_map<NodeName, Node> getMap() const;

private:
    std::unordered_map<NodeName, Node> nodeMap;

    static NodeName &getDestinationNode(NodeName &currentNode, char direction, const Node &node) ;

    static void checkForInfiniteLoops(const NodeName &currentNode) ;
};


#endif //ADVENT_OF_CODE_NODEMAP_H
