#ifndef __CONTIGUOUS_LIST_HPP__
#define __CONTIGUOUS_LIST_HPP__

#include <expected>
#include <string>

class ContiguousList {
    public:
        typedef int Content;

    private:
        int maximum_size;
        int quantity_of_items;
        Content *items;

        bool isWithin(int index);
        bool isWithinOrImmediatelyAfter(int index);

        std::string getMessageForIndexNotWithin();
        std::string getMessageForIndexNotWithinNorImmediatelyAfter();
        static std::string getMessageForEmptyList();
        std::string getMessageForFullList();

    public:
        ContiguousList(int maximum_size);

        ~ContiguousList();

        bool isEmpty();
        bool isFull();
        bool contains(Content content);

        std::expected<void, std::string> insert(int index, Content content);
        std::expected<void, std::string> insertAtBegin(Content content);
        std::expected<void, std::string> insertAtEnd(Content content);

        std::expected<void, std::string> remove(int index);
        std::expected<void, std::string> removeAtBegin();
        std::expected<void, std::string> removeAtEnd();

        std::expected<Content, std::string> getContent(int index);
        std::expected<Content, std::string> getContentAtBegin();
        std::expected<Content, std::string> getContentAtEnd();

        void print();
};

#endif  // __CONTIGUOUS_LIST_HPP__
