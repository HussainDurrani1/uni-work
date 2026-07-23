#include "Employee.h"
#include <iostream>
using namespace std;

int main() {
	int id;
	double sal, percent;
	char tempName[100];

	cout << "Enter Employee Name: ";
	cin.getline(tempName, 100);

	cout << "Enter Employee ID: ";
	cin >> id;

	cout << "Enter Salary: ";
	cin >> sal;

	Employee e1(id);
	e1.setName(tempName);
	e1.setSalary(sal);

	e1.display();

	cout << "Enter Raise Percentage: ";
	cin >> percent;

	cout << "Giving a raise:\t" << percent << "%" << endl;
	e1.giveRaise(percent);

	cout << "New Salary:\t" << e1.getSalary() << endl;

	return 0;
}