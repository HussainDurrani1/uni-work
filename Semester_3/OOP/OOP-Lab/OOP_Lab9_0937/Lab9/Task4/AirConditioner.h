#pragma once
#include "Appliance.h"
#include <iostream>
using namespace std;

class AirConditioner : public Appliance {
private:
	double price;
	int warranty;

public:
	AirConditioner() : price(0), warranty(0) {
		cout << "AirConditioner created...\n";
	}

	AirConditioner(double p, int w, char* brand) : price(p), warranty(w), Appliance(brand) {}

	void displayAirConditioner() const {
		cout << "-----------------------------------------------------\n";
		display();
		cout << "Price: " << price << ", Warranty: " << warranty << ".\n";
		cout << "-----------------------------------------------------\n";
	}
};