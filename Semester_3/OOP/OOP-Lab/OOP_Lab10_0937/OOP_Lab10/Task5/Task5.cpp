#include <iostream>
#include "Engine.h"
#include "Car.h"
using namespace std;

int main() {
    string type;
    int hp;

    cout << "--- Car Manufacturing Plant ---\n";
    cout << "Enter Engine Type (e.g., V8, Electric): ";
    cin >> type;

    cout << "Enter Horsepower: ";
    cin >> hp;
    cin.ignore();

    cout << "\nBuilding Car...\n";
    Car myCar(type, hp);

    cout << "\n----------------------------------------\n";
    cout << "FINAL CAR SPECS\n";
    cout << "----------------------------------------\n";
    myCar.display();

    cout << "\nExiting program...\n";
    return 0;
}