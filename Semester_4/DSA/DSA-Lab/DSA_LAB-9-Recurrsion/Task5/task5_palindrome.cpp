#include <iostream>
#include <string>
using namespace std;

// Recursive function to check if s[start to end] is a palindrome
bool isPalindrome(string s, int start, int end) {
    // If start >= end, remaining part is a palindrome
    if (start >= end) return true;

    // Chars don't match = not a palindrome
    if (s[start] != s[end]) return false;

    // Check the inner substring
    return isPalindrome(s, start + 1, end - 1);
}

int main() {
    string s1 = "madam";
    string s2 = "hello";
    string s3 = "racecar";
    string s4 = "abcba";

    cout << "isPalindrome(\"madam\")   = " << isPalindrome(s1, 0, s1.length() - 1) << "  (true)"  << endl;
    cout << "isPalindrome(\"hello\")   = " << isPalindrome(s2, 0, s2.length() - 1) << "  (false)" << endl;
    cout << "isPalindrome(\"racecar\") = " << isPalindrome(s3, 0, s3.length() - 1) << "  (true)"  << endl;
    cout << "isPalindrome(\"abcba\")   = " << isPalindrome(s4, 0, s4.length() - 1) << "  (true)"  << endl;
    return 0;
}