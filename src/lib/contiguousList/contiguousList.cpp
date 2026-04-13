#include "contiguousList.hpp"

#include <expected>
#include <print>

ContiguousList::ContiguousList(unsigned int maximum_size) {
    this->maximum_size = maximum_size;
    this->quantity_of_items = 0;

    this->items = new Content[maximum_size];
}

ContiguousList::~ContiguousList() {
    delete[] this->items;
}

bool ContiguousList::isInsideRangeToInsert(unsigned int index) {
    return index <= this->quantity_of_items;
}

bool ContiguousList::isInsideRangeToRemove(unsigned int index) {
    return index < this->quantity_of_items;
}

bool ContiguousList::isEmpty() {
    return this->quantity_of_items == 0;
}

bool ContiguousList::isFull() {
    return this->quantity_of_items == this->maximum_size;
}

std::expected<void, std::string> ContiguousList::insert(unsigned int index, Content content) {
    if (!this->isInsideRangeToInsert(index)) {
        return std::unexpected(
            "Index should be at least 0 and at most " +
            std::to_string(this->quantity_of_items) +
            ".");
    }

    if (this->isFull()) {
        return std::unexpected(
            "List is already full, with " +
            std::to_string(this->quantity_of_items) +
            " items.");
    }

    for (unsigned int current_index = this->quantity_of_items;
         current_index > index;
         current_index--) {
        this->items[current_index] = this->items[current_index - 1];
    }

    this->items[index] = content;
    this->quantity_of_items++;

    return {};
}

void ContiguousList::print() {
    unsigned int index = 0;
    while (index + 1 < this->quantity_of_items) {
        std::print("{}, ", this->items[index]);
        index++;
    }
    if (index < this->quantity_of_items && index >= 0) {
        std::print("{}", this->items[index]);
    }
    std::println();
}

std::expected<void, std::string> ContiguousList::remove(unsigned int index) {
    if (this->isEmpty()) {
        return std::unexpected("List is empty.");
    }

    if (!this->isInsideRangeToRemove(index)) {
        return std::unexpected(
            "Index should be at least 0 and below " +
            std::to_string(this->quantity_of_items) +
            ".");
    }

    this->quantity_of_items--;

    for (unsigned int current_index = index; current_index < this->quantity_of_items; current_index++) {
        this->items[current_index] = this->items[current_index + 1];
    }

    return {};
}
