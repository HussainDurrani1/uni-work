#pragma once
#include "BNode.h"

template <typename T>
class BST {
public:
    BNode<T>* root;

    BST() : root(nullptr) {}

    void insert(T value) {
        BNode<T>* newNode = new BNode<T>(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        BNode<T>* curr = root;
        while (true) {
            if (value < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    return;
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                }
                curr = curr->right;
            }
        }
    }
};
