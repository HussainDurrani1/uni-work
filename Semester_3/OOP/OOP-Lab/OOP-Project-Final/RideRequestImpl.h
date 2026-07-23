#pragma once
#include "RideRequest.h"
#include "Rider.h"
#include "Driver.h"


RideRequest::RideRequest(Rider* r, Route rt, const char* reqTime)
    : rider(r), route(rt)
{
    assignedDriver = nullptr;
    accepted = false;
    completed = false;
    canceled = false;
    fare = 0.0f;
    rideId = ++rideCounter;

    requestTime = copyString(reqTime);
    startTime = copyString("N/A");
    endTime = copyString("N/A");
    rating = nullptr;
}

RideRequest::~RideRequest()
{
    delete[] requestTime;
    delete[] startTime;
    delete[] endTime;
    if (rating != nullptr) delete rating;
}

void RideRequest::assignDriver(Driver* d)
{
    assignedDriver = d;
    accepted = true;
    if (assignedDriver != nullptr && assignedDriver->getVehicle() != nullptr)
    {
        route.setVehicleType(assignedDriver->getVehicle()->getVehicleType());
        d->acceptRide(rideId);
    }
}

void RideRequest::startRide(const char* start)
{
    if (accepted && !canceled)
    {
        delete[] startTime;
        startTime = copyString(start);
    }
}

void RideRequest::completeRideState(const char* end)
{
    if (accepted && !canceled && startTime[0] != '\0')
    {
        delete[] endTime;
        endTime = copyString(end);
        completed = true;
    }
}

void RideRequest::cancelRide()
{
    if (!completed)
    {
        canceled = true;
        accepted = false;
    }
}

void RideRequest::rateRide(float score, const char* comment) {
    if (completed && rating == nullptr) {
        rating = new Rating(score, comment);
        cout << "Ride " << rideId << " rated successfully." << endl;
    }
    else {
        cout << "Cannot rate ride. Either not completed or already rated." << endl;
    }
}

void RideRequest::display() const
{
    cout << "--- Ride Info ---" << endl;
    cout << "Ride ID: " << rideId << endl;
    cout << "Rider: " << (rider != nullptr ? rider->getName() : "Unknown") << endl;
    cout << "Driver: " << (assignedDriver != nullptr ? assignedDriver->getName() : "Not assigned") << endl;
    route.display(); 
    cout << "Fare: " << fare << endl;
    cout << "Request Time: " << requestTime << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Accepted: " << (accepted ? "Yes" : "No") << endl;
    cout << "Completed: " << (completed ? "Yes" : "No") << endl;
    cout << "Canceled: " << (canceled ? "Yes" : "No") << endl;
    if (rating != nullptr) {
        rating->display();
    }
}
