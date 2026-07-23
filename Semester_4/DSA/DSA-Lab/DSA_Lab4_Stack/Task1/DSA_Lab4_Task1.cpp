#include "Stack.h"

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

void checkBalanced(string expression) {
    Stack<char> s(expression.length());

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        // If opening bracket -> push
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If closing bracket -> check
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                cout << "Not Balanced\n";
                return;
            }

            char top = s.pop();

            if (!isMatching(top, ch)) {
                cout << "Not Balanced\n";
                return;
            }
        }
    }

    if (s.isEmpty()) cout << "Balanced\n";
    else cout << "Not Balanced\n";
}

int main()
{
    cout << "Test Cases:\n";

    cout << "{[()]} -> ";
    checkBalanced("{[()]}");

    cout << "{[(]} -> ";
    checkBalanced("{[(]}");

    string input;
    cout << "\nEnter your expression: ";
    cin >> input;

    checkBalanced(input);

    return 0;
}