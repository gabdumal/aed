#include "testLinkedStack.hpp"

#include <print>

#include "linkedStack.hpp"

void TestLinkedStack::printItem(LinkedStackNode::Content content) {
    std::println("Item: {}", content);
}

void TestLinkedStack::printItems(LinkedStack &linked_stack) {
    linked_stack.print();
}

void TestLinkedStack::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestLinkedStack::testContains(LinkedStack &linked_stack, LinkedStackNode::Content content) {
    std::println("Contains {}?", content);
    auto result = linked_stack.contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestLinkedStack::testPeek(LinkedStack &linked_stack) {
    std::println("Peek.");
    auto result = linked_stack.peek();
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestLinkedStack::testPush(LinkedStack &linked_stack, LinkedStackNode::Content content) {
    std::println("Push {}.", content);
    linked_stack.push(content);
    printItems(linked_stack);
    std::println();
}

void TestLinkedStack::testPop(LinkedStack &linked_stack) {
    std::println("Pop.");
    auto result = linked_stack.pop();
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
        printItems(linked_stack);
    }
    std::println();
}

void TestLinkedStack::test() {
    std::println("# TESTS: LINKED STACK");
    std::println();

    auto linked_stack = LinkedStack();
    TestLinkedStack::printItems(linked_stack);
    std::println();

    TestLinkedStack::testContains(linked_stack, 0);

    TestLinkedStack::testPeek(linked_stack);

    TestLinkedStack::testPop(linked_stack);

    TestLinkedStack::testPush(linked_stack, 4);

    TestLinkedStack::testContains(linked_stack, 0);

    TestLinkedStack::testContains(linked_stack, 4);

    TestLinkedStack::testPush(linked_stack, 1);

    TestLinkedStack::testPeek(linked_stack);

    TestLinkedStack::testPush(linked_stack, 2);

    TestLinkedStack::testPush(linked_stack, 3);

    TestLinkedStack::testPush(linked_stack, 4);

    TestLinkedStack::testPop(linked_stack);

    TestLinkedStack::testPush(linked_stack, 4);

    TestLinkedStack::testPop(linked_stack);

    TestLinkedStack::testPush(linked_stack, -3);

    TestLinkedStack::testPeek(linked_stack);

    TestLinkedStack::testContains(linked_stack, -3);

    std::println();

    std::println();
}
