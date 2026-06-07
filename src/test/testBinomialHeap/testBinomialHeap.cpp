#include "testBinomialHeap.hpp"

#include <print>

#include "binomialHeapNode.hpp"

void TestBinomialHeap::printHeap(BinomialHeapNode *node) {
    std::println("Heap: ");
    node->print();
    std::println();
}

void TestBinomialHeap::testFront(BinomialHeapNode *node) {
    std::println("Front: {}.", node->front());
    std::println();
}

void TestBinomialHeap::testPop(BinomialHeapNode *node) {
    std::println("Pop: {}.", node->pop());
    std::println();
}

void TestBinomialHeap::testGetOrder(BinomialHeapNode *node) {
    std::println("Order: {}.", node->getOrder());
    std::println();
}

void TestBinomialHeap::testCountNodes(BinomialHeapNode *node) {
    auto quantity_of_nodes = node->countNodes();
    std::println("Quantity of nodes: {}.", quantity_of_nodes);
    std::println();
}

void TestBinomialHeap::test() {
    BinomialHeapNode *node = new BinomialHeapNode(10);

    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testCountNodes(node);
    TestBinomialHeap::testFront(node);

    node->insert(5);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);
    TestBinomialHeap::testGetOrder(node);

    node->insert(20);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);
    TestBinomialHeap::testGetOrder(node);

    node->insert(15);
    node->insert(1);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    node->insert(7);
    TestBinomialHeap::printHeap(node);

    node->insert(4);
    TestBinomialHeap::printHeap(node);

    node->insert(2);
    TestBinomialHeap::printHeap(node);

    node->insert(25);
    node->insert(22);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    node->insert(6);
    TestBinomialHeap::printHeap(node);

    node->insert(3);
    TestBinomialHeap::printHeap(node);

    node->insert(8);
    TestBinomialHeap::printHeap(node);

    node->insert(9);
    TestBinomialHeap::printHeap(node);

    node->insert(11);
    node->insert(12);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testCountNodes(node);

    node->insert(27);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);
    TestBinomialHeap::testCountNodes(node);

    TestBinomialHeap::testPop(node);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    TestBinomialHeap::testPop(node);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    TestBinomialHeap::testPop(node);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    TestBinomialHeap::testPop(node);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    node->insert(5);
    node->insert(24);
    node->insert(26);
    node->insert(30);

    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);
    TestBinomialHeap::testCountNodes(node);

    TestBinomialHeap::testPop(node);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    TestBinomialHeap::testPop(node);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    TestBinomialHeap::testPop(node);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    TestBinomialHeap::testPop(node);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    TestBinomialHeap::testPop(node);
    TestBinomialHeap::printHeap(node);
    TestBinomialHeap::testFront(node);

    delete node;
}
