#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	string name;
	int rollNo;
	float gpa;

public:
	Student(): rollNo(0), gpa(0.0), name("Unknown") {}
	
	Student(string nom, int roll, float g) : rollNo(roll), gpa(g), name(nom) {}

	string getName() { return name; }

	bool operator == (const Student& other) {
		if (this->rollNo == other.rollNo) return true;
		return false;
	}

	bool operator != (const Student& other) {
		if (this->rollNo == other.rollNo) return false;
		return true;
	}

	bool operator >= (const Student& other) {
		if (this->gpa >= other.gpa) return true;
		return false;
	}

	bool operator <= (const Student& other) {
		if (this->gpa <= other.gpa) return true;
		return false;
	}

	void display() const {
		cout << "Name: " << name << ", Roll No: " << rollNo << ", GPA: " << gpa << endl;
	}
};