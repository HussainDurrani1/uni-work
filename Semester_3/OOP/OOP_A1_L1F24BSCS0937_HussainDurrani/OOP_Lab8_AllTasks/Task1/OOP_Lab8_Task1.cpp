#include "ComplexNumber.h"
#include <iostream>
using namespace std;

int main() {
	int real = 0, imag = 0;
	cout << "Enter real part: ";
	cin >> real;
	cout << "Enter imaginary part: ";
	cin >> imag;
	ComplexNumber c1(real, imag);
	c1.display();

	cout << "Enter real part: ";
	cin >> real;
	cout << "Enter imaginary part: ";
	cin >> imag;
	ComplexNumber c2(real, imag);
	c2.display();

	ComplexNumber c3 = c1 + c2;
	cout << "Adding Complex Number 1 & 2: \n";
	c3.display();

	ComplexNumber c4 = c1 - c2;
	cout << "Subtracting Complex Number 1 & 2: \n";
	c4.display();

	ComplexNumber c5 = c1 * c2;
	cout << "Multiplying Complex Number 1 & 2: \n";
	c5.display();

	ComplexNumber c6 = c1 / c2;
	cout << "Divide Complex Number 1 & 2: \n";
	c6.display();

	ComplexNumber c7 = c1 % c2;
	cout << "Taking Modulus of Complex Number 1 & 2: \n";
	c7.display();

	return 0;
}