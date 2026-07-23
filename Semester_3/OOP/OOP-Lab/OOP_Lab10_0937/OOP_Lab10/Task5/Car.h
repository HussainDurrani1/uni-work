#pragma once
#include <iostream>
#include "Engine.h"
using namespace std;

class Car {
private:
    Engine* engine; 

public:
    Car() {
        engine = new Engine();
    }

    Car(string type, int hp) {
        engine = new Engine(type, hp);
    }

    ~Car() {
        delete engine;
        cout << "(Car object destroyed, Engine deleted)\n";
    }

    void setEngineDetails(string type, int hp) {
        engine->setType(type);
        engine->setHP(hp);
    }

    Engine* getEngine() const { return engine; }

    void display() const {
        cout << "Car Details:\n";
        cout << "   Status: Functional\n";
        cout << "   ";
        engine->display();
    }
};