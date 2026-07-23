#pragma once
#include <iostream>
using namespace std;

class ComplexNumber
{
private:
	double realPart;
	double imaginaryPart;

public:
	void setValue() {
		cout << "Enter Real part of Complex Number: ";
		cin >> realPart;
		cout << "Enter Imaginary part of Complex Number: ";
		cin >> imaginaryPart;
	}

	double getReal() { return realPart; }
	double getImaginary() { return imaginaryPart; }

	ComplexNumber sum(ComplexNumber c2) {
		ComplexNumber temp;
		temp.realPart = realPart + c2.realPart;
		temp.imaginaryPart = imaginaryPart + c2.imaginaryPart;
		return temp;
	}

	ComplexNumber difference(ComplexNumber c2) {
		ComplexNumber temp;
		temp.realPart = realPart - c2.realPart;
		temp.imaginaryPart = imaginaryPart - c2.imaginaryPart;
		return temp;
	}

	void display() {
		cout << realPart << " + " << imaginaryPart << "i" << endl;
	}
};