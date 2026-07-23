#pragma once
#include <iostream>
using namespace std;
class Employee {
private:
    int id;
    double salary;

public:
    Employee() : id(1), salary(1000.10) {}

    Employee(int i, double s) : id(i), salary(s) {}

    void setId(int i) { id = i; }
    int getId() const { return id; }

    void setSalary(double s) { salary = s; }
    double getSalary() const { return salary; }

    void display() const {
        cout << "Employee ID: " << id << ", Salary: " << salary << endl;
    }

    ~Employee() {
    }
};