#include "contiguousList.hpp"

#include <print>
#include <stdexcept>

ContiguousList::ContiguousList(unsigned int maximum_size) {
    this->maximum_size = maximum_size;
    this->quantity_of_items = 0;

    this->items = new Content[maximum_size];
}

ContiguousList::~ContiguousList() {
    delete[] this->items;
}

void ContiguousList::ensureIsInsideRange(unsigned int index) {
    if (index < 0 ||
        index > this->quantity_of_items) {
        std::string message = "Index should be 0.";

        if (this->quantity_of_items > 0) {
            message = "Index should be between 0 and " +
                      std::to_string(this->quantity_of_items) +
                      ".";
        }

        throw std::out_of_range(message);
    }
}

bool ContiguousList::isFull() {
    return this->quantity_of_items == this->maximum_size;
}

void ContiguousList::ensureIsNotFull() {
    if (this->isFull()) {
        throw std::length_error(
            "List is already full, with " +
            std::to_string(this->quantity_of_items) +
            " elements.");
    }
}

bool ContiguousList::willIncludeNewItem(unsigned int index) {
    return index == this->quantity_of_items;
}

void ContiguousList::insert(unsigned int index, Content content) {
    this->ensureIsInsideRange(index);

    if (this->willIncludeNewItem(index)) {
        this->ensureIsNotFull();
        this->quantity_of_items++;
    }

    this->items[index] = content;
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
