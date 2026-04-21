#include "linkedList.hpp"

#include <expected>
#include <print>

#include "linkedListNode.hpp"

std::string LinkedList::getMessageForNegativeIndex() {
    return "Index should be at least 0.";
}

std::string LinkedList::getMessageForIndexNotWithin(int maximum) {
    return "Index should be at least 0 and below " +
           std::to_string(maximum) +
           ".";
}

std::string LinkedList::getMessageForIndexNotWithinNorImmediatelyAfter(int maximum) {
    return "Index should be at least 0 and at most " +
           std::to_string(maximum) +
           ".";
}

std::string LinkedList::getMessageForEmptyList() {
    return "List is empty.";
}

LinkedList::LinkedList() {
    this->first_node = nullptr;
}

LinkedList::~LinkedList() {
    auto current_node = this->first_node;

    while (current_node != nullptr) {
        auto next_node = current_node->getNextNode();

        delete current_node;

        current_node = next_node;
    }

    this->first_node = nullptr;
}

bool LinkedList::isEmpty() {
    return this->first_node == nullptr;
}

int LinkedList::getLength() {
    auto current_node = this->first_node;
    int length = 0;

    while (current_node != nullptr) {
        length++;

        auto next_node = current_node->getNextNode();
        current_node = next_node;
    }

    return length;
}

LinkedListNode *LinkedList::getLastNode() {
    auto current_node = this->first_node;

    while (current_node != nullptr && current_node->getNextNode() != nullptr) {
        auto next_node = current_node->getNextNode();
        current_node = next_node;
    }

    return current_node;
}

std::expected<void, std::string> LinkedList::insert(int index, LinkedListNode::Content content) {
    if (index < 0) {
        return std::unexpected(
            this->getMessageForNegativeIndex());
    }

    int current_index = 0;

    LinkedListNode *node_before_current = nullptr;
    auto current_node = this->first_node;

    while (current_index < index &&
           current_node != nullptr) {
        current_index++;

        node_before_current = current_node;
        current_node = current_node->getNextNode();
    }
    if (current_index < index) {
        // Index is greater than the size of list
        return std::unexpected(
            this->getMessageForIndexNotWithinNorImmediatelyAfter(current_index));
    }

    auto new_node = new LinkedListNode(content);
    new_node->setNextNode(current_node);

    if (node_before_current == nullptr) {
        this->first_node = new_node;
    } else {
        node_before_current->setNextNode(new_node);
    }

    return {};
}

std::expected<void, std::string> LinkedList::insertAtBegin(LinkedListNode::Content content) {
    auto first_node = this->first_node;

    auto new_node = new LinkedListNode(content);

    new_node->setNextNode(first_node);

    this->first_node = new_node;

    return {};
}

std::expected<void, std::string> LinkedList::insertAtEnd(LinkedListNode::Content content) {
    auto last_node = this->getLastNode();

    auto new_node = new LinkedListNode(content);

    if (last_node == nullptr) {
        this->first_node = last_node;
    } else {
        last_node->setNextNode(new_node);
    }

    return {};
}

std::expected<void, std::string> LinkedList::remove(int index) {
    if (index < 0) {
        return std::unexpected(
            this->getMessageForNegativeIndex());
    }

    if (this->isEmpty()) {
        return std::unexpected(
            this->getMessageForEmptyList());
    }

    int current_index = 0;

    LinkedListNode *node_before_current = nullptr;
    auto current_node = this->first_node;

    while (current_index < index &&
           current_node != nullptr) {
        current_index++;

        node_before_current = current_node;
        current_node = current_node->getNextNode();
    }
    if (current_node == nullptr) {
        // Index is greater than the index of the last item of list
        return std::unexpected(
            this->getMessageForIndexNotWithin(current_index));
    }

    auto node_after_current = current_node->getNextNode();

    if (node_before_current == nullptr) {
        this->first_node = node_after_current;
    } else {
        node_before_current->setNextNode(node_after_current);
    }

    delete current_node;

    return {};
}

std::expected<void, std::string> LinkedList::removeAtBegin() {
    if (this->isEmpty()) {
        return std::unexpected(
            this->getMessageForEmptyList());
    }

    auto first_node = this->first_node;
    auto node_after_first = first_node->getNextNode();

    this->first_node = node_after_first;

    delete first_node;

    return {};
}

std::expected<void, std::string> LinkedList::removeAtEnd() {
    if (this->isEmpty()) {
        return std::unexpected(
            this->getMessageForEmptyList());
    }

    LinkedListNode *node_before_current = nullptr;
    auto current_node = this->first_node;

    while (current_node != nullptr &&
           current_node->getNextNode() != nullptr) {
        node_before_current = current_node;
        current_node = current_node->getNextNode();
    }

    if (node_before_current == nullptr) {
        this->first_node = nullptr;
    } else {
        node_before_current->setNextNode(nullptr);
    }

    delete current_node;

    return {};
}

std::expected<LinkedListNode::Content, std::string> LinkedList::getContent(int index) {
    if (index < 0) {
        return std::unexpected(
            this->getMessageForNegativeIndex());
    }

    if (this->isEmpty()) {
        return std::unexpected(
            this->getMessageForEmptyList());
    }

    int current_index = 0;

    auto current_node = this->first_node;

    while (current_index < index &&
           current_node != nullptr) {
        current_index++;

        current_node = current_node->getNextNode();
    }
    if (current_node == nullptr) {
        // Index is greater than the index of the last item of list
        return std::unexpected(
            this->getMessageForIndexNotWithin(current_index));
    }

    return current_node->getContent();
}

std::expected<LinkedListNode::Content, std::string> LinkedList::getContentAtBegin() {
    if (this->isEmpty()) {
        return std::unexpected(
            this->getMessageForEmptyList());
    }

    return this->first_node->getContent();
}

std::expected<LinkedListNode::Content, std::string> LinkedList::getContentAtEnd() {
    if (this->isEmpty()) {
        return std::unexpected(
            this->getMessageForEmptyList());
    }

    auto last_node = this->getLastNode();

    return last_node->getContent();
}

bool LinkedList::contains(LinkedListNode::Content content) {
    auto current_node = this->first_node;

    while (current_node != nullptr) {
        if (current_node->getContent() == content) {
            return true;
        }

        current_node = current_node->getNextNode();
    }

    return false;
}

void LinkedList::print() {
    auto current_node = this->first_node;

    while (
        current_node != nullptr &&
        current_node->getNextNode() != nullptr) {
        std::print("{}, ", current_node->getContent());

        current_node = current_node->getNextNode();
    }

    if (current_node != nullptr) {
        std::print("{}", current_node->getContent());
    }

    std::println();
}
