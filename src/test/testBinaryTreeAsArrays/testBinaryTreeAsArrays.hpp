#ifndef __TEST_BINARY_TREE_AS_ARRAYS_HPP__
#define __TEST_BINARY_TREE_AS_ARRAYS_HPP__

#include "binaryTreeAsArrays.hpp"

class TestBinaryTreeAsArrays {
    private:
        static void testContains(BinaryTreeAsArrays *tree, BinaryTreeAsArrays::Content content);

        static void testRemove(BinaryTreeAsArrays *tree, BinaryTreeAsArrays::Content content);

        static void printTree(BinaryTreeAsArrays *tree);
        static void printError(const std::string &error);

    public:
        static void test();
};

#endif  // __TEST_BINARY_TREE_AS_ARRAYS_HPP__
