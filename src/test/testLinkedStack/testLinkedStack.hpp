#ifndef __TEST_LINKED_STACK_HPP__
#define __TEST_LINKED_STACK_HPP__

#include "linkedStack.hpp"
#include "linkedStackNode.hpp"

class TestLinkedStack {
    private:
        static void testContains(LinkedStack &linked_stack, LinkedStackNode::Content content);
        static void testPop(LinkedStack &linked_stack);
        static void testPush(LinkedStack &linked_stack, LinkedStackNode::Content content);
        static void testPeek(LinkedStack &linked_stack);

        static void printItem(LinkedStackNode::Content content);
        static void printItems(LinkedStack &linked_stack);
        static void printError(const std::string &error);

    public:
        static void test();
};

#endif  // __TEST_LINKED_STACK_HPP__
