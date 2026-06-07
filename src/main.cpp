#include <cstdlib>
#include <iostream>

#include "codedLeaves.hpp"
#include "discoverAddends.hpp"
#include "testAvlTree.hpp"
#include "testAvlTreeBal.hpp"
#include "testBinaryTree.hpp"
#include "testBinaryTreeAsArrays.hpp"
#include "testBinomialHeap.hpp"
#include "testContiguousList.hpp"
#include "testExternalHash.hpp"
#include "testHeap.hpp"
#include "testLinkedList.hpp"
#include "testLinkedQueue.hpp"
#include "testLinkedStack.hpp"
#include "testOpenAddressingHash.hpp"

int main(int argc, char *argv[]) {
    std::string algorithm_to_run;

    if (argc >= 2) {
        algorithm_to_run = argv[1];
    } else {
        const char *env_algorithm = std::getenv("ALGORITHM_TO_RUN");
        if (env_algorithm) {
            algorithm_to_run = env_algorithm;
        } else {
            std::cerr << "Usage: " << argv[0] << " <AlgorithmName>" << std::endl;
            std::cerr << "Or set ALGORITHM_TO_RUN environment variable" << std::endl;
            return 1;
        }
    }

    if (algorithm_to_run == "TestContiguousList") {
        TestContiguousList::test();
    } else if (algorithm_to_run == "TestLinkedList") {
        TestLinkedList::test();
    } else if (algorithm_to_run == "TestLinkedQueue") {
        TestLinkedQueue::test();
    } else if (algorithm_to_run == "TestLinkedStack") {
        TestLinkedStack::test();
    } else if (algorithm_to_run == "TestOpenAddressingHash") {
        TestOpenAddressingHash::test();
    } else if (algorithm_to_run == "TestExternalHash") {
        TestExternalHash::test();
    } else if (algorithm_to_run == "TestBinaryTree") {
        TestBinaryTree::test();
    } else if (algorithm_to_run == "DiscoverAddends") {
        DiscoverAddends::main();
    } else if (algorithm_to_run == "CodedLeaves") {
        CodedLeaves::main();
    } else if (algorithm_to_run == "TestBinaryTreeAsArrays") {
        TestBinaryTreeAsArrays::test();
    } else if (algorithm_to_run == "TestAvlTree") {
        TestAvlTree::test();
    } else if (algorithm_to_run == "TestAvlTreeBal") {
        TestAvlTreeBal::test();
    } else if (algorithm_to_run == "TestHeap") {
        TestHeap::test();
    } else if (algorithm_to_run == "TestBinomialHeap") {
        TestBinomialHeap::test();
    } else {
        std::cerr << "Unknown algorithm: " << algorithm_to_run << "." << std::endl;
        return 1;
    }

    return 0;
}
