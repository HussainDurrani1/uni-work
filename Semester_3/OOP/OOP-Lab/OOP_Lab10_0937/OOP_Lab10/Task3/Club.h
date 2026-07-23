#pragma once
#include <iostream>
using namespace std;

class Club {
private:
    string clubName;

public:
    Club(string n) {
        clubName = n;
    }
    void setClubName(string n) { clubName = n; }
    string getClubName() const { return clubName; }

    void display() const {
        cout << "Club: " << clubName;
    }
};