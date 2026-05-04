#ifndef __TEST_OPEN_ADDRESSING_HASH_HPP__
#define __TEST_OPEN_ADDRESSING_HASH_HPP__

#include "openAddressingHash.hpp"

class TestOpenAddressingHash {
    private:
        static void testContains(OpenAddressingHash &open_addressing_hash, OpenAddressingHash::Content content);

        static void testInsert(OpenAddressingHash &open_addressing_hash, int key, OpenAddressingHash::Content content);

        static void testRemove(OpenAddressingHash &open_addressing_hash, int key);

        static void testGetContent(OpenAddressingHash &open_addressing_hash, int key);

        static void printItem(OpenAddressingHash::Content content);
        static void printItems(OpenAddressingHash &open_addressing_hash);
        static void printError(const std::string &error);

        static void testListWithMaximumSizeOfFour();
        static void testListWithMaximumSizeOfZero();

    public:
        static void test();
};

#endif  // __TEST_OPEN_ADDRESSING_HASH_HPP__
