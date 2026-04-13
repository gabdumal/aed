#ifndef __CONTIGUOUS_LIST_HPP__
#define __CONTIGUOUS_LIST_HPP__

#include <expected>
#include <string>

class ContiguousList {
    public:
        typedef int Content;

    private:
        unsigned int maximum_size;

        unsigned int quantity_of_items;
        Content *items;

        bool isInsideRangeToInsert(unsigned int index);
        bool isInsideRangeToRemove(unsigned int index);

    public:
        ContiguousList(unsigned int maximum_size);

        ~ContiguousList();

        bool isEmpty();
        bool isFull();
        std::expected<void, std::string> insert(unsigned int index, Content content);
        void print();
        std::expected<void, std::string> remove(unsigned int index);
};

#endif  // __CONTIGUOUS_LIST_HPP__
