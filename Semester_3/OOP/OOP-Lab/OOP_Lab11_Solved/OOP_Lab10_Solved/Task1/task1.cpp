#include <iostream>
#include "Person.h"
#include "Employee.h"
#include "Manager.h"
using namespace std;

int main() {
	int teamSize = 0, age = 0, id = 0;
	char name[100], department[100];

	cout << "Enter Name: "; cin.getline(name, 100);
	cout << "Enter Age: "; cin >> age; cin.ignore();
	cout << "Enter your Department: "; cin.getline(department, 100);
	cout << "Enter Employee ID: "; cin >> id;
	cout << "Enter Team Size: "; cin >> teamSize;

	Manager m1(teamSize, name, department, age, id);
	m1.display();

	return 0;
}