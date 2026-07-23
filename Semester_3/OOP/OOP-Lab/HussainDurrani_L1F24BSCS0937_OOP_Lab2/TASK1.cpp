// Task 1:
#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapByReference(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	int a = 6, b = 9;

	cout << "a = " << a << " , b = " << b << endl;
	cout << "After Swap by Value..." << endl;
	swapByValue(a, b);

	cout << "a = " << a << " , b = " << b << endl;

	cout << "After Swap by Reference..." << endl;
	swapByReference(a, b);
	cout << "a = " << a << " , b = " << b << endl;

	return 0;
}
