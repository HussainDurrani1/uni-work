#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;

public:
	void setValues() {
		cout << "Enter Hours: ";
		cin >> hour;
		cout << "Enter Minutes: ";
		cin >> minute;
		cout << "Enter Seconds: ";
		cin >> second;
	}

	int getHour() { return hour; }
	int getMinute() { return minute; }
	int getSecond() { return second; }

	Time addTime(Time t2) {
		Time t3;
		t3.second = second + t2.second;
		t3.minute = minute + t2.minute + t3.second / 60;
		t3.hour = hour + t2.hour + t3.minute / 60;
		t3.second %= 60;
		t3.minute %= 60;
		return t3;
	}

	void display() {
		cout << hour << ":" << minute << ":" << second << endl;
	}
};