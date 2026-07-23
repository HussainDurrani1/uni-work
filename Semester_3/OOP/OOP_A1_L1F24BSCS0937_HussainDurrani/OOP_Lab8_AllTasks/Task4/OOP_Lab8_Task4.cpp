#include "Student.h"
#include <iostream>
using namespace std;

int main() {
	string name;
	int rollNo;
	float gpa;
	
	cout << "Student 1: \n"; // Without "cin >> " Overloading Function
	cout << "Enter Name: "; cin >> name;
	cout << "Enter Roll No: "; cin >> rollNo;
	cout << "Enter GPA: "; cin >> gpa;
	Student s1(name, rollNo, gpa);
	cout << s1;	// With Overloading function of '<<' operator

	cout << "Student 2: \n";
	Student s2;	// With Overloading Function
	cin >> s2;
	cout << s2;

	return 0;
}