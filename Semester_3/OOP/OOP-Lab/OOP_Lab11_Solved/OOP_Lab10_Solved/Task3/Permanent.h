#pragma once
#include "Teacher.h"

class Permanent : public Teacher {
protected:
	string schoolName;

public:
	Permanent() {
		schoolName = "Unknown Public School";
	}

	void show() {
		cout << "Teacher Name (Superclass): " << name << endl;
		cout << "School Name (Subclass): " << schoolName << endl;
	}
};