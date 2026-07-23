#include <iostream>
using namespace std;

int main() {

	cout << "These are a few Patterns:\n\n";


	int n = 5;
	// Butterfly Pattern:
	cout << "Butterfly Pattern: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) cout << "*";
		for (int j = 0; j < 2 * (n - i - 1); j++) cout << " ";
		for (int j = 0; j < i + 1; j++)cout << "*";
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) cout << "*";
		for (int j = 0; j < 2 * i; j++) cout << " ";
		for (int j = 0; j < n - i; j++)cout << "*";
		cout << endl;
	}

	cout << "\n\n\n";


	// Alphabet Diagram:
	// Way 2:
	cout << "Alphabet Diamond: \n";
	for (int i = 0; i < n; i++) {
		char val = 'A';
		for (int j = 0; j < n - i - 1; j++) cout << " ";
		for (int j = 0; j < i + 1; j++) cout << val++;
		--val;
		for (int j = 0; j < i; j++) cout << --val;
		cout << endl;
	}
	for (int i = 0; i < n - 1; i++) {
		char val = 'A';
		for (int j = 0; j < i + 1; j++) cout << " ";
		for (int j = 0; j < n - i - 1; j++) cout << val++;
		--val;
		for (int j = 0; j < n - i - 2; j++) cout << --val;
		cout << endl;
	}

	cout << "\n\n\n";


	// Way 1:
	cout << "Alphabet Diamond: \n";
	for (int i = 0; i < n; i++) {
		char val = 'A' - 1;
		for (int j = 0; j < n - i - 1; j++) cout << " ";
		for (int j = 0; j < 2 * i + 1; j++) {
			if (j < i + 1) cout << ++val;
			else { cout << --val; }
		}
		cout << endl;
	}
	for (int i = 0; i < n - 1; i++) {
		char val = 'A' - 1;
		for (int j = 0; j < i + 1; j++) cout << " ";
		for (int j = 0; j < 2 * (n - i - 2) + 1; j++) {
			if (j < n - i - 1) cout << ++val;
			else { cout << --val; }
		}
		cout << endl;
	}

	cout << "\n\n\n";


	//	Hollow Diamond:
	cout << "Hollow Diamond: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) cout << " ";
		cout << "*";
		if (i != 0) {
			for (int j = 0; j < (2 * i) - 1; j++) cout << " ";
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < i + 1; j++) cout << " ";
		cout << "*";
		if (i != n - 2) {
			for (int j = 0; j < 2 * (n - i - 2) - 1; j++) cout << " ";
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}