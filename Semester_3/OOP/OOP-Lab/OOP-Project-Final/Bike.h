#pragma once
#include "Vehicle.h"

class Bike : public Vehicle
{
private:
    bool helmet; 

public:
    Bike(const char* m, int id, const char* plate, int cap = 1, const char* c = "Black", bool providesHelmet = true)
        : Vehicle(m, id, plate, cap, c, "Bike")
    {
        helmet = providesHelmet;
        baseFare = 30.0f;
        perKmRate = 8.0f;
        perMinuteRate = 1.5f;
    }

    bool hasHelmet() const
    {
        return helmet;
    }

    float calculateFare(float distanceKm, float durationMinutes) const
    {
        float fare = baseFare + (perKmRate * distanceKm) + (perMinuteRate * durationMinutes);

        if (helmet) {
            fare += 5.0f; 
        }
        
        return fare;
    }

    void display() const
    {
        cout << "--- Bike Info ---" << endl;
        Vehicle::display();
        cout << "Helmet Provided: " << (helmet ? "Yes" : "No") << endl;
    }
};
