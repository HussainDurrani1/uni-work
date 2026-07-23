#pragma once
#include <iostream>
using namespace std;
#include "BNode.h"
#include "Queue.h"

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

    void breadthFirst() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        Queue<BNode<T>*> q;
        q.enqueue(root);

        while (!q.isEmpty()) {
            BNode<T>* curr = q.dequeue();
            cout << curr->data << " ";

            if (curr->left != nullptr)
                q.enqueue(curr->left);
            if (curr->right != nullptr)
                q.enqueue(curr->right);
        }
        cout << endl;
    }
};
