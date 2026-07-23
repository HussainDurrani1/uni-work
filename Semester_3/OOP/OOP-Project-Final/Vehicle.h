#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;

class Driver; 

class Vehicle
{
protected:
    char* model;
    int vehicleId;
    char* licensePlate;
    char* color;
    int capacity;
    Driver* driver;
    bool available;
    bool verified;
    float rating;
    int totalRatings;
    float baseFare;
    float perKmRate;
    float perMinuteRate;
    char* type;
    float typeMultiplier;
    float minimumFare;

public:
    Vehicle()
    {
        model = copyString("Unknown");
        vehicleId = 0;
        licensePlate = copyString("N/A");
        color = copyString("Unknown");
        capacity = 1;
        driver = nullptr;
        available = true;
        verified = false;
        rating = 0.0f;
        totalRatings = 0;
        baseFare = 0.0f;
        perKmRate = 0.0f;
        perMinuteRate = 0.0f;
        typeMultiplier = 1.0f;
        minimumFare = 30.0f;
        type = copyString("Unknown");
    }


    Vehicle(const char* m, int id, const char* plate, int cap = 1, const char* c = "Unknown", const char* t = "Unknown")
    {
        model = copyString(m);
        vehicleId = id;
        licensePlate = copyString(plate);
        color = copyString(c);
        type = copyString(t);
        capacity = cap;
        driver = nullptr;
        available = true;
        verified = false;
        rating = 0.0f;
        totalRatings = 0;
        baseFare = 50.0f;
        perKmRate = 10.0f;
        perMinuteRate = 2.0f;
        typeMultiplier = 1.0f;
        minimumFare = 30.0f;
    }

    virtual ~Vehicle()
    {
        delete[] model;
        delete[] licensePlate;
        delete[] color;
        delete[] type;
    }

    const char* getVehicleType() const
    {
        return type;
    }

    void assignDriver(Driver* d)
    {
        driver = d;
    }

    Driver* getDriver() const
    {
        return driver;
    }

    void setAvailability(bool status)
    {
        available = status;
    }

    bool isAvailable() const
    {
        return available && verified;
    }

    void verifyVehicle()
    {
        verified = true;
    }

    bool isVerified() const
    {
        return verified;
    }

    void addRating(float r)
    {
        rating = (rating * totalRatings + r) / (totalRatings + 1);
        totalRatings++;
    }

    float getRating() const
    {
        return rating;
    }

    int getVehicleId() const { return vehicleId; }
    const char* getModel() const { return model; }
    const char* getLicensePlate() const { return licensePlate; }
    const char* getColor() const { return color; }
    int getCapacity() const { return capacity; }
    float getPerMinuteRate() const { return perMinuteRate; }
    float getTypeMultiplier() const { return typeMultiplier; }
    float getMinimumFare() const { return minimumFare; }

    virtual float getBaseFare() const
    {
        return baseFare;
    }

    virtual float calculateFare(float distanceKm, float durationMinutes) const
    {
        float fare = baseFare + (perKmRate * distanceKm) + (perMinuteRate * durationMinutes);
        fare *= typeMultiplier;
        if (fare < minimumFare) fare = minimumFare;
        return fare;
    }

    virtual void display() const
    {
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Model: " << model << endl;
        cout << "License Plate: " << licensePlate << endl;
        cout << "Color: " << color << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Verified: " << (verified ? "Yes" : "No") << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
        cout << "Rating: " << rating << endl;
        if (driver != nullptr)
            cout << "Driver Assigned" << endl;
    }
};
