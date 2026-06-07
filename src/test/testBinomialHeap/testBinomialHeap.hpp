#ifndef __TEST_BINOMIAL_HEAP_HPP__
#define __TEST_BINOMIAL_HEAP_HPP__

#include "binomialHeapNode.hpp"

class TestBinomialHeap {
    private:
        static void testInsert(BinomialHeapNode *node, BinomialHeapNode::Content content);
        static void testFront(BinomialHeapNode *node);
        static void testPop(BinomialHeapNode *node);

        static BinomialHeapNode *testAdd(BinomialHeapNode *first_heap, BinomialHeapNode *second_heap);

        static void testCountNodes(BinomialHeapNode *node);

        static void printHeap(BinomialHeapNode *node);

        static void testWithAdd();

    public:
        static void test();
};

#endif  // __TEST_BINOMIAL_HEAP_HPP__
