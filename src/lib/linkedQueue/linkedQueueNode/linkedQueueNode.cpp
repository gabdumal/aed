#include "linkedQueueNode.hpp"

constexpr LinkedQueueNode::Content default_content = 0;

LinkedQueueNode::LinkedQueueNode(LinkedQueueNode::Content content, LinkedQueueNode *node_ahead) {
    this->content = content;
    this->node_behind = nullptr;

    node_ahead->node_behind = this;
}

LinkedQueueNode::~LinkedQueueNode() {
    this->content = default_content;
    this->node_behind = nullptr;
}

LinkedQueueNode::Content LinkedQueueNode::getContent() {
    return this->content;
}

LinkedQueueNode *LinkedQueueNode::getNodeBehind() {
    return this->node_behind;
}
