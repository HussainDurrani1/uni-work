#pragma once
#include <iostream>
#include "Employee.h"
using namespace std;

class Manager: private Employee
{
private:
	int teamSize;
	double budget;

public:
	Manager() : teamSize(0), budget(0.0), Employee((char*)("Unknown"), 0.0, 0){}

	Manager(int tS, double b, char* nom, double s, int id): teamSize(tS), budget(b), Employee(nom, s, id){}

	void setTeamSize(int tS) { teamSize = tS; }
	int getTeamSize() const { return teamSize; }

	void setBudget(double b) { budget = b; }
	double getBudget() const { return budget; }

	void displayManager() const {
		displayEmployee();
		cout << "Team Size: " << getTeamSize() << ", Budget: " << getBudget() << ".\n";
	}
};