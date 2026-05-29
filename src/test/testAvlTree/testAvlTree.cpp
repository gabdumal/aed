#include "testAvlTree.hpp"

#include <print>

#include "avlTreeNode.hpp"

void TestAvlTree::printTree(AvlTreeNode *tree) {
    std::println("Tree: ");
    tree->print();
    std::println();
}

void TestAvlTree::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestAvlTree::testContains(AvlTreeNode *tree, AvlTreeNode::Content content) {
    std::println("Contains {}?", content);
    auto result = tree->contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestAvlTree::testRemove(AvlTreeNode *tree, AvlTreeNode::Content content) {
    std::println("Remove {}.", content);
    auto result = tree->remove(content);
    if (!result) {
        printError(result.error());
    } else {
        printTree(tree);
    }
    std::println();
}

void TestAvlTree::testCountNodes(AvlTreeNode *tree) {
    auto quantity_of_nodes = tree->countNodes();
    std::println("Quantity of nodes: {}.", quantity_of_nodes);
    std::println();
}

void TestAvlTree::testCountNodesRecursively(AvlTreeNode *tree) {
    auto quantity_of_nodes = tree->countNodesRecursively();
    std::println("Quantity of nodes (recursive): {}.", quantity_of_nodes);
    std::println();
}

void TestAvlTree::testGetHeight(AvlTreeNode *tree) {
    auto height = tree->getHeight();
    std::println("Height: {}.", height);
    std::println();
}

void TestAvlTree::testIsStrictlyBinary(AvlTreeNode *tree) {
    auto is_strictly_binary = tree->isStrictlyBinary();
    std::println("Is strictly binary: {}.", is_strictly_binary);
    std::println();
}

void TestAvlTree::testIsComplete(AvlTreeNode *tree) {
    auto is_complete = tree->isComplete();
    std::println("Is complete: {}.", is_complete);
    std::println();
}

void TestAvlTree::test() {
    AvlTreeNode *tree = new AvlTreeNode(10);

    TestAvlTree::testCountNodes(tree);
    TestAvlTree::testCountNodesRecursively(tree);
    TestAvlTree::testGetHeight(tree);
    TestAvlTree::testIsStrictlyBinary(tree);
    TestAvlTree::testIsComplete(tree);

    tree->insert(5);
    TestAvlTree::printTree(tree);
    TestAvlTree::testGetHeight(tree);
    TestAvlTree::testIsStrictlyBinary(tree);
    TestAvlTree::testIsComplete(tree);

    tree->insert(20);
    TestAvlTree::printTree(tree);
    TestAvlTree::testGetHeight(tree);
    TestAvlTree::testIsStrictlyBinary(tree);
    TestAvlTree::testIsComplete(tree);

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

    TestAvlTree::printTree(tree);
    TestAvlTree::testCountNodes(tree);
    TestAvlTree::testCountNodesRecursively(tree);
    TestAvlTree::testGetHeight(tree);
    TestAvlTree::testIsStrictlyBinary(tree);
    TestAvlTree::testIsComplete(tree);

    TestAvlTree::testContains(tree, 10);
    TestAvlTree::testContains(tree, 0);
    TestAvlTree::testContains(tree, 3);
    TestAvlTree::testContains(tree, 8);
    TestAvlTree::testContains(tree, 11);

    TestAvlTree::testRemove(tree, 3);
    TestAvlTree::testContains(tree, 3);

    TestAvlTree::testRemove(tree, 8);
    TestAvlTree::testContains(tree, 8);

    TestAvlTree::testRemove(tree, 10);
    TestAvlTree::testContains(tree, 10);

    TestAvlTree::testRemove(tree, 11);
    TestAvlTree::testContains(tree, 11);

    TestAvlTree::testRemove(tree, 7);
    TestAvlTree::testContains(tree, 7);

    TestAvlTree::testRemove(tree, 7);
    TestAvlTree::testContains(tree, 7);

    TestAvlTree::printTree(tree);
    TestAvlTree::testCountNodes(tree);
    TestAvlTree::testCountNodesRecursively(tree);
    TestAvlTree::testGetHeight(tree);
    TestAvlTree::testIsStrictlyBinary(tree);
    TestAvlTree::testIsComplete(tree);

    TestAvlTree::testRemove(tree, 20);
    TestAvlTree::testRemove(tree, 5);
    TestAvlTree::testRemove(tree, 1);

    TestAvlTree::testCountNodes(tree);
    TestAvlTree::testCountNodesRecursively(tree);
    TestAvlTree::testGetHeight(tree);
    TestAvlTree::testIsStrictlyBinary(tree);
    TestAvlTree::testIsComplete(tree);

    tree->insert(5);
    tree->insert(24);
    tree->insert(26);

    TestAvlTree::printTree(tree);
    TestAvlTree::testCountNodes(tree);
    TestAvlTree::testCountNodesRecursively(tree);
    TestAvlTree::testGetHeight(tree);
    TestAvlTree::testIsStrictlyBinary(tree);
    TestAvlTree::testIsComplete(tree);

    delete tree;
}
