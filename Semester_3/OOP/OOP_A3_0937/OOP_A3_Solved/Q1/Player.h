#pragma once
#include "Character.h"
#include <iostream>
using namespace std;

class Player : virtual public Character {
protected:
    int level;

public:
    Player(): level(0), Character("Player", 0) {}

    Player(string n, int h, int l) : Character(n, h) {
        level = l;
    }

    void displayPlayer() const {
        cout << "Player Level: " << level << endl;
    }
};