#include <iostream>
#include "Cylinder.h"
using namespace std;

int main() {
    float radius, height;

    cout << "--- Cylinder Calculator ---\n";
    cout << "Enter Radius of Cylinder base: ";
    cin >> radius;
    cout << "Enter Height of Cylinder: ";
    cin >> height;

    Cylinder myCylinder(radius, height);

    cout << "\n----------------------------\n";
    myCylinder.display();
    cout << "----------------------------\n";

    cout << "Debug Access:\n";
    cout << "Area() call: " << myCylinder.area() << endl;
    cout << "Perimeter() call: " << myCylinder.perimeter() << endl;

    return 0;
}