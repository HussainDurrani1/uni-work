#pragma once
#include <iostream>
using namespace std;

class Shape {
public:
    virtual float area() = 0;
    virtual float perimeter() = 0;
};