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
	void setValues(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}

	int getHour() {
		return hour;
	}
	int getMinute() {
		return minute;
	}
	int getSecond() {
		return second;
	}


	void addTime(Time t2) {
		cout << "The total time is:\n";

		int tHour = hour + t2.hour;
		int tMin = minute + t2.minute;
		int tSec = second + t2.second;

		if (tSec >= 60) {
			tMin += tSec / 60;
			tSec %= 60; 
		}
		if (tMin >= 60) {
			tHour += tMin / 60;
			tMin %= 60;
		}
		

		if (tHour < 10) {
			cout << 0 << tHour << ":";
		}
		else {
			cout << tHour << ":";
		}

		if (tMin < 10) {
			cout << 0 << tMin << ":";
		}
		else {
			cout << tMin << ":";
		}

		if (tSec < 10) {
			cout << 0 << tSec << ":";
		}
		else {
			cout << tSec << ":";
		}

	}



	void display() {
		cout << "Time: " << hour << ":" << minute << ":" << second << ":\n\n\n";
	}

};

