#include <iostream>
using namespace std;

// Recursive function to count digits in a number
int countDigits(int n) {
    if (n < 0) n = -n; 	// To handle -ve nums

    if (n == 0) return 0;	// Base Case

    // Remove one digit (divide by 10) & count the rest
    return 1 + countDigits(n / 10);
}

int main() {
    cout << "countDigits(12345) = " << countDigits(12345) << endl;  // Expected: 5
    cout << "countDigits(9)     = " << countDigits(9)     << endl;  // Expected: 1
    cout << "countDigits(1000)  = " << countDigits(1000)  << endl;  // Expected: 4
    cout << "countDigits(7)     = " << countDigits(7)     << endl;  // Expected: 1
    return 0;
}