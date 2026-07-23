#pragma once
#include "SystemGlobals.h"
#include "InputUtils.h"
#include "RiderMenu.h"
#include "DriverMenu.h"
#include "AdminMenu.h"

void login() {
    cout << "\n--- Login ---\n";
    cout << "1. Rider\n";
    cout << "2. Driver\n";
    cout << "3. Admin\n";
    cout << "Choice: ";
    int role; 
    cin >> role; 
    clearInput();

    if (role == 1) {
        char name[100]; 

        getStringInput("Enter Name: ", name);

        for (int i = 0; i < riderCount; i++) {
            if (compareString(riders[i]->getName(), name)) {
                riderMenu(riders[i]);
                return;
            }
        }

        cout << "User not found.\n";
    }
    else if (role == 2) {
        char name[100]; 

        getStringInput("Enter Name: ", name);

        for (int i = 0; i < driverCount; i++) {
            if (compareString(drivers[i]->getName(), name)) {
                driverMenu(drivers[i]);
                return;
            }
        }

        cout << "Driver not found.\n";
    }
    else if (role == 3) {
        char pass[100]; 
        getStringInput("Enter Admin Password: ", pass);

        if (compareString(pass, "admin123")) {
            adminMenu();
        }
        else {
            cout << "Wrong password.\n";
        }
    }
}
