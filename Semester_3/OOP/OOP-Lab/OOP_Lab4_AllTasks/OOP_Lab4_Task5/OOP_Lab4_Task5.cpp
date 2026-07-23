#include <iostream>
#include "ComplexNumber.h"
#include "Time.h"
#include "Circle.h"
#include "Employee.h"
using namespace std;

int main() {
	int choice;

	do {
		cout << "\nPress 1 for Testing 'ComplexNumber' class";
		cout << "\nPress 2 for Testing 'Time' class";
		cout << "\nPress 3 for Testing 'Circle' class";
		cout << "\nPress 4 for Testing 'Employee' class";
		cout << "\nPress 0 for Exit";
		cout << "\nEnter choice: ";
		cin >> choice;
		cin.ignore();

		if (choice == 1) {
			cout << "\n1st Complex Number:\n";
			ComplexNumber c1;
			c1.setValue();

			cout << "\n2nd Complex Number:\n";
			ComplexNumber c2;
			c2.setValue();

			cout << "\n1st Complex Number: ";
			c1.display();
			cout << "2nd Complex Number: ";
			c2.display();

			ComplexNumber sum = c1.sum(c2);
			ComplexNumber diff = c1.difference(c2);

			cout << "Sum: ";
			sum.display();
			cout << "Difference: ";
			diff.display();
		}

		else if (choice == 2) {
			Time t1, t2;
			cout << "Enter Time 1:\n";
			t1.setValues();
			cout << "Enter Time 2:\n";
			t2.setValues();
			Time total = t1.addTime(t2);
			cout << "Total Time: ";
			total.display();
		}

		else if (choice == 3) {
			double r;
			cout << "Enter Radius: ";
			cin >> r;
			Circle c(r);
			c.display();
		}

		else if (choice == 4) {
			Employee e;
			char temp[100];
			int id;
			double sal, raise;

			cout << "Enter Name: ";
			cin.ignore();
			cin.getline(temp, 100);
			cout << "Enter Employee ID: ";
			cin >> id;
			cout << "Enter Salary: ";
			cin >> sal;
			e.setName(temp);
			e.setEmployeeId(id);
			e.setSalary(sal);
			e.display();

			cout << "Enter Raise Percentage: ";
			cin >> raise;
			e.giveRaise(raise);
			cout << "Updated Details:\n";
			e.display();
		}

		else if (choice == 0) {
			cout << "Exiting program...\n";
		}

		else {
			cout << "Invalid choice!\n";
		}

	} while (choice != 0);

	return 0;
}