#pragma once
#include <iostream>
using namespace std;
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

    // Left -> Root -> Right
    void inorder(BNode<T>* curr) {
        if (curr == nullptr) return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }

    // Root -> Left -> Right
    void preorder(BNode<T>* curr) {
        if (curr == nullptr) return;
        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }

    // Left -> Right -> Root
    void postorder(BNode<T>* curr) {
        if (curr == nullptr) return;
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }
};
