#include <iostream>
#include "Rectangle.h"
#include "Calculator.h"

using namespace std;

Rectangle::Rectangle(int l, int w) : length(l), width(w) {}

int calculateArea(const Rectangle& r) {
    return r.length * r.width;
}

int Calculator::area(const Rectangle& r) {
    return r.length * r.width;
}

int main() {
    int inputLength, inputWidth;

    cout << "Enter the length of the rectangle: ";
    cin >> inputLength;

    cout << "Enter the width of the rectangle: ";
    cin >> inputWidth;

    Rectangle rect(inputLength, inputWidth);

    cout << "--- Friend Function Demo ---" << endl;
    int area1 = calculateArea(rect);
    cout << "Area calculated by standalone friend function: " << area1 << endl;

    cout << "--- Friend Class Demo ---" << endl;
    Calculator calc;
    int area2 = calc.area(rect);
    cout << "Area calculated by Calculator's member function: " << area2 << endl;

    return 0;
}