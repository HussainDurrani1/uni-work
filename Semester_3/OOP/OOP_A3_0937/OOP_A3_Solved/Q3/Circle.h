#pragma once
#include "Shape.h"
using namespace std;

class Circle : virtual public Shape {
protected:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    float area() override {
        return 3.14159f * radius * radius;
    }

    float perimeter() override {
        return 2 * 3.14159f * radius;
    }
};