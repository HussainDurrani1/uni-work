#pragma once
#include <iostream>
#include "Passport.h"
using namespace std;

class Person
{
private:
	Passport* passport;
	string name;

public:
	Person(string nom, Passport* pass) {
		name = nom;
		passport = pass;
	}

	void setName(string nom) {
		name = nom;
	}
	string getName() const { return name; }

	void setPassport(Passport* pass) { 
		passport = pass;
	}

	Passport* getPassport() const { return passport; }

	void display() const {
		cout << "Name: " << getName() << "\n";
		passport->display();
	}
};