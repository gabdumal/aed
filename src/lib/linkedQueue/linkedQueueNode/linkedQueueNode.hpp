#ifndef __LINKED_QUEUE_NODE_HPP__
#define __LINKED_QUEUE_NODE_HPP__

class LinkedQueueNode {
    public:
        typedef int Content;

    private:
        Content content;
        LinkedQueueNode *next;

    public:
        LinkedQueueNode(Content content);

        ~LinkedQueueNode();

        Content get();
        void set(Content content);
};

#endif  // __LINKED_QUEUE_NODE_HPP__
