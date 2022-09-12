#pragma once
#include "AbstractTree.h"
#include <cstdlib>

class Treap :
    public AbstractTree
{
public:
    struct node {
        node* left;
        node* right;
        int value;
        int priority;

        explicit node(int val) {
            left = nullptr;
            right = nullptr;
            priority = std::rand();
            value = val;
        }
    };

    void print() const;

    bool insert(int val);

    bool remove(int val);

    void clear();

    node* getRoot() const;

    Treap() {
        root = nullptr;
    }

    ~Treap() {
        clear();
    }

protected:
    struct ret {
        node* gr;
        node* eq;
        node* less;
    };

    node* root;

    node* merge(node* first, node* second);

    ret split(node* current_node, const int& val);

    void printRecursive(node* current_node) const;

    void clearRecursive(node* current_node);
};
