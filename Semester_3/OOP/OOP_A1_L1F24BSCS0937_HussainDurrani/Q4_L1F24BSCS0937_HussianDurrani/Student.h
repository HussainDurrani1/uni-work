#pragma once
#include <iostream>
using namespace std;

class Student {

private:
	char* name;
	double marks;
	int* rollNumber;
	char** subjects;
	int numSubjects;

	int findLength(const char* src) const {
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
	Student() {
		name = copyString("Unknown");
		marks = 0.0;
		rollNumber = new int(0);
		subjects = nullptr;
		numSubjects = 0;
	}

	Student(const char* studentName, double studentMarks, int studentRollNo, const char** subject_list, int subject_count) {
		name = copyString(studentName);
		marks = studentMarks;
		rollNumber = new int(studentRollNo);

		numSubjects = subject_count;
		subjects = new char* [numSubjects];
		for (int i = 0; i < numSubjects; i++) {
			subjects[i] = copyString(subject_list[i]);
		}
	}

	~Student() {
		delete[] name;
		delete rollNumber;

		for (int i = 0; i < numSubjects; i++) {
			delete[] subjects[i];
		}
		delete[] subjects;

		name = nullptr;
		rollNumber = nullptr;
		subjects = nullptr;
	}

	Student(const Student& student) {
		name = copyString(student.name);
		marks = student.marks;
		rollNumber = new int(*(student.rollNumber));

		numSubjects = student.numSubjects;
		subjects = new char* [numSubjects];
		for (int i = 0; i < numSubjects; i++) {
			subjects[i] = copyString(student.subjects[i]);
		}
	}
	//---------------------------------------------------------------
	Student& operator=(const Student& other) {
		if (this == &other) {
			return *this;
		}

		delete[] name;
		delete rollNumber;
		for (int i = 0; i < numSubjects; i++) {
			delete[] subjects[i];
		}
		delete[] subjects;

		name = copyString(other.name);
		marks = other.marks;
		rollNumber = new int(*(other.rollNumber));

		numSubjects = other.numSubjects;
		subjects = new char* [numSubjects];
		for (int i = 0; i < numSubjects; i++) {
			subjects[i] = copyString(other.subjects[i]);
		}

		return *this;
	}
	//--------------------------------------------------------------------------
	void setName(const char* studentName) {
		if (name != nullptr) { delete[] name; }
		name = copyString(studentName);
	}

	void setMarks(double studentMarks) { marks = studentMarks; }

	void setRollNumber(int studentRollNo) {
		if (rollNumber != nullptr) { *(this->rollNumber) = studentRollNo; }
		else { rollNumber = new int(studentRollNo); }
	}

	void setSubjects(const char** subject_list, int subject_count) {
		for (int i = 0; i < numSubjects; i++) {
			delete[] subjects[i];
		}
		delete[] subjects;

		numSubjects = subject_count;
		subjects = new char* [numSubjects];
		for (int i = 0; i < numSubjects; i++) {
			subjects[i] = copyString(subject_list[i]);
		}
	}

	char* getName() const { return name; }
	double getMarks() const { return marks; }
	int getRollNumber() const {
		return (rollNumber != nullptr) ? *rollNumber : 0;
	}
	char** getSubjects() const { return subjects; }
	int getNumSubjects() const { return numSubjects; }

	const char* calculateGrade() const {
		if (marks >= 86) return "A";
		if (marks >= 80) return "B+";
		if (marks >= 75) return "B";
		if (marks >= 70) return "B-";
		if (marks >= 60) return "D";
		return "F";
	}

	const char* checkScholarship() const {
		if (marks > 80) return "Merit Scholarship";
		if (marks > 70) return "Punjab Scholarship";
		return "Not Eligible";
	}

	void print() const {
		cout << "======================================\n";
		cout << "Student: " << (name ? name : "N/A") << "\n";
		cout << "Roll #: " << getRollNumber() << "\n";
		cout << "Marks: " << marks << "%\n";

		cout << "Subjects (" << numSubjects << "):\n";
		if (numSubjects > 0 && subjects != nullptr) {
			for (int i = 0; i < numSubjects; i++) {
				cout << "  - " << (subjects[i] ? subjects[i] : "N/A") << "\n";
			}
		}
		else {
			cout << "  - None\n";
		}

		cout << "Grade: " << calculateGrade() << "\n";
		cout << "Scholarship: " << checkScholarship() << "\n";
		cout << "======================================\n";
	}
};