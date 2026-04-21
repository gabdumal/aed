#include "testLinkedList.hpp"

#include <print>

#include "linkedList.hpp"

void TestLinkedList::printItem(LinkedListNode::Content content) {
    std::println("Item: {}", content);
}

void TestLinkedList::printItems(LinkedList &linked_list) {
    std::print("Items: ");
    linked_list.print();
}

void TestLinkedList::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestLinkedList::testContains(LinkedList &linked_list, LinkedListNode::Content content) {
    std::println("Contains {}?", content);
    auto result = linked_list.contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestLinkedList::testInsert(LinkedList &linked_list, int index, LinkedListNode::Content content) {
    std::println("Insert {} at {}.", content, index);
    auto result = linked_list.insert(index, content);
    if (!result) {
        printError(result.error());
    } else {
        printItems(linked_list);
    }
    std::println();
}

void TestLinkedList::testInsertAtBegin(LinkedList &linked_list, LinkedListNode::Content content) {
    std::println("Insert {} at begin.", content);
    auto result = linked_list.insertAtBegin(content);
    if (!result) {
        printError(result.error());
    } else {
        printItems(linked_list);
    }
    std::println();
}

void TestLinkedList::testInsertAtEnd(LinkedList &linked_list, LinkedListNode::Content content) {
    std::println("Insert {} at end.", content);
    auto result = linked_list.insertAtEnd(content);
    if (!result) {
        printError(result.error());
    } else {
        printItems(linked_list);
    }
    std::println();
}

void TestLinkedList::testRemove(LinkedList &linked_list, int index) {
    std::println("Remove at {}.", index);
    auto result = linked_list.remove(index);
    if (!result) {
        printError(result.error());
    } else {
        printItems(linked_list);
    }
    std::println();
}

void TestLinkedList::testRemoveAtBegin(LinkedList &linked_list) {
    std::println("Remove at begin.");
    auto result = linked_list.removeAtBegin();
    if (!result) {
        printError(result.error());
    } else {
        printItems(linked_list);
    }
    std::println();
}

void TestLinkedList::testRemoveAtEnd(LinkedList &linked_list) {
    std::println("Remove at end.");
    auto result = linked_list.removeAtEnd();
    if (!result) {
        printError(result.error());
    } else {
        printItems(linked_list);
    }
    std::println();
}

void TestLinkedList::testGetContent(LinkedList &linked_list, int index) {
    std::println("Get content at {}.", index);
    auto result = linked_list.getContent(index);
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestLinkedList::testGetContentAtEnd(LinkedList &linked_list) {
    std::println("Get content at end.");
    auto result = linked_list.getContentAtEnd();
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestLinkedList::testGetContentAtBegin(LinkedList &linked_list) {
    std::println("Get content at begin.");
    auto result = linked_list.getContentAtBegin();
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestLinkedList::test() {
    std::println("# TESTS: LINKED LIST");
    std::println();

    auto linked_list = LinkedList();
    printItems(linked_list);

    testContains(linked_list, 0);

    testGetContent(linked_list, 0);
    testGetContentAtBegin(linked_list);
    testGetContentAtEnd(linked_list);

    testRemove(linked_list, 0);
    testRemoveAtBegin(linked_list);
    testRemoveAtEnd(linked_list);

    testInsert(linked_list, -1, 4);

    testInsert(linked_list, 0, 4);

    testRemoveAtBegin(linked_list);

    testInsertAtBegin(linked_list, 4);

    testContains(linked_list, 0);

    testContains(linked_list, 4);

    testInsert(linked_list, 0, 1);

    testGetContent(linked_list, 0);

    testInsert(linked_list, 1, 2);

    testInsert(linked_list, 4, 3);

    testInsertAtBegin(linked_list, -2);

    testInsert(linked_list, 2, 3);

    testInsert(linked_list, 3, 4);

    testRemove(linked_list, 3);

    testRemove(linked_list, 0);

    testInsert(linked_list, 2, -3);

    testRemove(linked_list, 4);

    testRemove(linked_list, 4);

    testContains(linked_list, 4);

    testGetContent(linked_list, 4);

    testGetContent(linked_list, 3);

    testRemoveAtEnd(linked_list);

    testInsertAtEnd(linked_list, -2);

    testInsertAtBegin(linked_list, 1);

    testRemoveAtBegin(linked_list);

    testInsertAtBegin(linked_list, 1);

    testGetContentAtEnd(linked_list);

    testGetContentAtBegin(linked_list);

    std::println();

    std::println();
}
