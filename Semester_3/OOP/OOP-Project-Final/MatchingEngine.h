#pragma once

#include <iostream>
#include "Driver.h"
#include "RideRequest.h"
#include "Route.h"
#include "Location.h"
using namespace std;

class MatchingEngine
{
private:
    Driver** drivers;
    int driverCount;

    float calculateDistance(Location a, Location b)
    {
        float dx = a.getLatitude() - b.getLatitude();
        float dy = a.getLongitude() - b.getLongitude();

        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;

        return dx + dy;   
    }

public:
    MatchingEngine()
    {
        drivers = NULL;
        driverCount = 0;
    }

    void setDrivers(Driver** list, int count)
    {
        drivers = list;
        driverCount = count;
    }

    // ---------------- OLD SYSTEM ----------------
    Driver* findDriver(RideRequest* request)
    {
        if (!request || !drivers)
            return NULL;

        Route* route = request->getRoute();
        if (route == NULL)
            return NULL;

        return findDriver(route->getVehicleType(), route->getPickup());
    }

    // ---------------- NEW SYSTEM ----------------
    Driver* findDriver(const char* vehicleType, Location pickup)
    {
        Driver* bestDriver = NULL;
        float bestScore = 999999;

        for (int i = 0; i < driverCount; i++)
        {
            if (drivers[i]->isAvailable())
            {
                if (drivers[i] == nullptr) continue;

                Vehicle* v = drivers[i]->getVehicle();
                if (v == nullptr) continue;

                const char* driverType = v->getVehicleType();
                if (driverType == nullptr) continue;

                if (!compareString(driverType, vehicleType))
                    continue;

                float dist = calculateDistance(drivers[i]->getLocation(), pickup);
                float rating = drivers[i]->getRating();
                float score = dist - (rating * 2);

                if (bestDriver == NULL || score < bestScore)
                {
                    bestScore = score;
                    bestDriver = drivers[i];
                }
            }
        }

        return bestDriver;
    }
};
