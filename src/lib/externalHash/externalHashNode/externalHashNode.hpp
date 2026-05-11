#ifndef __EXTERNAL_HASH_NODE_HPP__
#define __EXTERNAL_HASH_NODE_HPP__

#include <string>

class ExternalHashNode {
    public:
        typedef int ContentKey;
        typedef int ContentValue;

    private:
        ContentKey key;
        ContentValue value;
        ExternalHashNode *next_node;

    public:
        ExternalHashNode(ContentKey key, ContentValue value);

        ~ExternalHashNode();

        ExternalHashNode *getNextNode();
        void setNextNode(ExternalHashNode *next_node);

        ContentKey getContentKey();

        ContentValue getContentValue();
        void setContentValue(ContentValue value);

        std::string print();
};

#endif  // __EXTERNAL_HASH_NODE_HPP__
