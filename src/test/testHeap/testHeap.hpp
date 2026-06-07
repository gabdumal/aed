#ifndef __TEST_HEAP_HPP__
#define __TEST_HEAP_HPP__

#include "heapNode.hpp"

class TestHeap {
    private:
        static void testContains(HeapNode *node, HeapNode::Content content);

        static void testRemove(HeapNode *node, HeapNode::Content content);

        static void testPop(HeapNode *node);

        static void testCountNodes(HeapNode *node);

        static void testGetHeight(HeapNode *node);

        static void testIsStrictlyBinary(HeapNode *node);

        static void printHeap(HeapNode *node);
        static void printError(const std::string &error);

    public:
        static void test();
};

#endif  // __TEST_HEAP_HPP__
