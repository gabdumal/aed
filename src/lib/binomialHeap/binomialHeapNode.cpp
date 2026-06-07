#include "binomialHeapNode.hpp"

#include <format>
#include <print>
#include <stdexcept>

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
        throw std::invalid_argument("The order of both heaps must be the same.");
    }

    // Guarantee the heaps of greater order appear first on the linked list.
    if (first_heap->content > second_heap->content) {
        return add(second_heap, first_heap);
    }

    second_heap->sibling = first_heap->child;
    first_heap->child = second_heap;
    second_heap->parent = first_heap;
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

    BinomialHeapNode *new_heap = nullptr;

    // Merge root lists by decreasing order (greater orders first).
    BinomialHeapNode *current_on_first_heap = first_heap;
    BinomialHeapNode *current_on_second_heap = second_heap;

    if (current_on_first_heap->order >= current_on_second_heap->order) {
        new_heap = current_on_first_heap;
        current_on_first_heap = current_on_first_heap->sibling;
    } else {
        new_heap = current_on_second_heap;
        current_on_second_heap = current_on_second_heap->sibling;
    }

    BinomialHeapNode *current = new_heap;
    while (current_on_first_heap != nullptr &&
           current_on_second_heap != nullptr) {
        if (current_on_first_heap->order >= current_on_second_heap->order) {
            current->sibling = current_on_first_heap;
            current_on_first_heap = current_on_first_heap->sibling;
        } else {
            current->sibling = current_on_second_heap;
            current_on_second_heap = current_on_second_heap->sibling;
        }
        current = current->sibling;
    }
    current->sibling = (current_on_first_heap != nullptr) ? current_on_first_heap : current_on_second_heap;

    // Consolidate: link trees of equal order so that no two roots have the same order.
    BinomialHeapNode *previous = nullptr;
    BinomialHeapNode *a = new_heap;
    BinomialHeapNode *b = a->sibling;

    while (b != nullptr) {
        auto c = b->sibling;

        if ((a->order != b->order) ||
            (c != nullptr && c->order == a->order)) {
            // Move forward.
            previous = a;
            a = b;
            b = c;
        } else {
            if (a->content < b->content) {
                // Heap 'a' becomes parent of heap 'b'.
                a->sibling = b->sibling;
                add(a, b);
                b = a->sibling;
            } else {
                // Heap 'b' becomes parent of heap 'c'.
                if (previous == nullptr) {
                    new_heap = b;
                } else {
                    previous->sibling = b;
                }
                add(b, a);
                previous = b;
                a = b;
                b = a->sibling;
            }
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

    bool has_left = node->child != nullptr;     // left child  = child
    bool has_right = node->sibling != nullptr;  // right child = sibling

    if (!has_left && !has_right) {
        return output;
    }

    // Print right subtree first so it appears above in the ASCII art.
    if (has_right) {
        output += BinomialHeapNode::recursivePrint(node->sibling, child_prefix, false, false);
    } else {
        auto connector = "├── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    if (has_left) {
        output += BinomialHeapNode::recursivePrint(node->child, child_prefix, true, false);
    } else {
        auto connector = "└── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
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
            quantity_of_nodes += (unsigned int) 2 << (((int) current->order) - 1);
        }

        current = current->sibling;
    }

    return quantity_of_nodes;
}
