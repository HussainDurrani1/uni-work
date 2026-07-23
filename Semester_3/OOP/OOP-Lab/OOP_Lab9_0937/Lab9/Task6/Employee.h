#pragma once
#include <iostream>
using namespace std;

int getLen(const char* str) {
	int len = 0;
	while (str[len] != '\0')len++;
	return len;
}

char* copyStr(const char* src) {
	int len = getLen(src);
	char* dest = new char[len + 1];
	for (int i = 0; i < len; i++) dest[i] = src[i];
	dest[len] = '\0';
	return dest;
}

class Employee
{
protected:
	char* name;
	double salary;
	int empID;

public:
	Employee() : empID(0), salary(0.0) {
		name = copyStr("Unknown");
	}

	Employee(char* nom, double s, int id) : salary(s), empID(id) {
		name = copyStr(nom);
	}

	~Employee() {
		delete[] name;
	}

	void setName(const char* nom) {
		delete[] name;
		name = copyStr(nom);
	}
	char* getName() const { return name; }

	void setSalary(double s) { salary = s; }
	double getSalary() const { return salary; }

	void setEmpID(int id) { empID = id; }
	int getEmpID() const { return empID; }

	void displayEmployee() const {
		cout << "Employee Name: " << getName() << ", Employee ID: " << getEmpID() << ", Salary: " << getSalary() << ".\n";
	}
};