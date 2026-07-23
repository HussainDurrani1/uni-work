#pragma once
#include <iostream>
using namespace std;

class Student {

private:
	char* name;
	int rollNumber;
	double marks;

	int findLength(const char* src) {
		int len = 0;
		for (int i = 0; src[i]; i++) len++;
		return len;
	}

	char* copyString(const char* src) {
		int length = findLength(src);
		char* dest = new char[length + 1];
		for (int i = 0; i < length; i++) {
			dest[i] = src[i];
		}
		dest[length] = '\0';
		return dest;
	}


public:

	Student() {
		name = copyString("Unknown");
		rollNumber = 0;
		marks = 0.0;
	}

	Student(char* n, int rollN, double m) {
		rollNumber = rollN;
		marks = m;
		name = copyString(n);
	}


	Student(const Student& student) {
		rollNumber = student.rollNumber;
		marks = student.marks;
		if (student.name != nullptr) {
			name = copyString(student.name);
		}
		else {
			name = nullptr;
		}
	}
        // ----------------------------------------------------------
	Student& operator=(const Student& student) {
		if (this == &student) {
			return *this;
		}

		delete[] name;

		rollNumber = student.rollNumber;
		marks = student.marks;

		if (student.name != nullptr) {
			name = copyString(student.name);
		}
		else {
			name = nullptr;
		}
		return *this;
	}
	// ----------------------------------------------------------

	void setName() {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
		cout << "Enter the name of the student: ";
		char temp[100];
		cin.getline(temp, 100);

		name = copyString(temp);
	}
	void setRollNumber(int rN) { rollNumber = rN; }
	void setMarks(double m) { marks = m; }

	char* getName() { return name; }
	int getRollNumber() { return rollNumber; }
	double getMarks() { return marks; }


	Student compareMarks(const Student& student) {
		if (marks > student.marks) {
			return *this;
		}
		else {
			return student;
		}
	}

	void display() {
		cout << "------------------------------------------------------------------------------------------\n";
		cout << "Student: " << name << ", RollNumber: " << rollNumber << ", Marks: " << marks << " \n";
		cout << "------------------------------------------------------------------------------------------\n";
	}

	~Student() {
		delete[] name;
		name = nullptr;
		cout << "Destructor called...\n";
	}

};
