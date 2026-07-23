// Hussain Durrani
// L1F24BSCS0937

#include <iostream>
using namespace std;

template <class T>
class Array
{
	T* arr;
	int size;
	int n;

public:
	Array(int ssize) : n(0), size(ssize) {
		arr = new T[ssize];
	}

	void insert(T v) {
		if (n < size) {
			arr[n++] = v;
			cout << v << " added.\n";
		}
		else {
			cout << "Array is Full. Can't add more elements...\n";
		}
	}

	int search(T v) {
		for (int i = 0; i < n; i++) {
			if (arr[i] == v) { return i; }
		}
		return -1;
	}

	void display() {
		cout << "\n-----------------------------------\n";
		cout << "Elements of ARRAY: ";
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " | ";
		}
		cout << "\n-----------------------------------\n\n";
	}

	int getCurrentElements() { return n; }

	void remove(T v) {
		int index = this->search(v);
		for (int i = index; i < n - 1; i++) {
			arr[i] = arr[i + 1];
		}
		n--;
		cout << v << " is removed from the array...\n";
	}

	~Array() {
		delete[] arr;
	}

};

class Product {
	int productID;
	string productName;
	float price;
	int quantity;
	static int totalProducts;

public:
	Product(): price(0), quantity(0), productID(++totalProducts*10), productName("Unknown") {}
	Product(string name, float p, int q): price(p), quantity(q), productID(++totalProducts*10), productName(name){}

	void display() {
		cout << "\n=====================================================\n";
		cout << "Product Name: " << productName << ", Product ID: " << productID << "\n";
		cout << "Price: " << price << ",  Quantity: " << quantity << "\n";
		cout << "=====================================================\n\n";
	}

	friend ostream& operator << (ostream& out, const Product& p) {
		cout << p.productName << " ";
		return out;
	}

	bool operator == (const Product& p) {
		return this->productID == p.productID;
	}
};

int Product::totalProducts = 0;

int main() {
	
	Array<Product> arrProduct(10);

	Product p1("Laptop", 60000, 5);
	Product p2("PC", 100000, 3);
	Product p3("Mobile Phone", 120000, 15);
	Product p4("Tablet", 50000, 2);
	Product p5("PlayStation", 130000, 1);
	Product p6("iPhone", 190000, 9);

	arrProduct.insert(p1);
	arrProduct.insert(p2);
	arrProduct.insert(p3);
	arrProduct.insert(p4);
	arrProduct.insert(p5);
	arrProduct.insert(p6);

	arrProduct.display();

	if (arrProduct.search(p4) != -1) cout << "Product Tablet is at index: " << arrProduct.search(p4) << "\n";
	else cout << "Product is not present in the array\n";

	arrProduct.remove(p4);

	if (arrProduct.search(p4) != -1) cout << "Product Tablet is at index: " << arrProduct.search(p4) << "\n";
	else cout << "Product is not present in the array\n";

	arrProduct.display();

	Product p7("AirPods", 5000, 50);
	Product p8("Chrome Book", 100000, 5);
	Product p9("Gaming PC", 200000, 3);
	Product p10("Mobile Phone", 120000, 15);
	Product p11("Mobile 3710", 9000, 1);
	Product p12("CAR", 1120000, 15);
	Product p13("BIKE", 1220000, 15);

	arrProduct.insert(p7);
	arrProduct.insert(p8);
	arrProduct.insert(p9);
	arrProduct.insert(p10);
	arrProduct.insert(p11);
	arrProduct.insert(p12);
	arrProduct.insert(p13);

	arrProduct.display();
	

	return 0;
}