#pragma once
#include "Shape.h"
using namespace std;

class Rectangle : virtual public Shape {
protected:
    float length;
    float width;

public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float area() override {
        return length * width;
    }

    float perimeter() override {
        return 2 * (length + width);
    }
};