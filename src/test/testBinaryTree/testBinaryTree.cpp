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

void TestBinaryTree::testCountNodes(BinaryTreeNode *tree) {
    auto quantity_of_nodes = tree->countNodes();
    std::println("Quantity of nodes: {}.", quantity_of_nodes);
    std::println();
}

void TestBinaryTree::testCountNodesRecursively(BinaryTreeNode *tree) {
    auto quantity_of_nodes = tree->countNodesRecursively();
    std::println("Quantity of nodes (recursive): {}.", quantity_of_nodes);
    std::println();
}

void TestBinaryTree::testIsStrictlyBinary(BinaryTreeNode *tree) {
    auto is_strictly_binary = tree->isStrictlyBinary();
    std::println("Is strictly binary: {}.", is_strictly_binary);
    std::println();
}

void TestBinaryTree::testGetHeight(BinaryTreeNode *tree) {
    auto height = tree->getHeight();
    std::println("Height: {}.", height);
    std::println();
}

void TestBinaryTree::test() {
    BinaryTreeNode *tree = new BinaryTreeNode(10);

    TestBinaryTree::testCountNodes(tree);
    TestBinaryTree::testCountNodesRecursively(tree);
    TestBinaryTree::testGetHeight(tree);
    TestBinaryTree::testIsStrictlyBinary(tree);

    tree->insert(5);
    TestBinaryTree::printTree(tree);
    TestBinaryTree::testGetHeight(tree);
    TestBinaryTree::testIsStrictlyBinary(tree);

    tree->insert(20);
    TestBinaryTree::printTree(tree);
    TestBinaryTree::testGetHeight(tree);
    TestBinaryTree::testIsStrictlyBinary(tree);

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
    TestBinaryTree::testCountNodes(tree);
    TestBinaryTree::testCountNodesRecursively(tree);
    TestBinaryTree::testGetHeight(tree);
    TestBinaryTree::testIsStrictlyBinary(tree);

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

    TestBinaryTree::testCountNodes(tree);
    TestBinaryTree::testCountNodesRecursively(tree);

    TestBinaryTree::printTree(tree);
    TestBinaryTree::testCountNodes(tree);
    TestBinaryTree::testCountNodesRecursively(tree);
    TestBinaryTree::testGetHeight(tree);
    TestBinaryTree::testIsStrictlyBinary(tree);

    TestBinaryTree::testRemove(tree, 20);
    TestBinaryTree::testRemove(tree, 5);
    TestBinaryTree::testRemove(tree, 1);
    tree->insert(5);
    tree->insert(24);
    tree->insert(26);

    TestBinaryTree::printTree(tree);
    TestBinaryTree::testCountNodes(tree);
    TestBinaryTree::testCountNodesRecursively(tree);
    TestBinaryTree::testGetHeight(tree);
    TestBinaryTree::testIsStrictlyBinary(tree);

    delete tree;
}
