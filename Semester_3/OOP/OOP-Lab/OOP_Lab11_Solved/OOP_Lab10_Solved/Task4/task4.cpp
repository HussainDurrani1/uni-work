#include <iostream>
#include "TA.h"
using namespace std;

int main() {

	TA ta1;

	cout << "\nCalling display() using Student path:\n";
	ta1.Student::display();

	cout << "\nCalling display() using Teacher path:\n";
	ta1.Teacher::display();

	return 0;
}