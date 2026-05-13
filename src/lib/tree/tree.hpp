#ifndef __TREE_HPP__
#define __TREE_HPP__

#include <expected>
#include <string>

class Tree {
    public:
        typedef int Content;

    private:
        static constexpr Content default_content = 0;
        static constexpr auto message_for_content_not_found = "Content not found.";

        Content content;
        unsigned int maximum_quantity_of_children;
        Tree **children;

    public:
        Tree(unsigned int maximum_quantity_of_children, Content content);

        ~Tree();

        std::expected<bool, std::string> contains(Content content);

        std::expected<void, std::string> insert(Content content);

        std::expected<void, std::string> remove(Content content);

        void print();
};

#endif  // __TREE_HPP__
