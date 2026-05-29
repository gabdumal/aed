#ifndef __TEST_AVL_TREE_HPP__
#define __TEST_AVL_TREE_HPP__

#include "avlTreeNode.hpp"

class TestAvlTree {
    private:
        static void testContains(AvlTreeNode *tree, AvlTreeNode::Content content);

        static void testRemove(AvlTreeNode *tree, AvlTreeNode::Content content);

        static void testCountNodes(AvlTreeNode *tree);
        static void testCountNodesRecursively(AvlTreeNode *tree);

        static void testGetHeight(AvlTreeNode *tree);

        static void testIsStrictlyBinary(AvlTreeNode *tree);

        static void testIsComplete(AvlTreeNode *tree);

        static void printTree(AvlTreeNode *tree);
        static void printError(const std::string &error);

    public:
        static void test();
};

#endif  // __TEST_AVL_TREE_HPP__
