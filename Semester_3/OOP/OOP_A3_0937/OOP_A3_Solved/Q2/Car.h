#pragma once
#include "Vehicle.h"
#include <iostream>
using namespace std;

class Car : public Vehicle {
public:
    Car() : Vehicle("Car", "S", 2000, "Unknown", 0) {}

    Car(string m, int y, string n, int eng): Vehicle("Car", m, y, n, eng) {}

    void startEngine() override { 
        cout << "Car Engine (" << engineNumber << ") started with a key turn.\n";
    }

    void stopEngine() override {
        cout << "Car Engine stopped.\n";
    }
};