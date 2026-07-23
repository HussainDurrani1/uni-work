// Task 3:
#include <iostream>
using namespace std;

int Area(int length) {
	return length * length;
}

int Area(int length, int width) {
	return length * width;
}

double Area(double radius) {
	return (3.14) * (radius * radius);
}

int main() {
	int length = 8;
	int width = 5;
	double radius = 9.7;

	cout << "The area of square = " << Area(length) << endl;
	cout << "The area of rectangle = " << Area(length, width) << endl;
	cout << "The area of circle = " << Area(radius) << endl;

	return 0;
}