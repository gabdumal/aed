#ifndef __BINARY_TREE_NODE_HPP__
#define __BINARY_TREE_NODE_HPP__

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

        static bool recursiveContains(BinaryTreeNode *node, Content content);

        static BinaryTreeNode *recursiveInsert(BinaryTreeNode *node, Content content);

        static std::expected<BinaryTreeNode *, std::string> advanceStepToFindNodeToRemove(BinaryTreeNode *node, Content content, unsigned int index_of_child);
        static BinaryTreeNode *removeNodeWith0Or1Children(BinaryTreeNode *node, unsigned int index_of_child);
        static BinaryTreeNode *getSuccessor(BinaryTreeNode *node);
        static void switchNodes(BinaryTreeNode *first_node, BinaryTreeNode *second_node);
        static std::expected<BinaryTreeNode *, std::string> recursiveRemove(BinaryTreeNode *node, Content content);

        static std::string recursivePrint(BinaryTreeNode *node, const std::string &prefix, bool is_last_child, bool is_root);

        static unsigned int recursiveCountNodesRecursively(BinaryTreeNode *node);

        static bool recursiveIsStrictlyBinary(BinaryTreeNode *node);

        static unsigned int recursiveGetHeight(BinaryTreeNode *node, unsigned int height);

    public:
        BinaryTreeNode(Content content);

        ~BinaryTreeNode();

        bool contains(Content content);
        void insert(Content content);
        std::expected<void, std::string> remove(Content content);

        unsigned int countNodes();
        unsigned int countNodesRecursively();
        unsigned int getHeight();

        bool isStrictlyBinary();
        bool isComplete();

        void print();
};

#endif  // __BINARY_TREE_NODE_HPP__
