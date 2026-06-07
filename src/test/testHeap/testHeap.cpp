#include "testHeap.hpp"

#include <print>

#include "heapNode.hpp"

void TestHeap::printHeap(HeapNode *node) {
    std::println("Heap: ");
    node->print();
    std::println();
}

void TestHeap::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestHeap::testContains(HeapNode *node, HeapNode::Content content) {
    std::println("Contains {}?", content);
    auto result = node->contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestHeap::testRemove(HeapNode *node, HeapNode::Content content) {
    std::println("Remove {}.", content);
    auto result = node->remove(content);
    if (!result) {
        printError(result.error());
    } else {
        printHeap(node);
    }
    std::println();
}

void TestHeap::testPop(HeapNode *node) {
    std::println("Pop.");
    auto result = node->pop();
    if (!result) {
        printError(result.error());
    } else {
        std::println("{}", result.value());
    }
    std::println();
}

void TestHeap::testCountNodes(HeapNode *node) {
    auto quantity_of_nodes = node->countNodes();
    std::println("Quantity of nodes: {}.", quantity_of_nodes);
    std::println();
}

void TestHeap::testGetHeight(HeapNode *node) {
    auto height = HeapNode::getHeight(node);
    std::println("Height: {}.", height);
    std::println();
}

void TestHeap::testIsStrictlyBinary(HeapNode *node) {
    auto is_strictly_binary = node->isStrictlyBinary();
    std::println("Is strictly binary: {}.", is_strictly_binary);
    std::println();
}

void TestHeap::test() {
    HeapNode *node = new HeapNode(10);

    TestHeap::printHeap(node);
    TestHeap::testCountNodes(node);
    TestHeap::testIsStrictlyBinary(node);

    node->insert(5);
    TestHeap::printHeap(node);
    TestHeap::testGetHeight(node);
    TestHeap::testIsStrictlyBinary(node);

    node->insert(20);
    TestHeap::printHeap(node);
    TestHeap::testGetHeight(node);
    TestHeap::testIsStrictlyBinary(node);

    node->insert(15);
    node->insert(1);
    TestHeap::printHeap(node);

    node->insert(7);
    TestHeap::printHeap(node);

    node->insert(4);
    TestHeap::printHeap(node);

    node->insert(2);
    TestHeap::printHeap(node);

    node->insert(25);
    node->insert(22);
    TestHeap::printHeap(node);

    node->insert(6);
    TestHeap::printHeap(node);

    node->insert(3);
    TestHeap::printHeap(node);

    node->insert(8);
    TestHeap::printHeap(node);

    node->insert(9);
    TestHeap::printHeap(node);

    node->insert(11);
    node->insert(12);
    TestHeap::printHeap(node);
    TestHeap::testCountNodes(node);
    TestHeap::testIsStrictlyBinary(node);

    node->insert(27);
    TestHeap::printHeap(node);
    TestHeap::testCountNodes(node);
    TestHeap::testIsStrictlyBinary(node);

    TestHeap::testContains(node, 10);
    TestHeap::testContains(node, 0);
    TestHeap::testContains(node, 3);
    TestHeap::testContains(node, 8);
    TestHeap::testContains(node, 11);

    TestHeap::testRemove(node, 3);
    TestHeap::testContains(node, 3);

    TestHeap::testCountNodes(node);
    TestHeap::testIsStrictlyBinary(node);

    TestHeap::testRemove(node, 6);
    TestHeap::testContains(node, 6);

    TestHeap::testCountNodes(node);
    TestHeap::testIsStrictlyBinary(node);

    TestHeap::testRemove(node, 10);
    TestHeap::testContains(node, 10);

    TestHeap::testRemove(node, 11);
    TestHeap::testContains(node, 11);

    TestHeap::testRemove(node, 7);
    TestHeap::testContains(node, 7);

    TestHeap::testRemove(node, 7);
    TestHeap::testContains(node, 7);

    TestHeap::testCountNodes(node);
    TestHeap::testIsStrictlyBinary(node);

    TestHeap::testRemove(node, 20);
    TestHeap::testRemove(node, 5);
    TestHeap::testRemove(node, 1);

    TestHeap::testCountNodes(node);
    TestHeap::testIsStrictlyBinary(node);

    node->insert(5);
    node->insert(24);
    node->insert(26);
    node->insert(30);

    TestHeap::printHeap(node);
    TestHeap::testCountNodes(node);
    TestHeap::testIsStrictlyBinary(node);

    TestHeap::testPop(node);
    TestHeap::printHeap(node);

    TestHeap::testPop(node);
    TestHeap::printHeap(node);

    TestHeap::testPop(node);
    TestHeap::printHeap(node);

    TestHeap::testPop(node);
    TestHeap::printHeap(node);

    TestHeap::testPop(node);
    TestHeap::printHeap(node);

    delete node;
}
