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

    // Recursive: 3 cases — NULL (0), leaf (1), internal (recurse both sides)
    int count_leaves(BNode<T>* curr) {
        if (curr == nullptr) return 0;
        // A leaf has NO children
        if (curr->left == nullptr && curr->right == nullptr) return 1;
        return count_leaves(curr->left) + count_leaves(curr->right);
    }

    void inorder(BNode<T>* curr) {
        if (curr == nullptr) return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
};
