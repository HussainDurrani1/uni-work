#pragma once
#include <iostream>
#include "Shape.h"
using namespace std;

class _2DShape : private Shape
{
private:
	int sides;

public:
	_2DShape() : sides(0), Shape((char*)("Unknown")){}

	_2DShape(int s, char* c): sides(s), Shape((char*)c){}

	void setSides(bool s) { sides = s; }
	int getSides() const { return sides; }

	void display_2DShape() const {
		displayShape();
		cout << "Sides: " << getSides() << ".\n";
	}
};