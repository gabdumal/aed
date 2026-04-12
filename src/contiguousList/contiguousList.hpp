#ifndef __CONTIGUOUS_LIST_HPP__
#define __CONTIGUOUS_LIST_HPP__

class ContiguousList {
        typedef int Content;

    private:
        unsigned int maximum_size;
        unsigned int quantity_of_items;
        Content *items;

        void ensureIsInsideRange(unsigned int index);
        bool isFull();
        void ensureIsNotFull();

    public:
        ContiguousList(unsigned int maximum_size);

        ~ContiguousList();

        void insert(unsigned int index, Content content);
};

#endif  // __CONTIGUOUS_LIST_HPP__
