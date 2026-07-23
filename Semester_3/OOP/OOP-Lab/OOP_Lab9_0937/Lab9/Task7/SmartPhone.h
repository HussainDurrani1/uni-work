#pragma once
#include <iostream>
#include "SmartDevice.h"
#include "ElectronicDevice.h"
using namespace std;

class SmartPhone: public SmartDevice
{
private:
	int storageCapacity;
	float cameraResolution;
	double price;

public:
	SmartPhone() : storageCapacity(0), cameraResolution(0.0), price(0.0), SmartDevice() {}

	SmartPhone(int sC, float cR, double p, bool sB, char* b, int wP) : storageCapacity(sC), cameraResolution(cR), price(p), SmartDevice(sB, b, wP) {}

	void setStorageCapacity(int sC) { storageCapacity = sC; }
	int getStorageCapacity() const { return storageCapacity; }

	void setCameraResolution(float cR) { cameraResolution = cR; }
	float getCameraResolution() const { return cameraResolution; }

	void setPrice(double p) { price = p; }
	double getPrice() const { return price; }

	void displaySmartPhone() const {
		cout << "----------------------------------------------------------------------------------------------------------------------\n";
		displaySmartDevice();
		cout << "Storage Capacity: " << storageCapacity << " gbs, Camera Resolution: " << getCameraResolution() << " MegaPixels, Price: $" << getPrice() << ".\n";
		cout << "----------------------------------------------------------------------------------------------------------------------\n";
	}
};