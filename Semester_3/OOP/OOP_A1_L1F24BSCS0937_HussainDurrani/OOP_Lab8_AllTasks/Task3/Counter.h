#pragma once
#include <iostream>
using namespace std;

class Counter
{
private:
	int value;

public:
	Counter() : value(0){}
	Counter(int val): value(val){}

	int operator ++ () {	// prefix increment
		return ++this->value;
	}

	int operator ++ (int) {	// postfix increment
		return this->value++;
	}

	int operator -- () {	// prefix decrement
		return --this->value;
	}

	int operator -- (int) {	// postfix decrement
		return this->value--;
	}

	Counter operator + () {	// Absolute Value
		if (this->value < 0) { this->value *= -1; }
		return *this;
	}

	Counter operator - () {	// Negate Value
		if (this->value > 0) { this->value *= -1; }
		return *this;
	}

	void display() const {
		cout << "The Value: " << value << endl;
	}
};