#pragma once
#include "SystemGlobals.h"
#include "InputUtils.h"
#include "Car.h"
#include "Bike.h"
#include "Rickshaw.h"

void registerRider() {
    if (riderCount >= MAX_DB_USERS) { cout << "Database full!\n"; return; }

    int id = 100 + riderCount;
    char name[100], pass[100], phone[100], email[100];

    cout << "\n--- Rider Registration ---\n";
    getStringInput("Enter Name: ", name);
    getStringInput("Enter Password: ", pass);
    getStringInput("Enter Email: ", email);

    Rider* r = new Rider(id, name, pass);
    r->updateProfile(name, pass, email);

    riders[riderCount++] = r;
    cout << "Rider Registered Successfully! ID: " << id << endl;
}

void registerDriver() {
    if (driverCount >= MAX_DB_USERS) { cout << "Database full!\n"; return; }

    int id = 200 + driverCount;
    char name[100], pass[100], phone[100], email[100], lic[100];
    char vType[100], vModel[100], vPlate[100];

    cout << "\n--- Driver Registration ---\n";
    getStringInput("Enter Name: ", name);
    getStringInput("Enter Password: ", pass);
    getStringInput("Enter Email: ", email);
    getStringInput("Enter License Number: ", lic);

    Driver* d = new Driver(id, name, pass, email, lic);

    cout << "--- Vehicle Info ---\n";
    getStringInput("Vehicle Type (Car/Bike/Rickshaw): ", vType);
    getStringInput("Vehicle Model: ", vModel);
    getStringInput("License Plate: ", vPlate);

    int vId = 500 + driverCount;
    Vehicle* v = nullptr;

    if (compareString(vType, "Car")) {
        char hasAC;
        cout << "Has AC? (y/n): ";
        cin >> hasAC; 
        clearInput();
        bool ac = (hasAC == 'y' || hasAC == 'Y');
        v = new Car(vModel, vId, vPlate, 4, "Unknown", ac);
    }
    else if (compareString(vType, "Bike")) {
        char hasHelmet;
        cout << "Provides Helmet? (y/n): ";
        cin >> hasHelmet;
        clearInput();
        bool helmet = (hasHelmet == 'y' || hasHelmet == 'Y');
        v = new Bike(vModel, vId, vPlate, 1, "Black", helmet);
    }
    else if (compareString(vType, "Rickshaw")) {
        char isCovered;
        cout << "Is Covered? (y/n): ";
        cin >> isCovered;
        clearInput();
        bool covered = (isCovered == 'y' || isCovered == 'Y');
        v = new Rickshaw(vModel, vId, vPlate, 3, "Yellow", covered);
    }
    else {
        v = new Vehicle(vModel, vId, vPlate, 4, "Unknown", vType);
    }
    d->assignVehicle(v);

    cout << "--- Initial Location ---\n";
    double lat, lon;
    cout << "Latitude: "; cin >> lat;
    cout << "Longitude: "; cin >> lon;
    clearInput();

    d->updateLocation(lat, lon);

    drivers[driverCount++] = d;

    systemAdmin->addDriver(d);
    engine->setDrivers(drivers, driverCount);

    cout << "Driver Registered! Status: Pending Verification by Admin.\n";
}
