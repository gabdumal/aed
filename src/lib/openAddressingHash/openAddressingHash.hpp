#ifndef __OPEN_ADDRESSING_HASH_HPP__
#define __OPEN_ADDRESSING_HASH_HPP__

#include <expected>
#include <string>

class OpenAddressingHash {
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
        static std::string printContent(OpenAddressingHash::Content content);

    public:
        OpenAddressingHash(int maximum_size);

        ~OpenAddressingHash();

        bool isEmpty();
        bool isFull();
        bool contains(Content content);

        std::expected<void, std::string> insert(int key, Content content);

        std::expected<void, std::string> remove(int key);

        std::expected<Content, std::string> getContent(int key);

        void print();
};

#endif  // __OPEN_ADDRESSING_HASH_HPP__
