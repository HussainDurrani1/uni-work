#include <iostream>
#include <string>
using namespace std;

// Recursive function to reverse a string
string reverseString(string s) {
    if (s.length() <= 1) return s;	// Base Case

    return reverseString(s.substr(1)) + s[0];	    // Reverse substring from index 1 onward, then append s[0] at the end
}

int main() {
    cout << "reverseString(\"hello\")   = " << reverseString("hello")   << endl;  // Expected: olleh
    cout << "reverseString(\"abcd\")    = " << reverseString("abcd")    << endl;  // Expected: dcba
    cout << "reverseString(\"a\")       = " << reverseString("a")       << endl;  // Expected: a
    cout << "reverseString(\"racecar\") = " << reverseString("racecar") << endl;  // Expected: racecar
    return 0;
}