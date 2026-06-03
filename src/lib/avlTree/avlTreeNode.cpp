#include "avlTreeNode.hpp"

#include <algorithm>
#include <expected>
#include <format>
#include <print>
#include <queue>

AvlTreeNode::AvlTreeNode(Content content) {
    this->content = content;
    this->height = 1;
    for (unsigned int current_index = 0;
         current_index < this->maximum_quantity_of_children;
         ++current_index) {
        this->children[current_index] = nullptr;
    }
}

AvlTreeNode::~AvlTreeNode() {
    for (unsigned int current_index = 0;
         current_index < this->maximum_quantity_of_children;
         current_index++) {
        delete this->children[current_index];
        this->children[current_index] = nullptr;
    }

    this->content = default_content;
    this->height = 0;
}

AvlTreeNode *AvlTreeNode::rotateToLeft(AvlTreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    auto right_child = node->children[index_of_right_child];
    if (right_child == nullptr) {
        return node;
    }
    auto left_child_of_right_child =
        right_child == nullptr
            ? nullptr
            : right_child->children[index_of_left_child];

    right_child->children[index_of_left_child] = node;
    node->children[index_of_right_child] = left_child_of_right_child;

    node->height =
        1 + std::max(
                getHeight(node->children[index_of_left_child]),
                getHeight(node->children[index_of_right_child]));
    right_child->height =
        1 + std::max(
                getHeight(right_child->children[index_of_left_child]),
                getHeight(right_child->children[index_of_right_child]));

    return right_child;
}

AvlTreeNode *AvlTreeNode::rotateToRight(AvlTreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    auto left_child = node->children[index_of_left_child];
    if (left_child == nullptr) {
        return node;
    }

    auto right_child_of_left_child =
        left_child == nullptr
            ? nullptr
            : left_child->children[index_of_right_child];

    left_child->children[index_of_right_child] = node;
    node->children[index_of_left_child] = right_child_of_left_child;

    node->height =
        1 + std::max(
                getHeight(node->children[index_of_left_child]),
                getHeight(node->children[index_of_right_child]));
    left_child->height =
        1 + std::max(
                getHeight(left_child->children[index_of_left_child]),
                getHeight(left_child->children[index_of_right_child]));

    return left_child;
}

AvlTreeNode *AvlTreeNode::rotateToLeftThenRight(AvlTreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    auto left_child = node->children[index_of_left_child];
    node->children[index_of_left_child] = rotateToLeft(left_child);

    return rotateToRight(node);
}

AvlTreeNode *AvlTreeNode::rotateToRightThenLeft(AvlTreeNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    auto right_child = node->children[index_of_right_child];
    node->children[index_of_right_child] = rotateToRight(right_child);

    return rotateToLeft(node);
}

AvlTreeNode *AvlTreeNode::recursiveInsert(AvlTreeNode *node, Content content) {
    if (node == nullptr) {
        auto new_node = new AvlTreeNode(content);
        return new_node;
    }

    if (content < node->content) {
        node->children[index_of_left_child] = recursiveInsert(node->children[index_of_left_child], content);
    } else {
        node->children[index_of_right_child] = recursiveInsert(node->children[index_of_right_child], content);
    }

    auto left_child = node->children[index_of_left_child];
    auto right_child = node->children[index_of_right_child];

    node->height =
        1 + std::max(
                getHeight(left_child),
                getHeight(right_child));

    auto balancing_factor = getBalancingFactor(node);

    auto balancing_factor_of_left_child = getBalancingFactor(left_child);
    if (balancing_factor >= 2 && balancing_factor_of_left_child >= 1) {
        return rotateToRight(node);
    }
    if (balancing_factor >= 2 && balancing_factor_of_left_child <= -1) {
        return rotateToLeftThenRight(node);
    }

    auto balancing_factor_of_right_child = getBalancingFactor(right_child);
    if (balancing_factor <= -2 && balancing_factor_of_right_child <= -1) {
        return rotateToLeft(node);
    }
    if (balancing_factor <= -2 && balancing_factor_of_right_child >= 1) {
        return rotateToRightThenLeft(node);
    }

    return node;
}

void AvlTreeNode::insert(Content content) {
    AvlTreeNode::recursiveInsert(this, content);
}

