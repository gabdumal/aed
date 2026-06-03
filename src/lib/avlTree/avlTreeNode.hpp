#ifndef __AVL_TREE_NODE_HPP__
#define __AVL_TREE_NODE_HPP__

#include <expected>
#include <string>

class AvlTreeNode {
    public:
        typedef int Content;

    private:
        static constexpr unsigned int maximum_quantity_of_children = 2;
        static constexpr unsigned int index_of_left_child = 0;
        static constexpr unsigned int index_of_right_child = 1;
        static constexpr Content default_content = 0;
        static constexpr auto message_for_content_not_found = "Content not found.";

        Content content;
        AvlTreeNode *children[maximum_quantity_of_children];
        unsigned int height;

        static AvlTreeNode *rotateToLeft(AvlTreeNode *node);
        static AvlTreeNode *rotateToRight(AvlTreeNode *node);
        static AvlTreeNode *rotateToLeftThenRight(AvlTreeNode *node);
        static AvlTreeNode *rotateToRightThenLeft(AvlTreeNode *node);

        static AvlTreeNode *updateAvlStructure(AvlTreeNode *node);

        static bool recursiveContains(AvlTreeNode *node, Content content);

        static AvlTreeNode *recursiveInsert(AvlTreeNode *node, Content content);

        static std::expected<AvlTreeNode *, std::string> advanceStepToFindNodeToRemove(AvlTreeNode *node, Content content, unsigned int index_of_child);
        static AvlTreeNode *removeNodeWith0Or1Children(AvlTreeNode *node, unsigned int index_of_child);
        static AvlTreeNode *getSuccessor(AvlTreeNode *node);
        static void switchNodes(AvlTreeNode *first_node, AvlTreeNode *second_node);
        static std::expected<AvlTreeNode *, std::string> recursiveRemove(AvlTreeNode *node, Content content);

        static std::string recursivePrint(AvlTreeNode *node, const std::string &prefix, bool is_last_child, bool is_root);

        static unsigned int recursiveCountNodesRecursively(AvlTreeNode *node);

        static bool recursiveIsStrictlyBinary(AvlTreeNode *node);

    public:
        AvlTreeNode(Content content);

        ~AvlTreeNode();

        bool contains(Content content);
        void insert(Content content);
        std::expected<void, std::string> remove(Content content);

        unsigned int countNodes();
        unsigned int countNodesRecursively();

        static unsigned int getHeight(AvlTreeNode *node);
        static int getBalancingFactor(AvlTreeNode *node);

        bool isStrictlyBinary();
        bool isComplete();

        void print();
};

#endif  // __AVL_TREE_NODE_HPP__
