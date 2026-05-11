#include "testExternalHash.hpp"

#include <print>

#include "externalHashTable.hpp"

void TestExternalHash::printValue(ExternalHashNode::ContentValue value) {
    std::println("Value: {}", value);
}

void TestExternalHash::printItems(ExternalHashTable &external_hash_table) {
    std::print("Items: ");
    external_hash_table.print();
}

void TestExternalHash::printError(const std::string &error) {
    std::println("Error: {}", error);
}

void TestExternalHash::testContains(ExternalHashTable &external_hash_table, ExternalHashNode::ContentKey key) {
    std::println("Contains key {}?", key);
    auto result = external_hash_table.contains(key);
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

void TestExternalHash::testInsert(ExternalHashTable &external_hash_table, ExternalHashNode::ContentKey key, ExternalHashNode::ContentValue value) {
    std::println("Insert {} at key {}.", value, key);
    auto result = external_hash_table.insert(key, value);
    if (!result) {
        printError(result.error());
    } else {
        printItems(external_hash_table);
    }
    std::println();
}

void TestExternalHash::testRemove(ExternalHashTable &external_hash_table, ExternalHashNode::ContentKey key) {
    std::println("Remove at key {}.", key);
    auto result = external_hash_table.remove(key);
    if (!result) {
        printError(result.error());
    } else {
        printItems(external_hash_table);
    }
    std::println();
}

void TestExternalHash::testGetContent(ExternalHashTable &external_hash_table, ExternalHashNode::ContentKey key) {
    std::println("Get content at key {}.", key);
    auto result = external_hash_table.getContent(key);
    if (!result) {
        printError(result.error());
    } else {
        printValue(result.value());
    }
    std::println();
}

void TestExternalHash::testCountKeysGreaterThan(ExternalHashTable &external_hash_table, ExternalHashNode::ContentKey key) {
    std::println("Count keys greater than {}.", key);
    auto result = external_hash_table.getContent(key);
    if (!result) {
        printError(result.error());
    } else {
        printValue(result.value());
    }
    std::println();
}

void TestExternalHash::testListWithMaximumSizeOfZero() {
    std::println("## TEST: maximum size of 0.");
    std::println();

    constexpr int maximum_size = 0;

    try {
        auto external_hash_table = ExternalHashTable(maximum_size);
    } catch (std::string error) {
        std::println("{}", error);
    }

    std::println();
}

void TestExternalHash::testListWithMaximumSizeOfEight() {
    std::println("## TEST: maximum size of 8.");
    std::println();

    constexpr int maximum_size = 8;

    auto external_hash_table = ExternalHashTable(maximum_size);
    printItems(external_hash_table);
    std::println();

    testContains(external_hash_table, 0);

    testGetContent(external_hash_table, 0);

    testRemove(external_hash_table, 0);

    testInsert(external_hash_table, -1, 4);

    testInsert(external_hash_table, 10, 4);

    testContains(external_hash_table, 10);

    testContains(external_hash_table, 4);

    testInsert(external_hash_table, 1, 1);

    testGetContent(external_hash_table, 0);

    testInsert(external_hash_table, 7, 2);

    testInsert(external_hash_table, 4, 3);

    testInsert(external_hash_table, 21, 4);

    testRemove(external_hash_table, 21);

    testGetContent(external_hash_table, 21);

    testInsert(external_hash_table, 21, 4);

    testInsert(external_hash_table, 20, 20);

    testRemove(external_hash_table, 4);

    testInsert(external_hash_table, 20, -20);

    testInsert(external_hash_table, 9, -3);

    testGetContent(external_hash_table, 9);

    testContains(external_hash_table, 9);

    std::println();
}

void TestExternalHash::test() {
    std::println("# TESTS: EXTERNAL HASH");
    std::println();

    TestExternalHash::testListWithMaximumSizeOfZero();
    TestExternalHash::testListWithMaximumSizeOfEight();

    std::println();
}
