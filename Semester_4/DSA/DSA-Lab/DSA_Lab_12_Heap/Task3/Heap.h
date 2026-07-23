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

    // Check if value already in heap
    bool contains(int val) {
        for (int i = 1; i <= n; i++)
            if (arr[i] == val) return true;
        return false;
    }

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

    // Min-Heap insert + heapify-up
    // Min-Heap property: parent <= child  ->  swap while arr[i] < arr[p]
    void insert(int val) {
        if (n >= size) { cout << "Heap is full!" << endl; return; }

        if (contains(val)) {
            cout << "Duplicate value " << val << " skipped." << endl;
            return;
        }

        ++n;
        arr[n] = val;
        int i = n;
        int p = i / 2;
        while (p > 0 && arr[i] < arr[p]) {   // < instead of > for Min-Heap
            swapInts(&arr[i], &arr[p]);
            i = p;
            p = i / 2;
        }
    }

    int getSize() { return n; }
};
