#include <iostream>
using namespace std;
#include "Heap.h"

int main() {
    int s;
    cout << "Enter heap capacity (max 15): ";
    cin >> s;
    if (s > 15) s = 15;

    Heap heap(s);

    int n;
    cout << "How many elements to insert? ";
    cin >> n;
    if (n > s) n = s;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        heap.insert(val);
    }

    cout << "\nInitial heap:" << endl;
    heap.print();

    cout << "\nExtracting all elements (largest first):" << endl;
    while (heap.getSize() > 0) {
        int extracted = heap.deleteNode();
        cout << "  Extracted: " << extracted << "  -->  ";
        heap.print();
    }

    return 0;
}
