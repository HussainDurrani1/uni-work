#pragma once
#include <iostream>
using namespace std;
#include "BNode.h"

template <typename T>
class BST {
private:
    BNode<T>* insertRec(BNode<T>* node, T value) {
        if (node == nullptr) return new BNode<T>(value);
        if (value < node->data) node->left  = insertRec(node->left,  value);
        else                    node->right = insertRec(node->right, value);
        return node;
    }

public:
    BNode<T>* root;
    BST() : root(nullptr) {}

    void insert(T value) { root = insertRec(root, value); }

    // Lowest Common Ancestor using BST structural properties
    // Three rules at each node:
    //   1. Both values < curr  -> LCA is in left subtree  (go left)
    //   2. Both values > curr  -> LCA is in right subtree (go right)
    //   3. Values split OR one equals curr -> curr IS the LCA (return it)
    BNode<T>* LCA(BNode<T>* curr, T val1, T val2) {
        if (curr == nullptr) return nullptr;
        if (val1 < curr->data && val2 < curr->data)
            return LCA(curr->left, val1, val2);
        if (val1 > curr->data && val2 > curr->data)
            return LCA(curr->right, val1, val2);
        return curr;
    }

    void inorder(BNode<T>* curr) {
        if (curr == nullptr) return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
};
