#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    int n = 5;
    int arr[5] = { 10, 20, 30, 40, 50 };
    Queue<int> q(10);

    cout << "Original array : ";
    for (int i = 0; i < n; i++) cout << arr[i] << "  ";

    cout << "\nEnqueuing: ";
    for (int i = 0; i < n; i++) {
        q.Enqueue(arr[i]);
        cout << arr[i] << (i == n - 1 ? "" : " -> ");
    }

    cout << "\nDequeuing into array from index 4 to 0...";
    for (int i = n - 1; i >= 0; i--) { arr[i] = q.Dequeue(); }

    cout << "\nReversed array : ";
    for (int i = 0; i < n; i++) { cout << arr[i] << "  "; }
    cout << endl;

    return 0;
}