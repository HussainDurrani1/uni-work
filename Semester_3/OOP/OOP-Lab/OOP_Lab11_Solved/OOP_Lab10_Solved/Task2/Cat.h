#pragma once
#include "Animal.h"

class Cat : public Animal {
public:
	Cat(char* n) : Animal(n) {}

	void makeSound() {
		cout << "Derived class: Cat object" << endl;
	}
};