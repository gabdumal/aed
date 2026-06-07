#ifndef __HEAP_NODE_HPP__
#define __HEAP_NODE_HPP__

#include <expected>
#include <string>

class HeapNode {
    public:
        typedef int Content;

    private:
        static constexpr Content default_content = 0;
        static constexpr auto message_for_content_not_found = "Content not found.";

        Content content;
        HeapNode *parent;
        HeapNode *left_child;
        HeapNode *right_child;

        static void ascend(HeapNode *node);
        static HeapNode *descend(HeapNode *node);

        static std::string recursivePrint(HeapNode *node, const std::string &prefix, bool is_last_child, bool is_root);

        static unsigned int recursiveCountNodesRecursively(HeapNode *node);

        static bool recursiveIsStrictlyBinary(HeapNode *node);

    public:
        HeapNode(Content content);

        ~HeapNode();

        bool contains(Content content);
        void insert(Content content);
        std::expected<void, std::string> remove(Content content);
        std::expected<Content, std::string> pop();

        unsigned int countNodes();

        static unsigned int getHeight(HeapNode *node);

        bool isStrictlyBinary();

        void print();
};

#endif  // __HEAP_NODE_HPP__
