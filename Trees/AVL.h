#pragma once
#include "AbstractTree.cpp"
class AVL :
    public AbstractTree
{
public:
    struct node {
        node* left;
        node* right;
        char height;
        int value;

        explicit node(int val) {
            left = nullptr;
            right = nullptr;
            height = 1;
            value = val;
        }
    };

    bool insert(int val);

    void print() const;

    void clear();

    bool remove(int val);

    node* getRoot() const;

    AVL() {
        root = nullptr;
    }

    ~AVL() {
        clear();
    }

protected:
    node* root;

    bool insertRecursive(node* &current_node, const int &val);

    char height(node* current_node) const;

    char getBalance(node* current_node) const;

    void doBalance(node* &current_node);

    void recalc_height(node* current_node);

    void printRecursive(node* current_node) const;

    node* removeRecursive(node* &current_node, const int& val);

    void clearRecursive(node* current_node);

    node* min(node* current_node) const;

    node* max(node* current_node) const;
};
