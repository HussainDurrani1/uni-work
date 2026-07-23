#include <iostream>
using namespace std;
#include "Heap.h"

int main() {
    int n;
    cout << "How many elements (max 15)? ";
    cin >> n;
    if (n > 15) n = 15;

    int arr[15];
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Array:" << endl;
    cout << "[ ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "]" << endl << endl;

    Heap heap(arr, n);
    heap.sort();

    return 0;
}
