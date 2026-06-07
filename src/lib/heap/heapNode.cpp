#include "heapNode.hpp"

#include <algorithm>
#include <expected>
#include <format>
#include <print>
#include <queue>

HeapNode::HeapNode(Content content) {
    this->content = content;
    this->parent = nullptr;
    this->left_child = nullptr;
    this->right_child = nullptr;
}

HeapNode::~HeapNode() {
    this->content = default_content;

    this->parent = nullptr;

    delete left_child;
    this->left_child = nullptr;

    delete right_child;
    this->right_child = nullptr;
}

void HeapNode::ascend(HeapNode *node) {
    if (node == nullptr) {
        return;
    }

    if (node->parent != nullptr &&
        node->parent->content > node->content) {
        std::swap(node->content, node->parent->content);
        ascend(node->parent);
    }
}

HeapNode *HeapNode::descend(HeapNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    // Percolate the node's content down the heap until the heap property
    // is restored (i.e. node->content <= both children's content).
    while (node->left_child != nullptr || node->right_child != nullptr) {
        HeapNode *smallest_child = node->left_child;

        if (node->right_child != nullptr) {
            if (smallest_child == nullptr || node->right_child->content < smallest_child->content) {
                smallest_child = node->right_child;
            }
        }

        if (smallest_child == nullptr) {
            break;
        }

        if (smallest_child->content < node->content) {
            std::swap(node->content, smallest_child->content);
            node = smallest_child;
        } else {
            break;
        }
    }

    return node;
}

void HeapNode::insert(Content content) {
    std::queue<HeapNode *> queue;
    queue.push(this);

    while (!queue.empty()) {
        HeapNode *current = queue.front();
        queue.pop();

        if (current->left_child == nullptr) {
            current->left_child = new HeapNode(content);
            current->left_child->parent = current;
            ascend(current->left_child);
            return;
        } else {
            queue.push(current->left_child);
        }

        if (current->right_child == nullptr) {
            current->right_child = new HeapNode(content);
            current->right_child->parent = current;
            ascend(current->right_child);
            return;
        } else {
            queue.push(current->right_child);
        }
    }
}

bool HeapNode::contains(Content content) {
    std::queue<HeapNode *> queue;

    queue.push(this);
    while (!queue.empty()) {
        auto current = queue.front();
        queue.pop();

        if (current->content == content) {
            return true;
        }

        if (current->left_child != nullptr &&
            current->left_child->content <= content) {
            queue.push(current->left_child);
        }

        if (current->right_child != nullptr &&
            current->right_child->content <= content) {
            queue.push(current->right_child);
        }
    }

    return false;
}

std::expected<void, std::string> HeapNode::remove(Content content) {
    // Find the node to remove and the last node (rightmost deepest) via level-order traversal.
    std::queue<HeapNode *> queue;
    queue.push(this);

    HeapNode *node_to_remove = nullptr;
    HeapNode *last_node = nullptr;

    while (!queue.empty()) {
        auto current = queue.front();
        queue.pop();

        if (current->content == content && node_to_remove == nullptr) {
            node_to_remove = current;
        }

        last_node = current;

        if (current->left_child != nullptr) {
            queue.push(current->left_child);
        }
        if (current->right_child != nullptr) {
            queue.push(current->right_child);
        }
    }

    if (node_to_remove == nullptr) {
        return std::unexpected(message_for_content_not_found);
    }

    // If the node to remove is the last node, simply detach and delete it (or reset root).
    if (node_to_remove == last_node) {
        if (node_to_remove->parent != nullptr) {
            if (node_to_remove->parent->left_child == node_to_remove) {
                node_to_remove->parent->left_child = nullptr;
            } else if (node_to_remove->parent->right_child == node_to_remove) {
                node_to_remove->parent->right_child = nullptr;
            }
            delete node_to_remove;
        } else {
            // Single-node heap (root). Reset content to default.
            this->content = default_content;
        }

        return {};
    }

    // Replace target node's content with last node's content, remove last node, then restore heap property.
    node_to_remove->content = last_node->content;

    if (last_node->parent != nullptr) {
        if (last_node->parent->left_child == last_node) {
            last_node->parent->left_child = nullptr;
        } else if (last_node->parent->right_child == last_node) {
            last_node->parent->right_child = nullptr;
        }
    }

    delete last_node;

    // After replacing, the node may need to move up or down to restore heap invariant.
    if (node_to_remove->parent != nullptr && node_to_remove->parent->content > node_to_remove->content) {
        HeapNode::ascend(node_to_remove);
    } else {
        HeapNode::descend(node_to_remove);
    }

    return {};
}

std::expected<HeapNode::Content, std::string> HeapNode::pop() {
    // Save the root content to return later.
    Content top_content = this->content;

    // If the node is a leaf (single-node heap), reset content to default and return it.
    if (this->left_child == nullptr && this->right_child == nullptr) {
        this->content = default_content;
        return top_content;
    }

    // Find the last node (rightmost deepest) via level-order traversal.
    std::queue<HeapNode *> queue;
    queue.push(this);

    HeapNode *last_node = nullptr;

    while (!queue.empty()) {
        auto current = queue.front();
        queue.pop();

        last_node = current;

        if (current->left_child != nullptr) {
            queue.push(current->left_child);
        }
        if (current->right_child != nullptr) {
            queue.push(current->right_child);
        }
    }

    if (last_node == nullptr) {
        return std::unexpected(message_for_content_not_found);
    }

    // Replace root content with last node's content, detach and delete last node.
    this->content = last_node->content;

    if (last_node->parent != nullptr) {
        if (last_node->parent->left_child == last_node) {
            last_node->parent->left_child = nullptr;
        } else if (last_node->parent->right_child == last_node) {
            last_node->parent->right_child = nullptr;
        }
    }

    delete last_node;

    // Restore heap invariant by percolating the new root content down.
    HeapNode::descend(this);

    return top_content;
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
