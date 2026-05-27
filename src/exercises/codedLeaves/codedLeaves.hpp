#ifndef __CODED_LEAVES_HPP__
#define __CODED_LEAVES_HPP__

#include <string>
#include <vector>

class CodedLeaves {
    public:
        struct Node {
                Node *left_child = nullptr;
                Node *right_child = nullptr;
                std::string code = "";

                ~Node() {
                    delete left_child;
                    delete right_child;
                }
        };

    private:
        static constexpr char left = '0';
        static constexpr char right = '1';

        static std::string recursivePrint(Node *node, const std::string &prefix, bool is_last_child, bool is_root);
        static void print(Node *tree);

        static Node *buildTree(std::vector<std::string> leaves);
        static Node *insertNode(Node *node, std::string code, unsigned int index);

    public:
        static void main();
};

#endif  // __CODED_LEAVES_HPP__
