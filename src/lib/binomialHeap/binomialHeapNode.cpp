#include "binomialHeapNode.hpp"

#include <format>
#include <print>
#include <stdexcept>
#include <vector>

BinomialHeapNode::BinomialHeapNode(Content content) {
    this->content = content;
    this->parent = nullptr;
    this->sibling = nullptr;
    this->child = nullptr;
    this->order = 0;
}

BinomialHeapNode::~BinomialHeapNode() {
    this->content = default_content;

    this->parent = nullptr;

    delete child;
    this->child = nullptr;

    delete sibling;
    this->sibling = nullptr;

    this->order = 0;
}

BinomialHeapNode *BinomialHeapNode::add(
    BinomialHeapNode *first_heap,
    BinomialHeapNode *second_heap) {
    if (first_heap == nullptr) {
        return second_heap;
    }
    if (second_heap == nullptr) {
        return first_heap;
    }

    if (first_heap->order != second_heap->order) {
        throw std::invalid_argument(
            "The order of both heaps must be the same.");
    }

    if (first_heap->content > second_heap->content) {
        std::swap(first_heap, second_heap);
    }

    second_heap->parent = first_heap;

    second_heap->sibling = first_heap->child;
    first_heap->child = second_heap;

    ++first_heap->order;

    return first_heap;
}

BinomialHeapNode *BinomialHeapNode::unite(
    BinomialHeapNode *first_heap,
    BinomialHeapNode *second_heap) {
    if (first_heap == nullptr) {
        return second_heap;
    }
    if (second_heap == nullptr) {
        return first_heap;
    }

    //
    // Phase 1: merge root lists by decreasing degree.
    //
    BinomialHeapNode *head = nullptr;
    BinomialHeapNode **tail = &head;

    while (first_heap && second_heap) {
        if (first_heap->order >= second_heap->order) {
            *tail = first_heap;
            first_heap = first_heap->sibling;
        } else {
            *tail = second_heap;
            second_heap = second_heap->sibling;
        }

        tail = &((*tail)->sibling);
    }

    *tail = first_heap ? first_heap : second_heap;

    //
    // Phase 2: consolidate.
    //
    BinomialHeapNode *prev = nullptr;
    BinomialHeapNode *curr = head;

    while (curr && curr->sibling) {
        BinomialHeapNode *next = curr->sibling;

        if (curr->order != next->order) {
            prev = curr;
            curr = next;
            continue;
        }

        //
        // Save successor BEFORE add()
        //
        BinomialHeapNode *after_next = next->sibling;

        BinomialHeapNode *merged = add(curr, next);

        merged->sibling = after_next;

        if (prev == nullptr) {
            head = merged;
        } else {
            prev->sibling = merged;
        }

        curr = merged;

        //
        // Do not advance prev.
        // The merged tree may need another merge.
        //
    }

    return head;
}

BinomialHeapNode *BinomialHeapNode::insert(Content content) {
    auto new_node = new BinomialHeapNode(content);
    return unite(this, new_node);
}

BinomialHeapNode::Content BinomialHeapNode::front() {
    auto current = this;
    auto smallest_content = current->content;

    while (current != nullptr) {
        if (current->content < smallest_content) {
            smallest_content = current->content;
        }
        current = current->sibling;
    }

    return smallest_content;
}

BinomialHeapNode *BinomialHeapNode::pop() {
    BinomialHeapNode *before_smallest = nullptr;
    BinomialHeapNode *smallest = this;

    BinomialHeapNode *predecessor = this;
    BinomialHeapNode *current = this->sibling;

    while (current != nullptr) {
        if (current->content < smallest->content) {
            before_smallest = predecessor;
            smallest = current;
        }

        predecessor = current;
        current = current->sibling;
    }

    BinomialHeapNode *new_root = this;

    // Remove smallest from the root list.
    if (before_smallest != nullptr) {
        before_smallest->sibling = smallest->sibling;
    } else {
        new_root = this->sibling;
    }

    // Children already form a valid root list:
    // orders are stored in decreasing order.
    BinomialHeapNode *children_head = smallest->child;

    // Children become roots.
    for (auto p = children_head; p != nullptr; p = p->sibling) {
        p->parent = nullptr;
    }

    // Prevent recursive destruction of remaining heaps.
    smallest->child = nullptr;
    smallest->sibling = nullptr;

    delete smallest;

    return unite(new_root, children_head);
}

void BinomialHeapNode::printTree(
    BinomialHeapNode *node,
    const std::string &prefix,
    bool last) {
    if (node == nullptr) {
        return;
    }

    std::print("{}{}{} ({})\n",
               prefix,
               last ? "└── " : "├── ",
               node->content,
               node->order);

    std::vector<BinomialHeapNode *> children;

    for (auto c = node->child; c != nullptr; c = c->sibling) {
        children.push_back(c);
    }

    for (size_t i = 0; i < children.size(); ++i) {
        printTree(
            children[i],
            prefix + (last ? "    " : "│   "),
            i + 1 == children.size());
    }
}

void BinomialHeapNode::printRootList() {
    std::println("ROOT LIST");

    for (auto p = this; p != nullptr; p = p->sibling) {
        std::println(
            "[{}] key={} order={} parent={} child={} sibling={}",
            static_cast<void *>(p),
            p->content,
            p->order,
            static_cast<void *>(p->parent),
            static_cast<void *>(p->child),
            static_cast<void *>(p->sibling));
    }

    std::println("");
}

void BinomialHeapNode::print() {
    // printRootList();

    std::println("TREES");

    for (auto root = this; root != nullptr; root = root->sibling) {
        std::println("\nB{}", root->order);

        std::print("{} ({})\n",
                   root->content,
                   root->order);

        std::vector<BinomialHeapNode *> children;

        for (auto c = root->child; c != nullptr; c = c->sibling) {
            children.push_back(c);
        }

        for (size_t i = 0; i < children.size(); ++i) {
            printTree(children[i], "", i + 1 == children.size());
        }
    }
}

unsigned int BinomialHeapNode::countNodes() {
    unsigned int quantity_of_nodes = 0;
    auto current = this;

    while (current != nullptr) {
        if (current->order == 0) {
            quantity_of_nodes += 1;
        } else {
            quantity_of_nodes += (unsigned int) 2 << (((int) current->order) - 1);
        }

        current = current->sibling;
    }

    return quantity_of_nodes;
}

void BinomialHeapNode::ascend(BinomialHeapNode *node) {
    while (node->parent != nullptr &&
           node->content < node->parent->content) {
        std::swap(node->content,
                  node->parent->content);

        node = node->parent;
    }
}

void BinomialHeapNode::descend(BinomialHeapNode *node) {
    while (true) {
        BinomialHeapNode *smallest = node;

        for (auto child = node->child;
             child != nullptr;
             child = child->sibling) {
            if (child->content < smallest->content) {
                smallest = child;
            }
        }

        if (smallest == node) {
            break;
        }

        std::swap(node->content,
                  smallest->content);

        node = smallest;
    }
}

void BinomialHeapNode::changeContent(
    Content new_content) {
    auto old_content = this->content;

    this->content = new_content;

    if (new_content < old_content) {
        ascend(this);
    } else if (new_content > old_content) {
        descend(this);
    }
}
