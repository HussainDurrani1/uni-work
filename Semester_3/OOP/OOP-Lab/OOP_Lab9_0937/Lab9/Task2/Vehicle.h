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

class Vehicle
{
private:
	char* brand;
	int regNo;

public:
	Vehicle() : regNo(0) {
		brand = copystr("Unknown!");
		cout << "Vehicle created...\n";
	}

	Vehicle(char* b, int reg) : regNo(reg) {
		brand = copystr(b);
	}

	~Vehicle() {
		delete[] brand;
	}

	void display() const {
		cout << "Vehicle Class created: \n";
		cout << "Vehicle Brand: " << brand << ", RegNo: " << regNo << ". \n";
	}
};