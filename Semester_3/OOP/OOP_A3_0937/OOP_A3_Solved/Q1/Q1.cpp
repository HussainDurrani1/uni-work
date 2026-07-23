#include <iostream>
#include "Boss.h"
using namespace std;

int main() {
    string name, ability;
    int health, level, damage;

    cout << "--- Create Boss Character ---\n";
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Health: ";
    cin >> health;

    cout << "Enter Level (Player Attribute): ";
    cin >> level;

    cout << "Enter Damage (Enemy Attribute): ";
    cin >> damage;
    cin.ignore();

    cout << "Enter Special Ability: ";
    cin >> ability;

    Boss finalBoss(name, health, level, damage, ability);

    finalBoss.displayDetails();

    return 0;
}