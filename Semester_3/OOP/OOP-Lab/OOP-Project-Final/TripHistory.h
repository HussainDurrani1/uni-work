#pragma once
class RideRequest;

using namespace std;

class TripHistory {
private:
    RideRequest** rides;
    int count;
    int capacity;
    bool ownsObjects;

public:
    TripHistory(bool owns = false);
    ~TripHistory();

    void addTrip(RideRequest* ride);
    int getCount() const { return count; }
    RideRequest* getRide(int index) const;
    void displayHistory() const;
};
