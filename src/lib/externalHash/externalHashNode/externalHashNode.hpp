#ifndef __EXTERNAL_HASH_NODE_HPP__
#define __EXTERNAL_HASH_NODE_HPP__

#include <string>

class ExternalHashNode {
    public:
        typedef int Key;
        typedef int Value;

    private:
        Key key;
        Value value;
        ExternalHashNode *next_node;

        static constexpr ExternalHashNode::Key default_key = 0;
        static constexpr ExternalHashNode::Value default_value = 0;

    public:
        ExternalHashNode() {
            key = default_key;
            value = default_value;
        };

        ExternalHashNode(Key key, Value value);

        ~ExternalHashNode();

        ExternalHashNode *getNextNode();
        void setNextNode(ExternalHashNode *next_node);

        Key getKey();

        Value getValue();
        void setValue(Value value);

        std::string print();
};

#endif  // __EXTERNAL_HASH_NODE_HPP__
