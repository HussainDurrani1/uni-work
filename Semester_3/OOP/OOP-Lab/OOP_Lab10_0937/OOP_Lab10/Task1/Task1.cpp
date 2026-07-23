#include <iostream>
#include "Passport.h"
#include "Person.h"
using namespace std;

int main() {
	string name, nationality;
	int passportNumber = 0;

	cout << "Enter your Nationality: ";
	cin >> nationality;
	cout << "Enter Passport Number: ";
	cin >> passportNumber;
	Passport pass1(passportNumber, nationality);
	cout << "\n------------------------------------------------\n";
	cout << "Passport Object: \n";
	pass1.display();
	cout << "------------------------------------------------\n\n";

	cout << "Enter your Name: ";
	cin >> name;
	Person per1(name, &pass1);
	cout << "\n------------------------------------------------\n";
	cout << "Person Object: \n";
	per1.display();
	cout << "-----------------------------------------------\n\n";

	cout << "Enter New Passport Number: ";
	cin >> passportNumber;
	pass1.setPassportNumber(passportNumber);

	cout << "\n------------------------------------------------\n";
	cout << "Updated1 Passport Object: \n";
	pass1.display();
	cout << "Updated1 Person Object: \n";
	per1.display();
	cout << "------------------------------------------------\n\n";

	cout << "Enter your New Nationality: ";
	cin >> nationality;
	pass1.setNationality(nationality);
	cout << "\n-------------------------------------------------\n";
	cout << "Updated2 Passport Object: \n";
	pass1.display();
	cout << "Updated2 Person Object: \n";
	per1.display();
	cout << "------------------------------------------------\n\n";

	cout << "Enter your New Name: ";
	cin >> name;
	per1.setName(name);
	cout << "\n------------------------------------------------\n";
	cout << "Updated3 Passport Object: \n";
	pass1.display();
	cout << "Updated3 Person Object: \n";
	per1.display();
	cout << "------------------------------------------------\n\n";

	return 0;
}