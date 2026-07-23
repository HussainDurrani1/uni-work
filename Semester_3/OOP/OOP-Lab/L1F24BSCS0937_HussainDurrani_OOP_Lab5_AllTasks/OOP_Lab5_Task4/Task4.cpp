#include "Employee.h"
#include <iostream>
using namespace std;

int Employee::employeeCount = 0;


int main() {

	int age;
	float salary;
	char name1[100];

	cout << "Enter the name of the Employee 1: ";
	cin.getline(name1, 100);
	cout << "Enter the age of the Employee 1: ";
	cin >> age;
	cout << "Enter the salary of the Employee 1: ";
	cin >> salary;

	Employee e1(name1, age, salary);


	char name2[100];

	cout << "Enter the name of the Employee 2: ";
	cin.ignore();
	cin.getline(name2, 100);
	cout << "Enter the age of the Employee 2: ";
	cin >> age;
	cout << "Enter the salary of the Employee 2: ";
	cin >> salary;
	
	Employee e2(name2, age, salary);

	cout << "Total Employees: " << Employee::getEmployeeCount() << endl;

	e1.display();
	e2.display();

	const Employee e3("Constant Employee", 35, 5000);
	cout << "Employee 3 Name: " << e3.getName() << endl;
	cout << "Employee 3 Salary: " << e3.getSalary() << endl;

	cout << "Total Employees: " << Employee::getEmployeeCount() << endl;

	// Since e3 is a const object, it cannot be modified, and the following would cause an error: 
	// e3.setSalary(6000);  // Uncommenting this would result in a compile-time error 

	return 0;
}
