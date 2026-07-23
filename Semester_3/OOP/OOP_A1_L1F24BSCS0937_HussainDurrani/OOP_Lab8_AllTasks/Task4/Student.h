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
	Student() : name("Unknown"), rollNo(0), gpa(0.0){}
	Student(string nom, int roll, float g) : name(nom), rollNo(roll), gpa(g) {}

	friend istream& operator>>(istream& in, Student& s) {
		cout << "Enter Name: ";
		in >> s.name;
		cout << "Enter Roll No: ";
		in >> s.rollNo;
		cout << "Enter GPA: ";
		in >> s.gpa;
		return in;
	}

	friend ostream& operator<<(ostream& out, const Student& s) {
		out << "Name: " << s.name << ", Roll No: " << s.rollNo << ", GPA: " << s.gpa << ".\n";
		return out;
	}

	void display() const {
		cout << "Name: " << name << ", Roll No: " << rollNo << ", GPA: " << gpa << ". \n";
	}
};