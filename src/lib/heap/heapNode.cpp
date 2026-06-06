#include "heapNode.hpp"

#include <algorithm>
#include <expected>
#include <format>
#include <print>

HeapNode::HeapNode(Content content) {
    this->content = content;
    this->left_child = nullptr;
    this->right_child = nullptr;
}

HeapNode::~HeapNode() {
    this->content = default_content;

    delete left_child;
    this->left_child = nullptr;

    delete right_child;
    this->right_child = nullptr;
}

HeapNode *HeapNode::recursiveInsert(HeapNode *node, Content content) {
    if (node == nullptr) {
        auto new_node = new HeapNode(content);
        return new_node;
    }

    return nullptr;
}

void HeapNode::insert(Content content) {
    HeapNode::recursiveInsert(this, content);
}

bool HeapNode::recursiveContains(HeapNode *node, Content content) {
    if (node == nullptr) {
        return false;
    }

    if (content == node->content) {
        return true;
    }

    return false;
}

bool HeapNode::contains(Content content) {
    return HeapNode::recursiveContains(this, content);
}

std::expected<HeapNode *, std::string> HeapNode::recursiveRemove(HeapNode *node, Content content) {
    if (node == nullptr) {
        return std::unexpected(message_for_content_not_found);
    }

    return nullptr;
}

std::expected<void, std::string> HeapNode::remove(Content content) {
    auto result = HeapNode::recursiveRemove(this, content);
    if (!result) {
        return std::unexpected(result.error());
    } else {
        return {};
    }
}

std::string HeapNode::recursivePrint(HeapNode *node, const std::string &prefix, bool is_last_child, bool is_root) {
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

    bool has_left_child = node->left_child != nullptr;
    bool has_right_child = node->right_child != nullptr;

    // If this is a leaf, don't show child positions.
    if (!has_left_child && !has_right_child) {
        return output;
    }

    if (has_right_child) {
        output += HeapNode::recursivePrint(node->right_child, child_prefix, false, false);
    } else {
        auto connector = "├── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    if (has_left_child) {
        output += HeapNode::recursivePrint(node->left_child, child_prefix, true, false);
    } else {
        auto connector = "└── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    return output;
}

void HeapNode::print() {
    auto output = HeapNode::recursivePrint(this, std::string(""), false, true);
    std::print("{}", output);
}

unsigned int HeapNode::recursiveCountNodesRecursively(HeapNode *node) {
    if (node == nullptr) {
        return 0;
    }

    auto quantity_of_nodes_to_the_left = HeapNode::recursiveCountNodesRecursively(node->left_child);
    auto quantity_of_nodes_to_the_right = HeapNode::recursiveCountNodesRecursively(node->right_child);

    return quantity_of_nodes_to_the_left + quantity_of_nodes_to_the_right + 1;
}

unsigned int HeapNode::countNodes() {
    return HeapNode::recursiveCountNodesRecursively(this);
}

unsigned int HeapNode::getHeight(HeapNode *node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 +
           std::max(
               getHeight(node->left_child),
               getHeight(node->right_child));
}

bool HeapNode::recursiveIsStrictlyBinary(HeapNode *node) {
    if (node == nullptr) {
        return true;
    }

    if ((node->left_child == nullptr) !=
        (node->right_child == nullptr)) {
        return false;
    }

    auto is_strictly_binary_to_the_left = recursiveIsStrictlyBinary(node->left_child);
    auto is_strictly_binary_to_the_right = recursiveIsStrictlyBinary(node->right_child);

    return is_strictly_binary_to_the_left && is_strictly_binary_to_the_right;
}

bool HeapNode::isStrictlyBinary() {
    return HeapNode::recursiveIsStrictlyBinary(this);
}
