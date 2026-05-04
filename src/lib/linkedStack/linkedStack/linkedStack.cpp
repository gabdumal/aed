#include "linkedStack.hpp"

#include <expected>
#include <print>

#include "linkedStackNode.hpp"

std::string LinkedStack::getMessageForEmptyStack() {
    return "Stack is empty.";
}

LinkedStack::LinkedStack() {
    this->top_node = nullptr;
}

LinkedStack::~LinkedStack() {
    auto current_node = this->top_node;

    while (current_node != nullptr) {
        auto node_behind = current_node->getNodeBehind();
        delete current_node;
        current_node = node_behind;
    }

    this->top_node = nullptr;
}

bool LinkedStack::isEmpty() {
    return this->top_node == nullptr;
}

void LinkedStack::push(LinkedStackNode::Content content) {
    auto new_node =
        new LinkedStackNode(content, this->top_node);

    this->top_node = new_node;
}

void LinkedStack::print() {
    std::print("Top: ");

    auto current_node = this->top_node;

    while (
        current_node != nullptr &&
        current_node->getNodeBehind() != nullptr) {
        std::print("{}, ", current_node->getContent());

        current_node = current_node->getNodeBehind();
    }

    if (current_node != nullptr) {
        std::print("{}", current_node->getContent());
    }

    std::println();
}

std::expected<LinkedStackNode::Content, std::string> LinkedStack::peek() {
    if (this->isEmpty()) {
        return std::unexpected(this->getMessageForEmptyStack());
    }

    return this->top_node->getContent();
}

std::expected<LinkedStackNode::Content, std::string> LinkedStack::pop() {
    if (this->isEmpty()) {
        return std::unexpected(this->getMessageForEmptyStack());
    }

    auto content = this->top_node->getContent();
    auto node_behind_top_node = this->top_node->getNodeBehind();

    delete this->top_node;
    this->top_node = node_behind_top_node;

    return content;
}

bool LinkedStack::contains(LinkedStackNode::Content content) {
    auto current_node = this->top_node;

    while (current_node != nullptr) {
        if (current_node->getContent() == content) {
            return true;
        }
        current_node = current_node->getNodeBehind();
    }

    return false;
}
