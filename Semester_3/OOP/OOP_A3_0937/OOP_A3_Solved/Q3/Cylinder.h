#pragma once
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>
using namespace std;

class Cylinder : public Rectangle, public Circle {
public:
    Cylinder(float r, float h)
        : Rectangle(2 * 3.14159f * r, h), Circle(r) {
    }

    float area() override {
        return (2 * Circle::area()) + Rectangle::area();
    }

    float perimeter() override {
        return Circle::perimeter();
    }

    void display() {
        cout << "Cylinder Properties:\n";
        cout << "   Base Radius: " << radius << endl;
        cout << "   Height: " << width << endl; 
        cout << "   Total Surface Area: " << area() << endl;
    }
};