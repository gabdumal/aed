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

        bool isInsideRange(unsigned int index);
        std::string getMessageForIndexOutsideRange();

    public:
        ContiguousList(unsigned int maximum_size);

        ~ContiguousList();

        bool contains(Content content);
        bool isEmpty();
        bool isFull();

        std::expected<Content, std::string> getContent(unsigned int index);
        std::expected<void, std::string> insert(unsigned int index, Content content);
        std::expected<void, std::string> remove(unsigned int index);
        void print();
};

#endif  // __CONTIGUOUS_LIST_HPP__
