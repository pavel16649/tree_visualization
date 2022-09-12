#include "RB_Tree.h"
#include <iostream>

void RB_Tree::clear()
{
    clearRecursive(root);
    root = nullptr;
}

void RB_Tree::clearRecursive(node* current_node)
{
    if (current_node == nullptr) return;
    clearRecursive(current_node->left);
    clearRecursive(current_node->right);
    delete (current_node);
}

RB_Tree::node* RB_Tree::uncle(RB_Tree::node *current_node)
{
    node* gr = grparent(current_node);
    if (gr == nullptr) {
        return nullptr;
    } else if (current_node->parent == gr->left) {
        return gr->right;
    } else {
        return gr->left;
    }
}

RB_Tree::node *RB_Tree::grparent(RB_Tree::node *current_node)
{
    if (current_node != nullptr && current_node->parent != nullptr) {
        return current_node->parent->parent;
    } else {
        return nullptr;
    }
}

void RB_Tree::insertion_case1(RB_Tree::node *current_node)
{
    if (current_node->parent == nullptr) {
        current_node->color = black;
        root = current_node;
    } else {
        insertion_case2(current_node);
    }
}

void RB_Tree::insertion_case2(RB_Tree::node *current_node)
{
    if (current_node->parent->color == black) {
        return;
    } else {
        insertion_case3(current_node);
    }
}

void RB_Tree::insertion_case3(RB_Tree::node *current_node)
{
    node* gr = grparent(current_node);
    node* un = uncle(current_node);

    if (un != nullptr && un->color == red) {
        current_node->parent->color = black;
        un->color = black;
        gr->color = red;
        insertion_case1(gr);
    } else {
        insertion_case4(current_node);
    }
}

void RB_Tree::insertion_case4(RB_Tree::node *current_node)
{
    node* gr = grparent(current_node);
    if (current_node == current_node->parent->right
            && current_node->parent == gr->left) {
        leftRotate(current_node->parent);
        current_node = current_node->left;
    } else if (current_node == current_node->parent->left
               && current_node->parent == gr->right) {
        rightRotate(current_node->parent);
        current_node = current_node->right;
    }
    insertion_case5(current_node);
}

void RB_Tree::insertion_case5(RB_Tree::node *current_node)
{
    node* gr = grparent(current_node);
    current_node->parent->color = black;
    gr->color = red;
    if (current_node->parent->left == current_node
            && current_node->parent == gr->left) {
        rightRotate(gr);
    } else {
       leftRotate(gr);
    }
}

RB_Tree::node* RB_Tree::min(node* current_node) const
{
    if (current_node->left == nullptr) return current_node;
    return min(current_node->left);
}

RB_Tree::node* RB_Tree::max(node* current_node) const
{
    if (current_node->right == nullptr) return current_node;
    return min(current_node->right);
}

void RB_Tree::print() const
{
    if (root == nullptr) {
        std::cout << "empty\n";
        return;
    }
    printRecursive(root);
    std::cout << '\n';
}

void RB_Tree::printRecursive(node* current_node) const
{
    if (current_node == nullptr) {
        return;
    }

    printRecursive(current_node->left);
    std::cout << current_node->value << ' ' << current_node->color << '\n';
    printRecursive(current_node->right);
}

bool RB_Tree::insert(int val)
{
    if (root == nullptr) {
        root = new node(val);
        root->color = black;
        return true;
    }

    return insertRecursive(root, val);
}

bool RB_Tree::insertRecursive(node* &current_node, const int &val)
{
    if (current_node->value == val) {
        return false;

    } else if (current_node->value > val) {
        if (current_node->left == nullptr) {
            node* new_node = new node(val);
            new_node->parent = current_node;
            current_node->left = new_node;
            insertion_case1(new_node);
            return true;
        }
        return insertRecursive(current_node->left, val);

    } else {
        if (current_node->right == nullptr) {
            node* new_node = new node(val);
            new_node->parent = current_node;
            current_node->right = new_node;
            insertion_case1(new_node);
            return true;
        }
        return insertRecursive(current_node->right, val);
    }
}

//void RB_Tree::fixInsertion(node* current_node)
//{
//    if (current_node == root) {
//        current_node->color = black;
//        return;
//    }

//    if (current_node->parent == root) return;

//    node* father = current_node->parent;
//    node* grfather = father->parent;
//    while (father->color == red) {
//        node* uncle;
//        if (father == grfather->left) {
//            uncle = grfather->right;
//            if (uncle == nullptr || uncle->color == black) {
//                if (current_node == father->right) {
//                    current_node = father;
//                    leftRotate(current_node);
//                }
//                father->color = black;
//                grfather->color = red;
//                rightRotate(grfather);
//            } else {
//                father->color = black;
//                uncle->color = black;
//                grfather->color = red;
//                current_node = grfather;
//            }
//        } else {
//            uncle = grfather->left;
//            if (uncle == nullptr || uncle->color == black) {
//                if (current_node == father->left) {
//                    current_node = father;
//                    rightRotate(current_node);
//                }
//                father->color = black;
//                grfather->color = red;
//                leftRotate(grfather);
//            } else {
//                father->color = black;
//                uncle->color = black;
//                grfather->color = red;
//                current_node = grfather;
//            }
//        }
//        father = current_node->parent;
//        if (father == nullptr) break;
//        grfather = father->parent;
//    }

//    root->color = black;
//}

