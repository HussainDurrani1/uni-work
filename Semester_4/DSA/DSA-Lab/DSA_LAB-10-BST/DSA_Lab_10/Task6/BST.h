#pragma once
#include <iostream>
using namespace std;
#include "BNode.h"
#include "Stack.h"

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

    // Iterative Inorder: Left -> Root -> Right
    // Go as far left as possible pushing onto stack,
    // then pop, print, move right and repeat
    void inorder_iter() {
        Stack<BNode<T>*> s;
        BNode<T>* curr = root;

        while (curr != nullptr || !s.isEmpty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
        cout << endl;
    }

    // Iterative Preorder: Root -> Left -> Right
    // Push root, pop and print, push right then left
    void preorder_iter() {
        if (root == nullptr) return;

        Stack<BNode<T>*> s;
        s.push(root);

        while (!s.isEmpty()) {
            BNode<T>* curr = s.pop();
            cout << curr->data << " ";

            if (curr->right != nullptr) s.push(curr->right);
            if (curr->left != nullptr)  s.push(curr->left);
        }
        cout << endl;
    }
};
