#pragma once
#include "Person.h"
#include "Employee.h"

class Manager: public Person, public Employee
{
private:
	int teamSize;

public:
	Manager() : teamSize(0), Person(), Employee() {}

	Manager(int tSize, char* nom, char* dep, int a, int id) : teamSize(tSize), Person(nom, a), Employee(dep, id) {}

	int getTeamSize() const { return teamSize; }
	void setTeamSize(int tSize) { teamSize = tSize; }


	void display() const {
		cout << "----------------------------------------\n";
		Person::display();
		Employee::display();
		cout << "Team Size: " << getTeamSize() << "\n";
		cout << "----------------------------------------\n";
	}
};