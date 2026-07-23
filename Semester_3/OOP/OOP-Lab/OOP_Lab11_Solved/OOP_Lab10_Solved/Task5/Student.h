#pragma once
#include "Person.h"

class Student : virtual public Person {
public:
	Student() {
		cout << "Student constructor called." << endl;
	}

	Student(char* n, int a) : Person(n, a) {
		cout << "Student constructor called." << endl;
	}
};