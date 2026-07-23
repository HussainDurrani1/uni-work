#pragma once
#include <iostream>
#include "ElectronicDevice.h"
using namespace std;

class SmartDevice : private ElectronicDevice
{
private:
	bool supportBattery;

public:
	SmartDevice() : supportBattery(false), ElectronicDevice((char*)("Unknown"), 0){}

	SmartDevice(bool sB, char* b, int wP): supportBattery(sB), ElectronicDevice((char*)b, wP){}

	void setSupportBattery(bool sB) { supportBattery = sB; }
	bool getSupportBattery() const { return supportBattery; }

	void displaySmartDevice() const {
		displayElectronicDevice();
		cout << "Support Battery: ";
		if (getSupportBattery() == true) { cout << "True"; }
		else { cout << "False"; }
		cout << ".\n";
	}
};