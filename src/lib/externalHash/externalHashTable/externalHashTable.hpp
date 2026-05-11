#ifndef __EXTERNAL_HASH_TABLE_HPP__
#define __EXTERNAL_HASH_TABLE_HPP__

#include <expected>
#include <string>

#include "externalHashNode.hpp"

class ExternalHashTable {
    private:
        static constexpr auto message_for_negative_key = "Key should be at least 0.";
        static constexpr auto message_for_key_not_found = "Key not found.";

        unsigned int maximum_size;
        ExternalHashNode **items;

        std::expected<unsigned int, std::string> calculateIndex(ExternalHashNode::Key key);

    public:
        ExternalHashTable(int maximum_size);

        ~ExternalHashTable();

        std::expected<bool, std::string> contains(ExternalHashNode::Key key);

        std::expected<void, std::string> insert(ExternalHashNode::Key key, ExternalHashNode::Value value);

        std::expected<void, std::string> remove(ExternalHashNode::Key key);

        std::expected<ExternalHashNode::Value, std::string> getContent(ExternalHashNode::Key key);

        unsigned int countKeysGreaterThan(ExternalHashNode::Key key);

        void print();
};

#endif  // __EXTERNAL_HASH_TABLE_HPP__
