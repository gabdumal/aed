#include "linkedQueue.hpp"

#include <expected>
#include <print>

LinkedQueue::LinkedQueue() {
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedQueue::~LinkedQueue() {
    // TODO
}

bool LinkedQueue::isEmpty() {
    return this->head == nullptr;
}

void LinkedQueue::insert(LinkedQueueNode::Content content) {
    // TODO
}

void LinkedQueue::print() {
    // TODO
    std::println();
}

std::expected<void, std::string> LinkedQueue::remove() {
    if (this->isEmpty()) {
        return std::unexpected("List is empty.");
    }

    // TODO

    return {};
}

std::expected<LinkedQueueNode::Content, std::string> LinkedQueue::dequeue() {
    // TODO
}

bool LinkedQueue::contains(LinkedQueueNode::Content content) {
    // TODO
    return false;
}
