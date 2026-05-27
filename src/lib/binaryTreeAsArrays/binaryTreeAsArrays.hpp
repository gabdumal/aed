#ifndef __BINARY_TREE_AS_ARRAYS_HPP__
#define __BINARY_TREE_AS_ARRAYS_HPP__

#include <expected>
#include <string>

class BinaryTreeAsArrays {
    public:
        typedef unsigned int Content;

    private:
        static constexpr Content empty_content = std::numeric_limits<Content>::min();
        static constexpr unsigned int empty_index = std::numeric_limits<unsigned int>::max();
        static constexpr auto message_for_content_not_found = "Content not found.";

        unsigned int maximum_size;
        unsigned int next_free_index = 0;
        unsigned int index_of_root = empty_index;

        Content *content;
        unsigned int *left_child;
        unsigned int *right_child;

        unsigned int createNode(Content content);
        unsigned int recursiveInsert(unsigned int index, Content content);

        std::string recursivePrint(unsigned int index, const std::string &prefix, bool is_last_child, bool is_root);

    public:
        BinaryTreeAsArrays(unsigned int maximum_size);

        ~BinaryTreeAsArrays();

        bool contains(Content content);
        unsigned int insert(Content content);

        std::expected<void, std::string> remove(Content content);

        void print();
};

#endif  // __BINARY_TREE_AS_ARRAYS_HPP__
