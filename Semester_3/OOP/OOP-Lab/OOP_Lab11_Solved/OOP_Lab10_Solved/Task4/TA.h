#pragma once
#include "Student.h"
#include "Teacher.h"

class TA : public Student, public Teacher {
public:
	TA() {
		cout << "TA constructor called." << endl;
	}
};