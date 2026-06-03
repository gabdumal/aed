#ifndef __TEST_AVL_TREE_BAL_HPP__
#define __TEST_AVL_TREE_BAL_HPP__

#include "avlTreeBalNode.hpp"

class TestAvlTreeBal {
    private:
        static void testContains(AvlTreeBalNode *tree, AvlTreeBalNode::Content content);

        static void testRemove(AvlTreeBalNode *tree, AvlTreeBalNode::Content content);

        static void testCountNodes(AvlTreeBalNode *tree);
        static void testCountNodesRecursively(AvlTreeBalNode *tree);

        static void testGetHeight(AvlTreeBalNode *tree);

        static void testIsStrictlyBinary(AvlTreeBalNode *tree);

        static void testIsComplete(AvlTreeBalNode *tree);

        static void printTree(AvlTreeBalNode *tree);
        static void printError(const std::string &error);

    public:
        static void test();
};

#endif  // __TEST_AVL_TREE_BAL_HPP__
