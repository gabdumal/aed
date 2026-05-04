#include "testOpenAddressingHash.hpp"

#include <print>

#include "openAddressingHash.hpp"

void TestOpenAddressingHash::printItem(OpenAddressingHash::Content content) {
    std::println("Item: {}", content);
}

void TestOpenAddressingHash::printItems(OpenAddressingHash &contiguous_list) {
    std::print("Items: ");
    contiguous_list.print();
}

void TestOpenAddressingHash::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestOpenAddressingHash::testContains(OpenAddressingHash &contiguous_list, OpenAddressingHash::Content content) {
    std::println("Contains {}?", content);
    auto result = contiguous_list.contains(content);
    if (result) {
        std::println("True.");
    } else {
        std::println("False.");
    }
    std::println();
}

void TestOpenAddressingHash::testInsert(OpenAddressingHash &contiguous_list, int key, OpenAddressingHash::Content content) {
    std::println("Insert {} at key {}.", content, key);
    auto result = contiguous_list.insert(key, content);
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestOpenAddressingHash::testRemove(OpenAddressingHash &contiguous_list, int key) {
    std::println("Remove at key {}.", key);
    auto result = contiguous_list.remove(key);
    if (!result) {
        printError(result.error());
    } else {
        printItems(contiguous_list);
    }
    std::println();
}

void TestOpenAddressingHash::testGetContent(OpenAddressingHash &contiguous_list, int key) {
    std::println("Get content at key {}.", key);
    auto result = contiguous_list.getContent(key);
    if (!result) {
        printError(result.error());
    } else {
        printItem(result.value());
    }
    std::println();
}

void TestOpenAddressingHash::testListWithMaximumSizeOfZero() {
    std::println("## TEST: maximum size of 0.");
    std::println();

    constexpr int maximum_size = 0;

    try {
        auto contiguous_list = OpenAddressingHash(maximum_size);
    } catch (std::string error) {
        std::println("{}", error);
    }

    std::println();
}

void TestOpenAddressingHash::testListWithMaximumSizeOfFour() {
    std::println("## TEST: maximum size of 4.");
    std::println();

    constexpr int maximum_size = 4;

    auto contiguous_list = OpenAddressingHash(maximum_size);
    printItems(contiguous_list);

    testContains(contiguous_list, 0);

    testGetContent(contiguous_list, 0);

    testRemove(contiguous_list, 0);

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

    std::println();
}

void TestOpenAddressingHash::test() {
    std::println("# TESTS: OPEN ADDRESSING HASH");
    std::println();

    TestOpenAddressingHash::testListWithMaximumSizeOfZero();
    TestOpenAddressingHash::testListWithMaximumSizeOfFour();

    std::println();
}
