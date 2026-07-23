#include <iostream>
#include "SystemGlobals.h"
#include "RideRequestImpl.h" 
#include "TripHistoryImpl.h" 
#include "Registration.h"
#include "Auth.h"
#include "InputUtils.h"

using namespace std;

int main() {
    setupSystem();

    while (true) {
        cout << "\n============================================\n";
        cout << "   Ride-Sharing System (Modular)\n";
        cout << "============================================\n";
        cout << "1. Login\n";
        cout << "2. Register as Rider\n";
        cout << "3. Register as Driver\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        int choice;
        if (!(cin >> choice)) {
            clearInput();
            continue;
        }
        clearInput();

        if (choice == 1) login();
        else if (choice == 2) registerRider();
        else if (choice == 3) registerDriver();
        else if (choice == 4) break;
        else cout << "Invalid choice.\n";
    }

    return 0;
}
