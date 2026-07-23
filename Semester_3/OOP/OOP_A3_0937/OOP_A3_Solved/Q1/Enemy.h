#pragma once
#include "Character.h"
#include <iostream>
using namespace std;

class Enemy : virtual public Character {
protected:
    int damage;

public:
    Enemy(): damage(0), Character("Player", 0){}

    Enemy(string n, int h, int d) : Character(n, h) {
        damage = d;
    }

    void displayEnemy() const {
        cout << "Enemy Damage: " << damage << endl;
    }
};