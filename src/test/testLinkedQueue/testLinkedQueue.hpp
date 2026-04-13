#ifndef __TEST_LINKED_QUEUE_HPP__
#define __TEST_LINKED_QUEUE_HPP__

#include "linkedQueue.hpp"
#include "linkedQueueNode.hpp"

class TestLinkedQueue {
    private:
        static void testContains(LinkedQueue &linked_queue, LinkedQueueNode::Content content);
        static void testDequeue(LinkedQueue &linked_queue);
        static void testEnqueue(LinkedQueue &linked_queue, LinkedQueueNode::Content content);
        static void testPeek(LinkedQueue &linked_queue);

        static void printItem(LinkedQueueNode::Content content);
        static void printItems(LinkedQueue &linked_queue);
        static void printError(const std::string &error);

    public:
        static void test();
};

#endif  // __TEST_LINKED_QUEUE_HPP__
