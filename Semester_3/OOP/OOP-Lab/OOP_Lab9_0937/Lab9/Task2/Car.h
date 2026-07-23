#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Car : public Vehicle {
public:
	Car() {
		cout << "Car created.\n";
	}
};