// Task 2:
#include <iostream>
using namespace std;

int average(int a, int b) {
	int sum = a + b;
	return sum / 2;
}

double average(double a, double b) {
	double sum = a + b;
	double avg = sum / 2;
	return avg;
}


int main() {

	double a = 15.7, b = 19.2;

	cout << "The average of a & b in double: " << average(a, b) << endl;

	int c = 11, d = 42;
	cout << "The average of a & b in integer: " << average(c, d) << endl;


	return 0;
}
