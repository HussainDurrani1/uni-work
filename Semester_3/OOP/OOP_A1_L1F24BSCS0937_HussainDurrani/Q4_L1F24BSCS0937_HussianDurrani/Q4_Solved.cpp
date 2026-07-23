#include "Student.h"
#include <iostream>
using namespace std;

int main() {
	Student s1;
	cout << "--- Default Student ---\n";
	s1.print();

	char name[100];
	double marks;
	int roll;
	int numSubjects;

	cout << "\n--- Enter Details for New Student ---\n";
	cout << "Enter Name: ";
	cin.getline(name, 100);

	cout << "Enter Marks: ";
	cin >> marks;

	cout << "Enter Roll Number: ";
	cin >> roll;

	cout << "Enter Number of Subjects: ";
	cin >> numSubjects;
	cin.ignore();

	char** s2_subjects = new char* [numSubjects];
	char temp_subject[100];

	for (int i = 0; i < numSubjects; i++) {
		cout << "Enter Subject " << (i + 1) << ": ";
		cin.getline(temp_subject, 100);

		int len = 0;
		for (int j = 0; temp_subject[j]; j++) len++;
		s2_subjects[i] = new char[len + 1];
		for (int j = 0; j < len; j++) s2_subjects[i][j] = temp_subject[j];
		s2_subjects[i][len] = '\0';
	}

	Student s2(name, marks, roll, (const char**)s2_subjects, numSubjects);

	for (int i = 0; i < numSubjects; i++) {
		delete[] s2_subjects[i];
	}
	delete[] s2_subjects;

	cout << "\n--- New Student Details ---\n";
	s2.print();

	cout << "\n--- Updating Default Student ---\n";
	cout << "Enter new Name for Student 1: ";
	cin.getline(name, 100);
	s1.setName(name);

	cout << "Enter new Roll Number: ";
	cin >> roll;
	s1.setRollNumber(roll);

	cout << "Enter new Marks: ";
	cin >> marks;
	s1.setMarks(marks);

	cout << "Enter new Number of Subjects: ";
	cin >> numSubjects;
	cin.ignore();

	char** s1_subjects = new char* [numSubjects];
	for (int i = 0; i < numSubjects; i++) {
		cout << "Enter Subject " << (i + 1) << ": ";
		cin.getline(temp_subject, 100);

		int len = 0;
		for (int j = 0; temp_subject[j]; j++) len++;
		s1_subjects[i] = new char[len + 1];
		for (int j = 0; j < len; j++) s1_subjects[i][j] = temp_subject[j];
		s1_subjects[i][len] = '\0';
	}

	s1.setSubjects((const char**)s1_subjects, numSubjects);

	for (int i = 0; i < numSubjects; i++) {
		delete[] s1_subjects[i];
	}
	delete[] s1_subjects;

	cout << "\nUpdated Details for " << s1.getName() << ":\n";
	s1.print();

	cout << "\n--- Testing Copy Constructor ---\n";
	Student s3 = s2;
	cout << "This is a copy of the new student created above:\n";
	s3.print();

	cout << "\n--- Testing Copy Assignment ---\n";
	s3 = s1;
	cout << "The copy object now holds a copy of the updated Student 1:\n";
	s3.print();

	return 0;
}