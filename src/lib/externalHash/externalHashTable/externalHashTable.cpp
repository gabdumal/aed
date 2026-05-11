#include "externalHashTable.hpp"

ExternalHashTable::ExternalHashTable(int maximum_size) {
    if (maximum_size < 1) {
        throw(std::string("Maximum size should be at least 1."));
    }

    this->maximum_size = (unsigned int) maximum_size;

    this->items = &(new (ExternalHashNode *))[this->maximum_size];

    for (auto index = 0; index < maximum_size; index++) {
        this->items[index] = nullptr;
    }
}

ExternalHashTable::~ExternalHashTable() {
    delete[] this->items;
}
