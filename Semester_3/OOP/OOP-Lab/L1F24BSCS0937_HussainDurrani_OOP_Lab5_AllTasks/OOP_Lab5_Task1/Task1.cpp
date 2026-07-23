#include "Rectangle.h";
#include <iostream>
using namespace std;

int main() {

	double l1, l2, w1, w2;
	cout << "Enter length of 1st Rectangle: ";
	cin >> l1;
	cout << "Enter width of 1st Rectangle: ";
	cin >> w1;
	Rectangle rectangle1(l1, w1);


	cout << "Enter length of 2nd Rectangle: ";
	cin >> l2;
	cout << "Enter width of 2nd Rectangle: ";
	cin >> w2;
	Rectangle rectangle2;
	rectangle2.setLength(l2);
	rectangle2.setWidth(w2);

	cout << "Rectangle 1: ";
	rectangle1.display();
	cout << "Rectangle 2: ";
	rectangle2.display();

	Rectangle combined;
	combined = rectangle1.combine(rectangle2);

	cout << "Combined Rectangle: ";
	combined.display();

	cout << "Area of Combined Rectangle: " << combined.area() << "\n";
	cout << "Perimeter of Combined Rectangle: " << combined.perimeter() << "\n";

	return 0;
}