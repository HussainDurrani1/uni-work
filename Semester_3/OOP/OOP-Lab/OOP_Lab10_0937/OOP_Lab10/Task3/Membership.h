#pragma once
#include <iostream>
#include "Student.h"
#include "Club.h"
using namespace std;

class Membership {
private:
    Student* student;
    Club* club;

public:
    Membership(Student* s, Club* c) {
        student = s;
        club = c;
    }
    void display() const {
        cout << "Membership Record:\n";
        cout << "   "; student->display(); cout << "\n";
        cout << "   Joined -> "; club->display(); cout << "\n";
    }
};