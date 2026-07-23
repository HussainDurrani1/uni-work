#include "Counter.h"
#include <iostream>
using namespace std;

void performTask() {
	static Counter c;
	c.increment();
	c.displayCount();
}

int main() {
	cout << "First call to performTask():\n";
	performTask();
	cout << "\nSecond call to performTask():\n";
	performTask();
	cout << "\nThird call to performTask():\n";
	performTask();

	cout << "\nProgram ending...\n";
	
	
	return 0;
}