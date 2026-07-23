#include "stack.h"

void decimalToBinary(int num) {
    Stack<int> s(100);

    if (num == 0) {
        cout << "Binary: 0\n";
        return;
    }

    while (num > 0) {
        int rem = num % 2;
        s.push(rem);
        num = num / 2;
    }

    cout << "Binary: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
}

int main()
{
    cout << "13 -> ";
    decimalToBinary(13);

    int n;
    cout << "\nEnter a positive integer: ";
    cin >> n;

    decimalToBinary(n);

    return 0;
}