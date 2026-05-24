#include "testBinaryTree.hpp"

void TestBinaryTree::test() {
    BinaryTreeNode *tree = new BinaryTreeNode(10);
    tree->insert(5);
    tree->insert(20);
    tree->insert(15);
    tree->insert(1);
    tree->insert(7);
    tree->insert(4);
    tree->insert(2);
    tree->insert(25);
    tree->insert(22);
    tree->insert(6);

    tree->print();
}
