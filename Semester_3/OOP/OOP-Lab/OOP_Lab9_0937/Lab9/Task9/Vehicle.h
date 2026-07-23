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

class Vehicle
{
private:
	char* brand;
	int regNo;

public:
	Vehicle(): regNo(0) {
		brand = copyStr("Unknown");
	}

	Vehicle(const char* b, int reg): regNo(reg){
		brand = copyStr(b);
	}

	~Vehicle() {
		delete[] brand;
	}

	void setRegNo(int reg) { regNo = reg; }
	int getRegNo() const { return regNo; }

	void setBrand(const char* b) {
		delete[] brand;
		brand = copyStr(b);
	}
	char* getBrand() const { return brand; }

	void displayVehicle() const {
		cout << "Vehicle's Brand: " << getBrand()<< ", Registration NO.: " << getRegNo() << ".\n";
	}
};