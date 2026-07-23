#include <iostream>
using namespace std;

// Recursive function to compute sum of digits
int sumOfDigits(int n) {
    if (n < 0) n = -n;	// To handle -ve nums

    if (n == 0) return 0;	 // Base case

    return (n % 10) + sumOfDigits(n / 10);	// Last digit (n % 10) + sum of remaining digits (n / 10)
}

int main() {
    cout << "sumOfDigits(1234) = " << sumOfDigits(1234) << endl;  // Expected: 10
    cout << "sumOfDigits(567)  = " << sumOfDigits(567)  << endl;  // Expected: 18
    cout << "sumOfDigits(999)  = " << sumOfDigits(999)  << endl;  // Expected: 27
    cout << "sumOfDigits(100)  = " << sumOfDigits(100)  << endl;  // Expected: 1
    return 0;
}