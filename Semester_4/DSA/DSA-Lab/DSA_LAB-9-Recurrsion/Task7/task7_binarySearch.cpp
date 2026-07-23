#include <iostream>
using namespace std;

// Recursive binary search — returns index of target, or -1 if not found
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    // Target Found
    if (arr[mid] == target) return mid;

    // Target is smaller — search left half
    if (target < arr[mid]) return binarySearch(arr, left, mid - 1, target);

    // Target is larger — search right half
    return binarySearch(arr, mid + 1, right, target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = 7;

    int idx;

    idx = binarySearch(arr, 0, n - 1, 7);
    cout << "binarySearch(arr, 7)  = " << (idx != -1 ? "Found at index " + to_string(idx) : "Not Found (-1)") << endl;

    idx = binarySearch(arr, 0, n - 1, 1);
    cout << "binarySearch(arr, 1)  = " << (idx != -1 ? "Found at index " + to_string(idx) : "Not Found (-1)") << endl;

    idx = binarySearch(arr, 0, n - 1, 13);
    cout << "binarySearch(arr, 13) = " << (idx != -1 ? "Found at index " + to_string(idx) : "Not Found (-1)") << endl;

    idx = binarySearch(arr, 0, n - 1, 4);
    cout << "binarySearch(arr, 4)  = " << (idx != -1 ? "Found at index " + to_string(idx) : "Not Found (-1)") << endl;

    return 0;
}