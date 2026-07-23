#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

int main() {
    Queue<string> q(10);
    string command, docName;

    while (true) {
        cout << "Enter command (ADD / PRINT / EXIT): ";
        cin >> command;

        if (command == "ADD") {
            if (q.isFull()) {
                cout << "Queue is full. Cannot add." << endl;
            }
            else {
                cout << "Enter document name: ";
                cin >> docName;
                q.Enqueue(docName);
            }
        }
        else if (command == "PRINT") {
            if (q.isEmpty()) {
                cout << "No documents in queue." << endl;
            }
            else {
                cout << "Printing: " << q.Dequeue() << endl;
            }
        }
        else if (command == "EXIT") {
            break;
        }
    }
    return 0;
}