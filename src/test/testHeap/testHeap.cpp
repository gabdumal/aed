#include "testHeap.hpp"

#include <print>

#include "heapNode.hpp"

void TestHeap::printTree(HeapNode *tree) {
    std::println("Tree: ");
    tree->print();
    std::println();
}

void TestHeap::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestHeap::testContains(HeapNode *tree, HeapNode::Content content) {
    std::println("Contains {}?", content);
    auto result = tree->contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestHeap::testRemove(HeapNode *tree, HeapNode::Content content) {
    std::println("Remove {}.", content);
    auto result = tree->remove(content);
    if (!result) {
        printError(result.error());
    } else {
        printTree(tree);
    }
    std::println();
}

void TestHeap::testPop(HeapNode *tree) {
    std::println("Pop.");
    auto result = tree->pop();
    if (!result) {
        printError(result.error());
    } else {
        std::println("{}", result.value());
    }
    std::println();
}

void TestHeap::testCountNodes(HeapNode *tree) {
    auto quantity_of_nodes = tree->countNodes();
    std::println("Quantity of nodes: {}.", quantity_of_nodes);
    std::println();
}

void TestHeap::testGetHeight(HeapNode *tree) {
    auto height = HeapNode::getHeight(tree);
    std::println("Height: {}.", height);
    std::println();
}

void TestHeap::testIsStrictlyBinary(HeapNode *tree) {
    auto is_strictly_binary = tree->isStrictlyBinary();
    std::println("Is strictly binary: {}.", is_strictly_binary);
    std::println();
}

void TestHeap::test() {
    HeapNode *tree = new HeapNode(10);

    TestHeap::printTree(tree);
    TestHeap::testCountNodes(tree);
    TestHeap::testIsStrictlyBinary(tree);

    tree->insert(5);
    TestHeap::printTree(tree);
    TestHeap::testGetHeight(tree);
    TestHeap::testIsStrictlyBinary(tree);

    tree->insert(20);
    TestHeap::printTree(tree);
    TestHeap::testGetHeight(tree);
    TestHeap::testIsStrictlyBinary(tree);

    tree->insert(15);
    tree->insert(1);
    TestHeap::printTree(tree);

    tree->insert(7);
    TestHeap::printTree(tree);

    tree->insert(4);
    TestHeap::printTree(tree);

    tree->insert(2);
    TestHeap::printTree(tree);

    tree->insert(25);
    tree->insert(22);
    TestHeap::printTree(tree);

    tree->insert(6);
    TestHeap::printTree(tree);

    tree->insert(3);
    TestHeap::printTree(tree);

    tree->insert(8);
    TestHeap::printTree(tree);

    tree->insert(9);
    TestHeap::printTree(tree);

    tree->insert(11);
    tree->insert(12);
    TestHeap::printTree(tree);
    TestHeap::testCountNodes(tree);
    TestHeap::testIsStrictlyBinary(tree);

    tree->insert(27);
    TestHeap::printTree(tree);
    TestHeap::testCountNodes(tree);
    TestHeap::testIsStrictlyBinary(tree);

    TestHeap::testContains(tree, 10);
    TestHeap::testContains(tree, 0);
    TestHeap::testContains(tree, 3);
    TestHeap::testContains(tree, 8);
    TestHeap::testContains(tree, 11);

    TestHeap::testRemove(tree, 3);
    TestHeap::testContains(tree, 3);

    TestHeap::testCountNodes(tree);
    TestHeap::testIsStrictlyBinary(tree);

    TestHeap::testRemove(tree, 6);
    TestHeap::testContains(tree, 6);

    TestHeap::testCountNodes(tree);
    TestHeap::testIsStrictlyBinary(tree);

    TestHeap::testRemove(tree, 10);
    TestHeap::testContains(tree, 10);

    TestHeap::testRemove(tree, 11);
    TestHeap::testContains(tree, 11);

    TestHeap::testRemove(tree, 7);
    TestHeap::testContains(tree, 7);

    TestHeap::testRemove(tree, 7);
    TestHeap::testContains(tree, 7);

    TestHeap::testCountNodes(tree);
    TestHeap::testIsStrictlyBinary(tree);

    TestHeap::testRemove(tree, 20);
    TestHeap::testRemove(tree, 5);
    TestHeap::testRemove(tree, 1);

    TestHeap::testCountNodes(tree);
    TestHeap::testIsStrictlyBinary(tree);

    tree->insert(5);
    tree->insert(24);
    tree->insert(26);
    tree->insert(30);

    TestHeap::printTree(tree);
    TestHeap::testCountNodes(tree);
    TestHeap::testIsStrictlyBinary(tree);

    TestHeap::testPop(tree);
    TestHeap::printTree(tree);

    TestHeap::testPop(tree);
    TestHeap::printTree(tree);

    TestHeap::testPop(tree);
    TestHeap::printTree(tree);

    TestHeap::testPop(tree);
    TestHeap::printTree(tree);

    TestHeap::testPop(tree);
    TestHeap::printTree(tree);

    delete tree;
}
