#ifndef __EXTERNAL_HASH_TABLE_HPP__
#define __EXTERNAL_HASH_TABLE_HPP__

#include <expected>
#include <string>

#include "externalHashNode.hpp"

class ExternalHashTable {
    private:
        unsigned int maximum_size;
        ExternalHashNode **items;

    public:
        ExternalHashTable(int maximum_size);

        ~ExternalHashTable();

        std::expected<bool, std::string> contains(ExternalHashNode::ContentKey key);

        std::expected<void, std::string> insert(ExternalHashNode::ContentKey key, ExternalHashNode::ContentValue value);

        std::expected<void, std::string> remove(ExternalHashNode::ContentKey key);

        std::expected<ExternalHashNode::ContentValue, std::string> getContent(ExternalHashNode::ContentKey key);

        unsigned int countKeysGreaterThan(ExternalHashNode::ContentKey key);

        void print();
};

#endif  // __EXTERNAL_HASH_TABLE_HPP__
