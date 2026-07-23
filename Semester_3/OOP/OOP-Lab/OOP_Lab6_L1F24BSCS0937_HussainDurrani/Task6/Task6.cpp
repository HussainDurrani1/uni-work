#include "Rectangle.h"
#include "Calculator.h"
#include "Book.h"
#include "Counter.h"
#include "Employee.h"
#include "Student.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(int l, int w) : length(l), width(w) {}

int calculateArea(const Rectangle& r) {
    return r.length * r.width;
}

int Calculator::area(const Rectangle& r) {
    return r.length * r.width;
}


void performTask() {
    static Counter c;

    c.increment();
    c.displayCount();
}

int main() {
    int choice;
    cout << "---------------------------------------------------------\n";
    cout << "Press 1 Testing Pointer to Objects & (Static Object)\n";
    cout << "Press 2 for testing Array of Pointers to Objects\n";
    cout << "Press 3 for testing Friend functions and friend classes\n";
    cout << "Press 4 for exit.\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cout << "---------------------------------------------------------\n";
    cin.ignore();

    while (choice != 4) {
        if (choice == 1) {

            Book* myBookPtr = nullptr;

            char title[100];
            float price;

            cout << "Enter title of book: ";
            cin.getline(title, 100);

            cout << "Enter price of book: ";
            cin >> price;

            myBookPtr = new Book(title, price);

            myBookPtr->display();

            cout << "\nDeallocating the Book object..." << endl;
            delete myBookPtr;
            myBookPtr = nullptr;

            // ------------------------------------

            cout << "First call to performTask():" << endl;
            performTask();

            cout << "\nSecond call to performTask():" << endl;
            performTask();

            cout << "\nThird call to performTask():" << endl;
            performTask();

            cout << "\nProgram ending..." << endl;

            // ------------------------------------
        }
        else if (choice == 2) {
            int count = 5;
            Student* students[5];

            for (int i = 0; i < count; i++) {
                char name[100];
                cout << "Enter the name of the Student " << i + 1 << ": ";
                cin.getline(name, 100);

                int marks = 0;
                cout << "Enter marks of Student " << i + 1 << ": ";
                cin >> marks;
                cin.ignore();
                students[i] = new Student(name, marks);
            }

            cout << "Student Details: \n";
            for (int i = 0; i < count; i++) {
                students[i]->display();
            }

            // ------------------------------------

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

            // ------------------------------------
        }
        else if (choice == 3) {
            int inputLength, inputWidth;

            cout << "Enter the length of the rectangle: ";
            cin >> inputLength;

            cout << "Enter the width of the rectangle: ";
            cin >> inputWidth;

            Rectangle rect(inputLength, inputWidth);

            cout << "--- Friend Function Demo ---" << endl;
            int area1 = calculateArea(rect);
            cout << "Area calculated by standalone friend function: " << area1 << endl;

            cout << "--- Friend Class Demo ---" << endl;
            Calculator calc;
            int area2 = calc.area(rect);
            cout << "Area calculated by Calculator's member function: " << area2 << endl;
        }
        else {
            cout << "Invalid...\n";
        }
        cout << "\n---------------------------------------------------------\n";
        cout << "Press 1 Testing Pointer to Objects & (Static Object)\n";
        cout << "Press 2 for testing Array of Pointers to Objects\n";
        cout << "Press 3 for testing Friend functions and friend classes\n";
        cout << "Press 4 for exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << "---------------------------------------------------------\n";

    }

    return 0;
}