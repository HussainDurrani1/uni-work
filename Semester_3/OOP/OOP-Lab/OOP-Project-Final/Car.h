#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
private:
    bool ac; 

public:
    Car(const char* m, int id, const char* plate, int cap = 4, const char* c = "White", bool hasAC = true)
        : Vehicle(m, id, plate, cap, c, "Car") {
        ac = hasAC;
        baseFare = 50.0f;
        perKmRate = 12.0f;
        perMinuteRate = 3.0f;
    }

    bool hasAC() const
    {
        return ac;
    }

    float calculateFare(float distanceKm, float durationMinutes) const
    {
        float fare = baseFare + (perKmRate * distanceKm) + (perMinuteRate * durationMinutes);
        if (ac) {
            fare += 10.0f;
        }
        return fare;
    }

    void display() const
    {
        cout << "--- Car Info ---" << endl;
        Vehicle::display();
        cout << "AC: " << (ac ? "Yes" : "No") << endl;
    }
};
