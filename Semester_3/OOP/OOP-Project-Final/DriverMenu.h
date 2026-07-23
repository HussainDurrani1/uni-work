#pragma once
#include "SystemGlobals.h"
#include "InputUtils.h"
#include "Payment.h"
#include "PromoCode.h"

void driverMenu(Driver* user) {
    while (true) {
        cout << "\n=== Driver Menu (" << user->getName() << ") ===\n";
        cout << "1. Go Online\n";
        cout << "2. Go Offline\n";
        cout << "3. View Notifications\n";
        cout << "4. Complete Current Ride (Simulate)\n";
        cout << "5. View Stats/Wallet\n";
        cout << "6. Logout\n";
        cout << "Choice: ";
        int choice; 
        cin >> choice; 
        clearInput();

        if (choice == 1) {
            user->goOnline();
            if (user->isAvailable()) cout << "You are now ONLINE.\n";
            else cout << "Could not go online (Not verified?)\n";
        }
        else if (choice == 2) {
            user->goOffline();
            cout << "You are now OFFLINE.\n";
        }
        else if (choice == 3) {
            user->showNotifications();
        }
        else if (choice == 4) {
            bool found = false;
            for (int i = 0; i < riderCount; i++) {
                RideRequest* r = riders[i]->getCurrentRide();

                if (r != nullptr && r->getAssignedDriver() == user && !r->isCompleted()) {

                    found = true;
                    cout << "Found Active Ride ID: " << r->getRideId() << " from " << r->getRider()->getName() << endl;
                    cout << "Complete this ride? (y/n): ";
                    char c; 
                    cin >> c; 
                    clearInput();
                    if (c == 'y') {
                        user->completeRide(r, "Now");
                        cout << "Ride Completed. Fare: $" << r->getFare() << endl;

                        char* rIdStr = intToString(r->getRideId());
                        Payment* p = new Payment(rIdStr, r->getFare(), "Wallet");
                        delete[] rIdStr;

                        cout << "Apply Promo Code? (y/n): ";
                        
                        char pc; 
                        cin >> pc; 
                        clearInput();

                        if (pc == 'y') {
                            char code[50];
                            getStringInput("Enter Code: ", code);
                            if (compareString(code, "SAVE10")) {
                                PromoCode* promo = new PromoCode("SAVE10", 10.0);
                                p->applyPromoCode(promo, code);
                            }
                        }

                        p->processPayment(r);
                        delete p;

                        cout << "Rider will rate you later.\n";
                    }
                    break;
                }
            }
            if (!found) cout << "No active rides found.\n";

        }
        else if (choice == 5) {
            user->display();
        }
        else if (choice == 6) {
            break;
        }
    }
}
