#pragma once
#include "SystemGlobals.h"
#include "InputUtils.h"

void riderMenu(Rider* user) {
    while (true) {
        cout << "\n=== Rider Menu (" << user->getName() << ") ===\n";
        cout << "1. Book a Ride\n";
        cout << "2. View Notifications\n";
        cout << "3. Wallet (Balance/Add Funds)\n";
        cout << "4. View History\n";
        cout << "5. Rate Last Ride\n";
        cout << "6. Logout\n";
        cout << "Choice: ";
        int choice; 
        cin >> choice; 
        clearInput();

        if (choice == 1) {
            char pName[50], dName[50], vType[20];
            double pLat, pLon, dLat, dLon;

            cout << "\n--- Book Ride ---\n";
            getStringInput("Pickup Location Name: ", pName);
            cout << "Pickup Lat: "; cin >> pLat;
            cout << "Pickup Lon: "; cin >> pLon; 
            clearInput();

            getStringInput("Dropoff Location Name: ", dName);
            cout << "Dropoff Lat: "; cin >> dLat;
            cout << "Dropoff Lon: "; cin >> dLon; 
            clearInput();

            getStringInput("Preferred Vehicle (Car/Bike/Rickshaw): ", vType);

            Location pick(pName, "N/A", "N/A", pLat, pLon);
            Location drop(dName, "N/A", "N/A", dLat, dLon);

            RideRequest* req = bookingMgr->bookRide(user, pick, drop, vType);

            if (req != nullptr) {
                cout << "\n[Success] Driver Found! Waiting for completion...\n";
            }

        }
        else if (choice == 2) {
            user->showNotifications();
        }
        else if (choice == 3) {
            cout << "Balance: $" << user->getWalletBalance() << endl;
            cout << "Add Funds? (y/n): ";
            char c; 
            cin >> c; 
            clearInput();
            if (c == 'y') {
                double amt; 
                cout << "Amount: "; 
                cin >> amt; 
                clearInput();
                user->addToWallet(amt, "User Deposit");
                cout << "Funds added.\n";
            }
        }
        else if (choice == 4) {
            user->display();
        }
        else if (choice == 5) {
            RideRequest* r = user->getCurrentRide();
            if (r != nullptr && r->isCompleted()) {
                float score;
                char comment[100];
                cout << "\n--- Rate Driver ---\n";
                cout << "Enter Rating (1-5): "; cin >> score; clearInput();
                getStringInput("Enter Comment: ", comment);

                user->rateDriver(score, comment);
            }
            else {
                cout << "\n[Error] No completed ride to rate.\n";
            }
        }
        else if (choice == 6) {
            break;
        }
    }
}
