#include <iostream>
#include "Vehicle.h"
#include "RoadVehicle.h"
#include "Car.h"
using namespace std;

void takeUserInput(char (&brand)[100], char(&color)[100], int& regNo, int& noWs, int& miles) {
	cout << "Enter Brand of Car: ";
	cin.getline(brand, 100);
	cout << "Enter Registration no. of Car: ";
	cin >> regNo;
	cout << "Enter Number Of Wheels: ";
	cin >> noWs;
	cin.ignore();
	cout << "Enter Color: ";
	cin.getline(color, 100);
	cout << "Enter Miles: ";
	cin >> miles;
	cin.ignore();
}

int main() {
	char brand[100], color[100];
	int regNo = 0, noWs = 0, miles = 0;
	
	Car c1;
	cout << "Car 1: \n";
	c1.displayCar();
	
	takeUserInput(brand, color, regNo, noWs, miles);

	cout << "Rectangle 2: \n";
	Car c2(miles, color, brand, regNo, noWs);
	c2.displayCar();

	return 0;
}