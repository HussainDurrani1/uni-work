#pragma once
#include <iostream>
using namespace std;

class Counter {
private:
	int count;

public:
	Counter() {
		count = 0;
		cout << "Counter initialized.\n";
	}

	~Counter() {
		cout << "Counter destroyed.\n";
	}

		void increment() {
		count++;
	}

	void displayCount() {
		cout << "Current count: " << count << endl;
	}
};