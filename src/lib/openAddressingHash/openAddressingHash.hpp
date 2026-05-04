#ifndef __OPEN_ADDRESSING_HASH_HPP__
#define __OPEN_ADDRESSING_HASH_HPP__

#include <expected>
#include <string>

class OpenAddressingHash {
    public:
        typedef int Content;
        static constexpr OpenAddressingHash::Content empty_slot = -1;
        static constexpr OpenAddressingHash::Content deleted_slot = -2;

    private:
        unsigned int maximum_size;
        Content *items;

        static std::string printContent(OpenAddressingHash::Content content);

        std::expected<unsigned int, std::string> calculateIndex(int key);

    public:
        OpenAddressingHash(int maximum_size);

        ~OpenAddressingHash();

        bool contains(Content content);

        std::expected<void, std::string> insert(int key, Content content);

        std::expected<void, std::string> remove(int key);

        std::expected<Content, std::string> getContent(int key);

        void print();
};

#endif  // __OPEN_ADDRESSING_HASH_HPP__
