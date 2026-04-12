#ifndef __CONTIGUOUS_LIST_HPP__
#define __CONTIGUOUS_LIST_HPP__

class ContiguousList {
        typedef int Content;

    private:
        unsigned int maximum_size;
        unsigned int quantity_of_items;
        Content *items;

        bool isEmpty();
        bool isFull();
        bool willIncludeNewItem(unsigned int index);
        void ensureIsInsideRangeToInsert(unsigned int index);
        void ensureIsInsideRangeToRemove(unsigned int index);
        void ensureIsNotFull();

    public:
        ContiguousList(unsigned int maximum_size);

        ~ContiguousList();

        void insert(unsigned int index, Content content);
        void print();
        void remove(unsigned int index);
};

#endif  // __CONTIGUOUS_LIST_HPP__
