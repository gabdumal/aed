#include "contiguousList.hpp"

#include <expected>
#include <print>

std::string ContiguousList::getMessageForIndexNotWithin() {
    return "Index should be at least 0 and below " +
           std::to_string(this->maximum_size) +
           ".";
}

std::string ContiguousList::getMessageForIndexNotWithinNorImmediatelyAfter() {
    return "Index should be at least 0 and at most " +
           std::to_string(this->maximum_size) +
           ".";
}

std::string ContiguousList::getMessageForEmptyList() {
    return "List is empty.";
}

std::string ContiguousList::getMessageForFullList() {
    return "List is already full, with " +
           std::to_string(this->quantity_of_items) +
           " items.";
}

ContiguousList::ContiguousList(int maximum_size) {
    if (maximum_size < 1) {
        throw(std::string("Maximum size should be at least 1."));
    }

    this->maximum_size = maximum_size;
    this->quantity_of_items = 0;

    this->items = new Content[(unsigned int) maximum_size];
}

ContiguousList::~ContiguousList() {
    delete[] this->items;
}

bool ContiguousList::isWithin(int index) {
    return index >= 0 && index < this->quantity_of_items;
}

bool ContiguousList::isWithinOrImmediatelyAfter(int index) {
    return index >= 0 && index <= this->quantity_of_items;
}

bool ContiguousList::isEmpty() {
    return this->quantity_of_items == 0;
}

bool ContiguousList::isFull() {
    return this->quantity_of_items == this->maximum_size;
}

bool ContiguousList::contains(Content content) {
    for (
        int current_index = 0;
        current_index < this->quantity_of_items;
        current_index++) {
        if (this->items[current_index] == content) {
            return true;
        }
    }
    return false;
}

std::expected<void, std::string> ContiguousList::insert(int index, Content content) {
    if (!this->isWithinOrImmediatelyAfter(index)) {
        return std::unexpected(
            this->getMessageForIndexNotWithinNorImmediatelyAfter());
    }

    if (this->isFull()) {
        return std::unexpected(
            this->getMessageForFullList());
    }

    for (int current_index = this->quantity_of_items;
         current_index > index;
         current_index--) {
        this->items[current_index] = this->items[current_index - 1];
    }

    this->items[index] = content;
    this->quantity_of_items++;

    return {};
}

std::expected<void, std::string> ContiguousList::insertAtBegin(Content content) {
    constexpr int index = 0;
    return this->insert(index, content);
}

std::expected<void, std::string> ContiguousList::insertAtEnd(Content content) {
    auto index = this->quantity_of_items;
    return this->insert(index, content);
}

std::expected<void, std::string> ContiguousList::remove(int index) {
    if (this->isEmpty()) {
        return std::unexpected(getMessageForEmptyList());
    }

    if (!this->isWithin(index)) {
        return std::unexpected(
            this->getMessageForIndexNotWithin());
    }

    this->quantity_of_items--;

    for (int current_index = index;
         current_index < this->quantity_of_items;
         current_index++) {
        this->items[current_index] = this->items[current_index + 1];
    }

    return {};
}

std::expected<void, std::string> ContiguousList::removeAtBegin() {
    constexpr int index = 0;
    return this->remove(index);
}

std::expected<void, std::string> ContiguousList::removeAtEnd() {
    auto index = this->quantity_of_items - 1;
    return this->remove(index);
}

std::expected<ContiguousList::Content, std::string> ContiguousList::getContent(int index) {
    if (this->isEmpty()) {
        return std::unexpected(getMessageForEmptyList());
    }

    if (!this->isWithin(index)) {
        return std::unexpected(
            this->getMessageForIndexNotWithin());
    }

    return this->items[index];
}

std::expected<ContiguousList::Content, std::string> ContiguousList::getContentAtBegin() {
    constexpr int index = 0;
    return this->getContent(index);
}

std::expected<ContiguousList::Content, std::string> ContiguousList::getContentAtEnd() {
    auto index = this->quantity_of_items - 1;
    return this->getContent(index);
}

void ContiguousList::print() {
    int index = 0;
    while (index + 1 < this->quantity_of_items) {
        std::print("{}, ", this->items[index]);
        index++;
    }
    if (index < this->quantity_of_items && index >= 0) {
        std::print("{}", this->items[index]);
    }
    std::println();
}
