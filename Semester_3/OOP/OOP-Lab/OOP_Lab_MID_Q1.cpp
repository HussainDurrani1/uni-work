#include "Book.h"
#include <iostream>
using namespace std;

int Book::totalBooks = 0;
 
int main() {
	char title[100];
	float price;

	Book book1;
	cout << "Default Constructor: \n";
	book1.display();
	cout << "Enter the Title of the Book 1: ";
	book1.setTitle();
	cout << "Enter Price of the Book 1: ";
	cin >> price;
	book1.setPrice(price);
	cout << "Values Set using Setters: \n";
	book1.display();

	cout << "Enter Title of Book 2: ";
	cin.ignore();
	cin.getline(title, 100);
	cout << "Enter Price of the Book 2: ";
	cin >> price;
	Book book2(title, price);
	cout << "\nParameterized Constructor: \n";
	book2.display();

	cout << "\nCopy Constructor: \n";
	Book book3 = book1;
	book3.display();


	cout << "Total Books so far are: " << Book::getTotalBooks() << ". \n";

	cout << "Comparing Books using Operator Overloading: \n";
	book1 + book2;

	return 0;
}