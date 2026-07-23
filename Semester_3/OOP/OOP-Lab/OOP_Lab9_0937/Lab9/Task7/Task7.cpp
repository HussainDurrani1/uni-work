#include <iostream>
#include "ElectronicDevice.h"
#include "SmartDevice.h"
#include "SmartPhone.h"
using namespace std;

void takeUserInput(char (&brand)[100], int& wP, bool& sB, int &sC, double& price, float& cR) {
	cout << "Enter Brand Name: ";
	cin.getline(brand, 100);
	cout << "Enter Warranty Period: ";
	cin >> wP;
	cout << "Does it Support Battery? (y/n): ";
	char temp; cin >> temp; if (temp == 'y' || temp == 'Y') { sB = true; }
	else { sB = false; }
	cout << "Enter Storage Capacity: ";
	cin >> sC;
	cout << "Enter Camera Resolution: ";
	cin >> cR;
	cout << "Enter Price: ";
	cin >> price;
	cin.ignore();
}

int main() {
	char brand[100];
	int storageCapacity = 0, warrantyPeriod = 0;
	float cameraResolution = 0.0;
	double price = 0.0;
	bool supportBattery;
	
	SmartPhone sp1;
	cout << "Smart Phone 1: \n";
	sp1.displaySmartPhone();
	
	takeUserInput(brand, warrantyPeriod, supportBattery, storageCapacity, price, cameraResolution);

	cout << "Smart Phone 2: \n";
	SmartPhone sp2(storageCapacity, cameraResolution, price, supportBattery, brand, warrantyPeriod);
	sp2.displaySmartPhone();

	return 0;
}