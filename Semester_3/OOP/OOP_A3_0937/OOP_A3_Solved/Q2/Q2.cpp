#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
#include "Owner.h"
using namespace std;

int main() {
    string oName, vName, model;
    int year, choice, engNum;

    cout << "Enter Owner Name: ";
    cin >> oName;
    Owner owner(oName);

    cout << "Select Vehicle to buy:\n1. Car\n2. Motorcycle\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter Make (Name): ";
    cin >> vName;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Year: ";
    cin >> year;
    cin.ignore();
    cout << "Enter Engine Number: ";
    cin >> engNum;

    Vehicle* myVehicle = nullptr;

    if (choice == 1) {
        myVehicle = new Car(model, year, vName, engNum);
    }
    else {
        myVehicle = new Motorcycle(model, year, vName, engNum);
    }

    owner.setVehicle(myVehicle);

    cout << "\n--- Ownership Details ---\n";
    owner.showOwnership();

    Delete myVehicle;
    myVehicle  = nullptr;

    return 0;
}
