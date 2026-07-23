#include "Student.h"
#include <iostream>
using namespace std;

int main() {

	Student s1;
	int roll;
	double marks;

	s1.setName();
	cout << "Enter the roll number of the Student 1: ";
	cin >> roll;
	s1.setRollNumber(roll);
	cout << "Enter the marks of the Student 1: ";
	cin >> marks;
	s1.setMarks(marks);


	cout << "Enter the name of the Student 2: ";
	char temp[100];
	cin.ignore();
	cin.getline(temp, 100);
	cout << "Enter the roll number of the Student 2: ";
	cin >> roll;
	cout << "Enter the marks of the Student 2: ";
	cin >> marks;
	Student s2(temp, roll, marks);

	s1.display();
	s2.display();


	Student s3;
	s3 = s1.compareMarks(s2);
	cout << "Student with higher Marks: \n";
	s3.display();


	return 0;
}
