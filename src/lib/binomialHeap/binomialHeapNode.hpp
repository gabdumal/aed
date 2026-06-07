#ifndef __BINOMIAL_HEAP_NODE_HPP__
#define __BINOMIAL_HEAP_NODE_HPP__

#include <string>

class BinomialHeapNode {
    public:
        typedef int Content;

    private:
        static constexpr Content default_content = 0;
        static constexpr auto message_for_content_not_found = "Content not found.";

        Content content;
        BinomialHeapNode *parent;
        BinomialHeapNode *sibling;
        BinomialHeapNode *child;
        unsigned int order;

        static std::string recursivePrint(BinomialHeapNode *node, const std::string &prefix, bool is_last_child, bool is_root);

    public:
        BinomialHeapNode(Content content);

        ~BinomialHeapNode();

        static BinomialHeapNode *add(BinomialHeapNode *first_heap, BinomialHeapNode *second_heap);
        static BinomialHeapNode *unite(BinomialHeapNode *first_heap, BinomialHeapNode *second_heap);

        BinomialHeapNode *insert(Content content);
        Content front();
        BinomialHeapNode *pop();

        unsigned int countNodes();

        void print();
};

#endif  // __BINOMIAL_HEAP_NODE_HPP__
