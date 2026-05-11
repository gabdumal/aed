#include "externalHashTable.hpp"

#include <print>

#include "externalHashNode.hpp"

ExternalHashTable::ExternalHashTable(int maximum_size) {
    if (maximum_size < 1) {
        throw(std::string("Maximum size should be at least 1."));
    }

    this->maximum_size = (unsigned int) maximum_size;

    this->items = &(new (ExternalHashNode *))[this->maximum_size];

    for (unsigned int current_index = 0; current_index < this->maximum_size; current_index++) {
        this->items[current_index] = nullptr;
    }
}

ExternalHashTable::~ExternalHashTable() {
    for (unsigned int current_index = 0; current_index < this->maximum_size; current_index++) {
        auto current_node = this->items[current_index];
        while (current_node != nullptr) {
            auto next_node = current_node->getNextNode();
            delete current_node;
            current_node = next_node;
        }
    }
    delete[] this->items;
}

std::expected<unsigned int, std::string> ExternalHashTable::calculateIndex(ExternalHashNode::ContentKey key) {
    if (key < 0) {
        return std::unexpected(message_for_negative_key);
    }
    return (unsigned int) key %
           this->maximum_size;
}

std::expected<bool, std::string> ExternalHashTable::contains(ExternalHashNode::ContentKey key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }

    auto index = ideal_index.value();
    auto current_node = this->items[index];

    while (current_node != nullptr) {
        if (current_node->getContentKey() == key) {
            return true;
        }

        current_node = current_node->getNextNode();
    }

    return false;
}

std::expected<void, std::string> ExternalHashTable::insert(ExternalHashNode::ContentKey key, ExternalHashNode::ContentValue value) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }

    auto index = ideal_index.value();
    auto current_node = this->items[index];

    while (current_node != nullptr) {
        // Update existing value
        if (current_node->getContentKey() == key) {
            current_node->setContentValue(value);
            return {};
        }

        if (current_node->getNextNode() == nullptr) {
            break;
        }

        current_node = current_node->getNextNode();
    }

    auto new_node = new ExternalHashNode(key, value);
    current_node->setNextNode(new_node);
    return {};
}

std::expected<void, std::string> ExternalHashTable::remove(ExternalHashNode::ContentKey key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }

    auto index = ideal_index.value();

    auto current_node = this->items[index];
    ExternalHashNode *previous_node = nullptr;

    while (current_node != nullptr) {
        // Remove this node
        if (current_node->getContentKey() == key) {
            auto next_node = current_node->getNextNode();

            if (previous_node == nullptr) {
                this->items[index] = next_node;
            } else {
                previous_node->setNextNode(next_node);
            }

            delete current_node;
            return {};
        }

        previous_node = current_node;
        current_node = current_node->getNextNode();
    }

    return std::unexpected(message_for_key_not_found);
}

std::expected<ExternalHashNode::ContentValue, std::string> ExternalHashTable::getContent(ExternalHashNode::ContentKey key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }

    auto index = ideal_index.value();
    auto current_node = this->items[index];

    while (current_node != nullptr) {
        if (current_node->getContentKey() == key) {
            return current_node->getContentValue();
        }

        current_node = current_node->getNextNode();
    }

    return std::unexpected(message_for_key_not_found);
}

void ExternalHashTable::print() {
    unsigned int current_index = 0;
    while (current_index + 1 < this->maximum_size) {
        std::print(
            "{}, ",
            (this->items[current_index])->print());
        current_index++;
    }
    if (current_index < this->maximum_size && current_index >= 0) {
        std::print(
            "{}",
            (this->items[current_index])->print());
    }
    std::println();
}

unsigned int ExternalHashTable::countKeysGreaterThan(ExternalHashNode::ContentKey key) {
    unsigned int quantity_of_keys_greater_than_specified = 0;

    for (unsigned int current_index = 0;
         current_index < this->maximum_size;
         current_index++) {
        auto current_node = this->items[current_index];

        while (current_node != nullptr) {
            if (current_node->getContentKey() > key) {
                quantity_of_keys_greater_than_specified++;
            }

            current_node = current_node->getNextNode();
        }
    }

    return quantity_of_keys_greater_than_specified;
}
