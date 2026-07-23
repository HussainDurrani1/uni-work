#pragma once
#include <iostream>
#include <cmath>
#include "Vehicle.h"
#include "PromoCode.h"
#include "Route.h"
#include "Ride.h"

using namespace std;

class FareCalculator
{
private:
    float surgeMultiplier; 
    PromoCode* promo;      

public:
    
    FareCalculator() : surgeMultiplier(1.0f), promo(nullptr) {}

    FareCalculator(float surge, PromoCode* p = nullptr)
        : surgeMultiplier(surge), promo(p) {
    }
    
    void setSurge(float surge) { surgeMultiplier = surge; }
    void setPromoCode(PromoCode* p) { promo = p; }

    float calculateFare(Vehicle* vehicle, Route* route)
    {
        if (!vehicle || !route) return 0.0f;

        // Base distance fare
        float baseFare = vehicle->getBaseFare();
        float distance = route->getDistance();         
        float duration = route->getEstimatedTime();    

        float perMinuteRate = vehicle->getPerMinuteRate();

        float fare = (baseFare * distance) + (perMinuteRate * duration);
        fare *= vehicle->getTypeMultiplier();

        fare *= surgeMultiplier;

        if (promo != nullptr)
        {
            fare = promo->applyDiscount(fare);
        }

        float minFare = vehicle->getMinimumFare();
        if (fare < minFare)
            fare = minFare;

        fare = roundf(fare * 100) / 100.0f;

        return fare;
    }

    float calculateFare(Ride* ride, Route* route)
    {
        if (!ride || !ride->getDriver() || !ride->getDriver()->getVehicle())
            return 0.0f;

        Vehicle* v = ride->getDriver()->getVehicle();
        return calculateFare(v, route);
    }
};
