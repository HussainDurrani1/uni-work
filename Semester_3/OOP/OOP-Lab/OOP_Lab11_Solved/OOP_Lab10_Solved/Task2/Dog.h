#pragma once
#include "Animal.h"

class Dog : public Animal {
public:
	Dog(char* n) : Animal(n) {}

	void makeSound() {
		cout << "Derived class: Dog object" << endl;
	}
};