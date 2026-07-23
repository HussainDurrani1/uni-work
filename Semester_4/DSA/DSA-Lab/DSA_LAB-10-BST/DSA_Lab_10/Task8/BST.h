#pragma once
#include "BNode.h"

template <typename T>
class BST {
private:
    BNode<T>* insertRec(BNode<T>* node, T value) {
        if (node == nullptr) return new BNode<T>(value);
        if (value < node->data)
            node->left = insertRec(node->left, value);
        else
            node->right = insertRec(node->right, value);
        return node;
    }

public:
    BNode<T>* root;

    BST() : root(nullptr) {}

    void insert(T value) {
        root = insertRec(root, value);
    }

    // Iterative search: traverse left/right based on comparison
    bool search_iter(T val) {
        BNode<T>* curr = root;
        while (curr != nullptr) {
            if (val == curr->data)
                return true;
            else if (val < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return false;
    }

    // Recursive search: base case null = not found, match = found
    bool search_rec(BNode<T>* curr, T val) {
        if (curr == nullptr)
            return false;
        if (val == curr->data)
            return true;
        if (val < curr->data)
            return search_rec(curr->left, val);
        return search_rec(curr->right, val);
    }
};
