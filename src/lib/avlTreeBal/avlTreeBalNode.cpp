#include "avlTreeBalNode.hpp"

#include <algorithm>
#include <expected>
#include <format>
#include <print>
#include <queue>

AvlTreeBalNode::AvlTreeBalNode(Content content) {
    this->content = content;
    this->balancing_factor = 0;
    for (unsigned int current_index = 0;
         current_index < this->maximum_quantity_of_children;
         ++current_index) {
        this->children[current_index] = nullptr;
    }
}

AvlTreeBalNode::~AvlTreeBalNode() {
    for (unsigned int current_index = 0;
         current_index < this->maximum_quantity_of_children;
         current_index++) {
        delete this->children[current_index];
        this->children[current_index] = nullptr;
    }

    this->content = default_content;
    this->balancing_factor = 0;
}

AvlTreeBalNode *AvlTreeBalNode::rotateToLeft(AvlTreeBalNode *node) {
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

    node->balancing_factor = getBalancingFactor(node);
    right_child->balancing_factor = getBalancingFactor(right_child);

    return right_child;
}

AvlTreeBalNode *AvlTreeBalNode::rotateToRight(AvlTreeBalNode *node) {
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

    node->balancing_factor = getBalancingFactor(node);
    left_child->balancing_factor = getBalancingFactor(left_child);

    return left_child;
}

AvlTreeBalNode *AvlTreeBalNode::rotateToLeftThenRight(AvlTreeBalNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    auto left_child = node->children[index_of_left_child];
    node->children[index_of_left_child] = rotateToLeft(left_child);

    return rotateToRight(node);
}

AvlTreeBalNode *AvlTreeBalNode::rotateToRightThenLeft(AvlTreeBalNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    auto right_child = node->children[index_of_right_child];
    node->children[index_of_right_child] = rotateToRight(right_child);

    return rotateToLeft(node);
}

