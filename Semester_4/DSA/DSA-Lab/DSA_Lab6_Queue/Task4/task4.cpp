#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    int arr[] = { 101, 102, 103, 102, 104 };
    Queue<int> mainQ(10), helperQ(10);

    cout << "Array: 101  102  103  102  104" << endl;

    for (int i = 0; i < 5; i++) {
        int rollNumber = arr[i];
        bool found = false;

        while (!mainQ.isEmpty()) {
            int val = mainQ.Dequeue();
            if (val == rollNumber) found = true;
            helperQ.Enqueue(val);
        }

        while (!helperQ.isEmpty()) {
            mainQ.Enqueue(helperQ.Dequeue());
        }

        if (found) {
            cout << "Checking " << rollNumber << " ... DUPLICATE FOUND!" << endl;
        }
        else {
            mainQ.Enqueue(rollNumber);
            cout << "Checking " << rollNumber << " ... Added." << endl;
        }
    }

    return 0;
}