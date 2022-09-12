#include "AVL.h"
#include <iostream>


char AVL::height(node* current_node) const
{
    return current_node ? current_node->height : 0;
}

char AVL::getBalance(node* current_node) const
{
    return height(current_node->left) - height(current_node->right);
}

void AVL::recalc_height(node* current_node)
{
    char left_height = height(current_node->left);
    char right_height = height(current_node->right);
    current_node->height = (left_height > right_height) ? (left_height + 1) : (right_height + 1);
    return;
}

bool AVL::insert(int val) 
{
    if (root == nullptr) {
        root = new node(val);
        return true;
    }

    return insertRecursive(root, val);
}

void AVL::doBalance(node* &current_node)
{
    char bal = getBalance(current_node);
    if (bal > 1) {
        node* lhs = current_node->left;
        if (getBalance(lhs) >= 0) {
            current_node->left = lhs->right;
            lhs->right = current_node;
            recalc_height(current_node);
            current_node = lhs;
            //std::cout << current_node->value << " 1s\n";
        }
        else {
            node* lhsr = lhs->right;
            current_node->left = lhsr->right;
            lhs->right = lhsr->left;
            lhsr->left = lhs;
            lhsr->right = current_node;
            recalc_height(lhs);
            recalc_height(current_node);
            current_node = lhsr;
            //std::cout << current_node->value << " 1b\n";
        }
    }
    else if (bal < -1) {
        node* rhs = current_node->right;
        if (getBalance(rhs) <= 0) {
            current_node->right = rhs->left;
            rhs->left = current_node;
            recalc_height(current_node);
            current_node = rhs;
            //std::cout << current_node->value << " -1s\n";
        }
        else {
            node* rhsl = rhs->left;
            current_node->right = rhsl->left;
            rhs->left = rhsl->right;
            rhsl->left = current_node;
            rhsl->right = rhs;
            recalc_height(rhs);
            recalc_height(current_node);
            current_node = rhsl;
            //std::cout << current_node->value << " -1b\n";
        }
    }
    recalc_height(current_node);
}

bool AVL::insertRecursive(node* &current_node, const int &val)
{
    if (current_node == nullptr) {
        node* new_node = new node(val);
        current_node = new_node;
        return true;
    }

    if (current_node->value == val) {
        return false;
    } else if (current_node->value > val) {
        if (!insertRecursive(current_node->left, val)) return false;
    } else {
        if (!insertRecursive(current_node->right, val)) return false;
    }

    doBalance(current_node);
    return true;
}

AVL::node* AVL::min(node* current_node) const
{
    if (current_node->left == nullptr) return current_node;
    return min(current_node->left);
}

AVL::node* AVL::max(node* current_node) const
{
    if (current_node->right == nullptr) return current_node;
    return min(current_node->right);
}

 AVL::node* AVL::removeRecursive(node* &current_node, const int &val)
{
    if (current_node == nullptr) return nullptr;
    if (val == current_node->value) {
        if (current_node->right != nullptr) {
            node* Min = min(current_node->right);
            current_node->value = Min->value;
            current_node->right = removeRecursive(current_node->right, Min->value);

        } else if (current_node->left != nullptr) {
            node* Max = max(current_node->left);
            current_node->value = Max->value;
            current_node->left = removeRecursive(current_node->left, Max->value);

        } else {
            if (current_node == root) {
                root = nullptr;
            }
            delete (current_node);
            return nullptr;
        }               

    } else if (val < current_node->value) {
        current_node->left = removeRecursive(current_node->left, val);
    } else if (val > current_node->value) {
        current_node->right = removeRecursive(current_node->right, val);
    }

    doBalance(current_node);

    return current_node;
}

bool AVL::remove(int val)
{
    if (root == nullptr) return false;
    removeRecursive(root, val);
    return true;
}

AVL::node* AVL::getRoot() const
{
    return this->root;
}

void AVL::print() const
{
    if (root == nullptr) {
        std::cout << "empty\n";
        return;
    }
    printRecursive(root);
    std::cout << '\n';
}

void AVL::printRecursive(node* current_node) const
{
    if (current_node == nullptr) {
        return;
    }

    printRecursive(current_node->left);
    std::cout << current_node->value << ' ';
    printRecursive(current_node->right);
}

void AVL::clear()
{
    clearRecursive(root);
    root = nullptr;
}

void AVL::clearRecursive(node* current_node)
{
    if (current_node == nullptr) return;
    clearRecursive(current_node->left);
    clearRecursive(current_node->right);
    delete (current_node);
}
