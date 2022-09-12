#include "SplayTree.h"
#include <iostream>

void SplayTree::print() const
{
    if (root == nullptr) {
        std::cout << "empty\n";
        return;
    }
    printRecursive(root);
    std::cout << '\n';
}

void SplayTree::printRecursive(node* current_node) const
{
    if (current_node == nullptr) {
        return;
    }

    printRecursive(current_node->left);
    std::cout << current_node->value << ' ';
    printRecursive(current_node->right);
}

void SplayTree::clear()
{
    clearRecursive(root);
    root = nullptr;
}

void SplayTree::clearRecursive(node* current_node)
{
    if (current_node == nullptr) return;
    clearRecursive(current_node->left);
    clearRecursive(current_node->right);
    delete (current_node);
}

bool SplayTree::insert(int val)
{
    if (root == nullptr) {
        root = new node(val);
        return true;
    }
    return insertRecursive(root, val);
}

bool SplayTree::insertRecursive(node* &current_node, const int& val)
{
    if (current_node->value == val) {
        return false;
    } else if (current_node->value > val) {
        if (current_node->left == nullptr) {
            node* new_node = new node(val);
            current_node->left = new_node;
            new_node->parent = current_node;
            new_node = splay(new_node);
            return true;
        }
        return insertRecursive(current_node->left, val);

    } else {
        if (current_node->right == nullptr) {
            node* new_node = new node(val);
            current_node->right = new_node;
            new_node->parent = current_node;
            new_node =splay(new_node);
            return true;
        }
        return insertRecursive(current_node->right, val);
    }
}

SplayTree::node* SplayTree::splay(node* current_node)
{
    if (current_node->parent == nullptr) return current_node;
    if (current_node->parent->parent == nullptr) {
        current_node = zig(current_node);
    } else {
        node* parent = current_node->parent;
        node* grparent = current_node->parent->parent;
        if ((parent->left == current_node && grparent->left == parent)
            || (parent->right == current_node && grparent->right == parent)) {
            current_node = zigzig(current_node);
            current_node = splay(current_node);
        } else {
            current_node = zigzag(current_node);
            current_node = splay(current_node);
        }
    }
    return current_node;
}

SplayTree::node* SplayTree::zig(node* current_node)
{
    node* parent = current_node->parent;
    current_node->parent = nullptr;
    root = current_node;
    parent->parent = current_node;

    if (parent->left == current_node) {
        parent->left = current_node->right;
        if (parent->left != nullptr)
            parent->left->parent = parent;
        current_node->right = parent;
        
    } else {
        parent->right = current_node->left;
        if (parent->right != nullptr)
            parent->right->parent = parent;
        current_node->left = parent;
    }
    return current_node;
}

SplayTree::node* SplayTree::zigzig(node* current_node)
{
    node* parent = current_node->parent;
    node* grparent = current_node->parent->parent;
    if (grparent == root) root = current_node;
    current_node->parent = grparent->parent;

    if (current_node->parent != nullptr) {
        if (current_node->parent->left == grparent) {
            current_node->parent->left = current_node;
        } else {
            current_node->parent->right = current_node;
        }
    }
    if (parent->left == current_node && grparent->left == parent) {
        parent->left = current_node->right;
        if (parent->left != nullptr) {
            parent->left->parent = parent;
        }
        current_node->right = parent;
        current_node->right->parent = current_node;
        grparent->left = parent->right;
        if (grparent->left != nullptr) {
            grparent->left->parent = grparent;
        }
        parent->right = grparent;
        grparent->parent = parent;

    } else {
        parent->right = current_node->left;
        if (parent->right != nullptr) {
            parent->right->parent = parent;
        }
        current_node->left = parent;
        current_node->left->parent = current_node;
        grparent->right = parent->left;
        if (grparent->right != nullptr) {
            grparent->right->parent = grparent;
        }
        parent->left = grparent;
        grparent->parent = parent;
    }

    return current_node;
}

SplayTree::node* SplayTree::zigzag(node* current_node)
{
    node* parent = current_node->parent;
    node* grparent = current_node->parent->parent;
    if (grparent == root) root = current_node;
    current_node->parent = grparent->parent;  
    
    if (current_node->parent != nullptr) {
        if (current_node->parent->left == grparent) {
            current_node->parent->left = current_node;
        } else {
            current_node->parent->right = current_node;
        }
    }
    if (parent->right == current_node) {
        parent->right = current_node->left;
        if (parent->right != nullptr) {
            parent->right->parent = parent;
        }
        grparent->left = current_node->right;
        if (grparent->left != nullptr) {
            grparent->left->parent = grparent;
        }
        current_node->left = parent;
        current_node->left->parent = current_node;
        current_node->right = grparent;
        current_node->right->parent = current_node;

    } else {
        parent->left = current_node->right;
        if (parent->left != nullptr) {
            parent->left->parent = parent;
        }
        grparent->right = current_node->left;
        if (grparent->right != nullptr) {
            grparent->right->parent = grparent;
        }
        current_node->right = parent;
        current_node->right->parent = current_node;
        current_node->left = grparent;
        current_node->left->parent = current_node;
    }

    return current_node;
}

bool SplayTree::remove(int val)
{
    if (root == nullptr) return false;
    return removeRecursive(root, val);
}

SplayTree::node *SplayTree::getRoot() const
{
    return this->root;
}

bool SplayTree::removeRecursive(node* current_node, const int &val)
{
    if (current_node == nullptr) {
        return false;
    }

    if (current_node->value == val) {
        current_node = splay(current_node);
        node* left_subtree = current_node->left;
        node* right_subtree = current_node->right;
        current_node->left = nullptr;
        current_node->right = nullptr;
        if (left_subtree != nullptr) left_subtree->parent = nullptr;
        if (right_subtree != nullptr) right_subtree->parent = nullptr;        
        delete (current_node);
        root = merge(left_subtree, right_subtree);
        return true;
        
    } else if (current_node->value > val) {
        return removeRecursive(current_node->left, val);
    } else {
        return removeRecursive(current_node->right, val);
    }
}

SplayTree::node* SplayTree::min(node* current_node) const
{
    if (current_node == nullptr) return nullptr;
    if (current_node->left == nullptr) return current_node;
    return min(current_node->left);
}

SplayTree::node* SplayTree::max(node* current_node) const
{
    if (current_node == nullptr) return nullptr;
    if (current_node->right == nullptr) return current_node;
    return max(current_node->right);
}

SplayTree::node* SplayTree::merge(node* left_tree, node* right_tree)
{
    if (left_tree == nullptr) return right_tree;
    if (right_tree == nullptr) return left_tree;
    node* new_root = max(left_tree);
    new_root = splay(new_root);
    new_root->right = right_tree;
    right_tree->parent = new_root;
    return new_root;
}