bool AvlTreeNode::recursiveContains(AvlTreeNode *node, Content content) {
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

bool AvlTreeNode::contains(Content content) {
    return AvlTreeNode::recursiveContains(this, content);
}

AvlTreeNode *AvlTreeNode::getSuccessor(AvlTreeNode *node) {
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

void AvlTreeNode::switchNodes(AvlTreeNode *first_node, AvlTreeNode *second_node) {
    auto content_of_first_node = first_node->content;
    auto content_of_second_node = second_node->content;

    second_node->content = content_of_first_node;
    first_node->content = content_of_second_node;
}

std::expected<AvlTreeNode *, std::string> AvlTreeNode::advanceStepToFindNodeToRemove(AvlTreeNode *node, Content content, unsigned int index_of_child) {
    auto next_node = recursiveRemove(node->children[index_of_child], content);
    if (!next_node) {
        return std::unexpected(next_node.error());
    }

    node->children[index_of_child] = next_node.value();
    return node;
}

AvlTreeNode *AvlTreeNode::removeNodeWith0Or1Children(AvlTreeNode *node, unsigned int index_of_child) {
    auto child = node->children[index_of_child];
    node->children[index_of_child] = nullptr;
    delete node;
    return child;
}

std::expected<AvlTreeNode *, std::string> AvlTreeNode::recursiveRemove(AvlTreeNode *node, Content content) {
    if (node == nullptr) {
        return std::unexpected(message_for_content_not_found);
    }

    if (content == node->content) {
        // Node with 0 or 1 children.
        if (node->children[index_of_left_child] == nullptr) {
            return AvlTreeNode::removeNodeWith0Or1Children(node, index_of_right_child);
        }
        if (node->children[index_of_right_child] == nullptr) {
            return AvlTreeNode::removeNodeWith0Or1Children(node, index_of_left_child);
        }

        // Node with 2 children.
        auto successor_node = AvlTreeNode::getSuccessor(node);
        AvlTreeNode::switchNodes(node, successor_node);

        auto result = AvlTreeNode::recursiveRemove(node->children[index_of_right_child], successor_node->content);
        if (!result) {
            return std::unexpected(result.error());
        }

        auto new_right_child_of_node = result.value();
        node->children[index_of_right_child] = new_right_child_of_node;

        return node;
    }

    if (content < node->content) {
        return AvlTreeNode::advanceStepToFindNodeToRemove(node, content, index_of_left_child);
    } else {
        return AvlTreeNode::advanceStepToFindNodeToRemove(node, content, index_of_right_child);
    }
}

std::expected<void, std::string> AvlTreeNode::remove(Content content) {
    auto result = AvlTreeNode::recursiveRemove(this, content);
    if (!result) {
        return std::unexpected(result.error());
    } else {
        return {};
    }
}

std::string AvlTreeNode::recursivePrint(AvlTreeNode *node, const std::string &prefix, bool is_last_child, bool is_root) {
    std::string output = "";

    if (node == nullptr) {
        return output;
    }

    if (is_root) {
        output += std::format("{} ({})\n", node->content, getBalancingFactor(node));
    } else {
        auto connector = is_last_child ? "└── " : "├── ";
        output += prefix + connector + std::format("{} ({})\n", node->content, getBalancingFactor(node));
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
        output += AvlTreeNode::recursivePrint(node->children[index_of_right_child], child_prefix, false, false);
    } else {
        auto connector = "├── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    if (has_left_child) {
        output += AvlTreeNode::recursivePrint(node->children[index_of_left_child], child_prefix, true, false);
    } else {
        auto connector = "└── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    return output;
}

void AvlTreeNode::print() {
    auto output = AvlTreeNode::recursivePrint(this, std::string(""), false, true);
    std::print("{}", output);
}

unsigned int AvlTreeNode::countNodes() {
    unsigned int quantity_of_nodes = 0;

    auto queue = std::queue<AvlTreeNode *>();
    queue.push(this);

    while (!queue.empty()) {
        auto current_node = queue.front();
        queue.pop();

        quantity_of_nodes++;

        if (current_node->children[index_of_left_child] != nullptr) {
            queue.push(current_node->children[index_of_left_child]);
        }
        if (current_node->children[index_of_right_child] != nullptr) {
            queue.push(current_node->children[index_of_right_child]);
        }
    }

    return quantity_of_nodes;
}

unsigned int AvlTreeNode::recursiveCountNodesRecursively(AvlTreeNode *node) {
    if (node == nullptr) {
        return 0;
    }

    auto quantity_of_nodes_to_the_left = AvlTreeNode::recursiveCountNodesRecursively(node->children[index_of_left_child]);
    auto quantity_of_nodes_to_the_right = AvlTreeNode::recursiveCountNodesRecursively(node->children[index_of_right_child]);

    return quantity_of_nodes_to_the_left + quantity_of_nodes_to_the_right + 1;
}

unsigned int AvlTreeNode::countNodesRecursively() {
    return AvlTreeNode::recursiveCountNodesRecursively(this);
}

unsigned int AvlTreeNode::getHeight(AvlTreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AvlTreeNode::getBalancingFactor(AvlTreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return (int) getHeight(node->children[index_of_left_child]) -
           (int) getHeight(node->children[index_of_right_child]);
}

bool AvlTreeNode::recursiveIsStrictlyBinary(AvlTreeNode *node) {
    if (node == nullptr) {
        return true;
    }

    auto left_child = node->children[index_of_left_child];
    auto right_child = node->children[index_of_right_child];

    if ((left_child == nullptr) != (right_child == nullptr)) {
        return false;
    }

    auto is_strictly_binary_to_the_left = recursiveIsStrictlyBinary(left_child);
    auto is_strictly_binary_to_the_right = recursiveIsStrictlyBinary(right_child);

    return is_strictly_binary_to_the_left && is_strictly_binary_to_the_right;
}

bool AvlTreeNode::isStrictlyBinary() {
    return AvlTreeNode::recursiveIsStrictlyBinary(this);
}

bool AvlTreeNode::isComplete() {
    auto queue = std::queue<AvlTreeNode *>();
    queue.push(this);

    bool has_found_a_null_node_already = false;

    while (!queue.empty()) {
        auto current_node = queue.front();
        queue.pop();

        if (current_node->children[index_of_left_child] == nullptr) {
            has_found_a_null_node_already = true;
        } else {
            if (has_found_a_null_node_already) {
                return false;
            }
            queue.push(current_node->children[index_of_left_child]);
        }

        if (current_node->children[index_of_right_child] == nullptr) {
            has_found_a_null_node_already = true;
        } else {
            if (has_found_a_null_node_already) {
                return false;
            }
            queue.push(current_node->children[index_of_right_child]);
        }
    }

    return true;
}
