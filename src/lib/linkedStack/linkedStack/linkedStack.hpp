#ifndef __LINKED_STACK_HPP__
#define __LINKED_STACK_HPP__

#include <expected>
#include <string>

#include "linkedStackNode.hpp"

class LinkedStack {
    private:
        LinkedStackNode *top_node;

        static std::string getMessageForEmptyStack();

    public:
        LinkedStack();

        ~LinkedStack();

        bool contains(LinkedStackNode::Content content);
        bool isEmpty();

        std::expected<LinkedStackNode::Content, std::string> pop();
        std::expected<LinkedStackNode::Content, std::string> peek();
        void push(LinkedStackNode::Content content);

        void print();
};

#endif  // __LINKED_STACK_HPP__
