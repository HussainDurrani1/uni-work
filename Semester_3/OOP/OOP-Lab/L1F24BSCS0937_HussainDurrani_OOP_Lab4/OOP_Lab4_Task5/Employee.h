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

	void setEmployeeId(int id) { employeeId = id; }
	void setSalary(double s) { salary = s; }

	void setName(const char* n) {
		if (name != nullptr)
			delete[] name;
		int len = 0;
		while (n[len] != '\0')
			len++;
		name = new char[len + 1];
		for (int i = 0; i < len; i++)
			name[i] = n[i];
		name[len] = '\0';
	}

	void giveRaise(double percent) {
		double increase = (salary * percent) / 100;
		salary += increase;
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