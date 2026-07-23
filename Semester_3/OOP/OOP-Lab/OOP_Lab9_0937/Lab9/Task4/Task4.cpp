#include "Appliance.h"
#include "AirConditioner.h"
#include <iostream>
using namespace std;

int main() {
	double price;
	int warranty;
	char brand[100];

	AirConditioner a1;
	a1.displayAirConditioner();

	cout << "For Rectangle: \n";
	cout << "Enter price: "; cin >> price;
	cout << "Enter warranty (in years): "; cin >> warranty;
	cout << "Enter brand: "; cin.ignore(); cin.getline(brand, 100);


	AirConditioner a2(price, warranty, brand);
	a2.displayAirConditioner();

	return 0;
}