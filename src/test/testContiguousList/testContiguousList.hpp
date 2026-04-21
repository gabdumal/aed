#ifndef __TEST_CONTIGUOUS_LIST_HPP__
#define __TEST_CONTIGUOUS_LIST_HPP__

#include "contiguousList.hpp"

class TestContiguousList {
    private:
        static void testContains(ContiguousList &contiguous_list, ContiguousList::Content content);

        static void testInsert(ContiguousList &contiguous_list, int index, ContiguousList::Content content);
        static void testInsertAtBegin(ContiguousList &contiguous_list, ContiguousList::Content content);
        static void testInsertAtEnd(ContiguousList &contiguous_list, ContiguousList::Content content);

        static void testRemove(ContiguousList &contiguous_list, int index);
        static void testRemoveAtBegin(ContiguousList &contiguous_list);
        static void testRemoveAtEnd(ContiguousList &contiguous_list);

        static void testGetContent(ContiguousList &contiguous_list, int index);
        static void testGetContentAtBegin(ContiguousList &contiguous_list);
        static void testGetContentAtEnd(ContiguousList &contiguous_list);

        static void printItem(ContiguousList::Content content);
        static void printItems(ContiguousList &contiguous_list);
        static void printError(const std::string &error);

        static void testListWithMaximumSizeOfFour();
        static void testListWithMaximumSizeOfZero();

    public:
        static void test();
};

#endif  // __TEST_CONTIGUOUS_LIST_HPP__
