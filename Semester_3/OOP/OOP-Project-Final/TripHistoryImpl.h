#pragma once
#include "TripHistory.h"
#include "RideRequest.h" 

TripHistory::TripHistory(bool owns) {
    count = 0;
    capacity = 0;
    rides = nullptr;
    ownsObjects = owns;
}

TripHistory::~TripHistory() {
    if (rides != nullptr) {
        if (ownsObjects) {
            for (int i = 0; i < count; i++) {
                delete rides[i];
            }
        }
        delete[] rides;
    }
}

void TripHistory::addTrip(RideRequest* ride) {
    if (count == capacity) {
        int newCapacity = (capacity == 0) ? 5 : capacity * 2;
        RideRequest** newRides = new RideRequest * [newCapacity];

        for (int i = 0; i < count; i++) {
            newRides[i] = rides[i];
        }

        delete[] rides;
        rides = newRides;
        capacity = newCapacity;
    }
    rides[count++] = ride;
}

RideRequest* TripHistory::getRide(int index) const {
    if (index >= 0 && index < count) return rides[index];
    return nullptr;
}

void TripHistory::displayHistory() const {
    if (count == 0) {
        cout << "No trip history." << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "Trip " << (i + 1) << ": ";
        rides[i]->display(); 
        cout << "------------------------" << endl;
    }
}
