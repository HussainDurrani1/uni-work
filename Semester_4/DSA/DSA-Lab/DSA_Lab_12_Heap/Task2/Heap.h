#pragma once
#include <iostream>
using namespace std;

void swapInts(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

class Heap {
    int* arr;
    int size;
    int n;

public:
    Heap(int s) : size(s), n(0) {
        arr = new int[s + 1];
    }

    ~Heap() {
        delete[] arr;
    }

    void print() {
        if (n == 0) { cout << "Heap: [ empty ]" << endl; return; }
        cout << "Heap: [ ";
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " ";
        cout << "]" << endl;
    }

    void insert(int val) {
        if (n >= size) { cout << "Heap is full!" << endl; return; }
        arr[++n] = val;
        int i = n;
        int p = i / 2;
        while (p > 0 && arr[i] > arr[p]) {
            swapInts(&arr[i], &arr[p]);
            i = p;
            p = i / 2;
        }
    }

    // Extract max: replace root with last element, heapify-down
    // FIX: bounds-check children before comparing — original crashes when
    //      a node has no children (i*2 > n) because arr[i*2] is uninitialized
    int deleteNode() {
        if (n == 0) { cout << "Heap is empty!" << endl; return -1; }

        int extracted = arr[1];
        arr[1] = arr[n--];

        int i = 1;
        while (true) {
            int left  = i * 2;
            int right = i * 2 + 1;
            int largest = i;

            // Only consider children that actually exist (index <= n)
            if (left  <= n && arr[left]  > arr[largest]) largest = left;
            if (right <= n && arr[right] > arr[largest]) largest = right;

            if (largest == i) break;   // heap property restored

            swapInts(&arr[i], &arr[largest]);
            i = largest;
        }

        return extracted;
    }

    int getSize() { return n; }
};
