#pragma once
#include "Player.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

class Boss : public Player, public Enemy {
private:
    string specialAbility;

public:
    Boss() : specialAbility("Flying"), Character("Player", 0), Player("Player", 0, 0), Enemy("Player", 0, 0) {}

    Boss(string n, int h, int l, int d, string ability)
        : Character(n, h), Player(n, h, l), Enemy(n, h, d) {
        specialAbility = ability;
    }

    void displayDetails() const {
        cout << "\n--- BOSS DETAILS ---\n";
        displayCharacter(); 
        displayPlayer();    
        displayEnemy();     
        cout << "Special Ability: " << specialAbility << endl;
    }
};