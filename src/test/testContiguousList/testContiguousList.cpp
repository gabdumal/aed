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

void TestContiguousList::testGet(ContiguousList &contiguous_list, unsigned int index) {
    std::println("Get at {}.", index);
    auto result = contiguous_list.getContent(index);
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestContiguousList::testInsert(ContiguousList &contiguous_list, unsigned int index, ContiguousList::Content content) {
    std::println("Insert {} at {}.", content, index);
    auto result = contiguous_list.insert(index, content);
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestContiguousList::testRemove(ContiguousList &contiguous_list, unsigned int index) {
    std::println("Remove at {}.", index);
    auto result = contiguous_list.remove(index);
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestContiguousList::testListWithMaximumSizeOfZero() {
    std::println("## TEST: maximum size of 0.");
    std::println();

    constexpr unsigned int maximum_size = 0;

    auto contiguous_list = ContiguousList(maximum_size);
    printItems(contiguous_list);

    testInsert(contiguous_list, 0, 4);

    testContains(contiguous_list, 0);

    std::println();
}

void TestContiguousList::testListWithMaximumSizeOfFour() {
    std::println("## TEST: maximum size of 4.");
    std::println();

    constexpr unsigned int maximum_size = 4;

    auto contiguous_list = ContiguousList(maximum_size);
    printItems(contiguous_list);

    testContains(contiguous_list, 0);

    testGet(contiguous_list, 0);

    testRemove(contiguous_list, 0);

    testInsert(contiguous_list, (unsigned int) -1, 4);

    testInsert(contiguous_list, 0, 4);

    testContains(contiguous_list, 0);

    testContains(contiguous_list, 4);

    testInsert(contiguous_list, 0, 1);

    testGet(contiguous_list, 0);

    testInsert(contiguous_list, 1, 2);

    testInsert(contiguous_list, 2, 3);

    testInsert(contiguous_list, 3, 4);

    testRemove(contiguous_list, 3);

    testInsert(contiguous_list, 3, 4);

    testRemove(contiguous_list, 0);

    testInsert(contiguous_list, 2, -3);

    testGet(contiguous_list, 2);

    testContains(contiguous_list, -3);

    std::println();
}

void TestContiguousList::test() {
    std::println("# TESTS: CONTIGUOUS LIST");
    std::println();

    TestContiguousList::testListWithMaximumSizeOfZero();
    TestContiguousList::testListWithMaximumSizeOfFour();

    std::println();
}
