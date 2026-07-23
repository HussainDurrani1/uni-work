#pragma once
#include <iostream>
using namespace std;
class ComplexNumber
{
private:
	double realPart;
	double imaginaryPart;

public:
	void setValue(double realP, double imagP) {
		realPart = realP;
		imaginaryPart = imagP;
	}

	double getRealP(){return realPart;}

	double getImagP() {return imaginaryPart;}

	void display() {
		cout << "The real part is " << realPart << endl;
		cout << "The imaginary part is " << imaginaryPart << "i " << endl;
	}

	void sum(double realP, double imagP) {
		cout << realPart + realP << " + " << imaginaryPart + imagP << "i\n";
	}

	void difference(double realP, double imagP) {
		cout << realPart - realP << " + " << imaginaryPart - imagP << "i\n";
	}
};

