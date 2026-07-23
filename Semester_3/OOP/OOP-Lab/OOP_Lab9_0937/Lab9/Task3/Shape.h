#pragma once
#include <iostream>
using namespace std;

int getLen(const char* str) {
	int len = 0;
	while (str[len] != '\0') len++;
	return len;
}

char* copystr(const char* src) {
	int len = getLen(src);
	char* dest = new char[len + 1];
	for (int i = 0; i < len; i++) { dest[i] = src[i]; }
	dest[len] = '\0';
	return dest;
}

class Shape{
private:
	char* color;
	int sides;

public:
	Shape() : sides(0) {
		color = copystr("White");
		cout << "Shape created...\n";
	}

	Shape(char* c, int s) : sides(s) {
		cout << "Shape created...\n";
		color = copystr(c);
	}

	~Shape() {
		delete[] color;
	}

	void display() const {
		cout << "Shape Color: " << color << ", Sides: " << sides << ". \n";
	}
};