#pragma once
#include <iostream>
using namespace std;

class Device {
protected:
	int deviceID;

public:
	Device(int id) {
		deviceID = id;
		cout << "Device constructor called" << endl;
	}

	void displayDevice() const {
		cout << "Device ID: " << deviceID << endl;
	}
};