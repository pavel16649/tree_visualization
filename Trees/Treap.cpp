#include "Treap.h"
#include <iostream>

void Treap::print() const
{
	printRecursive(root);
	std::cout << '\n';
}

void Treap::printRecursive(node* current_node) const
{
    if (current_node == nullptr) {
        std::cout << "empty\n";
        return;
    }

    printRecursive(current_node->left);
    std::cout << current_node->value << ' ';
    printRecursive(current_node->right);
}

Treap::node* Treap::merge(node* first, node* second)
{
    if (first == nullptr) return second;
    if (second == nullptr) return first;
    if (first->priority > second->priority) {
        first->right = merge(first->right, second);
        return first;
    } else {
        second->left = merge(first, second->left);
        return second;
    }
}
Treap::ret Treap::split(node* current_node, const int& val) {
    if (current_node == nullptr) {
        ret res;
        res.gr = nullptr;
        res.eq = nullptr;
        res.less = nullptr;
        return res;
    }

    if (current_node->value < val) {
        ret res = split(current_node->right, val);
        current_node->right = res.less;
        res.less = current_node;
        return res;

    } else if (current_node->value > val) {
        ret res = split(current_node->left, val);
        current_node->left = res.gr;
        res.gr = current_node;
        return res;

    } else {
        node* ll = current_node->left;
        node* rr = current_node->right;
        current_node->left = nullptr;
        current_node->right = nullptr;
        ret res;
        res.less = ll;
        res.gr = rr;
        res.eq = current_node;
        return res;
    }
}

bool Treap::insert(int val) {
    if (root == nullptr) {
        root = new node(val);
        return true;
    }

    ret sp = split(root, val);
    if (sp.eq != nullptr) {
        root = merge(merge(sp.less, sp.eq), sp.gr);
        return false;
    }

    node* New = new node(val);
    root = merge(merge(sp.less, New), sp.gr);
    return true;
}

bool Treap::remove(int val)
{
    ret sp = split(root, val);
    root = merge(sp.less, sp.gr);

    if (sp.eq == nullptr) return false;

    delete sp.eq;
    return true;
}

void Treap::clear()
{
    clearRecursive(root);
    root = nullptr;
}

Treap::node *Treap::getRoot() const
{
    return this->root;
}

void Treap::clearRecursive(node* current_node)
{
    if (current_node == nullptr) return;
    clearRecursive(current_node->left);
    clearRecursive(current_node->right);
    delete (current_node);
}
