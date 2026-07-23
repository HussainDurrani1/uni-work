#pragma once
#include <iostream>
#include "Rider.h"
#include "Driver.h"
#include "MatchingEngine.h"
#include "RideRequest.h"
#include "MapService.h"
#include "Notification.h"
#include "Utils.h"

using namespace std;

class BookingManager {
private:
    MatchingEngine* matcher;

public:
    BookingManager(MatchingEngine* m) {
        matcher = m;
    }

    RideRequest* bookRide(Rider* rider, Location pickup, Location drop, const char* vehicleType) {
        if (rider == nullptr) {
            cout << "Invalid Rider." << endl;
            return nullptr;
        }

        cout << "--- Booking Ride for " << rider->getName() << " ---" << endl;

        double distance = MapService::calculateDistance(pickup, drop);
        int time = MapService::estimateTime(distance);
        MapService::displayRouteInfo(pickup, drop);

        Driver* driver = matcher->findDriver(vehicleType, pickup);

        if (driver != nullptr) {
            char* now = copyString("Now");

            Route route(pickup, drop, "Standard Trip", vehicleType);

            RideRequest* request = new RideRequest(rider, route, now);

            request->assignDriver(driver);
            driver->acceptRide(request->getRideId());
            rider->requestRide(request);

            cout << "Ride Booked! Driver: " << driver->getName() << endl;

            char* riderMsg = concatString("Ride Confirmed! Driver: ", driver->getName());
            rider->addNotification(new Notification(riderMsg, now));

            char* driverMsg = concatString("New Ride Request! Passenger: ", rider->getName());
            
            driver->addNotification(new Notification(driverMsg, now));

            delete[] now;
            delete[] riderMsg;
            delete[] driverMsg;

            return request;
        }
        else {
            cout << "Booking Failed: No Info or No Driver Available." << endl;
            char* failMsg = copyString("Booking Failed: No Driver Found.");
            rider->addNotification(new Notification(failMsg, "Now"));
            delete[] failMsg;
            return nullptr;
        }
    }
};
