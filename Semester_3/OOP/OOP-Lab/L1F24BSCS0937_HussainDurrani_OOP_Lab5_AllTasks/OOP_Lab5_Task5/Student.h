#pragma once
#include <iostream>
using namespace std;

class Student {

private:
	char* name;
	int rollNumber;
	static int totalStudents;
	const int MAX_ROLL_NUMBER;

	int findLength(const char* src) {
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

	Student() : MAX_ROLL_NUMBER(5000) {
		name = copyString("Unknown");
		rollNumber = 0;
		totalStudents++;
	}

	Student(const char* n, int r) : rollNumber(r), MAX_ROLL_NUMBER(5000) {
		name = copyString(n);
		totalStudents++;
	}

	Student(const Student& other) : rollNumber(other.rollNumber), MAX_ROLL_NUMBER(other.MAX_ROLL_NUMBER) {
		name = copyString(other.name);
		totalStudents++;
	}

	~Student() {
		delete[] name;
		name = nullptr;
		totalStudents--;
		cout << "Destructor called...\n";
	}

	void setName(const char* n) {
		if (name != nullptr) {
			delete[] name;
		}
		name = copyString(n);
	}

	char* getName() const { return name; }
	int getRollNumber() const { return rollNumber; }

	static int getTotalStudents() {
		return totalStudents;
	}

	void display() {
		cout << "\n---------------------------------------------------------------\n";
		cout << "Name: " << name << ", RollNumber: " << rollNumber << ". \n";
		cout << "---------------------------------------------------------------\n";
	}
};
