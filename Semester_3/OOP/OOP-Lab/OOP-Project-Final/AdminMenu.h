#pragma once
#include "SystemGlobals.h"
#include "InputUtils.h"

void adminMenu() {
    while (true) {
        cout << "\n=== Admin Menu ===\n";
        cout << "1. Verify Drivers\n";
        cout << "2. View All Drivers\n";
        cout << "3. View All Riders\n";
        cout << "4. Global System Report\n";
        cout << "5. Logout\n";
        cout << "Choice: ";
        
        int choice; cin >> choice; clearInput();

        if (choice == 1) {
            cout << "Enter Driver ID to verify: ";
            int id; cin >> id; clearInput();
            systemAdmin->verifyDriver(id);
        }
        else if (choice == 2) {
            for (int i = 0; i < driverCount; i++) drivers[i]->display();
        }
        else if (choice == 3) {
            for (int i = 0; i < riderCount; i++) riders[i]->display();
        }
        else if (choice == 4) {
            systemAdmin->display();
        }
        else if (choice == 5) {
            break;
        }
    }
}
