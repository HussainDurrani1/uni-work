// Hussain Durrani
// L1F24BSCS0937

#include <iostream>
using namespace std;

class PointerDemo {
	int* ptr;

public:
	PointerDemo() { ptr = NULL; }

	void userInput() {
		ptr = new int;
		cout << "Enter a value: ";
		cin >> *ptr;
	}

	int squareValue() {
		return (*ptr) * (*ptr);
	}

	void display() {
		if (ptr != NULL) {
			cout << "Stored Value: " << *ptr << ", Square: " << squareValue() << endl;
		}
		else {
			cout << "Pointer is NULL. Cannot display.\n";
		}
	}

	void deallocate() {
		delete ptr;
		cout << "Memory deallocated.\n";
	}

	void fixDangling() {
		ptr = NULL;
		cout << "Pointer set to NULL.\n";
	}

	void reallocate(int val) {
		ptr = new int;
		*ptr = val;
		cout << "New value after reallocation: " << *ptr << endl;
	}
};

int main() {
	PointerDemo obj;
	obj.userInput();
	obj.display();

	obj.deallocate();

	obj.fixDangling();
	obj.reallocate(59);

	return 0;
}