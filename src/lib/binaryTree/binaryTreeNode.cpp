#include "binaryTreeNode.hpp"

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

    if (content < this->content) {
        this->children[index_of_left_child] = recursiveInsert(this->children[index_of_left_child], content);
    } else {
        this->children[index_of_right_child] = recursiveInsert(this->children[index_of_right_child], content);
    }

    return node;
}

void BinaryTreeNode::insert(Content content) {
    this->recursiveInsert(this, content);
}
