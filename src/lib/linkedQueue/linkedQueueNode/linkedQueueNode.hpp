#ifndef __LINKED_QUEUE_NODE_HPP__
#define __LINKED_QUEUE_NODE_HPP__

class LinkedQueueNode {
    public:
        typedef int Content;

    private:
        Content content;
        LinkedQueueNode *node_behind;

    public:
        LinkedQueueNode(Content content, LinkedQueueNode *node_ahead);

        ~LinkedQueueNode();

        Content getContent();
        LinkedQueueNode *getNodeBehind();
};

#endif  // __LINKED_QUEUE_NODE_HPP__
