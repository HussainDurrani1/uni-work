#pragma once
#include <iostream>
using namespace std;

int getLen(const char* str) {
	int len = 0;
	while (str[len] != '\0')len++;
	return len;
}

char* copyStr(const char* src) {
	int len = getLen(src);
	char* dest = new char[len + 1];
	for (int i = 0; i < len; i++) dest[i] = src[i];
	dest[len] = '\0';
	return dest;
}

class Shape
{
protected:
	char* color;

public:
	Shape() {
		color = copyStr("Unknown");
	}

	Shape(const char* c){
		color = copyStr(c);
	}

	~Shape() {
		delete[] color;
	}

	void setColor(const char* c) {
		delete[] color;
		color = copyStr(c);
	}
	char* getColor() const { return color; }

	void displayShape() const {
		cout << "Shape's Color: " << getColor() << ".\n";
	}
};