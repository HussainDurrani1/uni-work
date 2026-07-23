#pragma once
#include <iostream>
using namespace std;

void swapInts(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

class Heap {
    int* arr;   // points to external array (0-indexed for in-place sort)
    int n;      // current heap size

    // Heapify-down on 0-indexed array of given heap size
    // Needed for in-place sort where we work on the user's array directly
    void heapifyDown(int heapSize, int i) {
        int largest = i;
        int left    = 2 * i + 1;
        int right   = 2 * i + 2;

        if (left  < heapSize && arr[left]  > arr[largest]) largest = left;
        if (right < heapSize && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            swapInts(&arr[i], &arr[largest]);
            heapifyDown(heapSize, largest);
        }
    }

public:
    // Takes the user's array and its size -- operates in-place, no extra memory
    Heap(int* a, int s) : arr(a), n(s) {}

    void print(int count) {
        cout << "[ ";
        for (int i = 0; i < count; i++)
            cout << arr[i] << " ";
        cout << "]" << endl;
    }

    void sort() {
        // Phase 1: Build Max-Heap in-place
        // Start from last internal node (n/2 - 1) down to root
        for (int i = n / 2 - 1; i >= 0; i--)
            heapifyDown(n, i);

        cout << "After building Max-Heap:" << endl;
        print(n);

        // Phase 2: Repeatedly extract max to end, shrink heap
        for (int i = n - 1; i > 0; i--) {
            swapInts(&arr[0], &arr[i]);   // move current max to sorted end
            heapifyDown(i, 0);            // restore heap on reduced array
        }

        cout << "Final Sorted Array:" << endl;
        print(n);
    }
};
