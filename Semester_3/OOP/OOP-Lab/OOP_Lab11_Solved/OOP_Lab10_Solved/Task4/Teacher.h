#pragma once
#include "Person.h"

class Teacher : public Person {
public:
	Teacher() {
		cout << "Teacher constructor called." << endl;
	}
};