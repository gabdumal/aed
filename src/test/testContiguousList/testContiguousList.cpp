#include "testContiguousList.hpp"

#include <print>

#include "contiguousList.hpp"

void TestContiguousList::printItem(ContiguousList::Content content) {
    std::println("Item: {}", content);
}

void TestContiguousList::printItems(ContiguousList &contiguous_list) {
    std::print("Items: ");
    contiguous_list.print();
}

void TestContiguousList::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestContiguousList::testContains(ContiguousList &contiguous_list, ContiguousList::Content content) {
    std::println("Contains {}?", content);
    auto result = contiguous_list.contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestContiguousList::testInsert(ContiguousList &contiguous_list, int index, ContiguousList::Content content) {
    std::println("Insert {} at {}.", content, index);
    auto result = contiguous_list.insert(index, content);
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestContiguousList::testInsertAtBegin(ContiguousList &contiguous_list, ContiguousList::Content content) {
    std::println("Insert {} at begin.", content);
    auto result = contiguous_list.insertAtBegin(content);
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestContiguousList::testInsertAtEnd(ContiguousList &contiguous_list, ContiguousList::Content content) {
    std::println("Insert {} at end.", content);
    auto result = contiguous_list.insertAtEnd(content);
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestContiguousList::testRemove(ContiguousList &contiguous_list, int index) {
    std::println("Remove at {}.", index);
    auto result = contiguous_list.remove(index);
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestContiguousList::testRemoveAtBegin(ContiguousList &contiguous_list) {
    std::println("Remove at begin.");
    auto result = contiguous_list.removeAtBegin();
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestContiguousList::testRemoveAtEnd(ContiguousList &contiguous_list) {
    std::println("Remove at end.");
    auto result = contiguous_list.removeAtEnd();
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestContiguousList::testGetContent(ContiguousList &contiguous_list, int index) {
    std::println("Get content at {}.", index);
    auto result = contiguous_list.getContent(index);
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestContiguousList::testGetContentAtEnd(ContiguousList &contiguous_list) {
    std::println("Get content at end.");
    auto result = contiguous_list.getContentAtEnd();
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestContiguousList::testGetContentAtBegin(ContiguousList &contiguous_list) {
    std::println("Get content at begin.");
    auto result = contiguous_list.getContentAtBegin();
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestContiguousList::testListWithMaximumSizeOfZero() {
    std::println("## TEST: maximum size of 0.");
    std::println();

    constexpr int maximum_size = 0;

    try {
        auto contiguous_list = ContiguousList(maximum_size);
    } catch (std::string error) {
        std::println("{}", error);
    }

    std::println();
}

void TestContiguousList::testListWithMaximumSizeOfFour() {
    std::println("## TEST: maximum size of 4.");
    std::println();

    constexpr int maximum_size = 4;

    auto contiguous_list = ContiguousList(maximum_size);
    printItems(contiguous_list);

    testContains(contiguous_list, 0);

    testGetContent(contiguous_list, 0);
    testGetContentAtBegin(contiguous_list);
    testGetContentAtEnd(contiguous_list);

    testRemove(contiguous_list, 0);
    testRemoveAtBegin(contiguous_list);
    testRemoveAtEnd(contiguous_list);

    testInsert(contiguous_list, -1, 4);

    testInsert(contiguous_list, 0, 4);

    testContains(contiguous_list, 0);

    testContains(contiguous_list, 4);

    testInsert(contiguous_list, 0, 1);

    testGetContent(contiguous_list, 0);

    testInsert(contiguous_list, 1, 2);

    testInsert(contiguous_list, 2, 3);

    testInsert(contiguous_list, 3, 4);

    testRemove(contiguous_list, 3);

    testInsert(contiguous_list, 3, 4);

    testRemove(contiguous_list, 0);

    testInsert(contiguous_list, 2, -3);

    testGetContent(contiguous_list, 2);

    testContains(contiguous_list, -3);

    testRemoveAtEnd(contiguous_list);

    testInsertAtEnd(contiguous_list, -2);

    testGetContentAtEnd(contiguous_list);

    testGetContentAtBegin(contiguous_list);

    testInsertAtBegin(contiguous_list, 1);

    testRemoveAtBegin(contiguous_list);

    testInsertAtBegin(contiguous_list, 1);

    std::println();
}

void TestContiguousList::test() {
    std::println("# TESTS: CONTIGUOUS LIST");
    std::println();

    TestContiguousList::testListWithMaximumSizeOfZero();
    TestContiguousList::testListWithMaximumSizeOfFour();

    std::println();
}
