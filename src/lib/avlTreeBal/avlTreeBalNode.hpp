#ifndef __AVL_TREE_BAL_NODE_HPP__
#define __AVL_TREE_BAL_NODE_HPP__

#include <expected>
#include <string>

class AvlTreeBalNode {
    public:
        typedef int Content;

    private:
        static constexpr unsigned int maximum_quantity_of_children = 2;
        static constexpr unsigned int index_of_left_child = 0;
        static constexpr unsigned int index_of_right_child = 1;
        static constexpr Content default_content = 0;
        static constexpr auto message_for_content_not_found = "Content not found.";

        Content content;
        AvlTreeBalNode *children[maximum_quantity_of_children];
        int balancing_factor;

        static AvlTreeBalNode *rotateToLeft(AvlTreeBalNode *node);
        static AvlTreeBalNode *rotateToRight(AvlTreeBalNode *node);
        static AvlTreeBalNode *rotateToLeftThenRight(AvlTreeBalNode *node);
        static AvlTreeBalNode *rotateToRightThenLeft(AvlTreeBalNode *node);

        static AvlTreeBalNode *updateAvlStructure(AvlTreeBalNode *node);

        static bool recursiveContains(AvlTreeBalNode *node, Content content);

        static AvlTreeBalNode *recursiveInsert(AvlTreeBalNode *node, Content content);

        static std::expected<AvlTreeBalNode *, std::string> advanceStepToFindNodeToRemove(AvlTreeBalNode *node, Content content, unsigned int index_of_child);
        static AvlTreeBalNode *removeNodeWith0Or1Children(AvlTreeBalNode *node, unsigned int index_of_child);
        static AvlTreeBalNode *getSuccessor(AvlTreeBalNode *node);
        static void switchNodes(AvlTreeBalNode *first_node, AvlTreeBalNode *second_node);
        static std::expected<AvlTreeBalNode *, std::string> recursiveRemove(AvlTreeBalNode *node, Content content);

        static std::string recursivePrint(AvlTreeBalNode *node, const std::string &prefix, bool is_last_child, bool is_root);

        static unsigned int recursiveCountNodesRecursively(AvlTreeBalNode *node);

        static bool recursiveIsStrictlyBinary(AvlTreeBalNode *node);

    public:
        AvlTreeBalNode(Content content);

        ~AvlTreeBalNode();

        bool contains(Content content);
        void insert(Content content);
        std::expected<void, std::string> remove(Content content);

        unsigned int countNodes();
        unsigned int countNodesRecursively();

        static unsigned int getHeight(AvlTreeBalNode *node);
        static int getBalancingFactor(AvlTreeBalNode *node);

        bool isStrictlyBinary();
        bool isComplete();

        void print();
};

#endif  // __AVL_TREE_BAL_NODE_HPP__
