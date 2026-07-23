#pragma once
#include "Person.h"

class Student : public Person {
public:
	Student() {
		cout << "Student constructor called." << endl;
	}
};