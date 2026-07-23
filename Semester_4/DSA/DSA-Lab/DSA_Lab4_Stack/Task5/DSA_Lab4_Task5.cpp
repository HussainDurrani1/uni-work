#include "stack.h"

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

string infixToPostfix(string exp) {
    Stack<char> s(exp.length());
    string result = "";

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            result += ch;
        }
        else if (isOperator(ch)) {
            while (!s.isEmpty() && getPrecedence(s.returnTop()) >= getPrecedence(ch)) {
                result += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.isEmpty()) {
        result += s.pop();
    }

    return result;
}

int main() {
    string exp = "A+B*C";

    cout << "Infix: " << exp << endl;
    cout << "Postfix: " << infixToPostfix(exp) << endl;

    return 0;
}