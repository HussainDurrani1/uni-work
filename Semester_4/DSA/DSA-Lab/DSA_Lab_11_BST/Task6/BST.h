#pragma once
#include <iostream>
using namespace std;
#include "BNode.h"

// No <climits> allowed — use nullptr as "no bound" sentinel instead.
// min_node/max_node are pointers; nullptr means unbounded on that side.

template <typename T>
class BST {
private:
    BNode<T>* insertRec(BNode<T>* node, T value) {
        if (node == nullptr) return new BNode<T>(value);
        if (value < node->data) node->left  = insertRec(node->left,  value);
        else                    node->right = insertRec(node->right, value);
        return node;
    }

    bool is_valid_BST(BNode<T>* curr, BNode<T>* min_node, BNode<T>* max_node) {
        if (curr == nullptr) return true;
        if (min_node != nullptr && curr->data <= min_node->data) return false;
        if (max_node != nullptr && curr->data >= max_node->data) return false;
        return is_valid_BST(curr->left,  min_node, curr)
            && is_valid_BST(curr->right, curr,     max_node);
    }

public:
    BNode<T>* root;
    BST() : root(nullptr) {}

    void insert(T value) { root = insertRec(root, value); }
    void setRoot(BNode<T>* node) { root = node; }

    bool is_valid_BST() { return is_valid_BST(root, nullptr, nullptr); }

    void inorder(BNode<T>* curr) {
        if (curr == nullptr) return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
};
