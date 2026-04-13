#include "linkedQueueNode.hpp"

constexpr LinkedQueueNode::Content default_content = 0;

LinkedQueueNode::LinkedQueueNode(LinkedQueueNode::Content content) {
    this->content = content;
    this->next = nullptr;
}

LinkedQueueNode::~LinkedQueueNode() {
    this->content = default_content;
    this->next = nullptr;
}

LinkedQueueNode::Content LinkedQueueNode::get() {
    return this->content;
}

void LinkedQueueNode::set(LinkedQueueNode::Content content) {
    this->content = content;
}
