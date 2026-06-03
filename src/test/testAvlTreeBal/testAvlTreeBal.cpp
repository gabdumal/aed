#include "testAvlTreeBal.hpp"

#include <print>

#include "avlTreeBalNode.hpp"

void TestAvlTreeBal::printTree(AvlTreeBalNode *tree) {
    std::println("Tree: ");
    tree->print();
    std::println();
}

void TestAvlTreeBal::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestAvlTreeBal::testContains(AvlTreeBalNode *tree, AvlTreeBalNode::Content content) {
    std::println("Contains {}?", content);
    auto result = tree->contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestAvlTreeBal::testRemove(AvlTreeBalNode *tree, AvlTreeBalNode::Content content) {
    std::println("Remove {}.", content);
    auto result = tree->remove(content);
    if (!result) {
        printError(result.error());
    } else {
        printTree(tree);
    }
    std::println();
}

void TestAvlTreeBal::testCountNodes(AvlTreeBalNode *tree) {
    auto quantity_of_nodes = tree->countNodes();
    std::println("Quantity of nodes: {}.", quantity_of_nodes);
    std::println();
}

void TestAvlTreeBal::testCountNodesRecursively(AvlTreeBalNode *tree) {
    auto quantity_of_nodes = tree->countNodesRecursively();
    std::println("Quantity of nodes (recursive): {}.", quantity_of_nodes);
    std::println();
}

void TestAvlTreeBal::testGetHeight(AvlTreeBalNode *tree) {
    auto height = AvlTreeBalNode::getHeight(tree);
    std::println("Height: {}.", height);
    std::println();
}

void TestAvlTreeBal::testIsStrictlyBinary(AvlTreeBalNode *tree) {
    auto is_strictly_binary = tree->isStrictlyBinary();
    std::println("Is strictly binary: {}.", is_strictly_binary);
    std::println();
}

void TestAvlTreeBal::testIsComplete(AvlTreeBalNode *tree) {
    auto is_complete = tree->isComplete();
    std::println("Is complete: {}.", is_complete);
    std::println();
}

void TestAvlTreeBal::test() {
    AvlTreeBalNode *tree = new AvlTreeBalNode(10);

    TestAvlTreeBal::printTree(tree);
    TestAvlTreeBal::testCountNodes(tree);
    TestAvlTreeBal::testCountNodesRecursively(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    tree->insert(5);
    TestAvlTreeBal::printTree(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    tree->insert(20);
    TestAvlTreeBal::printTree(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    tree->insert(15);
    tree->insert(1);
    TestAvlTreeBal::printTree(tree);

    tree->insert(7);
    TestAvlTreeBal::printTree(tree);

    tree->insert(4);
    TestAvlTreeBal::printTree(tree);

    tree->insert(2);
    TestAvlTreeBal::printTree(tree);

    tree->insert(25);
    tree->insert(22);
    TestAvlTreeBal::printTree(tree);

    tree->insert(6);
    TestAvlTreeBal::printTree(tree);

    tree->insert(3);
    TestAvlTreeBal::printTree(tree);

    tree->insert(8);
    TestAvlTreeBal::printTree(tree);

    tree->insert(9);
    TestAvlTreeBal::printTree(tree);

    tree->insert(11);
    tree->insert(12);
    TestAvlTreeBal::printTree(tree);
    TestAvlTreeBal::testCountNodes(tree);
    TestAvlTreeBal::testCountNodesRecursively(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    tree->insert(27);
    TestAvlTreeBal::printTree(tree);
    TestAvlTreeBal::testCountNodes(tree);
    TestAvlTreeBal::testCountNodesRecursively(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    TestAvlTreeBal::testContains(tree, 10);
    TestAvlTreeBal::testContains(tree, 0);
    TestAvlTreeBal::testContains(tree, 3);
    TestAvlTreeBal::testContains(tree, 8);
    TestAvlTreeBal::testContains(tree, 11);

    TestAvlTreeBal::testRemove(tree, 3);
    TestAvlTreeBal::testContains(tree, 3);

    TestAvlTreeBal::testCountNodes(tree);
    TestAvlTreeBal::testCountNodesRecursively(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    TestAvlTreeBal::testRemove(tree, 6);
    TestAvlTreeBal::testContains(tree, 6);

    TestAvlTreeBal::testCountNodes(tree);
    TestAvlTreeBal::testCountNodesRecursively(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    TestAvlTreeBal::testRemove(tree, 10);
    TestAvlTreeBal::testContains(tree, 10);

    TestAvlTreeBal::testRemove(tree, 11);
    TestAvlTreeBal::testContains(tree, 11);

    TestAvlTreeBal::testRemove(tree, 7);
    TestAvlTreeBal::testContains(tree, 7);

    TestAvlTreeBal::testRemove(tree, 7);
    TestAvlTreeBal::testContains(tree, 7);

    TestAvlTreeBal::testCountNodes(tree);
    TestAvlTreeBal::testCountNodesRecursively(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    TestAvlTreeBal::testRemove(tree, 20);
    TestAvlTreeBal::testRemove(tree, 5);
    TestAvlTreeBal::testRemove(tree, 1);

    TestAvlTreeBal::testCountNodes(tree);
    TestAvlTreeBal::testCountNodesRecursively(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    tree->insert(5);
    tree->insert(24);
    tree->insert(26);
    tree->insert(30);

    TestAvlTreeBal::printTree(tree);
    TestAvlTreeBal::testCountNodes(tree);
    TestAvlTreeBal::testCountNodesRecursively(tree);
    TestAvlTreeBal::testGetHeight(tree);
    TestAvlTreeBal::testIsStrictlyBinary(tree);
    TestAvlTreeBal::testIsComplete(tree);

    delete tree;
}
