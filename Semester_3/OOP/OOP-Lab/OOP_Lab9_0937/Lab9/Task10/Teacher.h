#pragma once
#include <iostream>
using namespace std;

int getLen(const char* str) {
	int len = 0;
	while (str[len] != '\0')len++;
	return len;
}

char* copyStr(const char* src) {
	int len = getLen(src);
	char* dest = new char[len + 1];
	for (int i = 0; i < len; i++) dest[i] = src[i];
	dest[len] = '\0';
	return dest;
}

class Teacher
{
private:
	char* name;
	char* subject;

public:
	Teacher(){
		name = copyStr("Teacher");
		subject = copyStr("Subject");
	}

	Teacher(const char* nom, const char* s){
		name = copyStr(nom);
		subject = copyStr(s);
	}

	~Teacher() {
		delete[] name;
		delete[] subject;
	}

	void setSubject(const char* sub) { delete[] subject; subject = copyStr(sub); }
	char* getSubject() const { return subject; }

	void setName(const char* n) {
		delete[] name;
		name = copyStr(n);
	}
	char* getName() const { return name; }

	void displayTeacher() const {
		cout << "Teacher's Name: " << getName()<< ", Subject: " << getSubject() << ".\n";
	}
};