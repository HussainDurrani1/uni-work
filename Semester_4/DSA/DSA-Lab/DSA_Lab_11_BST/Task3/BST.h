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

    // Returns the larger of two integers (avoids <algorithm>)
    int maxOf(int a, int b) {
        return (a > b) ? a : b;
    }

public:
    BNode<T>* root;
    BST() : root(nullptr) {}

    void insert(T value) { root = insertRec(root, value); }

    // Height = number of edges on longest root-to-leaf path
    // NULL  -> -1  (so a single node has height 0)
    // Leaf  ->  0
    // Other -> 1 + max(height(left), height(right))
    int height(BNode<T>* curr) {
        if (curr == nullptr) return -1;
        return 1 + maxOf(height(curr->left), height(curr->right));
    }

    void inorder(BNode<T>* curr) {
        if (curr == nullptr) return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
};
