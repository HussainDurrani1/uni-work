#include "stack.h"

string reverseString(string str) {
    Stack<char> s(str.length());

    for (int i = 0; i < str.length(); i++) { s.push(str[i]); }

    string reversed = "";

    while (!s.isEmpty())  reversed += s.pop();

    return reversed;
}

void checkPalindrome(string str) {
    string reversed = reverseString(str);

    if (str == reversed) cout << "Palindrome\n";
    else cout << "Not Palindrome\n";
}

int main() {
    string test = "hello";

    cout << "Original: " << test << endl;
    cout << "Reversed: " << reverseString(test) << endl;

    string input;
    cout << "\nEnter a word: ";
    cin >> input;

    checkPalindrome(input);

    return 0;
}