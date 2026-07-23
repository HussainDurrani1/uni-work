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

    // BST property: smallest value is always at the leftmost node
    T find_min(BNode<T>* curr) {
        if (curr == nullptr) {
            cout << "Tree is empty!" << endl;
            return T();
        }
        while (curr->left != nullptr)
            curr = curr->left;
        return curr->data;
    }

    // BST property: largest value is always at the rightmost node
    T find_max(BNode<T>* curr) {
        if (curr == nullptr) {
            cout << "Tree is empty!" << endl;
            return T();
        }
        while (curr->right != nullptr)
            curr = curr->right;
        return curr->data;
    }

    void inorder(BNode<T>* curr) {
        if (curr == nullptr) return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
};
