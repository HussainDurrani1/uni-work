#pragma once
#include <iostream>
#include "User.h"
#include "RideRequest.h"
#include "Utils.h"
#include "Wallet.h"
#include "TripHistory.h"
#include "Driver.h" 
using namespace std;

class Rider : public User
{
private:
    int riderId;
    TripHistory* history;
    RideRequest* currentRide;
    bool prefersAC;
    char* preferredVehicleType;
    float driverRating;
    int totalDriverRatings;
    Wallet* wallet;
    char* paymentMethod;

public:

    Rider() : User()
    {
        riderId = 0;
        history = new TripHistory(true);
        currentRide = nullptr;
        prefersAC = true;
        preferredVehicleType = copyString("Car");
        driverRating = 0.0f;
        totalDriverRatings = 0;
        wallet = new Wallet();
        paymentMethod = copyString("Cash");
    }

    Rider(int id, const char* n, const char* p)
        : User(id, n, p, "N/A")
    {
        riderId = id;
        history = new TripHistory(true);
        currentRide = nullptr;
        prefersAC = true;
        preferredVehicleType = copyString("Car");
        driverRating = 0.0f;
        totalDriverRatings = 0;
        wallet = new Wallet();
        paymentMethod = copyString("Cash");
    }

    ~Rider()
    {
        delete wallet;
        delete[] preferredVehicleType;
        delete[] paymentMethod;

        if (history != nullptr) delete history;
    }

    void requestRide(RideRequest* ride)
    {
        currentRide = ride;

        currentRide = ride;
        history->addTrip(ride);
    }

    void cancelCurrentRide()
    {
        if (currentRide != nullptr)
        {
            currentRide->cancelRide();
            currentRide = nullptr;
        }
    }

    void rateDriver(float rating, const char* comment = "No comment")
    {
        if (currentRide != nullptr) {
            currentRide->rateRide(rating, comment);
            if (currentRide->getAssignedDriver() != nullptr) {
                currentRide->getAssignedDriver()->addRating(rating);
            }
        }
        else {
            driverRating = (driverRating * totalDriverRatings + rating) / (totalDriverRatings + 1);
            totalDriverRatings++;
        }
    }

    void addToWallet(float amount, const char* source = "Top Up")
    {
        wallet->addFunds((double)amount, source);
    }

    void chargeWallet(float amount, const char* reason = "Payment")
    {
        wallet->deductFunds((double)amount, reason);
    }

    int getRiderId() const { return riderId; }
    RideRequest* getCurrentRide() const { return currentRide; }
    int getTotalRides() const { return history->getCount(); }
    float getDriverRating() const { return driverRating; }
    float getWalletBalance() const { return (float)wallet->getBalance(); }
    const char* getPreferredVehicleType() const { return preferredVehicleType; }

    void display() const
    {
        User::display();
        cout << "--- Rider Info ---" << endl;
        cout << "Rider ID: " << riderId << endl;
        cout << "Total Rides Taken: " << history->getCount() << endl;
        cout << "Current Ride: " << (currentRide != nullptr ? "Active" : "None") << endl;
        cout << "Preferred Vehicle: " << preferredVehicleType << endl;
        cout << "Prefers AC: " << (prefersAC ? "Yes" : "No") << endl;
        cout << "Driver Rating: " << driverRating << endl;

        cout << "History:" << endl;
        history->displayHistory();
        wallet->display();
        cout << "Payment Method: " << paymentMethod << endl;
    }
};
