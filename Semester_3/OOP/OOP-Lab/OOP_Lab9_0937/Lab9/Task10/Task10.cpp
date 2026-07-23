#include <iostream>
#include "Teacher.h"
#include "Researcher.h"
#include "Professor.h"
using namespace std;

void takeUserInput(char (&name)[100], char(&subject)[100], char (&rA)[100], int& p, char(&dep)[100], int& tL) {
	cout << "Enter Teacher's Name: ";
	cin.getline(name, 100);
	cout << "Enter Subject: ";
	cin >> subject;
	cin.ignore();
	cout << "Enter Research Area: ";
	cin.getline(rA, 100);
	cout << "Enter Publications: ";
	cin >> p;
	cin.ignore();
	cout << "Enter Department: ";
	cin.getline(dep, 100);
	cout << "Enter Teaching Load: ";
	cin >> tL;
	cin.ignore();
}

int main() {
	char name[100], subject[100], researchArea[100], department[100];
	int publications = 0, teachingLoad = 0;
	
	Professor p1;
	cout << "Professor 1: \n";
	p1.displayProfessor();
	
	takeUserInput(name, subject, researchArea, publications, department, teachingLoad);

	cout << "Professor 2: \n";
	Professor p2(teachingLoad, department, name, subject, researchArea, publications);
	p2.displayProfessor();

	return 0;
}