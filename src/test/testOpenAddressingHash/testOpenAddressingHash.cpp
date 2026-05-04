#include "testOpenAddressingHash.hpp"

#include <print>

#include "openAddressingHash.hpp"

void TestOpenAddressingHash::printValue(OpenAddressingHash::ContentValue value) {
    std::println("Value: {}", value);
}

void TestOpenAddressingHash::printItems(OpenAddressingHash &open_addressing_hash) {
    std::print("Items: ");
    open_addressing_hash.print();
}

void TestOpenAddressingHash::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestOpenAddressingHash::testContains(OpenAddressingHash &open_addressing_hash, OpenAddressingHash::ContentKey key) {
    std::println("Contains key {}?", key);
    auto result = open_addressing_hash.contains(key);
    if (!result) {
        printError(result.error());
    } else {
        if (result.value()) {
            std::println("True.");
        } else {
            std::println("False.");
        }
    }
    std::println();
}

void TestOpenAddressingHash::testInsert(OpenAddressingHash &open_addressing_hash, OpenAddressingHash::ContentKey key, OpenAddressingHash::ContentValue value) {
    std::println("Insert {} at key {}.", value, key);
    auto result = open_addressing_hash.insert(key, value);
    if (!result) {
        printError(result.error());
    } else {
        printItems(open_addressing_hash);
    }
    std::println();
}

void TestOpenAddressingHash::testRemove(OpenAddressingHash &open_addressing_hash, OpenAddressingHash::ContentKey key) {
    std::println("Remove at key {}.", key);
    auto result = open_addressing_hash.remove(key);
    if (!result) {
        printError(result.error());
    } else {
        printItems(open_addressing_hash);
    }
    std::println();
}

void TestOpenAddressingHash::testGetContent(OpenAddressingHash &open_addressing_hash, OpenAddressingHash::ContentKey key) {
    std::println("Get content at key {}.", key);
    auto result = open_addressing_hash.getContent(key);
    if (!result) {
        printError(result.error());
    } else {
        printValue(result.value());
    }
    std::println();
}

void TestOpenAddressingHash::testListWithMaximumSizeOfZero() {
    std::println("## TEST: maximum size of 0.");
    std::println();

    constexpr int maximum_size = 0;
    constexpr int step = 1;

    try {
        auto open_addressing_hash = OpenAddressingHash(maximum_size, step);
    } catch (std::string error) {
        std::println("{}", error);
    }

    std::println();
}

void TestOpenAddressingHash::testListWithMaximumSizeOfEight() {
    std::println("## TEST: maximum size of 8.");
    std::println();

    constexpr int maximum_size = 8;
    constexpr int step = 1;

    auto open_addressing_hash = OpenAddressingHash(maximum_size, step);
    printItems(open_addressing_hash);
    std::println();

    testContains(open_addressing_hash, 0);

    testGetContent(open_addressing_hash, 0);

    testRemove(open_addressing_hash, 0);

    testInsert(open_addressing_hash, -1, 4);

    testInsert(open_addressing_hash, 10, 4);

    testContains(open_addressing_hash, 10);

    testContains(open_addressing_hash, 4);

    testInsert(open_addressing_hash, 1, 1);

    testGetContent(open_addressing_hash, 0);

    testInsert(open_addressing_hash, 7, 2);

    testInsert(open_addressing_hash, 4, 3);

    testInsert(open_addressing_hash, 21, 4);

    testRemove(open_addressing_hash, 21);

    testGetContent(open_addressing_hash, 21);

    testInsert(open_addressing_hash, 21, 4);

    testInsert(open_addressing_hash, 20, 20);

    testRemove(open_addressing_hash, 4);

    testInsert(open_addressing_hash, 20, 20);

    testInsert(open_addressing_hash, 9, -3);

    testGetContent(open_addressing_hash, 9);

    testContains(open_addressing_hash, 9);

    std::println();
}

void TestOpenAddressingHash::test() {
    std::println("# TESTS: OPEN ADDRESSING HASH");
    std::println();

    TestOpenAddressingHash::testListWithMaximumSizeOfZero();
    TestOpenAddressingHash::testListWithMaximumSizeOfEight();

    std::println();
}
