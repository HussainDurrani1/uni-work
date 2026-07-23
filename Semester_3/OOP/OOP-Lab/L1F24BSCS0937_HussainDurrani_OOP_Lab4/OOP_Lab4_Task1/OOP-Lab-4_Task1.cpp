#include "ComplexNumber.h"
#include <iostream>
using namespace std;

void inputValues(int &real, int &imaginary) {
	cout << "Enter the real part: ";
	cin >> realPart;
	cout << "Enter the imaginary part: ";
	cin >> imaginaryPart;
}

int main() {
	ComplexNumber cn1;
	double frealPart, fimaginaryPart;
	double srealPart, simaginaryPart;

	inputValues(frealPart, fimaginaryPart);

	cn1.setValue(realPart, imaginaryPart);
	cn1.display();

	
	ComplexNumber cn2;
	inputValues(srealPart, simaginaryPart);
	cn2.setValue(realPart, imaginaryPart);
	cn2.setValue(realPart, imaginaryPart);
	cn2.display();

	cout << cn1.getRealP() << " + " << cn1.getImagP() << "i" << endl;
	cout << cn2.getRealP() << " + " << cn2.getImagP() << "i" << endl;

	cn1.sum(realPart, imaginaryPart);
	cn1.difference(realPart, imaginaryPart);


	return 0;
}