AvlTreeBalNode *AvlTreeBalNode::updateAvlStructure(AvlTreeBalNode *node) {
    if (node == nullptr) {
        return nullptr;
    }

    auto left_child = node->children[index_of_left_child];
    auto right_child = node->children[index_of_right_child];

    auto balancing_factor = getBalancingFactor(node);
    node->balancing_factor = balancing_factor;

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

AvlTreeBalNode *AvlTreeBalNode::recursiveInsert(AvlTreeBalNode *node, Content content) {
    if (node == nullptr) {
        auto new_node = new AvlTreeBalNode(content);
        return new_node;
    }

    if (content < node->content) {
        node->children[index_of_left_child] = recursiveInsert(node->children[index_of_left_child], content);
    } else {
        node->children[index_of_right_child] = recursiveInsert(node->children[index_of_right_child], content);
    }

    return updateAvlStructure(node);
}

void AvlTreeBalNode::insert(Content content) {
    AvlTreeBalNode::recursiveInsert(this, content);
}

bool AvlTreeBalNode::recursiveContains(AvlTreeBalNode *node, Content content) {
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

bool AvlTreeBalNode::contains(Content content) {
    return AvlTreeBalNode::recursiveContains(this, content);
}

AvlTreeBalNode *AvlTreeBalNode::getSuccessor(AvlTreeBalNode *node) {
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

void AvlTreeBalNode::switchNodes(AvlTreeBalNode *first_node, AvlTreeBalNode *second_node) {
    auto content_of_first_node = first_node->content;
    auto content_of_second_node = second_node->content;

    second_node->content = content_of_first_node;
    first_node->content = content_of_second_node;
}

std::expected<AvlTreeBalNode *, std::string> AvlTreeBalNode::advanceStepToFindNodeToRemove(AvlTreeBalNode *node, Content content, unsigned int index_of_child) {
    auto next_node = recursiveRemove(node->children[index_of_child], content);
    if (!next_node) {
        return std::unexpected(next_node.error());
    }

    node->children[index_of_child] = next_node.value();
    return node;
}

AvlTreeBalNode *AvlTreeBalNode::removeNodeWith0Or1Children(AvlTreeBalNode *node, unsigned int index_of_child) {
    auto child = node->children[index_of_child];
    node->children[index_of_child] = nullptr;
    delete node;
    return child;
}

std::expected<AvlTreeBalNode *, std::string> AvlTreeBalNode::recursiveRemove(AvlTreeBalNode *node, Content content) {
    if (node == nullptr) {
        return std::unexpected(message_for_content_not_found);
    }

    if (content < node->content) {
        (void) AvlTreeBalNode::advanceStepToFindNodeToRemove(node, content, index_of_left_child);
    } else if (content > node->content) {
        (void) AvlTreeBalNode::advanceStepToFindNodeToRemove(node, content, index_of_right_child);
    } else {
        // Node with 0 or 1 children.
        if (node->children[index_of_left_child] == nullptr) {
            node = AvlTreeBalNode::removeNodeWith0Or1Children(node, index_of_right_child);
        } else if (node->children[index_of_right_child] == nullptr) {
            node = AvlTreeBalNode::removeNodeWith0Or1Children(node, index_of_left_child);
        } else {
            // Node with 2 children.
            auto successor_node = AvlTreeBalNode::getSuccessor(node);
            AvlTreeBalNode::switchNodes(node, successor_node);

            auto result = AvlTreeBalNode::recursiveRemove(node->children[index_of_right_child], successor_node->content);
            if (!result) {
                return std::unexpected(result.error());
            }

            auto new_right_child_of_node = result.value();
            node->children[index_of_right_child] = new_right_child_of_node;
        }
    }

    return updateAvlStructure(node);
}

std::expected<void, std::string> AvlTreeBalNode::remove(Content content) {
    auto result = AvlTreeBalNode::recursiveRemove(this, content);
    if (!result) {
        return std::unexpected(result.error());
    } else {
        return {};
    }
}

std::string AvlTreeBalNode::recursivePrint(AvlTreeBalNode *node, const std::string &prefix, bool is_last_child, bool is_root) {
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
        output += AvlTreeBalNode::recursivePrint(node->children[index_of_right_child], child_prefix, false, false);
    } else {
        auto connector = "├── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    if (has_left_child) {
        output += AvlTreeBalNode::recursivePrint(node->children[index_of_left_child], child_prefix, true, false);
    } else {
        auto connector = "└── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    return output;
}

void AvlTreeBalNode::print() {
    auto output = AvlTreeBalNode::recursivePrint(this, std::string(""), false, true);
    std::print("{}", output);
}

unsigned int AvlTreeBalNode::countNodes() {
    unsigned int quantity_of_nodes = 0;

    auto queue = std::queue<AvlTreeBalNode *>();
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

unsigned int AvlTreeBalNode::recursiveCountNodesRecursively(AvlTreeBalNode *node) {
    if (node == nullptr) {
        return 0;
    }

    auto quantity_of_nodes_to_the_left = AvlTreeBalNode::recursiveCountNodesRecursively(node->children[index_of_left_child]);
    auto quantity_of_nodes_to_the_right = AvlTreeBalNode::recursiveCountNodesRecursively(node->children[index_of_right_child]);

    return quantity_of_nodes_to_the_left + quantity_of_nodes_to_the_right + 1;
}

unsigned int AvlTreeBalNode::countNodesRecursively() {
    return AvlTreeBalNode::recursiveCountNodesRecursively(this);
}

unsigned int AvlTreeBalNode::getHeight(AvlTreeBalNode *node) {
    if (node == nullptr) {
        return 0;
    }

    auto left_child = node->children[index_of_left_child];
    auto right_child = node->children[index_of_right_child];

    if (node->balancing_factor > 0) {
        return 1 + getHeight(left_child);
    }
    if (node->balancing_factor < 0) {
        return 1 + getHeight(right_child);
    }
    return 1 +
           std::max(
               getHeight(left_child),
               getHeight(right_child));
}

int AvlTreeBalNode::getBalancingFactor(AvlTreeBalNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return (int) getHeight(node->children[index_of_left_child]) -
           (int) getHeight(node->children[index_of_right_child]);
}

bool AvlTreeBalNode::recursiveIsStrictlyBinary(AvlTreeBalNode *node) {
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

bool AvlTreeBalNode::isStrictlyBinary() {
    return AvlTreeBalNode::recursiveIsStrictlyBinary(this);
}

bool AvlTreeBalNode::isComplete() {
    auto queue = std::queue<AvlTreeBalNode *>();
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
