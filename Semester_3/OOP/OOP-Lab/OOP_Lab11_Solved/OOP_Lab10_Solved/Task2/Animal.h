#pragma once
#include <iostream>
using namespace std;

int getLen(const char* str) {
	int len = 0;
	while (str[len] != '\0') len++;
	return len;
}

char* copyStr(const char* src) {
	int len = getLen(src);
	char* dest = new char[len + 1];
	for (int i = 0; i < len; i++)
		dest[i] = src[i];
	dest[len] = '\0';
	return dest;
}

class Animal {
protected:
	char* name;

public:
	Animal(char* n) {
		name = copyStr(n);
	}

	void setName(const char* n) {
		delete[] name;
		name = copyStr(n);
	}

	void display() const {
		cout << "Animal Name: " << name << endl;
	}

	virtual void makeSound() {
		cout << "Base class: Animal object" << endl;
	}
};