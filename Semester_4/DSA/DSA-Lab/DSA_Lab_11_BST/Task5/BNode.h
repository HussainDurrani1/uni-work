#pragma once

template <typename T>
class BNode {
public:
    T data;
    BNode<T>* left;
    BNode<T>* right;

    BNode(T value) : data(value), left(nullptr), right(nullptr) {}
};
