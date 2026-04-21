#include "linkedListNode.hpp"

constexpr LinkedListNode::Content default_content = 0;

LinkedListNode::LinkedListNode(LinkedListNode::Content content) {
    this->content = content;
    this->next_node = nullptr;
}

LinkedListNode::~LinkedListNode() {
    this->content = default_content;
    this->next_node = nullptr;
}

LinkedListNode::Content LinkedListNode::getContent() {
    return this->content;
}

LinkedListNode *LinkedListNode::getNextNode() {
    return this->next_node;
}

void LinkedListNode::setNextNode(LinkedListNode *next_node) {
    this->next_node = next_node;
}
