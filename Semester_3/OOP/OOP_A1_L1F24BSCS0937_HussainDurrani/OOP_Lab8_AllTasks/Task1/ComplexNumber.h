#pragma once
#include <iostream>
using namespace std;

class ComplexNumber
{
private:
	int real;
	int imag;

public:
	ComplexNumber() : real(0), imag(0) {}

	ComplexNumber(int r, int i) : real(r), imag(i) {}

	ComplexNumber operator + (const ComplexNumber& other) {
		ComplexNumber temp;
		temp.real = (this->real + other.real);
		temp.imag = (this->imag + other.imag);
		return temp;
	}

	ComplexNumber operator - (const ComplexNumber& other) {
		ComplexNumber temp;
		temp.real = (this->real - other.real);
		temp.imag = (this->imag - other.imag);
		return temp;
	}

	ComplexNumber operator*(const ComplexNumber& other) {
		ComplexNumber temp;
		temp.real = (this->real * other.real);
		temp.imag = (this->imag * other.imag);
		return temp;
	}

	ComplexNumber operator / (const ComplexNumber& other) {
		ComplexNumber temp;
		temp.real = (this->real / other.real);
		temp.imag = (this->imag / other.imag);
		return temp;
	}

	ComplexNumber operator%(const ComplexNumber& other) {
		ComplexNumber temp;
		temp.real = (this->real % other.real);
		temp.imag = (this->imag % other.imag);
		return temp;
	}

	void display() const {
		cout << this->real << " + " << this->imag << "i \n";
	}
};