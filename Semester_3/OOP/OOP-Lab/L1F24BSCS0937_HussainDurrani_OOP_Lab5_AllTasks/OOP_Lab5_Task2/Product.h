#pragma once
#include <iostream>
using namespace std;

class Product {

private:
	char* productName;
	double price;
	int quantity;

	int findLength(const char* src) {
		int len = 0;
		for (int i = 0; src[i]; i++) len++;
		return len;
	}

	char* copyString(const char* src) {
		int length = findLength(src);
		char* dest = new char[length + 1];
		for (int i = 0; i < length; i++) {
			dest[i] = src[i];
		}
		dest[length] = '\0';
		return dest;
	}

public:
	Product() {
		productName = nullptr;
		price = 0.0;
		quantity = 0;
	}

	Product(char* name, double p, int q) {
		quantity = q;
		price = p;
		productName = copyString(name);
	}

	Product(const Product& product) {
		price = product.price;
		quantity = product.quantity;
		if (product.productName != nullptr) {
			productName = copyString(product.productName);
		}
		else {
			productName = nullptr;
		}
	}
        // -----------------------------------------------------------------------
	Product& operator=(const Product& product) {
		if (this == &product) {
			return *this;
		}

		delete[] productName;

		price = product.price;
		quantity = product.quantity;

		if (product.productName != nullptr) {
			productName = copyString(product.productName);
		}
		else {
			productName = nullptr;
		}

		return *this;
	}
        // --------------------------------------------------------------------

	char* getProductName() { return productName; }
	void setProductName() {
		if (productName != nullptr) {
			delete[] productName;
			productName = nullptr;
		}
		cout << "Enter the Product Name: ";
		char temp[100];
		cin.getline(temp, 100);

		productName = copyString(temp);
	}


	void setName(char* name) {
		if (productName != nullptr) {
			delete[] productName;
		}
		productName = copyString(name);
	}

	void setPrice(double p) { price = p; }
	void setQuantity(int q) { quantity = q; }

	double getPrice() { return price; }
	int getQuantity() { return quantity; }

	double totalValue() { return (price * quantity); }
	void restock(int stock) { quantity += stock; }


	Product mergeProduct(const Product& p) {
		Product temp;
		int q = (quantity + p.quantity);
		double pr;
		temp.setQuantity(q);
		if (price > p.price) { pr = price; }
		else { pr = p.price; }
		temp.setPrice(pr);

		int len1 = findLength(productName);
		int len2 = findLength(p.productName);
		int length = len1 + 1 + len2;
		char* mergedPname = new char[length + 1];

		int i = 0;

		for (int j = 0; j < len1; j++, i++) { mergedPname[i] = productName[j]; }

		mergedPname[i++] = '&';

		for (int j = 0; j < len2; j++, i++) { mergedPname[i] = p.productName[j]; }
		mergedPname[i] = '\0';

		temp.setName(mergedPname);
		delete[] mergedPname;
		mergedPname = nullptr;

		return temp;
	}

	void display() {
		cout << "----------------------------------------------------------------------------------\n";
		cout << "Name: ";
		if (productName != nullptr) {
			cout << productName;
		}
		else {
			cout << "Name not set.\n";
		}
		cout << ", Price: " << price << ", Quantity: " << quantity << " \n";
		cout << "----------------------------------------------------------------------------------\n";
	}

	~Product() {
		cout << "Product removed from inventory...\n";
		delete[] productName;
	}

};
