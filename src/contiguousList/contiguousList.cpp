#include "contiguousList.hpp"

ContiguousList::ContiguousList(unsigned int maximum_size) {
    this->maximum_size = maximum_size;
    this->quantity_of_elements = 0;

    this->items = new Content[maximum_size];
}

ContiguousList::~ContiguousList() {
    delete[] this->items;
}
