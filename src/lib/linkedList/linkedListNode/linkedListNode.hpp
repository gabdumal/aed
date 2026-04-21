#ifndef __LINKED_LIST_NODE_HPP__
#define __LINKED_LIST_NODE_HPP__

class LinkedListNode {
    public:
        typedef int Content;

    private:
        Content content;
        LinkedListNode *next_node;

    public:
        LinkedListNode(Content content);

        ~LinkedListNode();

        LinkedListNode *getNextNode();
        void setNextNode(LinkedListNode *next_node);

        Content getContent();
};

#endif  // __LINKED_LIST_NODE_HPP__
