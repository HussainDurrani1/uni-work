// Task 1:
#include <iostream>
using namespace std;

class Rectangle {

private:
	double length;
	double width;

public:

	void setValue(double l, double w) {
		length = l;
		width = w;
	}

	void display() {
		cout << "The length of rectangle is: " << length << endl;
		cout << "The width of rectangle is: " << width << endl;
	}

	double calculateArea(double length, double width) {
		return length * width;
	}

};

int main() {

	Rectangle r1;
	double length, width;
	cout << "Enter the length of rectangle (in double): ";
	cin >> length;
	cout << "Enter the width of rectangle (in double): ";
	cin >> width;

	r1.setValue(length, width);
	r1.display();
	double l, w;
	cout << "Enter length & width of rectangle to find its Area: ";
	cin >> l >> w;
	cout << "The area of rectangle is = " << r1.calculateArea(l, w) << endl;

	return 0;
}