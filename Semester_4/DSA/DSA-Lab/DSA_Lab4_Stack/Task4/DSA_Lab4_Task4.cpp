#include "stack.h"

void sortStack(Stack<int>& s, int n) {
    Stack<int> temp(n);

    while (!s.isEmpty()) {
        int x = s.pop();

        while (!temp.isEmpty() && temp.returnTop() > x) {
            s.push(temp.pop());
        }
        temp.push(x);
    }

    while (!temp.isEmpty()) {
        s.push(temp.pop());
    }
}

int main() {
    Stack<int> s(10);

    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    sortStack(s, 10);

    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }

    return 0;
}