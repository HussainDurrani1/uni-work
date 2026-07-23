#pragma once
#include <iostream>
#include "Teacher.h"
using namespace std;

class Researcher
{
private:
	char* researchArea;
	int publications;

public:
	Researcher() : publications(0), researchArea((char*)("Unknown")) {}

	Researcher(char* rA, int p): publications(p), researchArea(rA){}

	void setResearchArea(char* rA) { researchArea = rA; }
	char* getResearchArea() const { return researchArea; }

	void setPublications(int p) { publications = p; }
	int getPublications() const { return publications; }

	void displayResearcher() const {
		cout << "Research Area: " << getResearchArea() << ", No. of Publications: " << getPublications() << ".\n";
	}
};