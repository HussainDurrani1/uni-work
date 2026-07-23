// Hussain Durrani
// L1F24BSCS0937

#include <iostream>
using namespace std;

class Rectangle {
	int length;
	int width = 5;

public:
	Rectangle() : length(0) {}

	void setLength(int l) { length = l; }
	void setWidth(int w) { width = w; }

	int calculateArea() {
		return length * width;
	}

	void display() {
		cout << "Length: " << length << ", Width: " << width << endl;
		cout << "Calculated Area: " << calculateArea() << endl;
	}
};

int main() {
	Rectangle r;

	r.setLength(10);
	cout << "Only Length set (Width = 5):\n";
	r.display();

	r.setLength(10);
	r.setWidth(10);
	cout << "\nBoth Length & Width updated:\n";
	r.display();

	return 0;
}