#pragma once
#include "Location.h"
#include "Utils.h"
#include <iostream>
using namespace std;

class Route
{
private:
    Location pickup;
    Location drop;
    float distance;
    int estimatedTime;
    char* routeName;
    char* vehicleType;  

public:
    Route()
        : pickup(), drop()
    {
        distance = 0.0f;
        estimatedTime = 0;
        routeName = copyString("Unnamed Route");
        vehicleType = copyString("Any");
    }

    Route(Location p, Location d, const char* name, const char* vType = "Any", float avgSpeed = 40.0f)
        : pickup(p), drop(d)
    {
        routeName = copyString(name);
        vehicleType = copyString(vType);
        distance = pickup.distanceTo(drop);
        estimatedTime = calculateEstimatedTime(avgSpeed);
    }

    ~Route()
    {
        delete[] routeName;
        delete[] vehicleType;
    }

    Route(const Route& other)
        : pickup(other.pickup), drop(other.drop)
    {
        distance = other.distance;
        estimatedTime = other.estimatedTime;
        routeName = copyString(other.routeName);
        vehicleType = copyString(other.vehicleType);
    }

    Route& operator=(const Route& other)
    {
        if (this != &other)
        {
            delete[] routeName;
            delete[] vehicleType;

            pickup = other.pickup;
            drop = other.drop;
            distance = other.distance;
            estimatedTime = other.estimatedTime;
            routeName = copyString(other.routeName);
            vehicleType = copyString(other.vehicleType);
        }
        return *this;
    }

    void updateRoute(Location p, Location d, float avgSpeed = 40.0f)
    {
        pickup = p;
        drop = d;
        distance = pickup.distanceTo(drop);
        estimatedTime = calculateEstimatedTime(avgSpeed);
    }

    void setRouteName(const char* name)
    {
        delete[] routeName;
        routeName = copyString(name);
    }

    void setVehicleType(const char* vType)
    {
        delete[] vehicleType;
        vehicleType = copyString(vType);
    }

    void setEstimatedTime(int time) { estimatedTime = time; }
    void setDistance(float dist) { distance = dist; }

    Location getPickup() const { return pickup; }
    Location getDrop() const { return drop; }
    float getDistance() const { return distance; }
    int getEstimatedTime() const { return estimatedTime; }
    const char* getRouteName() const { return routeName; }
    const char* getVehicleType() const { return vehicleType; }

    int calculateEstimatedTime(float avgSpeed) const
    {
        if (avgSpeed <= 0.0f) return 0;
        return (int)((distance / avgSpeed) * 60.0f); // in minutes
    }

    void display() const
    {
        cout << "--- Route Info ---" << endl;
        cout << "Route Name: " << routeName << endl;
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Pickup: " << pickup.getName() << ", Address: " << pickup.getAddress() << endl;
        cout << "Drop: " << drop.getName() << ", Address: " << drop.getAddress() << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Estimated Time: " << estimatedTime << " minutes" << endl;
    }
};
