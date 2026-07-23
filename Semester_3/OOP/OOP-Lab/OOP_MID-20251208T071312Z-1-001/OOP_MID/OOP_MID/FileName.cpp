#include "Book.h"
#include <iostream>
using namespace std;

int Book::totalBooks = 0;

// Sort Books array by price
void sortBooksByPrice(Book* arr[],int n) {
	for (int iter = 0; iter < n - 1; iter++) {
		for (int j = 0; j < n - iter - 1; j++){
			if (arr[j]->getPrice() > arr[j + 1]->getPrice()) {
				Book* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "(Sorted Successfully)";
}

// Finding Costliest Book (friend Func)
void findCostliestBook(Book* arr[]) {
	int MaxPriceIndex = 0;
	float maxPrice = arr[0]->price;
	for (int i = 1; arr[i] != nullptr; i++) {
		if (arr[i]->price > maxPrice) { maxPrice = arr[i]->price; MaxPriceIndex = i; }
	}
	cout << "Book ID: " << arr[MaxPriceIndex]->uniqueBookID << ", Title: " << arr[MaxPriceIndex]->title << ", Price: $" << arr[MaxPriceIndex]->price << ". \n\n";
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
	cout << "-----------------------------------------------------\n";
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
	cout << "-----------------------------------------------------\n";

	cout << "\nBookStore Inventory: \n";
	for (int i = 0; i < n; i++) {
		books[i]->display();
	}

	cout << "Total Books in System: " << Book::getTotalBooks() << ". \n";

	cout << "Costliest Book (Using Friend Function): \n";
	findCostliestBook(books);

	cout << "Sorting books by price using friend function: \n";
	sortBooksByPrice(books,n);
	for (int i = 0; i < n; i++) {
		books[i]->display();
	}


	for (int i = 0; i < n; i++) {
		delete books[i];
	}

	return 0;
}










// Q1:
//#include "Book.h"
//#include <iostream>
//using namespace std;
//
//int Book::totalBooks = 0;
//
//int main() {
//	char title[100];
//	float price;
//
//	Book book1;
//	cout << "Default Constructor: \n";
//	book1.display();
//	cout << "Enter the Title of the Book 1: ";
//	book1.setTitle();
//	cout << "Enter Price of the Book 1: ";
//	cin >> price;
//	book1.setPrice(price);
//	cout << "Values Set using Setters: \n";
//	book1.display();
//
//	cout << "Enter Title of Book 2: ";
//	cin.ignore();
//	cin.getline(title, 100);
//	cout << "Enter Price of the Book 2: ";
//	cin >> price;
//	Book book2(title, price);
//	cout << "\nParameterized Constructor: \n";
//	book2.display();
//
//	cout << "\nCopy Constructor: \n";
//	Book book3 = book1;
//	book3.display();
//
//
//	cout << "Total Books so far are: " << Book::getTotalBooks() << ". \n";
//
//	cout << "Comparing Books using Operator Overloading: \n";
//	book1 + book2;
//
//	return 0;
//}