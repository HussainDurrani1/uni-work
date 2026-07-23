#pragma once
#include <iostream>
using namespace std;

class Course{
public:
    string name;
    string code;
    int credits;

    Course() {}

    Course(string n, string c, int cr){
        name = n;
        code = c;
        credits = cr;
    }

    void display() const{
        cout << "Course Name: " << name << endl;
        cout << "Course Code: " << code << endl;
        cout << "Credits: " << credits << endl;
    }
};