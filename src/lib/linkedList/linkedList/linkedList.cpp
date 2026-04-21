#include "linkedList.hpp"

#include <expected>
#include <print>

#include "linkedListNode.hpp"

std::string LinkedList::getMessageForNegativeIndex() {
    return "Index should be at least 0.";
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

    LinkedListNode *node_before_new = nullptr;
    auto node_after_new = this->first_node;

    while (current_index < index &&
           node_after_new != nullptr) {
        current_index++;

        node_before_new = node_after_new;
        node_after_new = node_after_new->getNextNode();
    }
    if (current_index < index) {
        // Index is greater than the size of list
        return std::unexpected(
            getMessageForIndexNotWithinNorImmediatelyAfter(current_index));
    }

    auto new_node = new LinkedListNode(content);
    new_node->setNextNode(node_after_new);

    if (node_before_new == nullptr) {
        this->first_node = new_node;
    } else {
        node_before_new->setNextNode(new_node);
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
