#include "Stack.h"

int main() {
    Stack<string> backStack(20);
    Stack<string> forwardStack(20);
    string currentPage = "";

    string command, url;

    while (true) {
        cout << "\nEnter command (VISIT, BACK, FORWARD, EXIT): ";
        cin >> command;

        if (command == "VISIT") {
            cout << "Enter URL to visit: ";
            cin >> url;

            if (currentPage != "") {
                backStack.push(currentPage);
            }
            currentPage = url;

            while (!forwardStack.isEmpty()) {
                forwardStack.pop();
            }
            cout << "Current: " << currentPage << endl;
        }
        else if (command == "BACK") {
            if (backStack.isEmpty()) {
                cout << "Nothing to go back to." << endl;
            }
            else {
                forwardStack.push(currentPage);
                currentPage = backStack.pop();
                cout << "Current: " << currentPage << endl;
            }
        }
        else if (command == "FORWARD") {
            if (forwardStack.isEmpty()) {
                cout << "Nothing to go forward to." << endl;
            }
            else {
                backStack.push(currentPage);
                currentPage = forwardStack.pop();
                cout << "Current: " << currentPage << endl;
            }
        }
        else if (command == "EXIT") {
            break;
        }
    }

    return 0;
}