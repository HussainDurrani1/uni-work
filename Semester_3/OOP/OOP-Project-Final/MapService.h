#pragma once
#include <iostream>
#include <cmath>
#include "Location.h"

using namespace std;

class MapService {
public:
    static double calculateDistance(Location start, Location end) {
        double dLat = end.getLatitude() - start.getLatitude();
        double dLon = end.getLongitude() - start.getLongitude();
        return sqrt(dLat * dLat + dLon * dLon) * 111.0;
    }

    static int estimateTime(double distanceKm) {
        if (distanceKm <= 0) return 0;
        return (int)((distanceKm / 40.0) * 60.0);
    }

    static void displayRouteInfo(Location start, Location end) {
        double dist = calculateDistance(start, end);
        int time = estimateTime(dist);
        cout << "Route Info:" << endl;
        cout << "  Distance: " << dist << " km" << endl;
        cout << "  Est. Time: " << time << " mins" << endl;
    }
};
