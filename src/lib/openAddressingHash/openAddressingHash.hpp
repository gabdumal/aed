#ifndef __OPEN_ADDRESSING_HASH_HPP__
#define __OPEN_ADDRESSING_HASH_HPP__

#include <expected>
#include <string>

class OpenAddressingHash {
    public:
        typedef int ContentKey;
        typedef int ContentValue;

        typedef struct {
                ContentKey key;
                ContentValue value;
        } Content;

        static constexpr ContentKey key_of_empty_slot = -1;
        static constexpr OpenAddressingHash::Content empty_slot{
            .key = key_of_empty_slot,
            .value = 0};

        static constexpr ContentKey key_of_deleted_slot = -2;
        static constexpr OpenAddressingHash::Content deleted_slot{
            .key = key_of_deleted_slot,
            .value = 0};

    private:
        static constexpr auto message_for_negative_key = "Key should be at least 0.";
        static constexpr auto message_for_key_not_found = "Key not found.";

        unsigned int maximum_size;
        unsigned int step;
        Content *items;

        std::expected<unsigned int, std::string> calculateIndex(ContentKey key);

    public:
        OpenAddressingHash(int maximum_size, int step);

        ~OpenAddressingHash();

        std::expected<bool, std::string> contains(ContentKey key);

        std::expected<void, std::string> insert(ContentKey key, ContentValue value);

        std::expected<void, std::string> remove(ContentKey key);

        std::expected<ContentValue, std::string> getContent(ContentKey key);

        void print();
        static std::string printContent(OpenAddressingHash::Content content);
};

#endif  // __OPEN_ADDRESSING_HASH_HPP__
