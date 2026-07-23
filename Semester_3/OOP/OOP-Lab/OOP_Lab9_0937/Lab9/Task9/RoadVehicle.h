#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class RoadVehicle
{
private:
	int numberOfWheels;

public:
	RoadVehicle() : numberOfWheels(0){}

	RoadVehicle(int noWs): numberOfWheels(noWs){}

	void setNumberOfWheels(int w) { numberOfWheels = w; }
	int getNumberOfWheels() const { return numberOfWheels; }

	void displayRoadVehicle() const {
		cout << "Number Of Wheels: " << getNumberOfWheels() << ".\n";
	}
};