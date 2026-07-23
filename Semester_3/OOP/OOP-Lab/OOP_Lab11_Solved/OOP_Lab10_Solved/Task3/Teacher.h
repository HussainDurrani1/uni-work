#pragma once
#include <iostream>
using namespace std;

class Teacher {
protected:
	string name;
	int age;
	string qualification;
	int numberOfStudents;

public:
	void setName(string n) { name = n; }
	void setAge(int a) { age = a; }
	void setQualification(string q) { qualification = q; }
	void setNumberOfStudents(int n) { numberOfStudents = n; }

	string getName() const { return name; }
	int getAge() const { return age; }
	string getQualification() const { return qualification; }
	int getNumberOfStudents() const { return numberOfStudents; }
};