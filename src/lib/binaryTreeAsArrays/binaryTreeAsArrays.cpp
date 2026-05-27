#include "binaryTreeAsArrays.hpp"

#include <expected>
#include <print>
#include <stdexcept>

BinaryTreeAsArrays::BinaryTreeAsArrays(unsigned int maximum_size) {
    if (maximum_size < 1) {
        throw std::invalid_argument("Maximum size should be at least 1.");
    }

    this->maximum_size = maximum_size;

    this->content = new Content[maximum_size];
    this->left_child = new unsigned int[maximum_size];
    this->right_child = new unsigned int[maximum_size];
    this->next_free_position = new unsigned int[maximum_size];

    for (unsigned int current_index = 0;
         current_index < this->maximum_size;
         ++current_index) {
        this->content[current_index] = empty_content;
        this->right_child[current_index] = empty_index;
        this->left_child[current_index] = empty_index;
        this->next_free_position[current_index] = empty_index;
    }
}

BinaryTreeAsArrays::~BinaryTreeAsArrays() {
    delete[] this->content;
    delete[] this->left_child;
    delete[] this->right_child;
    delete[] this->next_free_position;
}

bool BinaryTreeAsArrays::recursiveContains(unsigned int index, Content content) {
    if (index == empty_index) {
        return false;
    }

    if (this->content[index] == content) {
        return true;
    }

    if (content < this->content[index]) {
        return this->recursiveContains(this->left_child[index], content);
    } else {
        return this->recursiveContains(this->right_child[index], content);
    }
}

bool BinaryTreeAsArrays::contains(Content content) {
    return this->recursiveContains(this->index_of_root, content);
}

unsigned int BinaryTreeAsArrays::allocatePosition() {
    // Reuse previously removed position.
    if (this->first_free_position != empty_index) {
        auto reused_index = this->first_free_position;
        this->first_free_position = this->next_free_position[reused_index];
        return reused_index;
    }

    // Use new unused position.
    if (this->next_free_index == this->maximum_size) {
        throw std::length_error("Tree is full.");
    }
    auto new_index = this->next_free_index;
    this->next_free_index++;
    return new_index;
}

unsigned int BinaryTreeAsArrays::createNode(Content content) {
    unsigned int index_of_new_node = this->allocatePosition();
    this->content[index_of_new_node] = content;
    this->left_child[index_of_new_node] = empty_index;
    this->right_child[index_of_new_node] = empty_index;
    return index_of_new_node;
}

unsigned int BinaryTreeAsArrays::recursiveInsert(unsigned int index, Content content) {
    if (index == empty_index) {
        return createNode(content);
    }

    if (content < this->content[index]) {
        this->left_child[index] =
            this->recursiveInsert(this->left_child[index], content);
    } else {
        this->right_child[index] =
            this->recursiveInsert(this->right_child[index], content);
    }

    return index;
}

unsigned int BinaryTreeAsArrays::insert(Content content) {
    auto index_of_new_node = this->recursiveInsert(this->index_of_root, content);
    this->index_of_root = index_of_new_node;
    return index_of_new_node;
}

void BinaryTreeAsArrays::releasePosition(unsigned int removed_index) {
    this->next_free_position[removed_index] = this->first_free_position;
    this->first_free_position = removed_index;
}

unsigned int BinaryTreeAsArrays::findMinimum(unsigned int index) {
    while (this->left_child[index] != empty_index) {
        index = this->left_child[index];
    }
    return index;
}

std::expected<unsigned int, std::string> BinaryTreeAsArrays::recursiveRemove(unsigned int index, Content content) {
    if (index == empty_index) {
        return std::unexpected(message_for_content_not_found);
    }

    if (this->content[index] == content) {
        // Leaf node.
        if (this->left_child[index] == empty_index &&
            this->right_child[index] == empty_index) {
            this->releasePosition(index);
            return empty_index;
        }

        // Has only left child.
        if (this->right_child[index] == empty_index) {
            this->releasePosition(index);
            return this->left_child[index];
        }

        // Has only right child.
        if (this->left_child[index] == empty_index) {
            this->releasePosition(index);
            return this->right_child[index];
        }

        // Has both children.
        unsigned int index_of_successor = this->findMinimum(this->right_child[index]);

        this->content[index] = this->content[index_of_successor];

        auto result = this->recursiveRemove(this->right_child[index], this->content[index_of_successor]);
        if (!result) {
            return std::unexpected(result.error());
        }
        this->right_child[index] = result.value();

        return index;
    }

    if (content < this->content[index]) {
        auto result = recursiveRemove(this->left_child[index], content);
        if (!result) {
            return std::unexpected(result.error());
        }
        this->left_child[index] = result.value();
        return index;
    } else {
        auto result = recursiveRemove(this->right_child[index], content);
        if (!result) {
            return std::unexpected(result.error());
        }
        this->right_child[index] = result.value();
        return index;
    }
}

std::expected<void, std::string> BinaryTreeAsArrays::remove(Content content) {
    auto result = this->recursiveRemove(this->index_of_root, content);
    if (!result) {
        return std::unexpected(result.error());
    }
    return {};
}

std::string BinaryTreeAsArrays::recursivePrint(unsigned int index, const std::string &prefix, bool is_last_child, bool is_root) {
    std::string output = "";

    if (index == empty_index) {
        return output;
    }

    if (is_root) {
        output += std::format("{}\n", this->content[index]);
    } else {
        auto connector = is_last_child ? "└── " : "├── ";
        output += prefix + connector + std::format("{}\n", this->content[index]);
    }

    std::string child_prefix = prefix;
    if (!is_root) {
        child_prefix += is_last_child ? "    " : "│   ";
    }

    auto left_index = left_child[index];
    auto right_index = right_child[index];

    bool has_left_child = left_index != empty_index;
    bool has_right_child = right_index != empty_index;

    // If this is a leaf, don't show child positions.
    if (!has_left_child && !has_right_child) {
        return output;
    }

    if (has_right_child) {
        output += BinaryTreeAsArrays::recursivePrint(right_index, child_prefix, false, false);
    } else {
        auto connector = "├── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    if (has_left_child) {
        output += BinaryTreeAsArrays::recursivePrint(left_index, child_prefix, true, false);
    } else {
        auto connector = "└── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    return output;
}

void BinaryTreeAsArrays::print() {
    auto output = BinaryTreeAsArrays::recursivePrint(this->index_of_root, std::string(""), false, true);
    std::print("{}", output);
}
