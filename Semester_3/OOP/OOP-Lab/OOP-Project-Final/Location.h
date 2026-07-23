#pragma once
#include <iostream>
#include "Utils.h"
using namespace std;

class Location
{
private:
    char* name;
    char* address;
    char* city;
    float latitude;
    float longitude;

public:
    Location()
    {
        name = copyString("Unknown");
        address = copyString("N/A");
        city = copyString("N/A");
        latitude = 0.0f;
        longitude = 0.0f;
    }

    Location(const char* n, const char* a, const char* c, float lat, float lon)
    {
        name = copyString(n);
        address = copyString(a);
        city = copyString(c);
        latitude = lat;
        longitude = lon;
    }

    Location(const Location& other)
    {
        name = copyString(other.name);
        address = copyString(other.address);
        city = copyString(other.city);
        latitude = other.latitude;
        longitude = other.longitude;
    }

    Location& operator=(const Location& other)
    {
        if (this != &other)
        {
            delete[] name;
            delete[] address;
            delete[] city;

            name = copyString(other.name);
            address = copyString(other.address);
            city = copyString(other.city);
            latitude = other.latitude;
            longitude = other.longitude;
        }
        return *this;
    }

    ~Location()
    {
        delete[] name;
        delete[] address;
        delete[] city;
    }

    void updateLocation(const char* n, const char* a, const char* c, float lat, float lon)
    {
        delete[] name;
        delete[] address;
        delete[] city;

        name = copyString(n);
        address = copyString(a);
        city = copyString(c);
        latitude = lat;
        longitude = lon;
    }

    float distanceTo(const Location& other) const
    {
        float dx = latitude - other.latitude;
        if (dx < 0) dx = -dx;

        float dy = longitude - other.longitude;
        if (dy < 0) dy = -dy;

        return dx + dy;
    }

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "City: " << city << endl;
        cout << "Latitude: " << latitude << endl;
        cout << "Longitude: " << longitude << endl;
    }

    const char* getName() const { return name; }
    const char* getAddress() const { return address; }
    const char* getCity() const { return city; }
    float getLatitude() const { return latitude; }
    float getLongitude() const { return longitude; }
};
