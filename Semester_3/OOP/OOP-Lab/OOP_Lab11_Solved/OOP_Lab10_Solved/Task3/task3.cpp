#include <iostream>
#include "Teacher.h"
#include "Permanent.h"
#include "Visiting.h"
using namespace std;

int main() {
	string name, qualification;
	int age, students;

	Permanent p1;

	cout << "Enter Permanent Staff Details\n";
	cout << "Enter Name: "; cin >> name;
	cout << "Enter Age: "; cin >> age; cin.ignore();
	cout << "Enter Qualification: "; cin >> qualification;
	cout << "Enter Number of Students: "; cin >> students;

	p1.setName(name);
	p1.setAge(age);
	p1.setQualification(qualification);
	p1.setNumberOfStudents(students);

	cout << "\n===== Permanent Staff =====\n";
	cout << "Name: " << p1.getName() << endl;
	cout << "Age: " << p1.getAge() << endl;
	cout << "Qualification: " << p1.getQualification() << endl;
	cout << "Students: " << p1.getNumberOfStudents() << endl;

	Teacher t1 = p1;

	cout << "\n===== Permanent Assigned to Teacher Object =====\n";
	cout << "Name: " << t1.getName() << endl;
	cout << "Age: " << t1.getAge() << endl;
	cout << "Qualification: " << t1.getQualification() << endl;
	cout << "Students: " << t1.getNumberOfStudents() << endl;

	Visiting v[3];

	for (int i = 0; i < 3; i++) {
		cout << "\nEnter Visiting Staff " << i + 1 << " Details\n";
		cout << "Enter Name: "; cin.ignore(); cin >> name;
		cout << "Enter Age: "; cin >> age; cin.ignore();
		cout << "Enter Qualification: "; cin >> qualification;
		cout << "Enter Number of Students: "; cin >> students;

		v[i].setName(name);
		v[i].setAge(age);
		v[i].setQualification(qualification);
		v[i].setNumberOfStudents(students);
	}

	cout << "\n===== Visiting Staff =====\n";
	cout << "Name\tAge\tQualification\tStudents\n";
	for (int i = 0; i < 3; i++) {
		cout << v[i].getName() << "\t"
			<< v[i].getAge() << "\t"
			<< v[i].getQualification() << "\t"
			<< v[i].getNumberOfStudents() << endl;
	}

	Teacher* ptr;

	ptr = &p1;
	cout << "\n===== Permanent Staff accessed using Superclass Pointer =====\n";
	cout << ptr->getName() << " "
		<< ptr->getAge() << " "
		<< ptr->getQualification() << " "
		<< ptr->getNumberOfStudents() << endl;

	cout << "\nUpdate Visiting Staff 2 using Superclass Pointer\n";
	ptr = &v[1];

	cout << "Enter New Name: "; cin.ignore(); cin >> name;
	cout << "Enter New Age: "; cin >> age; cin.ignore();
	cout << "Enter New Qualification: "; cin >> qualification;
	cout << "Enter New Number of Students: "; cin >> students;

	ptr->setName(name);
	ptr->setAge(age);
	ptr->setQualification(qualification);
	ptr->setNumberOfStudents(students);

	cout << "\n===== Visiting Staff with Object 2 Set using Superclass Pointer =====\n";
	for (int i = 0; i < 3; i++) {
		cout << v[i].getName() << " "
			<< v[i].getAge() << " "
			<< v[i].getQualification() << " "
			<< v[i].getNumberOfStudents() << endl;
	}

	Teacher* ptr2 = &v[0];

	cout << "\n===== Visiting Staff Accessed Using Pointer =====\n";
	for (int i = 0; i < 3; i++) {
		cout << (ptr2 + i)->getName() << " "
			<< (ptr2 + i)->getAge() << " "
			<< (ptr2 + i)->getQualification() << " "
			<< (ptr2 + i)->getNumberOfStudents() << endl;
	}

	Permanent p2;

	cout << "\nEnter Another Permanent Staff Details\n";
	cout << "Enter Name: "; cin.ignore(); cin >> name;
	cout << "Enter Age: "; cin >> age; cin.ignore();
	cout << "Enter Qualification: "; cin >> qualification;
	cout << "Enter Number of Students: "; cin >> students;

	p2.setName(name);
	p2.setAge(age);
	p2.setQualification(qualification);
	p2.setNumberOfStudents(students);

	cout << "\n===== Overriding Demonstration =====\n";
	cout << "Superclass Name: " << p2.getName() << endl;
	p2.show();

	return 0;
}