#pragma once
#include "Student.h"
#include "Teacher.h"

class TA : public Student, public Teacher {
public:
	TA() {
		cout << "TA constructor called." << endl;
	}

	TA(char* n, int a) : Person(n, a), Student(n, a), Teacher(n, a) {
		cout << "TA constructor called." << endl;
	}
};