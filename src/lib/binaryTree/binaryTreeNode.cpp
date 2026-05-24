#include "binaryTreeNode.hpp"

#include <expected>

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
        return recursiveInsert(node->children[index_of_left_child], content);
    } else {
        return recursiveInsert(node->children[index_of_right_child], content);
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

std::expected<BinaryTreeNode *, std::string> BinaryTreeNode::recursiveRemove(BinaryTreeNode *node, Content content) {
    if (node == nullptr) {
        return std::unexpected(message_for_content_not_found);
    }

    if (content == node->content) {
        // Node with 0 or 1 children.
        if (node->children[index_of_left_child] == nullptr) {
            auto right_child = node->children[index_of_right_child];
            delete node;
            return right_child;
        }
        if (node->children[index_of_right_child] == nullptr) {
            auto left_child = node->children[index_of_left_child];
            delete node;
            return left_child;
        }

        // Node with 2 children.
        auto node_to_be_deleted = node;
        auto left_child_of_node_to_be_deleted = node_to_be_deleted->children[index_of_left_child];
        auto right_child_of_node_to_be_deleted = node_to_be_deleted->children[index_of_right_child];

        auto successor_node = BinaryTreeNode::getSuccessor(node);
        auto left_child_of_successor_node = successor_node->children[index_of_left_child];
        auto right_child_of_successor_node = successor_node->children[index_of_right_child];

        successor_node->children[index_of_left_child] = left_child_of_node_to_be_deleted;
        successor_node->children[index_of_right_child] = right_child_of_node_to_be_deleted;

        node_to_be_deleted->children[index_of_left_child] = left_child_of_successor_node;
        node_to_be_deleted->children[index_of_right_child] = right_child_of_successor_node;

        return BinaryTreeNode::recursiveRemove(node_to_be_deleted, content);
    }

    if (content < node->content) {
        auto next_node = recursiveRemove(node->children[index_of_left_child], content);
        if (!next_node) {
            return std::unexpected(next_node.error());
        }
        node->children[index_of_left_child] = next_node.value();
    } else {
        auto next_node = recursiveRemove(node->children[index_of_right_child], content);
        if (!next_node) {
            return std::unexpected(next_node.error());
        }
        node->children[index_of_right_child] = next_node.value();
    }

    return node;
}

std::expected<void, std::string> BinaryTreeNode::remove(Content content) {
    auto result = BinaryTreeNode::recursiveRemove(this, content);
    if (!result) {
        return std::unexpected(result.error());
    } else {
        return {};
    }
}
