#ifndef __BINARY_TREE_HPP__
#define __BINARY_TREE_HPP__

#include <expected>
#include <string>

class BinaryTreeNode {
    public:
        typedef int Content;

    private:
        static constexpr unsigned int maximum_quantity_of_children = 2;
        static constexpr unsigned int index_of_left_child = 0;
        static constexpr unsigned int index_of_right_child = 1;
        static constexpr Content default_content = 0;
        static constexpr auto message_for_content_not_found = "Content not found.";

        Content content;
        BinaryTreeNode *children[maximum_quantity_of_children];

        BinaryTreeNode *recursiveInsert(BinaryTreeNode *node, Content content);

    public:
        BinaryTreeNode(Content content);

        ~BinaryTreeNode();

        std::expected<bool, std::string> contains(Content content);

        void insert(Content content);

        std::expected<void, std::string> remove(Content content);

        void print();
};

#endif  // __BINARY_TREE_HPP__
