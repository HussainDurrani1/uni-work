#pragma once
#include <iostream>
using namespace std;

class Student {
private:
    int studentID;
    string name;

public:
    Student(int id, string n) {
        studentID = id;
        name = n;
    }
    void setID(int id) { studentID = id; }
    void setName(string n) { name = n; }

    int getID() const { return studentID; }
    string getName() const { return name; }

    void display() const {
        cout << "Student: " << name << " (ID: " << studentID << ")";
    }
};