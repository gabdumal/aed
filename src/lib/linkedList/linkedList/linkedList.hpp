#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <expected>
#include <string>

#include "linkedListNode.hpp"

class LinkedList {
    private:
        LinkedListNode *first_node;

        static std::string getMessageForNegativeIndex();
        static std::string getMessageForIndexNotWithinNorImmediatelyAfter(int maximum);
        static std::string getMessageForEmptyList();

        LinkedListNode *getLastNode();

    public:
        LinkedList();

        ~LinkedList();

        int getLength();

        bool isEmpty();
        bool contains(LinkedListNode::Content content);

        std::expected<void, std::string> insert(int index, LinkedListNode::Content content);
        std::expected<void, std::string> insertAtBegin(LinkedListNode::Content content);
        std::expected<void, std::string> insertAtEnd(LinkedListNode::Content content);

        std::expected<LinkedListNode::Content, std::string> remove(int index);
        std::expected<LinkedListNode::Content, std::string> removeAtBegin();
        std::expected<LinkedListNode::Content, std::string> removeAtEnd();

        std::expected<LinkedListNode::Content, std::string> getContent(int index);
        std::expected<LinkedListNode::Content, std::string> getContentAtBegin();
        std::expected<LinkedListNode::Content, std::string> getContentAtEnd();

        void print();
};

#endif  // __LINKED_LIST_HPP__
