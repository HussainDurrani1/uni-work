#pragma once
#include "Vehicle.h"

class Rickshaw : public Vehicle
{
private:
    bool covered; 

public:
    Rickshaw(const char* m, int id, const char* plate, int cap = 3, const char* c = "Yellow", bool hasRoof = true)
        : Vehicle(m, id, plate, cap, c, "Rickshaw")
    {
        covered = hasRoof;
        baseFare = 20.0f;
        perKmRate = 6.0f;
        perMinuteRate = 1.0f;
    }

    bool isCovered() const
    {
        return covered; 
    }

    float calculateFare(float distanceKm, float durationMinutes) const
    {
        float fare = baseFare + (perKmRate * distanceKm) + (perMinuteRate * durationMinutes);
        if (covered) {
            fare += 3.0f; 
        }
        return fare;
    }

    void display() const
    {
        cout << "--- Rickshaw Info ---" << endl;
        Vehicle::display();
        cout << "Covered: " << (covered ? "Yes" : "No") << endl;
    }
};
