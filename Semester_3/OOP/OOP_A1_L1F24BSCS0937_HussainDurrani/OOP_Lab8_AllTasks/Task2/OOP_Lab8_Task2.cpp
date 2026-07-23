#include "Student.h"
#include <iostream>
using namespace std;

int main() {
	string name;
	int rollNo;
	float gpa;

	cout << "Student 1: \n";
	cout << "Enter Name: "; cin >> name;
	cout << "Enter Roll No: "; cin >> rollNo;
	cout << "Enter GPA: "; cin >> gpa;
	Student s1(name, rollNo, gpa);
	s1.display();

	cout << "Student 2: \n";
	cout << "Enter Name: "; cin >> name;
	cout << "Enter Roll No: "; cin >> rollNo;
	cout << "Enter GPA: "; cin >> gpa;
	Student s2(name, rollNo, gpa);
	s2.display();

	if (s1 == s2) { cout << "Both Objects have same Roll No.\n"; }
	if (s1 != s2) { cout << "Both Students have different Roll No.\n"; }

	if (s1 >= s2) { cout << "S1 has more GPA than S2.\n"; }
	if (s1 <= s2) { cout << s1.getName() << " has less GPA than " << s2.getName() << ".\n"; }

	return 0;
}