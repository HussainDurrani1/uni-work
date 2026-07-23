#pragma once
#include <iostream>
using namespace std;

class Circle
{
private:
	double radius;
	double pi;

public:
	Circle() {
		radius = 0.0;
		pi = 3.14159;
	}

	Circle(double r) {
		radius = r;
		pi = 3.14159;
	}

	void setRadius(double r) {
		radius = r;
	}

	double getRadius() { return radius; }
	double getDiameter() { return 2 * radius; }
	double getArea() { return pi * radius * radius; }
	double getCircumference() { return 2 * pi * radius; }

	void display() {
		cout << "Radius:\t\t" << radius << endl;
		cout << "Diameter:\t" << getDiameter() << endl;
		cout << "Area:\t\t" << getArea() << endl;
		cout << "Circumference:\t" << getCircumference() << endl;
	}
};