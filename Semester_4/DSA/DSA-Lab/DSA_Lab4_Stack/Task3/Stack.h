#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    int size;
    int top;
    T* arr;

public:
    Stack(int s) : size(s), top(-1) {
        arr = new T[size];
    }

    bool isEmpty() { return (top == -1); }

    void push(T value) {
        if (top < size - 1) {
            arr[++top] = value;
        }
    }

    T pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return '\0';
    }
};