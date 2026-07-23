#include "Book.h"
#include <iostream>
using namespace std;

int Book::totalBooks = 0;

// Sort Books array by price
void sortBooksByPrice(Book* arr[]) {
	Book* tempbook = nullptr;	
	float maxBookPrice = arr[0]->price;
	for (int i = 0; arr[i] != nullptr; i++) {
		if (arr[i+1]->price > arr[i]->price) {
			tempbook = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = tempbook;
		}
	}

	cout << "(Sorted Successfully)\n";
}

// Finding Costliest Book (friend Func)
void findCostliestBook(Book* arr[]) {
	int MaxPriceIndex = 0;
	float maxPrice = arr[0]->price;
	for (int i = 1; arr[i] != nullptr; i++) {
		if (arr[i]->price > maxPrice) { maxPrice = arr[i]->price; MaxPriceIndex = i; }
	}
	cout << "Book ID: " << arr[MaxPriceIndex]->uniqueBookID << ", Title: " << arr[MaxPriceIndex]->title << ", Price: $" << arr[MaxPriceIndex]->price <<". \n";
}
 
int main() {
	char title[100];
	char author[100];
	float price;
	const int MAX_BOOKS = 10;
	Book* books[MAX_BOOKS] = { nullptr };

	int n = 0;
	cout << "How many Books do you want to add? ";
	cin >> n;
	cin.ignore();
	int index;

	for (int i = 0; i < n; i++) {
		cout << "Enter Title of Book " << i + 1 << ": ";
		cin.getline(title, 100);
		cout << "Enter Author: ";
		cin.getline(author, 100);
		cout << "Enter Price: ";
		cin >> price;
		index = Book::getTotalBooks();

		books[index] = new Book(title, author, price);
		cin.ignore();
	}
	
	cout << "BookStore Inventory: \n";
	for (int i = 0; i < n; i++) {
		books[i]->display();
	}
	
	cout << "Total Books in System: " << Book::getTotalBooks() << ". \n";

	cout << "Costliest Book (Using Friend Function): \n";
	findCostliestBook(books);

	cout << "Sorting books by price using friend function: \n";
	//sortBooksByPrice(books);
	for (int i = 0; i < n; i++) {
		books[i]->display();
	}


	for (int i = 0; i < n; i++) {
		delete books[i];
	}

	return 0;
}