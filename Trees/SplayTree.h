#pragma once
#include "AbstractTree.h"
class SplayTree :
    public AbstractTree
{
public:
    struct node {
        node* left;
        node* right;
        node* parent;
        int value;

        explicit node(int val) {
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            value = val;
        }
    };

    bool insert(int val);

    void print() const;

    void clear();

    bool remove(int val);

    node* getRoot() const;

    SplayTree() {
        root = nullptr;
    }

    ~SplayTree() {
        clear();
    }

protected:
    node* root;

    bool insertRecursive(node* &current_node, const int& val);

    void printRecursive(node* current_node) const;

    bool removeRecursive(node* current_node, const int& val);

    void clearRecursive(node* current_node);

    node* splay(node* current_node);

    node* zig(node* current_node);

    node* zigzig(node* current_node);
    
    node* zigzag(node* current_node);

    node* min(node* current_node) const;

    node* max(node* current_node) const;

    node* merge(node* left_tree, node* right_tree);
};
