#include "linkedStackNode.hpp"

constexpr LinkedStackNode::Content default_content = 0;

LinkedStackNode::LinkedStackNode(LinkedStackNode::Content content, LinkedStackNode *node_behind) {
    this->content = content;
    this->node_behind = node_behind;
}

LinkedStackNode::~LinkedStackNode() {
    this->content = default_content;
    this->node_behind = nullptr;
}

LinkedStackNode::Content LinkedStackNode::getContent() {
    return this->content;
}

LinkedStackNode *LinkedStackNode::getNodeBehind() {
    return this->node_behind;
}
