#pragma once
#include <iostream>
#include "Shape.h"
#include "2DShape.h"
using namespace std;

class Rectangle: public _2DShape
{
private:
	double length;
	double width;

public:
	Rectangle() : length(0.0), width(0.0), _2DShape() {}

	Rectangle(double l, double w, int s, char* c) : length(l), width(w), _2DShape(s, c) {}

	void setLenght(int l) { length = l; }
	double getLenght() const { return length; }

	void setWidth(float w) { width = w; }
	double getWidth() const { return width; }

	double calculate_area() {
		return (length * width);
	}

	double calculate_perimeter() {
		return (2 * (length + width));
	}

	void displayRectangle() const {
		cout << "---------------------------------------------------------------------\n";
		display_2DShape();
		cout << "Lenght: " << getLenght() << ", Width: " << getWidth() << ".\n";
		cout << "---------------------------------------------------------------------\n";
	}
};