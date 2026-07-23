#pragma once
#include <iostream>
using namespace std;

class Passport
{
private:
	int passportNumber;
	string nationality;

public:
	Passport(int pNum, string n) : passportNumber(pNum) {
		nationality = n;
	}

	void setPassportNumber(int pNum) { passportNumber = pNum; }
	int getPassportNumber() const { return passportNumber; }

	void setNationality(string n) {
		nationality = n;
	}
	string getNationality() const { return nationality; }

	void display() const {
		cout << "Nationality: " << getNationality() << ", Passport Number: " << getPassportNumber() << ".\n";
	}
};