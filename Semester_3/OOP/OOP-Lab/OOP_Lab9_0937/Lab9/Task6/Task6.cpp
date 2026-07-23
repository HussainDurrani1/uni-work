#include <iostream>
#include "Employee.h"
#include "Manager.h"
using namespace std;

void takeUserInput(char (&name)[100], int &id, int &tS, double &salary, double &budget) {
	cout << "Enter Employee Name: ";
	cin.getline(name, 100);
	cout << "Enter Employee ID: ";
	cin >> id;
	cout << "Enter Salary: ";
	cin >> salary;
	cout << "Enter Team Size: ";
	cin >> tS;
	cout << "Enter Budget: ";
	cin >> budget;
	cin.ignore();
}

int main() {
	char name[100];
	int empID = 0, teamSize = 0;
	double salary = 0.0, budget = 0.0;
	
	Manager m1;
	cout << "Manager 1: \n";
	m1.displayManager();
	
	// Cannot do this when inherited privately:
	//cout << "Enter new Name for Manager 1: "; cin.getline(name, 100);
	//m1.setName(name);
	//cout << "Enter new Salary for Manager 1: "; cin >> salary;
	//m1.setSalary(salary);
	//m1.getBudget();
	//m1.name;
	//m1.getSalary();
	
	//cin.ignore();
	takeUserInput(name, empID, teamSize, salary, budget);

	cout << "Manager 2: \n";
	Manager m2(teamSize, budget, name, salary, empID);
	m2.displayManager();

	return 0;
}