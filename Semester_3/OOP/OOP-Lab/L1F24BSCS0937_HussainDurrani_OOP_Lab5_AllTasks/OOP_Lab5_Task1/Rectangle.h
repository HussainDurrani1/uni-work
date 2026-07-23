#pragma once

#include <iostream>
using namespace std;

class Rectangle
{
private:
	double length;
	double width;

public:
	void setLength(double l) { length = l; }
	void setWidth(double w) { width = w; }

	double getLength() { return length; }
	double getWidth() { return width; }

	Rectangle() {
		length = 0.0;
		width = 0.0;
	}

	Rectangle(double l, double w) {
		length = l;
		width = w;
	}

	Rectangle(Rectangle& rectangle) {
		length = rectangle.length;
		width = rectangle.width;
	}

	double area() { return (length * width); }

	double perimeter() { return (2 * (length + width)); }

	Rectangle combine(Rectangle& obj) {
		Rectangle temp;
		if (length > obj.length) {
			temp.setLength(length);
		}
		else {
			temp.setLength(obj.length);
		}

		if (width > obj.width) {
			temp.setWidth(width);
		}
		else {
			temp.setWidth(obj.width);
		}
		return temp;
	}

	void display() {
		cout << "Length = " << length << ", Width = " << width << " \n";
	}

	~Rectangle() {
		cout << "Destructor is called...\n";
	}


};
