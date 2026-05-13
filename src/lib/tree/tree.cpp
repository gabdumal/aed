#include "tree.hpp"

Tree::Tree(unsigned int maximum_quantity_of_children, Content content) {
    this->maximum_quantity_of_children = maximum_quantity_of_children;
    this->children = new Tree *[maximum_quantity_of_children];
    this->content = content;
}

Tree::~Tree() {
    for (unsigned int current_index = 0; current_index < this->maximum_quantity_of_children; current_index++) {
        auto current_child = this->children[current_index];
        delete current_child;
    }

    this->content = default_content;
    this->maximum_quantity_of_children = 0;

    delete[] this->children;
}
