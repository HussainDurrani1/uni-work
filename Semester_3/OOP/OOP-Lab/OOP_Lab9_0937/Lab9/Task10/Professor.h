#pragma once
#include <iostream>
#include "Teacher.h"
#include "Researcher.h"
using namespace std;

class Professor: public Teacher, public Researcher
{
private:
	char* department;
	int teachingLoad;

public:
	Professor() : teachingLoad(0), department(copyStr("Unknown")), Teacher(), Researcher() {}

	Professor(int tL, char* d, char* nom, char* subj, char* rA, int p) : teachingLoad(tL), department(d), Teacher(nom, subj), Researcher(rA, p) {}

	void setTeachingLoad(int tL) { teachingLoad = tL; }
	int getTeachingLoad() const { return teachingLoad; }

	void setDepartment(char* d) { delete[] department; department = copyStr(d); }
	char* getDepartment() const { return department; }

	void displayProfessor() const {
		cout << "---------------------------------------------------------------------\n";
		displayTeacher();
		displayResearcher();
		cout << "Department: " << getDepartment() << ", Teaching Load: " << getTeachingLoad() << ".\n";
		cout << "---------------------------------------------------------------------\n";
	}
};