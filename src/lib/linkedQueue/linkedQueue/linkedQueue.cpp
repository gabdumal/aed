#include "linkedQueue.hpp"

#include <expected>
#include <print>

#include "linkedQueueNode.hpp"

std::string LinkedQueue::getMessageForEmptyQueue() {
    return "Queue is empty.";
}

LinkedQueue::LinkedQueue() {
    this->head_node = nullptr;
    this->tail_node = nullptr;
}

LinkedQueue::~LinkedQueue() {
    auto current_node = this->head_node;

    while (current_node != nullptr) {
        auto node_behind = current_node->getNodeBehind();
        delete current_node;
        current_node = node_behind;
    }

    this->head_node = nullptr;
    this->tail_node = nullptr;
}

bool LinkedQueue::isEmpty() {
    return this->head_node == nullptr;
}

void LinkedQueue::enqueue(LinkedQueueNode::Content content) {
    auto new_node =
        new LinkedQueueNode(content, this->tail_node);

    this->tail_node = new_node;
    if (head_node == nullptr) {
        this->head_node = new_node;
    }
}

void LinkedQueue::print() {
    std::print("Head: ");

    auto current_node = this->head_node;
    while (current_node != nullptr) {
        std::print("{}, ", current_node->getContent());
        current_node = current_node->getNodeBehind();
    }

    std::println();
}

std::expected<LinkedQueueNode::Content, std::string> LinkedQueue::peek() {
    if (this->isEmpty()) {
        return std::unexpected(this->getMessageForEmptyQueue());
    }

    return this->head_node->getContent();
}

std::expected<LinkedQueueNode::Content, std::string> LinkedQueue::dequeue() {
    if (this->isEmpty()) {
        return std::unexpected(this->getMessageForEmptyQueue());
    }

    auto content = this->head_node->getContent();
    auto node_behind_head_node = this->head_node->getNodeBehind();

    delete this->head_node;
    this->head_node = node_behind_head_node;

    if (this->head_node == nullptr) {
        this->tail_node = nullptr;
    }

    return content;
}

bool LinkedQueue::contains(LinkedQueueNode::Content content) {
    auto current_node = this->head_node;

    while (current_node != nullptr) {
        if (current_node->getContent() == content) {
            return true;
        }
        current_node = current_node->getNodeBehind();
    }

    return false;
}
