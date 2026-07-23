#include "Product.h"
#include <iostream>
using namespace std;

int main() {

	Product p1;
	double price1, price2;
	int quant1, quant2;

	p1.setProductName();

	cout << "Enter the Quantity of Product 1: ";
	cin >> quant1;
	p1.setQuantity(quant1);
	cout << "Enter the Price of Product 1: ";
	cin >> price1;
	p1.setPrice(price1);

	cout << "Enter the Product Name: ";
	char temp[100];

	cin.ignore();
	cin.getline(temp, 100);

	cout << "Enter the Quantity of Product 2: ";
	cin >> quant2;
	cout << "Enter the Price of Product 2: ";
	cin >> price2;

	Product p2(temp, price2, quant2);

	p1.display();
	p2.display();

	Product mergedP;
	mergedP = p1.mergeProduct(p2);

	mergedP.display();

	return 0;
}