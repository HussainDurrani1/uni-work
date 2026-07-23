#pragma once
#include <iostream>
#include "Vehicle.h"
#include "RoadVehicle.h"
using namespace std;

class Car: public Vehicle, public RoadVehicle
{
private:
	char* color;
	int miles;

public:
	Car() : miles(0.0), color(copyStr("Unknown")), Vehicle(), RoadVehicle() {}

	Car(int m, char* c, char* b, int reg, int noWs) : miles(m), color(c), Vehicle(b, reg), RoadVehicle(noWs) {}

	void setMiles(int m) { miles = m; }
	int getMiles() const { return miles; }

	void setColor(char* c) { delete[] color; color = copyStr(c); }
	char* getColor() const { return color; }

	void displayCar() const {
		cout << "---------------------------------------------------------------------\n";
		displayVehicle();
		displayRoadVehicle();
		cout << "Color: " << getColor() << ", Miles: " << getMiles() << ".\n";
		cout << "---------------------------------------------------------------------\n";
	}
};
