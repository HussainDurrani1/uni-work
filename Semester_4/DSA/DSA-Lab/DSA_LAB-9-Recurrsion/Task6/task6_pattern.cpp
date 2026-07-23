#include <iostream>
using namespace std;

// Recursive function to print numbers 1 to row on a single line
void printRow(int row, int col) {
    // If col > row, print newline and return
    if (col > row) { cout << endl; return; }

    // Print current col, then recurse for next col
    cout << col << " ";
    printRow(row, col + 1);
}

// Recursive function to print the full pattern from row 1 to n
void printPattern(int n, int row) {
    // If row > n, stop
    if (row > n) return;

    // Print current row, then recurse for next row
    printRow(row, 1);
    printPattern(n, row + 1);
}

int main() {
    printPattern(5, 1);
    return 0;
}