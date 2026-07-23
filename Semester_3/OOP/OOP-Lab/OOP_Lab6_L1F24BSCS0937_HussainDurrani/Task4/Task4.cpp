#include "Employee.h"
#include <iostream>
using namespace std;

int main() {
    const int NUM_EMPLOYEES = 3;

    Employee* employees[NUM_EMPLOYEES];

    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        int inputId;
        double inputSalary;

        cout << "Enter details for Employee " << i + 1 << ":" << endl;
        cout << "Enter ID: ";
        cin >> inputId;
        cout << "Enter Salary: ";
        cin >> inputSalary;

        employees[i] = new Employee(inputId, inputSalary);
    }

    cout << "--- Employee Details ---" << endl;
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        if (employees[i] != nullptr) {
            employees[i]->display();
        }
    }

    cout << "--- Deallocating Memory ---" << endl;
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        delete employees[i];
        employees[i] = nullptr;
        cout << "Deleted employee object at index " << i << endl;
    }

    return 0;
}