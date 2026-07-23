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

class Person
{
private:
	char* name;
	int age;

public:
	Person(): age(18), name(copyStr("Unknown")){}

	Person(char* nom, int a): age(a), name(copyStr(nom)){}

	char* getName() const { return name; }
	void setName(const char* nom) {
		delete[] name;
		name = copyStr(nom);
	}

	int getAge() const { return age; }
	void setAge(int a) { age = a; }


	void display() const {
		cout << "Name: " << getName() << ", Age: " << getAge() << "\n";
	}
};