#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue {
private:
    int size;
    int front;
    int rear;
    int count;
    T* arr;
public:
    Queue(int s) {
        size = s;
        arr = new T[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() { delete[] arr; }

    bool isFull() { return count == size; }
    bool isEmpty() { return count == 0; }

    void Enqueue(T val) {
        if (!isFull()) {
            rear = (rear + 1) % size;
            arr[rear] = val;
            count++;
        }
    }

    T Dequeue() {
        if (!isEmpty()) {
            T val = arr[front];
            front = (front + 1) % size;
            count--;
            return val;
        }
        return T();
    }
};