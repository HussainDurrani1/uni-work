#include "Shape.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main() {
	double length, width;
	int sides;
	char color[100];

	Rectangle r1;
	r1.displayRect();

	cout << "For Rectangle: \n";
	cout << "Enter lenght: "; cin >> length;
	cout << "Enter width: "; cin >> width;
	cout << "Enter no. of sides: "; cin >> sides;
	cout << "Enter color: "; cin.ignore(); cin.getline(color, 100);


	Rectangle r2(length, width, color, sides);
	r2.displayRect();

	return 0;
}