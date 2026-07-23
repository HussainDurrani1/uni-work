#pragma once
#include "User.h"
#include "Vehicle.h"
#include "Utils.h"
#include "Utils.h"
#include "Wallet.h"
#include "TripHistory.h"
#include "RideRequest.h"

class Driver : public User
{
private:
    Vehicle* vehicle;

    bool available;
    bool online;
    int currentRideId;
    int completedRides;
    double latitude;
    double longitude;
    Wallet* wallet;
    TripHistory* history;
    char* licenseNumber;
    bool verified;

public:
    Driver() : User()
    {
        vehicle = nullptr;
        available = true;
        online = false;
        currentRideId = -1;
        completedRides = 0;
        latitude = 0.0;
        longitude = 0.0;
        wallet = new Wallet();
        history = new TripHistory(false);
        verified = false;
        licenseNumber = copyString("Unknown");
    }

    // Parameterized constructor
    Driver(int id, const char* n, const char* p, const char* e, const char* lic)
        : User(id, n, p, e)
    {
        vehicle = nullptr;
        available = true;
        online = false;
        currentRideId = -1;
        completedRides = 0;
        latitude = 0.0;
        longitude = 0.0;
        wallet = new Wallet();
        history = new TripHistory(false);
        verified = false;
        licenseNumber = copyString(lic);
    }

    Driver(const Driver& other) : User(other)
    {
        vehicle = other.vehicle;
        available = other.available;
        online = other.online;
        currentRideId = other.currentRideId;
        completedRides = other.completedRides;
        latitude = other.latitude;
        longitude = other.longitude;
        wallet = new Wallet(*other.wallet); 
        history = new TripHistory(false); 
        verified = other.verified;
        licenseNumber = copyString(other.licenseNumber);
    }

    Driver& operator=(const Driver& other)
    {
        if (this != &other)
        {
            User::operator=(other);
            vehicle = other.vehicle;
            available = other.available;
            online = other.online;
            currentRideId = other.currentRideId;
            completedRides = other.completedRides;
            latitude = other.latitude;
            longitude = other.longitude;

            delete wallet;
            wallet = new Wallet(*other.wallet); 

            if (history != nullptr) delete history;
            history = new TripHistory(false);

            verified = other.verified;

            delete[] licenseNumber;
            licenseNumber = copyString(other.licenseNumber);
        }
        return *this;
    }

    virtual ~Driver()
    {
        delete wallet; 
        if (history != nullptr) delete history;
        delete[] licenseNumber;
    }

    void assignVehicle(Vehicle* v) {
        vehicle = v;
    }
    Vehicle* getVehicle() const {
        return vehicle;
    }

    void goOnline() {
        if (verified) {
            online = true;
        }
    }
    void goOffline() {
        online = false; available = false;
    }

    bool isAvailable() const {
        return available && online;
    }

    void updateLocation(double lat, double lon)
    {
        latitude = lat;
        longitude = lon;
    }

    bool acceptRide(int rideId)
    {
        if (!isAvailable()) return false;
        currentRideId = rideId;
        available = false;
        return true;
    }

    void completeRide(RideRequest* ride, const char* end)
    {
        if (ride == nullptr) return;

        ride->completeRideState(end);

        double fare = 0.0;

        if (vehicle != nullptr) {
            fare = vehicle->calculateFare(ride->getRoute()->getDistance(), (float)ride->getRoute()->getEstimatedTime());

            vehicle->setAvailability(true);

            ride->setFare(fare); 
        }

        available = true;
        char* rideIdStr = intToString(currentRideId);
        char* desc = concatString("Earnings for Ride ", rideIdStr);

        currentRideId = -1;
        completedRides++;

        wallet->addFunds(fare, desc);

        history->addTrip(ride);

        delete[] rideIdStr;
        delete[] desc;
    }

    void endRide(double fare)
    {
        available = true;

        char* rideIdStr = intToString(currentRideId);
        char* desc = concatString("Earnings for Ride ", rideIdStr);

        currentRideId = -1;
        completedRides++;
        wallet->addFunds(fare, desc);

        delete[] rideIdStr;
        delete[] desc;
    }

    virtual void addRating(float r)
    {
        User::addRating(r);
    }

    double getTotalEarnings() const { return wallet->getBalance(); }

    const char* getLicenseNumber() const { return licenseNumber; }
    
    void verifyDriver() { verified = true; }
    Location getLocation() const
    {
        Location loc(getName(), "N/A", "N/A", latitude, longitude);
        return loc;
    }


    // Polymorphic display
    virtual void display() const
    {
        User::display();
        cout << "Driver Info:\n";
        cout << "License: " << licenseNumber << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
        cout << "Online: " << (online ? "Yes" : "No") << endl;
        cout << "Completed Rides: " << completedRides << endl;
        cout << "Location: (" << latitude << ", " << longitude << ")" << endl;
        history->displayHistory();
        wallet->display(); // Show wallet info
        cout << "Verified: " << (verified ? "Yes" : "No") << endl;
    }

    // Polymorphic profile update
    virtual void updateProfile(const char* n, const char* p, const char* e)
    {
        User::updateProfile(n, p, e);
    }
};
