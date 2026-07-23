// Hussain Durrani
// L1F24BSCS0937

#include <iostream>
using namespace std;

class ArrayOperations {
	int* arr;
	int size;

public:
	ArrayOperations(int s) {
		size = s;
		arr = new int[size];
	}

	void userInput() {
		for (int i = 0; i < size; i++) {
			cout << "Enter value for element " << i + 1 << ": ";
			cin >> arr[i];
		}
	}

	int calculateSum() {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += arr[i];
		}
		return sum;
	}

	double calculateAverage() {
		return (double)calculateSum() / size;
	}

	void display() {
		cout << "\n-----------------------------------\n";
		cout << "Array Elements: ";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " | ";
		}
		cout << "\n-----------------------------------\n";
	}

	~ArrayOperations() {
		delete[] arr;
	}
};

int main() {
	int s;
	cout << "Enter size of array: ";
	cin >> s;

	ArrayOperations obj(s);
	obj.userInput();
	obj.display();

	cout << "Total Sum: " << obj.calculateSum() << endl;
	cout << "Average: " << obj.calculateAverage() << endl;

	return 0;
}