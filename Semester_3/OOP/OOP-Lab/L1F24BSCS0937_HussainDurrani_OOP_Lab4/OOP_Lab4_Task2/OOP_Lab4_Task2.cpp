#include "Time.h"
#include <iostream>
using namespace std;

void inputValues(int& hour, int& minute, int& second) {
	cout << "Enter hour: ";
	cin >> hour;

	cout << "Enter minute: ";
	cin >> minute;
	if (minute >= 60){
		cout << "Minutes should be below 60...\n";
		minutes %= 60;
	}

	cout << "Enter second: ";
	cin >> second;
	if (second >= 60) {
		cout << "Seconds should be below 60...\n";
		second %= 60;
	}
}

int main() {
	Time t1;
	int hour, minute, second;
	inputValues(hour, minute, second);

	t1.setValues(hour, minute, second);
	cout << "The time you entered is: " << t1.getHour() << " hours " << t1.getMinute() << " minutes " << t1.getSecond() << " seconds \n";
	t1.display();

	Time t2;
	inputValues(hour, minute, second);
	t2.setValues(hour, minute, second);
	cout << "The time you entered is: " << t2.getHour() << " hours " << t2.getMinute() << " minutes " << t2.getSecond() << " seconds \n";
	t2.display();

	t1.addTime(t2);

	return 0;
}