#pragma once
#include "Person.h"
class Employee
{
private:
	int employeeID;
	char* department;

public:
	Employee() : employeeID(0), department(copyStr("Unknown")) {}

	Employee(char* dep, int id) : employeeID(id), department(copyStr(dep)) {}

	char* getDepartment() const { return department; }
	void setDepartment(const char* dep) {
		delete[] department;
		department = copyStr(dep);
	}

	int getEmployeeID() const { return employeeID; }
	void setEmployeeID(int id) { employeeID = id; }


	void display() const {
		cout << "Department: " << getDepartment() << ", Employee ID: " << getEmployeeID() << "\n";
	}
};