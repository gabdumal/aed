#include "openAddressingHash.hpp"

#include <expected>
#include <print>
#include <stdexcept>
#include <string>

OpenAddressingHash::OpenAddressingHash(int maximum_size, int step) {
    if (maximum_size < 1) {
        throw std::invalid_argument("Maximum size should be at least 1.");
    }
    if (step < 1) {
        throw std::invalid_argument("Step should be at least 1.");
    }

    this->maximum_size = (unsigned int) maximum_size;
    this->step = (unsigned int) step;

    this->items = new Content[this->maximum_size];

    for (auto index = 0; index < maximum_size; index++) {
        this->items[index] = empty_slot;
    }
}

OpenAddressingHash::~OpenAddressingHash() {
    delete[] this->items;
}

std::expected<unsigned int, std::string> OpenAddressingHash::calculateIndex(OpenAddressingHash::ContentKey key) {
    if (key < 0) {
        return std::unexpected(message_for_negative_key);
    }
    return (unsigned int) key %
           this->maximum_size;
}

std::expected<bool, std::string> OpenAddressingHash::contains(OpenAddressingHash::ContentKey key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }
    auto current_index = ideal_index.value();

    for (unsigned int steps = 0;
         steps < this->maximum_size;
         steps++) {
        const auto &entry = this->items[current_index];

        if (entry.key == key) {
            return true;
        }

        current_index = (current_index + this->step) % this->maximum_size;
    }

    return false;
}

std::expected<void, std::string> OpenAddressingHash::insert(OpenAddressingHash::ContentKey key, OpenAddressingHash::ContentValue value) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }
    auto current_index = ideal_index.value();

    for (unsigned int steps = 0;
         steps < this->maximum_size;
         steps++) {
        auto &entry = this->items[current_index];

        if (entry.key == key_of_empty_slot ||
            entry.key == key_of_deleted_slot) {
            entry.key = key;
            entry.value = value;
            return {};
        }

        if (entry.key == key) {
            // Update existing key.
            entry.value = value;
            return {};
        }

        current_index = (current_index + this->step) % this->maximum_size;
    }

    return std::unexpected("Hash table is full.");
}

std::expected<void, std::string> OpenAddressingHash::remove(OpenAddressingHash::ContentKey key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }
    auto current_index = ideal_index.value();

    for (
        unsigned int steps = 0;
        steps < this->maximum_size;
        steps++) {
        auto &entry = this->items[current_index];

        if (entry.key == key_of_empty_slot) {
            break;
        } else if (entry.key == key) {
            // Found the key. Mark this slot as empty and
            // relocate subsequent clustered entries so lookups
            // remain correct.
            this->items[current_index] = empty_slot;

            unsigned int hole_index = current_index;
            unsigned int scan_index = hole_index;

            while (true) {
                scan_index = (scan_index + this->step) % this->maximum_size;
                const auto &scan_slot = this->items[scan_index];

                if (scan_slot.key == key_of_empty_slot) {
                    break;
                }

                auto expected_home_index = this->calculateIndex(scan_slot.key);
                if (!expected_home_index) {
                    // Invalid key stored — treat as removed and continue.
                    this->items[scan_index] = deleted_slot;
                    continue;
                }
                unsigned int home_index = expected_home_index.value();

                bool home_in_cyclic_range;
                if (hole_index <= scan_index) {
                    home_in_cyclic_range = (hole_index < home_index) && (home_index <= scan_index);
                } else {
                    home_in_cyclic_range = (home_index <= scan_index) || (hole_index < home_index);
                }

                if (home_in_cyclic_range) {
                    continue;
                }

                // Move entry at scan_index into the hole at hole_index, leaving scan_index empty.
                this->items[hole_index] = this->items[scan_index];
                this->items[scan_index] = empty_slot;
                hole_index = scan_index;
            }

            return {};
        } else {
            current_index = (current_index + this->step) % this->maximum_size;
        }
    }

    return std::unexpected(message_for_key_not_found);
}

std::expected<OpenAddressingHash::ContentValue, std::string> OpenAddressingHash::getContent(OpenAddressingHash::ContentKey key) {
    auto ideal_index = this->calculateIndex(key);
    if (!ideal_index) {
        return std::unexpected(ideal_index.error());
    }
    auto current_index = ideal_index.value();

    for (
        unsigned int steps = 0;
        steps < this->maximum_size;
        steps++) {
        const auto &entry = this->items[current_index];

        if (entry.key == key_of_empty_slot) {
            break;
        } else if (entry.key == key) {
            return entry.value;
        } else {
            current_index = (current_index + this->step) % this->maximum_size;
        }
    }

    return std::unexpected(message_for_key_not_found);
}

std::string OpenAddressingHash::printContent(OpenAddressingHash::Content content) {
    std::string key = "";
    if (content.key == key_of_empty_slot) {
        key = "-";
    } else if (content.key == key_of_deleted_slot) {
        key = "X";
    } else {
        key = std::to_string(content.key);
    }
    return std::format("( key: {}, value: {} )", key, content.value);
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
