// Hussain Durrani
// L1F24BSCS0937

#include <iostream>
using namespace std;

class NumberSwapper {
	int num1;
	int num2;

public:
	void setNum1(int a) { num1 = a; }
	void setNum2(int b) { num2 = b; }
	int getNum1() { return num1; }
	int getNum2() { return num2; }

	void swapNumbers(int a, int b) {
		int temp = a;
		a = b;
		b = temp;
		cout << "[Inside Function] a: " << a << " b: " << b << endl;
	}

	void display() {
		cout << "\n=====================================================\n";
		cout << "Number 1: " << num1 << ", Number 2: " << num2 << endl;
		cout << "=====================================================\n\n";
	}
};

int main() {
	NumberSwapper obj;
	obj.setNum1(10);
	obj.setNum2(20);

	cout << "Before Swapping: ";
	obj.display();

	obj.swapNumbers(obj.getNum1(), obj.getNum2());

	cout << "After Swapping (Object members): ";
	obj.display();

	return 0;
}