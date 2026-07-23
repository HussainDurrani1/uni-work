#include <iostream>
#include "Student.h"
#include "Club.h"
#include "Membership.h"
using namespace std;

int main() {
    int id;
    string sName, cName;

    cout << "--- Create Student ---\n";
    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore(); 
    
    cout << "Enter Student Name: ";
    cin >> sName;
    Student s1(id, sName);

    cout << "\n--- Create Club ---\n";
    cout << "Enter Club Name: ";
    cin >> cName;
    Club c1(cName);
    Membership member1(&s1, &c1);
    cout << "\n------------------------------------------------\n";
    cout << "FINAL MEMBERSHIP RECORD\n";
    member1.display();
    cout << "------------------------------------------------\n";

    return 0;
}