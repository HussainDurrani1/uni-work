#pragma once
#include "Person.h"

class Teacher : virtual public Person {
public:
	Teacher() {
		cout << "Teacher constructor called." << endl;
	}

	Teacher(char* n, int a) : Person(n, a) {
		cout << "Teacher constructor called." << endl;
	}
};