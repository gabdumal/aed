#include "externalHashTable.hpp"

#include <print>
#include <stdexcept>

#include "externalHashNode.hpp"

ExternalHashTable::ExternalHashTable(int maximum_size) {
    if (maximum_size < 1) {
        throw std::invalid_argument("Maximum size should be at least 1.");
    }

    this->maximum_size = (unsigned int) maximum_size;

    this->items = new ExternalHashNode *[this->maximum_size];

    for (unsigned int current_index = 0;
         current_index < this->maximum_size;
         current_index++) {
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

std::expected<unsigned int, std::string> ExternalHashTable::calculateIndex(ExternalHashNode::Key key) {
    if (key < 0) {
        return std::unexpected(message_for_negative_key);
    }
    return (unsigned int) key %
           this->maximum_size;
}

std::expected<bool, std::string> ExternalHashTable::contains(ExternalHashNode::Key key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }

    auto index = ideal_index.value();
    auto current_node = this->items[index];

    while (current_node != nullptr) {
        if (current_node->getKey() == key) {
            return true;
        }

        current_node = current_node->getNextNode();
    }

    return false;
}

std::expected<void, std::string> ExternalHashTable::insert(ExternalHashNode::Key key, ExternalHashNode::Value value) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }

    auto index = ideal_index.value();
    auto current_node = this->items[index];

    while (current_node != nullptr) {
        // Update existing value
        if (current_node->getKey() == key) {
            current_node->setValue(value);
            return {};
        }

        if (current_node->getNextNode() == nullptr) {
            break;
        }

        current_node = current_node->getNextNode();
    }

    auto new_node = new ExternalHashNode(key, value);

    if (current_node == nullptr) {
        this->items[index] = new_node;
    } else {
        current_node->setNextNode(new_node);
    }

    return {};
}

std::expected<void, std::string> ExternalHashTable::remove(ExternalHashNode::Key key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }

    auto index = ideal_index.value();

    auto current_node = this->items[index];
    ExternalHashNode *previous_node = nullptr;

    while (current_node != nullptr) {
        // Remove this node
        if (current_node->getKey() == key) {
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

std::expected<ExternalHashNode::Value, std::string> ExternalHashTable::getContent(ExternalHashNode::Key key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }

    auto index = ideal_index.value();
    auto current_node = this->items[index];

    while (current_node != nullptr) {
        if (current_node->getKey() == key) {
            return current_node->getValue();
        }

        current_node = current_node->getNextNode();
    }

    return std::unexpected(message_for_key_not_found);
}

void ExternalHashTable::print() {
    for (unsigned int current_index = 0;
         current_index < this->maximum_size;
         current_index++) {
        auto current_node = (this->items[current_index]);

        if (current_node == nullptr) {
            std::print("-");
        } else {
            std::print("{}", current_node->print());

            current_node = current_node->getNextNode();

            while (current_node != nullptr) {
                std::print(", {}", current_node->print());

                current_node = current_node->getNextNode();
            }
        }

        std::println();
    }
}

unsigned int ExternalHashTable::countKeysGreaterThan(ExternalHashNode::Key key) {
    unsigned int quantity_of_keys_greater_than_specified = 0;

    for (unsigned int current_index = 0;
         current_index < this->maximum_size;
         current_index++) {
        auto current_node = this->items[current_index];

        while (current_node != nullptr) {
            if (current_node->getKey() > key) {
                quantity_of_keys_greater_than_specified++;
            }

            current_node = current_node->getNextNode();
        }
    }

    return quantity_of_keys_greater_than_specified;
}
