#pragma once
#include <iostream>
using namespace std;

class Calculator;

class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w);

    friend int calculateArea(const Rectangle& r);

    friend class Calculator;

    ~Rectangle() {}
};