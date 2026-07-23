#include <iostream>
using namespace std;

// Recursive function to return the nth Fibonacci number (0-indexed)
int fibonacci(int n) {
    // Base Cases:
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // fib(n) = fib(n-1) + fib(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);	
}

int main() {
    cout << "fibonacci(0)  = " << fibonacci(0)  << endl;  // Expected: 0
    cout << "fibonacci(1)  = " << fibonacci(1)  << endl;  // Expected: 1
    cout << "fibonacci(5)  = " << fibonacci(5)  << endl;  // Expected: 5
    cout << "fibonacci(6)  = " << fibonacci(6)  << endl;  // Expected: 8
    cout << "fibonacci(10) = " << fibonacci(10) << endl;  // Expected: 55
    return 0;
}