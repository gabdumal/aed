#include "testBinaryTree.hpp"

#include <print>

#include "binaryTreeNode.hpp"

void TestBinaryTree::printTree(BinaryTreeNode *tree) {
    std::println("Tree: ");
    tree->print();
    std::println();
}

void TestBinaryTree::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestBinaryTree::testContains(BinaryTreeNode *tree, BinaryTreeNode::Content content) {
    std::println("Contains {}?", content);
    auto result = tree->contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestBinaryTree::testRemove(BinaryTreeNode *tree, BinaryTreeNode::Content content) {
    std::println("Remove {}.", content);
    auto result = tree->remove(content);
    if (!result) {
        printError(result.error());
    } else {
        printTree(tree);
    }
    std::println();
}

void TestBinaryTree::test() {
    BinaryTreeNode *tree = new BinaryTreeNode(10);
    tree->insert(5);
    tree->insert(20);
    tree->insert(15);
    tree->insert(1);
    tree->insert(7);
    tree->insert(4);
    tree->insert(2);
    tree->insert(25);
    tree->insert(22);
    tree->insert(6);
    tree->insert(3);
    tree->insert(8);
    tree->insert(9);
    tree->insert(11);
    tree->insert(12);

    TestBinaryTree::printTree(tree);

    TestBinaryTree::testContains(tree, 10);
    TestBinaryTree::testContains(tree, 0);
    TestBinaryTree::testContains(tree, 3);
    TestBinaryTree::testContains(tree, 8);
    TestBinaryTree::testContains(tree, 11);

    TestBinaryTree::testRemove(tree, 3);
    TestBinaryTree::testContains(tree, 3);

    TestBinaryTree::testRemove(tree, 8);
    TestBinaryTree::testContains(tree, 8);

    TestBinaryTree::testRemove(tree, 10);
    TestBinaryTree::testContains(tree, 10);

    TestBinaryTree::testRemove(tree, 11);
    TestBinaryTree::testContains(tree, 11);

    TestBinaryTree::testRemove(tree, 7);
    TestBinaryTree::testContains(tree, 7);

    TestBinaryTree::testRemove(tree, 7);
    TestBinaryTree::testContains(tree, 7);

    delete tree;
}
