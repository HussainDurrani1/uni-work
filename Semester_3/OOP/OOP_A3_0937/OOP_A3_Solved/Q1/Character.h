#pragma once
#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int health;

public:
    Character(): health(0), name("Player") {}

    Character(string n, int h) {
        name = n;
        health = h;
    }

    void displayCharacter() const {
        cout << "Name: " << name << " | Health: " << health << endl;
    }
};