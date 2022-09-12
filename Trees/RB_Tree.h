#pragma once
#include "AbstractTree.h"
class RB_Tree :
    public AbstractTree
{
public:
    // 0 is red, 1 is black
    enum colors {red = 0, black};

    struct node {
        node* left;
        node* right;
        node* parent;
        bool color;
        int value;

        explicit node(int val) {
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            color = red;
            value = val;
        }
    };

    bool insert(int val);

    void print() const;

    void clear();

    bool remove(int val);

    node* getRoot() const;

    RB_Tree() {
        root = nullptr;
    }

    ~RB_Tree() {
        clear();
    }

protected:
    node* root;

    bool insertRecursive(node* &current_node, const int &val);

    void fixInsertion(node* current_node);

    void leftRotate(node* current_node);

    void rightRotate(node* current_node);

    void printRecursive(node* current_node) const;

    bool removeRecursive(node* current_node, const int &val);

    void clearRecursive(node* current_node);

    node* uncle(node* current_node);

    node* grparent(node* current_node);

    void insertion_case1(node* current_node);

    void insertion_case2(node* current_node);

    void insertion_case3(node* current_node);

    void insertion_case4(node* current_node);

    void insertion_case5(node* current_node);

    void remove_case1(node* current_node);

    void remove_case2(node* current_node);

    void remove_case3(node* current_node);

    void remove_case4(node* current_node);

    void remove_case5(node* current_node);

    void remove_case6(node* current_node);

    node* min(node* current_node) const;

    node* max(node* current_node) const;
};
