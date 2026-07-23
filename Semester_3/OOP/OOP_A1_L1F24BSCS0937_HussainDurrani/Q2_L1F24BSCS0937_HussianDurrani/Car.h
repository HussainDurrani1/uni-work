#pragma once
#include <iostream>
using namespace std;

class Car {
private:
	char* brand;
	char* model;
	double price;

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
	Car() {
		brand = copyString("Unknown");
		model = copyString("N/A");
		price = 0.0;
	}

	Car(const char* carBrand, const char* carModel, double carPrice) {
		brand = copyString(carBrand);
		model = copyString(carModel);
		price = carPrice;
	}

	~Car() {
		delete[] brand;
		delete[] model;
		brand = nullptr;
		model = nullptr;
	}

	Car(const Car& other) {
		brand = copyString(other.brand);
		model = copyString(other.model);
		price = other.price;
	}

	void setBrand(const char* b) {
		if (brand != nullptr) {
			delete[] brand;
		}
		brand = copyString(b);
	}

	void setModel(const char* m) {
		if (model != nullptr) {
			delete[] model;
		}
		model = copyString(m);
	}

	void setPrice(double p) { price = p; }

	char* getBrand() const { return brand; }
	char* getModel() const { return model; }
	double getPrice() const { return price; }

	void display() const {
		cout << "----------------------------------------------------------------------\n";
		cout << "Car Details: " << "Brand: "
			<< (brand ? brand : "N/A") << ", Model: "
			<< (model ? model : "N/A") << ", Price: $"
			<< price << "\n";
		cout << "----------------------------------------------------------------------\n";
	}
};