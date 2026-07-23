// Task 4:
#include <iostream>
using namespace std;

int calculate(int length, int width = 5) {
	return length * width;
}

int main() {
	int length = 7, width = 9;

	int area1 = calculate(length);
	int area2 = calculate(length, width);

	cout << "Area 1 = " << area1 << endl;
	cout << "Area 2 = " << area2 << endl;

	return 0;
}