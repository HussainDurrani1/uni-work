#include "Book.h"
#include <iostream>
using namespace std;

int main() {
	Book b1;
	cout << "--- Default Book ---\n";
	b1.display();

	char title[100];
	cout << "Enter the Title of the Book: ";
	cin.getline(title, 100);
	char author[100];
	cout << "Enter the name of Author of the Book: ";
	cin.getline(author, 100);
	double price;
	cout << "Enter the price of the book: ";
	cin >> price;
	cout << "Enter the available quantity of the book: ";
	int quantity;
	cin >> quantity;
	char category[100];
	cout << "Enter the category of the book: ";
	cin.ignore();
	cin.getline(category, 100);

	Book b2(title, author, price, quantity, category);
	cout << "\n--- Parameterized Book ---\n";
	b2.display();


	double discount = 15.0;
	cout << "Price of '" << b2.getTitle() << "' after " << discount << "% discount: $";
	cout << b2.calculateDiscountedPrice(discount) << "\n\n";

	int temp;
	cout << "Enter how many books you want: ";
	cin >> temp;
	b2.orderBook(temp);
	cout << "After ordering " << temp << " copies:\n";
	b2.display();


	cout << "Enter how many more books you want: ";
	cin >> temp;
	b2.orderBook(temp);
	b2.display();

	return 0;
}