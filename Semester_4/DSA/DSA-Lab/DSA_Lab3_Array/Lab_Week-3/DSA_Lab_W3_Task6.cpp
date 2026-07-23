// Hussain Durrani
// L1F24BSCS0937

#include <iostream>
using namespace std;

class StudentRecord {
	int rollNumber;
	int marks1;
	int marks2;

public:
	void setRollNumber(int r) { rollNumber = r; }
	void setMarks1(int m1) { marks1 = m1; }
	void setMarks2(int m2) { marks2 = m2; }

	int getRollNumber() { return rollNumber; }
	int getMarks1() { return marks1; }
	int getMarks2() { return marks2; }

	void calculateTotal() {
		cout << "Total Marks: " << marks1 + marks2 << endl;
	}

	void calculateGrade() {
		int total = marks1 + marks2;
		cout << "Grade: ";
		if (total >= 85) cout << "A";
		else if (total >= 70) cout << "B";
		else if (total >= 50) cout << "C";
		else cout << "F";
		cout << endl;
	}

	void display() {
		cout << "\n====================================\n";
		cout << "Student Roll Number: " << rollNumber << endl;
		cout << "Marks 1: " << marks1 << ", Marks 2: " << marks2 << endl;
		calculateTotal();
		calculateGrade();
		cout << "====================================\n";
	}
};

int main() {
	StudentRecord s;
	s.setRollNumber(55);
	s.setMarks1(40);
	s.setMarks2(42);
	s.display();

	return 0;
}