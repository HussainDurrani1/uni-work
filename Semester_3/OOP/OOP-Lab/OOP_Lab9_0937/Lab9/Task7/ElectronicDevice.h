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

class ElectronicDevice
{
protected:
	char* brand;
	int warrantyPeriod;

public:
	ElectronicDevice() : warrantyPeriod(0) {
		brand = copyStr("Unknown");
	}

	ElectronicDevice(const char* nom, int wP) : warrantyPeriod(wP){
		brand = copyStr(nom);
	}

	~ElectronicDevice() {
		delete[] brand;
	}

	void setBrand(const char* nom) {
		delete[] brand;
		brand = copyStr(nom);
	}
	char* getBrand() const { return brand; }

	void setWarrantyPeriod(int wP) { warrantyPeriod = wP; }
	int getWarrantyPeriod() const { return warrantyPeriod; }

	void displayElectronicDevice() const {
		cout << "Brand: " << getBrand() << ", Warranty Period: " << getWarrantyPeriod() << " years.\n";
	}
};