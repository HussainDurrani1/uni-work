#pragma once
#include <iostream>
using namespace std;

class Employee {

private:
	char* name;
	int age;
	float salary;
	static int employeeCount;
	const int MAX_SALARY;

	int findLength(const char* src) {
		int len = 0;
		for (int i = 0; src[i]; i++) len++;
		return len;
	}

	char* copyString(const char* src) {
		if (src == nullptr) {
			return nullptr;
		}
		int length = findLength(src);
		char* dest = new char[length + 1];
		for (int i = 0; i < length; i++) {
			dest[i] = src[i];
		}
		dest[length] = '\0';
		return dest;
	}

public:

	Employee() : MAX_SALARY(100000) {
		name = copyString("Unknown");
		age = 0;
		salary = 3000.0;
		employeeCount++;
	}
	
	Employee(const char* n, int a, float s) : age(a), MAX_SALARY(100000) {
		name = copyString(n);
		if (s > MAX_SALARY) {
			salary = MAX_SALARY;
		}
		else {
			salary = s;
		}
		employeeCount++;
	}
	
	Employee(const Employee& emp) : age(emp.age), salary(emp.salary), MAX_SALARY(emp.MAX_SALARY) {
		name = copyString(emp.name);
		employeeCount++;
	}
	
	~Employee() {
		delete[] name;
		name = nullptr;
		employeeCount--;
		cout << "Destructor called...\n";
	}

	void setName(const char* n) {
		if (name != nullptr) {
			delete[] name;
		}
		name = copyString(n);
	}

	void setAge(int a) {
		age = a;
	}
	
	void setSalary(float s) {
		if (s > MAX_SALARY) {
			salary = MAX_SALARY;
		}
		else {
			salary = s;
		}
	}
	
	char* getName() const { return name; }
	int getAge() const { return age; }
	float getSalary() const { return salary; }
	

	static int getEmployeeCount() {
		return employeeCount;
	}

	void display() {
		cout << "------------------------------------------------------------------------------------------\n";
		cout << "Name: " << name << ", Age: ";
		cout << age;
		cout << ", Salary: ";
		cout << salary;
		cout << "\n------------------------------------------------------------------------------------------\n";
	}

};
