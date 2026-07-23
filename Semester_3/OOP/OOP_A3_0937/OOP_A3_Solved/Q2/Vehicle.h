#pragma once
#include <iostream>
using namespace std;

class Vehicle {
protected:
    string type;
    string model;
    string name;
    int year;
    int engineNumber;

public:
    Vehicle(): year(2000), type("Any"), model("S"), name("Unknown"), engineNumber(0){}

    Vehicle(string t, string m, int y, string n, int eng) {
        type = t;
        model = m;
        year = y;
        name = n;
        engineNumber = eng;
    }

    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;

    string getName() const { return name; }
    string getModel() const { return model; }

    virtual void displayInfo() const {
        cout << year << " " << name << " " << model << " (" << type << ")";
    }
};