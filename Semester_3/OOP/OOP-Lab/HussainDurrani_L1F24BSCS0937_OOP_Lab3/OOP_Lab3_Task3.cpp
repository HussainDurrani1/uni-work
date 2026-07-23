// Task 3:
#include <iostream>
using namespace std;

class Calculator {
private:
	int num1, num2, num3;

public:
	Calculator(int n1, int n2, int n3) {
		num1 = n1;
		num2 = n2;
		num3 = n3;
	}

	void display() {
		cout << "Num1 = " << num1 << endl;
		cout << "Num2 = " << num2 << endl;
		cout << "Num3 = " << num3 << endl;
	}

	int add() {
		return (num1 + num2 + num3);
	}

	int multiply() {
		return (num1 * num2 * num3);
	}

	double average() {
		double sum = num1 + num2 + num3;
		double average = sum / 3;
		return average;
	}

	int maximum() {
		int max;
		if (num1 > num2 && num1 > num3) {
			max = num1;
		}
		else if (num2 > num1 && num2 > num3) {
			max = num2;
		}
		else {
			max = num3;
		}
		return max;
	}

	int minimum() {
		int min;
		if (num1 < num2 && num1 < num3) {
			min = num1;
		}
		else if (num2 < num1 && num2 < num3) {
			min = num2;
		}
		else {
			min = num3;
		}
		return min;
	}
};

int main() {
	int n1, n2, n3;
	cout << "Enter three numbers: " << endl;
	cin >> n1 >> n2 >> n3;

	Calculator obj1(n1, n2, n3);

	obj1.display();

	cout << "The addition of these 3 numbers is: " << obj1.add() << endl;
	cout << "The product of these 3 number is: " << obj1.multiply() << endl;
	cout << "The average of these 3 number is: " << obj1.average() << endl;
	cout << "The maximum in these 3 number is: " << obj1.maximum() << endl;
	cout << "The minimum in these 3 number is: " << obj1.minimum() << endl;

	return 0;
}