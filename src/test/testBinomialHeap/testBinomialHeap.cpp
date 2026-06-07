#include "testBinomialHeap.hpp"

#include <print>

#include "binomialHeapNode.hpp"

void TestBinomialHeap::printHeap(BinomialHeapNode *node) {
    std::println("Heap: ");
    node->print();
    std::println();
}

BinomialHeapNode *TestBinomialHeap::testAdd(BinomialHeapNode *first_heap, BinomialHeapNode *second_heap) {
    std::println("Add.");
    auto new_heap = BinomialHeapNode::add(first_heap, second_heap);
    printHeap(new_heap);
    return new_heap;
}

BinomialHeapNode *TestBinomialHeap::testUnite(BinomialHeapNode *first_heap, BinomialHeapNode *second_heap) {
    std::println("Unite.");
    auto new_heap = BinomialHeapNode::unite(first_heap, second_heap);
    printHeap(new_heap);
    return new_heap;
}

void TestBinomialHeap::testFront(BinomialHeapNode *node) {
    std::println("Front: {}.", node->front());
    std::println();
}

void TestBinomialHeap::testPop(BinomialHeapNode *node) {
    std::println("Pop: {}.", node->pop());
    std::println();
}

void TestBinomialHeap::testCountNodes(BinomialHeapNode *node) {
    auto quantity_of_nodes = node->countNodes();
    std::println("Quantity of nodes: {}.", quantity_of_nodes);
    std::println();
}

void TestBinomialHeap::testWithAddAndUnite() {
    BinomialHeapNode *first_heap = testAdd(new BinomialHeapNode(10), new BinomialHeapNode(20));

    BinomialHeapNode *second_heap = BinomialHeapNode::add(new BinomialHeapNode(5), new BinomialHeapNode(40));
    first_heap = testAdd(first_heap, second_heap);

    second_heap = BinomialHeapNode::add(new BinomialHeapNode(14), new BinomialHeapNode(7));
    second_heap = BinomialHeapNode::add(second_heap, BinomialHeapNode::add(new BinomialHeapNode(6), new BinomialHeapNode(25)));
    first_heap = testAdd(first_heap, second_heap);

    second_heap = testAdd(
        BinomialHeapNode::add(new BinomialHeapNode(23), new BinomialHeapNode(9)),
        BinomialHeapNode::add(new BinomialHeapNode(11), new BinomialHeapNode(32)));

    first_heap = testUnite(first_heap, second_heap);

    delete first_heap;
}

void TestBinomialHeap::test() {
    testWithAddAndUnite();

    // BinomialHeapNode *node = new BinomialHeapNode(10);

    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testCountNodes(node);
    // TestBinomialHeap::testFront(node);

    // node->insert(5);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // node->insert(20);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // node->insert(15);
    // node->insert(1);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // node->insert(7);
    // TestBinomialHeap::printHeap(node);

    // node->insert(4);
    // TestBinomialHeap::printHeap(node);

    // node->insert(2);
    // TestBinomialHeap::printHeap(node);

    // node->insert(25);
    // node->insert(22);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // node->insert(6);
    // TestBinomialHeap::printHeap(node);

    // node->insert(3);
    // TestBinomialHeap::printHeap(node);

    // node->insert(8);
    // TestBinomialHeap::printHeap(node);

    // node->insert(9);
    // TestBinomialHeap::printHeap(node);

    // node->insert(11);
    // node->insert(12);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testCountNodes(node);

    // node->insert(27);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);
    // TestBinomialHeap::testCountNodes(node);

    // TestBinomialHeap::testPop(node);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // TestBinomialHeap::testPop(node);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // TestBinomialHeap::testPop(node);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // TestBinomialHeap::testPop(node);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // node->insert(5);
    // node->insert(24);
    // node->insert(26);
    // node->insert(30);

    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);
    // TestBinomialHeap::testCountNodes(node);

    // TestBinomialHeap::testPop(node);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // TestBinomialHeap::testPop(node);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // TestBinomialHeap::testPop(node);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // TestBinomialHeap::testPop(node);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // TestBinomialHeap::testPop(node);
    // TestBinomialHeap::printHeap(node);
    // TestBinomialHeap::testFront(node);

    // delete node;
}
