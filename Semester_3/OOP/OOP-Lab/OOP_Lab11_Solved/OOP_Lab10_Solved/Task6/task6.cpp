#include <iostream>
#include "AllInOne.h"
using namespace std;

int main() {

	int id, speed, res;
	char model[100];

	cout << "Enter Device ID: "; cin >> id;
	cout << "Enter Print Speed: "; cin >> speed;
	cout << "Enter Scan Resolution: "; cin >> res; cin.ignore();
	cout << "Enter Model Name: "; cin.getline(model, 100);

	AllInOne a1(id, speed, res, model);

	cout << "\n----- Display Device -----\n";
	a1.displayDevice();

	cout << "\n----- Display Printer -----\n";
	a1.displayPrinter();

	cout << "\n----- Display Scanner -----\n";
	a1.displayScanner();

	cout << "\n----- Display All In One -----\n";
	a1.displayAllInOne();

	return 0;
}