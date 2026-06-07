#include "binomialHeapNode.hpp"

#include <format>
#include <print>
#include <queue>

BinomialHeapNode::BinomialHeapNode(Content content) {
    this->content = content;
    this->parent = nullptr;
    this->sibling = nullptr;
}

BinomialHeapNode::~BinomialHeapNode() {
    this->content = default_content;

    this->parent = nullptr;

    delete child;
    this->child = nullptr;

    delete sibling;
    this->sibling = nullptr;
}

unsigned int BinomialHeapNode::getOrder() {
    return this->order;
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

    bool has_child = node->child != nullptr;
    bool has_sibling = node->sibling != nullptr;

    // If this node has neither a child nor a sibling, nothing more to print.
    if (!has_child && !has_sibling) {
        return output;
    }

    // In the left-child / right-sibling representation, print the sibling first
    // (so it appears on the same level to the right), then the child (as the
    // left-most child). Use placeholders when a position is empty to keep the
    // visual alignment consistent.
    if (has_sibling) {
        output += BinomialHeapNode::recursivePrint(node->sibling, child_prefix, false, false);
    } else {
        auto connector = "├── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    if (has_child) {
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
            quantity_of_nodes += (unsigned int) 2 << (((int) this->order) - 1);
        }

        current = current->sibling;
    }

    return quantity_of_nodes;
}
