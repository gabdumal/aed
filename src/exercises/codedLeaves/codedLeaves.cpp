#include "codedLeaves.hpp"

#include <print>

CodedLeaves::Node *CodedLeaves::insertNode(
    Node *node, std::string code, unsigned int index) {
    if (node == nullptr) {
        node = new Node({.code = code.substr(0, index)});
    }

    if (index < code.length()) {
        // Not leaf node.
        auto direction = code[index];
        if (direction == left) {
            node->left_child = insertNode(node->left_child, code, index + 1);
        } else {
            node->right_child = insertNode(node->right_child, code, index + 1);
        }
    }

    return node;
}

CodedLeaves::Node *CodedLeaves::buildTree(std::vector<std::string> leaves) {
    Node *root = nullptr;
    for (unsigned int index = 0; index < leaves.size(); index++) {
        std::string code = leaves[index];
        std::println("Inserting: {}.", code);
        root = CodedLeaves::insertNode(root, code, 0);
        CodedLeaves::print(root);
        std::println();
    }
    return root;
}

void CodedLeaves::main() {
    {
        std::vector<std::string> leaves = {""};
        auto tree = CodedLeaves::buildTree(leaves);
        delete tree;
    }

    {
        std::vector<std::string> leaves = {"0"};
        auto tree = CodedLeaves::buildTree(leaves);
        delete tree;
    }

    {
        std::vector<std::string> leaves = {"1"};
        auto tree = CodedLeaves::buildTree(leaves);
        delete tree;
    }

    {
        std::vector<std::string> leaves = {"0", "1"};
        auto tree = CodedLeaves::buildTree(leaves);
        delete tree;
    }

    {
        std::vector<std::string> leaves = {"01", "1001"};
        auto tree = CodedLeaves::buildTree(leaves);
        delete tree;
    }

    {
        std::vector<std::string> leaves = {"", "0", "1", "00", "01", "10", "11"};
        auto tree = CodedLeaves::buildTree(leaves);
        delete tree;
    }
}

std::string CodedLeaves::recursivePrint(Node *node, const std::string &prefix, bool is_last_child, bool is_root) {
    std::string output = "";

    if (node == nullptr) {
        return output;
    }

    if (is_root) {
        output += std::format("{}\n", node->code);
    } else {
        auto connector = is_last_child ? "└── " : "├── ";
        output += prefix + connector + std::format("{}\n", node->code);
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
        output += CodedLeaves::recursivePrint(node->right_child, child_prefix, false, false);
    } else {
        auto connector = "├── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    if (has_left_child) {
        output += CodedLeaves::recursivePrint(node->left_child, child_prefix, true, false);
    } else {
        auto connector = "└── ";
        output += child_prefix + connector + std::format("{}\n", std::string("-"));
    }

    return output;
}

void CodedLeaves::print(Node *tree) {
    auto output = CodedLeaves::recursivePrint(tree, std::string(""), false, true);
    std::print("{}", output);
}
