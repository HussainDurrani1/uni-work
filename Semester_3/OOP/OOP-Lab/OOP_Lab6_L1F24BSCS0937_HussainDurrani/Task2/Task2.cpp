#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    int count = 5;
    Student* students[5];

    for (int i = 0; i < count; i++) {
        char name[100];
        cout << "Enter the name of the Student " << i+1 << ": ";
        cin.getline(name, 100);

        int marks = 0;
        cout << "Enter marks of Student " << i+1 << ": ";
        cin >> marks;
        cin.ignore();
        students[i] = new Student(name, marks);
    }

    cout << "Student Details: \n";
    for (int i = 0; i < count; i++) {
        students[i]->display();
    }

    return 0;
}