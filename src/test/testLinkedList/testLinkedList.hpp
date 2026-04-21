#ifndef __TEST_LINKED_LIST_HPP__
#define __TEST_LINKED_LIST_HPP__

#include "linkedList.hpp"

class TestLinkedList {
    private:
        static void testContains(LinkedList &linked_list, LinkedListNode::Content content);

        static void testInsert(LinkedList &linked_list, int index, LinkedListNode::Content content);
        static void testInsertAtBegin(LinkedList &linked_list, LinkedListNode::Content content);
        static void testInsertAtEnd(LinkedList &linked_list, LinkedListNode::Content content);

        static void testRemove(LinkedList &linked_list, int index);
        static void testRemoveAtBegin(LinkedList &linked_list);
        static void testRemoveAtEnd(LinkedList &linked_list);

        static void testGetContent(LinkedList &linked_list, int index);
        static void testGetContentAtBegin(LinkedList &linked_list);
        static void testGetContentAtEnd(LinkedList &linked_list);

        static void printItem(LinkedListNode::Content content);
        static void printItems(LinkedList &linked_list);
        static void printError(const std::string &error);

    public:
        static void test();
};

#endif  // __TEST_LINKED_LIST_HPP__
