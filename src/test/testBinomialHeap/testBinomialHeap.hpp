#ifndef __TEST_BINOMIAL_HEAP_HPP__
#define __TEST_BINOMIAL_HEAP_HPP__

#include "binomialHeapNode.hpp"

class TestBinomialHeap {
    private:
        static BinomialHeapNode *testInsert(BinomialHeapNode *node, BinomialHeapNode::Content);
        static void testFront(BinomialHeapNode *node);
        static BinomialHeapNode *testPop(BinomialHeapNode *node);

        static BinomialHeapNode *testAdd(BinomialHeapNode *first_heap, BinomialHeapNode *second_heap);
        static BinomialHeapNode *testUnite(BinomialHeapNode *first_heap, BinomialHeapNode *second_heap);

        static void testCountNodes(BinomialHeapNode *node);
        static void testChangeContent(BinomialHeapNode *node, BinomialHeapNode::Content);

        static void printHeap(BinomialHeapNode *node);

        static void testWithAddAndUnite();

    public:
        static void test();
};

#endif  // __TEST_BINOMIAL_HEAP_HPP__
