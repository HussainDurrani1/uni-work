#pragma once

template <typename T>
class Stack {
private:
    struct SNode {
        T data;
        SNode* next;
        SNode(T val) : data(val), next(nullptr) {}
    };

    SNode* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty()) pop();
    }

    void push(T value) {
        SNode* newNode = new SNode(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    T pop() {
        if (isEmpty()) return T();
        SNode* temp = top;
        T val = temp->data;
        top = top->next;
        delete temp;
        size--;
        return val;
    }

    T peek() {
        if (!isEmpty()) return top->data;
        return T();
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getSize() {
        return size;
    }
};
