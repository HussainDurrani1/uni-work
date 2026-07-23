#include "Student.h"
#include <iostream>
using namespace std;

int Student::totalStudents = 0;

int main() {
	int roll;
	cout << "Enter the name of the Student 1: ";
	char temp[100];
	cin.getline(temp, 100);
	cout << "Enter the roll number of the Student 1: ";
	cin >> roll;

	Student s1(temp, roll);
	cout << "Total Students: " << Student::getTotalStudents() << endl;

	cout << "Enter the name of the Student 2: ";
	char temp1[100];
	cin.ignore();
	cin.getline(temp1, 100);
	cout << "Enter the roll number of the Student 2: ";
	cin >> roll;

	const Student s2(temp1, roll);

	s1.display();

	// Since s2 is a const object, it cannot be modified, and the following would cause an error: 
	// s2.setName("John");  // Uncommenting this would result in a compile-time error 

	cout << "Student 2 Name: " << s2.getName() << endl;
	cout << "Student 2 Roll Number: " << s2.getRollNumber() << endl;

	cout << "Total Students after creation: " << Student::getTotalStudents() << endl;

	return 0;
}
