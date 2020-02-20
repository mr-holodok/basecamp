/*
 *  binary_tree.h
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 *  Binary Tree header and source file
 *
 */

#ifndef BINARYTREE_BINARY_TREE_H
#define BINARYTREE_BINARY_TREE_H

template<typename T>
class BTree {

    struct BTreeNode {
        BTreeNode *left, *right;
        T data;

        explicit BTreeNode(T value) : data{value}, left{nullptr}, right{nullptr} {};
    };

    BTreeNode *root;

    void print(BTreeNode *node);

    void delete_tree(BTreeNode *node);

public:
    BTree();

    ~BTree();

    void add(T value);

    void print();
    
    bool is_present(T val); // find function
};

template<typename T>
BTree<T>::BTree() : root{nullptr} {}

template<typename T>
BTree<T>::~BTree() {
    delete_tree(root);
}

template<typename T>
void BTree<T>::add(T value) {
    if (!root) {
        root = new BTreeNode(value);
        return;
    }

    BTreeNode *current = root;
    while (current != nullptr) {
        if (value < current->data) {
            if (!current->left) {
                current->left = new BTreeNode(value);
                return;
            }
            current = current->left;
        } else if (value > current->data) {
            if (!current->right) {
                current->right = new BTreeNode(value);
                return;
            }
            current = current->right;
        } else // equal
            return;
    }
}

template<typename T>
void BTree<T>::print() {
    print(root);
}

template<typename T>
void BTree<T>::print(BTreeNode *node) {
    if (node != NULL) {
        print(node->left);
        std::cout << node->data << " ";
        print(node->right);
    }
}

template<typename T>
void BTree<T>::delete_tree(BTree::BTreeNode *node) {
    if (node != nullptr) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

template <typename T>
bool BTree<T>::is_present(T val)
{
    BTreeNode *current = root;

    while(current != nullptr) {
        if (current->data == val)
            return true;
        else if (val > current->data && current->right != nullptr)
            current = current->right;
        else if (val < current->data && current->left != nullptr)
            current = current->left;
        else
            current = nullptr;
    }

    return false;
}

#endif //BINARYTREE_BINARY_TREE_H
