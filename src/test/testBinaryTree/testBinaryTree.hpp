#ifndef __TEST_BINARY_TREE_HPP__
#define __TEST_BINARY_TREE_HPP__

#include "binaryTreeNode.hpp"

class TestBinaryTree {
    private:
        static void testContains(BinaryTreeNode &tree, BinaryTreeNode::Content content);

        static void testInsert(BinaryTreeNode &tree, BinaryTreeNode::Content content);

        static void testRemove(BinaryTreeNode &tree, BinaryTreeNode::Content content);

        static void printItems(BinaryTreeNode &tree);
        static void printError(const std::string &error);

    public:
        static void test();
};

#endif  // __TEST_BINARY_TREE_HPP__