void RB_Tree::leftRotate(node* current_node)
{
    node* rhs = current_node->right;  
    rhs->parent = current_node->parent;
    if (rhs->parent != nullptr) {
        if (rhs->parent->left == current_node) {
            rhs->parent->left = rhs;
        } else {
            rhs->parent->right = rhs;
        }
    } else {
        root = rhs;
    }
    current_node->right = rhs->left;
    if (current_node->right != nullptr)
        current_node->right->parent = current_node;
    current_node->parent = rhs;
    rhs->left = current_node;
    //current_node = rhs;
}

void RB_Tree::rightRotate(node* current_node)
{
    node* lhs = current_node->left;
    lhs->parent = current_node->parent;
    if (lhs->parent != nullptr) {
        if (lhs->parent->left == current_node) {
            lhs->parent->left = lhs;
        } else {
            lhs->parent->right = lhs;
        }
    } else {
        root = lhs;
    }
    current_node->left = lhs->right;
    if (current_node->left != nullptr)
        current_node->left->parent = current_node;
    current_node->parent = lhs;
    lhs->right = current_node;
    //current_node = lhs;
}

bool RB_Tree::remove(int val)
{
    if (root == nullptr) return false;

    bool ok = removeRecursive(root, val);
    if (root != nullptr) root->color = black;
    return ok;
}

RB_Tree::node *RB_Tree::getRoot() const
{
    return this->root;
}

bool RB_Tree::removeRecursive(node* current_node, const int& val)
{
    if (current_node == nullptr) return false;
    if (val == current_node->value) {
        if (current_node == root
                && current_node->left == nullptr && current_node->right == nullptr) {
            root = nullptr;
            delete (current_node);

        } else if (current_node->right != nullptr && current_node->left != nullptr) {
            node* Min = min(current_node->right);
            std::swap(current_node->value, Min->value);
            return removeRecursive(Min, val);

        } else {
            node* child = (current_node->left != nullptr)
                    ? current_node->left : current_node->right;
            bool flag = false;
            if (child == nullptr) {
                child = new node(-2000000000);
                child->color = black;
                flag = true;
            }
            child->parent = current_node->parent;
            if (current_node->parent != nullptr) {
                if (current_node->parent->left == current_node) {
                    current_node->parent->left = child;
                } else {
                    current_node->parent->right = child;
                }
            }

            if (current_node->color == black) {
                if (current_node == root) {
                    root = child;
                    if (flag) {
                        delete (child);
                    }
                } else if (child->color == red) {
                    child->color = black;
                } else {
                    remove_case1(child);
                    if (flag) {
                        if (child->parent->left == child) {
                            child->parent->left = nullptr;
                        } else {
                            child->parent->right = nullptr;
                        }
                        delete (child);
                    }
                }
            } else {
                if (child->parent->left == child) {
                    child->parent->left = nullptr;
                } else {
                    child->parent->right = nullptr;
                }
                delete (child);
            }
            delete (current_node);
        }       
        return true;

    } else if (val < current_node->value) {
        return removeRecursive(current_node->left, val);

    } else if (val > current_node->value) {
        return removeRecursive(current_node->right, val);
    }
}

void RB_Tree::remove_case1(node* current_node)
{
    if (current_node->parent == nullptr) {
        root = current_node;
        root->color = black;
    } else {
        remove_case2(current_node);
    }
}

void RB_Tree::remove_case2(node *current_node)
{
    node* father = current_node->parent;
    node* sister = (father->left == current_node)
        ? (father->right) : (father->left);

    if (sister != nullptr && sister->color == red) {
        father->color = red;
        sister->color = black;
        if (current_node == father->left) {
            leftRotate(father);
        } else {
            rightRotate(father);
        }
    }
    remove_case3(current_node);
}

void RB_Tree::remove_case3(RB_Tree::node *current_node)
{
    node* sister = (current_node->parent->left == current_node)
        ? (current_node->parent->right) : (current_node->parent->left);

    if (current_node->parent->color == black && sister->color == black
            && (sister->left == nullptr || sister->left->color == black)
            && (sister->right == nullptr || sister->right->color == black)) {
        sister->color = red;
        remove_case1(current_node->parent);
    } else {
        remove_case4(current_node);
    }
}

void RB_Tree::remove_case4(RB_Tree::node *current_node)
{
    node* sister = (current_node->parent->left == current_node)
        ? (current_node->parent->right) : (current_node->parent->left);

    if ((current_node->parent->color == red)
            && (sister->color == black)
            && (sister->left == nullptr || sister->left->color == black)
            && (sister->right == nullptr || sister->right->color == black)) {
        sister->color = red;
        current_node->parent->color = black;
    } else {
        remove_case5(current_node);
    }
}

void RB_Tree::remove_case5(RB_Tree::node *current_node)
{
    node* sister = (current_node->parent->left == current_node)
        ? (current_node->parent->right) : (current_node->parent->left);

    if (sister->color == black) {
        if (current_node == current_node->parent->left
                && (sister->left != nullptr && sister->left->color == red)
                && (sister->right == nullptr || sister->right->color == black)) {
            rightRotate(sister);
        } else if (current_node== current_node->parent->right
                   && (sister->left == nullptr || sister->left->color == black)
                   && (sister->right != nullptr && sister->right->color == red)) {
            leftRotate(sister);
        }
    }
    remove_case6(current_node);
}

void RB_Tree::remove_case6(RB_Tree::node *current_node)
{
    node* sister = (current_node->parent->left == current_node)
        ? (current_node->parent->right) : (current_node->parent->left);

    sister->color = current_node->parent->color;
    current_node->parent->color = black;

    if (current_node == current_node->parent->left) {
        sister->right->color = black;
        leftRotate(current_node->parent);
    } else {
        sister->left->color = black;
        rightRotate(current_node->parent);
    }
}
