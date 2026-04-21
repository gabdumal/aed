#ifndef __LINKED_QUEUE_HPP__
#define __LINKED_QUEUE_HPP__

#include <expected>
#include <string>

#include "linkedQueueNode.hpp"

class LinkedQueue {
    private:
        LinkedQueueNode *head_node;
        LinkedQueueNode *tail_node;

        static std::string getMessageForEmptyQueue();

    public:
        LinkedQueue();

        ~LinkedQueue();

        bool contains(LinkedQueueNode::Content content);
        bool isEmpty();

        std::expected<LinkedQueueNode::Content, std::string> dequeue();
        std::expected<LinkedQueueNode::Content, std::string> peek();
        void enqueue(LinkedQueueNode::Content content);

        void print();
};

#endif  // __LINKED_QUEUE_HPP__
