#pragma once
#include "Device.h"

class Scanner : virtual public Device {
protected:
	int scanResolution;

public:
	Scanner(int res) : Device(0) {
		scanResolution = res;
		cout << "Scanner constructor called" << endl;
	}

	void displayScanner() const {
		cout << "Scan Resolution: " << scanResolution << " DPI" << endl;
	}
};