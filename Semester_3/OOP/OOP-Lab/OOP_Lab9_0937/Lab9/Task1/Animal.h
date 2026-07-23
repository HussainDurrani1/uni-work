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

class Animal {
private:
	char* name;
	int age;

public:
	Animal() : age(0) {
		name = copystr("Unknown!");
	}

	Animal(char* nom, int a) : age(a) {
		name = copystr(nom);
	}

	~Animal() {
		delete[] name;
	}

	void display() const {
		cout << "Animal Class created: \n";
		cout << "Animal Name: " << name << ", Age: " << age << ". \n";
	}
};