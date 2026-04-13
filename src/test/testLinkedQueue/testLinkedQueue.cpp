#include "testLinkedQueue.hpp"

#include <print>

#include "linkedQueue.hpp"

void TestLinkedQueue::printItem(LinkedQueueNode::Content content) {
    std::println("Item: {}", content);
}

void TestLinkedQueue::printItems(LinkedQueue &linked_queue) {
    linked_queue.print();
}

void TestLinkedQueue::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestLinkedQueue::testContains(LinkedQueue &linked_queue, LinkedQueueNode::Content content) {
    std::println("Contains {}?", content);
    auto result = linked_queue.contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestLinkedQueue::testPeek(LinkedQueue &linked_queue) {
    std::println("Peek.");
    auto result = linked_queue.peek();
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestLinkedQueue::testEnqueue(LinkedQueue &linked_queue, LinkedQueueNode::Content content) {
    std::println("Enqueue {}.", content);
    linked_queue.enqueue(content);
    printItems(linked_queue);
    std::println();
}

void TestLinkedQueue::testDequeue(LinkedQueue &linked_queue) {
    std::println("Dequeue.");
    auto result = linked_queue.dequeue();
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
        printItems(linked_queue);
    }
    std::println();
}

void TestLinkedQueue::test() {
    std::println("# TESTS: LINKED QUEUE");
    std::println();

    auto linked_queue = LinkedQueue();
    TestLinkedQueue::printItems(linked_queue);
    std::println();

    TestLinkedQueue::testContains(linked_queue, 0);

    TestLinkedQueue::testPeek(linked_queue);

    TestLinkedQueue::testDequeue(linked_queue);

    TestLinkedQueue::testEnqueue(linked_queue, 4);

    TestLinkedQueue::testContains(linked_queue, 0);

    TestLinkedQueue::testContains(linked_queue, 4);

    TestLinkedQueue::testEnqueue(linked_queue, 1);

    TestLinkedQueue::testPeek(linked_queue);

    TestLinkedQueue::testEnqueue(linked_queue, 2);

    TestLinkedQueue::testEnqueue(linked_queue, 3);

    TestLinkedQueue::testEnqueue(linked_queue, 4);

    TestLinkedQueue::testDequeue(linked_queue);

    TestLinkedQueue::testEnqueue(linked_queue, 4);

    TestLinkedQueue::testDequeue(linked_queue);

    TestLinkedQueue::testEnqueue(linked_queue, -3);

    TestLinkedQueue::testPeek(linked_queue);

    TestLinkedQueue::testContains(linked_queue, -3);

    std::println();

    std::println();
}
