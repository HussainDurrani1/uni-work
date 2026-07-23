#include "Counter.h"
#include <iostream>
using namespace std;

int main() {
	int value;
	cout << "Enter a value: "; cin >> value;
	Counter c1(value);

	int val = c1++;
	cout << "Value (Prefix Inc): " << val << endl;
	val = ++c1;
	cout << "Value (Postfix Inc): " << val << endl;
	c1.display();

	val = c1--;
	cout << "Value (Prefix Dec): " << val << endl;
	val = --c1;
	cout << "Value (Postfix Dec): " << val << endl;
	c1.display();

	-c1;
	cout << "Negating Value: \n";
	c1.display();

	+c1;
	cout << "Absolute Value: \n";
	c1.display();

	return 0;
}