// L1F20BSCS0000 – Ahmad
#include <iostream>
using namespace std;

class PointerDemo {
	int* ptr;

public:
	PointerDemo() {
		ptr = NULL;
	}

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
			cout << "Current Value: " << *ptr << ", Square: " << squareValue() << endl;
		}
	}

	void deallocate() {
		delete ptr;
		ptr = NULL;
	}

	void demonstrateLeak() {
		ptr = new int;
		*ptr = 100;
		cout << "Value: " << *ptr << " Address: " << ptr << endl;

		ptr = new int;
		*ptr = 200;
		cout << "New Value: " << *ptr << " Address: " << ptr << endl;
	}

	void demonstrateFix() {
		if (ptr != NULL) {
			delete ptr;
		}
		ptr = new int;
		*ptr = 300;
		cout << "Corrected Value: " << *ptr << " Address: " << ptr << endl;
	}

	~PointerDemo() {
		if (ptr != NULL) {
			delete ptr;
		}
	}
};

int main() {
	PointerDemo obj;

	obj.userInput();
	obj.display();
	obj.demonstrateLeak();
	obj.demonstrateFix();

	return 0;
}