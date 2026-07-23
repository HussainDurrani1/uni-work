#pragma once
#include <iostream>
using namespace std;

// Free swap using pointers
void swapInts(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

class Heap {
    int* arr;
    int size;   // capacity
    int n;      // current count of elements

public:
    // 1-indexed heap: valid indices are 1..n
    // Allocate size+1 so index 'size' is valid
    Heap(int s) : size(s), n(0) {
        arr = new int[s + 1];
    }

    ~Heap() {
        delete[] arr;
    }

    void print() {
        cout << "Heap: [ ";
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " ";
        cout << "]" << endl;
    }

    // Insert + heapify-up (Max-Heap: parent >= child)
    // Parent of node i = i/2
    void insert(int val) {
        if (n >= size) {
            cout << "Heap is full!" << endl;
            return;
        }
        ++n;
        arr[n] = val;
        int i = n;
        int p = i / 2;
        while (p > 0 && arr[i] > arr[p]) {
            swapInts(&arr[i], &arr[p]);
            i = p;
            p = i / 2;
        }
    }

    int getSize() { return n; }
};
