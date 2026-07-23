#include <iostream>
#include "Shape.h"
#include "2DShape.h"
#include "Rectangle.h"
using namespace std;

void takeUserInput(char (&color)[100], int& sides, double& length, double& width) {
	cout << "Enter Color of Rectangle: ";
	cin.getline(color, 100);
	cout << "Enter no. of Sides: ";
	cin >> sides;
	cout << "Enter Length: ";
	cin >> length;
	cout << "Enter Width: ";
	cin >> width;
	cin.ignore();
}

int main() {
	char color[100];
	int sides = 0;
	double length= 0.0, width = 0.0;
	
	Rectangle r1;
	cout << "Rectangle 1: \n";
	r1.displayRectangle();
	
	takeUserInput(color, sides, length, width);

	cout << "Rectangle 2: \n";
	Rectangle r2(length, width, sides, color);
	r2.displayRectangle();

	cout << "Area of Rectangle = " << r2.calculate_area() << ".\n";
	cout << "Perimeter of Rectangle = " << r2.calculate_perimeter() << ".\n";

	return 0;
}