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

    // Swap left and right children at every node recursively
    // After mirroring: inorder traversal gives values in DESCENDING order
    void mirror(BNode<T>* curr) {
        if (curr == nullptr) return;

        // Swap left and right
        BNode<T>* temp = curr->left;
        curr->left  = curr->right;
        curr->right = temp;

        // Recurse on both subtrees
        mirror(curr->left);
        mirror(curr->right);
    }

    // Inorder to verify the effect of mirroring
    void inorder(BNode<T>* curr) {
        if (curr == nullptr) return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
};
