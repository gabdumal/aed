#ifndef __TEST_HEAP_HPP__
#define __TEST_HEAP_HPP__

#include "heapNode.hpp"

class TestHeap {
    private:
        static void testContains(HeapNode *tree, HeapNode::Content content);

        static void testRemove(HeapNode *tree, HeapNode::Content content);

        static void testCountNodes(HeapNode *tree);
        static void testCountNodesRecursively(HeapNode *tree);

        static void testGetHeight(HeapNode *tree);

        static void testIsStrictlyBinary(HeapNode *tree);

        static void testIsComplete(HeapNode *tree);

        static void printTree(HeapNode *tree);
        static void printError(const std::string &error);

    public:
        static void test();
};

#endif  // __TEST_HEAP_HPP__
