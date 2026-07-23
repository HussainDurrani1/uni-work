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

    cout << "Enter " << n << " values one by one:" << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cout << "  Insert: ";
        cin >> val;
        heap.insert(val);
        heap.print();
    }

    return 0;
}