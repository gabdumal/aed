#include "openAddressingHash.hpp"

#include <expected>
#include <print>
#include <string>

constexpr OpenAddressingHash::Content default_content = -1;
constexpr OpenAddressingHash::Content deleted_content = -2;

std::string OpenAddressingHash::getMessageForIndexNotWithin() {
    return "Index should be at least 0 and below " +
           std::to_string(this->maximum_size) +
           ".";
}

std::string OpenAddressingHash::getMessageForIndexNotWithinNorImmediatelyAfter() {
    return "Index should be at least 0 and at most " +
           std::to_string(this->maximum_size) +
           ".";
}

std::string OpenAddressingHash::getMessageForEmptyList() {
    return "List is empty.";
}

std::string OpenAddressingHash::getMessageForFullList() {
    return "List is already full, with " +
           std::to_string(this->quantity_of_items) +
           " items.";
}

OpenAddressingHash::OpenAddressingHash(int maximum_size) {
    if (maximum_size < 1) {
        throw(std::string("Maximum size should be at least 1."));
    }

    this->maximum_size = maximum_size;
    this->quantity_of_items = 0;

    this->items = new Content[(unsigned int) maximum_size];

    for (auto index = 0; index < maximum_size; index++) {
        this->items[index] = default_content;
    }
}

OpenAddressingHash::~OpenAddressingHash() {
    delete[] this->items;
}

bool OpenAddressingHash::isWithin(int index) {
    return index >= 0 && index < this->quantity_of_items;
}

bool OpenAddressingHash::isWithinOrImmediatelyAfter(int index) {
    return index >= 0 && index <= this->quantity_of_items;
}

bool OpenAddressingHash::isEmpty() {
    return this->quantity_of_items == 0;
}

bool OpenAddressingHash::isFull() {
    return this->quantity_of_items == this->maximum_size;
}

bool OpenAddressingHash::contains(Content content) {
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

std::expected<void, std::string> OpenAddressingHash::insert(int key, Content content) {
    if (!this->isWithinOrImmediatelyAfter(key)) {
        return std::unexpected(
            this->getMessageForIndexNotWithinNorImmediatelyAfter());
    }

    if (this->isFull()) {
        return std::unexpected(
            this->getMessageForFullList());
    }

    for (int current_index = this->quantity_of_items;
         current_index > key;
         current_index--) {
        this->items[current_index] = this->items[current_index - 1];
    }

    this->items[key] = content;
    this->quantity_of_items++;

    return {};
}

std::expected<void, std::string> OpenAddressingHash::remove(int key) {
    if (!this->isWithin(key)) {
        return std::unexpected(
            this->getMessageForIndexNotWithin());
    }

    if (this->isEmpty()) {
        return std::unexpected(getMessageForEmptyList());
    }

    this->quantity_of_items--;

    for (int current_index = key;
         current_index < this->quantity_of_items;
         current_index++) {
        this->items[current_index] = this->items[current_index + 1];
    }

    return {};
}

std::expected<OpenAddressingHash::Content, std::string> OpenAddressingHash::getContent(int key) {
    if (this->isEmpty()) {
        return std::unexpected(getMessageForEmptyList());
    }

    if (!this->isWithin(key)) {
        return std::unexpected(
            this->getMessageForIndexNotWithin());
    }

    return this->items[key];
}

std::string OpenAddressingHash::printContent(OpenAddressingHash::Content content) {
    if (content == default_content) {
        return "-";
    } else if (content == deleted_content) {
        return "X";
    }
    return std::to_string(content);
}

void OpenAddressingHash::print() {
    int index = 0;
    while (index + 1 < this->maximum_size) {
        std::print("{}, ", this->printContent(this->items[index]));
        index++;
    }
    if (index < this->maximum_size && index >= 0) {
        std::print("{}", this->printContent(this->items[index]));
    }
    std::println();
}
