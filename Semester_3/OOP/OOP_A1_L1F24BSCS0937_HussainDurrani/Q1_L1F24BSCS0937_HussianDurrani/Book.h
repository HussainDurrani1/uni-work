#pragma once
#include <iostream>
using namespace std;

class Book {

private:
	char* title;
	char* author;
	double price;
	int availableQuantity;
	char* category;

	int findLength(const char* src) const {
		int len = 0;
		for (int i = 0; src[i]; i++) len++;
		return len;
	}

	char* copyString(const char* src) {
		if (src == nullptr) {
			return nullptr;
		}
		int length = findLength(src);
		char* dest = new char[length + 1];
		for (int i = 0; i < length; i++) {
			dest[i] = src[i];
		}
		dest[length] = '\0';
		return dest;
	}

public:
	Book() {
		title = copyString("Unknown");
		author = copyString("Unknown");
		price = 0.0;
		availableQuantity = 0;
		category = copyString("None");
	}

	Book(const char* bookTitle, const char* bookAuthor, double bookPrice, int bookAQ, const char* bookCategory) {
		title = copyString(bookTitle);
		author = copyString(bookAuthor);
		price = bookPrice;
		availableQuantity = bookAQ;
		category = copyString(bookCategory);
	}

	~Book() {
		delete[] title;
		delete[] author;
		delete[] category;
		title = nullptr;
		author = nullptr;
		category = nullptr;
	}

	Book(const Book& other) {
		title = copyString(other.title);
		author = copyString(other.author);
		price = other.price;
		availableQuantity = other.availableQuantity;
		category = copyString(other.category);
	}

	Book& operator=(const Book& other) {
		if (this == &other) {
			return *this;
		}

		delete[] title;
		delete[] author;
		delete[] category;

		title = copyString(other.title);
		author = copyString(other.author);
		price = other.price;
		availableQuantity = other.availableQuantity;
		category = copyString(other.category);

		return *this;
	}


	double calculateDiscountedPrice(double discountPercentage) const {
		if (discountPercentage < 0.0 || discountPercentage > 100.0) {
			return price;
		}
		return price * (1.0 - (discountPercentage / 100.0));
	}

	bool orderBook(int quantity) {
		if (quantity <= 0) {
			cout << "Order quantity must be positive.\n";
			return false;
		}
		if (quantity <= availableQuantity) {
			availableQuantity -= quantity;
			cout << "Order successful. " << quantity << " copies purchased.\n";
			return true;
		}
		else {
			cout << "Order failed. Only " << availableQuantity << " copies available.\n";
			return false;
		}
	}

	char* getTitle() { return title; }

	void display() const {
		cout << "---------------------------------\n";
		cout << "Title: " << (title ? title : "N/A") << "\n";
		cout << "Author: " << (author ? author : "N/A") << "\n";
		cout << "Category: " << (category ? category : "N/A") << "\n";
		cout << "Price: $" << price << "\n";
		cout << "Available: " << availableQuantity << " copies\n";
		cout << "---------------------------------\n";
	}
};