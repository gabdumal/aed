#include "openAddressingHash.hpp"

#include <expected>
#include <print>
#include <string>

OpenAddressingHash::OpenAddressingHash(int maximum_size) {
    if (maximum_size < 1) {
        throw(std::string("Maximum size should be at least 1."));
    }

    this->maximum_size = (unsigned int) maximum_size;

    this->items = new Content[this->maximum_size];

    for (auto index = 0; index < maximum_size; index++) {
        this->items[index] = empty_slot;
    }
}

OpenAddressingHash::~OpenAddressingHash() {
    delete[] this->items;
}

std::expected<unsigned int, std::string> OpenAddressingHash::calculateIndex(int key) {
    if (key < 0) {
        return std::unexpected("Key should be at least 0.");
    }
    return (unsigned int) key %
           this->maximum_size;
}

bool OpenAddressingHash::contains(Content content) {
    for (
        unsigned int current_index = 0;
        current_index < this->maximum_size;
        current_index++) {
        if (this->items[current_index] == content) {
            return true;
        }
    }
    return false;
}

std::expected<void, std::string> OpenAddressingHash::insert(int key, Content content) {
    if (content <= 0) {
        return std::unexpected("Content must be at least 0.");
    }

    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }
    auto current_index = ideal_index.value();

    for (unsigned int steps = 0;
         steps < this->maximum_size;
         steps++) {
        auto content_at_current_index = this->items[current_index];

        if (content_at_current_index == empty_slot ||
            content_at_current_index == deleted_slot) {
            this->items[current_index] = content;
            return {};
        }

        current_index = (current_index + 1) %
                        this->maximum_size;
    }

    return std::unexpected("Hash table is full.");
}

std::expected<void, std::string> OpenAddressingHash::remove(int key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }
    auto current_index = ideal_index.value();

    for (unsigned int steps = 0;
         steps < this->maximum_size;
         steps++) {
        auto content_at_current_index = this->items[current_index];

        if (content_at_current_index == empty_slot) {
            return {};
        } else if (content_at_current_index == deleted_slot) {
            current_index = (current_index + 1) %
                            this->maximum_size;
        } else {
            this->items[current_index] = deleted_slot;
            return {};
        }
    }

    return std::unexpected("Hash table is empty.");
}

std::expected<OpenAddressingHash::Content, std::string> OpenAddressingHash::getContent(int key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }
    auto current_index = ideal_index.value();

    for (unsigned int steps = 0;
         steps < this->maximum_size;
         steps++) {
        auto content_at_current_index = this->items[current_index];

        if (content_at_current_index == empty_slot) {
            break;
        } else if (content_at_current_index == deleted_slot) {
            current_index = (current_index + 1) %
                            this->maximum_size;
        } else {
            return content_at_current_index;
        }
    }

    return empty_slot;
}

std::string OpenAddressingHash::printContent(OpenAddressingHash::Content content) {
    if (content == empty_slot) {
        return "-";
    } else if (content == deleted_slot) {
        return "X";
    }
    return std::to_string(content);
}

void OpenAddressingHash::print() {
    unsigned int index = 0;
    while (index + 1 < this->maximum_size) {
        std::print(
            "{}, ",
            this->printContent(this->items[index]));
        index++;
    }
    if (index < this->maximum_size && index >= 0) {
        std::print(
            "{}",
            this->printContent(this->items[index]));
    }
    std::println();
}
