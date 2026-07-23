#include "Circle.h"
#include <iostream>
using namespace std;

void inputValues(double& radius) {
	cout << "Enter radius: ";
	cin >> radius;
}

int main() {
	double rad;
	inputValues(rad);
	Circle c1(rad);
	c1.display();

	cout << "Enter new radius: ";
	cin >> rad;
	c1.setRadius(rad);

	c1.display();

	Circle c2;
	c2.display();


	return 0;
}