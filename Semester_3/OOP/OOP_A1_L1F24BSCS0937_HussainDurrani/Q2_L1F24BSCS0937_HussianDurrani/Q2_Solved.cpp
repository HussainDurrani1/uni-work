#include "Car.h"
#include <iostream>
using namespace std;

int main() {
	Car car1;

	char brand[100], model[100];
	double price;
	cout << "Enter the BRAND of the car: ";
	cin.getline(brand, 100);
	cout << "Enter the MODEL of the car: ";
	cin.getline(model, 100);
	cout << "Enter the price of the car: ";
	cin >> price;
	Car car2(brand, model, price);

	cout << "\n--- Initial Car Details ---\n";
	car1.display();
	car2.display();

	cin.ignore();
	cout << "Enter the BRAND of the car: ";
	cin.getline(brand, 100);
	cout << "Enter the MODEL of the car: ";
	cin.getline(model, 100);
	cout << "Enter the price of the car: ";
	cin >> price;
	cout << "\n--- Updating Car 1 ---\n";
	car1.setModel(brand);
	car1.setBrand(model);
	car1.setPrice(price);

	cout << "Car 1's new brand (via getter): " << car1.getBrand() << "\n";
	cout << "Car 1's new model (via getter): " << car1.getModel() << "\n";
	cout << "Car 1's new price (via getter): " << car1.getPrice() << "\n";

	cout << "\n--- Final Car Details ---\n";
	car1.display();
	car2.display();

	return 0;
}