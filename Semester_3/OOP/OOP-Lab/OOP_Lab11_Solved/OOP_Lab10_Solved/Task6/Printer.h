#pragma once
#include "Device.h"

class Printer : virtual public Device {
protected:
	int printSpeed;

public:
	Printer(int speed) : Device(0) {
		printSpeed = speed;
		cout << "Printer constructor called" << endl;
	}

	void displayPrinter() const {
		cout << "Print Speed: " << printSpeed << " pages/min" << endl;
	}
};