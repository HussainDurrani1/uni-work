#pragma once
#include "BNode.h"

template <typename T>
class BST {
private:
    BNode<T>* insertRec(BNode<T>* node, T value) {
        if (node == nullptr) {
            return new BNode<T>(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

public:
    BNode<T>* root;

    BST() : root(nullptr) {}

    void insertIterative(T value) {
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
