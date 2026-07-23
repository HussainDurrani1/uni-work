#pragma once
#include <iostream>
#include "Location.h"
#include "Vehicle.h"
#include "Route.h"
#include "Utils.h"
#include "Rating.h"

using namespace std;

class Rider;
class Driver;

class RideRequest
{
private:
    int rideId;
    static int rideCounter;

    Rider* rider;
    Driver* assignedDriver;

    Route route;
    Rating* rating;

    bool accepted;
    bool completed;
    bool canceled;

    float fare;

    char* requestTime;
    char* startTime;
    char* endTime;

public:
    RideRequest(Rider* r, Route rt, const char* reqTime = "N/A");

    ~RideRequest();

    void assignDriver(Driver* d);
    void startRide(const char* start);
    void completeRideState(const char* end);
    void cancelRide();
    void rateRide(float score, const char* comment);

    int getRideId() const { return rideId; }
    Rider* getRider() const { return rider; }
    Driver* getDriver() const { return assignedDriver; }
    Driver* getAssignedDriver() const { return assignedDriver; }
    Route* getRoute() { return &route; }
    bool isAccepted() const { return accepted; }
    bool isCompleted() const { return completed; }
    bool isCanceled() const { return canceled; }
    float getFare() const { return fare; }
    const char* getRequestTime() const { return requestTime; }
    const char* getStartTime() const { return startTime; }
    const char* getEndTime() const { return endTime; }
    const char* getRequestedVehicleType() const { return route.getVehicleType(); }

    void setFare(double f) { fare = f; }
    void setCompleted(bool c) { completed = c; }

    void display() const;
};

// Initialize static member
int RideRequest::rideCounter = 0;

