#include "testBinaryTreeAsArrays.hpp"

#include <print>

#include "binaryTreeAsArrays.hpp"

void TestBinaryTreeAsArrays::printTree(BinaryTreeAsArrays *tree) {
    std::println("Tree: ");
    tree->print();
    std::println();
}

void TestBinaryTreeAsArrays::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestBinaryTreeAsArrays::testContains(BinaryTreeAsArrays *tree, BinaryTreeAsArrays::Content content) {
    std::println("Contains {}?", content);
    auto result = tree->contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestBinaryTreeAsArrays::testRemove(BinaryTreeAsArrays *tree, BinaryTreeAsArrays::Content content) {
    std::println("Remove {}.", content);
    auto result = tree->remove(content);
    if (!result) {
        printError(result.error());
    } else {
        printTree(tree);
    }
    std::println();
}

void TestBinaryTreeAsArrays::test() {
    BinaryTreeAsArrays *tree = new BinaryTreeAsArrays(15);

    tree->insert(5);

    TestBinaryTreeAsArrays::printTree(tree);

    tree->insert(20);

    TestBinaryTreeAsArrays::printTree(tree);

    tree->insert(15);
    tree->insert(1);
    tree->insert(7);
    tree->insert(4);
    tree->insert(2);
    tree->insert(25);
    tree->insert(22);
    tree->insert(6);
    tree->insert(3);
    tree->insert(8);
    tree->insert(9);
    tree->insert(12);
    tree->insert(11);

    TestBinaryTreeAsArrays::printTree(tree);

    TestBinaryTreeAsArrays::testContains(tree, 10);
    TestBinaryTreeAsArrays::testContains(tree, 0);
    TestBinaryTreeAsArrays::testContains(tree, 3);
    TestBinaryTreeAsArrays::testContains(tree, 8);
    TestBinaryTreeAsArrays::testContains(tree, 11);

    TestBinaryTreeAsArrays::testRemove(tree, 3);
    TestBinaryTreeAsArrays::testContains(tree, 3);

    tree->insert(13);
    TestBinaryTreeAsArrays::printTree(tree);

    TestBinaryTreeAsArrays::testRemove(tree, 8);
    TestBinaryTreeAsArrays::testContains(tree, 8);

    TestBinaryTreeAsArrays::testRemove(tree, 10);
    TestBinaryTreeAsArrays::testContains(tree, 10);

    TestBinaryTreeAsArrays::testRemove(tree, 11);
    TestBinaryTreeAsArrays::testContains(tree, 11);

    TestBinaryTreeAsArrays::testRemove(tree, 7);
    TestBinaryTreeAsArrays::testContains(tree, 7);

    TestBinaryTreeAsArrays::testRemove(tree, 7);
    TestBinaryTreeAsArrays::testContains(tree, 7);

    TestBinaryTreeAsArrays::testRemove(tree, 20);
    TestBinaryTreeAsArrays::testRemove(tree, 5);
    TestBinaryTreeAsArrays::testRemove(tree, 1);

    tree->insert(5);
    tree->insert(24);
    tree->insert(26);

    TestBinaryTreeAsArrays::printTree(tree);

    delete tree;
}
