#pragma once

template <typename T>
class Queue {
private:
    struct QNode {
        T data;
        QNode* next;
        QNode(T val) : data(val), next(nullptr) {}
    };

    QNode* front;
    QNode* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) dequeue();
    }

    void enqueue(T value) {
        QNode* newNode = new QNode(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) return T();
        QNode* temp = front;
        T val = temp->data;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        size--;
        return val;
    }

    T peek() {
        if (!isEmpty()) return front->data;
        return T();
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int getSize() {
        return size;
    }
};
