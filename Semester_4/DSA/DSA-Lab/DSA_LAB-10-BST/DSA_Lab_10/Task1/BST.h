#pragma once
#include "BNode.h"

template <typename T>
class BST {
public:
    BNode<T>* root;

    BST() : root(nullptr) {}
};
