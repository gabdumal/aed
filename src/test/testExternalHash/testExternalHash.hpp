#ifndef __TEST_EXTERNAL_HASH_HPP__
#define __TEST_EXTERNAL_HASH_HPP__

#include "externalHashTable.hpp"

class TestExternalHash {
    private:
        static void testContains(ExternalHashTable &external_hash_table, ExternalHashNode::Key key);

        static void testInsert(ExternalHashTable &external_hash_table, ExternalHashNode::Key key, ExternalHashNode::Value value);

        static void testRemove(ExternalHashTable &external_hash_table, ExternalHashNode::Key key);

        static void testGetContent(ExternalHashTable &external_hash_table, ExternalHashNode::Key key);

        static void testCountKeysGreaterThan(ExternalHashTable &external_hash_table, ExternalHashNode::Key key);

        static void printValue(ExternalHashNode::Value value);
        static void printItems(ExternalHashTable &external_hash_table);
        static void printError(const std::string &error);

        static void testListWithMaximumSizeOfSeven();
        static void testListWithMaximumSizeOfZero();

    public:
        static void test();
};

#endif  // __TEST_EXTERNAL_HASH_HPP__
