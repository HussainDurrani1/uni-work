// Q2 -> Extended Version of Q1
// Advanced Bookstore Management
#pragma once
#include <iostream>
using namespace std;

int getLength(const char* str) {
	int length = 0;
	while (str[length] != '\0') { length++; }
	return length;
}

char* copyString(const char* src) {
	int len = getLength(src);
	char* dest = new char[len + 1];
	for (int i = 0; i < len; i++) {
		dest[i] = src[i];
	}
	dest[len] = '\0';
	return dest;
}

char* concatenateString(const char* str1, const char* str2) {
	int len1 = getLength(str1);
	int len2 = getLength(str2);
	char* combined = new char[len1 + len2 + 2];
	int index = 0;
	while (index < len1) { combined[index] = str1[index++]; }
	combined[index++] = ' ';
	while (index < len2) { combined[index] = str2[index++]; }
	combined[index] = '\0';
	return combined;
}

class Book
{

private:
	char* title;
	char* author;
	float price;
	int uniqueBookID;
	static int totalBooks;

public:
	Book() : price(0.0) {
		title = copyString("Untitled");
		author = copyString("None");
		++totalBooks;
		uniqueBookID = ((totalBooks + 1) * 10);
	}

	Book(char* t, char* a, float p) : price(p) {
		title = copyString(t);
		author = copyString(a);
		++totalBooks;
		uniqueBookID = ((totalBooks + 1) * 10);
	}



	Book(const Book& obj) : price(obj.price) {
		title = copyString(obj.title);
		author = copyString(obj.author);
		++totalBooks;
		uniqueBookID = ((totalBooks + 1) * 10);
	}

	~Book() {
		delete[] title;
		title = nullptr;
		--totalBooks;
	}

	friend void findCostliestBook(Book* arr[]);

	friend void sortBooksByPrice(Book* arr[], int n);


	char* getTitle() { return title; }
	void setTitle() {
		char t[100];
		cin.getline(t, 100);

		delete[] title;
		title = copyString(t);
	}

	float getPrice() { return price; }
	void setPrice(float p) {
		if (p > 0) {
			price = p;
		}
		else {
			cout << "This is not a valid price. \n";
		}
	}

	char* getAuthor() { return author; }
	void setAuthor() {
		char a[100];
		cin.getline(a, 100);

		delete[] author;
		author = copyString(a);
	}

	int getUniqueBookID() { return uniqueBookID; }

	static int getTotalBooks() { return totalBooks; }

	void display() {
		cout << "-------------------------------------------------------------------------------------\n";
		cout << "Book ID: " << getUniqueBookID() << "\n";
		cout << "Title: " << getTitle() << ", Author: " << getAuthor() << ", Price: " << getPrice() << " \n";
		cout << "----------------------------------------------------------------------------------------\n";
	}

	void operator +(const Book& obj) {
		if (obj.price > price) {
			cout << obj.title << " ($" << obj.price << ") \n";
		}
		else {
			cout << title << " ($" << price << ") \n";
		}
	}

};