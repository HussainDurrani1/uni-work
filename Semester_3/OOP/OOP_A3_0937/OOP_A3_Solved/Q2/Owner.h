#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Owner {
private:
    string ownerName;
    Vehicle* vehicle;

public:
    Owner(string n) {
        ownerName = n;
        vehicle = nullptr;
    }

    void setVehicle(Vehicle* v) {
        vehicle = v;
    }

    void showOwnership() const {
        cout << ownerName << " owns a: ";
        if (vehicle != nullptr) {
            vehicle->displayInfo();
            cout << endl;
            vehicle->startEngine();
            vehicle->stopEngine();
        }
        else {
            cout << "No vehicle assigned.\n";
        }
    }
};