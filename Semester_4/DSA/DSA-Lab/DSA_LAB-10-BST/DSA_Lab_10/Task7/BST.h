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

    // Iterative Postorder using two stacks:
    // Stack1: push root, pop into stack2 while pushing left then right to stack1
    // Stack2 collects results in reverse postorder — print at the end
    void postorder_iter() {
        if (root == nullptr) return;

        Stack<BNode<T>*> stack1;
        Stack<BNode<T>*> stack2;

        stack1.push(root);

        while (!stack1.isEmpty()) {
            BNode<T>* curr = stack1.pop();
            stack2.push(curr);

            if (curr->left != nullptr)  stack1.push(curr->left);
            if (curr->right != nullptr) stack1.push(curr->right);
        }

        while (!stack2.isEmpty()) {
            cout << stack2.pop()->data << " ";
        }
        cout << endl;
    }
};
