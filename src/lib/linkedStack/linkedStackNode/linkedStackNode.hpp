#ifndef __LINKED_STACK_NODE_HPP__
#define __LINKED_STACK_NODE_HPP__

class LinkedStackNode {
    public:
        typedef int Content;

    private:
        Content content;
        LinkedStackNode *node_behind;

    public:
        LinkedStackNode(Content content, LinkedStackNode *node_behind);

        ~LinkedStackNode();

        Content getContent();
        LinkedStackNode *getNodeBehind();
};

#endif  // __LINKED_STACK_NODE_HPP__
