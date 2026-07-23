#pragma once
#include <iostream>
using namespace std;
class Student {
private:
	char* name;
	int marks;

	int getLength(const char* src) {
		int len = 0;
		while (src[len] != '\0') { len++; }
		return len;
	}

	char* copyString(const char* src) {
		int length = getLength(src);
		char* dest = new char[length + 1];
		for (int i = 0; i < length; i++) {
			dest[i] = src[i];
		}
		dest[length] = '\0';
		return dest;
	}

public:
	Student() : marks(0) {
		name = copyString("Unknown");
	}

	Student(char* n, int m) : marks(m) {
		name = copyString(n);
	}

	~Student() {
		delete[] name;
		name = nullptr;
	}

	int getMarks() { return marks; }
	void setMarks(int m) { marks = m; }

	char* getName() { return name; }
	void setName(char* n) {
		name = copyString(n);
	}

	void display() {
		cout << "Student's Name: " << name << ", Marks = " << marks << " \n";
	}

};