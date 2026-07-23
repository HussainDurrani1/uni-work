#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle : public Shape {
private:
	double length;
	double width;

public:
	Rectangle() : length(0), width(0) {
		cout << "Rectangle created...\n";
	}

	Rectangle(double len, double wid, char* color, int sides) : length(len), width(wid), Shape(color, sides) {}

	void displayRect() const {
		cout << "-----------------------------------------------------\n";
		display();
		cout << "Length: " << length << ", Width: " << width << ".\n";
		cout << "-----------------------------------------------------\n";
	}
};