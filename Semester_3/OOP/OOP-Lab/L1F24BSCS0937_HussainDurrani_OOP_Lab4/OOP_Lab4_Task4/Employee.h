#pragma once
#include <iostream>
using namespace std;

class Employee
{
private:
	char* name;
	int employeeId;
	double salary;

public:
	Employee() {
		name = nullptr;
		employeeId = 0;
		salary = 0.0;
	}

	Employee(int id) {
		name = nullptr;
		employeeId = id;
		salary = 0.0;
	}

	Employee(const Employee& e) {
		employeeId = e.employeeId;
		salary = e.salary;
		if (e.name != nullptr) {
			int length = 0;
			while (e.name[length] != '\0') {
				length++;
			}
			name = new char[length + 1];
			for (int i = 0; i < length; i++) {
				name[i] = e.name[i];
			}
			name[length] = '\0';
		}
		else {
			name = nullptr;
		}
	}

	void setName(const char* n) {
		if (name != nullptr) {
			delete[] name;
		}
		int length = 0;
		while (n[length] != '\0') {
			length++;
		}
		name = new char[length + 1];
		for (int i = 0; i < length; i++) {
			name[i] = n[i];
		}
		name[length] = '\0';
	}

	void setSalary(double s) {
		salary = s;
	}

	void setEmployeeId(int id) {
		employeeId = id;
	}

	char* getName() {
		return name;
	}

	int getEmployeeId() {
		return employeeId;
	}

	double getSalary() {
		return salary;
	}

	void giveRaise(double percent) {
		double increase = (salary * percent) / 100;
		salary = salary + increase;
	}

	void display() {
		cout << "Name:\t\t" << (name ? name : "N/A") << endl;
		cout << "Employee ID:\t" << employeeId << endl;
		cout << "Salary:\t\t" << salary << endl;
	}

	~Employee() {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
	}
};