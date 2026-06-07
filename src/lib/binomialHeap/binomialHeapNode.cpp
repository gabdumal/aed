#include "binomialHeapNode.hpp"

#include <format>
#include <print>
#include <stdexcept>
#include <vector>

BinomialHeapNode::BinomialHeapNode(Content content) {
    this->content = content;
    this->parent = nullptr;
    this->sibling = nullptr;
    this->child = nullptr;
    this->order = 0;
}

BinomialHeapNode::~BinomialHeapNode() {
    this->content = default_content;

    this->parent = nullptr;

    delete sibling;
    this->sibling = nullptr;

    delete child;
    this->child = nullptr;

    this->order = 0;
}

BinomialHeapNode *BinomialHeapNode::add(BinomialHeapNode *first_heap, BinomialHeapNode *second_heap) {
    if (first_heap == nullptr) {
        return second_heap;
    }
    if (second_heap == nullptr) {
        return first_heap;
    }
    if (first_heap->order != second_heap->order) {
        throw new std::invalid_argument("The order of both heaps must be the same.");
    }

    // Guarantee the heaps of greater order appear first on the linked list.
    if (first_heap->content > second_heap->content) {
        return add(second_heap, first_heap);
    }

    second_heap->sibling = first_heap->child;
    first_heap->child = second_heap;
    first_heap->order++;

    return first_heap;
}

BinomialHeapNode *BinomialHeapNode::unite(BinomialHeapNode *first_heap, BinomialHeapNode *second_heap) {
    if (first_heap == nullptr) {
        return second_heap;
    }
    if (second_heap == nullptr) {
        return first_heap;
    }

    auto current_on_first_heap = first_heap;
    auto current_on_second_heap = second_heap;

    BinomialHeapNode *new_heap = nullptr;
    if (current_on_first_heap->order > current_on_second_heap->order) {
        new_heap = current_on_first_heap;
        current_on_first_heap = current_on_first_heap->sibling;
    } else if (current_on_second_heap->order > current_on_first_heap->order) {
        new_heap = current_on_second_heap;
        current_on_second_heap = current_on_second_heap->sibling;
    }

    BinomialHeapNode *current = new_heap;

    while (true) {
        if (current_on_first_heap->order == current_on_second_heap->order) {
            current_on_first_heap = current_on_first_heap->sibling;
            current_on_second_heap = current_on_second_heap->sibling;

            current->sibling = add(current_on_first_heap, current_on_second_heap);
            current = current->sibling;
        } else if (current_on_first_heap->order > current_on_second_heap->order) {
            current_on_first_heap = current_on_first_heap->sibling;
            new_heap->sibling = current_on_first_heap;
        } else if (current_on_second_heap->order > current_on_first_heap->order) {
            current_on_second_heap = current_on_second_heap->sibling;
            new_heap->sibling = current_on_second_heap;
        }

        if (current_on_first_heap == nullptr ||
            current_on_second_heap == nullptr) {
            break;
        }
    }

    return new_heap;
}

void BinomialHeapNode::insert(Content content) {
}

BinomialHeapNode::Content BinomialHeapNode::front() {
    return default_content;
}

BinomialHeapNode::Content BinomialHeapNode::pop() {
    return default_content;
}

std::string BinomialHeapNode::recursivePrint(BinomialHeapNode *node, const std::string &prefix, bool is_last_child, bool is_root) {
    std::string output = "";

    if (node == nullptr) {
        return output;
    }

    if (is_root) {
        output += std::format("{}\n", node->content);
    } else {
        auto connector = is_last_child ? "└── " : "├── ";
        output += prefix + connector + std::format("{}\n", node->content);
    }

    std::string child_prefix = prefix;
    if (!is_root) {
        child_prefix += is_last_child ? "    " : "│   ";
    }

    // Collect all direct children (child + its siblings)
    std::vector<BinomialHeapNode *> children;
    for (auto c = node->child; c != nullptr; c = c->sibling) {
        children.push_back(c);
    }

    if (children.empty()) {
        return output;
    }

    // Print the left-most child first, then remaining siblings appear on the last rows.
    bool first_is_last = (children.size() == 1);
    output += BinomialHeapNode::recursivePrint(children[0], child_prefix, first_is_last, false);

    for (size_t i = 1; i < children.size(); ++i) {
        bool is_last = (i + 1 == children.size());
        output += BinomialHeapNode::recursivePrint(children[i], child_prefix, is_last, false);
    }

    return output;
}

void BinomialHeapNode::print() {
    auto output = BinomialHeapNode::recursivePrint(this, std::string(""), false, true);
    std::print("{}", output);
}

unsigned int BinomialHeapNode::countNodes() {
    unsigned int quantity_of_nodes = 0;
    auto current = this;

    while (current != nullptr) {
        if (current->order == 0) {
            quantity_of_nodes += 1;
        } else {
            quantity_of_nodes += (unsigned int) 2 << (((int) this->order) - 1);
        }

        current = current->sibling;
    }

    return quantity_of_nodes;
}
