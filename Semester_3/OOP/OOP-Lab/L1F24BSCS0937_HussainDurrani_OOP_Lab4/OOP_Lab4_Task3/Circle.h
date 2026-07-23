#pragma once
#include <iostream>
using namespace std;
class Circle
{
private:
	double radius;
	double pi = 3.14159;

public:
	Circle(){
		radius = 0.0;
	}

	Circle(double rad) {
		radius = rad;
	}

	void setRadius(double rad) {
		radius = rad;
	}
	double getRadius() {
		return radius;
	}

	double area() {
		return (pi * radius * radius);
	}

	double getDiameter() {
		return (radius * 2);
	}
	
	double getCircumference() {
		return (2 * pi * radius);
	}


	void display() {
		cout << "------------------------------------------------------\n";
		cout << "Displaying:\n";

		cout << "The radius of circle: " << radius << endl;
		cout << "The Area of circle: " << area() << endl;
		cout << "The Diameter of circle: " << getDiameter() << endl;
		cout << "The Circumference of circle: " << getCircumference() << endl;

		cout << "------------------------------------------------------\n";
	}
};

