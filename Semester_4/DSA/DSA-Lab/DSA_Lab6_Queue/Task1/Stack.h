#pragma once
#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    int size;
    int top;
    T* arr;
public:
    Stack(int s) {
        size = s;
        arr = new T[size];
        top = -1;
    }

    ~Stack() { delete[] arr; }

    void push(T val) {
        if (top < size - 1) arr[++top] = val;
    }

    T pop() {
        if (top >= 0) return arr[top--];
        return T();
    }

    bool isEmpty() { return top == -1; }
};