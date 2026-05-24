#include "binaryTreeNode.hpp"

#include <expected>
#include <format>
#include <print>

BinaryTreeNode::BinaryTreeNode(Content content) {
    this->content = content;
}

BinaryTreeNode::~BinaryTreeNode() {
    for (unsigned int current_index = 0;
         current_index < this->maximum_quantity_of_children;
         current_index++) {
        auto current_child = this->children[current_index];

        delete current_child;
        current_child = nullptr;
    }

    this->content = default_content;
}

BinaryTreeNode *BinaryTreeNode::recursiveInsert(BinaryTreeNode *node, Content content) {
    if (node == nullptr) {
        auto new_node = new BinaryTreeNode(content);
        return new_node;
    }

    if (content < node->content) {
        node->children[index_of_left_child] = recursiveInsert(node->children[index_of_left_child], content);
    } else {
        node->children[index_of_right_child] = recursiveInsert(node->children[index_of_right_child], content);
    }

    return node;
}

void BinaryTreeNode::insert(Content content) {
    BinaryTreeNode::recursiveInsert(this, content);
}

bool BinaryTreeNode::recursiveContains(BinaryTreeNode *node, Content content) {
    if (node == nullptr) {
        return false;
    }

    if (content == node->content) {
        return true;
    }

    if (content < node->content) {
        return recursiveContains(node->children[index_of_left_child], content);
    } else {
        return recursiveContains(node->children[index_of_right_child], content);
    }
}

bool BinaryTreeNode::contains(Content content) {
    return BinaryTreeNode::recursiveContains(this, content);
}

BinaryTreeNode *BinaryTreeNode::getSuccessor(BinaryTreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    auto successor_node = node->children[index_of_right_child];

    while (successor_node != nullptr &&
           successor_node->children[index_of_left_child] != nullptr) {
        successor_node = successor_node->children[index_of_left_child];
    }

    return successor_node;
}

void BinaryTreeNode::switchNodes(BinaryTreeNode *first_node, BinaryTreeNode *second_node) {
    auto content_of_first_node = first_node->content;
    auto content_of_second_node = second_node->content;

    second_node->content = content_of_first_node;
    first_node->content = content_of_second_node;
}

std::expected<BinaryTreeNode *, std::string> BinaryTreeNode::advanceStepToFindNodeToRemove(BinaryTreeNode *node, Content content, unsigned int index_of_child) {
    auto next_node = recursiveRemove(node->children[index_of_child], content);
    if (!next_node) {
        return std::unexpected(next_node.error());
    }

    node->children[index_of_child] = next_node.value();
    return node;
}

BinaryTreeNode *BinaryTreeNode::removeNodeWith0Or1Children(BinaryTreeNode *node, unsigned int index_of_child) {
    auto child = node->children[index_of_child];
    node->children[index_of_child] = nullptr;
    delete node;
    return child;
}

std::expected<BinaryTreeNode *, std::string> BinaryTreeNode::recursiveRemove(BinaryTreeNode *node, Content content) {
    if (node == nullptr) {
        return std::unexpected(message_for_content_not_found);
    }

    if (content == node->content) {
        // Node with 0 or 1 children.
        if (node->children[index_of_left_child] == nullptr) {
            return BinaryTreeNode::removeNodeWith0Or1Children(node, index_of_right_child);
        }
        if (node->children[index_of_right_child] == nullptr) {
            return BinaryTreeNode::removeNodeWith0Or1Children(node, index_of_left_child);
        }

        // Node with 2 children.
        auto successor_node = BinaryTreeNode::getSuccessor(node);
        BinaryTreeNode::switchNodes(node, successor_node);

        auto result = BinaryTreeNode::recursiveRemove(node->children[index_of_right_child], successor_node->content);
        if (!result) {
            return std::unexpected(result.error());
        }

        auto new_right_child_of_node = result.value();
        node->children[index_of_right_child] = new_right_child_of_node;

        return node;
    }

    if (content < node->content) {
        return BinaryTreeNode::advanceStepToFindNodeToRemove(node, content, index_of_left_child);
    } else {
        return BinaryTreeNode::advanceStepToFindNodeToRemove(node, content, index_of_right_child);
    }
}

std::expected<void, std::string> BinaryTreeNode::remove(Content content) {
    auto result = BinaryTreeNode::recursiveRemove(this, content);
    if (!result) {
        return std::unexpected(result.error());
    } else {
        return {};
    }
}

std::string BinaryTreeNode::recursivePrint(BinaryTreeNode *node, const std::string &prefix, bool is_last_child, bool is_root) {
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

    bool has_left_child = node->children[index_of_left_child] != nullptr;
    bool has_right_child = node->children[index_of_right_child] != nullptr;

    // If this is a leaf, don't show child positions.
    if (!has_left_child && !has_right_child) {
        return output;
    }

    if (has_right_child) {
        output += BinaryTreeNode::recursivePrint(node->children[index_of_right_child], child_prefix, false, false);
    } else {
        auto connector = "├── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    if (has_left_child) {
        output += BinaryTreeNode::recursivePrint(node->children[index_of_left_child], child_prefix, true, false);
    } else {
        auto connector = "└── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    return output;
}

void BinaryTreeNode::print() {
    auto output = BinaryTreeNode::recursivePrint(this, std::string(""), false, true);
    std::print("{}", output);
}
