#pragma once
#include <iostream>
using namespace std;

class Engine {
private:
    string type;
    int horsepower;

public:
    Engine() {
        type = "Standard";
        horsepower = 100;
    }

    Engine(string t, int hp) {
        type = t;
        horsepower = hp;
    }

    void setType(string t) { type = t; }
    void setHP(int hp) { horsepower = hp; }

    string getType() const { return type; }
    int getHP() const { return horsepower; }

    void display() const {
        cout << "Engine Type: " << type << " | Horsepower: " << horsepower << "HP\n";
    }
};