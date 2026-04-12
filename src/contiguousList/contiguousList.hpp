#ifndef __CONTIGUOUS_LIST_HPP__
#define __CONTIGUOUS_LIST_HPP__

class ContiguousList {
        typedef int Content;

    private:
        unsigned int maximum_size;
        unsigned int quantity_of_elements;
        Content *items;

    public:
        ContiguousList(unsigned int maximum_size);

        ~ContiguousList();
};

#endif  // __CONTIGUOUS_LIST_HPP__
